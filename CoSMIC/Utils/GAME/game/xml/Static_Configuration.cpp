// $Id$

#include "Static_Configuration.h"
#include "xercesc/util/PlatformUtils.hpp"

namespace GAME
{
namespace Xml
{
//
// Static_Configuration
//
Static_Configuration::Static_Configuration (void)
{
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
                                &this->allocator_);
}

//
// ~Static_Configuration
//
Static_Configuration::~Static_Configuration (void)
{
  ::xercesc::XMLPlatformUtils::Terminate ();
}

//
// memory_manager
//
::xercesc::MemoryManager * Static_Configuration::memory_manager (void)
{
  return &this->allocator_;
}

}
}
