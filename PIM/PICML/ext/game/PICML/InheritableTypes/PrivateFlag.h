// -*- C++ -*-

//============================================================================
/**
 * @file    PrivateFlag.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_PRIVATEFLAG_H_
#define _PICML_INHERITABLETYPES_PRIVATEFLAG_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PrivateFlag_Impl;
  typedef PrivateFlag_Impl * PrivateFlag_in;
  typedef ::GAME::Mga::Smart_Ptr < PrivateFlag_Impl > PrivateFlag;

  // Forward decl.
  class Visitor;

  /**
   * @class PrivateFlag_Impl
   *
   * Implementation for the PrivateFlag model element.
   */
  class PICML_Export PrivateFlag_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static PrivateFlag _create (const ObjectByValue_in parent);
    ///@}

    // Default constructor.
    PrivateFlag_Impl (void);

    // Initializing constructor.
    PrivateFlag_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~PrivateFlag_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ObjectByValue parent_ObjectByValue (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst MakeMemberPrivate connection.
    size_t dst_MakeMemberPrivate (std::vector <MakeMemberPrivate> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PrivateFlag.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_PRIVATEFLAG
