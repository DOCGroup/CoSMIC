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

#ifndef _GAME_MGA_META_BASE_H_
#define _GAME_MGA_META_BASE_H_

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
 * @class Base_Impl
 *
 * Wrapper class for the IMgaMetaBase interface.
 */
class GAME_MGA_Export Base_Impl : public Refcountable
{
public:
  /// Type definition of the interface type.
  typedef IMgaMetaBase interface_type;

  /// Default constructor.
  Base_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       meta        Pointer to the source interface.
   */
  Base_Impl (IMgaMetaBase * meta);

  /// Destructor.
  virtual ~Base_Impl (void);

  /**
   * Get the actual meta name.
   *
   * @return          The name of the meta object.
   */
  std::string name (void) const;

  /**
   * Set the actual meta name.
   *
   * @param[in]       name      The name of the meta object.
   */
  void name (const std::string & name);

  /**
   * Get the displayed name for the meta.
   *
   * @return          The displayed name.
   */
  std::string display_name (void) const;

  /**
   * Set the displayed meta name.
   *
   * @param[in]       name      The name of the meta object.
   */
  void display_name (const std::string & name);

  /**
   * Attach to an existing interface.
   *
   * @param[in]       meta        Pointer to the source object.
   */
  void attach (IMgaMetaBase * meta);

  /**
   * Get the meta reference id.
   *
   * @return          The reference id.
   */
  long refid (void) const;

  /**
   * Set the meta reference id.
   *
   * @param[in]       refid       The reference id.
   */
  void refid (long refid);

  /**
   * Get all the constraints.
   *
   * @param[out]       cons        The vector holds all the constraints
   */
  size_t constraints (std::vector <Constraint> & cons) const;

  /**
   * Get the object type of the meta information.
   *
   * @return          The object type.
   */
  objtype_enum type (void) const;

  /// Delete the meta object.
  void destroy (void);

  /**
   * Get the specified registry value.
   *
   * @param[in]       path      The target path.
   * @return          The registry value of \a path.
   */
  std::string registry_value (const std::string & path) const;

  /**
   * Set the specified registry value.
   *
   * @param[in]       path      The target path.
   * @param[in]       value     The new value.
   */
  void registry_value (const std::string & path, const std::string & value);

  /**
   * Get a pointer to the implementation.
   *
   * @return          Pointer to the implementation.
   */
  IMgaMetaBase * impl (void) const;

  /// Release the underlying pointer.
  void release (void);

  /// Get the parent project for this object.
  Project project (void) const;

  /// Get the hash value for the object.
  unsigned long hash (void) const;

  /// Test the equality with this implementation.
  bool is_equal_to (const Base_Impl * impl) const;

protected:
  /// The underlying interface pointer.
  mutable ATL::CComPtr <IMgaMetaBase> metabase_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaBase.inl"
#endif

#endif  // !defined _GAME_MGA_META_BASE_H_
