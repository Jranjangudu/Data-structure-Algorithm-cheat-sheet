// Higher order function  || functional programming !

// ->  A “higher-order function” is a function that accepts functions as parameters and/or returns a function is called higher order function (HOF).

// Example

const radius = [3, 5, 6, 2];

// find Area of circle
const area = function (radius) {
  return Math.PI * radius * radius;
};
// find circumference of circle
const circumference = function (radius) {
  return 2 * Math.PI * radius;
};

// find diameter of circle
const diameter = (radius) => {
  return 2 * radius;
};

const calculate = function (radius, logic) {
  let output = [];
  radius.forEach((Eachradius) => {
    output.push(logic(Eachradius));
  });
  return output;
};

// instanded of creating your won calculate function , your can use map (map also a  higher order function;)
console.log(radius.map(area));
console.log(radius.map(circumference));
console.log(radius.map(diameter));

// OR

console.log(calculate(radius, area));
console.log(calculate(radius, circumference));
console.log(calculate(radius, diameter));

// In the above functions ,
// calculate --> higher order function;
// and area , circumference , diameter --> callback function

///////////////////////////////////////////////////////////////

Array.prototype.calculate = function (radius, logic) {
  let output = [];
  radius.forEach((Eachradius) => {
    output.push(logic(Eachradius));
  });
  return output;
};
console.log(radius.calculate(radius, area));
// ----------------------------------------------------------
Array.prototype.calculate = function (logic) {
  // console.log(this); //[ 3, 5, 6, 2 ]
  let output = []; // here this points to radius
  this.forEach((Eachradius) => {
    output.push(logic(Eachradius));
  });
  return output;
};
//  {this} points to radius
console.log(radius.calculate(area));
console.log(radius.calculate(diameter));
