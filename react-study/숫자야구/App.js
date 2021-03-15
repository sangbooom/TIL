import React, { useState, useEffect, useRef } from "react";
import Show from "./Show";
function shuffle(arr) {
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
  const [randomStr, setRandomStr] = useState([]);
  const [result, setResult] = useState([]);

  useEffect(() => {
    randomGenStr();
  }, []);

  useEffect(() => {
    console.log("randomStr", randomStr);
  }, [randomStr]);

  useEffect(() => {
    console.log("result", result);
  }, [result]);

  const randomGenStr = () => {
    setRandomStr(shuffle([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]).splice(0, 4));
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

    let ball = 0;
    let strike = 0;
    let targetNumber = randomStr.join("");

    if (text === targetNumber) {
      alert("홈런!!");
      randomGenStr();
      setResult([]);
      setText("");
      return;
    }
    if (result.length >= 9) {
      alert(`답은 ${targetNumber}입니다.`);
      randomGenStr();
      setResult([]);
      setText("");
      return;
    } else {
      for (let i = 0; i < 4; i++) {
        if (text.includes(targetNumber[i])) {
          ball++;
        }
        if (text[i] === targetNumber[i]) {
          strike++;
        }
      }
    }
    setResult([
      ...result,
      { try: text, record: `${strike}스트라이크, ${ball}볼` }
    ]);
    setText("");
  };
  return (
    <div>
      <form onSubmit={onSubmitHandler}>
        <input
          type="number"
          maxLength={4}
          onChange={onChangeInput}
          value={text}
          onKeyPress={onKeyPressHandler}
        />
      </form>
      <div style={{ margin: "10px 0" }}>남은 기회 : {10 - result.length}</div>
      <ul>
        {result.length >= 1 &&
          result.map((results, index) => (
            // <Show results={results} key={index} />
            <li key={index}>
              <div>{results.try}</div>
              <div>{results.record}</div>
            </li>
          ))}
      </ul>
    </div>
  );
}
