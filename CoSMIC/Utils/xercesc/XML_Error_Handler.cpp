// $Id$

#include "XML_Error_Handler.h"
#include "ace/Log_Msg.h"
#include <xercesc/dom/DOMLocator.hpp>
#include "XercesString.h"

namespace Utils
{
//
// XML_Error_Handler
//
XML_Error_Handler::XML_Error_Handler (void)
: errors_ (false)
{

}

//
// ~XML_Error_Handler
//
XML_Error_Handler::~XML_Error_Handler (void)
{

}

//
// handleError
//
bool XML_Error_Handler::handleError (const xercesc::DOMError& domError)
{
  static const char * severity [] = {"", "warning", "error", "fatal error"};

  if (this->errors_ != true)
    this->errors_ = true;

  XStr error_msg (domError.getMessage (), false);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("%s at line %d and column %d\n"),
              error_msg.to_string ().c_str (),
              domError.getLocation ()->getLineNumber (),
              domError.getLocation ()->getColumnNumber ()));

  return true;
}

//
// resetErrors
//
void XML_Error_Handler::resetErrors (void)
{
  this->errors_ = false;
}

//
// getErrors
//
bool XML_Error_Handler::getErrors (void) const
{
  return this->errors_;
}

}
