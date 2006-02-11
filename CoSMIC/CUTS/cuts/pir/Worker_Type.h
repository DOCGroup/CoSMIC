// -*- C++ -*-

//=============================================================================
/**
 * @file      Worker_Type.h
 *
 * $Id$
 *
 * [insert description here]
 *
 * @author    James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_PIR_WORKER_TYPE_H_
#define _CUTS_PIR_WORKER_TYPE_H_

#include "cuts/pir/Reference_Element.h"
#include "cuts/pir/Visitor.h"

namespace CUTS_PIR
{
  class CUTS_Export Worker_Type :
    public Reference_Element,
    public Visitor_Element_T <Visitor, Worker_Type, Visitor::visit_worker_type>
  {
  public:
    /// Constructor.
    Worker_Type (void);

    /// Destructor.
    virtual ~Worker_Type (void);

  private:
    Worker_Type (const Worker_Type & worker_type);
    const Worker_Type & operator = (const Worker_Type & worker_type);
  };
}

#endif  // !defined _CUTS_WORKRER_TYPE_H_
