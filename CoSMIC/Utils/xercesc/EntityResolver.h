/* -*- c++ -*- */
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
#include "ace/SString.h"
#include "Xerces_Utils_export.h"

namespace Utils
{
/**
 * @class EntityResolver
 */
class COSMIC_XERCES_UTILS_Export EntityResolver :
  public virtual xercesc::EntityResolver
{
public:
  /// Guaranteed to be a non-empty path - check is made before
  /// constructor is called.
  EntityResolver (const char *path);

  /// This function is called by the Xerces infrastructure to
  /// actually resolve the location of a schema.
  virtual xercesc::InputSource * resolveEntity (const XMLCh *const publicId,
                                                const XMLCh *const systemId);

private:
  /// Base path for resolving entities.
  ACE_CString base_path_;
};

}

#endif /* ENTITYRESOLVER_H */

