import "./Action.css";
import { useEffect, useState } from "react";
import { getServer } from "../api";
import { FaLink, FaReddit, FaTwitch, FaTwitter } from "react-icons/fa";
import { SocialIcon } from "react-social-icons";
import { useNavigate } from "react-router-dom";
import { Box } from "../Component/Home-Box";

function Action() {
  const navigate = useNavigate();
  const [list, setList] = useState([]);
  const [filtered, setFiltered] = useState([]);
  const [twitch, setTwitch] = useState(true);
  const [twitter, setTwitter] = useState(true);
  const [reddit, setReddit] = useState(true);
  const [epitech, setEpitech] = useState(true);
  const [spotify, setSpotify] = useState(true);
  const [hidden, setHidden] = useState(undefined);
  const [updated, setUpdated] = useState(false);

  useEffect(() => {
    getServer("user/getActions")
      .then((r) => {
        setList(r.data);
        setFiltered(r.data);
      })
      .catch(() => console.log("Can't get action list"));
    const hasApi = async (api, setter) => {
      return await getServer("user/hasApi/" + api)
        .then((res) => {
          setter(res.data);
        })
        .catch(() => console.log(`Couldn't get ${api} status`));
    };
    const getAll = async () => {
      await hasApi("reddit", setReddit);
      await hasApi("twitter", setTwitter);
      await hasApi("twitch", setTwitch);
      await hasApi("epitech", setEpitech);
      await hasApi("spotify", setSpotify);
    };
    getAll().then(() => setUpdated(true));
  }, []);

  useEffect(() => {
    setHidden({ twitch, twitter, reddit, epitech, spotify });
  }, [updated]);

  const filterByApi = (data) => {
    return data.filter(
      ({ service }) =>
        (twitch || service.name !== "twitch") &&
        (twitter || service.name !== "twitter") &&
        (reddit || service.name !== "reddit") &&
        (epitech || service.name !== "epitech") &&
        (spotify || service.name !== "spotify")
    );
  };

  useEffect(() => {
    const filteredData = filterByApi(list);
    setFiltered(filteredData);
  }, [twitch, twitter, reddit, epitech, spotify]);

  return (
    <div className="action-page">
      <h1 className="action-title">When ___</h1>
      <div className="action-icons">
        <button
          onClick={() => setTwitch(!twitch)}
          className="action-background twitch-icon twitch-button"
          style={
            !hidden?.twitch
              ? { display: "none" }
              : twitch
              ? styles.on
              : styles.off
          }
        >
          <FaTwitch size={40} className="twitch-icon action-icon" />
        </button>
        <button
          onClick={() => setTwitter(!twitter)}
          className="action-background twitter-icon twitter-button"
          style={
            !hidden?.twitter
              ? { display: "none" }
              : twitter
              ? styles.on
              : styles.off
          }
        >
          <FaTwitter size={40} className="twitter-icon action-icon" />
        </button>
        <button
          onClick={() => setReddit(!reddit)}
          className="action-background reddit-icon reddit-button"
          style={
            !hidden?.reddit
              ? { display: "none" }
              : reddit
              ? styles.on
              : styles.off
          }
        >
          <FaReddit size={40} className="reddit-icon action-icon" />
        </button>
        <button
          onClick={() => setEpitech(!epitech)}
          className="action-background epitech-icon epitech-button"
          style={
            !hidden?.epitech
              ? { display: "none" }
              : epitech
              ? styles.on
              : styles.off
          }
        >
          <img
            src="/epitechlogo.png"
            alt="epitech"
            className="epitech-icon action-icon"
          />
        </button>
        <button
          onClick={() => setSpotify(!spotify)}
          className="action-background spotify-icon spotify-button"
          style={
            !hidden?.spotify
              ? { display: "none" }
              : spotify
              ? styles.on
              : styles.off
          }
        >
          <SocialIcon
            network="spotify"
            size={40}
            className="spotify-icon action-icon"
          />
        </button>
      </div>
      {updated && !filtered?.length > 0 ? (
        <Box onClick={() => navigate("/connect-api")}>
          <FaLink size={80} />
        </Box>
      ) : (
        <></>
      )}
      <div className="action-boxes">
        {filtered.map((action) => {
          const optionSet = action.options?.every((o) => o?.value?.length > 0);
          const handleClick = () => {
            if (optionSet) {
              navigate("/reaction", {
                state: { id: action._id, options: action.options ?? [] },
              });
            }
          };
          return (
            <div
              className={`action-box${optionSet ? " enabled" : ""} ${
                action.service.name
              }`}
              key={action._id}
              onClick={handleClick}
            >
              <div className={"action-info"}>
                {icons[action.service.name]}
                <div className="action-info-name">{action.name}</div>
              </div>
              <div className="option-boxes">
                {action.options?.map((option) => {
                  const handleChange = (e) => {
                    const newList = list.map((item) => {
                      if (item._id === action._id) {
                        return {
                          ...item,
                          options: action.options.map((newOption) => {
                            if (newOption.name === option.name) {
                              return { ...newOption, value: e.target.value };
                            }
                            return newOption;
                          }),
                        };
                      }
                      return item;
                    });

                    setList(newList);
                    setFiltered(filterByApi(newList));
                  };
                  return (
                    <div
                      className="option-box"
                      key={option.name}
                      onClick={(e) => e.stopPropagation()}
                    >
                      <div className="option-name">{option.name}</div>
                      <input
                        className="option-input"
                        value={option.value ?? ""}
                        placeholder={option.placeholder ?? "..."}
                        onChange={handleChange}
                      />
                    </div>
                  );
                })}
              </div>
            </div>
          );
        })}
      </div>
    </div>
  );
}

export const icons = {
  twitter: <FaTwitter size={40} className="twitter-icon" />,
  reddit: <FaReddit size={40} className="reddit-icon" />,
  twitch: <FaTwitch size={40} className="twitch-icon" />,
  spotify: <SocialIcon network="spotify" size={30} className="spotify-icon" />,
  epitech: (
    <img className="epitech-logo" src="/epitechlogo.png" alt="epitech" />
  ),
};

export const styles = {
  on: {
    border: "2px solid green",
    transform: "scale(1.1)",
  },
  off: {
    border: "2px solid red",
    filter: "brightness(80%)",
  },
};

export default Action;
