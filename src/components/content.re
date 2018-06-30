let component = ReasonReact.statelessComponent("Content");

module Styles = {
  open Css;

  let content =
    style([
      gridColumn(2, 8),
      paddingBottom(`percent(10.0)),
      media(
        "(min-width: 700px)",
        [
          gridColumn(6, 8),
          display(grid),
          gridTemplateRows([`fr(0.5), `fr(1.0), `fr(0.5)]),
          paddingBottom(`percent(0.0)),
        ],
      ),
    ]);
  let text =
    style([
      gridRow(2, 3),
      fontFamily("Lato"),
      fontSize(`percent(150.0)),
      paddingTop(`percent(5.0)),
      color(hex("FFFFFF")),
    ]);
};

[@bs.deriving abstract]
type jsProps = {. data: string};

let make = (~data, _children) => {
  ...component,
  render: _self =>
    <div className=Styles.content>
      <div className=(Styles.text ++ " content")>
        (ReasonReact.string(data))
      </div>
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~data=jsProps##data, [||])
  );