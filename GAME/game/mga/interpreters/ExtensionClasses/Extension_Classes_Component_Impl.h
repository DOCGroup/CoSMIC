// -*- C++ -*-

//=============================================================================
/**
 * @file        Extension_Classes_Component_Impl.h
 *
 * $Id: Extension_Classes_Component_Impl.h 2338 2010-07-08 14:29:57Z alhad $
 *
 * @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_COMPONENT_IMPL_H_
#define _EXTENSION_CLASSES_COMPONENT_IMPL_H_

#include "game/mga/component/Interpreter_Impl_Base.h"

/**
 * @class Extension_Classes_Component_Impl
 *
 * Main implementation for the extension class interpreter.
 */
class Extension_Classes_Component_Impl :
  public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  Extension_Classes_Component_Impl (void);

  /// Destructor.
  virtual ~Extension_Classes_Component_Impl (void);

  // Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in focus,
                 std::vector <GAME::Mga::FCO> & selected,
                 long flags);

  int set_parameter (const std::string & name, const std::string & value);

private:
  /// Load the save project settings.
  void load_project_settings (GAME::Mga::Project proj);

  /// Save the project settings for next time.
  void save_project_settings (GAME::Mga::Project proj);

  /// The target location for the generation.
  std::string output_;
};

#endif  // !defined _EXTENSION_CLASSES_COMPONENT_IMPL_H_
