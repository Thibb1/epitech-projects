import AsyncStorage from '@react-native-async-storage/async-storage';

export async function getItem(key: string) {
  try {
    const item = await AsyncStorage.getItem(key);
    return JSON.parse(item);
  } catch (e) {
    console.log(`Couldn't getItem '${key}'`);
    console.log(e);
  }
}

export async function setItem(key: string, item: any) {
  try {
    const jsonItem = JSON.stringify(item);
    await AsyncStorage.setItem(key, jsonItem);
    console.log(`'${key}' set`);
  } catch (e) {
    console.log(`Couldn't setItem '${key}'`);
    console.log(e);
  }
}

export async function removeItem(key: string) {
  try {
    await AsyncStorage.removeItem(key);
  } catch (e) {
    console.log(`Couldn't removeItem '${key}'`);
    console.log(e);
  }
}

export function getParams(url: string) {
  const regex = /[?&]([^=#]+)=([^&#]*)/g;
  const params = {};
  let match;
  while ((match = regex.exec(url))) {
    params[match[1]] = match[2];
  }
  return params;
}
