// stack follow LIFO  (last in first out) principle
// some method  push() , pop() , peek(){it return the last element of your stack} , isEmpty()

class stack {
  constructor() {
    this.store = {};
    this.size = 0;
  }

  push(element) {
    this.size++;
    this.store[this.size] = element;
  }
  pop() {
    let remove = this.store[this.size];
    delete this.store[this.size];
    this.size--;
    return remove;
  }
  peek() {
    // it return last element
    return this.store[this.size];
  }
  isEmpty() {
    if (this.store[this.size] === undefined) {
      return true;
    }
    return false;
  }
  stack_size() {
    return this.size;
  }
}
let st = new stack();
st.push(19);
st.push(9);
st.push(11);

console.log(`Before remove ${st.peek()} \n`);
console.log(`${st.pop()} removed successfully \n`);
console.log(`After remove ${st.peek()}\n`);
console.log(st.isEmpty() + "\n");
console.log(`total size is:- ${st.stack_size()}\n`);

/* ==========  Implement STACK using Array  ========== */

let stack = [];

// push() / insert element

stack.push(10);
stack.push(40);
stack.push(60);

console.log(stack); // [10,40,60]

// pop()  / remove element from last

stack.pop();

console.log(stack); // [ 10, 40]

// peek <--- it means it show / return the last element from the stack

let last_element = stack[stack.length - 1];

console.log(last_element); // 40 <---- last element it return ;
