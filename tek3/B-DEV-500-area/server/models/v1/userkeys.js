const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const UserKeys = new Schema({
  service: {
    type: String,
    required: [true, "Service name is required"],
  },
  keys: {
    type: Map,
  },
});

module.exports = mongoose.model("UserKeys", UserKeys);
