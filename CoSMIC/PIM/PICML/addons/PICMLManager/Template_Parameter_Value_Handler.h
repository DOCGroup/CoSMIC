// -*- C++ -*-

//=============================================================================
/**
 *  @file       Template_Parameter_Value_Handler.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_TEMPLATE_PARAMETER_VALUE_HANDLER_H_
#define _PICML_MI_TEMPLATE_PARAMETER_VALUE_HANDLER_H_

#include "game/be/Readonly_Event_Handler.h"

namespace PICML
{
namespace MI
{

/**
 * @class NodeReference_Event_Handler
 *
 * This class creates a NodeReference for the desired object.
 */
class Template_Parameter_Value_Handler :
  public GAME::Readonly_Event_Handler
{
public:
  /// Default constructor.
  Template_Parameter_Value_Handler (void);

  /// Destructor.
  virtual ~Template_Parameter_Value_Handler (void);
};

}
}

#endif