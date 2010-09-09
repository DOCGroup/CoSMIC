// -*- C++ -*-

//=============================================================================
/**
 *  @file       AttributeValue_Event_Handler.h
 *
 *  $Id: AttributeValue_Event_Handler.h 2482 2010-09-08 04:26:38Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_ATTRIBUTE_VALUE_EVENT_HANDLER_H_
#define _PICML_MI_ATTRIBUTE_VALUE_EVENT_HANDLER_H_

#include "Event_Handler_Base.h"

namespace PICML
{
namespace MI
{

/**
 * @class AttributeValue_Event_Handler
 *
 * This class creates a AttributeValue for the desired object.
 */
class AttributeValue_Event_Handler :
  public PICML::MI::Event_Handler_Base
{
public:
  /// Default constructor.
  AttributeValue_Event_Handler (void);

  /// Destructor.
  virtual ~AttributeValue_Event_Handler (void);

  virtual int handle_object_created (GAME::Object obj);
};

}
}

#endif