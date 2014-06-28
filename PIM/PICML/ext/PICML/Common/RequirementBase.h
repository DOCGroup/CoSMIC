// -*- C++ -*-

//============================================================================
/**
 * @file    RequirementBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_REQUIREMENTBASE_H_
#define _PICML_COMMON_REQUIREMENTBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequirementBase_Impl;
  typedef RequirementBase_Impl * RequirementBase_in;
  typedef ::GAME::Mga::Smart_Ptr < RequirementBase_Impl > RequirementBase;

  /**
   * @class RequirementBase_Impl
   *
   * Implementation for the RequirementBase model element.
   */
  class PICML_Export RequirementBase_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    RequirementBase_Impl (void);

    // Initializing constructor.
    RequirementBase_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~RequirementBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of resourceType
    void resourceType (const std::string & val);

    /// Get the value of resourceType
    std::string resourceType (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "RequirementBase.inl"
#endif

#endif  // !defined _PICML_COMMON_REQUIREMENTBASE
