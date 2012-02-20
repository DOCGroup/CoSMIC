// -*- C++ -*-

//=============================================================================
/**
 * @file       DQML_iCCM_Component_Impl.h
 *
 * $Id$
 *
 * @author     James H. Hill
 */
//=============================================================================

#ifndef _DQML_ICCM_COMPONENT_IMPL_H_
#define _DQML_ICCM_COMPONENT_IMPL_H_

#include "game/mga/component/Interpreter_Impl_Base.h"



class DQML_iCCM_Component_Impl :
 public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  DQML_iCCM_Component_Impl (void);

  /// Destructor.
  virtual ~DQML_iCCM_Component_Impl (void);

  /// Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in focus,
                 std::vector <GAME::Mga::FCO> & selected,
                 long flags);
};

#endif