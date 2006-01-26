#ifndef _CUTS_PIR_ELEMENT_H_
#define _CUTS_PIR_ELEMENT_H_

#include "cuts/config.h"
#include <string>

namespace CUTS_PIR
{
  //===========================================================================
  /**
   *
   */
  //===========================================================================

  class CUTS_Export Element
  {
  public:
    /// Constructor.
    Element (void);

    /// Destructor.
    virtual ~Element (void);

    /// Get the name of the element.
    const char * name (void) const;

    /// Set the name of the element.
    void name (const char * name);

    /// Get the unique ID for the element.
    const char * uuid (void) const;

    /// Set the unique ID for the element.
    void uuid (const char * uuid);

  private:
    /// Name of the element.
    std::string name_;

    /// Unique ID for the element.
    std::string uuid_;
  };

  // forward declaration
  class Module;

  class CUTS_Export Module_Element :
    virtual public Element
  {
  public:
    /// Constructor.
    Module_Element (Module * module = 0);

    /// Destructor.
    virtual ~Module_Element (void);

    /// Get the module of the element.
    Module * module (void) const;

    const char * scoped_name (const char * seperator) const;

  private:
    Module * module_;

    static std::string str_;
  };

  //===========================================================================
  /**
   *
   */
  //===========================================================================

  template <typename VISITOR,
            typename ELEMENT,
            void (VISITOR::*METHOD) (const ELEMENT &)>
  class Visitor_Element_T
  {
  public:
    virtual ~Visitor_Element_T (void)
    {

    }

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
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Element.inl"
#endif

#endif  // !defined _CUTS_PIR_ELEMENT_H_
