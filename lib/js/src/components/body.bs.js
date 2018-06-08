'use strict';

var Css = require("bs-css/lib/js/src/Css.js");
var React = require("react");
var Content = require("./content.bs.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Header");

var picture = Css.style(/* :: */[
      Css.width(/* `percent */[
            -119887163,
            30.0
          ]),
      /* :: */[
        Css.border(Css.px(3), Css.solid, Css.hex("E27D60")),
        /* :: */[
          Css.borderRadius(Css.px(400)),
          /* :: */[
            Css.marginTop(Css.em(3.0)),
            /* :: */[
              Css.marginLeft(Css.em(3.0)),
              /* [] */0
            ]
          ]
        ]
      ]
    ]);

var text = Css.style(/* :: */[
      Css.fontFamily("Lato"),
      /* :: */[
        Css.zIndex(2),
        /* :: */[
          Css.position(Css.fixed),
          /* :: */[
            Css.color(Css.hex("FFFFFF")),
            /* [] */0
          ]
        ]
      ]
    ]);

var Styles = /* module */[
  /* picture */picture,
  /* text */text
];

function make(data, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", undefined, React.createElement("h1", {
                              className: text
                            }, data.contentfulAbout.name), React.createElement("img", {
                              className: picture,
                              alt: data.contentfulAbout.portrait.description,
                              src: data.contentfulAbout.portrait.file.url + "?w=300&h=300"
                            }), ReasonReact.element(/* None */0, /* None */0, Content.make(data.contentfulAbout.markdown, /* array */[])));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

var $$default = ReasonReact.wrapReasonForJs(component, (function (jsProps) {
        return make(jsProps.data, /* array */[]);
      }));

exports.component = component;
exports.Styles = Styles;
exports.make = make;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* component Not a pure module */
