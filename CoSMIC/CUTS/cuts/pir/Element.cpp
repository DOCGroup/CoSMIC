#include "cuts/pir/Element.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/Element.inl"
#endif

#include "cuts/pir/Module.h"

namespace CUTS_PIR
{
  //===========================================================================
  /*
   * class Element
   */
  //===========================================================================

  //
  // Element
  //
  Element::Element (void)
  {

  }

  //
  // ~Element
  //
  Element::~Element (void)
  {

  }

  //===========================================================================
  /*
   * class Reference_Element
   */
  //===========================================================================

  Reference_Element::Reference_Element (void)
    : reference_ (0)
  {

  }

  Reference_Element::~Reference_Element (void)
  {

  }

  //===========================================================================
  /*
   * class Module_Element
   */
  //===========================================================================

  //
  // str_
  //
  std::string Module_Element::str_;

  //
  // Module_Element
  //
  Module_Element::Module_Element (Module * module)
    : module_ (module)
  {

  }

  //
  // Module_Element
  //
  Module_Element::~Module_Element (void)
  {

  }

  //
  // scoped_name
  //
  const char * Module_Element::scoped_name (const char * seperator) const
  {
    // Create the full scope of the element name.
    scope (seperator);
    Module_Element::str_.append (this->name ());

    return Module_Element::str_.c_str ();
  }

  //
  // scope
  //
  const char * Module_Element::scope (const char * seperator) const
  {
    // Clear the <str_> and store full name of the element
    if (!Module_Element::str_.empty ())
      Module_Element::str_.clear ();

    // Prepend the scope of the event to the name.
    const CUTS_PIR::Module * module = this->module_;

    while (module->parent () != 0)
    {
      Module_Element::str_.insert (0, seperator);
      Module_Element::str_.insert (0, module->name ());

      module = module->parent ();
    }

    return Module_Element::str_.c_str ();
  }
}
