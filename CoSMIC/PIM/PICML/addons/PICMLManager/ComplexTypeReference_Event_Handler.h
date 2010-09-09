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

#include "game/GAME.h"
#include "game/be/Event_Handler_Impl.h"

namespace PICML
{
namespace MI
{

/**
 * @class ComplexTypeReference_Relation_Event_Handler
 *
 * This class creates a ComplexTypeReference and the related references.
 */
class ComplexTypeReference_Relation_Event_Handler :
  public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  ComplexTypeReference_Relation_Event_Handler (void);

  /// Destructor.
  virtual ~ComplexTypeReference_Relation_Event_Handler (void);

  virtual int handle_object_relation (GAME::Object obj);

  void create_DataValue (GAME::Model & container, const GAME::FCO & member);
};

}
}

#endif