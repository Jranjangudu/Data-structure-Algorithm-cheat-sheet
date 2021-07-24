//-------Bubble Sort-------------->

// Bubble sort is based on the idea of repeatedly comparing pairs of adjacent elements and then swapping their positions if they exist in the wrong order.

const bubble_sort = (arr) => {
  let n = arr.length;
  for (let i = 0; i < n - 1; i++) {
    // (n - i - 1) is for ignoring comparisons of elements which have already been compared in earlier iterations
    let isSorted = false; // it helps to optimizing of the code;
    for (let j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        isSorted = true;
      }
    }
    if (!isSorted) return arr;
  }
  return arr;
};
const arr = [1, 2, 3, 4, 15, -6];
bubble_sort(arr);
//---------Time Complexity ------->:

// if  array already sorted , then the time complexity is O(n) {best case }

// The complexity of bubble sort is O(n²) in both{ worst} and {average} cases, because the entire array needs to be iterated for every element.

// time complexity of O(n²) in the {average} and {worst} cases – and O(n) in the {best} case.

// space complexity --> O(1)
