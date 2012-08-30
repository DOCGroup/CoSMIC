//=============================================================================
/**
 * @file      Init_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_INIT_T_H_
#define _GAME_MGA_INIT_T_H_

#include "Impl_Factory.h"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Init_T
 *
 * Utility class for initializing an extension class framework. This class
 * is parameterized by an Impl_Factory object.
 */
template <typename T>
class Init_T
{
public:
  /// Type definition of the implementation factory.
  typedef ACE_Unmanaged_Singleton <T, ACE_Null_Mutex> impl_factory_type;

  Init_T (void)
  {
    ::GAME::Mga::GLOBAL_IMPL_FACTORY::instance ()->set_next (impl_factory_type::instance ());
  }

  ~Init_T (void)
  {
    ::GAME::Mga::GLOBAL_IMPL_FACTORY::instance ()->remove (impl_factory_type::instance ());
    impl_factory_type::close ();
  }
};

}
}

#endif  // !defined _GAME_MGA_INIT_T_H_
