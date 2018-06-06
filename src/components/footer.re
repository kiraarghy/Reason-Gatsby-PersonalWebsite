let component = ReasonReact.statelessComponent("Footer");

[@bs.deriving abstract]
type file = {url: string};

[@bs.deriving abstract]
type contentfulAbout = {. name:string, portrait: Header.portrait, builtUsing: array({. title:string, file:file})};

[@bs.deriving abstract]
type data = {. contentfulAbout:contentfulAbout};

[@bs.deriving abstract]
type jsProps = {. data:data};

let make = (~data, _children) => {
  ...component,
  render: _self => <div>
  <p> (ReasonReact.string("Built using: ")) </p> 
  (
	ReasonReact.array(Array.map((builtWith) => <img style=(ReactDOMRe.Style.make(~height="4em", ())) key={builtWith##title} alt={builtWith##title} src={builtWith##file##url} />, data##contentfulAbout##builtUsing)
	)
  )
</div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(
	  ~data = jsProps##data,[||],
));