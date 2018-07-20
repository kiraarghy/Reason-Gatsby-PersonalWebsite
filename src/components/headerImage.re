let component = ReasonReact.statelessComponent("HeaderImage");

module Styles = {
  open Css;

  let wrapper = style([gridColumn(2, 5), gridRow(1, 2)]);
  let picture =
    style([
      maxHeight(`px(700)),
      marginTop(`px(50)),
      maxWidth(`percent(100.0)),
      borderRadius(px(5)),
      display(none),
      media("(min-width: 700px)", [display(block)]),

    ]);
    let logo = style([      border(px(3), solid, hex("E27D60")),
    maxWidth(`px(200)),
    borderRadius(px(400)),
    marginLeft(`percent(3.0)),
    marginTop(`px(50)),
    media("(min-width: 700px)", [display(none)]),]);
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
        src=(data##contentfulAbout##portrait##file##url)
      />
      <img
      className=Styles.logo
      alt=data##contentfulAbout##portrait##description
      src=(data##contentfulAbout##logo##file##url)
    />
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~data=jsProps##data, [||])
  );