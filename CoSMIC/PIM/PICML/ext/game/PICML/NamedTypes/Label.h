// -*- C++ -*-

//============================================================================
/**
 * @file    Label.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_LABEL_H_
#define _PICML_NAMEDTYPES_LABEL_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Label_Impl;
  typedef Label_Impl * Label_in;
  typedef ::GAME::Mga::Smart_Ptr <Label_Impl> Label;

  // Forward decl.
  class Visitor;

  class PICML_Export Label_Impl :
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
    Label_Impl (void);

    /// Initializing constructor
    Label_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~Label_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Label _create (const SwitchedAggregate_in parent);
    ///@}
    size_t in_LabelConnection_connections (std::vector <LabelConnection> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    SwitchedAggregate parent_SwitchedAggregate (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
