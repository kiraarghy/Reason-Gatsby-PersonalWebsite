let component = ReasonReact.statelessComponent("Content");

module Styles = {
  open Css;
  let text =
    style([
      fontFamily("Lato"),
      paddingTop(`percent(13.0)),
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
    <div className=(Styles.text ++ " content")>
      (ReasonReact.string(data##contentfulAbout##markdown##markdown))
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~data=jsProps##data, [||])
  );