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

#include "game/mga/component/Interpreter_Impl_Base.h"

/**
 * @class Quotas_Specification_Impl
 *
 * Implemenation of the Quotas specification interpreter.
 */
class IDL_Generator_Component_Impl :
  public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  IDL_Generator_Component_Impl (void);

  /// Destructor.
  virtual ~IDL_Generator_Component_Impl (void);

  // Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO fco,
                 GAME::Mga::Collection_T <GAME::Mga::FCO> & selected,
                 long flags);

  int set_parameter (const std::string & name, const std::string & value);

private:
  /// The target location for the generation.
  std::string output_;
};

#endif
