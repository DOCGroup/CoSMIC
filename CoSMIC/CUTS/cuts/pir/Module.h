#ifndef _CUTS_PIR_MODULE_H_
#define _CUTS_PIR_MODULE_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"
#include <set>

namespace CUTS_PIR
{
  class Component;

  class CUTS_Export Module :
    public Visitor_Element_T <Visitor, Module, &Visitor::visit_module>,
    public Element
  {
  public:
    /// Type definition for the collection of components.
    typedef std::set <Component *> Components;

    /// Type definition for the collection of modules.
    typedef std::set <Module *> Modules;

    Module (const Module * parent = 0);

    virtual ~Module (void);

    Modules & modules (void);

    const Modules & modules (void) const;

    Components & components (void);

    const Components & components (void) const;

    const Module * parent (void) const;

  private:
    /// Components contained in this module.
    Components components_;

    /// Modules contained in this module.
    Modules modules_;

    const Module * parent_;
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Module.inl"
#endif

#endif  // !defined _CUTS_PIR_MODULE_H_
