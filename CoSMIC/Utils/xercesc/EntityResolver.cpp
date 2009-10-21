// $Id$

#include "EntityResolver.h"
#include "XercesString.h"
#include <xercesc/framework/LocalFileInputSource.hpp>
#include <xercesc/framework/Wrapper4InputSource.hpp>

namespace Utils
{
EntityResolver::EntityResolver (const char *path)
: base_path_ (path)
{

}

/// This function is called by the Xerces infrastructure to
/// actually resolve the location of a schema.
xercesc::InputSource *
EntityResolver::resolveEntity (const XMLCh *const /* publicId */,
                               const XMLCh *const systemId)
{
  ACE_CString path_str (this->base_path_);
  const char *tmp = xercesc::XMLString::transcode (systemId);
  path_str += tmp;

  Utils::XStr path (path_str.c_str ());

  // Ownership of these objects is taken care of.
  return new xercesc::LocalFileInputSource (path);
}
}
