// -*- C++ -*-

//=============================================================================
/**
 * @file       PICML_TO_DQML_Component_Impl.h
 *
 * @author     Tanumoy Pati
 */
//=============================================================================

#ifndef _PICML_TO_DQML_COMPONENT_IMPL_H_
#define _PICML_TO_DQML_COMPONENT_IMPL_H_

#include "game/mga/component/Interpreter_Impl_Base.h"



class PICML_TO_DQML_Component_Impl :
 public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  PICML_TO_DQML_Component_Impl (void);

  /// Destructor.
  virtual ~PICML_TO_DQML_Component_Impl (void);

  /// Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in focus,
                 GAME::Mga::Collection_T <GAME::Mga::FCO> & selected,
                 long flags);
};

#endif