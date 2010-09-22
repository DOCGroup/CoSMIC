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

namespace GAME
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
  static Connection _create (Model parent,
                             const GAME::Xml::String & kind,
                             const FCO & src,
                             const FCO & dst);

  static Connection _narrow (const Object & obj);

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
  static const GAME::Xml::String TAGNAME;

  void src (const FCO & fco);
  const FCO & src (void) const;

  void dst (const FCO & fco);
  const FCO & dst (void) const;

  /**
   * Release the current element. The client takes ownership of
   * this element once this method returns.
   *
   * @return        The contained element.
   */
  virtual xercesc::DOMElement * release (void);

  virtual void attach (xercesc::DOMElement * e, bool validate = true);

protected:
  Connection (xercesc::DOMElement * parent,
              const GAME::Xml::String & kind,
              size_t relid,
              const FCO & src,
              const FCO & dst);

private:
  static const GAME::Xml::String TAGNAME_CONNPOINT;
  static const GAME::Xml::String CONNPOINT_SRC;
  static const GAME::Xml::String CONNPOINT_DST;
  static const GAME::Xml::String ATTR_TARGET;

  /// The source FCO.
  mutable FCO src_;

  /// The destination FCO.
  mutable FCO dst_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Connection.inl"
#endif

#endif  // !defined _GAME_XME_CONNECTION_H_
