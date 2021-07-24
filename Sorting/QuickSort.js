// Quick sort is based on the divide-and-conquer approach based on the idea of choosing one element as a pivot element and partitioning the array around it such that: Left side of pivot contains all the elements that are less than the pivot element Right side contains all elements greater than the pivot

// It reduces the space complexity and removes the use of the auxiliary array that is used in merge sort. Selecting a random pivot in an array results in an improved time complexity in most of the cases.

// It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.

// 1. Always pick first element as pivot.
// 2. Always pick last element as pivot
// 3. Pick a random element as pivot.
// 4. Pick median as pivot.

// Algorithm
// 1. first check , if your array length lessthan 1 , then simple return ;
// 2. then call partition function , this is the main part of quickSort , this function return the index of pivot [target element] element
// 3. then recursive call , start element to pivot-1 element [ left sublist ]
// 4. then recursive call ,  pivot+1 to end  element [ right sublist ]

// final return your array;

function quickSort(arr, l, r) {
  //check if your array having atleast two element
  if (l < r) {
    let pivot = partition(arr, l, r);

    // recursive call , left part of pivot  // Before pivot
    quickSort(arr, l, pivot - 1);

    // recursive call , right part of pivot  // After  pivot
    quickSort(arr, pivot + 1, r);
  }
  return arr;
}

// define partition

function partition(arr, l, r) {
  let pivot = arr[l]; //  u can use first, last , middle or any element , it's depends you!
  let i = l,
    j = r;

  while (i < j) {
    while (arr[i] <= pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i < j) {
      swap(arr, i, j);
    }
  }

  swap(arr, j, l);
  return j; // return j
}

// define swap function
function swap(arr, i, j) {
  let temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

let arr = [20, 30, 4, 50, -7, 90, -35];
let l = 0,
  r = arr.length - 1;
console.log(quickSort(arr, l, r));

//-------Time complexity --->

// Best and Average case ---> O(n log n) // this case happen if your array every time divide n/2 , means ..  n/2 then n/4 and so on.... like merge sort ,
// worst case ---> O(n^2) // this case happen if your array already sorted

// space complexity ---> O(log(n)) // due to recursive stack
