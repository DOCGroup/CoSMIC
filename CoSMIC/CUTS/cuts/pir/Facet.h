#ifndef _CUTS_PIR_FACET_H_
#define _CUTS_PIR_FACET_H_

#include "cuts/pir/Element.h"
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
    public Element,
    public Visitor_Element_T <Visitor, Facet, &Visitor::visit_facet>
  {
  public:
    /// Constructor.
    Facet (void);

    /// Destructor.
    virtual ~Facet (void);
  };
}

#endif  // _CUTS_PIR_FACET_H_
