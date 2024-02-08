const express = require("express");
const passport = require("passport");
const bodyParser = require("body-parser");
const mongodb = require("./db/mongo");
const cookieParser = require("cookie-parser");
const logger = require("morgan");
const cors = require("cors");
const Users = require("./models/v1/user");
const Actions = require("./models/v1/action");
const Reactions = require("./models/v1/reaction");
const ActionReaction = require("./models/v1/actionreaction");
const https = require("https");
const fs = require("fs");
const session = require("express-session");
const utils = require("./utils.js");
require("./auth/auth");

const port = process.env.PORT || 8080;
mongodb.initDbConnection().then(() => console.log("MongoDb connected"));

const routes = require("./routes/v1/index");
const secureRoute = require("./routes/v1/secure-index");
const Services = require("./models/v1/services");
const dbUtils = require("./db_utils");

const app = express();
app.use(passport.initialize());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(logger("dev"));
app.use(express.json());
app.use(
  session({
    secret: "TOP_SECRET",
    resave: false,
    saveUninitialized: true,
  })
);
app.use(passport.session());
app.use(
  cors({
    credentials: true,
  })
);

app.use("/", routes);
app.use("/user", passport.authenticate("jwt", { session: false }), secureRoute);

if (process.env.HTTPS === "true") {
  const credentials = {
    key: fs.readFileSync((path = process.env.SSL_KEY_FILE)),
    cert: fs.readFileSync((path = process.env.SSL_CRT_FILE)),
  };
  const httpsServer = https.createServer(credentials, app);
  httpsServer.listen(port);
} else {
  app.listen(port);
}

function addKeys(str) {
  while (str.indexOf("{") != -1 && str) {
    substr = str.substring(str.indexOf("{") + 1, str.indexOf("}"))
    str = str.replaceAll("{" + substr + "}", process.env[substr])
  }
  return str
}

async function build_db(file_path) {
  try {
    const data = utils.getDb();
    if (!data?.services) {
      console.log(`Faulty file ${file_path} backed up in ${file_path}.old`);
      utils.writeDb(data, file_path, "backed up", `${file_path}.old`);
      data.services = [];
      utils.writeDb(data, "services", "added", file_path);
    }
    for (const dbService of data.services) {
      const service = await Services.find({ name: dbService.name });
      if (service.length === 0)
        await dbUtils.addService({
          name: dbService.name,
          desc: dbService.desc,
          appKeys: addKeys(dbService.appKeys),
        });
      for (const action of dbService.actions) {
        action.service = dbService.name;
        const arr = await Actions.find({ name: action.name });
        if (arr.length === 0) await dbUtils.addAction(action);
      }
      for (const reaction of dbService.reactions) {
        reaction.service = dbService.name;
        const arr = await Reactions.find({ name: reaction.name });
        if (arr.length === 0) await dbUtils.addReaction(reaction);
      }
    }
  } catch (error) {
    console.log("Server was unable to build database: " + error);
  }
}
build_db("./db.json").then(() => console.log("Db was restored"));

console.log(`Server listening on port ${port}`);

async function checkActions() {
  try {
    Users.find({}, (err, users) => {
      if (err) {
        console.log("found err");
        console.log(err);
      }
      users.forEach((user) => {
        try {
          console.log(user.username + " :");
          user.populate("actionReaction").then(() => {
            user.actionReaction.forEach(async (ar) => {
              await ar.populate("action");
              if (ar.action != null) {
                if (!ar.webhook_uid)
                  if ((await ar.action.check(user, ar)) === true)
                    ar.populate("reaction").then(async () => {
                      if (ar.reaction != null)
                        await ar.reaction.exec(user, ar.reaction_params);
                      else await ActionReaction.deleteOne({ _id: ar._id });
                    });
              } else await ActionReaction.deleteOne({ _id: ar._id });
            });
          });
        } catch (error) {
          console.log(error);
        }
      });
    });
  } catch (e) {
    console.log("catch error");
    console.log(e);
  }
}
setInterval(checkActions, 5 * 1000);
