// The JavaScript this keyword refers to the object it belongs to.

// It has different values depending on where it is used:

// In a method, this refers to the owner object.
// Alone, this refers to the global object.
// In a function, this refers to the global object.
// In a function, in strict mode, this is undefined.
// In an event, this refers to the element that received the event.
// Methods like call(), and apply() can refer this to any object.

// --------------------this in a Method-----------------

const person = {
  firstName: "simran",
  lastName: "simu",
  id: 5566,
  fullname: function () {
    console.log(this.firstName + " " + this.lastName);
    // here {this} points to the owner object. [ means person object ]
    //The person object is the owner of the fullName method.
  },
};

person.fullname();

// In the example below, when calling person1.fullName with person2 as argument, this will refer to person2, even if it is a method of person1:
const person1 = {
  fullName: function () {
    return this.firstName + " " + this.lastName;
  },
};
const person2 = {
  firstName: "John",
  lastName: "Doe",
};
person1.fullName.call(person2); // Will return "John Doe"

// ---------this Alone---------------

// When used alone, the owner is the Global object, so this refers to the Global object.In a browser window the Global object
let x = this;
console.log(x);
// output -
// Window {0: Window, 1: Window, 2: global, 3: Window, 4: Window, 5: Window, 6: global, 7: global, 8: global, 9: global, 10: global, 11: global, 12: global, 13: global, 14: global, 15: Window, 16: Window, 17: global, 18: global, 19: Window, window: Window, self: Window, document: document, name: '', location: Location, …}

// ---------this in a Function ---------------

// In a JavaScript function, the owner of the function is the default binding for this.

// So, in a function, this refers to the Global object [object Window].

function func() {
  console.log(this);
}

func();

// ------------- this in Event Handlers ------------

// In HTML event handlers, this refers to the HTML element that received the event:

{
  /* <button onclick="this.style.display='none'">Click to Remove Me!</button>; */
}

// when we click the {Click to Remove Me!} button , it remove the button from webpage

// .
// .
// .
// .
// .
// .
// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

let data = {
  name: "simran",
  age: 20,
  show: function () {
    console.log(this.name, this.age);
  },
};

let info = {
  name: "guddu",
  age: 22,
};

data.show.call(info); // here {this} points to info object;
data.show.apply(data); // here {this} points to data object;
let res = data.show.bind(info); // here {this} points to info object; by the way bind() method return a function , so you need to invoke / call the return function ;
res();
// ------------------------------------------
function Cost(name, age) {
  (this.name = name), (this.age = age);
}
Cost.prototype.add = function () {
  console.log(this.name, this.age);
};

let c = new Cost("simran", 21);
let p = new Cost("pooja", 21);
c.add();
p.add();

// ---------------------------------
let usefun = function () {
  console.log(this.name, this.age, this);
};
let data = {
  name: "simu",
  age: 21,
};
let data2 = {
  name: "guddu",
  age: 22,
};
usefun.call(data); // [this] point to data object
usefun.call(data2); // [this] point to data2 object
// output
// simu 21 {name: 'simu', age: 21}
// guddu 22 {name: 'guddu', age: 22}

// ----------------------

function printData() {
  // console.log(this)
  this.forEach((ele) => {
    console.log(ele);
  });
}

let ar = [12, 34, 5, 6, 7, 8, 9];
let arr = [4, 6, 7, 8, 8, 8];

printData.call(ar);
console.log("-------");
printData.apply(arr);





