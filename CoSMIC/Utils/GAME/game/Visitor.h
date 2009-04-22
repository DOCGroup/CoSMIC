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

#include "GME_fwd.h"
#include "GME_export.h"

namespace GME
{
/**
 * @class Visitor
 *
 * Base class for all visitor objects. All the operations for the
 * object are a NOOP. It is the responsibility of the application
 * to extend this class and implement each visit operation, as it
 * deems necessary.
 */
class GME_Export Visitor
{
public:
  /// Default constructor
  Visitor (void);

  /// Destructor.
  virtual ~Visitor (void);

  /// Visit a GME::Object
  virtual void visit_Object (GME::Object &);

  /// Visit a GME::FCO
  virtual void visit_FCO (GME::FCO &);

  /// Visit a GME::Model
  virtual void visit_Model (GME::Model &);

  /// Visit a GME::Atom
  virtual void visit_Atom (GME::Atom &);

  /// Visit a GME::Folder
  virtual void visit_Folder (GME::Folder &);

  /// Visit a GME::Reference
  virtual void visit_Reference (GME::Reference &);

  virtual void visit_Set (GME::Set &);
};
}

#if defined (__GME_INLINE__)
#include "Visitor.inl"
#endif

#endif  // !defined _GME_VISITOR_H_
