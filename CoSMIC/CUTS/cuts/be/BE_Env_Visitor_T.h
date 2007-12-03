// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Env_Visitor_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_ENV_VISITOR_H_
#define _CUTS_BE_ENV_VISITOR_H_

#include "PICML/PICML.h"
#include "BE_Generators_T.h"

//=============================================================================
/**
 * @class CUTS_BE_Env_Visitor_T
 *
 * Visitor for the environment portions of the model.
 */
//=============================================================================

template <typename IMPL_STRATEGY>
class CUTS_BE_Env_Visitor_T : public PICML::Visitor
{
public:
  /// Constructor.
  CUTS_BE_Env_Visitor_T (void);

  /// Destructor.
  virtual ~CUTS_BE_Env_Visitor_T (void);

protected:
  void Visit_Environment (
    const PICML::Environment & env);

  void Visit_MultiInput (
    const PICML::MultiInput & input);

  void Visit_InputAction (
    const PICML::InputAction & input);
};

#include "BE_Env_Visitor_T.cpp"

#endif  // !defined _CUTS_BE_ENV_VISITOR_H_
