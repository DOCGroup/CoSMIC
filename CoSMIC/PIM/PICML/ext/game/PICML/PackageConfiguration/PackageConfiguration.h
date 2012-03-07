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

    /// Get the src PackageConfBasePackage connection.
    size_t src_PackageConfBasePackage (std::vector <PackageConfBasePackage> & items) const;

    /// Get the src PackageConfReference connection.
    size_t src_PackageConfReference (std::vector <PackageConfReference> & items) const;

    /// Get the src PackageConfConfigProperty connection.
    size_t src_PackageConfConfigProperty (std::vector <PackageConfConfigProperty> & items) const;

    /// Get the src PackageConfSelectRequirement connection.
    size_t src_PackageConfSelectRequirement (std::vector <PackageConfSelectRequirement> & items) const;

    /// Get the src PackageConfSpecializedConfig connection.
    size_t src_PackageConfSpecializedConfig (std::vector <PackageConfSpecializedConfig> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PackageConfiguration.inl"
#endif

#endif  // !defined _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATION
