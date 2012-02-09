// -*- C++ -*-

//=============================================================================
/**
 * @file          Expr_Command.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _MODEL_INTELLIGENCE_EXPR_COMMAND_H_
#define _MODEL_INTELLIGENCE_EXPR_COMMAND_H_

/**
 * @class Expr_Command
 * Base class for all operations to be performed 
 */
class Expr_Command
{
public:
  /// Default Constructor
  Expr_Command (void);

  /// Destructor
  ~Expr_Command (void);

  /**
   * Declaring a pure virtual method execute
   */
  virtual bool execute (void) = 0;
};

#endif
