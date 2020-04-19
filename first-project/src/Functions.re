let avg = (a, b) => {
  (a +. b) /. 2.0;
};

let result = avg(100.0, 5000.0);
Js.log(result);

let payment = (~principal: float, ~apr: float, ~years: int=30, ()) => {
  let r = apr /. 12.0 /. 100.0;
  let n = float_of_int(years * 12);
  let powerTerm = (1.0 +. r) ** n;
  principal *. (r *. powerTerm) /. (powerTerm -. 1.0);
};

let principal = 10000.0;
let apr = 5.0;
let years = 30;

let amount = payment(~principal, ~apr, ~years, ());

Js.log2(
  "Amount per month: $",
  Js.Float.toFixedWithPrecision(amount, ~digits=2),
);

let sqr = x => x * x;