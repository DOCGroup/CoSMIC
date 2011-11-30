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
#include "game/mga/component/Event_Handler_Impl.h"

GAME_DEFAULT_ADDON_IMPL (Model_Intelligence_ComponentEx_Impl,
                         "Library Model Intelligence",
                         "Library_System",
                         "MGA.AddOn.Model_Intelligence");

/**
 * @class Library_Model_Intelligence
 *
 * Raw component interface for the add-on.
 */
class Library_Model_Intelligence : public GAME::Mga::Event_Handler_Impl
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED |
                                         OBJEVENT_SELECT |
                                         OBJEVENT_DESTROYED |
                                         OBJEVENT_RELATION;

  /// Default constructor.
  Library_Model_Intelligence (void);

  /// Destructor.
  virtual ~Library_Model_Intelligence (void);

  virtual int initialize (GAME::Mga::Project project);
};

#endif