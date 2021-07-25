#include "msr_thApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
msr_thApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

msr_thApp::msr_thApp(InputParameters parameters) : MooseApp(parameters)
{
  msr_thApp::registerAll(_factory, _action_factory, _syntax);
}

msr_thApp::~msr_thApp() {}

void
msr_thApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"msr_thApp"});
  Registry::registerActionsTo(af, {"msr_thApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
msr_thApp::registerApps()
{
  registerApp(msr_thApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
msr_thApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  msr_thApp::registerAll(f, af, s);
}
extern "C" void
msr_thApp__registerApps()
{
  msr_thApp::registerApps();
}
