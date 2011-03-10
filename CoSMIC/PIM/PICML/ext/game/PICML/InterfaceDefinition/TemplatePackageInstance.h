// -*- C++ -*-

//============================================================================
/**
 * @file    TemplatePackageInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_TEMPLATEPACKAGEINSTANCE_H_
#define _PICML_INTERFACEDEFINITION_TEMPLATEPACKAGEINSTANCE_H_

#include "game/mga/Model.h"
#include "PICML/InterfaceDefinition/Package.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TemplatePackageInstance_Impl;
  typedef TemplatePackageInstance_Impl * TemplatePackageInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <TemplatePackageInstance_Impl> TemplatePackageInstance;

  // Forward decl.
  class Visitor;

  class PICML_Export TemplatePackageInstance_Impl :
    public virtual Package_Impl,
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    TemplatePackageInstance_Impl (void);

    /// Initializing constructor
    TemplatePackageInstance_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~TemplatePackageInstance_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_TemplateParameterValues (std::vector <TemplateParameterValue> & items) const;

    PackageType get_PackageType (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
