const express = require("express");
const router = express.Router();
const ActionReaction = require("../../../models/v1/actionreaction.js");
const axios = require("axios");
const crypto = require("crypto");
const twitch = require("./index");
const utils = require("../../../utils");

router.post("/webhook", async (req, res) => {
  const messageType = req.header("Twitch-Eventsub-Message-Type");
  if (messageType === "webhook_callback_verification") {
    const { challenge } = req.body;
    console.log("callback verification", challenge);
    res.send(challenge);
  } else if (messageType === "notification") {
    const { subscription } = req.body;
    console.log("twitch webhook triggered for", subscription);
    await ActionReaction.find(
      { webhook_uid: subscription.id },
      (err, linkedReactions) => {
        if (err) console.log(err);
        console.log(linkedReactions);
        linkedReactions.forEach((reaction) => {
          reaction.populate("reaction").then(async () => {
            await reaction.populate("user");
            console.log(reaction.user);
            await reaction.reaction.exec(
              reaction.user,
              reaction.reaction_params
            );
          });
        });
      }
    ).clone();
    res.send("");
  }
});

function get_twitch_bearer() {
  const uri = twitch.twitchUrl();
  uri.searchParams.append("grant_type", "client_credentials");
  try {
    console.log("Get bearer");
    return axios({
      method: "post",
      url: uri,
    }).then((r) => {
      return r.data["access_token"];
    });
  } catch (e) {
    console.log("error getting bearer", e?.response?.data);
    throw Error("Bearer failed");
  }
}

router.post("/link-webhook", async (req, res) => {
  try {
    const { webhook, params } = req.body;
    console.log("Linking webhook twitch", { webhook, params });
    const webhook_header = {
      Authorization: `Bearer ${await get_twitch_bearer()}`,
      "Client-ID": process.env.TWITCH_APP_ID,
    };
    const target_type = utils.fillParams(webhook.target_type, params);
    const webhook_type = utils.fillParams(webhook.webhook_type, params);
    const targetId = utils.fillParams(webhook.condition_value, params);

    const { data } = await axios.get(
      "https://api.twitch.tv/helix/eventsub/subscriptions",
      { headers: webhook_header }
    );
    let id = "";
    data.data.forEach((webhook) => {
      if (
        webhook["status"] === "enabled" &&
        webhook["type"] === webhook_type &&
        webhook["transport"]["callback"] === `${process.env.WEBHOOK_URL}/twitch/webhook` &&
        webhook["condition"][target_type] === targetId
      )
        id = webhook["id"];
    });
    if (id !== "") {
      res.status(200).send(id);
      return;
    }
    console.log("request")
    await axios
      .post(
        "https://api.twitch.tv/helix/eventsub/subscriptions",
        {
          type: webhook_type,
          version: "1",
          condition: { [target_type]: targetId },
          transport: {
            method: "webhook",
            callback: `${process.env.WEBHOOK_URL}/twitch/webhook`,
            secret: crypto.randomBytes(10).toString("hex"),
          },
        },
        { headers: webhook_header }
      )
      .then((r) => {
        console.log(r.data["data"][0]["id"])
        res.status(200).send(r.data["data"][0]["id"]);
      });
  } catch (e) {
    console.log(e);
    console.log("Twitch link-webhook failed", e?.response?.data);
    res.status(500).send("Twitch link-webhook failed");
  }
});
module.exports = router;
