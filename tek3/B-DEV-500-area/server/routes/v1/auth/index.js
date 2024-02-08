const express = require("express");
const passport = require("passport");
const jwt = require("jsonwebtoken");
const User = require("../../../models/v1/user");
const router = express.Router();

router.post(
  "/signup",
  passport.authenticate("signup", { session: false }),
  async (req, res) => {
    const user = req.user;
    const token = jwt.sign(
      { user: { _id: user._id, username: user.username } },
      "TOP_SECRET"
    );
    res.json({
      message: "Signup successful",
      token: token,
    });
  }
);

router.post("/login", async (req, res, next) => {
  passport.authenticate("login", async (err, user) => {
    try {
      if (err || !user) {
        const error = new Error("An error occurred.");
        return next(error);
      }
      req.login(user, { session: false }, async (error) => {
        if (error) return next(error);
        const body = { _id: user._id, username: user.username };
        const token = jwt.sign({ user: body }, "TOP_SECRET");
        return res.json({ token });
      });
    } catch (error) {
      return next(error);
    }
  })(req, res, next);
});

router.get(
  "/google",
  passport.authenticate("google", { scope: ["email", "profile"] })
);

router.get("/exist/:name", async (req, res) => {
  const { name } = req.params;
  try {
    console.log(name);
    const user = await User.findOne({ username: name });
    if (user) {
      return res.status(200).json(true);
    }
    return res.status(201).json(false);
  } catch (error) {
    console.log(error);
  }
});

router.get("/google/callback", (req, res) => {
  passport.authenticate("google", {}, async (issuer, user, profile) => {
    console.log({ user, profile });
    const token = jwt.sign({ user: user }, "TOP_SECRET");
    res.redirect(process.env.BASE_URL + ":8081/login?jwt=" + token);
  })(req, res);
});

router.get("/logout", (req, res) => {
  req.logout();
  req.session.destroy();
  res.send("Goodbye!");
});

module.exports = router;
