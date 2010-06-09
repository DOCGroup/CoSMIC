// $Id$

#include "EntityResolver.h"
#include <xercesc/framework/LocalFileInputSource.hpp>
#include <xercesc/framework/Wrapper4InputSource.hpp>

namespace Utils
{
//
// EntityResolver
//
EntityResolver::EntityResolver (const char * path)
: base_path_ (path)
{

}

//
// EntityResolver
//
EntityResolver::EntityResolver (const ::Utils::XStr & path)
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

/////

//
// EntityResolver
//
DOM_Entity_Resolver::DOM_Entity_Resolver (const char * path)
: base_path_ (path)
{

}

//
// EntityResolver
//
DOM_Entity_Resolver::DOM_Entity_Resolver (const ::Utils::XStr & path)
: base_path_ (path)
{

}

//
// resolveEntity
//
xercesc::DOMLSInput *
DOM_Entity_Resolver::
resolveResource (const XMLCh * const resourceType,
                 const XMLCh * const namespaceUri,
                 const XMLCh * const publicId,
                 const XMLCh * const systemId,
                 const XMLCh * const baseURI)
{
  using xercesc::Wrapper4InputSource;
  using xercesc::LocalFileInputSource;

  return new Wrapper4InputSource (new LocalFileInputSource (this->base_path_, systemId));
}

}
