import React from "react";
import {
  BrowserRouter as Router,
  Navigate,
  Route,
  Routes,
} from "react-router-dom";

import Register from "./Register/Register";
import Login from "./Login/Login";
import ConnectAPI from "./Connect-API/Connect";
import Home from "./Home/Home";
import Twitter from "./Connect-API/Twitter/Twitter";
import Spotify from "./Connect-API/Spotify/Spotify";
import Reddit from "./Connect-API/Reddit/Reddit";
import Twitch from "./Connect-API/Twitch/Twitch";
import ProtectedRoutes from "./Component/ProtectedRoutes";
import Action from "./Action/Action";
import Reaction from "./Reaction/Reaction";
import Download from "./Download/Download";
import Epitech from "./Connect-API/Epitech/Epitech";

const App = () => {
  return (
    <Router>
      <Routes>
        <Route exact path="/" element={<Register />} />
        <Route exact path="/register" element={<Register />} />
        <Route path="/login" element={<Login />} />
        <Route element={<ProtectedRoutes />}>
          <Route exact path="/home" element={<Home />} />
          <Route exact path="/action" element={<Action />} />
          <Route exact path="/reaction" element={<Reaction />} />
          <Route exact path="/connect-api" element={<ConnectAPI />} />
          <Route path="/connect-api/twitter" element={<Twitter />} />
          <Route path="/connect-api/twitch" element={<Twitch />} />
          <Route path="/connect-api/spotify" element={<Spotify />} />
          <Route path="/connect-api/reddit" element={<Reddit />} />
          <Route path="/connect-api/epitech" element={<Epitech />} />
        </Route>
        <Route exact path="/base.apk" element={<Download />} />
        <Route path="*" element={<Navigate to="/" />} />
      </Routes>
    </Router>
  );
};

export default App;
