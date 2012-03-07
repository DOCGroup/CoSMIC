// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Singleton_Adapter_T
//
template <typename T>
GAME_INLINE
Singleton_Adapter_T <T>::Singleton_Adapter_T (void)
{

}

//
// ~Singleton_Adapter_T
//
template <typename T>
GAME_INLINE
Singleton_Adapter_T <T>::~Singleton_Adapter_T (void)
{

}

//
// name
//
template <typename T>
GAME_INLINE
const char * Singleton_Adapter_T <T>::name (void) const
{
  return typeid (T).name ();
}

//
// dll_name
//
template <typename T>
GAME_INLINE
const char * Singleton_Adapter_T <T>::dll_name (void) const
{
  return ACE_TEXT ("GAME_Mga_Component");
}

}
}
