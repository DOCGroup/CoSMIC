// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfSelectRequirement.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFSELECTREQUIREMENT_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFSELECTREQUIREMENT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfSelectRequirement_Impl;
  typedef PackageConfSelectRequirement_Impl * PackageConfSelectRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageConfSelectRequirement_Impl > PackageConfSelectRequirement;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageConfSelectRequirement_Impl
   *
   * Implementation for the PackageConfSelectRequirement model element.
   */
  class PICML_Export PackageConfSelectRequirement_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfSelectRequirement _create (const PackageConfigurationContainer_in parent, PackageConfiguration_in src, Requirement_in dst);
    ///@}

    // Default constructor.
    PackageConfSelectRequirement_Impl (void);

    // Initializing constructor.
    PackageConfSelectRequirement_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PackageConfSelectRequirement_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageConfigurationContainer parent_PackageConfigurationContainer (void);
    ///@}
    PackageConfiguration src_PackageConfiguration (void) const;
    Requirement dst_Requirement (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "PackageConfSelectRequirement.inl"
#endif

#endif  // !defined _PICML_PACKAGECONFIGURATION_PACKAGECONFSELECTREQUIREMENT
