export default function Nodes({ parent, initialState, onclick, onclickBack }) {
  this.onclick = onclick;
  this.onclickBack = onclickBack;
  const nodesComponent = document.createElement("div");
  nodesComponent.className = "Nodes";
  parent.appendChild(nodesComponent);

  this.state = initialState;

  this.setState = (nextState) => {
    this.state = nextState;

    this.render();
  };

  this.render = () => {
    const renderNodes = this.state
      .map(
        ({ id, type, name }) =>
          `
                <div class="Node" data-id=${id}>
                    <img src=${
                      type === "DIRECTORY"
                        ? "./assets/directory.png"
                        : "./assets/file.png"
                    } />
                    <div>${name}</div>
                </div>
            `
      )
      .join("");

    nodesComponent.innerHTML = this.state[0].parent
      ? `
            <div class="Node">
                <img src="./assets/prev.png">
            </div>
            ${renderNodes}
        `
      : renderNodes;
  };

  nodesComponent.addEventListener("click", (e) => {
    if (e.target.closest(".Node")) {
      const nodeId = e.target.closest(".Node").dataset.id;
      const targetNode = this.state.find((node) => node.id === nodeId);
      if (targetNode) {
        this.onclick(targetNode);
      } else {
        this.onclickBack();
      }
    }
  });
}
