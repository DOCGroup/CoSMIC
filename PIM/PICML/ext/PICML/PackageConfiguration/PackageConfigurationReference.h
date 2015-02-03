// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfigurationReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONREFERENCE_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONREFERENCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfigurationReference_Impl;
  typedef PackageConfigurationReference_Impl * PackageConfigurationReference_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageConfigurationReference_Impl > PackageConfigurationReference;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageConfigurationReference_Impl
   *
   * Implementation for the PackageConfigurationReference model element.
   */
  class PICML_Export PackageConfigurationReference_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfigurationReference _create (const TopLevelPackageContainer_in parent);
    ///@}

    // Default constructor.
    PackageConfigurationReference_Impl (void);

    // Initializing constructor.
    PackageConfigurationReference_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~PackageConfigurationReference_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelPackageContainer parent_TopLevelPackageContainer (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst PackageConfSpecializedConfig connection.
    size_t dst_of_PackageConfSpecializedConfig (std::vector <PackageConfSpecializedConfig> & items) const;
    GAME::Mga::Collection_T <PackageConfSpecializedConfig> dst_of_PackageConfSpecializedConfig (void) const;

    /// Get the dst package connection.
    size_t dst_of_package (std::vector <package> & items) const;
    GAME::Mga::Collection_T <package> dst_of_package (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool PackageConfiguration_is_nil (void) const;
    PackageConfiguration refers_to_PackageConfiguration (void) const;
    void refers_to_PackageConfiguration (PackageConfiguration_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PackageConfigurationReference.inl"
#endif

#endif  // !defined _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONREFERENCE
