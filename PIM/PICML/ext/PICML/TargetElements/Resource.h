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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/Common/RequirementSatisfier.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Resource_Impl;
  typedef Resource_Impl * Resource_in;
  typedef ::GAME::Mga::Smart_Ptr < Resource_Impl > Resource;

  // Forward decl.
  class Visitor;

  /**
   * @class Resource_Impl
   *
   * Implementation for the Resource model element.
   */
  class PICML_Export Resource_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual RequirementSatisfier_Impl
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
    static Resource _create (const Interconnect_in parent);
    static Resource _create (const Bridge_in parent);
    static Resource _create (const Node_in parent);
    ///@}

    // Default constructor.
    Resource_Impl (void);

    // Initializing constructor.
    Resource_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Resource_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Interconnect parent_Interconnect (void);
    Bridge parent_Bridge (void);
    Node parent_Node (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Resource.inl"
#endif

#endif  // !defined _PICML_TARGETELEMENTS_RESOURCE
