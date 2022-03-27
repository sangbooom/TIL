import { request } from "../../api/api.js";
import ProductList from "./ProductList.js";

export default function ProductListPage({ appRoot }) {
  const productListPage = document.createElement("div");
  productListPage.className = "ProductListPage";
  productListPage.innerHTML = "<h1>상품목록</h1>";

  this.setState = (nextState) => {
    this.state = nextState;
    this.render();
  };

  this.getProductList = async () => {
    const productList = await request("/products");
    // console.log("productList",productList)
    this.setState(productList);
  };

  this.getProductList();

  this.render = () => {
    appRoot.appendChild(productListPage);
    new ProductList({ parent: productListPage, initialState: this.state });
  };
}
