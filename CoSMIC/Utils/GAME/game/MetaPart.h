// -*- C++ -*-

//=============================================================================
/**
 * @file        MetaRole.h
 *
 * Defines the GAME::Meta::Role class
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_METAPART_H_
#define _GME_METAPART_H_

#include "MetaRole.h"

namespace GAME
{
namespace Meta
{
/**
 * @class Part
 *
 * Wrapper class for the IMgaMetaPart interface.
 */
class GAME_Export Part : public Base
{
public:
  /// Type definition of the COM interface.
  typedef IMgaMetaPart interface_type;

  /// Default constructor.
  Part (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     role        Pointer to a COM interface.
   */
  Part (IMgaMetaPart * role);

  /**
   * Copy constructor.
   *
   * @param[in]     role        The source object.
   */
  Part (const Part & part);

  /// Destructor.
  virtual ~Part (void);

  /**
   * Assignment operator.
   *
   * @param[in]       role      The source role.
   * @return          Reference to self.
   */
  const Part & operator = (const Part & role);

  /**
   * Get the meta FCO for the role.
   *
   * @return          The meta FCO of the role.
   */
  std::string kind (void) const;

  /**
   * Get a raw pointer to the underlying COM object.
   *
   * @return        Pointer to the raw COM object.
   */
  IMgaMetaPart * impl (void) const;

  bool is_linked (void) const;

  bool is_primary (void) const;

  /**
   * Get the role for the part.
   */
  Role role (void) const;

  // Aspect parent (void) const;

private:
  /// Pointer to the COM object.
  mutable ATL::CComPtr <IMgaMetaPart> part_;
};
}
}

#if defined (__GAME_INLINE__)
#include "MetaPart.inl"
#endif

#endif  // !defined _GME_METAROLE_H_
