const ROUTE_CHANGE = "ROUTE_CHANGE";

export const init = (onRouteChange) => {
  window.addEventListener("ROUTE_CHANGE", () => {
    onRouteChange();
  });
};

export const routeChange = (url) => {
  history.pushState(null, null, url);
  window.dispatchEvent(new CustomEvent(ROUTE_CHANGE), null);
};
