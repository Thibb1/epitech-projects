import axios from "axios";
import { getCookie } from "../cookie";

function token() {
  return getCookie("TOKEN");
}

export function craftUri(endpoint: string) {
  const uri = new URL(process.env.REACT_APP_API_URL);
  uri.pathname = endpoint;
  return uri;
}

export async function getServer(endpoint: string) {
  const uri = craftUri(endpoint);
  return await axios.get(uri, {
    headers: { Authorization: "Bearer " + token() },
  });
}

export async function postServer(endpoint: string, data: any) {
  const uri = craftUri(endpoint);
  return await axios.post(uri, data, {
    headers: { Authorization: "Bearer " + token() },
  });
}

export async function deleteServer(endpoint: string) {
  const uri = craftUri(endpoint);
  return await axios.delete(uri, {
    headers: { Authorization: "Bearer " + token() },
  });
}

export async function isConnected() {
  if (token().length > 0) {
    return await getServer("user/profile");
  }
  throw new Error("No token auth token set");
}
