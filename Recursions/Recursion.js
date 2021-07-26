function factorial(n) {
  if (n === 0) {
    return 1;
  }

  return n * factorial(n - 1);
}
let n = 4;
console.log(factorial(n));

// call stack image --->  https://miro.medium.com/max/250/1*1fJDfn158p1JxXfQfZ87Uw.png

// how factorial recursion function works

// function factorial(4) {
//     if (n === 0) {     //4 !==0
//       return 1;
//     }
//     return n * factorial(n - 1);
//   }

//   //so we get 4 * factorial(3)

//   function factorial(3) {
//     if (n === 0) {    //3 !==0
//       return 1;
//     }
//     return n * factorial(n - 1);
//   }

//   //so we get 4 * (3 * factorial(2))

//   function factorial(2) {
//     if (n === 0) {    //2 !==0
//       return 1;
//     }
//     return n * factorial(n - 1);
//   }

//   //so we get 4 * (3 * (2 * factorial(1))))

//   function factorial(1) {
//     if (n === 0) {    //1 !==0
//       return 1;
//     }
//     return n * factorial(n - 1);
//   }

//   //so we get 4 * (3 * (2 * (1 * factorial(0)))))

//   function factorial(0) {
//     if (n === 0) {    //0 === 0, so we've hit our break!
//       return 1;
//     }
//     return n * factorial(n - 1);
//   }

// so the end return is 4 * (3 * (2 * (1 * (1)))))

function add_number(n) {
  if (n === 1) return 1;

  return n + add_number(n - 1);
}
console.log(add_number(10));

// ---------------
const data = [
  {
    name: "Facebook",
    location: "London",
  },
  {
    name: "Amazon",
    location: "hyderabad",
  },
  {
    name: "Google",
    location: "Mumbai",
  },
];
console.table(data);
