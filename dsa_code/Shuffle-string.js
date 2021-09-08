// Given a string s and an integer array indices of the same length.

// The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

// Return the shuffled string.

const restoreString = function (s, indices) {
  // 1. One way to do using array
  // let ar = new Array(indices.length).fill(0);
  // for(let i= 0 ; i < indices.length ; i++){
  //     ar[indices[i]] = s[i]
  // }
  // return ar.join('');

  // 2. Second way to do using object
  let obj = {};
  for (let i = 0; i < indices.length; i++) {
    obj[indices[i]] = s[i];
  }
  return Object.values(obj).join("");
};
let s = "codeleet",
  indices = [4, 5, 6, 7, 0, 2, 1, 3];
let res = restoreString(s, indices);
console.log(res);
// Output: "leetcode"
// Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
