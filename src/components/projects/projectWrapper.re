let component = ReasonReact.statelessComponent("ProjectWrapper");

module Styles = {
  open Css;
  let projects = style([gridColumn(2, 8)]);

  let title =
    style([
      fontSize(`percent(150.0)),
      paddingBottom(`percent(5.0)),
      color(hex("FFFFFF")),
    ]);
  let projectWrapper =
    style([
      display(grid),
      gridTemplateColumns([`fr(1.0)]),
      gridGap(`percent(10.0)),
      media(
        "(min-width: 1200px)",
        [
          gridTemplateColumns([`fr(1.0), `fr(1.0), `fr(1.0)]),
          gridGap(`percent(10.0)),
        ],
      ),
      media(
        "(min-width: 650px)",
        [
          gridTemplateColumns([`fr(1.0), `fr(1.0)]),
          gridGap(`percent(10.0)),
        ],
      ),
    ]);
};

[@bs.deriving abstract]
type blurb = {. blurb: string};

[@bs.deriving abstract]
type file = {. url: string};

[@bs.deriving abstract]
type logo = {
  .
  description: string,
  file: file,
  title: string,
};

[@bs.deriving abstract]
type node = {
  .
  projectTItle: string,
  logo: logo,
  blurb: blurb,
  url: string,
};

[@bs.deriving abstract]
type allContentfulProjects = {. edges: array({. node: node})};

[@bs.deriving abstract]
type data = {. allContentfulProjects: allContentfulProjects};

[@bs.deriving abstract]
type jsProps = {. data: data};

let make = (~data, _children) => {
  ...component,
  render: _self => {
    let edges = data##allContentfulProjects##edges;
    <div className=Styles.projects>
      <div className=Styles.title>
        (ReasonReact.string("Projects I have worked on"))
      </div>
      <div className=Styles.projectWrapper>
        (
          ReasonReact.array(
            Array.map(edge => <Projects data=edge##node />, edges),
          )
        )
      </div>
    </div>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~data=jsProps##data, [||])
  );

let helloReactJSGirls = (~blah: string) => Js.log(blah);