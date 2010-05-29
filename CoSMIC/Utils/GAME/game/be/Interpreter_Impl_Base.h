// -*- C++ -*-

//=============================================================================
/**
 * @file        Interpreter_Impl_Base.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_INTERPRETER_IMPL_BASE_H_
#define _GAME_INTERPRETER_IMPL_BASE_H_

#include "BE_export.h"
#include "game/GME_fwd.h"
#include "game/Collection_T.h"
#include <string>

namespace GAME
{
/**
 * @class Interpreter_Impl_Base
 *
 * Base implemenation for all interperters. Subclasses of this class
 * are used as the second parameter for GAME::Interpreter_T
 */
class GAME_BE_Export Interpreter_Impl_Base
{
protected:
  /// Default constructor.
  Interpreter_Impl_Base (bool managed = true);

  Interpreter_Impl_Base (const std::string & name,
                         const std::string & paradigm,
                         const std::string & progid,
                         bool managed = true);
public:
  /// Destructor.
  ~Interpreter_Impl_Base (void);

  int initialize (GAME::Project & project);

  int invoke (GAME::Project & project,
              std::vector <GAME::FCO> & selected,
              long flags);

  int invoke_ex (GAME::Project & project,
                 GAME::FCO & fco,
                 std::vector <GAME::FCO> & selected,
                 long flags);

  int invoke_object_ex (GAME::Project & project,
                        GAME::Object & obj,
                        std::vector <GAME::Object> & selected,
                        long flags);

  void interactive (bool mode);

  bool interactive (void) const;

  void enable (bool mode);

  const std::string & name (void) const;

  const std::string & paradigm (void) const;

  const std::string & progid (void) const;

  bool is_managed (void) const;

protected:
  /// Name of the interpreter.
  std::string name_;

  /// Paradigm for the interpreter.
  std::string paradigm_;

  /// Program id for the interpreter.
  std::string progid_;

  /// Interactive state of the interpreter.
  bool is_interactive_;

  bool is_enabled_;

  /// Flag for managing the transaction.
  bool is_managed_;
};

}

#if defined (__GAME_INLINE__)
#include "Interpreter_Impl_Base.inl"
#endif

#endif  // !defined _GAME_INTERPRETER_IMPL_BASE_H_
