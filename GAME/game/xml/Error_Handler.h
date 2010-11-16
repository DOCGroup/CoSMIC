// -*- C++ -*-

//=============================================================================
/**
 *  @file  Xml_Error_Handler.h
 *
 *  $Id$
 *
 *  @brief Error handler for Xerces
 *
 *  @author Bala Natarajan <bala@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef _GAME_XML_ERROR_HANDLER_H_
#define _GAME_XML_ERROR_HANDLER_H_

#include "xercesc/sax/HandlerBase.hpp"
#include "xercesc/dom/DOMErrorHandler.hpp"
#include "game/config.h"
#include "Xml_export.h"

namespace GAME
{
namespace Xml
{

/**
 * @class Xml_Error_Handler
 *
 * Implementation of the default error handler for the Xml backend
 * in Xerces-C.
 */
class GAME_XML_Export Xml_Error_Handler :
  public xercesc::HandlerBase
{
public:
  /// Default constructor.
  Xml_Error_Handler (void);

  /// Destructor.
  ~Xml_Error_Handler (void);

  /**
   * Callback for handling an error.
   *
   * @param[in]     err           DOM error object
   */
  bool handleError (const xercesc::DOMError & err);

  /// Reset the state of the error handler.
  void reset (void);

  /// Test if the object has detected any errors.
  bool has_errors (void) const;

private :
  /// Flag that determines if there are errors.
  bool has_errors_;

  // prevent the following operations
  Xml_Error_Handler (const Xml_Error_Handler&);
  Xml_Error_Handler & operator = (const Xml_Error_Handler&);
};

/**
 * @class DOM_Error_Handler
 *
 * Implementation of the default error handler for the Xml backend
 * in Xerces-C.
 */
class GAME_XML_Export DOM_Error_Handler :
  public xercesc::DOMErrorHandler
{
public:
  /// Default constructor.
  DOM_Error_Handler (void);

  /// Destructor.
  ~DOM_Error_Handler (void);

  /**
   * Callback for handling an error.
   *
   * @param[in]     err           DOM error object
   */
  bool handleError (const xercesc::DOMError& domError);

  /// Reset the error flag.
  void reset (void);

  /// Test if the object has detected any errors.
  bool has_errors (void) const;

private :
  /// Flag that determines if there are errors.
  bool has_errors_;

  // prevent the following operations
  DOM_Error_Handler (const DOM_Error_Handler&);
  DOM_Error_Handler& operator = (const DOM_Error_Handler&);
};

}
}

#if defined (__GAME_INLINE__)
#include "Error_Handler.inl"
#endif

#endif /* _COSMIC_UTILS_ERROR_ERROR_HANDLER_H_*/
