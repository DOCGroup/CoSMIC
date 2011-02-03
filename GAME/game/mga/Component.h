// -*- C++ -*-

//=============================================================================
/**
 * @file      Component_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_COMPONENT_H_
#define _GAME_MGA_COMPONENT_H_

#include "Project.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Component_Impl
 *
 * Wrapper class for GME components.
 */
class GAME_MGA_Export Component_Impl : public Refcountable
{
public:
  /// Type definition of the interface type.
  typedef IMgaComponent interface_type;

  /**
   * Load a component with the specified program id. This is useful
   * when automating a interpreter from another client application.
   *
   * @param[in]   progid      Program id of the component.
   */
  static Component _load (const std::string & progid);

  /// Default constructor.
  Component_Impl (void);

  /**
   * Initializing constructor
   *
   * @param[in]         c       Pointer to the component
   */
  Component_Impl (IMgaComponent * c);

  /// Destructor
  virtual ~Component_Impl (void);

  /**
   * Initialize the component.
   *
   * @param[in]   project     The target project.
   */
  void initialize (Project project);

  /// Test the iteractive state of the component.
  bool interactive (void) const;

  /// Set the interactive state of the component.
  void interactive (bool flag);

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
  void invoke (Project project,
               const std::vector <FCO> & selected,
               long param);

  /// Set the enable state for the component.
  void enable (bool state);

  /// Explicitly release the component.
  void release (void);

  /// Attach to the specified inteface.
  void attach (IMgaComponent * c);

  IMgaComponent * impl (void) const;

protected:
  /// The underlying component interface.
  ATL::CComPtr <IMgaComponent> component_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Component.inl"
#endif

#endif  // !defined _GAME_MGA_COMPONENT_H_
