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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InterfaceDefinition/Package.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TemplatePackageInstance_Impl;
  typedef TemplatePackageInstance_Impl * TemplatePackageInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < TemplatePackageInstance_Impl > TemplatePackageInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class TemplatePackageInstance_Impl
   *
   * Implementation for the TemplatePackageInstance model element.
   */
  class PICML_Export TemplatePackageInstance_Impl :
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static TemplatePackageInstance _create (const Package_in parent);
    static TemplatePackageInstance _create (const File_in parent);
    ///@}

    // Default constructor.
    TemplatePackageInstance_Impl (void);

    // Initializing constructor.
    TemplatePackageInstance_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~TemplatePackageInstance_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_PackageType (void) const;
    PackageType get_PackageType (void) const;
    size_t get_TemplateParameterValues (std::vector <TemplateParameterValue> & items) const;
    ::GAME::Mga::Collection_T <TemplateParameterValue> get_TemplateParameterValues (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TemplatePackageInstance.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_TEMPLATEPACKAGEINSTANCE
