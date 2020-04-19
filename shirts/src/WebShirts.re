module D = Webapi.Dom;
module Doc = Webapi.Dom.Document;
module Elem = Webapi.Dom.Element;

let getValue = (element: option(Elem.t)): option(string) => {
  element
  ->Belt.Option.map(_, Elem.unsafeAsHtmlElement)
  ->Belt.Option.map(_, D.HtmlElement.value);
};

let toInt = (s: string): option(int) => {
  switch (int_of_string(s)) {
  | result => Some(result)
  | exception (Failure("int_of_string")) => None
  };
};

type shirtSize =
  | Small
  | Medium
  | Large
  | XLarge(int);

let shirtSizesOfString = (str: string): option(shirtSize) => {
  switch (str) {
  | "S" => Some(Small)
  | "M" => Some(Medium)
  | "L" => Some(Large)
  | "XL" => Some(XLarge(1))
  | "XXL" => Some(XLarge(2))
  | "XXXL" => Some(XLarge(3))
  | "XXXXL" => Some(XLarge(4))
  | _ => None
  };
};

let price = (size: shirtSize): float => {
  switch (size) {
  | Small => 11.00
  | Medium => 12.50
  | Large => 14.00
  | XLarge(n) => 16.00 +. float_of_int(n - 1) *. 0.50
  };
};

let toFixed = Js.Float.toFixedWithPrecision;

let buildDisplayText = (amount: option(float)) => {
  switch (amount) {
  | Some(cost) =>
    let costStr = toFixed(cost, ~digits=2);
    {j|Your $input shirt costs \$$costStr.|j};
  | None => {j|Canot determine price for $input|j}
  };
};

let quantityInput = Doc.getElementById("quantity", D.document);
let sizeSelection = Doc.getElementById("size", D.document);

let calculate = (_: Dom.event): unit => {
  let quantity = getValue(quantityInput)->Belt.Option.flatMap(_, toInt);
  let unitPrice =
    getValue(sizeSelection)
    ->Belt.Option.flatMap(_, shirtSizesOfString)
    ->Belt.Option.map(_, price);

  let totalPrice =
    switch (unitPrice, quantity) {
    | (Some(uPrice), Some(qty)) => Some(uPrice *. float_of_int(qty))
    | (_, _) => None
    };

  let priceString =
    switch (totalPrice) {
    | Some(total) => Js.Float.toFixedWithPrecision(total, ~digits=2)
    | None => ""
    };
  let _ =
    Doc.getElementById("price", D.document)
    ->Belt.Option.map(_, Elem.setInnerText(_, priceString));
  ();
};

quantityInput->Belt.Option.map(_, element =>
                 D.EventTarget.addEventListener(
                   "input",
                   calculate,
                   Elem.asEventTarget(element),
                 )
               );

sizeSelection->Belt.Option.map(_, element =>
                 D.EventTarget.addEventListener(
                   "change",
                   calculate,
                   Elem.asEventTarget(element),
                 )
               );