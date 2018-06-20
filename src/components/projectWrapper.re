let component = ReasonReact.statelessComponent("ProjectWrapper");

module Styles = {
  open Css;

  let projectWrapper =
  style([
display(grid),
gridTemplateColumns([`fr(1.0), `fr(1.0), `fr(1.0),`fr(1.0)])
  ]);
};

[@bs.deriving abstract]
type blurb = {. blurb: string};

[@bs.deriving abstract]
type file = {. url: string};

[@bs.deriving abstract]
type logo= {. description: string, file: file, title: string };

[@bs.deriving abstract]
type node = {. projectTItle: string, logo: logo, blurb: blurb 
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
  Js.log(edges);
  <div className = (Styles.projectWrapper ++ " projectWrapper") >        (
	ReasonReact.array(
	  Array.mapi(
		 (index , edge) =>
			<Projects data=edge##node index = index/>,
		edges,
	  ),
	)
  )</div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~data=jsProps##data, [||])
  );