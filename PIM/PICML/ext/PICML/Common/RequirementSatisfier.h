// -*- C++ -*-

//============================================================================
/**
 * @file    RequirementSatisfier.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_REQUIREMENTSATISFIER_H_
#define _PICML_COMMON_REQUIREMENTSATISFIER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequirementSatisfier_Impl;
  typedef RequirementSatisfier_Impl * RequirementSatisfier_in;
  typedef ::GAME::Mga::Smart_Ptr < RequirementSatisfier_Impl > RequirementSatisfier;

  /**
   * @class RequirementSatisfier_Impl
   *
   * Implementation for the RequirementSatisfier model element.
   */
  class PICML_Export RequirementSatisfier_Impl :
    public virtual ::GAME::Mga::Model_Impl
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

    // Default constructor.
    RequirementSatisfier_Impl (void);

    // Initializing constructor.
    RequirementSatisfier_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~RequirementSatisfier_Impl (void) = 0;

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
    size_t get_SatisfierPropertys (std::vector <SatisfierProperty> & items) const;
    ::GAME::Mga::Collection_T <SatisfierProperty> get_SatisfierPropertys (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "RequirementSatisfier.inl"
#endif

#endif  // !defined _PICML_COMMON_REQUIREMENTSATISFIER
