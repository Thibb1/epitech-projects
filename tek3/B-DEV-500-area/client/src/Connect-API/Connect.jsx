import "./Connect.css";
import React, { useEffect, useState } from "react";
import { Link } from "react-router-dom";
import { deleteServer, getServer } from "../api";

export default function Connect() {
  const [twitch, setTwitch] = useState(false);
  const [twitter, setTwitter] = useState(false);
  const [reddit, setReddit] = useState(false);
  const [epitech, setEpitech] = useState(false);
  const [spotify, setSpotify] = useState(false);

  const toggleApi = (api: string, state: boolean, setter) => {
    if (state) {
      deleteServer("user/deleteAPI/" + api)
        .then(() => setter(false))
        .catch(() => {});
      return;
    }
    getServer(`user/${api}/addAccount`).then(
      (res) => (window.location.href = res.data["path"])
    );
  };
  useEffect(() => {
    const hasApi = (api, setter) => {
      getServer("user/hasApi/" + api)
        .then((res) => {
          setter(res.data);
        })
        .catch(() => console.log(`Couldn't get ${api} status`));
    };
    hasApi("reddit", setReddit);
    hasApi("twitter", setTwitter);
    hasApi("twitch", setTwitch);
    hasApi("epitech", setEpitech);
    hasApi("spotify", setSpotify);
  }, []);

  return (
    <div className="connect-page">
      <h1>Connect to your API's</h1>
      <h3>By doing this, you consent the usage of your data</h3>
      <div className="api-buttons">
        <input
          type="submit"
          value="Twitch"
          className={twitch ? "api-btn-connected" : "api-btn"}
          onClick={() => toggleApi("twitch", twitch, setTwitch)}
        />
        <input
          type="submit"
          value="Reddit"
          className={reddit ? "api-btn-connected" : "api-btn"}
          onClick={() => toggleApi("reddit", reddit, setReddit)}
        />
        <input
          type="submit"
          value="Twitter"
          className={twitter ? "api-btn-connected" : "api-btn"}
          onClick={() => toggleApi("twitter", twitter, setTwitter)}
        />
        <input
          type="submit"
          value="Spotify"
          className={spotify ? "api-btn-connected" : "api-btn"}
          onClick={() => toggleApi("spotify", spotify, setSpotify)}
        />
        <Link
          to="epitech"
          value="Epitech"
          className={epitech ? "api-btn-connected" : "api-btn"}
          onClick={(e) => {
            if (epitech) {
              e.preventDefault();
              toggleApi("epitech", epitech, setEpitech);
            }
          }}
        >
          Epitech
        </Link>
      </div>
    </div>
  );
}
