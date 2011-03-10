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

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class GraphVertex_Impl;
  typedef GraphVertex_Impl * GraphVertex_in;
  typedef ::GAME::Mga::Smart_Ptr <GraphVertex_Impl> GraphVertex;

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

    /// Default constructor
    GraphVertex_Impl (void);

    /// Initializing constructor
    GraphVertex_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~GraphVertex_Impl (void) = 0;
    size_t in_DstEdge_connections (std::vector <DstEdge> & conns) const;
    size_t in_SrcEdge_connections (std::vector <SrcEdge> & conns) const;

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
