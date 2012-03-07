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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Path_Impl;
  typedef Path_Impl * Path_in;
  typedef ::GAME::Mga::Smart_Ptr < Path_Impl > Path;

  // Forward decl.
  class Visitor;

  /**
   * @class Path_Impl
   *
   * Implementation for the Path model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static Path _create (const Paths_in parent);
    ///@}

    // Default constructor.
    Path_Impl (void);

    // Initializing constructor.
    Path_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Path_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src PathProperty connection.
    size_t src_PathProperty (std::vector <PathProperty> & items) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ComponentRefs (std::vector <ComponentRef> & items) const;
    ::GAME::Mga::Iterator <ComponentRef> get_ComponentRefs (void) const;

    size_t get_Propertys (std::vector <Property> & items) const;
    ::GAME::Mga::Iterator <Property> get_Propertys (void) const;

    size_t get_DstEdges (std::vector <DstEdge> & items) const;
    ::GAME::Mga::Iterator <DstEdge> get_DstEdges (void) const;

    size_t get_GraphVertexs (std::vector <GraphVertex> & items) const;
    ::GAME::Mga::Iterator <GraphVertex> get_GraphVertexs (void) const;

    size_t get_SrcEdges (std::vector <SrcEdge> & items) const;
    ::GAME::Mga::Iterator <SrcEdge> get_SrcEdges (void) const;

    size_t get_EdgePropertys (std::vector <EdgeProperty> & items) const;
    ::GAME::Mga::Iterator <EdgeProperty> get_EdgePropertys (void) const;

    size_t get_Edges (std::vector <Edge> & items) const;
    ::GAME::Mga::Iterator <Edge> get_Edges (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Path.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_PATH
