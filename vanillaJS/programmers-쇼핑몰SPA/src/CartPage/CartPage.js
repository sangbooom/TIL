import { request } from "../../api/api.js";
import Cart from "./Cart.js";
import { routeChange } from "../../route/route.js";

export default function CartPage({ appRoot }) {
  const cartPage = document.createElement("div");
  cartPage.className = "CartPage";
  cartPage.innerHTML = "<h1>장바구니</h1>";

  this.state = {
    products: null,
  };

  const cartData =
    JSON.parse(window.localStorage.getItem("products_cart")) ?? [];

  this.setState = (nextState) => {
    this.state = nextState;
    console.log("4");
    this.render();
  };

  this.fetchProducts = async () => {
    const products = await Promise.all(
      cartData.map(async (data) => {
        const productData = await request(`/products/${data.productId}`);
        const selectedData = productData.productOptions.find(
          (optionData) => optionData.id === data.optionId
        );

        return {
          imageUrl: productData.imageUrl,
          productName: productData.name,
          productPrice: productData.price,
          optionName: selectedData.name,
          optionPrice: selectedData.price,
          quantity: data.quantity,
        };
      })
    );
    this.setState({ products });
    console.log("2");
  };

  this.fetchProducts();
  // if( ) {
  this.render = () => {
    console.log("1 render");
    console.log("cartData", cartData);
    if (!cartData.length) {
      alert("장바구니가 비었습니다");
      console.log("3");
      routeChange("/web/");
    } else {
      appRoot.appendChild(cartPage);
      new Cart({
        parent: cartPage,
        initialState: this.state.products,
      });
    }
  };
  // }
}
