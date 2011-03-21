// -*- C++ -*-

//=============================================================================
/**
 * @file      Set_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_SET_H_
#define _GAME_MGA_SET_H_

#include "FCO.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Set_Impl
 *
 * Wrapper class for the IMgaSet interface.
 */
class GAME_MGA_Export Set_Impl : public virtual FCO_Impl
{
public:
  /// Type definition for the interface pointer.
  typedef IMgaSet interface_type;

  /// Type definition of the type tag.
  typedef set_tag_t type_tag;

  /**
   * Create a new set element.
   *
   * @param[in]       role          The role of the new object, i.e.,
   *                                its meta name.
   * @param[in]       parent        The parent model.
   * @return          The newly created set.
   */
  static Set _create (const Model_in parent, const std::string & type);
  static Set _create (const Model_in parent, const Meta::Role_in role);

  /// Default constructor.
  Set_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       set       The source interface.
   */
  Set_Impl (IMgaSet * set);

  /// Destructor.
  virtual ~Set_Impl (void);

  /**
   * Attach to an existing set.
   *
   * @param[in]       set       The existing set.
   */
  void attach (IMgaSet * set);

  /**
   * Insert an FCO into the set.
   *
   * @param[in]     fco       The source FCO object.
   */
  void insert (const FCO_in fco);

  /**
   * Remove an FCO from the set.
   *
   * @param[in]     fco       The source FCO object.
   */
  void remove (const FCO_in fco);

  /**
   * Determine if the set contains a specific FCO object.
   *
   * @retval        true      The set contains the object.
   * @retval        false     The set does not contain the object.
   */
  bool contains (const FCO_in fco);

  /// Clear all the objects from the set.
  void clear (void);

  /**
   * Get all the objects in the set.
   *
   * @param[out]    members       Collection of objects in the set.
   * @return        Number of elements in \a members.
   */
  size_t members (std::vector <FCO> & members) const;

  /// Accept the visitor.
  virtual void accept (Visitor * v);

  /// Get the meta information for this object.
  Meta::Set meta (void) const;

protected:
  /// Helper method for getting the correct implemenation.
  IMgaSet * impl (void) const;

  /// The underlying COM interface pointer.
  mutable ATL::CComPtr <IMgaSet> set_;
};

/**
 * @struct object_type_t
 *
 * Specialization of the object type for Atom_Impl.
 */
template < >
struct object_type_t <Set_Impl>
{
  static const int result_type = OBJTYPE_SET;
};

}
}

#if defined (__GAME_INLINE__)
#include "Set.inl"
#endif

#endif  // !defined _GME_SET_H_
