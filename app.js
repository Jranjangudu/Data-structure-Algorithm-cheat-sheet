const data = {
  name: "***",
  age: "26",
};

data["mobile"] = "0000-000-000";
data.education = "M-Tech";
const information = {
  ...data,
  fullname: "***** ",
};
// console.table(data);
// console.table(information);

// function reverseWord(arr, l, r) {
//   // base case
//   if (l >= r) return arr;
//   let temp = arr[l];
//   arr[l] = arr[r];
//   arr[r] = temp;
//   return reverseWord(arr, l + 1, r - 1);
// }
// let arr = [1, 2, 3, 4, 5, 6];
// console.log(reverseWord(arr, 0, arr.length - 1));

function getMinMax(arr) {
  let min = arr[0];
  let max = arr[0];
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] > max) {
      max = arr[i];
    } else if (arr[i] < min) {
      min = arr[i];
    }
  }
  console.log("Minimum --->" + min, "and Maximum --->" + max);
}
// let arr = [2];
// getMinMax(arr);

// two pointer
function rearrange(arr, l, r) {
  // while (l <= r) {
  //   if (arr[l] > 0 && arr[r] < 0) {
  //     let temp = arr[l];
  //     arr[l] = arr[r];
  //     arr[r] = temp;
  //     r -= 1;
  //     l += 1;
  //   } else if (arr[l] < 0 && arr[r] < 0) {
  //     l += 1;
  //   } else if (arr[l] > 0 && arr[r] > 0) {
  //     r -= 1;
  //   } else {
  //     r -= 1;
  //     l += 1;
  //   }
  // }
  //The idea is to simply apply the partition process of quicksort.
  let j = 0;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] < 0) {
      if (i !== j) {
        let temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
      j++;
    }
  }

  console.log(arr);
}

let arr = [-12, 11, -13, -5, 6, -7, 5, -3, -6, 0, -4];
rearrange(arr, 0, arr.length - 1);
