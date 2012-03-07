// -*- C++ -*-

//==============================================================================
/**
 *  @file        Singleton_Adapter_T.h
 *
 *  $Id$
 *
 *  @author      James H. Hill
 */
//==============================================================================

#ifndef _GAME_MGA_COMPONENT_SINGLETON_ADAPTER_T_H_
#define _GAME_MGA_COMPONENT_SINGLETON_ADAPTER_T_H_

namespace GAME
{
namespace Mga
{

/**
 * @class Singleton_Adapter_T
 *
 * Adapter class for using type T with ACE_DLL_Singleton_T.
 */
template <typename T>
class Singleton_Adapter_T : public T
{
public:
  /// Default constructor.
  Singleton_Adapter_T (void);

  /// Destructor.
  ~Singleton_Adapter_T (void);

  /// Name of the adapter class.
  const char * name (void) const;

  /// Name of the singleton's owner dll.
  const char * dll_name (void) const;
};

}
}

#if defined (__GAME_INLINE__)
#include "Singleton_Adapter_T.inl"
#endif  // !defined __GAME_INLINE__

#include "Singleton_Adapter_T.cpp"

#endif  // _GAME_MGA_COMPONENT_SINGLETON_ADAPTER_T_H_
