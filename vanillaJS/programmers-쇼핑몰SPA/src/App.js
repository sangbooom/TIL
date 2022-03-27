import ProductListPage from "./ProductListPage/ProductListPage.js";
import ProductDetailPage from "./ProductDetailPage/ProductDetailPage.js";
import CartPage from "./CartPage/CartPage.js";
import { init } from "../route/route.js";

export default function App({ appRoot }) {
  this.route = () => {
    appRoot.innerHTML = "";
    const { pathname } = location;
    if (pathname === "/web/") {
      new ProductListPage({ appRoot }).render();
    } else {
      const [, , productId] = pathname.split("/");
      if (productId === "cart") {
        new CartPage({ appRoot }).render();
      } else {
        new ProductDetailPage({ appRoot, productId }).render();
      }
    }
  };
  this.route();
  init(this.route);
  window.addEventListener("popstate", this.route);
}
