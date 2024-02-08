import Cookies from "universal-cookie";

const cookies = new Cookies();

export function getCookie(name: string) {
  return cookies.get(name) ?? "";
}

export function setCookie(name: string, data: any) {
  cookies.set(name, data);
}

export function removeCookie(name: string) {
  cookies.remove(name);
}
