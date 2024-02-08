const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const ActionReaction = new Schema(
    {
        action: {
            type: Schema.ObjectId,
            ref: "Action",
            required: [true, "Action is required"],
        },
        reaction: {
            type: Schema.ObjectId,
            ref: "Reaction",
            required: [true, "Reaction is required"],
        },
        webhook_uid: {
            type: String
        },
        action_params: [{
            name: {type: String},
            value: {type: String}
        }],
        reaction_params: [{
            name: {type: String},
            value: {type: String}
        }],
        memory: {
          type: Array,
        },
        user: {
            type: Schema.ObjectId,
            ref: 'User'
        }
    }
)

module.exports = mongoose.model("ActionReaction", ActionReaction);