const express = require("express");
const User = require("../../../models/v1/user");
const axios = require("axios");
const router = express.Router();

function twitchUrl() {
  const uri = new URL("https://id.twitch.tv/oauth2/token");
  uri.searchParams.append("client_id", process.env.TWITCH_APP_ID);
  uri.searchParams.append("client_secret", process.env.TWITCH_APP_SECRET);
  return uri;
}

router.post("/callback", async (req, res) => {
  const { code } = req.body;
  const uri = twitchUrl();
  uri.searchParams.append("code", code);
  uri.searchParams.append("grant_type", "authorization_code");
  uri.searchParams.append(
    "redirect_uri",
    `${process.env.BASE_URL}:8081/connect-api/twitch`
  );
  try {
    const user = await User.findOne({ username: req.user.username });
    await axios({
      method: "post",
      url: uri,
    }).then((r) => {
      const map = new Map([
        ["access_token", "Bearer " + r.data["access_token"].toString()],
        ["refresh_token", "Bearer " + r.data["refresh_token"].toString()],
      ]);
      user.addApiKey(map, "twitch").then((e) => res.status(201).send(e));
    });
  } catch (e) {
    console.log(e);
    res.status(500).send(e);
  }
});

router.get("/addAccount", async (req, res) => {
  const uri = new URL("https://id.twitch.tv/oauth2/authorize");
  uri.searchParams.append(
    "redirect_uri",
    process.env.BASE_URL + ":8081/connect-api/twitch"
  );
  uri.searchParams.append("client_id", process.env.TWITCH_APP_ID);
  uri.searchParams.append("response_type", "code");
  uri.searchParams.append(
    "scope",
    "user:edit user:read:follows channel:manage:broadcast"
  );
  res.status(200).json({ path: uri.href });
});

module.exports = { router: router, twitchUrl: twitchUrl };
