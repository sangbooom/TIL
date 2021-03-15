import React from "react";

function Show({ results }) {
  return (
    <li>
      <div>{results.try}</div>
      <div>{results.record}</div>
    </li>
  );
}

export default React.memo(Show);