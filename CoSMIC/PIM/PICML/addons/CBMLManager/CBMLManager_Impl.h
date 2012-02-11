// -*- C++ -*-

//=============================================================================
/**
 * @file        CBML_Model_Intelligence.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CBML_MODEL_INTELLIGENCE_H_
#define _CBML_MODEL_INTELLIGENCE_H_

#include <string>
#include <set>
#include <map>

#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"
#include "ace/SString.h"

#include "game/mga/FCO.h"
#include "game/mga/component/Addon_Impl_T.h"
#include "game/mga/component/ComponentEx_T.h"
#include "game/mga/component/Event_Handler_Impl.h"

GAME_DEFAULT_ADDON_IMPL (CBML_Manager_ComponentEx_Impl,
                         "CBML Model Intelligence",
                         "PICML",
                         "MGA.AddOn.CBMLManager");

/**
 * @class CBML_Model_Intelligence
 *
 * Raw component interface for the add-on.
 */
class CBML_Model_Intelligence :
  public GAME::Mga::Static_Event_Handler_Impl
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED |
                                         OBJEVENT_SELECT |
                                         OBJEVENT_DESTROYED |
                                         OBJEVENT_RELATION;

  /// Default constructor.
  CBML_Model_Intelligence (void);

  /// Destructor.
  virtual ~CBML_Model_Intelligence (void);

  virtual int initialize (GAME::Mga::Project project);
};

#endif  // !defined RAWCOMPONENT_H
