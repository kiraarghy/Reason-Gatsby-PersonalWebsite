let component = ReasonReact.statelessComponent("Content");

module Styles = {
  open Css;
  let text =
    style([
      fontFamily("Lato"),
      zIndex(2),
      left(`percent(50.0)),
      right(`percent(10.0)),
      position(absolute),
      color(hex("FFFFFF")),
    ]);
};
let make = (~data, _children) => {
  ...component,
  render: _self =>
    <div className=Styles.text> (ReasonReact.string(data##markdown)) </div>,
};