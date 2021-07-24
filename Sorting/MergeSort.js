// Merge sort is a divide-and-conquer algorithm based on the idea of breaking down a list into several sub-lists until each sublist consists of a single element and merging those sublists in a manner that results into a sorted list.

// Idea:

// Divide the unsorted list into N sublists, each containing 1 element.
// Take adjacent pairs of two singleton lists and merge them to form a list of 2 elements. N will now convert into N/2 lists of size 2.
// Repeat the process till a single sorted list of obtained.

function mergeSort(arr, l, r) {
  if (l < r) {
    // find mid
    let mid = Math.floor((l + r) / 2);
    // call left sublist
    mergeSort(arr, l, mid);
    // call right sublist
    mergeSort(arr, mid + 1, r);
    // merge two sublist
    return merge(arr, l, mid, r);
  }
}

function merge(arr, l, mid, r) {
  let newArr = [];
  let i = l,
    j = mid + 1,
    k = l;

  while (i <= mid && j <= r) {
    if (arr[i] <= arr[j]) {
      newArr[k] = arr[i];
      i++;
    } else {
      newArr[k] = arr[j];
      j++;
    }
    k++; // k every time increment by one ;
  }
  // find if any sublist having element
  if (i > mid) {
    while (j <= r) {
      newArr[k] = arr[j];
      j++;
      k++;
    }
  } else {
    while (i <= mid) {
      newArr[k] = arr[i];
      i++;
      k++;
    }
  }
  // to copy all newArr element into  arr [ your main array]
  for (k = l; k <= r; k++) {
    arr[k] = newArr[k];
  }
  return arr;
}
const arr = [4, 2, 0, 6, 1, 17, 8, -2];
let l = 0,
  r = arr.length - 1;
console.log(mergeSort(arr, l, r));

// Time complexity is --->  O(n log n) {best , Worst cases}

// The list of N size  is divided into a max of LogN parts, and the merging of all sublists into a single list takes O(N) time, the worst case run time of this algorithm is O(n log n)

//---------------- second ways-------------------------------------

function mergeSort(arr) {
  if (arr.length < 2) return arr;
  var mid = Math.floor(arr.length / 2);
  var subLeft = mergeSort(arr.slice(0, mid));
  var subRight = mergeSort(arr.slice(mid));
  return merge(subLeft, subRight);
}
function merge(a, b) {
  var result = [];

  while (a.length > 0 && b.length > 0)
    result.push(a[0] < b[0] ? a.shift() : b.shift());

  return result.concat(a.length ? a : b);
}
var test = [5, 6, 7, 3, 1, 3, 15];
console.log(mergeSort(test));

//-----------------------------------------------------
