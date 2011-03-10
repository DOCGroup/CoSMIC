// -*- C++ -*-

//============================================================================
/**
 * @file    DstEdge.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_DSTEDGE_H_
#define _PICML_PATHDIAGRAM_DSTEDGE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DstEdge_Impl;
  typedef DstEdge_Impl * DstEdge_in;
  typedef ::GAME::Mga::Smart_Ptr <DstEdge_Impl> DstEdge;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    DstEdge_Impl (void);

    /// Initializing constructor
    DstEdge_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~DstEdge_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static DstEdge _create (const Path_in parent);
    static DstEdge _create (const ConnectedComponent_in parent);
    ///@}

    /// Get the src GraphVertex connection point.
    GraphVertex src_GraphVertex (void);

    /// Get the dst Edge connection point.
    Edge dst_Edge (void);

    /**
     * @name Parent Methods
     */
    ///@{
    Path parent_Path (void) const;
    ConnectedComponent parent_ConnectedComponent (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
