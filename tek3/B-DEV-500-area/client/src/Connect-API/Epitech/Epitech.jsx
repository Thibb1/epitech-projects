import "./Epitech.css";
import { useNavigate } from "react-router-dom";
import React, { useState } from "react";
import { postServer } from "../../api";

export default function Epitech() {
  const navigate = useNavigate();
  const [cookie, setCookie] = useState("");

  function handleSubmit() {
    postServer("user/epitech/callback", { user_cookie: cookie })
      .then(() => navigate("/connect-api", { replace: true }))
      .catch((e) => {
        console.log("error", e);
      });
  }

  return (
    <div className="epitech-page">
      <div className="how-to">
        <img src="/get_cookie.png" alt="How to get your cookie" />
        <h4>To open your console, right click and click on "Inspect".</h4>
        <a href="https://intra.epitech.eu" target="_blank" rel="noreferrer">
          Get my cookie
        </a>
      </div>
      <div className="epitech-form">
        <h5>Paste it here !</h5>
        <input
          className="text-input"
          type="text"
          onChange={(e) => setCookie(e.target.value)}
          onKeyDown={(event) => {
            if (event.key === "Enter") {
              handleSubmit();
            }
          }}
          value={cookie}
        />
        <input
          className="button"
          type="button"
          value="Add Epitech cookie"
          maxLength={300}
          disabled={cookie.length <= 100}
          onClick={() => {
            handleSubmit();
          }}
        />
      </div>
    </div>
  );
}
