async function getData() {
  let res = await fetch("data.text", {
    method: "GET",
    headers: {
      "Content-Type": "application/text",
    },
  });
  let data = await res.text();
  console.log(data);
}
getData();
//  ------------------------

async function handlebtn() {
  let res = await fetch("data.json", {
    method: "GET",
    headers: {
      "Content-Type": "application/json",
    },
  });

  let data = await res.json();

  let html = "";
  data.forEach((element) => {
    let htmlSegment = `<div class="user">
                            <img src=${element.url}  width="100px" />
                            <p>${element.id} ${element.title}</p>
                        </div>`;

    html += htmlSegment;
  });

  let node = document.getElementById("userdata");
  // console.log(html);
  node.innerHTML = html;
}
