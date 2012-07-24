// -*- C++ -*-

//=============================================================================
/**
 * @file          Add_Command.h
 *
 * $Id: Add_Command.h 2899 2012-05-01 20:01:10Z tpati $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _MODEL_INTELLIGENCE_ADD_COMMAND_H_
#define _MODEL_INTELLIGENCE_ADD_COMMAND_H_

#include "Expr_Command.h"
#include "game/mga/Model.h"
#include "game/mga/Atom.h"
#include "game/mga/Reference.h"
#include "game/mga/Set.h"
#include "MetaRole.h"
#include "MetaFCO.h"

/**
 * @class Add_Command
 *
 * Add_Command derived from Expr_Command.
 * Meant to handle the addition of objects to the model.
 */
class Add_Command : public Expr_Command
{
public:
  /// Constructor
  Add_Command (GAME::Mga::Model parent_model,
		           std::vector <GAME::Mga::Meta::Role> target_metaroles,
               double count);

  ///Destructor
  ~Add_Command (void);

  /**
   * Method handling the addition of objects
   *
   * @return       bool          True if objects are added
   *                             False if objects are not added
   */
  bool execute (void);
private:
  // Target parent model
  GAME::Mga::Model parent_model_;

  // Target meta roles
	std::vector <GAME::Mga::Meta::Role> target_metaroles_;

  // Metatype of objects to be added
  GAME::Mga::Meta::FCO target_metatype_;

  // Number of objects to be added
  double count_;
};

#endif
