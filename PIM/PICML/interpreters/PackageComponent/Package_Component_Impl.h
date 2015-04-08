// -*- C++ -*-

//=============================================================================
/**
 * @file        Package_Component_Impl.h
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_PACKAGE_COMPONENT_IMPL_H_
#define _PICML_PACKAGE_COMPONENT_IMPL_H_

#include "game/mga/component/Interpreter_Impl_Base.h"

// Forward decl.
class PackageOptions;

/**
 * @class Package_Component_Impl
 *
 * Implemenation of the packaging component.
 */
class Package_Component_Impl :
  public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  Package_Component_Impl (void);

  /// Destructor.
  virtual ~Package_Component_Impl (void);

  // Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in fco,
                 std::vector <GAME::Mga::FCO> & selected,
                 long flags);

private:
  // Helper method to load last configuration.
  static void load_configuration (GAME::Mga::Project proj, PackageOptions & config);

  // Helper method to s last configuration.
  static void save_configuration (GAME::Mga::Project proj, const PackageOptions & config);
};

#endif
