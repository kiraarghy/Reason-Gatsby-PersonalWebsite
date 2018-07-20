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
          alignSelf(`center)
        ],
      ),
    ]);
  let text =
    style([
      fontSize(`percent(150.0)),
      paddingTop(`percent(5.0)),
      color(hex("FFFFFF")),
    ]);
};

[@bs.deriving abstract]
type jsProps = {. data: string};

let make = (~data, _children) => {
  ...component,

  render: _self =>{
    <div className=Styles.content>
      <div className=(Styles.text)>
        (ReasonReact.array(Array.mapi((i,item) => 
        if (i === 0) {
            <h2 key=(string_of_int(i))>
              (ReasonReact.string(item))
            </h2>;
          } else {
            <p key=(string_of_int(i))> (ReasonReact.string(item)) </p>;
          },Js.String.split("\\n",data),)))
      </div>
    </div>}
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~data=jsProps##data, [||])
  );