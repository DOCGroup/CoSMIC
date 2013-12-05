// -*- C++ -*-

//============================================================================
/**
 * @file    Key.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_KEY_H_
#define _PICML_NAMEDTYPES_KEY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Key_Impl;
  typedef Key_Impl * Key_in;
  typedef ::GAME::Mga::Smart_Ptr < Key_Impl > Key;

  // Forward decl.
  class Visitor;

  /**
   * @class Key_Impl
   *
   * Implementation for the Key model element.
   */
  class PICML_Export Key_Impl :
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
    static Key _create (const Aggregate_in parent);
    ///@}

    // Default constructor.
    Key_Impl (void);

    // Initializing constructor.
    Key_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~Key_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Aggregate parent_Aggregate (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src KeyMember connection.
    size_t src_KeyMember (std::vector <KeyMember> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Key.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_KEY
