'use strict';

var React = require("react");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Header");

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
              return React.createElement("span", undefined, React.createElement("img", {
                              style: {
                                height: "20em"
                              },
                              alt: data.contentfulAbout.portrait.description,
                              src: data.contentfulAbout.portrait.file.url + "?fl=progressive&q=50"
                            }), React.createElement("h1", undefined, data.contentfulAbout.name));
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
