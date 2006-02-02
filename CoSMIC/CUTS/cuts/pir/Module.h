#ifndef _CUTS_PIR_MODULE_H_
#define _CUTS_PIR_MODULE_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"
#include <set>

namespace CUTS_PIR
{
  /// forward declarations
  class Component;
  class Component_Home;

  //===========================================================================
  /**
   * @class Module
   */
  //===========================================================================

  class CUTS_Export Module :
    public Element,
    public Visitor_Element_T <Visitor, Module, &Visitor::visit_module>
  {
  public:
    /// Type definition for the collection of components.
    typedef std::set <Component *> Components;

    /// Type definition for the collection of modules.
    typedef std::set <Module *> Modules;

    /// Type definition for the collection of objects.
    typedef std::set <Object *> Objects;

    /// Constructor.
    Module (const Module * parent = 0);

    /// Destructor.
    virtual ~Module (void);

    /// Get the modules defined in this module.
    Modules & modules (void);

    /// Get the modules defined in thie module.
    const Modules & modules (void) const;

    /// Get the components defined in this module.
    Components & components (void);

    /// Get the components defined in this module.
    const Components & components (void) const;

    /// Get the parent of this module.
    const Module * parent (void) const;

    /// Get the objects defined in this module.
    Objects & objects (void);

    /// Get the objects defined in this module.
    const Objects & objects (void) const;

  private:
    /// Components contained in this module.
    Components components_;

    /// Modules contained in this module.
    Modules modules_;

    /// Objects contained in this module.
    Objects objects_;

    /// The parent of this module.
    const Module * parent_;
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Module.inl"
#endif

#endif  // !defined _CUTS_PIR_MODULE_H_
