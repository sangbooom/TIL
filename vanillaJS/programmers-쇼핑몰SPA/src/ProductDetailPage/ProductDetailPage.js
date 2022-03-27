import { request } from "../../api/api.js";
import ProductDetail from "./ProductDetail.js";

export default function ProductDetailPage({ appRoot, productId }) {
  const productDetailPage = document.createElement("div");
  productDetailPage.className = "ProductDetailPage";
  productDetailPage.innerHTML = "<h1>커피잔 상품 정보</h1>";

  this.state = {
    productId,
    productDetail: null,
  };

  this.setState = (nextState) => {
    this.state = nextState;
    this.render();
  };

  this.getProductDetail = async () => {
    const { productId } = this.state;
    const productDetail = await request(`/products/${productId}`);
    this.setState({ ...this.state, productDetail });
  };

  this.getProductDetail();

  this.render = () => {
    const { productDetail } = this.state;
    if (!productDetail) {
      appRoot.innerHTML = "<h1>loading...</h1>";
    } else {
      appRoot.innerHTML = "";
      appRoot.appendChild(productDetailPage);
      new ProductDetail({
        parent: productDetailPage,
        initialState: {
          productDetail,
          selectedOptions: [],
        },
      });
    }
  };
}
