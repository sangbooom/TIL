방법 1. 
```javascript
import React, { useState, Component } from "react";

export default class App extends Component {
  input = React.createRef();

  handleFocus = () => {
    this.input.current.focus();
  };

  render() {
    return (
      <div>
        <input ref={this.input} />
        <button onClick={this.handleFocus}>검증</button>
      </div>
    );
  }
}
```
---
방법 2.

```javascript
import React, { Component } from "react";
import "./ValidationSample.css";

export default class ValidationSample extends Component {
  state = {
    password: "",
    clicked: false,
    validated: false,
  };
  handleChange = (e) => {
    this.setState({
      password: e.target.value,
    });
  };

  handleButtonClick = () => {
    this.setState({
      clicked: true,
      validated: this.state.password === "0000" ? true : false
    });
    this.input.focus();
  };

  render() {
    return (
      <div>
        <input
          ref={(ref) => {this.input = ref}}
          type="password"
          value={this.state.password}
          onChange={this.handleChange}
          className={
            this.state.clicked
              ? (this.state.validated
                ? "success"
                : "failure")
              : ""
          }
        />
        <button onClick={this.handleButtonClick}>검증하기</button>
      </div>
    );
  }
}
```
---
방법 3.

App.js
```javascript
import React, { useState, Component } from "react";
import ScrollBox from "./ScrollBox";

export default class App extends Component {
  render() {
    return (
      <div>
        <ScrollBox ref={(ref) => this.ScrollBox = ref} />
        <button onClick={() => this.ScrollBox.ScrollToBottom()}>
          맨 밑으로
        </button>
      </div>
    );
  }
}

```
ScrollBox.js
```javascript
import React, { Component } from "react";

export default class ScrollBox extends Component {
  ScrollToBottom = () => {
    const { scrollHeight, clientHeight } = this.box;
    this.box.scrollTop = scrollHeight - clientHeight;
  };
  render() {
    const style = {
      border: "1px solid black",
      height: "300px",
      width: "300px",
      overflow: "auto",
      position: "relative",
    };
    const innerStyle = {
      width: "100%",
      height: "650px",
      background: "linear-gradient(white, black)",
    };
    return (
      <div
        style={style}
        ref={(ref) => {
          this.box = ref;
        }}
      >
        <div style={innerStyle} />
      </div>
    );
  }
}

```
