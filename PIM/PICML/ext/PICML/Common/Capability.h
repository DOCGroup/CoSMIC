// -*- C++ -*-

//============================================================================
/**
 * @file    Capability.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_CAPABILITY_H_
#define _PICML_COMMON_CAPABILITY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/Common/RequirementSatisfier.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Capability_Impl;
  typedef Capability_Impl * Capability_in;
  typedef ::GAME::Mga::Smart_Ptr < Capability_Impl > Capability;

  // Forward decl.
  class Visitor;

  /**
   * @class Capability_Impl
   *
   * Implementation for the Capability model element.
   */
  class PICML_Export Capability_Impl :
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


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Capability _create (const ComponentImplementationContainer_in parent);
    ///@}

    // Default constructor.
    Capability_Impl (void);

    // Initializing constructor.
    Capability_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Capability_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentImplementationContainer parent_ComponentImplementationContainer (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ImplementationCapability connection.
    size_t dst_of_ImplementationCapability (std::vector <ImplementationCapability> & items) const;
    GAME::Mga::Collection_T <ImplementationCapability> dst_of_ImplementationCapability (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Capability.inl"
#endif

#endif  // !defined _PICML_COMMON_CAPABILITY
