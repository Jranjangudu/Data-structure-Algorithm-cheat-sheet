//----------Binary Search---------------
// Binary search is a fast search algorithm with run-time complexity of Ο(log2 n). This search algorithm works on the principle of divide and conquer. For this algorithm to work properly, the data collection should be in the sorted form.
// Binary search works only on a sorted set of elements. To use binary search on a collection, the collection must first be sorted.
// Binary search looks for a particular item by comparing the middle most item of the collection. If a match occurs, then the index of item is returned. If the middle item is greater than the item, then the item is searched in the sub-array to the left of the middle item. Otherwise, the item is searched for in the sub-array to the right of the middle item. This process continues on the sub-array as well until the size of the subarray reduces to zero.

function binarySearch(arr, key) {
  let n = arr.length - 1;
  let i = 0;
  while (i <= n) {
    let mid = Math.floor((i + n) / 2); // The median of the lower and upper bounds is (lower_bound + upper_bound) / 2
    // If element is present at mid, return index of key
    if (arr[mid] === key) return mid;
    // Else look in left or right half accordingly
    else if (arr[mid] < key) i = mid + 1;
    else n = mid - 1;
  }
  return -1;
}

let arr = [1, 3, 5, 6, 7, 8, 9];
let key = 6;
binarySearch(arr, key);

// -------Solve by Recursion--------------->
function RecursivebinarySearch(arr, l, r, key) {
  if (r >= l) {
    let mid = Math.floor((l + r) / 2);

    // base case
    if (arr[mid] === key) return mid;

    if (arr[mid] > key) {
      return RecursivebinarySearch(arr, l, mid - 1, key);
    } else {
      return RecursivebinarySearch(arr, mid + 1, r, key);
    }
  }
  return -1; // if element not found
}
let arr = [2, 4, 6, 7, 8, 9];
//In the case of recursive implementation, Time complexity  O(Logn)
let key = 7;
let n = arr.length;
let res = RecursivebinarySearch(arr, 0, n - 1, key);

//---------Time complexity ---------->
// O(log2 N) // base 2

// The{ best-case} time complexity would be O(1) when the central index would directly match the desired value.

//--------------- Space complexity--------->

// The space complexity of the binary search algorithm depends on the implementation of the algorithm. There are two ways of implementing it:
//  1. Iterative method
//  2. Recursive method

// Both methods are quite the same, with two differences in implementation. First, there is no loop in the recursive method. Second, rather than passing the new values to the next iteration of the loop, it passes them to the next recursion. In the iterative method, the iterations can be controlled through the looping conditions, while in the recursive method, the maximum and minimum are used as the boundary condition.

// In the iterative method, the space complexity would be { O(1) }. While in the recursive method, the space complexity would be{ O(log n)}
