/* -*- C++ -*- */

//=============================================================================
/**
 * @file      PICMLManager_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_IMPL_H_
#define _PICML_MANAGER_IMPL_H_

#include <set>
#include "game/be/Event_Handler_Impl.h"
#include "game/FCO.h"
#include "game/Connection.h"
#include "game/Project.h"

#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"

#include "Event_Handler_Config.h"

namespace GAME
{
// Forward decl.
class FCO;
}

/**
 * @class PICMLManager_Impl
 *
 * Raw COM implementation of the PICML manager add-on.
 */
class PICMLManager_Impl : public GAME::Event_Handler_Impl
{
public:
  /// Constructor.
  PICMLManager_Impl (void);

  /// Destructor.
  virtual ~PICMLManager_Impl (void);

  virtual int initialize (GAME::Project & project);

  virtual int handle_global_event (long global_event);

  virtual int handle_object_event (GAME::Object & obj, unsigned long mask);

private:

  typedef
    int (PICMLManager_Impl::*_member_function)
    (unsigned long, GAME::Object &);
  

  ACE_Hash_Map_Manager <std::string,
                        _member_function,
                        ACE_Null_Mutex> handlers_;

  PICML::MI::Event_Handler_Config * config_;
};

#endif // _PICML_MANAGER_IMPL_H_
