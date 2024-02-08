import "./Login.css";
import { FcGoogle } from "react-icons/fc";
import React, { useEffect, useState } from "react";
import { Button, Form } from "react-bootstrap";
import { Link, useLocation, useNavigate } from "react-router-dom";
import { craftUri, isConnected, postServer } from "../api";
import { setCookie } from "../cookie";

export default function Login() {
  const navigate = useNavigate();
  const location = useLocation();
  useEffect(() => {
    const params = new URLSearchParams(location.search);
    if (params.has("jwt")) {
      setCookie("TOKEN", params.get("jwt"));
    }
    isConnected()
      .then(() => navigate("/home"))
      .catch(() => {});
  }, [location, navigate]);
  const [username, setUser] = useState("");
  const [password, setPassword] = useState("");
  const [login, setLogin] = useState(false);
  const client = {
    username,
    password,
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    if (client.password.length < 1) return;
    postServer("login", client)
      .then((res) => {
        setLogin(true);
        setCookie("TOKEN", res.data.token);
        navigate("/home");
      })
      .catch(() => console.log("Submit error"));
  };

  return (
    <>
      <div className="home">
        <div className="login-box">
          <h1 className="title">Login</h1>
          <Form onSubmit={(e) => handleSubmit(e)}>
            <div className="login-box-btns">
              <Form.Group controlId="formUsername">
                <label htmlFor="username"></label>
                <input
                  value={username}
                  type="text"
                  name="username"
                  placeholder="Username"
                  className="btn"
                  onChange={(e) => setUser(e.target.value)}
                />
              </Form.Group>
              <Form.Group controlId="formPassword">
                <label htmlFor="password"></label>
                <input
                  value={password}
                  type="password"
                  name="password"
                  placeholder="Password"
                  className="btn"
                  onChange={(e) => setPassword(e.target.value)}
                  onKeyDown={(event) => {
                    if (event.key === "Enter") {
                      handleSubmit(event);
                    }
                  }}
                />
              </Form.Group>
              <div className="separator">
                <div className="line"></div>
                <h6>or</h6>
                <div className="line"></div>
              </div>
              <div className="login-box-icons">
                <a href={craftUri("google")}>
                  <div className="oauth-button">
                    <FcGoogle className="icon" />
                    <h6>Log in with google</h6>
                  </div>
                </a>
              </div>
            </div>
            <Button
              variant="primary"
              type="submit"
              className="login-btn"
              onClick={(e) => handleSubmit(e)}
            >
              Login
            </Button>
            {login ? (
              <p className="text-success">You are logged in</p>
            ) : (
              <p className="text-danger">You are not logged in</p>
            )}
          </Form>
          <p>
            You don't have an account ? Back to{" "}
            <Link to="/register">register</Link>
          </p>
        </div>
        <div className="phone">
          <Link className="phone-link" to="/base.apk">
            <input
              type="submit"
              className="phone-input"
              value="Download mobile client"
            />
          </Link>
        </div>
      </div>
    </>
  );
}
