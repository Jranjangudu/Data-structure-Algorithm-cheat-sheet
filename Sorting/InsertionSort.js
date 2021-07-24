
// Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

// Algorithm 
// To sort an array of size n in ascending order: 
// 1: Iterate from arr[1] to arr[n] over the array. 
// 2: Compare the current element (key) to its predecessor. 
// 3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.

function insertion_sort(arr, n) {
  for (let i = 1; i < n; i++) {
    let cur_element = arr[i];
    let j = i - 1;

    while (j >= 0 && arr[j] > cur_element) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = cur_element;
  }
  return arr;
}

const arr = [4, 2, 6, 1, 3, 10, 0];
const n = arr.length;
insertion_sort(arr, n);

// -- STEPS ----
 [4,4,6,1,3,10,0] --> [2,4,6,1,3,10,0] --> [2,4,6,1,3,10,0] -->

 [6,2,4,6,3,10,0] --> [1,2,4,6,3,10,0] --> [1,2,3,4,6,10,0] -->

 [1,1,2,3,4,6,10] --> [0,1,2,3,4,6,10] // END


 // --------- Time Complexity----->

// Worst complexity: n^2
// Average complexity: n^2
// Best complexity: n {if array already sorted}
// Space complexity: 1