// -*- C++ -*-

//=============================================================================
/**
 * @file       VisitPatron_Component_Impl.h
 *
 * $Id$
 *
 * @author     Tanumoy Pati
 */
//=============================================================================

#ifndef _VISITPATRON_COMPONENT_IMPL_H_
#define _VISITPATRON_COMPONENT_IMPL_H_

#include "game/mga/component/Interpreter_Impl_Base.h"



class VisitPatron_Component_Impl :
 public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  VisitPatron_Component_Impl (void);

  /// Destructor.
  virtual ~VisitPatron_Component_Impl (void);

  /// Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in focus,
                 std::vector <GAME::Mga::FCO> & selected,
                 long flags);

private:
  
};

#endif