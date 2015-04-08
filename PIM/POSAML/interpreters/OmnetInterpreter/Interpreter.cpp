#include "stdafx.h"
#include "Interpreter.h"
#include "Patterns.h"
#include "BON2Component.h"

Pattern::~Pattern ()
{

}


Pattern_Factory::Pattern_Factory (const BON::Project &project)
: project_(project)
{
}

Pattern *Pattern_Factory::get_pattern (const BON::Model &model)
{
  if (model->getObjectMeta ().name () == "Reactor_Pattern")
  	return new Reactor (project_, model);
  else
	return NULL;
}
