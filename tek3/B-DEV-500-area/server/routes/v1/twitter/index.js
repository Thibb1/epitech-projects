const express = require("express");
const router = express.Router();
const OAuth = require("oauth");
const User = require("../../../models/v1/user");

function consumer() {
  return new OAuth.OAuth(
    "https://api.twitter.com/oauth/request_token",
    "https://api.twitter.com/oauth/access_token",
    process.env.TWITTER_APP_ID,
    process.env.TWITTER_APP_SECRET,
    "1.0A",
    `${process.env.BASE_URL}:8081/connect-api/twitter`,
    "HMAC-SHA1"
  );
}

router.post("/callback", function (req, res) {
  try {
    consumer().getOAuthAccessToken(
      req.body["oauth_token"],
      null,
      req.body["oauth_verifier"],
      async (error, oauthAccessToken, oauthAccessTokenSecret, results) => {
        if (error) {
          console.log(error);
          res.status(500).send(error + " " + results);
        } else {
          const user = await User.findOne({ username: req.user.username });
          const map = new Map([
            ["public", oauthAccessToken.toString()],
            ["secret", oauthAccessTokenSecret.toString()],
          ]);
          user.addApiKey(map, "twitter").then((e) => res.status(201).send(e));
        }
      }
    );
  } catch (error) {
    console.log(error);
  }
});

router.get("/addAccount", function (req, res) {
  consumer().getOAuthRequestToken(function (
    error,
    oauthRequestToken,
    oauthRequestTokenSecret
  ) {
    const uri = new URL("https://twitter.com/oauth/authorize");
    uri.searchParams.append("oauth_token", oauthRequestToken);
    uri.searchParams.append("oauth_token_secret", oauthRequestTokenSecret);
    if (error) {
      console.log(error);
      res
        .status(500)
        .send({ error: "Error getting OAuth request token : " + error });
    } else {
      res.status(200).send({
        path: uri,
      });
    }
  });
});

module.exports = router;
