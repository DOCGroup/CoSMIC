// - *- C++ -*-

//=============================================================================
/**
 * @file      RawComponent.h
 *
 * $Id$
 *
 * @author    Unknown
 */
//=============================================================================

#ifndef _PICML_CIDL_COMPONENT_H_
#define _PICML_CIDL_COMPONENT_H_

#include "ComponentLib.h"
#include "game/be/Interpreter_T.h"
#include "game/be/Interpreter_Impl_Base.h"

/**
 * @class CIDL_Interpreter_Impl
 *
 * Actual implementation of the interpreter.
 */
class CIDL_Interpreter_Impl :
  public GME::Interpreter_Impl_Base
{
public:
  CIDL_Interpreter_Impl (void);

  virtual ~CIDL_Interpreter_Impl (void);

  int invoke_ex (GME::Project & project,
                 GME::FCO & fco,
                 GME::Collection_T <GME::FCO> & selected,
                 long flags);

private:
  void preprocess (GME::Project & project);

  void postprocess (GME::Project & project);

  /// Output directory for the generated files.
  std::string output_;
};

GME_RAWCOMPONENT_DECL (GME::Interpreter_T, CIDL_Interpreter_Impl);

#endif  // !defined _PICML_CIDL_COMPONENT_H_
