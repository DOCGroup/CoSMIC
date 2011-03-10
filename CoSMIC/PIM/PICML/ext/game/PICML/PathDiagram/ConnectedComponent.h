// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectedComponent.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_CONNECTEDCOMPONENT_H_
#define _PICML_PATHDIAGRAM_CONNECTEDCOMPONENT_H_

#include "game/mga/Model.h"
#include "PICML/PathDiagram/GraphVertex.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectedComponent_Impl;
  typedef ConnectedComponent_Impl * ConnectedComponent_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectedComponent_Impl> ConnectedComponent;

  // Forward decl.
  class Visitor;

  class PICML_Export ConnectedComponent_Impl :
    public virtual GraphVertex_Impl,
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
    ConnectedComponent_Impl (void);

    /// Initializing constructor
    ConnectedComponent_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ConnectedComponent_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Ports (std::vector <Port> & items) const;
    size_t get_DstEdges (std::vector <DstEdge> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
