let component = ReasonReact.statelessComponent("Projects");

module Styles = {
  open Css;
  let project = oddOrEven =>
    style([
      gridColumn(1, 6),
      media("(min-width: 600px)", [gridColumn(oddOrEven[0], oddOrEven[1])]),
      backgroundColor(`hex("C38D9E")),
      marginBottom(`percent(10.0)),
      borderRadius(`px(5)),
    ]);

  let icon =
    style([
      height(`percent(5.0)),
      marginTop(`percent(-2.0)),
      marginLeft(`percent(-1.0)),
      backgroundColor(`hex("E27D60")),
      border(`px(5), `solid, `hex("E27D60")),
      borderRadius(`px(5)),
      position(`absolute),
    ]);

  let header =
    style([
      marginTop(`vh(5.0)),
      marginLeft(`percent(3.0)),
      color(`hex("ffff")),
    ]);
  let content = style([margin(`percent(3.0))]);
};

let make = (~data, ~index, _children) => {
  ...component,
  render: _self => {
    let oddOrEven =
      switch (mod_float(float_of_int(index), 2.0)) {
      | 1.0 => [|4, 6|]
      | _ => [|1, 3|]
      };
    <div className=(Styles.project(oddOrEven))>
      <img
        className=Styles.icon
        src=data##logo##file##url
        alt=data##logo##title
      />
      <h2 className=Styles.header>
        (ReasonReact.string(data##projectTItle))
      </h2>
      <p className=Styles.content>
        (ReasonReact.string(data##blurb##blurb))
      </p>
    </div>;
  },
};