// Call() Method----------->

// 1. The call() method allows for a function / method belonging to one object to be assigned and called for a different object ;

// 2. Using call() mathod you can do function borrowing , we can borrow function from the other object ;

// Ex:-

function disp() {
  console.log("print something ..");
}

// invoke a function
disp(); // print something..
disp.call(); // print something..
disp.apply(); // print something..
// when you invoke a function , behind the screen it do like  this --> disp.call()

// Another example

let persone1 = {
  name: "Reshma",
  battery: 70, // 70%
  charge_battery: function () {
    // if we invoke / call this charge_battery function , this update the battery 70% to 100%
    this.battery = 100; //100%
  },
};
// persone1.charge_battery();
// console.log(persone1);

let persone2 = {
  name: "Guddu",
  battery: 30, //30%
}; // if i want to update/modify my battery value , i need charge_battery() function , but instance writting again tha same code , i just barrow the method to Reshma by the help of call() mathod !!

// here i barrow charge_battery() method
persone1.charge_battery.call(persone2); // This line means you need charge_battery () method of person1 and used in persone2 object ;

console.log(persone1);
console.log(persone2);
// Output 👇
// {
//     name: 'Reshma',
//     battery: 70,
//     charge_battery: [Function: charge_battery]
//   }
//   { name: 'Guddu', battery: 100 }

// apply()---------------------------------------
persone1.charge_battery.apply(persone2);

console.log(persone1);
console.log(persone2);
// Output 👇
// {
//     name: 'Reshma',
//     battery: 70,
//     charge_battery: [Function: charge_battery]
//   }
//   { name: 'Guddu', battery: 100 }
// .
// .
// .
// @Note >>>>>>>>>>>>>>>>>>>>
// call() , apply() and bind() method are quite similar
// * call() and apply() method invoke immidatly but bind() method retuen a function , so you need to call the return function ;

// bind()------->

let result = persone1.charge_battery.bind(persone2);
result(); // invoke bind function
console.log(persone2);

// Output 👇
//{ name: 'Guddu', battery: 100 }
