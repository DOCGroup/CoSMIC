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

#ifndef _DEPLOYMENT_PLAN_GENERATOR_IMPL_H_
#define _DEPLOYMENT_PLAN_GENERATOR_IMPL_H_

#include "game/be/Interpreter_Impl_Base.h"
#include "Configuration.h"

/**
 * @class Deployment_Plan_Generator_Impl
 *
 * Implemenation of the Quotas specification interpreter.
 */
class Deployment_Plan_Generator_Impl :
  public GAME::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  Deployment_Plan_Generator_Impl (void);

  /// Destructor.
  virtual ~Deployment_Plan_Generator_Impl (void);

  // Handle the InvokeEx callback.
  int invoke_ex (GAME::Project & project,
                 GAME::FCO & fco,
                 std::vector <GAME::FCO> & selected,
                 long flags);

  int set_parameter (const std::string & name, const std::string & value);

private:
  /// Configuration for the deployment plan generator.
  Configuration config_;
};

#endif
