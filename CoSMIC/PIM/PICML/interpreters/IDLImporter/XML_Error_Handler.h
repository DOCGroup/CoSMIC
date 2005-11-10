//==============================================================
/**
 *  @file  XML_Error_Handler.h
 *
 *  $Id$
 *
 *  @brief Error handler for Xerces
 *
 *  @author Bala Natarajan <bala@dre.vanderbilt.edu>
 */
//================================================================
#ifndef CIAO_CONFIG_HANLDERS_ERROR_HANDLER_H
#define CIAO_CONFIG_HANLDERS_ERROR_HANDLER_H

#include /**/ "ace/pre.h"

#include "TAO_PICML_BE_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include <xercesc/dom/DOMErrorHandler.hpp>

using xercesc::DOMErrorHandler;
using xercesc::DOMError;

/**
  * @class XML_Error_Hander
  *
  * @brief Error handler for XERCES
  *
  */
class TAO_PICML_BE_Export XML_Error_Handler
  : public DOMErrorHandler
{
public:

  XML_Error_Handler (void);

  ~XML_Error_Handler (void);

  bool handleError (const DOMError& domError);

  void resetErrors (void);

  bool getErrors(void) const;

private :
  // Disallow copying
  XML_Error_Handler (const XML_Error_Handler&);
  XML_Error_Handler& operator= (const XML_Error_Handler&);

  bool errors_;
};

#include /**/ "ace/post.h"

#endif /* CIAO_CONFIG_HANLDERS_ERROR_HANDLER_H*/