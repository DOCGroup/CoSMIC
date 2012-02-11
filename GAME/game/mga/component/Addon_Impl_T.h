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

#ifndef _GAME_ADDON_T_H_
#define _GAME_ADDON_T_H_

#include "ComponentEx_Impl_T.h"
#include "Addon_Impl_Base.h"
#include "Event_Sink.h"

#define GAME_DEFAULT_ADDON_IMPL(type, name, paradigm, progid) \
  class type : public GAME::Mga::Addon_Impl_Base { \
  public: \
    type (void) \
    : GAME::Mga::Addon_Impl_Base (name, paradigm, progid) { } \
    virtual ~type (void) { } \
  }

namespace GAME
{
namespace Mga
{

/**
 * @class Addon_Impl_T
 *
 * Wrapper class for interfacing the add-on with GME/COM. The IMPL
 * parameters the actual implementation, which should be derived
 * from Addon_Impl_Base. The SINK is the event handler for the add-on
 * and should be a subclass of Event_Handler_Impl.
 */
template <typename IMPL, typename SINK>
class Addon_Impl_T : public ComponentEx_Impl_T < IMPL >
{
public:
  /// Default constructor.
  Addon_Impl_T (void);

  /// Destructor.
  virtual ~Addon_Impl_T (void);

  // Handle the initialization of the addon
  STDMETHOD (Initialize) (IMgaProject * proj);
  STDMETHOD (Enable) (VARIANT_BOOL enable);

protected:
  /// The implementation of the sink.
  SINK impl_;

  /// Raw interface to the event sink.
  ::ATL::CComPtr <Event_Sink> sink_;

  /// Raw interface to the add-on.
  ::ATL::CComPtr <IMgaAddOn> addon_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Addon_Impl_T.inl"
#endif

#include "Addon_Impl_T.cpp"

#endif  // !defined _GME_RAW_COMPONENT_I_H_
