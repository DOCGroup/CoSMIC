// -*- C++ -*-

//=============================================================================
/**
 * @file      Connection.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_CONNECTION_H_
#define _GAME_XME_CONNECTION_H_

#include "FCO.h"

namespace GME
{
namespace XME
{
// Forward decl.
class Model;

/**
 * @class Connection
 *
 * Wrapper class for connection objects in the XML document.
 */
class GAME_XME_Export Connection : public FCO
{
public:
  /**
   * Create a new model
   *
   * @param[in]       parent          Parent of the new folder
   * @param[in]       kind            Type folder's type
   */
  static Connection _create (Model & parent,
                             const ::Utils::XStr & kind,
                             const FCO & src,
                             const FCO & dst);

  /// Default constructor.
  Connection (void);

  /**
   * Initializing constructor
   *
   * @param[in]     obj       The source object.
   */
  Connection (xercesc::DOMElement * conn, bool validate = true);

  /**
   * Copy constructor
   *
   * @param[in]     obj       The source object
   */
  Connection (const Connection & conn);

  /// Destructor.
  ~Connection (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const Connection & operator = (const Connection & fco);

  /// The XML tagname for this element.
  static const ::Utils::XStr TAGNAME;

protected:
  Connection (xercesc::DOMElement * parent,
              const ::Utils::XStr & kind,
              size_t relid,
              const FCO & src,
              const FCO & dst);

private:
  static const ::Utils::XStr TAGNAME_CONNPOINT;
  static const ::Utils::XStr CONNPOINT_SRC;
  static const ::Utils::XStr CONNPOINT_DST;
  static const ::Utils::XStr ATTR_TARGET;
};

}
}

#if defined (__GME_INLINE__)
#include "Connection.inl"
#endif

#endif  // !defined _GAME_XME_CONNECTION_H_
