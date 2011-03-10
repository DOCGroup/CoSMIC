// -*- C++ -*-

//============================================================================
/**
 * @file    Edge.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_EDGE_H_
#define _PICML_PATHDIAGRAM_EDGE_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Edge_Impl;
  typedef Edge_Impl * Edge_in;
  typedef ::GAME::Mga::Smart_Ptr <Edge_Impl> Edge;

  // Forward decl.
  class Visitor;

  class PICML_Export Edge_Impl :
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
    Edge_Impl (void);

    /// Initializing constructor
    Edge_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~Edge_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Edge _create (const Path_in parent);
    ///@}
    size_t in_SrcEdge_connections (std::vector <SrcEdge> & conns) const;
    size_t in_EdgeProperty_connections (std::vector <EdgeProperty> & conns) const;
    size_t in_DstEdge_connections (std::vector <DstEdge> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    Path parent_Path (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
