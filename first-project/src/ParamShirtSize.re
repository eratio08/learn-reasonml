type shirtSize =
  | Small
  | Medium
  | Large
  | XLarge(int);

let mySize: shirtSize = Medium;
let bigSize = XLarge(1);
let veryBigSize = XLarge(3);

let price = (size: shirtSize): float => {
  switch (size) {
  | Small => 11.00
  | Medium => 12.50
  | Large => 14.00
  | XLarge(n) => 16.00 +. float_of_int(n - 1) *. 0.50
  };
};

Js.log(price(mySize));
Js.log(price(bigSize));
Js.log(price(veryBigSize));

let stringOfShirtSize = (size: shirtSize): string => {
  switch (size) {
  | Small => "S"
  | Medium => "M"
  | Large => "L"
  | XLarge(n) => String.make(n, 'X') ++ "L"
  };
};

Js.log(stringOfShirtSize(veryBigSize));

type colorSpec =
  | White
  | Black
  | Gray(float)
  | RGB(int, int, int);

let stringOfColorSpec = (cspec: colorSpec): string => {
  switch (cspec) {
  | White => "rgb(255,255,255)"
  | Black => "rgb(0,0,0)"
  | Gray(p) =>
    let n = string_of_int(int_of_float(p *. 255.0));
    {j|rgb($n,$n,$n)|j};
  | RGB(r, g, b) => {j|rgb($r,$g,$b)|j}
  };
};

Js.log(stringOfColorSpec(White)); /* rgb(255,255,255) */
Js.log(stringOfColorSpec(Black)); /* rgb(0,0,0) */
Js.log(stringOfColorSpec(Gray(0.5))); /* rgb(127,127,127) */
Js.log(stringOfColorSpec(RGB(64, 128, 192))); /* rgb(64,128,192) */