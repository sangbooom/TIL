import { routeChange } from "../../route/route.js";

export default function SelectedOptions({ parent, initialState }) {
  const component = document.createElement("div");
  parent.appendChild(component);

  this.state = initialState;

  this.setState = (nextState) => {
    this.state = nextState;
    this.render();
  };

  this.totalPrice = () => {
    const { productDetail, selectedOptions } = this.state;
    const { price: productPrice } = productDetail;

    return selectedOptions
      .reduce(
        (acc, option) =>
          acc + (productPrice + option.optionPrice) * option.quantity,
        0
      )
      .toLocaleString();
  };

  this.render = () => {
    const { productDetail, selectedOptions = [] } = this.state;
    console.log("SelectedOptions의 state", this.state);
    if (productDetail && selectedOptions) {
      component.innerHTML = `
                <h3>선택된 상품</h3>
                <ul>
                    ${selectedOptions
                      .map(
                        ({ optionId, optionName, optionPrice, quantity }) => `
                            <li>
                                ${optionName} ${
                          productDetail.price + optionPrice
                        }원 
                                <input type="text" data-option-id=${optionId} value=${quantity}>
                            </li>
                        `
                      )
                      .join("")}
                </ul>
                <div class="ProductDetail__totalPrice">${this.totalPrice()}원</div>
                <button class="OrderButton">주문하기</button>
            `;
    }
  };
  this.render();

  component.addEventListener("change", (e) => {
    if (e.target.tagName === "INPUT") {
      try {
        const nextQuantity = parseInt(e.target.value);
        const nextSelectedOptions = [...this.state.selectedOptions];
        console.log("nextQuantity", nextQuantity);
        if (nextQuantity) {
          const { productDetail } = this.state;

          const optionId = parseInt(e.target.dataset.optionId);
          console.log(optionId);
          const option = productDetail.productOptions.find(
            (productOption) => productOption.id === optionId
          );
          const selectedOptionIndex = nextSelectedOptions.findIndex(
            (selectedOption) => selectedOption.optionId === optionId
          );

          nextSelectedOptions[selectedOptionIndex].quantity =
            option.stock < nextQuantity ? option.stock : nextQuantity;

          this.setState({
            ...this.state,
            selectedOptions: nextSelectedOptions,
          });
        }
      } catch (error) {
        console.log(error);
      }
    }
  });

  component.addEventListener("click", (e) => {
    const getLocalData = JSON.parse(
      window.localStorage.getItem("products_cart")
    );
    if (e.target.tagName === "BUTTON") {
      if (this.state.selectedOptions.length > 0) {
        if (window.localStorage.getItem("products_cart")) {
          window.localStorage.setItem(
            "products_cart",
            JSON.stringify(
              getLocalData.concat(
                this.state.selectedOptions.map((selectedOption) => {
                  delete selectedOption.optionName;
                  delete selectedOption.optionPrice;
                  return selectedOption;
                })
              )
            )
          );
        } else {
          window.localStorage.setItem(
            "products_cart",
            JSON.stringify(
              this.state.selectedOptions.map((selectedOption) => {
                delete selectedOption.optionName;
                delete selectedOption.optionPrice;
                return selectedOption;
              })
            )
          );
        }
        routeChange("/web/cart");
      }
    }
  });
}
