// -*- C++ -*-

//=============================================================================
/**
 * @file      Component.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_COMPONENT_H_
#define _GME_COMPONENT_H_

#include "Project.h"
#include "Mga.h"

namespace GME
{
  //===========================================================================
  /**
   * @class Component
   *
   * Wrapper class for GME components.
   */
  //===========================================================================

  class GME_Export Component
  {
  public:
    /// Default constructor.
    Component (void);

    /// Destructor
    virtual ~Component (void);

    /**
     * Get the name of the component.
     *
     * @return      The name of the component.
     */
    std::string name (void) const;

    /**
     * Get the component's type.
     *
     * @return      The type of the component.
     */
    componenttype_enum type (void) const;

    /**
     * Get the name(s) of the paradigms to which the component is
     * registered.
     *
     * @return      The names of the paradigm.
     */
    std::string registered_paradigm (void) const;

    /**
     * Invoke the interpreter.
     *
     * @param[in]     project       The project to interpret.
     * @param[in]     selected      Collection of selected FCOs.
     * @param[in]     param         User-defined parameter.
     */
    void invoke (Project & project, std::vector <FCO> & selected, long param);

    /**
     * Load a component with the specified program id.
     *
     * @param[in]   progid      Program id of the component.
     */
    void load (const std::string & progid);

    /// Explicitly release the component.
    void release (void);

  protected:
    /// The underlying component interface.
    CComPtr <IMgaComponent> component_;
  };
}

#endif  // !defined _GME_COMPONENT_H_
