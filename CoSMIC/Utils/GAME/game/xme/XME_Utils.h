// -*- C++ -*-

//=============================================================================
/**
 * @file      XME_Base_Type.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_BASE_TYPE_H_
#define _GAME_XME_BASE_TYPE_H_

#include <string>
#include <vector>
#include "xercesc/dom/DOM.hpp"
#include "Utils/xercesc/XercesString.h"

namespace GAME
{
namespace XME
{
/**
 * @class XME_Base_Type
 *
 * Base class for all the objects in the XME backend
 */
class Utils
{
public:
  /**
   * Set the value of an element. If the element does not exist, then
   * the element is created before setting its value.
   *
   * @param[in]       e           Parent element
   * @param[in]       element     Name of the element
   * @param[in]       value       Value of the element
   */
  static void set_element_value (xercesc::DOMElement * e,
                                 const std::string & element,
                                 const std::string & value);

  static void set_element_value (xercesc::DOMElement * e,
                                 const ::Utils::XStr & element,
                                 const ::Utils::XStr & value);

  /**
   * Set the value of an element. If the element does not exist, then
   * the element is created before retrieving its value.
   *
   * @param[in]       e           Parent element
   * @param[in]       element     Name of the element
   * @param[out]      value       Value of the element
   */
  static void get_element_value (const xercesc::DOMElement * e,
                                 const std::string & element,
                                 std::string & value);

  static const XMLCh * get_element_value (const xercesc::DOMElement * e,
                                          const std::string & element);

  static const XMLCh * get_element_value (const xercesc::DOMElement * e,
                                          const ::Utils::XStr & element);

  /**
   * Get the child elements. This function does not recursively
   * retrieve all elements of the specified type. It only gets
   * the most immediate child elements.
   */
  template <typename T>
  static size_t get_children (xercesc::DOMElement * e,
                              std::vector <T> & children);

  /**
   * Get the child elements. This function does not recursively
   * retrieve all elements of the specified type. It only gets
   * the most immediate child elements.
   */
  template <typename T>
  static size_t get_children (xercesc::DOMElement * e,
                              const ::Utils::XStr & metaname,
                              std::vector <T> & children);
};

}
}

#if defined (__GAME_INLINE__)
#include "XME_Utils.inl"
#endif

#include "XME_Utils_T.cpp"

#endif  // !defined _GAME_XME_OBJECT_H_
