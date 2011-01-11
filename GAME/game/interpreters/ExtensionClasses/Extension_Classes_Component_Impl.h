// -*- C++ -*-

//=============================================================================
/**
 * @file        Extension_Classes_Component_Impl.h
 *
 * $Id: Extension_Classes_Component_Impl.h 2338 2010-07-08 14:29:57Z alhad $
 *
 * @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _Extension_Classes_COMPONENT_IMPL_H_
#define _Extension_Classes_COMPONENT_IMPL_H_

#include "game/be/Interpreter_Impl_Base.h"

/**
 * @class Quotas_Specification_Impl
 *
 * Implemenation of the Quotas specification interpreter.
 */
class Extension_Classes_Component_Impl :
  public GAME::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  Extension_Classes_Component_Impl (void);

  /// Destructor.
  virtual ~Extension_Classes_Component_Impl (void);

  // Handle the InvokeEx callback.
  int invoke_ex (GAME::Project project,
                 GAME::FCO_in focus,
                 std::vector <GAME::FCO> & selected,
                 long flags);

  int set_parameter (const std::string & name, const std::string & value);

private:
  /// The target location for the generation.
  std::string output_;
};

#endif
