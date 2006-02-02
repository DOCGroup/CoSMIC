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

  //===========================================================================
  /**
   * @class Module_Element
   */
  //===========================================================================

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

    /// Get the full scoped name of the element.
    const char * scoped_name (const char * seperator) const;

    /// Get the scope of the element.
    const char * scope (const char * seperator) const;

  private:
    /// Parent module for the element.
    Module * module_;

    /// Temporary string for creating the scoped name.
    static std::string str_;
  };

  //===========================================================================
  /**
   * @class Visitor_Element_T
   */
  //===========================================================================

  class CUTS_Export Reference_Element
  {
  public:
    /// Constructor.
    Reference_Element (void);

    /// Destructor.
    virtual ~Reference_Element (void);

    /// Set the referenced element.
    void reference (Element * reference);

    /// Get the referenced element.
    Element * reference (void) const;

  private:
    /// Pointer to the referenced element.
    Element * reference_;
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
