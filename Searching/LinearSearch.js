//------ Linear Search------------------

// Linear Search is the simplest searching algorithm.
// It traverses the array sequentially to locate the required element.
// It searches for an element by comparing it with each element of the array one by one.

// So, it is also called as Sequential Search.

// ----------------------------------------------------------------------

// Linear search is used on a collections of items. It relies on the technique of traversing a list from start to end by exploring properties of all the elements that are found on the way.

// For example, consider an array of integers of size . You should find and print the position of all the elements with value . Here, the linear search is based on the idea of matching each element from the beginning of the list to the end of the list with the integer , and then printing the position of the element if the condition is `True'.

//--------pseudo code---------

//    for(start to end of array){
//        if (current_element equals to x) // here x is your target element
//        {
//          return current_index;
//        }
//    }

//----- Implementation---------------------

function Linear_search(arr, target) {
  let n = arr.length;
  for (let i = 0; i < n; i++) {
    if (arr[i] === target) {
      return i; // return index of your target element
    }
  }
}

const arr = [4, 8, 3, 9, 1, 6];
const target = 9;
Linear_search(arr, target);

// ---------Space complexity ---> O(1) {constant space}

//---------- Time Complexity ------

//  { Best case  } complexity ----> O(1)
//  {  Worst-case } complexity ---->  O(n)
//  { Average} complexity ---->  O(n/2)

//  thus Time Complexity of Linear Search Algorithm is O(n).

// { Best case }------------------>

// In the best possible case,

// The element being searched may be found at the first position.
// In this case, the search terminates in success with just one comparison.
// Thus in best case, linear search algorithm takes O(1) operations.

//{ Worst Case}----------------------->

// In the worst possible case,

// The element being searched may be present at the last position or not present in the array at all.
// In the former case, the search terminates in success with n comparisons.
// In the later case, the search terminates in failure with n comparisons.
// Thus in worst case, linear search algorithm takes O(n) operations.
