## 1. Lexical Enviranment

<!-- <hr/> -->

- Lexical enviranment is created , when execution context is created .!

- Lexical ==> local memory + ref. to the Lexical enviranment of parent

<!-- <hr/> -->

## 2. Scope Chain

There are three types of scopes in JS:

- Global Scope
- Local or Function Scope
- Block Scope

- When a variable is used in JavaScript, the JavaScript engine will try to find the variable’s value in the current scope. If it could not find the variable, it will look into the outer scope and will continue to do so until it finds the variable or reaches global scope.

- If it’s still could not find the variable, it will either implicitly declare the variable in the global scope (if not in strict mode) or return an error.

- so this process is call scope chain

<!-- <hr/> -->

## 3. let and const

- let and const variable store in a shaparate memory zone is called { script zone }

- let and const declaration are hoisted , but in different way ! , these are hoisted in temporal dead zone

- when we try to access a variable in temporal zone , it give ref. error , until some value not assign to this variable ;

<!-- <hr/> -->

## 4. Block scope and shadowing

- The grouping of multiple statement inside Curly brases { } , this is known as block
- let and const are block scope;

- Block scope is related to the variables declared using let and const. Variables declared with var do not have block scope.

- Block scope tells us that any variable declared inside a block { }, can be accessed only inside that block and cannot be accessed outside of it.

Example

```javascript
 1. var a =10;
{
var a =20; // <-- this is "shadow" of top of the ' a '
}
console.log(a); // o/p = 20#
2.  let a =10;
{
let a =20 ; // 0/p = 20 { here a store in block scope and "a" is the "shadowing" of the top of "a" }
}
console.log(a); // o/p = 10
```

## 5. Callback function

- Any function that is passed as an argument is called a callback function ;
- Callback can be Synchronous if they execute immediately or they can be asynchronous where they execute after some time passed
- A callback is a function that is to be executed after another function has finished executing -- hence the name 'callback'

Example:

```javascript
    function a(arg){
        console.log(" a() func executed ")
        arg()
    }

    function b(){
        console.log(" b() func executed ")
    }

    // invoke a() and passing b() as argument;

    a(b)


    [
     - output :-
        a() func executed
        b() func executed
    ]
```

## 6. [defer & async in script tag] :-

```javascript
The defer attribute is a boolean attribute.
[
    1. <script defer src=""></script>
    2. <script async src=""></script>
]

If the defer attribute is set, it specifies that the script is downloaded in parallel to parsing the page, and executed after the page has finished parsing.

Note: The defer attribute is only for external scripts (should only be used if the src attribute is present).

Note: There are several ways an external script can be executed:

If async is present: The script is downloaded in parallel to parsing the page, and executed as soon as it is available (before parsing completes)
If defer is present (and not async): The script is downloaded in parallel to parsing the page, and executed after the page has finished parsing
If neither async or defer is present: The script is downloaded and executed immediately, blocking parsing until the script is completed

```

## 6. [ Higher-Order Components] :-

```javascript react
import "./styles.css";
import { useState } from "react";
import FOCgreen from "./FOCgreen";
export default function App() {
  return (
    <div className="App">
      Implementing
      <FOCred func={Increment} />
      <FOCblue func={Increment} />
      <FOCgreen func={Increment} />
    </div>
  );
}
// Higher-Order Components
const FOCred = (props) => {
  return (
    <div style={{ backgroundColor: "#FF9933", padding: "2px" }}>
      {" "}
      <props.func />{" "}
    </div>
  );
};
const FOCblue = (props) => {
  return (
    <div style={{ backgroundColor: "white", padding: "2px" }}>
      {" "}
      <props.func />{" "}
    </div>
  );
};

const Increment = () => {
  const [count, setCount] = useState(0);
  return (
    <>
      <h1> count : {count}</h1>
      <button onClick={() => setCount(count + 1)}>increment</button>
    </>
  );
};
```

## . [shallow copy and deep copy] {https://www.geeksforgeeks.org/what-is-shallow-copy-and-deep-copy-in-javascript/}

- Shallow Copy: it means two variable points to same memory location , when one variable modify it value it also changes the another variable , cause of same memory

```javascript
const arr = [10, 203, 40];
const arr1 = arr;
arr1[0] = 101;
arr[1] = 2;
console.log(arr, arr1); // [101, 2, 40] , [101, 2, 40]

// object
const obj = {
  name: "simran",
  age: 22,
};

const obj1 = obj;
obj1.name = "jyoti";
obj1.mobile = 20203846;
console.log(obj, obj1);
//{name: "jyoti", age: 22, mobile: 20203846} --- obj
// {name: "jyoti", age: 22, mobile: 20203846} ---obj1
```

- deep Copy :- it means two variable points to different memory location , when one variable modify it value it don't changes the another variable , both variable point diff memory location

```javascript
const arr = [10, 203, 40];
const arr1 = [...arr];
arr1[0] = 101;
arr[1] = 2;
console.log(arr, arr1); //[10, 2, 40] , [101, 203, 40]

// object
const obj = {
  name: "simran",
  age: 22,
};

const obj1 = { ...obj };
obj1.name = "jyoti";
obj1.mobile = 20203846;
console.log(obj, obj1);
// {name: "simran", age: 22} --->  obj
// {name: "jyoti", age: 22, mobile: 20203846} --->  obj1
```

## .[ Pure Component Vs useMemo ]

Pure Component works in class Component , and usrMemo in functional component;
, both are use to restricts the re-rendering when there is no use of re-rendering of the component , if state or props update then re-render alse stop re-rendering component
