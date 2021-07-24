//---------Selection Sort --------------->

// The Selection sort algorithm is based on the idea of finding the minimum or maximum element in an unsorted array and then putting it in its correct position in a sorted array.
// The idea behind this algorithm is pretty simple. We divide the array into two parts: sorted and unsorted. The left part is sorted subarray and the right part is unsorted subarray.

// Algorithm ---------->
// Step 1 − Set MIN to location 0
// Step 2 − Search the minimum element in the list
// Step 3 − Swap with value at location MIN
// Step 4 − Increment MIN to point to next element
// Step 5 − Repeat until list is sorted

function selection_sort(arr) {
  let n = arr.length;
  for (let i = 0; i < n - 1; i++) {
    let minimum = i;
    for (let j = i + 1; j < n; j++) {
      if (arr[j] < arr[minimum]) {
        minimum = j;
      }
    }
    // swap element
    swap(arr, i, minimum);
  }
  return arr;
}

function swap(arr, i, min) {
  let temp = arr[i];
  arr[i] = arr[min];
  arr[min] = temp;
  return arr;
}

let arr = [8, 14, 2, 5, 9, -1, 0, 4, -12, 3];
selection_sort(arr);

// Time complexity  O(n2) {Best , worst , average {All cases }}
// space complexity O(1) {constant space}
