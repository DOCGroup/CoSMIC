// -*- C++ -*-

//=============================================================================
/**
 *  @file       AttributeMember_Event_Handler.h
 *
 *  $Id: AttributeMember_Event_Handler.h 2482 2010-09-08 04:26:38Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_ATTRIBUTE_MEMBER_EVENT_HANDLER_H_
#define _PICML_MI_ATTRIBUTE_MEMBER_EVENT_HANDLER_H_

#include "Event_Handler_Base.h"
#include "game/Connection.h"

namespace PICML
{
namespace MI
{

/**
 * @class AttributeMember_Event_Handler
 *
 * This class creates a AttributeMember and the related references.
 */
class AttributeMember_Event_Handler :
  public PICML::MI::Event_Handler_Base
{
public:
  /// Default constructor.
  AttributeMember_Event_Handler (void);

  /// Destructor.
  virtual ~AttributeMember_Event_Handler (void);

  virtual int handle_object_relation (GAME::Object_in obj);

  void verify_property_datatype (GAME::ConnectionPoint & attr,
                                 const GAME::FCO_in attr_type);

  void verify_property_datatype_entry (GAME::ConnectionPoints::value_type & attr,
                                       const GAME::FCO_in attr_type);
};

}
}

#endif