const userData = {
  name: "simran",
  age: 22,
};

function print(city, state, number) {
  console.log(this.name, " ", this.age, " ", city, " ", state, " ", number);
}

// pre-define bind() method
let output = print.bind(userData, "BBSR", "Odisha");
// output(9004567546); //--> simran   22   BBSR   Odisha   9004567546

// now implement own bind() method ;|| polyfill of bind method ;

// define mybind function with Function prototype , because every function can access this mybind() function;
Function.prototype.mybind = function (...args) {
  //   console.log(args); // [ { name: 'simran', age: 22 }, 'BBSR' ]
  let func = this; // this points to print() function
  let params = args.splice(1); // splice[0] contain userData object;
  return function (...args2) {
    // console.log(args2);  // [ 9004567546 ]
    func.apply(args[0], [...params, ...args2]);
  };
};

const customOutput = print.mybind(userData, "BBSR", "Odisha");
customOutput(9004567546); // you can pass argument here;
// o/p -->  simran   22   BBSR   Odisha   9004567546
