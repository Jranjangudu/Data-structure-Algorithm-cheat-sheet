let arr = [12, 4, 7, 9, 3];
// filter even values
let even = arr.filter((data) => data % 2 === 0); // it return only even number;

console.log(even);
// filter odd values
let odd = arr.filter((data) => data % 2);
console.log(odd);

// ---------------------

let data = [
  {
    firstname: "simran",
    lastname: "x",
    age: 20,
  },
  {
    firstname: "Mr",
    lastname: "y",
    age: 21,
  },
  {
    firstname: "simu",
    lastname: "z",
    age: 18,
  },
  {
    firstname: "Mr",
    lastname: "A",
    age: 25,
  },
];
// filter people less than 21 age;
let res = data.filter((x) => x.age < 21).map((x) => x.firstname);
console.log(res);
// [ 'simran', 'simu' ]
