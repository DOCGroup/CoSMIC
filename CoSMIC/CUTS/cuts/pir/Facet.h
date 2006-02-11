#ifndef _CUTS_PIR_FACET_H_
#define _CUTS_PIR_FACET_H_

#include "cuts/pir/Reference_Element.h"
#include "cuts/pir/Visitor.h"

namespace CUTS_PIR
{
  //===========================================================================
  /**
   * @class Facet
   */
  //===========================================================================

  class CUTS_Export Facet :
    public Reference_Element,
    public Visitor_Element_T <Visitor, Facet, &Visitor::visit_facet>
  {
  public:
    /// Constructor.
    Facet (void);

    /// Destructor.
    virtual ~Facet (void);

  private:
    Facet (const Facet &);
    const Facet & operator = (const Facet &);
  };
}

#endif  // _CUTS_PIR_FACET_H_
