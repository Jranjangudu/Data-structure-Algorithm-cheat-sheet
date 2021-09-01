// Throttling is a technique in which, no matter how many times the user fires the event, the attached function will be executed only once in a given time interval.

const api_btn = document.getElementById("btn");
const userDiv = document.getElementById("userData");
const cound_btnclick = document.getElementById("cound_btnclick");
// fetch Api

function createelement(data) {
  let para = document.createElement("p");
  para.innerHTML = data;
  return para;
}

function appendchild(parent, children) {
  children.forEach((element) => {
    let new_node = createelement(element);
    parent.appendChild(new_node);
  });
}
// This represents a very heavy method which takes a lot of time to execute
let apicallCount = 1;
function makeAPICall() {
  apicallCount += 1;
  fetch("https://jsonplaceholder.typicode.com/users")
    .then((res) => {
      return res.json();
    })
    .then((data) => {
      data.forEach((element) => {
        let newnode = document.createElement("div");
        newnode.classList = "newcreated_div";
        let item = [element.id, element.name, element.email];
        appendchild(newnode, item);
        userDiv.appendChild(newnode);
      });
    })
    .catch((err) => {
      console.log(err);
    });
}

let timerId; // declaring timeId variable; not assign anything , currently it have undefined value
// Throttle function: Input as function which needs to be throttled and delay is the time interval in milliseconds
function throttleFunction(func, delay) {
  // If setTimeout is already scheduled, no need to do anything , simplely return ;
  //  The setTimeout function returns an integer value as its unique id, which is stored by the timerId.
  if (timerId) {
    return;
  }
  // here i assign unique id value  into timeId variable,
  timerId = setTimeout(() => {
    func(); // calling makeApiCall function;
    timerId = undefined; // re-assign timeId unique id value to undefined,
  }, delay);
}
let count = 0;
api_btn.addEventListener("click", () => {
  cound_btnclick.innerHTML = ` you click button :- ${parseInt(
    (count += 1)
  )} times But apicall only ${apicallCount} times because of Throttling technique`;
  console.log("count button click");
  throttleFunction(makeAPICall, 500);
});
