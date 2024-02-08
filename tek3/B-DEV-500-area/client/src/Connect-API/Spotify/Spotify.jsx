import { useEffect } from "react";
import queryString from "query-string";
import { useNavigate } from "react-router-dom";
import { postServer } from "../../api";

export default function Spotify() {
  const navigate = useNavigate();
  useEffect(() => {
    try {
      const { code } = queryString.parse(window.location.search);
      if (code) {
        postServer("user/spotify/callback", { code }).then(() =>
          navigate("/connect-api", { replace: true })
        );
      }
    } catch (error) {
      console.error(error);
    }
  }, [navigate]);
  return null;
}
