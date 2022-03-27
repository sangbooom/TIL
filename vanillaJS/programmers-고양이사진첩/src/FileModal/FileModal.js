export default function FileModal() {
  this.state = null;
  this.setState = (nextState) => {
    this.state = nextState;

    this.render();
  };

  const bodyComponent = document.querySelector("body");
  const modalViewerComponent = document.createElement("div");
  modalViewerComponent.className = "Modal ImageViewer";
  bodyComponent.appendChild(modalViewerComponent);

  this.render = () => {
    modalViewerComponent.innerHTML = `
            <div class="content">
                <img src="https://fe-dev-matching-2021-03-serverlessdeploymentbuck-t3kpj3way537.s3.ap-northeast-2.amazonaws.com/public${this.state}">
            </div>
        `;
  };

  document.addEventListener("keydown", (e) => {
    if (e.key === "Escape") {
      modalViewerComponent.remove();
    }
  });

  modalViewerComponent.addEventListener("click", (e) => {
    if (e.target.tagName !== "IMG") {
      modalViewerComponent.remove();
    }
  });
}
