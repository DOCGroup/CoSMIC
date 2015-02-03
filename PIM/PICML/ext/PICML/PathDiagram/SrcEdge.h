// -*- C++ -*-

//============================================================================
/**
 * @file    SrcEdge.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_SRCEDGE_H_
#define _PICML_PATHDIAGRAM_SRCEDGE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SrcEdge_Impl;
  typedef SrcEdge_Impl * SrcEdge_in;
  typedef ::GAME::Mga::Smart_Ptr < SrcEdge_Impl > SrcEdge;

  // Forward decl.
  class Visitor;

  /**
   * @class SrcEdge_Impl
   *
   * Implementation for the SrcEdge model element.
   */
  class PICML_Export SrcEdge_Impl :
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
    static SrcEdge _create (const Path_in parent, Edge_in src, GraphVertex_in dst);
    ///@}

    // Default constructor.
    SrcEdge_Impl (void);

    // Initializing constructor.
    SrcEdge_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~SrcEdge_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Path parent_Path (void);
    ///@}
    Edge src_Edge (void) const;
    GraphVertex dst_GraphVertex (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "SrcEdge.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_SRCEDGE
