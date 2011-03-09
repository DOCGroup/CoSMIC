// -*- C++ -*-

//=============================================================================
/**
 *  @file       ComplexTypeReference_Event_Handler.h
 *
 *  $Id: ComplexTypeReference_Event_Handler.h 2482 2010-09-08 04:26:38Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_COMPLEX_TYPE_REFERENCE_EVENT_HANDLER_H_
#define _PICML_MI_COMPLEX_TYPE_REFERENCE_EVENT_HANDLER_H_

#include "game/mga/component/Event_Handler_Impl.h"

namespace PICML
{
namespace MI
{

/**
 * @class ComplexTypeReference_Event_Handler
 *
 * This class creates a ComplexTypeReference and the related references.
 */
class ComplexTypeReference_Event_Handler :
  public GAME::Mga::Event_Handler_Impl
{
public:
  /// Default constructor.
  ComplexTypeReference_Event_Handler (void);

  /// Destructor.
  virtual ~ComplexTypeReference_Event_Handler (void);

  virtual int handle_object_relation (GAME::Mga::Object_in obj);

  void create_DataValue (GAME::Mga::Model_in container,
                         const GAME::Mga::FCO_in member);
};

}
}

#endif