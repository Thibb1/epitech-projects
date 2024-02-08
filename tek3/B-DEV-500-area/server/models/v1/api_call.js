const axios = require("axios");
const mongoose = require("mongoose");
const utils = require("../../utils");
const jwt = require("jsonwebtoken");
const Schema = mongoose.Schema;

// const Users = require("./user");
const Api_call = new Schema({
  method: {
    type: String,
  },
  endpointUrl: {
    type: String,
  },
  header: {
    type: String,
  },
  body: {
    type: String,
  },
  trigger: {
    type: Array,
  },
  userKey: {
    type: Boolean,
  },
});

async function check_trigger(trig, memory, res, data) {
  if (typeof data === "undefined") return false;
  switch (trig[0]) {
    case "dataChanged":
      if (data !== memory && memory !== "unset") return true;
      break;
    case "dataUp":
      if (data > memory && memory !== "unset") return true;
      break;
    case "dataDown":
      if (data < memory && memory !== "unset") return true;
      break;
    case "dataIs":
      if (data === trig[2]) return true;
      break;
    case "dataHas":
      if (~data.indexOf(trig[2])) return true;
      break;
    case "codeChanged":
      if (String(res.status) !== memory && memory !== "unset") return true;
      break;
    case "codeIs":
      if (String(res.status) === trig[1]) return true;
      break;
    case "codeHas":
      if (~String(res.status).indexOf(trig[1])) return true;
      break;
    default:
      return false;
  }
  return false;
}

async function check_response(action, res, ar) {
  try {
    let results = [];
    let newmem = [];
    let data = res.data;
    //console.log(action.trigger);
    //console.log(res.data);
    if (data.errors) {
      console.error(data.errors);
      throw new Error("TypeError: Cannot read properties of undefined");
    }
    let mem_index = 0;
    for (const [index, trigger] of action.trigger.entries()) {
      // console.log({ index, trigger });
      if (trigger[0] === "&&" || trigger[0] === "||") {
        results[index] = trigger[0];
        continue;
      }
      if (~trigger[0].indexOf("data"))
        trigger[1].split(".").forEach((elem) => {
          data = data[elem];
        });
      else data = res.status;
      newmem.push(data);
      results[index] = await check_trigger(
        trigger,
        ar.memory[mem_index],
        res,
        data
      );
      mem_index++;
    }
    console.log("mem", newmem);
    ar.memory = newmem;
    await ar.save();
    for (let i = 0; typeof results[i + 2] !== "undefined"; i += 2) {
      if (results[i + 1] === "&&") {
        results[i + 2] = results[i] && results[i + 2];
        results[i] = "";
        results[i + 1] = "";
      }
    }
    results = results.filter((val) => typeof val !== "string" || val !== "");
    for (let i = 0; typeof results[i + 2] !== "undefined"; i += 2) {
      if (results[i + 1] === "||") {
        results[i + 2] = results[i] || results[i + 2];
        results[i] = "";
        results[i + 1] = "";
      }
    }
    results = results.filter((val) => typeof val !== "string" || val !== "");
    //console.log(results);
    return results[0];
  } catch (err) {
    console.log(err);
    return false;
  }
}

Api_call.methods.check = async function (user, service, ar) {
  try {
    const params = ar.action_params;
    console.log("Checking for action " + ar.action.name);
    await user.populate("keys");
    const { keys } = user.keys.find(
      ({ service: keyService }) => keyService === service.name
    );
    const refresh = keys.get("expires_in");
    if (!!refresh && refresh <= Date.now()) {
      await axios.post(
        `${process.env.BASE_URL}:8080/user/${service.name}/refresh`,
        {
          refresh: keys.get("refresh_token"),
        },
        {
          headers: {
            Authorization: "Bearer " + jwt.sign({ user: user }, "TOP_SECRET"),
          },
        }
      );
    }
    utils.fillParams(this.endpointUrl, params);
    return await check_response(
      this,
      await axios({
        method: this.method,
        url: await utils.completeUrl(user, service, this.endpointUrl, params),
        headers: await utils.getHeaders(this, user, service),
        data: utils.fillParams(this.body, params),
      }),
      ar
    );
  } catch (e) {
    console.log(e);
  }
};

module.exports = mongoose.model("Api_call", Api_call);
