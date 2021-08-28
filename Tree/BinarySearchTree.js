// Time complexity -->

// Best , average case tc --> O(n log n)
// worst case tc --> O(n) , cause, in case your all nodes value present in ascending / descending order then the searching tc is O(n) , ex- [10,20,30] / [10,9,8] , in case this situation arrive , we can use AVL tree for balancing tree

class Node {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

class BST {
  constructor(value) {
    this.root = new Node(value);
    this.count = 1;
  }

  insert(value) {
    this.count++;

    let newNode = new Node(value);

    const searchTree = (node) => {
      // if value < node.value, go left
      if (value < node.value) {
        // if no left child, append new node
        if (!node.left) {
          node.left = newNode;
        }
        // if left child, look left again
        else {
          searchTree(node.left);
        }
      }
      // if value > node.value, go right
      else if (value > node.value) {
        // if no right child, append new node
        if (!node.right) {
          node.right = newNode;
        }
        // if right child, look right again
        else {
          searchTree(node.right);
        }
      }
    };

    searchTree(this.root);
  }
  // return size of  tree
  size() {
    return this.count;
  }
  // find minimum
  min() {
    let node = this.root;
    // continue traversing left until no more children
    while (node.left) {
      node = node.left;
    }
    return node.value;
  }
  // find maximum
  max() {
    let node = this.root;
    // continue traversing right until no more children
    while (node.right) {
      node = node.right;
    }
    return node.value;
  }

  // find a node
  contains(value) {
    let cur_node = this.root;
    while (cur_node) {
      if (cur_node.value === value) return true;
      if (cur_node.value > value) {
        cur_node = cur_node.left;
      } else {
        cur_node = cur_node.right;
      }
    }
    return false;
  }
  // depth first search - branch by branch

  // in-order
  // left, root, right

  dfsInOrder() {
    let result = [];

    const traverse = (node) => {
      // if left child exists, go left again
      if (node.left) traverse(node.left);
      // capture root node value
      result.push(node.value);
      // if right child exists, go right again
      if (node.right) traverse(node.right);
    };

    traverse(this.root);

    return result;
  }
  // pre-order
  // root, left, right

  dfsPreOrder() {
    let result = [];

    const traverse = (node) => {
      // capture root node value
      result.push(node.value);
      // if left child exists, go left again
      if (node.left) traverse(node.left);
      // if right child exists, go right again
      if (node.right) traverse(node.right);
    };

    traverse(this.root);

    return result;
  }
  // post-order
  // left, right, root

  dfsPostOrder() {
    let result = [];

    const traverse = (node) => {
      // if left child exists, go left again
      if (node.left) traverse(node.left);
      // if right child exists, go right again
      if (node.right) traverse(node.right);
      // capture root node value
      result.push(node.value);
    };

    traverse(this.root);

    return result;
  }

  // breadth first search - level by level
  // use a queue!
  bfs() {
    let result = [];
    let queue = [];
    queue.push(this.root);

    while (queue.length) {
      let head_node = queue.shift();
      result.push(head_node.value);

      if (head_node.left) {
        queue.push(head_node.left);
      }
      if (head_node.right) {
        queue.push(head_node.right);
      }
    }
    return result;
  }

  // Delete node

  deleteNodeHelper(root, key) {
    if (root === null) {
      return null;
    }

    if (key < root.value) {
      root.left = this.deleteNodeHelper(root.left, key);
      return root;
    } else if (key > root.value) {
      root.right = this.deleteNodeHelper(root.right, key);
      return root;
    } else {
      // No children
      //case 1 - a leaf node
      if (root.left === null && root.right === null) {
        return null;
      }
      // Single Child cases
      if (root.left === null) return root.right;
      if (root.right === null) return root.left;

      // Both children, so need to find successor
      let currNode = root.right;
      while (currNode.left !== null) {
        currNode = currNode.left;
      }
      root.value = currNode.value;
      // Delete the value from right subtree successor value.
      root.right = this.deleteNodeHelper(root.right, currNode.value);
      return root;
    }
  }
}

const bst = new BST(10);
bst.insert(1);
bst.insert(4);
bst.insert(13);

bst.insert(8);
bst.insert(20);
bst.insert(12);

console.log(bst.min(), "----> minimum value");
console.log(bst.max(), "----> maximum value");
console.log(bst.contains(4), "---->  [true] or [false]");

console.log();
console.log(bst.dfsInOrder(), "----> dfsInOrder");
console.log(bst.dfsPostOrder(), "----> dfsPostOrder");
console.log(bst.dfsPreOrder(), "----> dfsPreOrder");
console.log(bst.bfs(), "----> breadth first search - level by level");

console.log(bst.contains(1));
// bst.deleteNodeHelper(bst.root, 10);
// bst.deleteNodeHelper(bst.root, 20);
bst.deleteNodeHelper(bst.root, 1);
console.log(bst.bfs(), "----> bfs");

const deleteNode = function (root, key) {
  if (!root) return null;

  if (key < root.val) {
    root.left = deleteNode(root.left, key);
    return root;
  } else if (key > root.val) {
    root.right = deleteNode(root.right, key);
    return root;
  } else {
    // check if leaf node
    if (root.val === null && root.val === null) {
      return null;
    }
    // if node contain only one child
    else if (root.left === null) return root.right;
    else if (root.right === null) return root.left;

    // if node contain two child
    // inorder successor --> The smallest element of delete nodes right subtree ;
    let cur_node = root.right;

    while (cur_node.left !== null) {
      cur_node = cur_node.left;
    }
    root.val = cur_node.val; // replace delete node with  right most small node
    // delete right most small node
    root.right = deleteNode(root.right, cur_node.val);
    return root;
  }
};

// --------------------------------------------------------------------

// What is Predecessor and Successor :

// When you do the inorder traversal of a binary tree, the neighbors of given node are called Predecessor(the node lies behind of given node) and Successor (the node lies ahead of given node).

// https://www.tutorialspoint.com/Removing-a-node-in-a-Javascript-Tree

/**
 * Takes root and key and recursively searches for the key.
 * If it finds the key, there could be 3 cases:
 *
 * 1. This node is a leaf node.
 *
 * Example: Removing F
 *     A
 *    / \
 *   B   C
 *  /   / \
 * D   E   F
 *
 * To remove it, we can simply remove its parent's connection to it.
 *
 *      A
 *     / \
 *    B   C
 *   /    /
 *  D    E
 *
 * 2. This node is in between the tree somewhere with one child.
 *
 * Example: Removing B
 *       A
 *      / \
 *     B   C
 *    /   / \
 *   D   E   F
 *
 * To remove it, we can simply make the child node replace the parent node in the above connection
 *       A
 *      / \
 *     D   C
 *        / \
 *       E   F
 *
 * 3. This node has both children. This is a tricky case.
 *
 * Example: Removing C
 *
 *        A
 *       / \
 *      B   C
 *     /   / \
 *    D   E   F
 *       /   / \
 *      G   H   I
 *
 * In this case, we need to find either a successor or a predecessor of the node and replace this node with
 * that. For example, If we go with the successor, its successor will be the element just greater than it,
 * ie, the min element in the right subtree. So after deletion, the tree would look like:
 *
 *        A
 *       / \
 *      B   H
 *     /   / \
 *    D   E   F
 *       /     \
 *      G       I
 *
 * To remove this element, we need to find the parent of the successor, break their link, make successor's left
 * and right point to current node's left and right. The easier way is to just replace the data from node to be
 * deleted with successor and delete the sucessor.
 */
