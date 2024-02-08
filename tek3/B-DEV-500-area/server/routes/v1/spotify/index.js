const express = require("express");
const User = require("../../../models/v1/user");
const axios = require("axios");
const crypto = require("crypto");
const router = express.Router();

function getAuth() {
  return `Basic ${Buffer.from(
    `${process.env.SPOTIFY_APP_ID}:${process.env.SPOTIFY_APP_SECRET}`
  ).toString("base64")}`;
}

router.post("/refresh", async (req, res) => {
  try {
    const user = await User.findOne({ username: req.user.username });
    const { refresh } = req.body;
    await axios
      .post(
        "https://accounts.spotify.com/api/token",
        {
          grant_type: "refresh_token",
          refresh_token: refresh,
        },
        {
          headers: {
            Authorization: getAuth(),
            "content-type": "application/x-www-form-urlencoded",
          },
        }
      )
      .then((r) => {
        const map = new Map([
          ["access_token", "Bearer " + r.data["access_token"]],
          ["refresh_token", refresh],
          ["expires_in", Date.now() + r.data["expires_in"] * 1000],
        ]);
        user.updateApiKey(map, "spotify").then((e) => res.status(201).send(e));
      });
  } catch (e) {
    console.log(e);
    res.status(500).send("Couldn't refresh");
  }
});

router.post("/callback", async (req, res) => {
  const { code } = req.body;
  try {
    const user = await User.findOne({ username: req.user.username });
    await axios({
      method: "post",
      url: "https://accounts.spotify.com/api/token",
      headers: {
        Authorization: getAuth(),
        "content-type": "application/x-www-form-urlencoded",
      },
      data: {
        grant_type: "authorization_code",
        code: code,
        redirect_uri: `${process.env.BASE_URL}:8081/connect-api/spotify`,
      },
    }).then((r) => {
      axios
        .get("https://api.spotify.com/v1/me/player/devices", {
          headers: { Authorization: "Bearer " + r.data["access_token"] },
        })
        .then((d) => {
          console.log("got devices");
          const { devices } = d.data;
          const deviceId = devices[0].id;
          const map = new Map([
            ["access_token", "Bearer " + r.data["access_token"]],
            ["refresh_token", r.data["refresh_token"]],
            ["expires_in", Date.now() + r.data["expires_in"] * 1000],
            ["device_id", deviceId],
          ]);
          user.addApiKey(map, "spotify").then((e) => res.status(201).send(e));
        });
    });
  } catch (e) {
    console.log(e);
    res.status(500).send(e);
  }
});

router.get("/addAccount", async (req, res) => {
  const state = crypto.randomBytes(8).toString("hex");
  const uri = new URL("https://accounts.spotify.com/authorize");
  uri.searchParams.append("client_id", process.env.SPOTIFY_APP_ID);
  uri.searchParams.append(
    "redirect_uri",
    `${process.env.BASE_URL}:8081/connect-api/spotify`
  );
  uri.searchParams.append("response_type", "code");
  uri.searchParams.append(
    "scope",
    "playlist-read-private playlist-read-collaborative user-read-private user-modify-playback-state app-remote-control user-read-playback-state"
  );
  uri.searchParams.append("state", state);
  res.status(200).json({ path: uri.href });
});

module.exports = router;
