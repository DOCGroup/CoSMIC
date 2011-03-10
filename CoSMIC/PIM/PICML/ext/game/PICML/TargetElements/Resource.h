// -*- C++ -*-

//============================================================================
/**
 * @file    Resource.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TARGETELEMENTS_RESOURCE_H_
#define _PICML_TARGETELEMENTS_RESOURCE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Resource_Impl;
  typedef Resource_Impl * Resource_in;
  typedef ::GAME::Mga::Smart_Ptr <Resource_Impl> Resource;

  // Forward decl.
  class Visitor;

  class PICML_Export Resource_Impl :
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
    Resource_Impl (void);

    /// Initializing constructor
    Resource_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Resource_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Resource _create (const Bridge_in parent);
    static Resource _create (const Node_in parent);
    static Resource _create (const Interconnect_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    Bridge parent_Bridge (void) const;
    Node parent_Node (void) const;
    Interconnect parent_Interconnect (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
