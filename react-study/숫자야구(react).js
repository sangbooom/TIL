import React, { useState, useEffect, useRef } from "react";
function shuffle (arr) {
  let j, x, index;
  for (index = arr.length - 1; index > 0; index--) {
      j = Math.floor(Math.random() * (index + 1));
      x = arr[index];
      arr[index] = arr[j];
      arr[j] = x;
  }
  return arr;
}
export default function App() {
  const [text, setText] = useState("");
  const [trys, setTrys] = useState([]);
  const [randomStr, setRandomStr] = useState([]);
  const [result, setResult] = useState([]);

  useEffect(() => {
    randomGenStr();
  }, []);
 
  useEffect(() => {
    console.log("randomStr", randomStr);
  }, [randomStr]);
  const randomGenStr = () => {
    setRandomStr(shuffle([0,1,2,3,4,5,6,7,8,9]).splice(0,4));
  };
  const onChangeInput = (e) => {
    setText(e.target.value);
  };
  const onKeyPressHandler = (e) => {
    if (e.key === "ENTER") {
      onSubmitHandler();
    }
  };
  const onSubmitHandler = (e) => {
    e.preventDefault();
    setTrys([text]);
    setText("");
    console.log(trys);

    let a = randomStr.join("");
    console.log(a);
    console.log(trys[0]);
    let ball = 0;
    let strike = 0;

    for(let i=0; i<4; i++){
      if(trys.includes(a[i])){
        ball++;
      }
      if(trys[i] === a[i]){
        strike++;
      }
    }
    setResult([...result, {len : result.length, record: `${strike}스트라이크, ${ball}볼`}]);
  };
  return (
    <div>
      <form onSubmit={onSubmitHandler}>
        <input
          onChange={onChangeInput}
          value={text}
          onKeyPress={onKeyPressHandler}
        />
      </form>
      <div style={{ margin: "10px 0" }}>시도 : {trys.length}</div>
      <ul>
        {trys.length >= 1 &&
          trys.map((tryNum, index) => (
            <li key={index}>
              {tryNum}
              <br /> {result.record}
            </li>
          ))}
      </ul>
    </div>
  );
}
