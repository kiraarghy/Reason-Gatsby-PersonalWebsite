let component = ReasonReact.statelessComponent("Header");

module Styles = {
  open Css;

  let wrapper =
    style([
      media("(min-width: 700px)", [gridColumn(4, 5)]),
      gridColumn(4, 7),
    ]);

  let text =
    style([
      fontFamily("Lato"),
      fontSize(`vw(8.0)),
      zIndex(2),
      left(`percent(25.0)),
      paddingTop(`px(58)),
      top(`percent(0.0)),
      minWidth(`px(150)),
      textTransform(uppercase),
      media("(min-width: 700px)", [position(sticky)]),
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
type data = {
  .
  allContentfulProjects: ProjectWrapper.allContentfulProjects,
  contentfulAbout: contentfulAbout,
};

[@bs.deriving abstract]
type jsProps = {. data: data};

let make = (~data, _children) => {
  ...component,
  render: _self =>
    <div className=Styles.wrapper>
      <h1 className=Styles.text>
        (ReasonReact.string(data##contentfulAbout##name))
      </h1>
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~data=jsProps##data, [||])
  );