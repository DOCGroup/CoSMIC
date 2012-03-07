// -*- C++ -*-

//============================================================================
/**
 * @file    GraphVertex.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_GRAPHVERTEX_H_
#define _PICML_PATHDIAGRAM_GRAPHVERTEX_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class GraphVertex_Impl;
  typedef GraphVertex_Impl * GraphVertex_in;
  typedef ::GAME::Mga::Smart_Ptr < GraphVertex_Impl > GraphVertex;

  /**
   * @class GraphVertex_Impl
   *
   * Implementation for the GraphVertex model element.
   */
  class PICML_Export GraphVertex_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    GraphVertex_Impl (void);

    // Initializing constructor.
    GraphVertex_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~GraphVertex_Impl (void) = 0;

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src DstEdge connection.
    size_t src_DstEdge (std::vector <DstEdge> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst SrcEdge connection.
    size_t dst_SrcEdge (std::vector <SrcEdge> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "GraphVertex.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_GRAPHVERTEX
