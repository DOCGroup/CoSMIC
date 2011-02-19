// -*- C++ -*-

//=============================================================================
/**
 * @file        Deployment_Plan_Generator_Impl.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_IDL_TEXT_EDITOR_IMPL_H_
#define _PICML_IDL_TEXT_EDITOR_IMPL_H_

#include "game/mga/be/Interpreter_Impl_Base.h"

/**
 * @class IDLTextEditor_Impl
 *
 * Implementation of the IDLTextEditor component.
 */
class IDLTextEditor_Impl :
  public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  IDLTextEditor_Impl (void);

  /// Destructor.
  virtual ~IDLTextEditor_Impl (void);

  // Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in fco,
                 std::vector <GAME::Mga::FCO> & selected,
                 long flags);
};

#endif
