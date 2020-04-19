module D = Webapi.Dom;
module Doc = Webapi.Dom.Document;
module Elem = Webapi.Dom.Element;

let payment = (~principal, ~apr, ~years) => {
  let r = apr /. 12.0 /. 100.0;
  let n = float_of_int(years * 12);
  let powerTerm = (1.0 +. r) ** n;
  principal *. (r *. powerTerm) /. (powerTerm -. 1.0);
};

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

let getIntValue = (elementId: string): option(int) => {
  elementId
  ->Doc.getElementById(_, D.document)
  ->getValue
  ->Belt.Option.flatMap(_, toInt);
};

let toFloat = (s: string): option(float) => {
  switch (float_of_string(s)) {
  | result => Some(result)
  | exception (Failure("float_of_string")) => None
  };
};

let getFloatValue = (elementId: string): option(float) => {
  elementId
  ->Doc.getElementById(_, D.document)
  ->getValue
  ->Belt.Option.flatMap(_, toFloat);
};

let principalId = "principal";
let aprId = "apr";
let yearsId = "years";

let principalInput = Doc.getElementById(principalId, D.document);
let aprInput = Doc.getElementById(aprId, D.document);
let yearInput = Doc.getElementById(yearsId, D.document);
let paymentDisplay = Doc.getElementById("payment", D.document);

let setInnerText = (text: string, elementId: string): option(unit) =>
  Doc.getElementById(elementId, D.document)
  ->Belt.Option.map(_, Elem.setInnerText(_, text));

let toFixed = Js.Float.toFixedWithPrecision;

let calculate = (_: Dom.event): unit => {
  let principal = getFloatValue(principalId);
  let apr = getFloatValue(aprId);
  let years = getIntValue(yearsId);

  Belt.Option.flatMap(principal, p =>
    Belt.Option.flatMap(apr, r =>
      Belt.Option.map(years, y => payment(~principal=p, ~apr=r, ~years=y))
    )
  )
  ->Belt.Option.map(_, toFixed(_, ~digits=3))
  ->Belt.Option.flatMap(_, setInnerText(_, "payment"))
  ->Belt.Option.getWithDefault(_, ());
};

let addListener =
    (
      eventType: string,
      element: option(Dom.element),
      action: Dom.event => unit,
    ) =>
  Belt.Option.map(element, element =>
    D.EventTarget.addEventListener(
      eventType,
      action,
      Elem.asEventTarget(element),
    )
  );

let addInputListener = addListener("input");

addInputListener(principalInput, calculate);
addInputListener(aprInput, calculate);
addInputListener(yearInput, calculate);