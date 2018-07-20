let component = ReasonReact.statelessComponent("Projects");

module Styles = {
  open Css;
  let project =
    style([
      backgroundColor(`hex("e6b6c5")),
      marginBottom(`percent(10.0)),
      borderRadius(`px(5)),
      border(`px(2), `dashed, `hex("2b2e88")),
      cursor(`pointer),
      textDecoration(`none),
      hover([textDecoration(`underline)]),
      color(`hex("000000")),
    ]);

  let icon =
    style([
      height(`px(60)),
      marginTop(`px(-9)),
      marginLeft(`px(-9)),
      backgroundColor(`hex("ffffff")),
      padding(`px(3)),
      maxWidth(`px(140)),
      borderRadius(`px(5)),
      position(`absolute),
      boxShadow(
        ~x=`px(4),
        ~y=`px(4),
        ~blur=`px(7),
        ~spread=`px(-1),
        ~inset=false,
        `hex("000000"),
      ),
    ]);

  let header = style([paddingTop(`px(45)), marginLeft(`percent(3.0))]);
  let content = style([margin(`percent(3.0))]);
};

let make = (~data, _children) => {
  ...component,
  render: _self =>
    <a className=Styles.project href=data##url target="_blank">
      <img
        className=Styles.icon
        src=data##logo##file##url
        alt=data##logo##title
      />
      <h1 className=Styles.header>
        (ReasonReact.string(data##projectTItle))
      </h1>
      <p className=Styles.content>
        (
          ReasonReact.array(
            Array.mapi(
              (i, item) =>
                if (i === 0) {
                  <h3 key=(string_of_int(i))>
                    (ReasonReact.string(item))
                  </h3>;
                } else {
                  <p key=(string_of_int(i))> (ReasonReact.string(item)) </p>;
                },
              Js.String.split("\\n", data##blurb##blurb),
            ),
          )
        )
      </p>
    </a>,
};