export default function BreadCrumb({ parent, initialState }) {
  const BreadCrumbComponent = document.createElement("nav");
  BreadCrumbComponent.className = "Breadcrumb";
  parent.appendChild(BreadCrumbComponent);

  // const breadCrumbDiv = document.createElement('div');
  // breadCrumbDiv.innerText = 'root';

  this.state = initialState;

  this.setState = (nextState) => {
    this.state = nextState;

    this.render();
  };

  this.render = () => {
    console.log("breadCrumb", this.state);
    // 여기서 data-id 설정해놓고 App.js의 onclickBack에서 한번에 이동해서 값들도 이동한만큼 빼기
    BreadCrumbComponent.innerHTML = `
            <div>root</div>${this.state
              .map((target) => {
                return `<div>${target.name}</div>`;
              })
              .join("")}
        `;
  };
}
