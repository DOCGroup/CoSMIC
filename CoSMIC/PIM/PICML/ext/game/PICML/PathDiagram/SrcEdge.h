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

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SrcEdge_Impl;
  typedef SrcEdge_Impl * SrcEdge_in;
  typedef ::GAME::Mga::Smart_Ptr <SrcEdge_Impl> SrcEdge;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    SrcEdge_Impl (void);

    /// Initializing constructor
    SrcEdge_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~SrcEdge_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static SrcEdge _create (const Path_in parent);
    ///@}

    /// Get the src Edge connection point.
    Edge src_Edge (void);

    /// Get the dst GraphVertex connection point.
    GraphVertex dst_GraphVertex (void);

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
