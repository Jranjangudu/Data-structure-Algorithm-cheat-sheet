// -> there are two way to use currying
// 1. using bind() method
// 2. using closures

// using bind() method
// bind method make a copy of {addtwonumber}  method / function

let addtwonumber = function (a, b) {
  console.log(`a = ${a} and b = ${b}  ===>`, a + b);
};

let numberone = addtwonumber.bind(this, 10); // here we pass argument ,  a = 10 ;
numberone(20); // b = 20   ; second argument
// output -->  a = 10 and b = 20  ===> 30
let numbertwo = addtwonumber.bind(this, 20, 40); // a = 20 , b = 40
numbertwo(10); // a = 20 and b = 40  ===> 60

let numberthree = addtwonumber.bind(this); // not passing anythings in bind() method
numberthree(40, 60); // a = 40 and b = 60  ===> 100 , here  we pass both a and b value

// ------- function closures -------------------

let multiply = function (a) {
  return function (b) {
    console.log(a * b);
  };
};

let valueone = multiply(2);
valueone(3); // 6

// function add(a) {
//   return function (b) {
//     return function (c) {
//       console.log(a + b + c);
//     };
//   };
// }

// // 1st way to call a func and pass argument
// add(10)(20)(30); // 60

// // 2st way to call a func and store the return func then pass argument
// let res1 = add(10);
// let res2 = res1(20);
// res2(30);
// // o/p =  60
