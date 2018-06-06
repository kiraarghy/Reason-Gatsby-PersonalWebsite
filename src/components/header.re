let component = ReasonReact.statelessComponent("Header");

[@bs.deriving abstract]
type file = {url: string};

[@bs.deriving abstract]
type portrait ={. description: string, file: file};

[@bs.deriving abstract]
type contentfulAbout = {. name:string, portrait: portrait};

[@bs.deriving abstract]
type data = {. contentfulAbout:contentfulAbout};

[@bs.deriving abstract]
type jsProps = {. data:data};

let make = (~data, _children) => {
  ...component,
  render: _self => <span>
  <img style=(ReactDOMRe.Style.make(~height="20em", ())) alt = {data##contentfulAbout##portrait##description}src={ data##contentfulAbout##portrait##file##url ++ "?fl=progressive&q=50"}/>
<h1> (ReasonReact.string(data##contentfulAbout##name)) </h1>  
</span>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(
	  ~data = jsProps##data,[||],
));