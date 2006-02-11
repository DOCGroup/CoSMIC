#ifndef _CUTS_PIR_ELEMENT_H_
#define _CUTS_PIR_ELEMENT_H_

#include "cuts/config.h"
#include <string>

namespace CUTS_PIR
{
  //===========================================================================
  /**
   * @class Element
   */
  //===========================================================================

  class CUTS_Export Element
  {
  public:
    /// Destructor.
    virtual ~Element (void) = 0;

    /// Get the name of the element.
    const std::string & name (void) const;

    /// Set the name of the element.
    void name (std::string & name);

    /// Get the unique ID for the element.
    const std::string & uuid (void) const;

    /// Set the unique ID for the element.
    void uuid (std::string & uuid);

  protected:
    /// Constructor.
    Element (void);

    /// Name of the element.
    std::string name_;

    /// Unique ID for the element.
    std::string uuid_;

  private:
    Element (const Element &);
    const Element & operator = (const Element &);
  };

  //===========================================================================
  /**
   * @class Visitor_Element_T
   */
  //===========================================================================

  template <typename VISITOR,
            typename ELEMENT,
            void (VISITOR::*METHOD) (const ELEMENT &)>
  class Visitor_Element_T
  {
  public:
    /// Constructor.
    virtual ~Visitor_Element_T (void)
    {

    }

    /// Accept the visitor.
    virtual void accept (VISITOR * visitor)
    {
      try
      {
        // Since we are using templates and this is a base class for
        // another class, we have to cast the element to the appropriate
        // type in order to visit it.
        const ELEMENT * element = dynamic_cast <const ELEMENT *> (this);
        (visitor->*METHOD) (*element);
      }
      catch (...)
      {

      }
    }

    /// Accept the visitor.
    virtual void accept (VISITOR * visitor) const
    {
      try
      {
        // Since we are using templates and this is a base class for
        // another class, we have to cast the element to the appropriate
        // type in order to visit it.
        const ELEMENT * element = dynamic_cast <const ELEMENT *> (this);
        (visitor->*METHOD) (*element);
      }
      catch (...)
      {

      }
    }
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Element.inl"
#endif

#endif  // !defined _CUTS_PIR_ELEMENT_H_
