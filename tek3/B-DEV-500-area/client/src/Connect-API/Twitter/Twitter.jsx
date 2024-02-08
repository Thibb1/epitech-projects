import { useEffect } from "react";
import queryString from "query-string";
import { useNavigate } from "react-router-dom";
import { postServer } from "../../api";

export default function Twitter() {
  const navigate = useNavigate();
  useEffect(() => {
    try {
      const { oauth_token, oauth_verifier } = queryString.parse(
        window.location.search
      );
      if (oauth_token && oauth_verifier) {
        postServer("user/twitter/callback", {
          oauth_token,
          oauth_verifier,
        }).then(() => navigate("/connect-api", { replace: true }));
      }
    } catch (error) {
      console.error(error);
    }
  }, [navigate]);
  return null;
}
