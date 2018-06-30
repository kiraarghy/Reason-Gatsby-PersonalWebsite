let component = ReasonReact.statelessComponent("Projects");

module Styles = {
  open Css;
  let project =
    style([
      backgroundColor(`hex("C38D9E")),
      marginBottom(`percent(10.0)),
      borderRadius(`px(5)),
      cursor(`pointer),
      textDecoration(`none),
      hover([textDecoration(`underline)]),
    ]);

  let icon =
    style([
      height(`percent(5.0)),
      minHeight(`px(60)),
      marginTop(`percent(-2.0)),
      marginLeft(`percent(-1.0)),
      backgroundColor(`hex("E27D60")),
      border(`px(5), `solid, `hex("E27D60")),
      borderRadius(`px(5)),
      position(`absolute),
      boxShadow(
        ~x=`px(4),
        ~y=`px(4),
        ~blur=`px(7),
        ~spread=`px(-1),
        ~inset=false,
        `hex("000000"),
      ),
    ]);

  let header =
    style([
      marginTop(`vh(6.0)),
      marginLeft(`percent(3.0)),
      color(`hex("2b2e88")),
    ]);
  let content = style([margin(`percent(3.0)), color(`hex("2b2e88"))]);
};

let make = (~data, ~index, _children) => {
  ...component,
  render: _self =>
    <a className=Styles.project href=data##url target="_blank">
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
    </a>,
};