const mongoose = require("mongoose");
const axios = require("axios");
const Twitter = require("twitter");
const utils = require("../../utils");
const Schema = mongoose.Schema;

const Reaction = new Schema({
  name: {
    type: String,
    required: [true, "Name is required"],
    unique: true,
  },
  description: {
    type: String,
  },
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
  service: {
    type: Schema.ObjectId,
    ref: "Services",
  },
  userKey: {
    type: Boolean,
  },
  options: {
    type: Array,
  },
});


const twitter_call = async (user, service, url) => {
  const uri = new URL(url);
  await user.populate("keys");
  const {keys} = await user.keys.find((e) => e.service === service.name);
  const client = new Twitter({
    consumer_key: process.env.TWITTER_APP_ID,
    consumer_secret: process.env.TWITTER_APP_SECRET,
    access_token_key: keys.get("public"),
    access_token_secret: keys.get("secret")
  })
  client.post(uri.pathname.replace("/1.1", "").replace("/2", ""), Object.fromEntries(uri.searchParams), () => {})
}

Reaction.methods.exec = async function (user, params) {
  console.log("\n\nreaction\n\n");
  try {
    console.log(`${user.username} : Triggered reaction ${this.name}`);
    await this.populate("service");
    const uri = await utils.completeUrl(user, this.service, this.endpointUrl, params)
    if (this.service.name === "twitter")
      return twitter_call( user, this.service, uri)
    console.log(
      await axios({
        method: this.method,
        url: uri,
        headers: await utils.getHeaders(this, user, this.service),
        data: this.body.slice(0, 5) === "JSON:" ? JSON.parse(utils.fillParams(this.body.slice(5), params)) : utils.fillParams(this.body, params)
      })
    );
  } catch (error) {
    console.log(error?.config);
    console.log(error?.response?.data);
  }
};

module.exports = mongoose.model("Reaction", Reaction);
