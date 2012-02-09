// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaConstraint.h
 *
 * $Id$
 *
 * @author    Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MGA_META_CONSTRAINT_H_
#define _GAME_MGA_META_CONSTRAINT_H_

#include <string>
#include "Refcountable.h"

#include "GME_fwd.h"
#include "game/config.h"
#include "Mga_export.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

/**
 * @class Constraint_Impl
 *
 * Wrapper class for the IMgaConstraint interface.
 */
class GAME_MGA_Export Constraint_Impl : public Refcountable
{
public:
  /// Type definition of the interface type.
  typedef IMgaConstraint interface_type;

  /// Default constructor.
  Constraint_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       meta        Pointer to the source interface.
   */
  Constraint_Impl (IMgaConstraint * meta);

  /// Destructor.
  virtual ~Constraint_Impl (void);

  /**
   * Get the actual meta name.
   *
   * @return          The name of the constraint.
   */
  std::string name (void) const;

   /**
   * Get the actual expression.
   *
   * @return          The constraint expression.
   */
  std::string expression (void) const;

   /**
   * Attach to an existing interface.
   *
   * @param[in]       meta        Pointer to the source object.
   */
  void attach (IMgaConstraint * meta);

  /**
   * Get a pointer to the implementation.
   *
   * @return          Pointer to the implementation.
   */
  IMgaConstraint * impl (void) const;

  /// Release the underlying pointer.
  void release (void);

protected:
  /// The underlying interface pointer.
  mutable ATL::CComPtr <IMgaConstraint> metaconst_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaConstraint.inl"
#endif

#endif  // !defined _GAME_MGA_META_CONSTRAINT_H_

