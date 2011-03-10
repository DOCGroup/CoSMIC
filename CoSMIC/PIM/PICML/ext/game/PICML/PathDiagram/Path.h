// -*- C++ -*-

//============================================================================
/**
 * @file    Path.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_PATH_H_
#define _PICML_PATHDIAGRAM_PATH_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Path_Impl;
  typedef Path_Impl * Path_in;
  typedef ::GAME::Mga::Smart_Ptr <Path_Impl> Path;

  // Forward decl.
  class Visitor;

  class PICML_Export Path_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Path_Impl (void);

    /// Initializing constructor
    Path_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Path_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Path _create (const Paths_in parent);
    ///@}
    size_t in_PathProperty_connections (std::vector <PathProperty> & conns) const;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_SrcEdges (std::vector <SrcEdge> & items) const;
    size_t get_Edges (std::vector <Edge> & items) const;
    size_t get_EdgePropertys (std::vector <EdgeProperty> & items) const;
    size_t get_GraphVertexs (std::vector <GraphVertex> & items) const;
    size_t get_DstEdges (std::vector <DstEdge> & items) const;
    size_t get_Propertys (std::vector <Property> & items) const;
    size_t get_ComponentRefs (std::vector <ComponentRef> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    Paths parent_Paths (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
