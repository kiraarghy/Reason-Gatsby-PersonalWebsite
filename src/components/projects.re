let component = ReasonReact.statelessComponent("Projects");

module Styles = {
  open Css;
  let project = oddOrEven =>
    style([gridColumnStart(oddOrEven[0]), gridColumnEnd(oddOrEven[1])]);

  let icon =
    style([
      width(`percent(20.0)),
      marginTop(`percent(1.0)),
      marginLeft(`percent(1.0)),
    ]);
};

let make = (~data, ~index, _children) => {
  ...component,
  render: _self => {
    Js.log(data##logo);
    let oddOrEven =
      switch (mod_float(float_of_int(index), 2.0)) {
      | 1.0 => [|3, 5|]
      | _ => [|1, 3|]
      };
    Js.log(oddOrEven);
    <div className=(Styles.project(oddOrEven))>
      <img className=Styles.icon src=data##logo##file##url />
      <h2> (ReasonReact.string(data##projectTItle)) </h2>
      <p> (ReasonReact.string(data##blurb##blurb)) </p>
    </div>;
  },
};