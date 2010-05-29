// -*- C++ -*-

//=============================================================================
/**
 * @file      Atom.h
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
   * @class Atom
   *
   * Wrapper class for the IMgaAtom interface.
   */
  class GAME_Export Atom : public FCO
  {
  public:
    /// Type definition for the interface.
    typedef IMgaAtom interface_type;

    /**
     * Convert a FCO into an atom.
     *
     * @param[in]       fco           The source FCO object.
     * @return          The atom object.
     */
    static Atom _narrow (const GAME::Object & object);

    /**
     * Create a new atom element.
     *
     * @param[in]       role          The role of the new object, i.e.,
     *                                its meta name.
     * @param[in]       parent        The parent model.
     * @return          The newly created atom.
     */
    static Atom _create (Model & parent, const std::string & type);
    static Atom _create (Model & parent, const Meta::Role & type);

    static Atom _create (Folder & parent, const std::string & type);
    static Atom _create (Folder & parent, const Meta::FCO & type);

    /// Default constructor.
    Atom (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       atom        Pointer to the atom.
     */
    Atom (IMgaAtom * atom);

    /**
     * Copy constructor.
     *
     * @param[in]       atom        The source object.
     */
    Atom (const Atom & atom);

    /// Destructor.
    virtual ~Atom (void);

    /**
     * Assignment operator.
     *
     * @param[in]       atom        The source object.
     * @return          Reference to this object.
     */
    const Atom & operator = (const Atom & atom);

    /**
     * Attach to an existing atom.
     *
     * @param[in]       atom        The source interface.
     */
    void attach (IMgaAtom * atom);

    virtual void accept (GAME::Visitor & visitor);

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
