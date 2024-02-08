const express = require("express");
const User = require("../../../models/v1/user");
const axios = require("axios");
const crypto = require("crypto");
const router = express.Router();

router.post("/callback", async (req, res) => {
  const { code } = req.body;
  try {
    const user = await User.findOne({ username: req.user.username });
    await axios({
      method: "post",
      url: "https://www.reddit.com/api/v1/access_token",
      headers: {
        Authorization: `Basic ${Buffer.from(
          `${process.env.REDDIT_APP_ID}:${process.env.REDDIT_APP_SECRET}`
        ).toString("base64")}`,
        "content-type": "application/x-www-form-urlencoded",
      },
      data: {
        grant_type: "authorization_code",
        code: code,
        redirect_uri: `${process.env.BASE_URL}:8081/connect-api/reddit`,
      },
    }).then((r) => {
      const map = new Map([
        ["access_token", "Bearer " + r.data["access_token"].toString()],
        ["refresh_token", "Bearer " + r.data["refresh_token"].toString()],
      ]);
      user.addApiKey(map, "reddit").then((e) => res.status(201).send(e));
    });
  } catch (e) {
    console.log(e);
    res.status(500).send(e);
  }
});

router.get("/addAccount", async (req, res) => {
  const random_string = crypto.randomBytes(5).toString("hex");
  const uri = new URL("https://www.reddit.com/api/v1/authorize");
  uri.searchParams.append("client_id", process.env.REDDIT_APP_ID);
  uri.searchParams.append("response_type", "code");
  uri.searchParams.append("state", random_string);
  uri.searchParams.append(
    "redirect_uri",
    `${process.env.BASE_URL}:8081/connect-api/reddit`
  );
  uri.searchParams.append("duration", "permanent");
  uri.searchParams.append("scope", "read,submit,account");
  res.status(200).json({ path: uri });
});

module.exports = router;
