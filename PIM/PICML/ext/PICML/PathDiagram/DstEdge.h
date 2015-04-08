// -*- C++ -*-

//============================================================================
/**
 * @file    DstEdge.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_DSTEDGE_H_
#define _PICML_PATHDIAGRAM_DSTEDGE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DstEdge_Impl;
  typedef DstEdge_Impl * DstEdge_in;
  typedef ::GAME::Mga::Smart_Ptr < DstEdge_Impl > DstEdge;

  // Forward decl.
  class Visitor;

  /**
   * @class DstEdge_Impl
   *
   * Implementation for the DstEdge model element.
   */
  class PICML_Export DstEdge_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static DstEdge _create (const ConnectedComponent_in parent, GraphVertex_in src, Edge_in dst);
    static DstEdge _create (const Path_in parent, GraphVertex_in src, Edge_in dst);
    ///@}

    // Default constructor.
    DstEdge_Impl (void);

    // Initializing constructor.
    DstEdge_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~DstEdge_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectedComponent parent_ConnectedComponent (void);
    Path parent_Path (void);
    ///@}
    GraphVertex src_GraphVertex (void) const;
    Edge dst_Edge (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "DstEdge.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_DSTEDGE
