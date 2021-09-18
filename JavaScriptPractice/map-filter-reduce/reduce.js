// acc ---> accumulator
// cur ---> currentValue;
// [ https://www.javascripttutorial.net/javascript-array-reduce/ ]

// function reducer(accumulator, currentValue, currentIndex, array){}

// second value of reduce method is the initial value of accumulator ;

let arr = [1, 2, 3, 4, 5];
// find sum of all number;
let output = arr.reduce((acc, cur) => {
  acc = acc + cur;
  return acc;
}, 0);
console.log(output); // 15

// find maximum of given array(arr[])

let max = arr.reduce((acc, cur) => {
  if (cur > acc) {
    acc = cur;
  }
  return acc;
}, Number.MIN_VALUE);
console.log(max); // 5 <-- maximum value

// -------------------------
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
    age: 20,
  },
];

// find how many people is in same age group;

let res = data.reduce((acc, cur) => {
  if (acc[cur.age]) {
    acc[cur.age] += 1;
    //  OR
    // acc[cur.age] = ++acc[cur.age];
  } else {
    acc[cur.age] = 1;
  }
  return acc;
}, {});
console.log(res); //{ '18': 1, '20': 2, '21': 1 } / age 18 --> 1 people ; age 20 --> 2 people & so on ..
// ------------------------------------

// filter people less than 21 age;

let result = data.reduce((acc, cur) => {
  if (cur.age < 21) {
    acc.push(cur.firstname);
  }
  return acc;
}, []);
console.log(result); //[ 'simran', 'simu', 'Mr' ]
