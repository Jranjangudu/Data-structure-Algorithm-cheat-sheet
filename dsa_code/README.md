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

```
