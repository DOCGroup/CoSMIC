// -*- C++ -*-

//=============================================================================
/**
 * @file    Action_Property.h
 *
 * $Id$
 *
 * [insert description here]
 *
 * @author  James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_PIR_ACTION_PROPERTY_H_
#define _CUTS_PIR_ACTION_PROPERTY_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"

namespace CUTS_PIR
{
  //===========================================================================
  /**
   * @class Action_Property
   *
   * This class is the generic representation for the properties. Each
   * property has a name and a corresponding value.
   */
  //===========================================================================

  class CUTS_Export Action_Property :
    public Element,
    public Visitor_Element_T <
      Visitor, Action_Property, &Visitor::visit_action_property>
  {
  public:
    /// Constructor.
    Action_Property (void);

    /// Destructor.
    virtual ~Action_Property (void);

    /// Get the value of the action.
    const std::string & value (void) const;

    /// Set the value of the action.
    void value (std::string & value);

  private:
    /// Value of the property.
    std::string value_;

    Action_Property (const Action_Property & ap);
    const Action_Property & operator = (const Action_Property & ap);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Action_Property.inl"
#endif

#endif // !defined _CUTS_PIR_ACTION_PROPERTY_H_

