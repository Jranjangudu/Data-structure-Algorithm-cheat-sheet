class Graph {
  constructor() {
    this.Adjlist = new Map();
  }

  // add vertex / node
  addVertex(v) {
    // initialize the adjacent list with a null array ;
    this.Adjlist.set(v, []);
  }
  // connect Edges ,
  addEdge(v, w) {
    // get the list for vertex v and put the
    // vertex w denoting edge between v and w
    this.Adjlist.get(v).push(w);

    // Since graph is undirected,
    // add an edge from w to v also
    this.Adjlist.get(w).push(v);
  }

  printGraph() {
    // Get all keys
    let get_keys = this.Adjlist.keys();
    // now  iterate over the vertices / vertex
    for (let i of get_keys) {
      //  great the corresponding adjacency list for the vertex
      let get_values = this.Adjlist.get(i);
      let str = "";
      // iterate over the adjacency list
      // concatenate the values into a string
      for (let j of get_values) {
        str += j + " ";
      }
      console.log(i + " --> " + str);
    }
  }
}

let g = new Graph();
let vertices = ["A", "B", "C", "D", "E", "F"];
vertices.forEach((ele) => {
  g.addVertex(ele);
});

// adding edges
g.addEdge("A", "B");
g.addEdge("A", "D");
g.addEdge("A", "E");
g.addEdge("B", "C");
g.addEdge("D", "E");
g.addEdge("E", "F");
g.addEdge("E", "C");
g.addEdge("C", "F");

// print graph
g.printGraph();

/**   
          (A)----(B)<---------------Vertex / Node
         /   \      \<------Edge
        (D)--(E)----(C)
                \    /  
                 \  / <------Edge 
                  (F)<---------------Vertex / Node

         ( Undirected graph )
   */
