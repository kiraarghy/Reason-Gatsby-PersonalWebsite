'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Footer");

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
              return React.createElement("div", undefined, React.createElement("p", undefined, "Built using: "), $$Array.map((function (builtWith) {
                                return React.createElement("img", {
                                            key: builtWith.title,
                                            style: {
                                              height: "4em"
                                            },
                                            alt: builtWith.title,
                                            src: builtWith.file.url
                                          });
                              }), data.contentfulAbout.builtUsing));
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
exports.make = make;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* component Not a pure module */
