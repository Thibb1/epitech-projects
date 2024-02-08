import { Navigate } from "react-router-dom";

export default function Download() {
  window.location.href = "/app/base.apk";
  return <Navigate to="/" />;
}
