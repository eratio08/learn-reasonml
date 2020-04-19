let more = [|17, 18, 19|];
let joined = Belt.Array.concat(IntArray.items, more);

let part1 = [|"the", "array", "has"|];
let part2 = Belt.Array.concat(part1, [|"more"|]);

Js.log(part2);

Js.log(Belt.Array.slice(IntArray.items, ~offset=1, ~len=3));
Js.log(Belt.Array.slice(IntArray.items, ~offset=5, ~len=9));
Js.log(Belt.Array.slice(IntArray.items, ~offset=-3, ~len=2));
Js.log(Belt.Array.slice(IntArray.items, ~offset=3, ~len=-2));

let arrayTake = (a: array('a), n: int) =>
  Belt.Array.slice(a, ~offset=0, ~len=n);

Js.log(arrayTake(IntArray.items, 3));

let arrayDrop = (a: array('a), n: int) =>
  Belt.Array.slice(a, ~offset=n, ~len=Belt.Array.length(a));

Js.log(arrayDrop(IntArray.items, 3));

let arraySplitAt = (n: int) => (
  arrayTake(IntArray.items, n),
  arrayDrop(IntArray.items, n),
);
Js.log(arraySplitAt(3));