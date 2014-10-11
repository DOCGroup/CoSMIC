// -*- C++ -*-

//=============================================================================
/**
 * @file       Domain_Component_Impl.h
 *
 * $Id$
 *
 * @author     Tanumoy Pati
 */
//=============================================================================

#ifndef _DOMAIN_COMPONENT_IMPL_H_
#define _DOMAIN_COMPONENT_IMPL_H_

#include "game/mga/component/Interpreter_Impl_Base.h"



class Domain_Component_Impl :
 public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  Domain_Component_Impl (void);

  /// Destructor.
  virtual ~Domain_Component_Impl (void);

  /// Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in focus,
                 std::vector <GAME::Mga::FCO> & selected,
                 long flags);
};

#endif