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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Package_Impl;
  typedef Package_Impl * Package_in;
  typedef ::GAME::Mga::Smart_Ptr < Package_Impl > Package;

  // Forward decl.
  class Visitor;

  /**
   * @class Package_Impl
   *
   * Implementation for the Package model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static Package _create (const File_in parent);
    ///@}

    // Default constructor.
    Package_Impl (void);

    // Initializing constructor.
    Package_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Package_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ComponentRefs (std::vector <ComponentRef> & items) const;
    ::GAME::Mga::Iterator <ComponentRef> get_ComponentRefs (void) const;

    size_t get_ManagesComponents (std::vector <ManagesComponent> & items) const;
    ::GAME::Mga::Iterator <ManagesComponent> get_ManagesComponents (void) const;

    size_t get_Exceptions (std::vector <Exception> & items) const;
    ::GAME::Mga::Iterator <Exception> get_Exceptions (void) const;

    size_t get_Constants (std::vector <Constant> & items) const;
    ::GAME::Mga::Iterator <Constant> get_Constants (void) const;

    size_t get_TemplateParameters (std::vector <TemplateParameter> & items) const;
    ::GAME::Mga::Iterator <TemplateParameter> get_TemplateParameters (void) const;

    size_t get_NativeValues (std::vector <NativeValue> & items) const;
    ::GAME::Mga::Iterator <NativeValue> get_NativeValues (void) const;

    size_t get_NamedTypes (std::vector <NamedType> & items) const;
    ::GAME::Mga::Iterator <NamedType> get_NamedTypes (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Package.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_PACKAGE
