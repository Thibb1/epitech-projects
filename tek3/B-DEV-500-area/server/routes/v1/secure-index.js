const express = require("express");
const router = express.Router();

const twitter = require("./twitter");
const twitch = require("./twitch");
const reddit = require("./reddit");
const epitech = require("./epitech");
const spotify = require("./spotify");
const area = require("./area");
const api = require("./api");

router.use("/twitter", twitter);
router.use("/twitch", twitch.router);
router.use("/reddit", reddit);
router.use("/spotify", spotify);
router.use("/epitech", epitech);
router.use("/", area);
router.use("/", api);

router.get("/profile", async (req, res) => {
  res.json({
    message: "You made it to the secure route",
    user: req.user,
  });
});

module.exports = router;
