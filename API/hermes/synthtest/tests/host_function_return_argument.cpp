/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the LICENSE
 * file in the root directory of this source tree.
 */
#include "TestFunctions.h"

namespace facebook {
namespace hermes {
namespace synthtest {

const char *hostFunctionReturnArgumentTrace() {
  return R"###(
{
  "version": 1,
  "globalObjID": 1,
  "env": {
    "mathRandomSeed": 0,
    "callsToDateNow": [],
    "callsToNewDate": [],
    "callsToDateAsFunction": []
  },
  "trace": [
    {
      "type": "CreateHostFunctionRecord",
      "time": 0,
      "objID": 10
    },
    {
      "type": "SetPropertyRecord",
      "time": 0,
      "objID": 1,
      "propName": "foo",
      "value": "object:10"
    },
    {
      "type": "BeginExecJSRecord",
      "time": 0
    },
    {
      "type": "CallToNativeRecord",
      "time": 0,
      "functionID": 10,
      "thisArg": "undefined:",
      "args": ["object:11"]
    },
    {
      "type": "ReturnFromNativeRecord",
      "time": 0,
      "retval": "object:11"
    },
    {
      "type": "EndExecJSRecord",
      "time": 0
    }
  ]
}
)###";
}

const char *hostFunctionReturnArgumentSource() {
  return R"###(
'use strict';

(function(global) {
  // Native code creates a function foo.
  // foo takes in an argument and returns it immediately.
  // It should have the same identity as the passed-in object.
  var o = {};
  if (global.foo(o) !== o) {
    throw new Error();
  }
})(this);
)###";
}

} // namespace synthtest
} // namespace hermes
} // namespace facebook