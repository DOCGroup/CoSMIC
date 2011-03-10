// -*- C++ -*-

//============================================================================
/**
 * @file    PackageType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_PACKAGETYPE_H_
#define _PICML_INTERFACEDEFINITION_PACKAGETYPE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageType_Impl;
  typedef PackageType_Impl * PackageType_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageType_Impl> PackageType;

  // Forward decl.
  class Visitor;

  class PICML_Export PackageType_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    PackageType_Impl (void);

    /// Initializing constructor
    PackageType_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~PackageType_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageType _create (const TemplatePackageInstance_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    TemplatePackageInstance parent_TemplatePackageInstance (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    Package refers_to_Package (void) const;
    ///@}
  };
}

#endif
