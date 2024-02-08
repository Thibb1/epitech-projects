const express = require("express");
const utils = require("../../../utils");
const Services = require("../../../models/v1/services");
const router = express.Router();

router.post("/addService", (req, res) => {
  const { name, desc, appKeys } = req.body;
  utils
    .addService(req.body)
    .then(() => {
      try {
        const newData = utils.getDb();
        newData.services.push({
          name: name,
          desc: desc,
          appKeys: appKeys,
          actions: [],
          reactions: [],
        });
        utils.writeDb(newData, name);
        res.status(201).json({
          message: "Service saved successfully!",
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

router.delete("/removeService/:service", async (req, res) => {
  try {
    const { service } = req.params;
    await Services.findOneAndDelete({ name: service });
    const newData = utils.getDb();
    newData.services.forEach((dbService, index) => {
      if (dbService.name === service) newData.services.splice(index, 1);
    });
    utils.writeDb(newData, service, "removed");
    res.status(201).json({
      message: `${service} was removed.`,
    });
  } catch (error) {
    console.log(error);
    res.status(400).json({
      error: error,
    });
  }
});

module.exports = router;
