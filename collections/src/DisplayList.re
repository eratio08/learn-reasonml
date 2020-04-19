let intReducer = (accumulator: string, item: int) => {
  accumulator ++ string_of_int(item) ++ ", ";
};

let stringOfIntList = (items: list(int)): string => {
  "[" ++ Belt.List.reduce(items, "", intReducer) ++ "]";
};

let items = [10, 11, 12, 13, 14, 15];
Js.log(stringOfIntList(items));

let floatReducer = (accumulator: string, item: float) => {
  accumulator ++ Js.Float.toString(item) ++ ", ";
};
let stringOfFloatList = (items: list(float)): string => {
  "[" ++ Belt.List.reduce(items, "", floatReducer) ++ "]";
};
let floatItems = [3.6, 7.9, 8.25, 41.0];
Js.log(stringOfFloatList(floatItems));

let displayList = (items: list('a), stringify: 'a => string): string => {
  let elementReducer = (accumulator: string, item: 'a) => {
    accumulator ++ stringify(item) ++ ", ";
  };
  "[" ++ Belt.List.reduce(items, "", elementReducer) ++ "]";
};

Js.log(displayList(items, string_of_int));
Js.log(displayList(floatItems, Js.Float.toString));