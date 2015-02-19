// -*- C++ -*-

//============================================================================
/**
 * @file    RTRequirements.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_REALTIMEREQUIREMENTS_RTREQUIREMENTS_H_
#define _PICML_REALTIMEREQUIREMENTS_RTREQUIREMENTS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/Common/Requirement.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RTRequirements_Impl;
  typedef RTRequirements_Impl * RTRequirements_in;
  typedef ::GAME::Mga::Smart_Ptr < RTRequirements_Impl > RTRequirements;

  // Forward decl.
  class Visitor;

  /**
   * @class RTRequirements_Impl
   *
   * Implementation for the RTRequirements model element.
   */
  class PICML_Export RTRequirements_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual Requirement_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static RTRequirements _create (const ComponentAssembly_in parent);
    static RTRequirements _create (const ArtifactContainer_in parent);
    static RTRequirements _create (const PackageConfigurationContainer_in parent);
    ///@}

    // Default constructor.
    RTRequirements_Impl (void);

    // Initializing constructor.
    RTRequirements_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~RTRequirements_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ServiceConsumer (void) const;
    ServiceConsumer get_ServiceConsumer (void) const;

    bool has_ServiceProvider (void) const;
    ServiceProvider get_ServiceProvider (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "RTRequirements.inl"
#endif

#endif  // !defined _PICML_REALTIMEREQUIREMENTS_RTREQUIREMENTS
