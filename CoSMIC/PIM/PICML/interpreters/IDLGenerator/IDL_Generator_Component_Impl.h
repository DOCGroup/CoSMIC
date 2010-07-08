// -*- C++ -*-

//=============================================================================
/**
 * @file        IDL_Generator_Component_Impl.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _IDL_GENERATOR_COMPONENT_IMPL_H_
#define _IDL_GENERATOR_COMPONENT_IMPL_H_

#include "game/be/Interpreter_Impl_Base.h"

/**
 * @class Quotas_Specification_Impl
 *
 * Implemenation of the Quotas specification interpreter.
 */
class IDL_Generator_Component_Impl : 
  public GAME::Interpreter_Impl_Base 
{
public:
  /// Default constructor.
  IDL_Generator_Component_Impl (void);

  /// Destructor.
  virtual ~IDL_Generator_Component_Impl (void);

  // Handle the InvokeEx callback.
  int invoke_ex (GAME::Project & project,
                 GAME::FCO & fco,
                 std::vector <GAME::FCO> & selected,
                 long flags);
};

#endif
