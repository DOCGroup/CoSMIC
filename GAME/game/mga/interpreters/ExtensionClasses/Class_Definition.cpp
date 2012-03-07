// $Id$

#include "StdAfx.h"
#include "Class_Definition.h"

#include "Atom_Class_Definition.h"
#include "Connection_Class_Definition.h"
#include "Folder_Class_Definition.h"
#include "Model_Class_Definition.h"
#include "Reference_Class_Definition.h"
#include "Set_Class_Definition.h"

//
// _create
//
Class_Definition * Class_Definition::_create (GAME::Mga::FCO_in fco)
{
  const std::string metaname = fco->meta ()->name ();

  if (metaname == "Atom")
    return new Atom_Class_Definition ();
  else if (metaname == "Connection")
    return new Connection_Class_Definition ();
  else if (metaname == "FCO")
    return new FCO_Class_Definition ();
  else if (metaname == "Folder")
    return new Folder_Class_Definition ();
  else if (metaname == "Model")
    return new Model_Class_Definition ();
  else if (metaname == "Reference")
    return new Reference_Class_Definition ();
  else if (metaname == "Set")
    return new Set_Class_Definition ();
  else
    return 0;
}

//
// ~Class_Definition
//
Class_Definition::~Class_Definition (void)
{

}
