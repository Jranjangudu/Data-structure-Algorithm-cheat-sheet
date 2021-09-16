// Promises are used to handle asynchronous operations ;
// resolve ---> if your promise is success;
// reject ---> if your promise is failed;

// if your promise is resolve(completed) , then it comes to .then() method;
// if your promise is reject(failed) , then it comes to .catch() method;

let p = new Promise((resolve, reject) => {
  let status = true;
  //let status = false;
  if (status) {
    resolve("message send successfully ..");
  } else {
    reject("unable to send your message ..");
  }
});

p.then((message) => {
  console.log(message); // o/p ->  message send successfully ..
}).catch((errmsg) => {
  console.log(errmsg); // o/p -> unable to send your message ..
});
