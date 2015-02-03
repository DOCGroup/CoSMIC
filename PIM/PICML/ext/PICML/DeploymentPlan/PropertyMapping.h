// -*- C++ -*-

//============================================================================
/**
 * @file    PropertyMapping.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_PROPERTYMAPPING_H_
#define _PICML_DEPLOYMENTPLAN_PROPERTYMAPPING_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PropertyMapping_Impl;
  typedef PropertyMapping_Impl * PropertyMapping_in;
  typedef ::GAME::Mga::Smart_Ptr < PropertyMapping_Impl > PropertyMapping;

  // Forward decl.
  class Visitor;

  /**
   * @class PropertyMapping_Impl
   *
   * Implementation for the PropertyMapping model element.
   */
  class PICML_Export PropertyMapping_Impl :
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
    static PropertyMapping _create (const DeploymentPlan_in parent, NodeReference_in src, Property_in dst);
    ///@}

    // Default constructor.
    PropertyMapping_Impl (void);

    // Initializing constructor.
    PropertyMapping_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PropertyMapping_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DeploymentPlan parent_DeploymentPlan (void);
    ///@}
    NodeReference src_NodeReference (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "PropertyMapping.inl"
#endif

#endif  // !defined _PICML_DEPLOYMENTPLAN_PROPERTYMAPPING
