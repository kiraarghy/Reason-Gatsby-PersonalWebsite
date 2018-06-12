let component = ReasonReact.statelessComponent("Header");

module Styles = {
  open Css;

  let container = style([height(px(1000))]);
  let picture =
    style([
      width(`percent(20.0)),
      border(px(3), solid, hex("E27D60")),
      borderRadius(px(400)),
      marginTop(`percent(5.0)),
      marginLeft(`percent(3.0)),
      position(fixed),
    ]);

  let text =
    style([
      fontFamily("Lato"),
      zIndex(2),
      left(`percent(25.0)),
      marginTop(`percent(13.0)),
      width(`percent(20.0)),
      position(fixed),
      color(hex("FFFFFF")),
    ]);
};

[@bs.deriving abstract]
type file = {url: string};

[@bs.deriving abstract]
type portrait = {
  .
  description: string,
  file: file,
};

[@bs.deriving abstract]
type blah = {markdown: string};

[@bs.deriving abstract]
type contentfulAbout = {
  .
  name: string,
  portrait: portrait,
  content: blah,
};

[@bs.deriving abstract]
type data = {. contentfulAbout: contentfulAbout};

[@bs.deriving abstract]
type jsProps = {. data: data};

let make = (~data, _children) => {
  ...component,
  render: _self =>
    <div className=(Styles.container ++ " body")>
      <h1 className=Styles.text>
        (ReasonReact.string(data##contentfulAbout##name))
      </h1>
      <img
        className=Styles.picture
        alt=data##contentfulAbout##portrait##description
        src=(data##contentfulAbout##portrait##file##url ++ "?w=300&h=300")
      />
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~data=jsProps##data, [||])
  );