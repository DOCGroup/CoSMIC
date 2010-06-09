/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO_IFR_BE_DLL
//
// = FILENAME
//    EntityResolver.h
//
// = DESCRIPTION
//    Header file for class deriving from DOMEntityResolver
//
// = AUTHOR
//    Jeff Parsons <j.parsons@vanderbilt.edu>
//
// ============================================================================

#ifndef ENTITYRESOLVER_H
#define ENTITYRESOLVER_H

#include "xercesc/sax/EntityResolver.hpp"
#include "xercesc/dom/DOMLSResourceResolver.hpp"
#include "XercesString.h"

namespace Utils
{
/**
 * @class EntityResolver
 */
class COSMIC_XERCES_UTILS_Export EntityResolver :
  public xercesc::EntityResolver
{
public:
  /// Guaranteed to be a non-empty path - check is made before
  /// constructor is called.
  EntityResolver (const char *path);

  EntityResolver (const ::Utils::XStr & path);

  /// This function is called by the Xerces infrastructure to
  /// actually resolve the location of a schema.
  virtual xercesc::InputSource * resolveEntity (const XMLCh *const publicId,
                                                const XMLCh *const systemId);

private:
  /// Base path for resolving entities.
  const XStr base_path_;
};

/**
 * @class DOM_Entity_Resolver
 */
class COSMIC_XERCES_UTILS_Export DOM_Entity_Resolver :
  public xercesc::DOMLSResourceResolver
{
public:
  /// Guaranteed to be a non-empty path - check is made before
  /// constructor is called.
  DOM_Entity_Resolver (const char *path);

  DOM_Entity_Resolver (const ::Utils::XStr & path);

  xercesc::DOMLSInput * resolveResource (const XMLCh * const resourceType,
                                         const XMLCh * const namespaceUri,
 		                                     const XMLCh * const publicId,
 		                                     const XMLCh * const systemId,
		                                     const XMLCh * const baseURI); 

private:
  /// Base path for resolving entities.
  const XStr base_path_;
};

}

#endif /* ENTITYRESOLVER_H */

