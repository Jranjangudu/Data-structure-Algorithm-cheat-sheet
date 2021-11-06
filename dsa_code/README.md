## Find UNION of Two Arrays

```
let num1 = [1,4,2,6]
let num2 = [4,5,6,1,8]

function getUnion(){
  let newArr = [...num1 , ...num2]
  return [...new Set(newArr)]
}
console.log(getUnion()) //[1, 4, 2, 6, 5, 8]

console.log(getUnion().sort().reverse()) //[8, 6, 5, 4, 2, 1]
console.log(getUnion().sort()) //[1, 2, 4, 5, 6, 8]

```

## getSum(1)(2)(3)(4).....(n)()

```
function getSum(a){
  return (b)=>{
    if(b){
      return getSum(a+b)
    }
    return a;
  }
}

let res= getSum(1)(2)(3)(4)()
console.log(res) //10

```

## Find Intersection of Two Arrays

```

let num1 = [4,5,1,8,4]
let num2 = [1,4,2,1]

let getIntra = num1.filter(cur=>num2.includes(cur))

console.log([...new Set(getIntra)]) //[4, 1] <-Set() helps to Remove duplicate value  ->
console.log(getIntra) //[4, 1, 4]

```

## [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)

```
let size = 5;
function generate(n){
  let arr = [];
  for(let i = 0 ; i < n ; i++){
    arr[i] = [];
    arr[i][0] = 1;
    for(let j = 1; j <=i ; j++){
      j < i ? arr[i][j] = arr[i-1][j-1]+arr[i-1][j] : arr[i][j] = 1
    }
  }
  return arr;
}
console.log(generate(size));

. first assign a empty array in every index
. Then add 1 inside  empty array [0] index of every index
. Here i use two loop
. Inside  j loop , you check if j is graterthan  i , then add one in last of index
. if i is grater then j , then you access the privious array , and add the [i , j] value then assign in present array !!
Output:-
[[1],[1, 1],[1, 2, 1],[1, 3, 3, 1],[1, 4, 6, 4, 1]]


Time Complexity: We are creating a 2D array of size (numRows * numCols) (where 1 <= numCols <= numRows), and we are traversing through each of the cells to update it with its correct value, so Time Complexity = O(numRows2).

Space Complexity: Since we are creating a 2D array, space complexity = O(numRows2).
```

## [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

```
// One Pass

let maxProfit = function (prices){
    let profit = 0 ;

    let min_val = prices[0]

    for(let i =1  ; i  < prices.length ; i++){
        if (prices[i] < min_val){
            min_val = prices[i]
        }
        else {
            let curprofit = prices[i] - min_val
            if (curprofit > profit){
                profit  = curprofit;
            }
        }

    }
    return profit
}
// Time complexity O(n)
// Space complexity O(1)

// first you take a profit variable , and also mentain a minvalue of your array / stock
// then run a loop one to last because , in first day you can't sell your stock , first you Buy stock then sell
// then check if your current value is lessthan minval then you update the minval=prices[i]

// if you have already minval then go to else block , then check if the prices[i]- minVal is graterthan profit then you update profit ...

// then finally return your profit



```

## [Rotate Image](https://leetcode.com/problems/rotate-image/)

```
// first rotate or exchange the n Diagonal element ;
var rotate = function(matrix) {
    let n = matrix.length
    // reverse the diagonal
    for(let i=0 ; i < n ;i++){
        for(let j=i ; j < n ;j++){
            let temp= matrix[j][i]
            matrix[j][i] = matrix[i][j]
            matrix[i][j]=temp

        }
    }

       // reverse the each row element
     // n = length of matrix
       for(let i = 0 ; i< n;i++){
          for(let j = 0 ; j < Math.floor(n/2) ; j++){

              let temp = matrix[i][j]

              matrix[i][j] = matrix[i][n - j - 1]   // it means [n - j - 1] , to reduce one by one element in last  side / position , (j) helps to decrease one by one element  , Math.floor(3/2) = 1;

              matrix[i][n - j - 1]= temp
          }
       }


    // Another way to reverse the matrix
//     for(let i = 0 ; i < matrix.length ; i++){
//         let s = 0 , e = matrix.length-1
//         while(s < e){
//             let temp = matrix[i][s];
//             matrix[i][s] = matrix[i][e];
//             matrix[i][e] = temp;
//             s++;
//             e--;

//         }
//     }

   }

// Time complexity O(n^2) + O(n^2)  (rotate + reverse) , => 2 O(n^2) = O(n^2) (2 constant),
so the time complexity  is O(n^2)
// Space complexity O(n^2)
```

## [Merge Intervals](https://leetcode.com/problems/merge-intervals/)

```
let merge = (intervals)=> {
   intervals = intervals.sort((a, b) => a[0] - b[0]);
   let stack = [];
    stack.push(intervals[0]);

  for (let i = 1; i < intervals.length; i++) {
    let prev = stack.pop();
    let cur = intervals[i];
    if (prev[1] >= cur[0]) {
      stack.push([prev[0], Math.max(cur[1], prev[1])]);
    } else {
      stack.push(prev, cur);
    }
  }
  return stack;
};

// Time complexity O(nlogn) + O(n) (sorting + traversal)
// Space complexity O(n)
```
