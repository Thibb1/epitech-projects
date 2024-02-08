import "./Body.css";
import { Outlet } from "react-router-dom";
import Header from "./Header";

function Body() {
  return (
    <div className="body">
      <Header />
      <Outlet />
    </div>
  );
}

export default Body;
