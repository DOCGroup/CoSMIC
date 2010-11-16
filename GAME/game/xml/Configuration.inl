// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Xml
{

//
// memory_manager
//
GAME_INLINE
Memory_Manager * Configuration::memory_manager (void)
{
  return this->allocator_;
}

//
// memory_manager
//
GAME_INLINE
void Configuration::memory_manager (Memory_Manager * allocator)
{
  this->allocator_ = allocator;
}

}
}
