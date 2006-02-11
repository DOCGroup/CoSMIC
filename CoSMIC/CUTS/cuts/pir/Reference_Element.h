#ifndef _CUTS_PIR_REFERENCE_ELEMENT_H_
#define _CUTS_PIR_REFERENCE_ELEMENT_H_

#include "cuts/pir/Element.h"

namespace CUTS_PIR
{
  //===========================================================================
  /**
   * @class Reference_Element
   */
  //===========================================================================

  class CUTS_Export Reference_Element :
    virtual public Element
  {
  public:
    /// Destructor.
    virtual ~Reference_Element (void) = 0;

    /// Set the referenced element.
    void reference (Element * reference);

    /// Get the referenced element.
    Element * reference (void) const;

  protected:
    /// Constructor.
    Reference_Element (void);

    /// Pointer to the referenced element.
    Element * reference_;

    Reference_Element (const Reference_Element & element);
    const Reference_Element & operator = (const Reference_Element &);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Reference_Element.inl"
#endif

#endif
