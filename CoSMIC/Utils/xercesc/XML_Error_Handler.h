// -*- C++ -*-

//=============================================================================
/**
 *  @file  XML_Error_Handler.h
 *
 *  $Id$
 *
 *  @brief Error handler for Xerces
 *
 *  @author Bala Natarajan <bala@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef _COSMIC_UTILS_ERROR_ERROR_HANDLER_H_
#define _COSMIC_UTILS_ERROR_ERROR_HANDLER_H_

#include "xercesc/sax/HandlerBase.hpp"
#include "Xerces_Utils_export.h"

using xercesc::DOMError;

namespace Utils
{
/**
  * @class XML_Error_Hander
  *
  * @brief Error handler for XERCES
  */
class COSMIC_XERCES_UTILS_Export  XML_Error_Handler
  : public xercesc::HandlerBase
{
public:
  /// Default constructor.
  XML_Error_Handler (void);

  /// Destructor.
  ~XML_Error_Handler (void);

  bool handleError (const DOMError& domError);

  /// Reset the error flag.
  void resetErrors (void);

  bool getErrors(void) const;

private :
  /// Flag that determines if there are errors.
  bool errors_;

  // Disallow copying
  XML_Error_Handler (const XML_Error_Handler&);
  XML_Error_Handler& operator= (const XML_Error_Handler&);
};

}

#endif /* _COSMIC_UTILS_ERROR_ERROR_HANDLER_H_*/