let component = ReasonReact.statelessComponent("Header");

module Styles = {
  open Css;
  let picture =
    style([
      width(`percent(30.0)),
      border(px(3), solid, hex("E27D60")),
      borderRadius(px(400)),
      marginTop(em(3.0)),
      marginLeft(em(3.0)),
    ]);

  let text =
    style([
      fontFamily("Lato"),
      zIndex(2),
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
type markdown = {markdown: string};

[@bs.deriving abstract]
type contentfulAbout = {
  .
  name: string,
  portrait: portrait,
  content: markdown,
};

[@bs.deriving abstract]
type data = {. contentfulAbout: contentfulAbout};

[@bs.deriving abstract]
type jsProps = {. data: data};

let make = (~data, _children) => {
  ...component,
  render: _self =>
    <div>
      <h1 className=Styles.text>
        (ReasonReact.string(data##contentfulAbout##name))
      </h1>
      <img
        className=Styles.picture
        alt=data##contentfulAbout##portrait##description
        src=(data##contentfulAbout##portrait##file##url ++ "?w=300&h=300")
      />
      <Content data=data##contentfulAbout##markdown />
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~data=jsProps##data, [||])
  );