// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "ExternalDelegate_Event_Handler.h"

namespace PICML
{
namespace MI
{

//
// ExternalDelegate_Create_Event_Handler
//
ExternalDelegate_Create_Event_Handler::ExternalDelegate_Create_Event_Handler (void)
: GAME::Event_Handler_Impl (OBJEVENT_CREATED)
{

}

//
// ~ExternalDelegate_Create_Event_Handler
//
ExternalDelegate_Create_Event_Handler::~ExternalDelegate_Create_Event_Handler (void)
{

}

//
// handle_object_created
//
int ExternalDelegate_Create_Event_Handler::
handle_object_created (GAME::Object obj)
{
  // Extract the connection for the FCO.
  GAME::Connection ext_conn = GAME::Connection::_narrow (obj);
  GAME::ConnectionPoints points;

  if (ext_conn.connection_points (points))
  {
    // Get the connection points.
    GAME::ConnectionPoint ext_src = points["src"];
    GAME::ConnectionPoint ext_dst = points["dst"];

    // Get the destination port type (i.e., the target delegation port).
    GAME::Reference dst_port = GAME::Reference::_narrow (ext_dst.target ());
    GAME::Atom src_port = GAME::Atom::_narrow (ext_src.target ());

    // Update the name of the external reference.
    if (src_port.name () != dst_port.name ())
      src_port.name (dst_port.name ());
  }

  return 0;
}

}
}