import "./Header.css";
import { Link } from "react-router-dom";
import { FaHome, FaLink } from "react-icons/fa";
import { removeCookie } from "../cookie";

function Header() {
  const logout = async () => {
    await removeCookie("TOKEN");
    window.location.href = "/login";
    return false;
  };
  return (
    <div className="header">
      <Link className="link" to="/connect-api">
        <FaLink size={30} />
        Connect another API
      </Link>
      <Link className="link" to="/home">
        <FaHome size={30} />
        Home
      </Link>
      <button className="button" onClick={logout}>
        Logout
      </button>
    </div>
  );
}

export default Header;
