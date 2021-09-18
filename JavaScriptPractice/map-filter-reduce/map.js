let arr = [2, 4, 6, 8];
function binary(x) {
  return x.toString(2); // convert number to binary
}

console.log(arr.map(binary));
//[ '10', '100', '110', '1000' ] binary of --> [2, 4, 6, 8];

// ------------------------

let data = [
  {
    firstname: "Mr",
    lastname: "x",
    age: 22,
  },
  {
    firstname: "Mr",
    lastname: "y",
    age: 21,
  },
  {
    firstname: "Mr",
    lastname: "z",
    age: 20,
  },
];

let res = data.map((curData) => curData.firstname + " " + curData.lastname);
console.log(res); //[ 'Mr x', 'Mr y', 'Mr z' ]
