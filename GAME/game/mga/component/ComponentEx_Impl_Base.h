// -*- C++ -*-

//=============================================================================
/**
 * @file        ComponentEx_Impl_Base.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_COMPONENT_EX_IMPL_BASE_H_
#define _GAME_COMPONENT_EX_IMPL_BASE_H_

#include <string>
#include <vector>

#include "game/mga/GME_fwd.h"
#include "game/config.h"

#include "Component_export.h"

namespace GAME
{
namespace Mga
{

/**
 * @class ComponentEx_Impl_Base
 *
 * Base implemenation for all components.
 */
class GAME_MGA_COMPONENT_Export ComponentEx_Impl_Base
{
protected:
  ComponentEx_Impl_Base (const std::string & name,
                         const std::string & paradigm,
                         const std::string & progid,
                         bool managed = true);
public:
  /// Destructor.
  virtual ~ComponentEx_Impl_Base (void);

  int initialize (Project project);

  int invoke (Project project,
              std::vector <FCO> & selected,
              long flags);

  int invoke_ex (Project project,
                 FCO_in fco,
                 std::vector <FCO> & selected,
                 long flags);

  int invoke_object_ex (Project project,
                        Object_in obj,
                        std::vector <Object> & selected,
                        long flags);

  void interactive (bool mode);

  bool interactive (void) const;

  void enable (bool mode);

  const std::string & name (void) const;

  const std::string & paradigm (void) const;

  const std::string & progid (void) const;

  bool is_managed (void) const;

  int set_parameter (const std::string & name, const std::string & value);
  int get_parameter (const std::string & name, std::string & value);

protected:
  /// Name of the interpreter.
  const std::string name_;

  /// Paradigm for the interpreter.
  const std::string paradigm_;

  /// Program id for the interpreter.
  const std::string progid_;

  /// Interactive state of the interpreter.
  bool is_interactive_;

  bool is_enabled_;

  /// Flag for managing the transaction.
  bool is_managed_;
};

}
}

#if defined (__GAME_INLINE__)
#include "ComponentEx_Impl_Base.inl"
#endif

#endif  // !defined _GAME_COMPONENT_EX_IMPL_BASE_H_
