import { request } from "../api/api.js";
import FileModal from "./FileModal/FileModal.js";
import BreadCrumb from "./BreadCrumb/BreadCrumb.js";
import Nodes from "./Nodes/Nodes.js";

export default function App({ appRoot }) {
  this.state = {
    nodes: [],
    depth: [],
    targets: [],
  };
  this.setState = (nextState) => {
    this.state = nextState;

    breadCrumbComponent.setState(this.state.targets);
    nodesComponent.setState(this.state.nodes);
  };

  const breadCrumbComponent = new BreadCrumb({
    parent: appRoot,
    initialState: this.state.targets,
  });
  const nodesComponent = new Nodes({
    parent: appRoot,
    initialState: this.state.nodes,
    onclick: async (targetNode) => {
      if (targetNode.type === "DIRECTORY") {
        try {
          const childNodeData = await request(`/${targetNode.id}`);
          // console.log("childNodeData", childNodeData)
          // console.log("targetNode",targetNode)
          this.setState({
            ...this.state,
            nodes: childNodeData,
            depth: this.state.depth.concat([childNodeData]),
            targets: this.state.targets.concat(targetNode),
          });
        } catch (error) {
          console.log(error);
        }
      } else if (targetNode.type === "FILE") {
        new FileModal().setState(targetNode.filePath);
      }
    },
    onclickBack: () => {
      const { depth, targets } = this.state;
      depth.pop();
      targets.pop();
      this.setState({ ...this.state, nodes: depth[depth.length - 1], depth });
    },
  });

  this.fetchRootData = async () => {
    try {
      const rootData = await request("");
      this.setState({
        ...this.state,
        nodes: rootData,
        depth: this.state.depth.concat([rootData]),
      });
    } catch (error) {
      console.log(error);
    }
  };

  this.init = () => {
    this.fetchRootData();
  };

  this.init();
}
