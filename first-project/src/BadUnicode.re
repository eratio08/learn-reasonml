let qty = 7;

let price = 10.50;

let discount = qty < 10 ? 0.05 : 0.10;

let total = float_of_int(qty) *. price;

let afterDiscount = total *. (1.0 -. discount);

Js.log("Prix avant réduction: " ++ Js.Float.toString(total) ++ " €");
Js.log(
  "Prix après réduction: " ++ Js.Float.toString(afterDiscount) ++ " €",
);

Js.log(
  {js|Prix avant réduction: |js} ++ Js.Float.toString(total) ++ {js| €|js},
);
Js.log(
  {js|Prix après réduction: |js}
  ++ Js.Float.toString(afterDiscount)
  ++ {js| €|js},
);

Js.log({j|Prix avant réduction: $total €|j});
Js.log({j|Prix après réduction: $afterDiscount €|j});