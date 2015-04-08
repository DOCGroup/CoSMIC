// -*- C++ -*-

//=============================================================================
/**
 * @file       PICML_MPCComponent_Impl.h
 *
 * @author     Tanumoy Pati
 */
//=============================================================================

#ifndef _PICML_MPCCOMPONENT_IMPL_H_
#define _PICML_MPCCOMPONENT_IMPL_H_

#include "game/mga/component/Interpreter_Impl_Base.h"



class PICML_MPCComponent_Impl :
 public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  PICML_MPCComponent_Impl (void);

  /// Destructor.
  virtual ~PICML_MPCComponent_Impl (void);

  /// Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in focus,
                 GAME::Mga::Collection_T <GAME::Mga::FCO> & selected,
                 long flags);
};

#endif