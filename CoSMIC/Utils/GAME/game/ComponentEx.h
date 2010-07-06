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
/**
 * @class ComponentEx
 *
 * Wrapper class for GME extended components.
 */

class GAME_Export ComponentEx : public Component
{
public:
  /**
   * Load a extended component into memory. This method will create the
   * extended component with the specified program id. If the component 
   * cannot be created, then an exception is thrown.
   *
   * @param[in]       progid        Source program id
   */
  static ComponentEx _load (const std::string & progid);

  /// Default constructor.
  ComponentEx (void);

  /**
   * Initializing constructor
   *
   * @param[in]       ptr       Pointer to the interface
   */
  ComponentEx (IMgaComponentEx * ptr);

  /**
   * Copy constructor
   *
   * @param[in]       c         The source component
   */
  ComponentEx (const ComponentEx & c);

  /// Destructor
  virtual ~ComponentEx (void);

  /**
   * Set a parameter of the component.
   *
   * @param[in]       param       The name of the parameter.
   * @param[in]       value       The value of the parameter.
   */
  void parameter (const std::string & param, const std::string & value);

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

  /**
   * Get the program id assigned to this component.
   *
   * @return        The component's program id.
   */
  std::string progid (void) const;

  virtual IMgaComponentEx * operator -> (void) const;

protected:
  /// Helper method to get the correct implementation.
  IMgaComponentEx * impl () const;

private:
  /// The underlying component interface.
  mutable ATL::CComPtr <IMgaComponentEx> component_ex_;
};

}

#if defined (__GAME_INLINE__)
#include "ComponentEx.inl"
#endif

#endif  // !defined _GME_COMPONENT_EX_H_
