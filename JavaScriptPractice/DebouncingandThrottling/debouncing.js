// In the debouncing technique, no matter how many times the user fires the event, the attached function will be executed only after the specified time once the user stops firing the event.

const userDiv = document.getElementById("userData");
const get_input_data = document.getElementById("input");
const cound_btnclick = document.getElementById("cound_btnclick");

// This represents a very heavy method. Which takes a lot of time to execute
let apicallCount = 1;
function makeAPICall(text) {
  //
  let html = "";

  apicallCount += 1;
  fetch(
    `https://api.edamam.com/search?q=${text}&app_id=16ad8eb2&app_key=11c514b334846bac22e3a9697a53f51e`
  )
    .then((res) => {
      return res.json();
    })
    .then((data) => {
      data.hits.forEach((element) => {
        let htmlSegment = `
                         <div class="user">
                            <img src=${element.recipe.image} />
                            <p>  ${element.recipe.label} </p>
                         </div>
        `;
        html += htmlSegment;
      });
      userDiv.innerHTML = html;
    })
    .catch((err) => {
      console.log(err);
    });
  timerId = undefined;
}

// Debounce function: Input as function which needs to be debounced and delay is the debounced time in milliseconds
let timerId;
function debounceFunction(func, text, delay) {
  // Cancels the setTimeout method execution
  clearTimeout(timerId);
  // Executes the func after delay time.
  //  The setTimeout function returns an integer value as its unique id, which is stored by the timerId.
  timerId = setTimeout(() => {
    func(text);
  }, delay);
}

// Event listener on the input box
let count = 0;
get_input_data.addEventListener("keypress", () => {
  cound_btnclick.innerHTML = ` you search  :- ${parseInt(
    (count += 1)
  )} times But apicall only ${apicallCount} times because of debouncing technique`;
  let text = get_input_data.value.trim();

  if (text.length !== 0) {
    // Debounces makeAPICall method
    debounceFunction(makeAPICall, text, 300);
  }
});
