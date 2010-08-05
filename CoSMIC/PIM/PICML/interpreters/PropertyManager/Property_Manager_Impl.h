// -*- C++ -*-

//=============================================================================
/**
 * @file        Property_Manager_Impl.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PROPERTY_MANAGER_IMPL_H_
#define _PROPERTY_MANAGER_IMPL_H_

#include "game/be/Interpreter_Impl_Base.h"
#include "game/FCO.h"

/**
 * @class PICML_Property_Mangaer_Impl
 */
class PICML_Property_Mangaer_Impl :
  public GAME::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  PICML_Property_Mangaer_Impl (void);

  /// Destructor.
  virtual ~PICML_Property_Mangaer_Impl (void);

  // Handle the InvokeEx callback.
  int invoke_ex (GAME::Project & project,
                 GAME::FCO & fco,
                 std::vector <GAME::FCO> & selected,
                 long flags);

private:
  void handle_property (GAME::FCO fco);
};

#endif  // !defined _PROPERTY_MANAGER_IMPL_H_
