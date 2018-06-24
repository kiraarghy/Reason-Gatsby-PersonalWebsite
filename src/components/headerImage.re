let component = ReasonReact.statelessComponent("HeaderImage");

module Styles = {
  open Css;

  let wrapper = style([gridColumn(2, 3), gridRow(1, 2)]);
  let picture =
    style([
      border(px(3), solid, hex("E27D60")),
      maxWidth(`px(200)),
      borderRadius(px(400)),
      marginLeft(`percent(3.0)),
      marginTop(`px(50)),
    ]);
};

[@bs.deriving abstract]
type data = {
  .
  allContentfulProjects: ProjectWrapper.allContentfulProjects,
  contentfulAbout: Header.contentfulAbout,
};

[@bs.deriving abstract]
type jsProps = {. data: data};

let make = (~data, _children) => {
  ...component,
  render: _self =>
    <div className=Styles.wrapper>
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