const mongoose = require("mongoose");
const Schema = mongoose.Schema;
const bcrypt = require("bcryptjs");
const UserKeys = require("./userkeys.js");

const User = new Schema(
  {
    username: {
      type: String,
      trim: true,
      required: [true, "Username is required"],
      unique: true,
      lowercase: true,
    },
    password: {
      type: String,
    },
    keys: [
      {
        type: Schema.ObjectId,
        ref: "UserKeys",
      },
    ],
    actionReaction: [
      {
        type: Schema.ObjectId,
        ref: "ActionReaction",
      },
    ],
  },
  {
    timestamps: true,
  }
);

User.pre("save", function (next) {
  if (!this.isModified("password")) {
    return next();
  }
  this.password = bcrypt.hashSync(this.password, 10);
  next();
});

User.methods.isValidPassword = async function (password) {
  const user = this;
  return await bcrypt.compare(password, user.password);
};

User.methods.addApiKey = async function (key, service) {
  try {
    const user = this;
    const id = await new UserKeys({ service: service, keys: key }).save();
    await user.keys.push(id);
    await user.save();
    return `${service} key added to ${user.username}`;
  } catch (e) {
    throw `Couldn't add ${service} key`;
  }
};

User.methods.updateApiKey = async function (newKeys, service) {
  try {
    await UserKeys.findOneAndUpdate({ service: service }, { keys: newKeys });
    return `${service} key updated`;
  } catch (e) {
    console.log(e);
    throw `Couldn't update ${service} key`;
  }
};

module.exports = mongoose.model("User", User);
