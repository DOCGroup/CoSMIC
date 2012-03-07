// -*- C++ -*-

//============================================================================
/**
 * @file    TemplatePackageAlias.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_TEMPLATEPACKAGEALIAS_H_
#define _PICML_INTERFACEDEFINITION_TEMPLATEPACKAGEALIAS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InterfaceDefinition/Package.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TemplatePackageAlias_Impl;
  typedef TemplatePackageAlias_Impl * TemplatePackageAlias_in;
  typedef ::GAME::Mga::Smart_Ptr < TemplatePackageAlias_Impl > TemplatePackageAlias;

  // Forward decl.
  class Visitor;

  /**
   * @class TemplatePackageAlias_Impl
   *
   * Implementation for the TemplatePackageAlias model element.
   */
  class PICML_Export TemplatePackageAlias_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual Package_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static TemplatePackageAlias _create (const Package_in parent);
    static TemplatePackageAlias _create (const File_in parent);
    ///@}

    // Default constructor.
    TemplatePackageAlias_Impl (void);

    // Initializing constructor.
    TemplatePackageAlias_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~TemplatePackageAlias_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Containment Methods
     */
    ///@{
    PackageType get_PackageType (void) const;

    size_t get_TemplateParameterReferences (std::vector <TemplateParameterReference> & items) const;
    ::GAME::Mga::Iterator <TemplateParameterReference> get_TemplateParameterReferences (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TemplatePackageAlias.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_TEMPLATEPACKAGEALIAS
