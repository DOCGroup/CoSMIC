// $Id$

#include "Error_Handler.h"

#if !defined (__GAME_INLINE__)
#include "Error_Handler.inl"
#endif

#include "String.h"
#include "ace/Log_Msg.h"
#include "xercesc/dom/DOMLocator.hpp"

namespace GAME
{
namespace Xml
{

//
// handleError
//
bool Xml_Error_Handler::handleError (const xercesc::DOMError & domError)
{
  static const char * severity [] = {"", "warning", "error", "fatal error"};

  if (!this->has_errors_)
    this->has_errors_ = true;

  String error_msg (domError.getMessage (), false);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("%s at line %d and column %d\n"),
              error_msg.to_string ().c_str (),
              domError.getLocation ()->getLineNumber (),
              domError.getLocation ()->getColumnNumber ()));

  return true;
}

//
// handleError
//
bool DOM_Error_Handler::handleError (const xercesc::DOMError& domError)
{
  static const char * severity [] = {"", "warning", "error", "fatal error"};

  if (!this->has_errors_)
    this->has_errors_ = true;

  String error_msg (domError.getMessage (), false);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("%s at line %d and column %d\n"),
              error_msg.to_string ().c_str (),
              domError.getLocation ()->getLineNumber (),
              domError.getLocation ()->getColumnNumber ()));

  return true;
}

}
}
