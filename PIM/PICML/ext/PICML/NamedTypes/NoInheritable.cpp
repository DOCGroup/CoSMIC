// $Id$

#include "StdAfx.h"
#include "NoInheritable.h"

#if !defined (__GAME_INLINE__)
#include "NoInheritable.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string NoInheritable_Impl::metaname ("NoInheritable");

  //
  // parent_HasOperations
  //
  HasOperations NoInheritable_Impl::parent_HasOperations (void)
  {
    return HasOperations::_narrow (this->parent ());
  }
}

