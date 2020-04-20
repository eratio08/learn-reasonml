let dewPoint = ((temperatur: float, humidity: float)): float => {
  temperatur -. (100.0 -. humidity) /. 5.0;
};

let calculate = (input: array((float, float))): array(float) => {
  input->Belt.Array.map(_, dewPoint);
};

let min = (dewPoints: array(float)): float => {
  dewPoints->Belt.Array.reduce(_, 100.0, (min, dewPoint) =>
               min < dewPoint ? min : dewPoint
             );
};

let max = (dewPoints: array(float)): float => {
  dewPoints->Belt.Array.reduce(_, 0.0, (max, dewPoint) =>
               max > dewPoint ? max : dewPoint
             );
};

let avg = (dewPoints: array(float)): float => {
  dewPoints
  ->Belt.Array.reduce(_, 0.0, (+.))
  ->(sum => sum /. float_of_int(Belt.Array.length(dewPoints)));
};

let data: array((float, float)) = [|
  (27.0, 55.0),
  (15.0, 70.0),
  (18.3, 58.1),
|];

let dewPoints = calculate(data);

Js.log2("Minimum value:", min(dewPoints));
Js.log2("Maximum value:", max(dewPoints));
Js.log2("Average value:", avg(dewPoints));