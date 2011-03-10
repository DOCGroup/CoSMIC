// -*- C++ -*-

//============================================================================
/**
 * @file    Package.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_PACKAGE_H_
#define _PICML_INTERFACEDEFINITION_PACKAGE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Package_Impl;
  typedef Package_Impl * Package_in;
  typedef ::GAME::Mga::Smart_Ptr <Package_Impl> Package;

  // Forward decl.
  class Visitor;

  class PICML_Export Package_Impl :
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
    Package_Impl (void);

    /// Initializing constructor
    Package_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Package_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Package _create (const File_in parent);
    static Package _create (const Package_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_NativeValues (std::vector <NativeValue> & items) const;
    size_t get_TemplateParameters (std::vector <TemplateParameter> & items) const;
    size_t get_ManagesComponents (std::vector <ManagesComponent> & items) const;
    size_t get_ComponentRefs (std::vector <ComponentRef> & items) const;
    size_t get_NamedTypes (std::vector <NamedType> & items) const;
    size_t get_Constants (std::vector <Constant> & items) const;
    size_t get_Exceptions (std::vector <Exception> & items) const;
    size_t get_Packages (std::vector <Package> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    File parent_File (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
