const express = require("express");
const utils = require("../../../utils");
const Actions = require("../../../models/v1/action");
const Reactions = require("../../../models/v1/reaction");
const dbUtils = require("../../../db_utils");
const router = express.Router();

router.post("/addAction", (req, res) => {
  dbUtils
    .addAction(req.body)
    .then(() => {
      try {
        const { service, name, desc, method, options } = req.body;
        const newData = utils.getDb();
        let newAction = {
          name: name,
          desc: desc,
          options: options,
        };
        newAction =
          method?.length > 0
            ? {
                ...newAction,
                method: method,
                endpointUrl: req.body.endpointUrl,
                header: req.body.header,
                body: req.body.body,
                trigger: req.body.trigger,
                userKey: req.body.userKey === "true",
              }
            : {
                ...newAction,
                webhook_type: req.body.webhook_type,
                condition_value: req.body.condition_value,
                target_type: req.body.target_type,
              };
        newData.services
          .filter((serv) => {
            return serv.name === service;
          })[0]
          .actions.push(newAction);
        utils.writeDb(newData);
        res.status(201).json({
          message: `Action added successfully to service ${service}!`,
        });
      } catch (err) {
        console.log(err);
        res.status(400).json({ error: err });
      }
    })
    .catch((error) => {
      console.log(error);
      res.status(400).json({
        error: error,
      });
    });
});

router.post("/addReaction", async (req, res) => {
  dbUtils
    .addReaction(req.body)
    .then(() => {
      try {
        const {
          service,
          name,
          desc,
          method,
          options,
          endpointUrl,
          header,
          body,
          userKey,
        } = req.body;
        const newData = utils.getDb();
        const newReaction = {
          name: name,
          desc: desc,
          options: options,
          method: method,
          endpointUrl: endpointUrl,
          header: header,
          body: body,
          userKey: userKey === "true",
        };
        newData.services
          .filter((serv) => {
            return serv.name === service;
          })[0]
          .reactions.push(newReaction);
        utils.writeDb(newData, name);
        res.status(201).json({
          message: `Reaction added successfully to service ${service}!`,
        });
      } catch (err) {
        console.log(err);
        res.status(400).json({ error: err });
      }
    })
    .catch((error) => {
      console.log(error);
      res.status(400).json({ error: error });
    });
});

router.delete("/removeAction/:service/:action", async (req, res) => {
  try {
    const { service, action } = req.params;
    await Actions.findOneAndDelete({ name: action });
    const newData = utils.getDb();
    newData.services.forEach((dbService, index) => {
      if (dbService.name === service) {
        newData.services[index].actions.forEach((dbAction, index2) => {
          if (dbAction.name === action) {
            newData.services[index].actions.splice(index2, 1);
          }
        });
      }
    });
    utils.writeDb(newData, action, "removed");
    res.status(201).json({
      message: `${action} was removed from ${service}.`,
    });
  } catch (error) {
    console.log(error);
    res.status(400).json({
      error: error,
    });
  }
});

router.delete("/removeReaction/:service/:reaction", async (req, res) => {
  try {
    const { service, reaction } = req.params;
    await Reactions.findOneAndDelete({ name: reaction });
    const newData = utils.getDb();
    newData.services.forEach((dbService, index) => {
      if (dbService.name === service) {
        newData.services[index].reactions.forEach((dbAction, index2) => {
          if (dbAction.name === reaction) {
            newData.services[index].reactions.splice(index2, 1);
          }
        });
      }
    });
    utils.writeDb(newData, reaction, "removed");
    res.status(201).json({
      message: `${reaction} was removed from ${service}.`,
    });
  } catch (error) {
    console.log(error);
    res.status(400).json({
      error: error,
    });
  }
});

module.exports = router;
