// -*- C++ -*-

//============================================================================
/**
 * @file    Visitor.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _LIBRARY_VISITOR_H_
#define _LIBRARY_VISITOR_H_

#include "game/mga/Visitor.h"

#include "Library_fwd.h"
#include "Library_export.h"

namespace Library
{
  class LIBRARY_Export Visitor : public ::GAME::Mga::Visitor
  {
    protected:
    /// Default constructor.
    Visitor (void);

    public:
    /// Destructor.
    virtual ~Visitor (void);

    /**
     * @name Visit Methods
     */
    ///@{
    virtual void visit_Patron (Patron_in item);
    virtual void visit_Borrow (Borrow_in item);
    virtual void visit_Library (Library_in item);
    virtual void visit_Book (Book_in item);
    ///@}
    private:
    // prevent the following operation(s)
    const Visitor & operator = (const Visitor &);
  };
}

#endif
