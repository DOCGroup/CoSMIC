// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "NodeReference_Event_Handler.h"

#include "game/mga/modelgen.h"
#include "game/mga/utils/Point.h"
#include "game/mga/Connection.h"
#include "game/mga/Model.h"
#include "game/mga/Reference.h"
#include "game/mga/Set.h"

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED;
//
// NodeReference_Event_Handler
//
NodeReference_Event_Handler::NodeReference_Event_Handler (void)
: GAME::Mga::Event_Handler_Impl (mask)
{

}

//
// ~NodeReference_Event_Handler
//
NodeReference_Event_Handler::~NodeReference_Event_Handler (void)
{

}

//
// handle_object_created
//
int NodeReference_Event_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  // Get the parent model for the node reference.
  GAME::Mga::Reference node = GAME::Mga::Reference::_narrow (obj);
  GAME::Mga::Model parent = GAME::Mga::Model::_narrow (node->parent ());

  // Create a 'default' collocation group for the node reference
  GAME::Mga::Set group = GAME::Mga::Set_Impl::_create (parent, "CollocationGroup");
  group->name ("DefaultGroup");

  // Create an InstanceMapping connection between the node reference
  // and the collocation group.
  GAME::Mga::Connection mapping =
    GAME::Mga::Connection_Impl::_create (parent,
                                         "InstanceMapping",
                                         group,
                                         node);

  // Align the collocation group with its corresponding node.
  GAME::Mga::Point pt;
  GAME::Mga::get_position ("NodeMapping", node, pt);
  pt.shift (4, 128);

  GAME::Mga::set_position ("NodeMapping", pt, group);

  return 0;
}

}
}