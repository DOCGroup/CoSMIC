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

  /// Visit a GAME::Model_Impl
  virtual void visit_Model (Model_in);

  /// Visit a GAME::Atom_Impl
  virtual void visit_Atom (Atom_in);

  /// Visit a GAME::Folder_Impl_Impl
  virtual void visit_Folder (Folder_in);

  /// Visit a GAME::Reference_Impl
  virtual void visit_Reference (Reference_in);

  /// Visit a GAME::Set_Impl
  virtual void visit_Set (Set_in);

  /// Visit a GAME::Set_Impl
  virtual void visit_Connection (Connection_in);
};
}

#if defined (__GAME_INLINE__)
#include "Visitor.inl"
#endif

#endif  // !defined _GME_VISITOR_H_
