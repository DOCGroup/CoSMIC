// -*- C++ -*-

//==============================================================================
/**
 *  @file        Connection_Endpoint_Visitor.h
 *
 *  $Id$
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_EXTENSION_CLASSES_CONNECTION_ENDPOINT_VISITOR_H_
#define _GAME_EXTENSION_CLASSES_CONNECTION_ENDPOINT_VISITOR_H_

#include <set>
#include "Proxy_Visitor.h"

#include "game/mga/Atom.h"
#include "game/mga/Connection.h"

// Forward decl.
class Object_Class_Definition;

/**
 * @class Source_Connection_Endpoint_Visitor
 *
 * Utility class that gathers the unique source endpoints of a
 * connection.
 */
class Source_Connection_Endpoint_Visitor : public Proxy_Visitor
{
public:
  /// Default constructor.
  Source_Connection_Endpoint_Visitor (
    GAME::Mga::FCO_in dst,
    std::set <Object_Class_Definition *> & items);

  /// Destructor.
  virtual ~Source_Connection_Endpoint_Visitor (void);

  virtual void visit_Connection (GAME::Mga::Connection_in item);
  virtual void visit_Atom (GAME::Mga::Atom_in item);

private:
  GAME::Mga::FCO dst_;
  std::set <Object_Class_Definition *> & items_;
};

/**
 * @class Destination_Connection_Endpoint_Visitor
 *
 * Utility class that gathers the unique destination endpoints of a
 * connection.
 */
class Destination_Connection_Endpoint_Visitor : public Proxy_Visitor
{
public:
  /// Default constructor.
  Destination_Connection_Endpoint_Visitor (
    GAME::Mga::FCO_in src,
    std::set <Object_Class_Definition *> & items);

  /// Destructor.
  virtual ~Destination_Connection_Endpoint_Visitor (void);

  virtual void visit_Connection (GAME::Mga::Connection_in item);
  virtual void visit_Atom (GAME::Mga::Atom_in item);

private:
  GAME::Mga::FCO src_;
  std::set <Object_Class_Definition *> & items_;
};

#if defined (__GAME_INLINE__)
#include "Connection_Endpoint_Visitor.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _CONNECTION_ENDPOINT_VISITOR_H_
