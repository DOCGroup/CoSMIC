// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaSet.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_META_SET_H_
#define _GAME_MGA_META_SET_H_

#include <vector>
#include "MetaFCO.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

/**
 * @class Set_Impl
 */
class GAME_MGA_Export Set_Impl : public FCO_Impl
{
public:
  typedef IMgaMetaSet interface_type;

  /// Default constructor.
  Set_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       r       Pointer to reference.
   */
  Set_Impl (IMgaMetaSet * set);

  /// Destructor.
  virtual ~Set_Impl (void);

  /**
   * Get the valid target FCOs for this reference.
   *
   * @param[out]          fcos      Target FCOs.
   */
  size_t members (std::vector <FCO> & fcos);

  IMgaMetaSet * impl (void) const;

private:
  mutable ATL::CComPtr <IMgaMetaSet> set_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaSet.inl"
#endif

#endif
