import "./Home.css";
import HomeBox, { Box } from "../Component/Home-Box";
import { useEffect, useState } from "react";
import { getServer } from "../api";
import { FaPlusCircle } from "react-icons/fa";
import { useNavigate } from "react-router-dom";

export default function Home() {
  const navigate = useNavigate();
  const [list, setList] = useState([]);
  useEffect(() => {
    getServer("user/getActionReaction").then((r) => setList(r.data));
  }, []);
  const filterList = (id: string) => {
    setList(list.filter(({ _id }) => _id !== id));
  };
  return (
    <div className="home-content">
      <h1>Select or edit your AREA</h1>
      <div className="home-container">
        {list.map((e) => {
          return (
            <HomeBox key={e._id} data={e} onDelete={() => filterList(e._id)} />
          );
        })}
      </div>
      <div className="home-container">
        <Box onClick={() => navigate("/action")}>
          <FaPlusCircle size={80} />
        </Box>
      </div>
      <div className="home-tuto">
        <h1>How to create an AREA ?</h1>
        <div className="home-tuto-box">
          <div className="circle circle-1">
            <h5>1</h5>
          </div>
          <div className="line line-0"></div>
          <div className="text text-0">
            <h5>Connect your api</h5>
          </div>
          <div className="line line-0"></div>
          <div className="circle circle-1">
            <h5>2</h5>
          </div>
          <div className="line line-1"></div>
          <div className="text text-1">
            <h5>Click on the "+"</h5>
          </div>
          <div className="line line-1"></div>
          <div className="circle circle-2">
            <h5>3</h5>
          </div>
          <div className="line line-2"></div>
          <div className="text text-2">
            <h5>Select an action</h5>
          </div>
          <div className="line line-1"></div>
          <div className="circle circle-3">
            <h5>4</h5>
          </div>
          <div className="line line-3"></div>
          <div className="text text-3">
            <h5>Select a reaction</h5>
          </div>
        </div>
        <h3>And that's it !</h3>
      </div>
    </div>
  );
}
