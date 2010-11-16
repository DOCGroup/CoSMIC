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

#ifndef _GAME_META_REFERENCE_H_
#define _GAME_META_REFERENCE_H_

#include <vector>
#include "MetaFCO.h"

namespace GAME
{
namespace Meta
{
/**
 * @class Reference
 */
class GAME_Export Reference : public FCO
{
public:
  /// Default constructor.
  Reference (void);

  Reference (const Reference & r);

  Reference (IMgaMetaReference * r);

  static Reference _narrow (const Base & b);

  /// Destructor.
  virtual ~Reference (void);

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

#if defined (__GAME_INLINE__)
#include "MetaReference.inl"
#endif

#endif  
