//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "msr_thTestApp.h"
#include "msr_thApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
msr_thTestApp::validParams()
{
  InputParameters params = msr_thApp::validParams();
  return params;
}

msr_thTestApp::msr_thTestApp(InputParameters parameters) : MooseApp(parameters)
{
  msr_thTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

msr_thTestApp::~msr_thTestApp() {}

void
msr_thTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  msr_thApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"msr_thTestApp"});
    Registry::registerActionsTo(af, {"msr_thTestApp"});
  }
}

void
msr_thTestApp::registerApps()
{
  registerApp(msr_thApp);
  registerApp(msr_thTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
msr_thTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  msr_thTestApp::registerAll(f, af, s);
}
extern "C" void
msr_thTestApp__registerApps()
{
  msr_thTestApp::registerApps();
}
