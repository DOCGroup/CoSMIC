#include "cuts/pir/Element.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/Element.inl"
#endif

#include "cuts/pir/Module.h"

namespace CUTS_PIR
{
  Element::Element (void)
  {

  }

  Element::~Element (void)
  {

  }

  std::string Module_Element::str_;

  Module_Element::Module_Element (Module * module)
    : module_ (module)
  {

  }

  Module_Element::~Module_Element (void)
  {

  }

  const char * Module_Element::scoped_name (const char * seperator) const
  {
    // Clear the <str_> and store full name of the element
    if (!Module_Element::str_.empty ())
      Module_Element::str_.clear ();

    Module_Element::str_ += this->name ();

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
