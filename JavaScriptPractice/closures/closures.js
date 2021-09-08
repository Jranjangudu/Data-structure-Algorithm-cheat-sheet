// Closure means that an inner function always has access to the variable and parameters of its outer function, even after the outer function has returned.

function OuterFunction() {
  let outerVariable = 100;

  return function InnerFunction() {
    console.log(outerVariable);
  };
}
let innerFunc = OuterFunction();

innerFunc(); // 100
// In the above example, return InnerFunction; returns InnerFunction from OuterFunction when you call OuterFunction(). A variable innerFunc reference the InnerFunction() only, not the OuterFunction(). So now, when you call innerFunc(), it can still access outerVariable which is declared in OuterFunction(). This is called Closure.
//
//
//
//
// -----------------When to use Closure?---------------

// Closure is useful in hiding implementation detail in JavaScript. In other words, it can be useful to create private variables or functions.

let counter = function () {
  let privateCounter = 0;
  function changeCounter(val) {
    privateCounter += val;
  }

  function increment() {
    changeCounter(1);
  }
  function decrement() {
    changeCounter(-1);
  }
  function totalValue() {
    return privateCounter;
  }
  return {
    increment,
    decrement,
    totalValue,
  };
};

let result = counter();
result.increment();
result.increment();
result.increment();
result.decrement();
result.increment();
result.decrement();
console.log(result.totalValue()); // 2

// In the above example, increment(), decrement() and totalValue() becomes public function because they are included in the return object, whereas changeCounter() function becomes private function because it is not returned and only used internally by increment() and decrement().
