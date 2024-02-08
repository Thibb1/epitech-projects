import "./Register.css";

import React, { useEffect, useState } from "react";
import { Button, Form } from "react-bootstrap";
import { Link, useNavigate } from "react-router-dom";
import { craftUri, isConnected, postServer } from "../api";
import { setCookie } from "../cookie";
import { FcGoogle } from "react-icons/fc";

export default function Register() {
  const navigate = useNavigate();
  useEffect(() => {
    isConnected()
      .then(() => navigate("/home"))
      .catch(() => {});
  }, [navigate]);
  const [username, setUser] = useState("");
  const [password, setPassword] = useState("");
  const [register, setRegister] = useState(false);
  const client = {
    username,
    password,
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    if (client.password.length < 1) return;
    postServer("signup", client)
      .then((res) => {
        setRegister(true);
        setCookie("TOKEN", res.data.token);
        navigate("/home");
      })
      .catch(() => console.log("Submit error"));
  };

  return (
    <>
      <div className="home">
        <div className="register-box">
          <h1 className="title">Register</h1>
          <Form onSubmit={(e) => handleSubmit(e)}>
            <div className="register-box-btns">
              <Form.Group controlId="formUsername">
                <label htmlFor="username"></label>
                <input
                  value={username}
                  type="text"
                  name="username"
                  placeholder="Username"
                  className="btn"
                  onChange={(e) => setUser(e.target.value)}
                  required
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
                  required
                />
              </Form.Group>
              <div className="separator">
                <div className="line"></div>
                <h6>or</h6>
                <div className="line"></div>
              </div>
              <div className="register-box-icons">
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
              Register
            </Button>
            {register ? (
              <p className="text-success">You are successfully registered</p>
            ) : (
              <p className="text-danger">You are not registered</p>
            )}
          </Form>
          <p>
            You already have an account ? Go to <Link to="/login">login</Link>
          </p>
        </div>
        <div className="phone">
          <Link className="phone-link" to="base.apk">
            <input
              type="submit"
              className=" phone-input"
              value="Download mobile client"
            />
          </Link>
        </div>
      </div>
    </>
  );
}
