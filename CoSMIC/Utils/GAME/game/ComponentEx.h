// -*- C++ -*-

//=============================================================================
/**
 * @file      ComponentEx.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_COMPONENT_EX_H_
#define _GME_COMPONENT_EX_H_

#include "Component.h"

namespace GAME
{
  //===========================================================================
  /**
   * @class ComponentEx
   *
   * Wrapper class for GME extended components.
   */
  //===========================================================================

  class GAME_Export ComponentEx : public Component
  {
  public:
    /// Default constructor.
    ComponentEx (void);

    /**
     * Load the specified component based on the provided
     * ProgID.
     *
     * @param[in]       progid          Program ID.
     */
    ComponentEx (const std::string & progid);

    /// Destructor
    virtual ~ComponentEx (void);

    /**
     * Set a parameter of the component.
     *
     * @param[in]       param       The name of the parameter.
     * @param[in]       value       The value of the parameter.
     */
    void parameter (const std::string & param,
                    const std::string & value);

    /**
     * Invoke the interpreter.
     *
     * @param[in]     project       The project to interpret.
     * @param[in]     selected      Collection of selected FCOs.
     * @param[in]     param         User-defined parameter.
     */
    void invoke (Project & project,
                 FCO & current,
                 std::vector <FCO> & selected,
                 long param);

  protected:
    /// Helper method to get the correct implementation.
    IMgaComponentEx * impl () const;

  private:
    /// The underlying component interface.
    mutable ATL::CComPtr <IMgaComponentEx> component_ex_;
  };
}

#endif  // !defined _GME_COMPONENT_EX_H_
