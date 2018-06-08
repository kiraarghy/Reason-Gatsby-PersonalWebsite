let component = ReasonReact.statelessComponent("Content");

module Styles = {
  open Css;
};

let make = (~data, _children) => {
  ...component,
  render: _self => <div> (ReasonReact.string(data##markdown)) </div>,
};