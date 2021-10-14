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
