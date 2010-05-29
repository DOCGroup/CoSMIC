// -*- C++ -*-

//=============================================================================
/**
 * @file      Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_VISITOR_H_
#define _GME_VISITOR_H_

#include "game/config.h"
#include "GME_fwd.h"
#include "GAME_export.h"

namespace GAME
{
/**
 * @class Visitor
 *
 * Base class for all visitor objects. All the operations for the
 * object are a NOOP. It is the responsibility of the application
 * to extend this class and implement each visit operation, as it
 * deems necessary.
 */
class GAME_Export Visitor
{
public:
  /// Default constructor
  Visitor (void);

  /// Destructor.
  virtual ~Visitor (void);

  /// Visit a GAME::Object
  virtual void visit_Object (GAME::Object &);

  /// Visit a GAME::FCO
  virtual void visit_FCO (GAME::FCO &);

  /// Visit a GAME::Model
  virtual void visit_Model (GAME::Model &);

  /// Visit a GAME::Atom
  virtual void visit_Atom (GAME::Atom &);

  /// Visit a GAME::Folder
  virtual void visit_Folder (GAME::Folder &);

  /// Visit a GAME::Reference
  virtual void visit_Reference (GAME::Reference &);

  virtual void visit_Set (GAME::Set &);
};
}

#if defined (__GAME_INLINE__)
#include "Visitor.inl"
#endif

#endif  // !defined _GME_VISITOR_H_
