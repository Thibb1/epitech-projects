import React, { useEffect, useState } from "react";
import { Navigate } from "react-router-dom";
import { isConnected } from "../api";
import Body from "./Body";

export default function ProtectedRoutes() {
  const [element, setElement] = useState(<></>);
  useEffect(() => {
    isConnected()
      .then(() => setElement(<Body />))
      .catch(() => setElement(<Navigate to={"/login"} />));
  }, []);
  return element;
}
