// -*- C++ -*-

//=============================================================================
/**
 * @file        Visitor_Test_Impl.h
 *
 * $Id$
 *
 * @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _VISITOR_TEST_COMPONENT_IMPL_H_
#define _VISITOR_TEST_COMPONENT_IMPL_H_

#include "game/mga/component/Interpreter_Impl_Base.h"

/**
 * @class Visitor_Test_Impl
 */
class Visitor_Test_Impl :
  public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  Visitor_Test_Impl (void);

  /// Destructor.
  virtual ~Visitor_Test_Impl (void);

  // Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in focus,
                 std::vector <GAME::Mga::FCO> & selected,
                 long flags);

  int set_parameter (const std::string & name, const std::string & value);
};

#endif
