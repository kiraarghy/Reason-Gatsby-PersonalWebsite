let component = ReasonReact.statelessComponent("Footer");

module Styles = {
  open Css;

  let gridContainer =
    style([
      display(grid),
      gridGap(em(1.0)),
      paddingRight(`percent(5.0)),
      gridTemplateColumns([
        `fr(1.0),
        `fr(1.0),
        `fr(1.0),
        `fr(1.0),
        `fr(8.0),
      ]),
      justifyContent(`endGrid),
    ]);

  let gridItem = style([width(`percent(70.0))]);
};

[@bs.deriving abstract]
type file = {url: string};

[@bs.deriving abstract]
type contentfulAbout = {
  .
  name: string,
  portrait: Header.portrait,
  builtUsing:
    array({
      .
      title: string,
      file: file,
    }),
};

[@bs.deriving abstract]
type data = {. contentfulAbout: contentfulAbout};

[@bs.deriving abstract]
type jsProps = {. data: data};

let make = (~data, _children) => {
  ...component,
  render: _self =>
    <div className="footer">
      <p> (ReasonReact.string("Built using: ")) </p>
      <div className=Styles.gridContainer>
        (
          ReasonReact.array(
            Array.map(
              builtWith =>
                <div className=Styles.gridItem>
                  <img
                    key=builtWith##title
                    alt=builtWith##title
                    src=builtWith##file##url
                  />
                </div>,
              data##contentfulAbout##builtUsing,
            ),
          )
        )
      </div>
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~data=jsProps##data, [||])
  );