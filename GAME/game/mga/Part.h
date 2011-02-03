// -*- C++ -*-

//=============================================================================
/**
 * @file        MetaRole.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_PART_H_
#define _GAME_MGA_PART_H_

#include "MetaRole.h"
#include "MetaPart.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Part
 *
 * Wrapper class for the IMgaMetaPart interface.
 */
class GAME_MGA_Export Part
{
public:
  /// Type definition of the COM interface.
  typedef IMgaPart interface_type;

  /// Default constructor.
  Part (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     role        Pointer to a COM interface.
   */
  Part (IMgaPart * part);

  /**
   * Copy constructor.
   *
   * @param[in]     role        The source object.
   */
  Part (const Part & part);

  /// Destructor.
  ~Part (void);

  /**
   * Assignment operator.
   *
   * @param[in]       role      The source role.
   * @return          Reference to self.
   */
  const Part & operator = (const Part & role);

  /// Get the meta information for this object.
  GAME::Mga::Meta::Part meta (void) const;

  /// Get a pointer the underlying interface.
  IMgaPart * impl (void) const;

  /// Test if the object is nil.
  bool is_nil (void) const;

  void get_location (long & x, long & y);
  void set_location (long x, long y);

private:
  /// Pointer to the COM object.
  mutable ATL::CComPtr <IMgaPart> part_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Part.inl"
#endif

#endif  // !defined _GME_METAROLE_H_
