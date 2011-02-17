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

#ifndef _GAME_MGA_VISITOR_H_
#define _GAME_MGA_VISITOR_H_

#include "game/config.h"
#include "GME_fwd.h"

#include "Mga_export.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Visitor
 *
 * Base class for all visitor objects. All the operations for the
 * object are a NOOP. It is the responsibility of the application
 * to extend this class and implement each visit operation, as it
 * deems necessary.
 */
class GAME_MGA_Export Visitor
{
public:
  /// Default constructor.
  Visitor (void);

  /// Destructor.
  virtual ~Visitor (void);

  /// Visit a Model_Impl element.
  virtual void visit_Model (Model_in);

  /// Visit a Atom_Impl element.
  virtual void visit_Atom (Atom_in);

  /// Visit a Folder_Impl element.
  virtual void visit_Folder (Folder_in);

  /// Visit a RootFolder_Impl element.
  virtual void visit_RootFolder (RootFolder_in);

  /// Visit a Reference_Impl element.
  virtual void visit_Reference (Reference_in);

  /// Visit a Set_Impl element.
  virtual void visit_Set (Set_in);

  /// Visit a Set_Impl element.
  virtual void visit_Connection (Connection_in);

private:
  Visitor (const Visitor &);
  const Visitor & operator = (const Visitor &);
};

}
}

#if defined (__GAME_INLINE__)
#include "Visitor.inl"
#endif

#endif  // !defined _GME_VISITOR_H_
