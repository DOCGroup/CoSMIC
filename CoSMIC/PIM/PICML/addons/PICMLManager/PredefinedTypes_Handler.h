// -*- C++ -*-

///=============================================================================
/**
 * @file      PredefinedTypes_Handler.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_PREDEFINEDTYPES_HANDLER_H_
#define _PICML_MI_PREDEFINEDTYPES_HANDLER_H_

#include "game/mga/component/Event_Handler_Impl.h"
#include "game/mga/Object.h"

namespace PICML
{
namespace MI
{

/**
 * @class PredefinedTypes_Handler
 *
 * Implemenation of the event handler for dealing with ami4ccm. This
 * event handler will auto-generate the necessary artifact so that
 * moders can correctly leverage ami4ccm support in CoSMIC.
 */
class PredefinedTypes_Handler : public GAME::Mga::Event_Handler_Impl
{
public:
  /// Default constructor
  PredefinedTypes_Handler (void);

  /// Destructor.
  virtual ~PredefinedTypes_Handler (void);

  /// Handle the project open event.
  virtual int handle_object_created (GAME::Mga::Object_in);
};

}
}

#endif  // !defined _PICML_MANAGER_DEFAULT_IMPLEMENTATION_GENERATOR_H_
