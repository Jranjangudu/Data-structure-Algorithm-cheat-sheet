// 1. using object / map

let str = "teststring";

let count = {};
for (let i = 0; i < str.length; i++) {
  count[str[i]] = 0;
}
for (let i = 0; i < str.length; i++) {
  count[str[i]]++;
}
for (let eachEle in count) {
  if (count[eachEle] > 1) {
    console.log(eachEle, "count -", count[eachEle]);
  }
}
// o/p
// t count - 3
// s count - 2
// time Complexity - O(n) 
// -----------------------------------------------

// 2.

let str = "teststring";

let NO_OF_CHARS = 256;
function count(str) {
  let ar = new Array(NO_OF_CHARS);
  ar.fill(0);
  for (let i = 0; i < str.length; i++) {
    ar[str[i].charCodeAt()]++;
  }
  for (let i = 0; i < NO_OF_CHARS; i++) {
    if (ar[i] > 1) {
      console.log(String.fromCharCode(i), "count - ", ar[i]);
    }
  }
}
count(str);
// O/p
//  s count -  2
//  t count -  3
// Time Complexity: O(n), where n = length of the string passed

// Space Complexity: O(NO_OF_CHARS)
