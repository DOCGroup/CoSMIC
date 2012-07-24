// -*- C++ -*-

//=============================================================================
/**
 * @file         Model_Intelligence.h
 *
 * $Id: Model_Intelligence_Impl.h 2907 2012-06-07 21:35:18Z tpati $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================


#ifndef _MODEL_INTELLIGENCE_IMPL_H_
#define _MODEL_INTELLIGENCE_IMPL_H_

#include <string>
#include <set>
#include <map>

#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"
#include "ace/SString.h"

#include "game/mga/FCO.h"
#include "game/mga/component/Addon_Impl_T.h"
#include "game/mga/component/ComponentEx_T.h"
#include "game/mga/component/Object_Event_Handler.h"
#include "game/mga/component/Global_Event_Handler.h"

GAME_DEFAULT_ADDON_IMPL (Model_Intelligence_Impl,
                         "GAME Model Intelligence",
                         "*",
                         "GAME.AddOn.Model_Intelligence");
namespace GAME

{
/**
 * @class Model_Intelligence
 *
 * Raw component interface for the add-on.
 */
class Model_Intelligence :
  public Mga::Top_Level_Event_Handler
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED |
                                         OBJEVENT_SELECT |
                                         OBJEVENT_DESTROYED |
                                         OBJEVENT_RELATION;

  /// Default constructor.
  Model_Intelligence (void);

  /// Destructor.
  virtual ~Model_Intelligence (void);

  virtual int initialize (Mga::Project project);
private:
  int test;
};

}

#endif