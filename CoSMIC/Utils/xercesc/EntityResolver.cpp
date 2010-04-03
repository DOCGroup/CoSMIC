// $Id$

#include "EntityResolver.h"
#include <xercesc/framework/LocalFileInputSource.hpp>
#include <xercesc/framework/Wrapper4InputSource.hpp>

namespace Utils
{
EntityResolver::EntityResolver (const char * path)
: base_path_ (path)
{

}

//
// resolveEntity
//
xercesc::InputSource *
EntityResolver::
resolveEntity (const XMLCh * const public_id, const XMLCh * const system_id)
{
  // Construct the full path.
  XStr path (this->base_path_);
  path.append (system_id);

  return new xercesc::LocalFileInputSource (path);

  ACE_UNUSED_ARG (public_id);
}
}
