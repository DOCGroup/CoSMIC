// -*- C++ -*-

//============================================================================
/**
 * @file    DisplayNode.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_DISPLAYNODE_H_
#define _PICML_PATHDIAGRAM_DISPLAYNODE_H_

#include "game/mga/Atom.h"
#include "PICML/PathDiagram/GraphVertex.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DisplayNode_Impl;
  typedef DisplayNode_Impl * DisplayNode_in;
  typedef ::GAME::Mga::Smart_Ptr <DisplayNode_Impl> DisplayNode;

  // Forward decl.
  class Visitor;

  class PICML_Export DisplayNode_Impl :
    public virtual GraphVertex_Impl,
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
    DisplayNode_Impl (void);

    /// Initializing constructor
    DisplayNode_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~DisplayNode_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
