const Services = require("./models/v1/services");
const Api_call = require("./models/v1/api_call");
const Webhook = require("./models/v1/webhook");
const Action = require("./models/v1/action");
const { db } = require("./models/v1/action");
const Reaction = require("./models/v1/reaction");

exports.addService = async (rbody) => {
  const { name, desc, appKeys } = rbody;
  const map = new Map();
  appKeys.split(",").forEach((elem) => {
    map.set(
      elem.substring(0, elem.indexOf(":")),
      elem.substring(elem.indexOf(":") + 1)
    );
  });
  const newService = new Services({
    name: name,
    description: desc,
    appKeys: map,
  });
  await newService.save();
  console.log("Created service " + name);
};

async function addApiAction(rbody) {
  const { method, endpointUrl, header, body, trigger, userKey } = rbody;
  const trigger_arr = trigger.split(/(&&|\|\|)/);
  trigger_arr.forEach((elem, index) => {
    if (elem !== "&&" || elem !== "||") trigger_arr[index] = elem.split(",");
  });
  const newApi_call = new Api_call({
    method: method,
    endpointUrl: endpointUrl,
    header: header,
    body: body,
    trigger: trigger_arr,
    userKey: userKey === "true",
  });
  await newApi_call.save();
  return newApi_call;
}

async function addWebhookAction(rbody) {
  const { target_type, webhook_type, condition_value } = rbody;
  return await new Webhook({
    target_type: target_type,
    webhook_type: webhook_type,
    condition_value: condition_value,
  }).save();
}

exports.addAction = async (rbody) => {
  try {
    const { service, name, desc, method, options } = rbody;
    const newAction = await new Action({
      name: name,
      description: desc,
      service: await Services.findOne({ name: service }),
      options: JSON.parse(options ?? "[]"),
      webhook: !method ? await addWebhookAction(rbody) : null,
      api_call: method ? await addApiAction(rbody) : null,
    });
    await newAction.save();
    await db
      .collection("services")
      .findOneAndUpdate(
        { name: service },
        { $push: { actions: newAction._id } },
        { new: true }
      )
      .then((data) => {
        newAction.service = data.value._id;
      });
    console.log(service + ": added action " + name);
  } catch (error) {
    throw error;
  }
};

exports.addReaction = async (rbody) => {
  try {
    const {
      service,
      name,
      method,
      desc,
      header,
      body,
      endpointUrl,
      userKey,
      options,
    } = rbody;
    const newReaction = new Reaction({
      name: name,
      description: desc,
      service: await Services.findOne({ name: service }),
      method: method,
      endpointUrl: endpointUrl,
      header: header,
      body: body,
      userKey: userKey === "true",
      options: JSON.parse(options ?? "[]"),
    });
    await db
      .collection("services")
      .findOneAndUpdate(
        { name: service },
        { $push: { reactions: newReaction._id } },
        { new: true }
      )
      .then((data) => {
        newReaction.service = data.value._id;
      });
    await newReaction.save();
    console.log(service + ": added reaction " + name);
  } catch (error) {
    throw error;
  }
};
