// -*- C++ -*-

//=============================================================================
/**
 * @file      Atom_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_ATOM_H_
#define _GME_ATOM_H_

#include "FCO.h"

namespace GAME
{
/**
 * @class Atom_Impl
 *
 * Wrapper class for the IMgaAtom interface.
 */
class GAME_Export Atom_Impl : public FCO_Impl
{
public:
  /// Type definition for the interface.
  typedef IMgaAtom interface_type;

  /**
   * Create a new atom element.
   *
   * @param[in]       role          The role of the new object, i.e.,
   *                                its meta name.
   * @param[in]       parent        The parent model.
   * @return          The newly created atom.
   */
  static Atom _create (const Model_in parent, const std::string & type);
  static Atom _create (const Model_in parent, const Meta::Role_in type);

  static Atom _create (const Folder_in parent, const std::string & type);
  static Atom _create (const Folder_in parent, const Meta::FCO_in type);

  /// Default constructor.
  Atom_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       atom        Pointer to the atom.
   */
  Atom_Impl (IMgaAtom * atom);

  /// Destructor.
  virtual ~Atom_Impl (void);

  /**
   * Attach to an existing atom.
   *
   * @param[in]       atom        The source interface.
   */
  void attach (IMgaAtom * atom);

  virtual void accept (Visitor * v);

  /// Get the meta information for this atom.
  Meta::Atom meta (void) const;

protected:
  /// Helper method to get the correct implementation.
  IMgaAtom * impl (void) const;

  /// The underlying interface pointer.
  mutable ATL::CComPtr <IMgaAtom> atom_;
};
}

#if defined (__GAME_INLINE__)
#include "Atom.inl"
#endif

#endif
