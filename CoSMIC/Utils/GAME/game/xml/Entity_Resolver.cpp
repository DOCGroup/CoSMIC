// $Id$

#include "Entity_Resolver.h"

#if !defined (__GAME_INLINE__)
#include "Entity_Resolver.inl"
#endif

#include "xercesc/framework/LocalFileInputSource.hpp"
#include "xercesc/framework/Wrapper4InputSource.hpp"

namespace GAME
{
namespace Xml
{

///////////////////////////////////////////////////////////////////////////////
// class Entity_Resolver

//
// resolveEntity
//
xercesc::InputSource *
Entity_Resolver::
resolveEntity (const XMLCh * const public_id, const XMLCh * const system_id)
{
  // Construct the full path.
  String path (this->base_path_);
  path.append (system_id);

  return new xercesc::LocalFileInputSource (path);

  ACE_UNUSED_ARG (public_id);
}

///////////////////////////////////////////////////////////////////////////////
// class Resource_Resolver

//
// resolveEntity
//
xercesc::DOMLSInput *
Resource_Resolver::
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
}
