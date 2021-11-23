const p1 = new Promise((resolve, rejects) => {
  console.log("p1 promise");
  resolve("p1 promise success");
});
const p2 = new Promise((resolve, rejects) => {
  console.log("p2 promise");
  resolve("p2 promise success");
});
p1.then((result) => {
  console.log(result); /* output:-
                    p1 promise
                    p2 promise
                    p1 promise success
  */
});
// p2.then((result) => {
//   console.log(result);
// });

// Using Promise.all() method;

// resolve -----------------------

const p4 = new Promise((resolve, rejects) => {
  setTimeout(() => {
    console.log("P4 called");
    resolve("p4 promise success");
  }, 1000);
});
const p5 = new Promise((resolve, rejects) => {
  setTimeout(() => {
    console.log("P5 called");
    resolve("p5 promise success");
  }, 2000);
});
Promise.all([p4, p5]) // add all promise inside square brackets []
  .then((allPromise) => console.log(allPromise)) //[ 'p4 promise success', 'p5 promise success' ]
  .catch((arr) => console.log(arr));

// reject --------------------------------------------

const p6 = new Promise((resolve, rejects) => {
  setTimeout(() => {
    console.log("p6 called successfully ..");
    resolve("p6 promise success");
  }, 1000);
});
const p7 = new Promise((resolve, rejects) => {
  setTimeout(() => {
    console.log("p7 promise failed..");
    rejects("p7 promise Failed , that's why it thorw reject message");
  }, 2000);
});

// Promise.all()
Promise.all([p6, p7]) // add all promise inside square brackets []
  .then((allPromise) => console.log(allPromise)) //[ 'p4 promise success', 'p5 promise success' ]
  .catch((arr) => console.log(arr)); //p7 promise Failed , that's why it thorw reject message

// total output
/*

p1 promise
p2 promise
p1 promise success
P4 called
p6 called successfully ..
P5 called
[ 'p4 promise success', 'p5 promise success' ]
p7 promise failed..
p7 promise Failed , that's why it thorw reject message

*/
