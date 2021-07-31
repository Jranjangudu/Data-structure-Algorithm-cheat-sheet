const data = {
  name: "***",
  age: "26",
};

data["mobile"] = "0000-000-000";
data.education = "M-Tech";
const information = {
  ...data,
  fullname: "***** ",
};
console.table(data);
console.table(information);
