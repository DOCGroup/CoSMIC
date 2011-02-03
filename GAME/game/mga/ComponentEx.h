// -*- C++ -*-

//=============================================================================
/**
 * @file      ComponentEx_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_COMPONENT_EX_H_
#define _GAME_MGA_COMPONENT_EX_H_

#include "Component.h"

namespace GAME
{
namespace Mga
{

/**
 * @class ComponentEx_Impl
 *
 * Wrapper class for GME extended components.
 */

class GAME_MGA_Export ComponentEx_Impl : public Component_Impl
{
public:
  /// Type definition of the interface type.
  typedef IMgaComponentEx interface_type;

  /**
   * Load a extended component into memory. This method will create the
   * extended component with the specified program id. If the component
   * cannot be created, then an exception is thrown.
   *
   * @param[in]       progid        Source program id
   */
  static ComponentEx _load (const std::string & progid);

  /// Default constructor.
  ComponentEx_Impl (void);

  /**
   * Initializing constructor
   *
   * @param[in]       ptr       Pointer to the interface
   */
  ComponentEx_Impl (IMgaComponentEx * ptr);

  /// Destructor
  virtual ~ComponentEx_Impl (void);

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
  void invoke (Project project,
               FCO_in current,
               const std::vector <FCO> & selected,
               long param);

  /**
   * Get the program id assigned to this component.
   *
   * @return        The component's program id.
   */
  std::string progid (void) const;

  /// Helper method to get the correct implementation.
  IMgaComponentEx * impl () const;

private:
  /// The underlying component interface.
  mutable ATL::CComPtr <IMgaComponentEx> component_ex_;
};

}
}

#if defined (__GAME_INLINE__)
#include "ComponentEx.inl"
#endif

#endif  // !defined _GME_COMPONENT_EX_H_
