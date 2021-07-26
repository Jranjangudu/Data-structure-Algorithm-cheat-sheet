/* ========== QUEUE ========== */ // It follow FIFO (first in first out) principle

class queue {
  constructor() {
    this.store = {};
    this.head = 0;
    this.tail = 0;
  }
  enqueue(element) {
    this.store[this.tail] = element;
    this.tail++;
  }
  dequeue() {
    let remove = this.store[this.head];
    delete this.store[this.head];
    this.head++;
    return remove;
  }
}

let dq = new queue();
dq.enqueue(10);
dq.enqueue(20);
dq.enqueue("seahorse");
dq.enqueue("dolphin");
dq.enqueue("whale shark");
console.log(dq.dequeue());
console.log(dq.dequeue());
console.log(dq.store);
// o/p
// 10
// 20
// { '2': 'seahorse', '3': 'dolphin', '4': 'whale shark' }

/* ==========  Implement QUEUE using Array  ========== */

let queue = [];

// enqueue OR/ insert new element

queue.push(10);
queue.push(30);
queue.push(50);

console.log(queue); // [10,20,30]

// dequeue OR/ remove ( remove element from first position)

let remove_element = queue.shift();

console.log(queue); // [20 , 30]  ** shift remove the first element ;

console.log(remove_element); // 10
