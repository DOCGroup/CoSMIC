// -*- C++ -*-

//============================================================================
/**
 * @file    Edge.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_EDGE_H_
#define _PICML_PATHDIAGRAM_EDGE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Edge_Impl;
  typedef Edge_Impl * Edge_in;
  typedef ::GAME::Mga::Smart_Ptr < Edge_Impl > Edge;

  // Forward decl.
  class Visitor;

  /**
   * @class Edge_Impl
   *
   * Implementation for the Edge model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Edge _create (const Path_in parent);
    ///@}

    // Default constructor.
    Edge_Impl (void);

    // Initializing constructor.
    Edge_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~Edge_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Path parent_Path (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src SrcEdge connection.
    size_t src_of_SrcEdge (std::vector <SrcEdge> & items) const;
    bool has_src_of_SrcEdge (void) const;
    SrcEdge src_of_SrcEdge (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst DstEdge connection.
    size_t dst_of_DstEdge (std::vector <DstEdge> & items) const;
    bool has_dst_of_DstEdge (void) const;
    DstEdge dst_of_DstEdge (void) const;

    /// Get the dst EdgeProperty connection.
    size_t dst_of_EdgeProperty (std::vector <EdgeProperty> & items) const;
    bool has_dst_of_EdgeProperty (void) const;
    EdgeProperty dst_of_EdgeProperty (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Edge.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_EDGE
