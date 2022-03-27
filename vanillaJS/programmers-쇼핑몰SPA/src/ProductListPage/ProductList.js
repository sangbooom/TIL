import { routeChange } from "../../route/route.js";

export default function ProductList({ parent, initialState }) {
  const productListWrap = document.createElement("ul");

  this.state = initialState;

  this.setState = (nextState) => {
    this.state = nextState;
    this.render();
  };

  parent.appendChild(productListWrap);

  productListWrap.addEventListener("click", function (e) {
    const li = e.target.closest("li");
    const { productId } = li.dataset;
    routeChange(productId);
  });

  this.render = () => {
    if (!this.state) {
      return;
    }
    productListWrap.innerHTML = this.state
      .map(({ id, imageUrl, name, price }) => {
        return `
                <li class="Product" data-product-id=${id}>
                    <img src=${imageUrl}>
                    <div class="Product__info">
                    <div>${name}</div>
                    <div>${price.toLocaleString()}원</div>
                    </div>
                </li>
            `;
      })
      .join(" ");
  };
  this.render();
}
