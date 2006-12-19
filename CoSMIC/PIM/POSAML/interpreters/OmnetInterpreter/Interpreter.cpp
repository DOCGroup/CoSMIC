#ifndef _INTERPRETER_CPP_
#define _INTERPRETER_CPP_

#include "stdafx.h"
#include "Interpreter.h"
#include "Patterns.h"
#include "BON2Component.h"

/*
template <typename T> 
Pattern<T>::Pattern (const BON::Project &project)
: pattern_ (new T (project))
{
}

template <typename T>
int Pattern<T>::create_init_file ()
{
  this->pattern_->create_init_file ();
  return 0;
}

template <typename T>
Pattern<T>::~Pattern ()
{
  delete this->pattern_;
}*/


Pattern_Factory::Pattern_Factory (const BON::Project &project)
: project_(project)
{
}

//template <typename T>
//Pattern<T> *Pattern_Factory::get_pattern (const BON::Model &model)
Pattern *Pattern_Factory::get_pattern (const BON::Model &model)
{
  if (model->getObjectMeta ().name () == "Reactor_Pattern")
  {
	//return new Pattern<Reactor> (project_);
	return new Reactor (project_, model);
  }
  else 
	return NULL;
}

#endif;