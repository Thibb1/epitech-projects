const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const Webhook = new Schema({
  target_type: {
    type: String,
  },
  webhook_type: {
    type: String,
  },
  condition_value: {
    type: String,
  },
});

module.exports = mongoose.model("Webhook", Webhook);
