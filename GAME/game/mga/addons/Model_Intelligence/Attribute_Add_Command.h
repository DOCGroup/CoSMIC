// -*- C++ -*-

//=============================================================================
/**
 * @file          Attribute_Add_Command.h
 *
 * $Id:  tpati $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _MODEL_INTELLIGENCE_ATTRIBUTE_ADD_COMMAND_H_
#define _MODEL_INTELLIGENCE_ATTRIBUTE_ADD_COMMAND_H_

#include "Expr_Command.h"
#include "game/mga/Model.h"
#include "game/mga/Atom.h"
#include "game/mga/Reference.h"
#include "game/mga/Set.h"
#include "MetaFCO.h"
#include "Value.h"

/**
 * @class Attribute_Add_Command
 *
 * Attribute_Add_Command derived from Expr_Command.
 * Meant to handle the addition of attribute values to the object.
 */
class Attribute_Add_Command : public Expr_Command
{
public:
  /// Constructor
  Attribute_Add_Command (GAME::Mga::FCO fco,
                         std::string name,
                         Value * val);

  ///Destructor
  ~Attribute_Add_Command (void);

  /**
   * Method handling the addition of objects
   *
   * @return       bool          True if objects are added
   *                             False if objects are not added
   */
  bool execute (void);
private:
  // Target object
  GAME::Mga::FCO fco_;

  // Attribute name
  std::string atrname_;

  // Value of the attribute
  Value * val_;
};

#endif
