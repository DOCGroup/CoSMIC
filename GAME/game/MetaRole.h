// -*- C++ -*-

//=============================================================================
/**
 * @file        MetaRole.h
 *
 * Defines the GAME::Meta::Role_Impl class
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_METAROLE_H_
#define _GME_METAROLE_H_

#include "MetaBase.h"

namespace GAME
{
namespace Meta
{

/**
 * @class Role_Impl
 *
 * Wrapper class for the IMgaMetaRole interface.
 */
class GAME_Export Role_Impl : public Base_Impl
{
public:
  /// Type definition of the COM interface.
  typedef IMgaMetaRole interface_type;

  /// Default constructor.
  Role_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     role        Pointer to a COM interface.
   */
  Role_Impl (IMgaMetaRole * role);

  /// Destructor.
  virtual ~Role_Impl (void);

  /**
   * Get the meta FCO for the role.
   *
   * @return          The meta FCO of the role.
   */
  FCO kind (void) const;

  /**
   * Get a raw pointer to the underlying COM object.
   *
   * @return        Pointer to the raw COM object.
   */
  IMgaMetaRole * impl (void) const;

  /**
   * Get the parent model of the role.
   *
   * @return        Parent model of the role.
   */
  Model parent (void) const;

private:
  /// Pointer to the COM object.
  mutable ATL::CComPtr <IMgaMetaRole> metarole_;
};

}
}

#if defined (__GAME_INLINE__)
#include "MetaRole.inl"
#endif

#endif  // !defined _GME_METAROLE_H_
