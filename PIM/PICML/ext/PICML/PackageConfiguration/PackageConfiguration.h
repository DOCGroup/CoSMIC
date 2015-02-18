// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfiguration.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATION_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfiguration_Impl;
  typedef PackageConfiguration_Impl * PackageConfiguration_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageConfiguration_Impl > PackageConfiguration;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageConfiguration_Impl
   *
   * Implementation for the PackageConfiguration model element.
   */
  class PICML_Export PackageConfiguration_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfiguration _create (const PackageConfigurationContainer_in parent);
    ///@}

    // Default constructor.
    PackageConfiguration_Impl (void);

    // Initializing constructor.
    PackageConfiguration_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~PackageConfiguration_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageConfigurationContainer parent_PackageConfigurationContainer (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of UUID
    void UUID (const std::string & val);

    /// Get the value of UUID
    std::string UUID (void) const;

    /// Set the value of label
    void label (const std::string & val);

    /// Get the value of label
    std::string label (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src PackageConfReference connection.
    size_t src_of_PackageConfReference (std::vector <PackageConfReference> & items) const;
    GAME::Mga::Collection_T <PackageConfReference> src_of_PackageConfReference (void) const;

    /// Get the src PackageConfBasePackage connection.
    size_t src_of_PackageConfBasePackage (std::vector <PackageConfBasePackage> & items) const;
    GAME::Mga::Collection_T <PackageConfBasePackage> src_of_PackageConfBasePackage (void) const;

    /// Get the src PackageConfConfigProperty connection.
    size_t src_of_PackageConfConfigProperty (std::vector <PackageConfConfigProperty> & items) const;
    GAME::Mga::Collection_T <PackageConfConfigProperty> src_of_PackageConfConfigProperty (void) const;

    /// Get the src PackageConfSpecializedConfig connection.
    size_t src_of_PackageConfSpecializedConfig (std::vector <PackageConfSpecializedConfig> & items) const;
    GAME::Mga::Collection_T <PackageConfSpecializedConfig> src_of_PackageConfSpecializedConfig (void) const;

    /// Get the src PackageConfSelectRequirement connection.
    size_t src_of_PackageConfSelectRequirement (std::vector <PackageConfSelectRequirement> & items) const;
    GAME::Mga::Collection_T <PackageConfSelectRequirement> src_of_PackageConfSelectRequirement (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PackageConfiguration.inl"
#endif

#endif  // !defined _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATION
