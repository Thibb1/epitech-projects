const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const Action = new Schema({
  name: {
    type: String,
    required: [true, "Name is required"],
    unique: true,
  },
  description: {
    type: String,
  },
  service: {
    type: Schema.ObjectId,
    ref: "Services",
  },
  webhook: {
    type: Schema.ObjectId,
    ref: "Webhook",
  },
  api_call: {
    type: Schema.ObjectId,
    ref: "Api_call",
  },
  options: {
    type: Array,
  },
});

Action.methods.isWebhook = function () {
  return typeof this.webhook !== "undefined";
};

Action.methods.check = async function (user, ar) {
  try {
    const action = await this.populate("api_call service");
    return await action.api_call.check(user, this.service, ar);
  } catch (error) {
    console.log(error);
  }
};

module.exports = mongoose.model("Action", Action);
