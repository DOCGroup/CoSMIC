#ifndef _CUTS_PIR_COMPONENT_HOME_H_
#define _CUTS_PIR_COMPONENT_HOME_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"

namespace CUTS_PIR
{
  class CUTS_Export Component_Home :
    public Module_Element,
    public Visitor_Element_T <
      Visitor, Component_Home, &Visitor::visit_component_home>
  {
  public:
    Component_Home (Module * module = 0);

    virtual ~Component_Home (void);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/ComponentHome.inl"
#endif

#endif  // !defined _CUTS_PIR_COMPONENT_HOME_H_