import "./Home-Box.css";
import { FaPencilAlt, FaTrashAlt } from "react-icons/fa";
import { deleteServer } from "../api";
import { useNavigate } from "react-router-dom";

export function Box({ children, onClick }) {
  return (
    <div onClick={onClick} className="box actionable">
      {children}
    </div>
  );
}

function HomeBox({ data, onDelete }) {
  const navigate = useNavigate();
  const { reaction, action, _id } = data;
  console.log(data);
  const handleDelete = () => {
    deleteServer("user/deleteActionReaction/" + _id)
      .then(() => onDelete())
      .catch((e) => console.log(e));
  };
  return (
    <div className="box">
      <div className="text">
        <div className="bold">Do</div>
        <div>{reaction.name}</div>
        <div className="bold">When</div>
        <div>{action.name}</div>
      </div>
      <div className="icons">
        <div
          className="pencil"
          onClick={() => {
            handleDelete();
            navigate("/action");
          }}
        >
          <FaPencilAlt size={25} />
        </div>
        <div className="trash" onClick={handleDelete}>
          <FaTrashAlt size={25} />
        </div>
      </div>
    </div>
  );
}
export default HomeBox;
