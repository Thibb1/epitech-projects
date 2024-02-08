const express = require("express");
const Action = require("../../../models/v1/action");
const User = require("../../../models/v1/user");
const Reaction = require("../../../models/v1/reaction");
const ActionReaction = require("../../../models/v1/actionreaction");
const axios = require("axios");
const router = express.Router();

router.get("/getActions", async (req, res) => {
  let data = [];
  try {
    const actions = await Action.find({})
      .populate({
        path: "service",
        select: "name",
      })
      .select("name description service options");
    const { keys } = await User.findOne({
      username: req.user.username,
    }).populate("keys");
    keys.forEach((key) => {
      data.push(actions.filter(({ service }) => service.name === key.service));
    });
    res.status(200).json(data.flat());
  } catch (e) {
    console.log(e);
    res.status(500).send("Couldn't getActions");
  }
});

router.get("/getReactions", async (req, res) => {
  let data = [];
  try {
    const reactions = await Reaction.find({})
      .populate({ path: "service", select: "name" })
      .select("name description service options");
    const { keys } = await User.findOne({
      username: req.user.username,
    }).populate("keys");
    keys.forEach((key) => {
      data.push(
        reactions.filter(({ service }) => service.name === key.service)
      );
    });
    res.status(200).json(data.flat());
  } catch (e) {
    console.log(e);
    res.status(500).send("Couldn't getReactions");
  }
});

router.get("/getActionReaction", async (req, res) => {
  try {
    const { actionReaction } = await User.findOne({
      username: req.user.username,
    }).populate({
      path: "actionReaction",
      populate: [
        { path: "action", select: "name" },
        { path: "reaction", select: "name" },
      ],
    });
    res.status(200).json(actionReaction);
  } catch (e) {
    console.log(e);
    res.status(500).send("Error getting ar");
  }
});

router.delete("/deleteActionReaction/:id", async (req, res) => {
  const { id } = req.params;
  try {
    await User.findOne({ username: req.user.username }).then(async (user) => {
      user.actionReaction = user.actionReaction.filter(
        ({ _id }) => !_id.equals(id)
      );
      await ActionReaction.findByIdAndDelete(id);
      await user.save().then(() => res.status(200).send("ar deleted"));
    });
  } catch (e) {
    console.log(e);
    res.status(500).json(e);
  }
});

router.post("/addActionReaction", async (req, res) => {
  try {
    const split_params = (params, dest) => {
      params.split(",").forEach((p) => {
        if (p === "") return;
        p = p.split(":");
        dest.push({ name: p[0], value: p[1] });
      });
    };
    const { action_id, reaction_id, action_params, reaction_params } = req.body;
    const user = await User.findOne({ username: req.user.username });
    const action = await Action.findById(action_id);
    const reaction = await Reaction.findById(reaction_id);
    const newAR = await new ActionReaction({
      action: action._id,
      reaction: reaction._id,
      memory: ["unset"],
      webhook_uid: "",
      user: user,
    });
    split_params(action_params, newAR.action_params);
    split_params(reaction_params, newAR.reaction_params);
    if (action.webhook) {
      await action.populate("webhook service");
      await axios
        .post(
          `${process.env.BASE_URL}:8080/${action.service.name}/link-webhook`,
          {
            webhook: action.webhook,
            params: newAR.action_params,
          }
        )
        .then((r) => {
          console.log(r.data);
          newAR.webhook_uid = r.data;
        });
    }
    newAR.save().then(() => {
      user.actionReaction.push(newAR);
      user.save().then(() => {
        res.status(201).json({
          message: `action ${action.name} and reaction ${reaction.name} successfully added to user ${req.user.username}`,
        });
      });
    });
  } catch (error) {
    console.log("error adding ActionReaction", error?.response?.data);
    res.status(400).json({
      error: error?.response?.data,
    });
  }
});

module.exports = router;
