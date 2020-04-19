let items = [10, 11, 12, 13, 14, 15, 16];

let sqrtPlusOne = x => sqrt(float_of_int(x) +. 1.0);

let roots = Belt.List.make(5, sqrtPlusOne);

let added1 = Belt.List.add(items, 9);
let added2 = [9, ...items];

let more = [12, 18, 19];
let joined = Belt.List.concat(items, more);

let taken3 = Belt.List.take(items, 3);
let dropped3 = Belt.List.drop(items, 3);
let badTaken = Belt.List.take(items, 10);

let result = Belt.List.splitAt(items, 3);
switch (result) {
| Some((firstPart, lastPart)) =>
  Js.log(firstPart);
  Js.log(lastPart);
| None => Js.log("None")
};

let optElement = Belt.List.get(items, 3);
let badOptElement = Belt.List.get(items, 10);
let element = Belt.List.getExn(items, 3);
let badElement: int =
  try(Belt.List.getExn(items, 10)) {
  | Js.Exn.Error(e) =>
    switch (Js.Exn.message(e)) {
    | Some(message) => Js.log({j|Error $message|j})
    | None => Js.log("An unknown error occurred")
    };
    (-1);
  };

Js.log(badElement);