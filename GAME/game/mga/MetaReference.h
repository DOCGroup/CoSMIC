// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaBase.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_META_REFERENCE_H_
#define _GAME_MGA_META_REFERENCE_H_

#include <vector>
#include "MetaFCO.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

/**
 * @class Reference_Impl
 */
class GAME_MGA_Export Reference_Impl : public FCO_Impl
{
public:
  typedef IMgaMetaReference interface_type;

  /// Default constructor.
  Reference_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       r       Pointer to reference.
   */
  Reference_Impl (IMgaMetaReference * r);

  /// Destructor.
  virtual ~Reference_Impl (void);

  /**
   * Get the valid target FCOs for this reference.
   *
   * @param[out]          fcos      Target FCOs.
   */
  size_t targets (std::vector <FCO> & fcos);

  IMgaMetaReference * impl (void) const;

private:
  mutable ATL::CComPtr <IMgaMetaReference> ref_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaReference.inl"
#endif

#endif
