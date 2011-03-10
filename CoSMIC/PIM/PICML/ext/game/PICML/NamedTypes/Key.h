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

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Key_Impl;
  typedef Key_Impl * Key_in;
  typedef ::GAME::Mga::Smart_Ptr <Key_Impl> Key;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    Key_Impl (void);

    /// Initializing constructor
    Key_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~Key_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Key _create (const Aggregate_in parent);
    ///@}
    size_t in_KeyMember_connections (std::vector <KeyMember> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    Aggregate parent_Aggregate (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
