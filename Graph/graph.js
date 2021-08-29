//  queue data structure
class Queue {
  constructor() {
    this.items = [];
  }

  // add element to the queue
  enqueue(element) {
    return this.items.push(element);
  }

  // remove element from the queue
  dequeue() {
    if (this.items.length > 0) {
      return this.items.shift();
    }
  }

  // check if the queue is empty
  isEmpty() {
    return this.items.length == 0;
  }
}

//  Graph
// A Graph is a non-linear data structure consisting of nodes / vertex and edges.

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
  addEdge(v, w, undirected = 1) {
    // get the list for vertex v and put the
    // vertex w denoting edge between v and w
    this.Adjlist.get(v).push(w);

    if (undirected) {
      // add an edge from w to v also , and make it undirected graph
      this.Adjlist.get(w).push(v);
    }
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

  // function to performs BFS (Breadth First Search )
  bfs(startingNode) {
    // create a visited object
    const visited = {};

    // Create an object for queue
    let q = new Queue();

    // add the starting node to the queue , and make it visited
    visited[startingNode] = true;
    q.enqueue(startingNode);

    // loop until queue is element
    while (!q.isEmpty()) {
      // get the element from the queue
      let getQueueElement = q.dequeue();

      // print vertex / nodes
      console.log(getQueueElement, "---> bfs");

      // get the adjacent list for current vertex
      let get_List = this.Adjlist.get(getQueueElement);

      // loop through the list and add the element to the
      // queue if it is not processed yet
      for (let i of get_List) {
        if (!visited[i]) {
          visited[i] = true; // make it visited , then add into queue;
          q.enqueue(i);
        }
      }
    }
  }

  // DFS (depth First Search )
  dfs(startingNode) {
    let visited = {};
    this.DFSUtil(startingNode, visited);
  }
  // Recursive function which process and explore
  // all the adjacent vertex of the vertex with which it is called
  DFSUtil(vert, visited) {
    visited[vert] = true;
    console.log(vert, "---> dfs");

    let get_lists = this.Adjlist.get(vert);

    for (let i of get_lists) {
      if (!visited[i]) this.DFSUtil(i, visited);
    }
  }
}

let g = new Graph();
let vertices = ["A", "B", "C", "D", "E", "F"];
vertices.forEach((ele) => {
  g.addVertex(ele);
});

/**
 1 = undirected graph;
 0 = directed graph
 if you can't pass third argument , by default it make undirected graph
 */

// adding edges

// Example to undirected graph 👇
g.addEdge("A", "D", 1);
g.addEdge("A", "E", 1);
g.addEdge("A", "B", 1);
g.addEdge("B", "C", 1);
g.addEdge("D", "E", 1);
g.addEdge("E", "F", 1);
g.addEdge("E", "C", 1);
g.addEdge("F", "C", 1);

// Example to directed graph 👇
// g.addEdge("A", "D", 0);
// g.addEdge("A", "E", 0);
// g.addEdge("A", "B", 0);
// g.addEdge("B", "C", 0);
// g.addEdge("D", "E", 0);
// g.addEdge("E", "F", 0);
// g.addEdge("E", "C", 0);
// g.addEdge("F", "C", 0);

// Example to complete graph 👇
// g.addEdge("A", "B");
// g.addEdge("A", "C");
// g.addEdge("B", "A");
// g.addEdge("B", "C");
// g.addEdge("C", "A");
// g.addEdge("C", "B");

// print graph
g.printGraph();
g.bfs("A");
g.dfs("A");
/**   
          (A)----(B)<---------------Vertex / Node
         /   \      \<------Edge
        (D)--(E)----(C)
                \    /  
                 \  / <------Edge 
                  (F)<---------------Vertex / Node

         ( Undirected graph )
   */
