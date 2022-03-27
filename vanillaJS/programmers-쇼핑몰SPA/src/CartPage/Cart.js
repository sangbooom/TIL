import { routeChange } from "../../route/route.js";

export default function Cart({ parent, initialState }) {
  const component = document.createElement("div");
  component.className = "Cart";

  parent.appendChild(component);

  this.state = initialState;

  this.setState = (nextState) => {
    this.state = nextState;
    this.render();
  };

  this.totalPrice = () => {
    return this.state
      .reduce(
        (acc, option) =>
          acc + (option.productPrice + option.optionPrice) * option.quantity,
        0
      )
      .toLocaleString();
  };

  this.render = () => {
    // console.log("Cart",this.state)

    component.innerHTML = `
            <ul>
                ${this.state
                  .map(
                    ({
                      imageUrl,
                      optionPrice,
                      productName,
                      optionName,
                      productPrice,
                      quantity,
                    }) => {
                      return `
                        <li class="Cart__item">
                            <img src=${imageUrl}>
                            <div class="Cart__itemDesription">
                            <div>${productName} ${optionName} ${productPrice.toLocaleString()}원 ${quantity}개</div>
                            <div>${
                              (optionPrice + productPrice) * quantity
                            }원</div>
                            </div>
                        </li>
                    `;
                    }
                  )
                  .join("")}
            </ul>
            <div class="Cart__totalPrice">
                총 상품가격 ${this.totalPrice()}원
            </div>
            <button class="OrderButton">주문하기</button>
        `;
    return component;
  };
  this.render();

  component.addEventListener("click", (e) => {
    if (e.target.tagName === "BUTTON") {
      alert("주문되었습니다");
      routeChange("/web/");
      window.localStorage.removeItem("products_cart");
    }
  });
}
