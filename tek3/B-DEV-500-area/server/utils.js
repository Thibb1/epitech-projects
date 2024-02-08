const fs = require("fs");

const getDb = (path = "db.json") => {
  const content = fs.readFileSync(path);
  return JSON.parse(content);
};

const writeDb = (
  newData,
  description = "Something",
  operation = "added",
  path = "db.json"
) => {
  fs.writeFileSync(path, JSON.stringify(newData));
  console.log(`${description} was ${operation} to ${path}`);
};

const fillParams = (str, params) => {
  if (str && params)
    params.forEach((p) => {
      str = str.replaceAll("{" + p.name + "}", p.value);
    });
  return str;
};

const getHeaders = async (action, user, service) => {
  if (!action.header) return ""
  const header = {};
  await user.populate("keys");
  let keys = await user.keys.find((e) => e.service === service.name);
  action.header.split(",").forEach((element) => {
    let type = element.split(":");
    let data = keys.keys.get(type[type.length - 1]);
    if (typeof data === "undefined")
      data = service.appKeys.get(type[type.length - 1]);
    header[type[0]] =
      typeof data === "undefined" ? element : data;
  });
  return header;
};

const completeUrl = async (user, service, str, params) => {
  str = fillParams(str, params)
  await user.populate("keys")
  const keys = await user.keys.find((e) => e.service === service.name);
  keys.keys.forEach((val, key) => {
    str = str.replaceAll("{" + key + "}", val);
  });
  return str;
};

exports.getDb = getDb;
exports.writeDb = writeDb;

exports.fillParams = fillParams;
exports.getHeaders = getHeaders;
exports.completeUrl = completeUrl;
