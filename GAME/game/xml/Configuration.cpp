// $Id$

#include "Configuration.h"

#if !defined (__GAME_INLINE__)
#include "Configuration.inl"
#endif

#include "Memory_Manager.h"
#include "xercesc/util/PlatformUtils.hpp"

namespace GAME
{
namespace Xml
{
//
// global_allocator_
//
Memory_Manager Configuration::global_allocator_;

//
// Configuration
//
Configuration::Configuration (Memory_Manager * allocator)
: allocator_ (allocator)
{
  if (0 == this->allocator_)
    this->allocator_ = &this->global_allocator_;

  using ::xercesc::XMLPlatformUtils;
  using ::xercesc::XMLUni;

  // When initializing, we need to provide our own memory manager
  // since we know it will stay alive beyond Terminate (). This
  // will therefore allow the framework to have static strings,
  // which will need a memory manager that lives past Terminate ()
  // to safely release its memory.
  XMLPlatformUtils::Initialize (XMLUni::fgXercescDefaultLocale,
                                0,
                                0,
                                this->allocator_);
}

//
// ~Configuration
//
Configuration::~Configuration (void)
{
  ::xercesc::XMLPlatformUtils::Terminate ();
}



}
}
