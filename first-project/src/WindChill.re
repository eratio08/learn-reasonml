let t = 5;
let v = 20;

let tFloat = float_of_int(5);
let vFloat = float_of_int(20);

let windChil =
  13.12
  +. 0.6215
  *. tFloat
  -. 11.37
  *. vFloat
  ** 0.16
  +. 0.3965
  *. tFloat
  *. vFloat
  ** 0.16;

Js.log(
  {j| At temperature $t degrees C and wind speed $v km/hr, the wind chill temperature is $windChil.|j},
);