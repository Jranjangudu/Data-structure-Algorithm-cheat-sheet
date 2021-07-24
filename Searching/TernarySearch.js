//-------------Ternary search ---------------->

// Ternary search is a divide and conquer algorithm that can be used to find an element in an array. It is similar to binary search where we divide the array into two parts but in this algorithm, we divide the given array into three parts and determine which has the key (searched element). We can divide the array into three parts by taking mid1 and mid2

// Note: Array needs to be sorted to perform ternary search on it.

// Steps to perform Ternary Search:

// 1. First, we compare the key with the element at mid1. If found equal, we return mid1.
// 2. If not, then we compare the key with the element at mid2. If found equal, we return mid2.
// 3. If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
// 4. If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
// 5. If not, then we recur to the second (middle) part.

function ternarySearch(l, r, arr, key) {
  if (r >= l) {
    // Find the mid1 and mid2
    // let mid1 = l + parseInt((r - l) / 3, 10);
    let mid1 = Math.trunc(l + (r - l) / 3);
    let mid2 = Math.trunc(l + (r - l) / 3);
    // Check if key is present at any mid
    if (arr[mid1] === key) {
      return mid1;
    }
    if (arr[mid2] === key) {
      return mid2;
    }
    if (arr[mid1] > key) {
      // / The key lies in between l and mid1
      return ternarySearch(l, mid1 - 1, arr, key);
    } else if (arr[mid2] < key) {
      // The key lies in between mid2 and r
      return ternarySearch(mid2 + 1, r, arr, key);
    } else {
      // The key lies in between mid1 and mid2
      return ternarySearch(mid1 + 1, mid2 - 1, arr, key);
    }
  }
  // Key not found
  return -1;
}

let arr = [1, 2, 3, 4, 5, 6, 7, 8];
let key = 4;
let l = 0,
  r = arr.length - 1;
ternarySearch(l, r, arr, key);
//--------Time Complexity: -------------------->
// O(log3 n) , --> base 3

//{ best-case}, time complexity O(1)
