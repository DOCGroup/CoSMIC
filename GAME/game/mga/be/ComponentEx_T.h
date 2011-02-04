// -*- C++ -*-

//=============================================================================
/**
 * @file        ComponentEx_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_COMPONENT_EX_T_H_
#define _GAME_COMPONENT_EX_T_H_

namespace GAME
{
namespace Mga
{

/**
 * @class ComponentEx_T
 *
 * Wrapper class for declaring a GME component, and its CoClass.
 */
template <typename IMPL, const CLSID * pclsid = &CLSID_NULL>
class ComponentEx_T :
  public ATL::CComCoClass < ComponentEx_T <IMPL, pclsid> , pclsid >,
  public IMPL
{
public:
  /// Default constructor.
  ComponentEx_T (void);

  /// Destructor.
  virtual ~ComponentEx_T (void);

  DECLARE_PROTECT_FINAL_CONSTRUCT ()
  DECLARE_NO_REGISTRY ()
};

}
}

#define DECLARE_GAME_COMPONENT_EX(impl, type) \
  typedef GAME::Mga::ComponentEx_T < impl, &CLSID_##type > type##_ComponentEx; \
  OBJECT_ENTRY_AUTO (__uuidof (type), type##_ComponentEx)

#if defined (__GAME_INLINE__)
#include "ComponentEx_T.inl"
#endif

#include "ComponentEx_T.cpp"

#endif  // !defined _GAME_COMPONENT_EX_T_H_
