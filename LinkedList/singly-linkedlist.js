class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }
  //adds to the tail of the list
  push(data) {
    let newNode = new Node(data);
    if (!this.head) {
      this.head = newNode;
      this.tail = this.head;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
    this.length++;

    return this;
  }
  //remove from the tail of the list
  pop() {
    // if linkedlist contail only one element;
    if (!this.head) return "linkedlist empty";
    else if (this.length === 1) {
      this.head = null;
      this.tail = null;
      return this;
    }
    let curNode = this.head;
    while (curNode.next.next) {
      curNode = curNode.next;
    }
    this.tail = curNode;
    this.tail.next = null;
    this.length--;
    return this.head;
  }
  // /remove from the head of the list
  shift() {
    if (!this.head) return undefined;
    let curHead = this.head;
    this.head = curHead.next;
    this.length--;
    if (this.length === 0) {
      this.tail = null;
    }
    return curHead;
  }
  //insert a node to the beginning of the list
  unshift(data) {
    let newNode = new Node(data);
    // if head not exist
    if (!this.head) {
      this.push(data);
      return this;
    }
    // if head exist;
    newNode.next = this.head;
    this.head = newNode;
    this.length++;
    return this;
  }
  // get: retrieves a value at a given index
  get(index) {
    if (index < 0 || index > this.length) return null;
    let counter = 0;
    let curnode = this.head;
    while (counter !== index) {
      curnode = curnode.next;
      counter++;
    }
    return curnode; //Or return curnode.data;
  }
  //given an index and value, will update the value of that node
  set(index, val) {
    let foundNode = this.get(index);
    if (foundNode) {
      foundNode.data = val;
      return "Node updated ..";
    }
    return "index not found.";
  }
  //accepts an index and value and inserts a new node
  insert(index, val) {
    if (index < 0 || index > this.length) return null;
    if (index === this.length) return this.push(val);
    if (index === 0) return this.unshift(val);

    let newNode = new Node(val);
    let getPrevNode = this.get(index - 1);
    let temp = getPrevNode.next;
    getPrevNode.next = newNode;
    newNode.next = temp;
    this.length++;
    return "newNode Inserted..";
  }
  // Remove node
  remove(index) {
    if (index < 0 || index > this.length) return null;
    if (index === 0) return this.shift();
    if (index === this.length) return this.pop();
    let prevNode = this.get(index - 1);
    let removeNode = prevNode.next;
    prevNode.next = removeNode.next;
    this.length--;
    return removeNode;
  }
}

let l = new LinkedList();
l.push(10);
l.push(20);
l.push(30);
l.push(40);
// console.log(l.unshift(20));
console.log(l.head, "-------->");
// console.log(l.remove(1));
// console.log(l.get(2));
// console.log(l.shift())
// console.log(l.insert(2, 300));
console.log(l.set(1, 200));
console.log(l.head, "<--------------");

// BigO of Linked Lists

// Insertion: O(1)
// Removal: O(1) or O(n) // removal vs. within the list
// Searching: O(n)
// Access: O(n)
