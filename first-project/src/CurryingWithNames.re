let payment = (~principal: float, ~apr: float, ~years: int=30, ()) => {
  let r = apr /. 12.0 /. 100.0;
  let n = float_of_int(years * 12);
  let powerTerm = (1.0 +. r) ** n;
  principal *. (r *. powerTerm) /. (powerTerm -. 1.0);
};

let usPayment = payment(~years=30);
let ukPayment = payment(~years=25);
let dePayment = payment(~years=20);

let toFixed = Js.Float.toFixedWithPrecision;

Js.log("Loan of 10000 at 5%");
Js.log2(
  {js| US: $|js},
  toFixed(usPayment(~principal=10000.0, ~apr=5.0, ()), ~digits=2),
);
Js.log2(
  {js| UK: £|js},
  toFixed(ukPayment(~principal=10000.0, ~apr=5.0, ()), ~digits=2),
);
Js.log2(
  {js| EU: €|js},
  toFixed(dePayment(~principal=10000.0, ~apr=5.0, ()), ~digits=2),
);

let discount = (~dPercentage: float, ~price: float) => {
  let discountAmount = price *. dPercentage;
  price -. discountAmount;
};

let halfOff = discount(~dPercentage=0.50);
let tenPercentOff = discount(~dPercentage=0.10);

Js.log2("50% off", halfOff(~price=100.0));
Js.log2("10% off", tenPercentOff(~price=100.0));