'use strict';

var Css = require("bs-css/lib/js/src/Css.js");
var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Footer");

var gridContainer = Css.style(/* :: */[
      Css.display(Css.inlineGrid),
      /* :: */[
        Css.gridGap(Css.em(1.0)),
        /* :: */[
          Css.paddingLeft(/* `percent */[
                -119887163,
                5.0
              ]),
          /* :: */[
            Css.gridTemplateColumns(/* :: */[
                  Css.auto,
                  /* :: */[
                    Css.auto,
                    /* :: */[
                      Css.auto,
                      /* :: */[
                        Css.auto,
                        /* [] */0
                      ]
                    ]
                  ]
                ]),
            /* :: */[
              Css.width(/* `percent */[
                    -119887163,
                    40.0
                  ]),
              /* [] */0
            ]
          ]
        ]
      ]
    ]);

var gridItem = Css.style(/* :: */[
      Css.width(Css.em(2.0)),
      /* [] */0
    ]);

var Styles = /* module */[
  /* gridContainer */gridContainer,
  /* gridItem */gridItem
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
              return React.createElement("div", undefined, React.createElement("p", undefined, "Built using: "), React.createElement("div", {
                              className: gridContainer
                            }, $$Array.map((function (builtWith) {
                                    return React.createElement("div", {
                                                className: gridItem
                                              }, React.createElement("img", {
                                                    key: builtWith.title,
                                                    alt: builtWith.title,
                                                    src: builtWith.file.url
                                                  }));
                                  }), data.contentfulAbout.builtUsing)));
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
