# 1. Lexical Enviranment

<!-- <hr/> -->

-> Lexical enviranment is created , when execution context is created .!

- Lexical ==> local memory + ref. to the Lexical enviranment of parent

<!-- <hr/> -->

# 2. Scope Chain

-> When a variable is used in JavaScript, the JavaScript engine will try to find the variable’s value in the current scope. If it could not find the variable, it will look into the outer scope and will continue to do so until it finds the variable or reaches global scope.

-> If it’s still could not find the variable, it will either implicitly declare the variable in the global scope (if not in strict mode) or return an error.

-> so this process is call scope chain

<!-- <hr/> -->

# let and const

-> let and const variable store in a shaparate memory zone is called { script zone }

-> let and const declaration are hoisted , but in different way ! , these are hoisted in temporal dead zone

-> when we try to access a variable in temporal zone , it give ref. error , until some value not assign to this variable ;

<!-- <hr/> -->

# Block scope and shadowing

-> The grouping of multiple statement inside Curly brases { } , this is known as block
-> let and const are block scope;

Example

<code>
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
</code>
