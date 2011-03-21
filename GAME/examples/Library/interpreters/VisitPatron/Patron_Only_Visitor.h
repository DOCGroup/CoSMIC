// -*- C++ -*-

//=============================================================================
/**
 * @file          Patron_Only_Visitor.h
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#include "Library/Visitor.h"

/**
 * @class Patron_Only_Visitor
 *
 * Visitor that only visits Patron elements. It prints the full
 * path of each Patron it sees.
 */
class Patron_Only_Visitor : public Library::Visitor
{
public:
  /// Default constructor.
  Patron_Only_Visitor (void);

  /// Destructor.
  virtual ~Patron_Only_Visitor (void);

  // Visit a RootFolder element.
  virtual void visit_RootFolder (GAME::Mga::RootFolder_in r);

  // Visit a Library element.
  virtual void visit_Library (Library::Library_in l);

  // Visit a Patron element.
  virtual void visit_Patron (Library::Patron_in p);
};
