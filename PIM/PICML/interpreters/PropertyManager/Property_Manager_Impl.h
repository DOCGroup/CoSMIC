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

#include "game/mga/component/Interpreter_Impl_Base.h"
#include "game/mga/FCO.h"

/**
 * @class PICML_Property_Mangaer_Impl
 */
class PICML_Property_Mangaer_Impl :
  public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  PICML_Property_Mangaer_Impl (void);

  /// Destructor.
  virtual ~PICML_Property_Mangaer_Impl (void);

  // Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in fco,
                 GAME::Mga::Collection_T <GAME::Mga::FCO> & selected,
                 long flags);
};

#endif  // !defined _PROPERTY_MANAGER_IMPL_H_
