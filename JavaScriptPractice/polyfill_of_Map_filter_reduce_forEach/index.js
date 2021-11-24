let arr = [12, 46, 8, 9, 65, 43];

// ForEach()

Array.prototype.myForEach = function (cb) {
  for (let i = 0; i < this.length; i++) {
    cb(this[i], i, this);
  }
};

arr.myForEach((cur, i, ar) => {
  console.log(cur, i, ar);
});

// Map()

Array.prototype.myMap = function (cb) {
  const arr = [];
  for (let i = 0; i < this.length; i++) {
    arr.push(cb(this[i], i, this));
  }
  return arr;
};

let res = arr.myMap((ele, i, e) => {
  //   console.log(ele, i, e);
  return ele;
});
console.log(res);

// filter()

Array.prototype.myFilter = function (cb) {
  let arr = [];
  for (let i = 0; i < this.length; i++) {
    if (cb(this[i], i, this)) {
      arr.push(this[i]);
    }
  }
  return arr;
};

console.log(
  arr.myFilter((ar, i, e) => {
    console.log(ar, i, e);
    return ar === 8;
  })
);

// Array.prototype.reduces = function (callback, initialValue) {
//   var accumulator = initialValue === undefined ? undefined : initialValue;

//   for (var i = 0; i < this.length; i++) {
//     if (accumulator !== undefined) {
//       accumulator = callback.call(undefined, accumulator, this[i], i, this);
//       console.log(accumulator);
//     } else {
//       accumulator = this[i];
//     }
//   }
//   return accumulator;
// }; // our polyfill for reduce
// var combineAlbums = arr.reduces(function (a, b) {
//   return a + b;
// }, 0); // Initial Value is Young Sinatra

// console.log(combineAlbums);
