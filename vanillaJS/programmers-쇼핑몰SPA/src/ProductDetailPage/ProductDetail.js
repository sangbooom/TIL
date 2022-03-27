import SelectedOptions from "./SelectedOptions.js";

export default function ProductDetail({ parent, initialState }) {
  this.state = initialState;

  let isInitialized = false;
  let selectedOptions = null;

  this.setState = (nextState) => {
    this.state = nextState;

    this.render();

    if (selectedOptions) {
      selectedOptions.setState({
        productDetail: this.state.productDetail,
        selectedOptions: this.state.selectedOptions,
      });
    }
  };

  this.render = () => {
    const { imageUrl, name, price, productOptions } = this.state.productDetail;
    console.log("productDetail의 state", this.state);
    if (!isInitialized) {
      parent.innerHTML = `
                <div class="ProductDetail">
                    <img src=${imageUrl}>
                    <div class="ProductDetail__info">
                        <h2>${name}</h2>
                        <div class="ProductDetail__price">${price.toLocaleString()}원~</div>
                        <select>
                            <option>선택하세요.</option>
                            ${productOptions.map(
                              ({
                                id,
                                name: optionName,
                                price: optionPrice,
                                stock,
                              }) => {
                                if (optionPrice)
                                  return `<option value=${id}>${name} ${optionName} (+${optionPrice.toLocaleString()}원)</option>`;
                                if (stock === 0)
                                  return `<option value=${id} disabled> (품절) ${name} ${optionName}</option>`;
                                return `<option value=${id}>${name} ${optionName}</option>`;
                              }
                            )}
                        </select>
                        <div class="ProductDetail__selectedOptions"></div>
                    </div>
                </div>
            `;
      selectedOptions = new SelectedOptions({
        parent: document.querySelector(".ProductDetail__selectedOptions"),
        initialState: {
          productDetail: this.state.productDetail,
          selectedOptions: this.state.selectedOptions,
        },
      });
      isInitialized = true;
    }
  };

  this.render();

  parent.addEventListener("change", (e) => {
    if (e.target.tagName === "SELECT") {
      const selectedOptionId = parseInt(e.target.value);
      const { productDetail, selectedOptions } = this.state;

      const option = productDetail.productOptions.find(
        (productOption) => productOption.id === selectedOptionId
      );
      const selectedOption = selectedOptions.find(
        (selectedOption) => selectedOption.optionId === selectedOptionId
      );

      if (option && !selectedOption) {
        const newSelectedOptions = [
          ...selectedOptions,
          {
            productId: productDetail.id,
            optionId: option.id,
            optionName: option.name,
            optionPrice: option.price,
            quantity: 1,
          },
        ];
        this.setState({
          ...this.state,
          selectedOptions: newSelectedOptions,
        });
      }
    }
  });
}
