#ifndef _CUTS_PIR_MODULE_ELEMENT_H_
#define _CUTS_PIR_MODULE_ELEMENT_H_

#include "cuts/pir/Element.h"

namespace CUTS_PIR
{
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
    /// Destructor.
    virtual ~Module_Element (void) = 0;

    /// Get the module of the element.
    const Module * module (void) const;

    /// Get the full scoped name of the element.
    const char * scoped_name (const char * seperator) const;

    /// Get the scope of the element.
    const char * scope (const char * seperator) const;

  protected:
    /// Constructor.
    Module_Element (const Module * module = 0);

    /// Parent module for the element.
    const Module * module_;

  private:
    /// Temporary string for creating the scoped name.
    static std::string str_;

    Module_Element (const Module_Element &);
    const Module_Element & operator = (const Module_Element & me);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Module_Element.inl"
#endif

#endif  // !defined _CUTS_PIR_MODULE_ELEMENT_H_
