// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "NodeReference_Event_Handler.h"

#include "game/utils/modelgen.h"
#include "game/utils/Point.h"
#include "game/Model.h"

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED;
//
// NodeReference_Event_Handler
//
NodeReference_Event_Handler::NodeReference_Event_Handler (void)
: GAME::Event_Handler_Impl (mask)
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
handle_object_created (GAME::Object obj)
{
  if (this->is_importing_)
    return 0;

  static const char * _REGPATH_ = "PartRegs/NodeMapping/Position";

  // Get the parent model for the node reference.
  GAME::Reference node = GAME::Reference::_narrow (obj);
  GAME::Model parent = GAME::Model::_narrow (node.parent ());

  // Create a 'default' collocation group for the node reference
  GAME::Set group = GAME::Set::_create (parent, "CollocationGroup");
  group.name ("DefaultGroup");

  // Create an InstanceMapping connection between the node reference
  // and the collocation group.
  GAME::Connection mapping =
    GAME::Connection::_create (parent, "InstanceMapping", group, node);

  // Align the collocation group with its corresponding node.
  GAME::utils::Point pt;
  GAME::utils::position ("NodeMapping", node, pt);
  pt.shift (4, 128);

  GAME::utils::position ("NodeMapping", pt, group);

  return 0;
}

}
}