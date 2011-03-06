// -*- C++ -*-

//=============================================================================
/**
 * @file        Addon_Impl_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_ADDON_IMPL_BASE_H_
#define _GAME_ADDON_IMPL_BASE_H_

#include "ComponentEx_Impl_Base.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Addon_Impl_Base
 *
 * Base class for all addon implementations. This base class allows
 * concrete add-on components to define their name, paradigm, and
 * program id.
 */
class GAME_MGA_COMPONENT_Export Addon_Impl_Base : public ComponentEx_Impl_Base
{
protected:
  Addon_Impl_Base (const std::string & name,
                   const std::string & paradigm,
                   const std::string & progid);

public:
  /// Destructor.
  virtual ~Addon_Impl_Base (void);
};

}
}

#if defined (__GAME_INLINE__)
#include "Addon_Impl_Base.inl"
#endif

#endif  // !defined _GAME_ADDON_IMPL_BASE_H_
