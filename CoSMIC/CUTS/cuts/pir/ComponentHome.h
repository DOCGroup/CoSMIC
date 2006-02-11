#ifndef _CUTS_PIR_COMPONENT_HOME_H_
#define _CUTS_PIR_COMPONENT_HOME_H_

#include "cuts/pir/Module_Element.h"
#include "cuts/pir/Visitor.h"

namespace CUTS_PIR
{
  class Component;

  class CUTS_Export Component_Home :
    public Module_Element,
    public Visitor_Element_T <
      Visitor, Component_Home, &Visitor::visit_component_home>
  {
  public:
    /// Constructor.
    Component_Home (const Module * module = 0);

    /// Destructor.
    virtual ~Component_Home (void);

    /// Get the component it manages.
    const Component * manages (void) const;

    /// Set the component it manages.
    void manages (const Component * component);

  private:
    /// The component it manages.
    const Component * manages_;

    Component_Home (Component_Home &);
    const Component_Home & operator = (const Component_Home &);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/ComponentHome.inl"
#endif

#endif  // !defined _CUTS_PIR_COMPONENT_HOME_H_