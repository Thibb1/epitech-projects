const express = require("express");
const User = require("../../../models/v1/user");
const axios = require("axios");
const router = express.Router();

router.post("/callback", async (req, res) => {
  const { user_cookie } = req.body;
  try {
    const user = await User.findOne({ username: req.user.username });
    const { data } = await axios.get(
      "https://intra.epitech.eu/user/?format=json",
      { headers: { Cookie: "user=" + user_cookie } }
    );
    const { internal_email } = data;
    const map = new Map([
      ["user_cookie", "user=" + user_cookie.toString()],
      ["email", internal_email],
    ]);
    user.addApiKey(map, "epitech").then((e) => res.status(201).send(e));
  } catch (e) {
    console.log(e);
    res.status(500).send(e);
  }
});

router.get("/addAccount", async (req, res) => {
  const uri = await axios
    .get("https://intra.epitech.eu")
    .then((r) => console.log(r.data))
    .catch((e) => {
      const { office_auth_uri } = e.response.data;
      return office_auth_uri;
    });
  res.status(200).send({ path: uri });
});

module.exports = router;
