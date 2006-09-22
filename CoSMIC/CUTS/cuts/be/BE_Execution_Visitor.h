// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Execution_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_EXECUTION_VISITOR_H_
#define _CUTS_BE_EXECUTION_VISITOR_H_

#include "BE_File_Generator_Set.h"
#include "PICML/PICML.h"
#include <stack>

//=============================================================================
/**
 * @class CUTS_BE_Execution_Visitor
 *
 * Visitor responsible for parsing the execution paths. It signals
 * the generators when to write the appropriate information.
 */
//=============================================================================

class CUTS_BE_Execution_Visitor : public PICML::Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       generators      Reference to target generators.
   */
  CUTS_BE_Execution_Visitor (const CUTS_BE_File_Generator_Set & generators);

  /// Destructor.
  virtual ~CUTS_BE_Execution_Visitor (void);

protected:
  /// Visit an Input element.
  void Visit_Input (const PICML::Input &);

  /// Visit an InputAction element.
  void Visit_InputAction (const PICML::InputAction &);

  /// Visit an Effect element.
  void Visit_Effect (const PICML::Effect &);

  /// Visit a State element.
  void Visit_State (const PICML::State &);

  /// Visit a Transition element.
  void Visit_Transition (const PICML::Transition &);

  /// Visit a Property element.
  void Visit_Property (const PICML::Property &);

  /// Visit an Action element.
  void Visit_Action (const PICML::Action &);

  /// Visit an OutputAction element.
  void Visit_OutputAction (const PICML::OutputAction &);

  /// Visit a CompositeAction element.
  void Visit_CompositeAction (const PICML::CompositeAction &);

private:
  /// Collection of file generators.
  const CUTS_BE_File_Generator_Set & generators_;

  /// Flag that determines if effects should be ignored.
  bool ignore_effects_;

  /// Current depth of the flow control.
  int depth_;

  /// Type definition for a ordered collection of return states
  typedef std::stack <PICML::State> Holding_State;

  /// Collection of ordered return states.
  Holding_State holding_state_;

  // prevent the following operations
  CUTS_BE_Execution_Visitor (CUTS_BE_Execution_Visitor &);
  const CUTS_BE_Execution_Visitor & operator = (const CUTS_BE_Execution_Visitor &);
};

#endif  // !defined _CUTS_BE_EXECUTION_VISITOR_H_
