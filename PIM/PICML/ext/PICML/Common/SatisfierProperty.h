// -*- C++ -*-

//============================================================================
/**
 * @file    SatisfierProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_SATISFIERPROPERTY_H_
#define _PICML_COMMON_SATISFIERPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SatisfierProperty_Impl;
  typedef SatisfierProperty_Impl * SatisfierProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < SatisfierProperty_Impl > SatisfierProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class SatisfierProperty_Impl
   *
   * Implementation for the SatisfierProperty model element.
   */
  class PICML_Export SatisfierProperty_Impl :
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

    /**
     * @name Factory Methods
     */
    ///@{
    static SatisfierProperty _create (const RequirementSatisfier_in parent);
    ///@}

    // Default constructor.
    SatisfierProperty_Impl (void);

    // Initializing constructor.
    SatisfierProperty_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~SatisfierProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RequirementSatisfier parent_RequirementSatisfier (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of SatisfierPropertyKind
    void SatisfierPropertyKind (const std::string & val);

    /// Get the value of SatisfierPropertyKind
    std::string SatisfierPropertyKind (void) const;

    /// Set the value of DataValue
    void DataValue (const std::string & val);

    /// Get the value of DataValue
    std::string DataValue (void) const;

    /// Set the value of dynamic
    void dynamic (bool val);

    /// Get the value of dynamic
    bool dynamic (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_DataType (void) const;
    DataType get_DataType (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SatisfierProperty.inl"
#endif

#endif  // !defined _PICML_COMMON_SATISFIERPROPERTY
