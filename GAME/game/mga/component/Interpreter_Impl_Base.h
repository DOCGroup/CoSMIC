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

#include "ComponentEx_Impl_Base.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Interpreter_Impl_Base
 *
 * Base implemenation for all interperters. Subclasses of this class
 * are used as the second parameter for GAME::Interpreter_T
 */
class GAME_MGA_COMPONENT_Export Interpreter_Impl_Base :
  public ComponentEx_Impl_Base 
{
protected:
  Interpreter_Impl_Base (const std::string & name,
                         const std::string & paradigm,
                         const std::string & progid);
public:
  /// Destructor.
  virtual ~Interpreter_Impl_Base (void);
};

}
}

#if defined (__GAME_INLINE__)
#include "Interpreter_Impl_Base.inl"
#endif

#endif  // !defined _GAME_INTERPRETER_IMPL_BASE_H_
