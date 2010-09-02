// -*- C++ -*-

//=============================================================================
/**
 *  @file  Xml_Error_Handler.h
 *
 *  $Id$
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef _GAME_XML_ENTITY_RESOLVER_H_
#define _GAME_XML_ENTITY_RESOLVER_H_

#include "xercesc/sax/EntityResolver.hpp"
#include "xercesc/dom/DOMLSResourceResolver.hpp"
#include "String.h"

namespace GAME
{
namespace Xml
{

/**
 * @class Entity_Resolver
 */
class GAME_XML_Export Entity_Resolver :
  public xercesc::EntityResolver
{
public:
  Entity_Resolver (const char * path);

  Entity_Resolver (const String & path);

  virtual xercesc::InputSource * resolveEntity (const XMLCh *const publicId,
                                                const XMLCh *const systemId);

private:
  /// Base path for resolving entities.
  const String base_path_;
};

/**
 * @class Resource_Resolver
 */
class GAME_XML_Export Resource_Resolver :
  public xercesc::DOMLSResourceResolver
{
public:
  /// Guaranteed to be a non-empty path - check is made before
  /// constructor is called.
  Resource_Resolver (const char *path);

  Resource_Resolver (const String & path);

  xercesc::DOMLSInput * resolveResource (const XMLCh * const resourceType,
                                         const XMLCh * const namespaceUri,
                                         const XMLCh * const publicId,
                                         const XMLCh * const systemId,
                                         const XMLCh * const baseURI);

private:
  /// Base path for resolving entities.
  const String base_path_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Entity_Resolver.inl"
#endif

#endif /* ENTITYRESOLVER_H */

