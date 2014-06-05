// -*- C++ -*-

//============================================================================
/**
 * @file    File.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_FILE_H_
#define _PICML_INTERFACEDEFINITION_FILE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/IdTags/Prefixable.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class File_Impl;
  typedef File_Impl * File_in;
  typedef ::GAME::Mga::Smart_Ptr < File_Impl > File;

  // Forward decl.
  class Visitor;

  /**
   * @class File_Impl
   *
   * Implementation for the File model element.
   */
  class PICML_Export File_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual Prefixable_Impl
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
    static File _create (const InterfaceDefinitions_in parent);
    ///@}

    // Default constructor.
    File_Impl (void);

    // Initializing constructor.
    File_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~File_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    InterfaceDefinitions parent_InterfaceDefinitions (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Path
    void Path (const std::string & val);

    /// Get the value of Path
    std::string Path (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_PortTypes (std::vector <PortType> & items) const;
    ::GAME::Mga::Collection_T <PortType> get_PortTypes (void) const;

    size_t get_Aggregates (std::vector <Aggregate> & items) const;
    ::GAME::Mga::Collection_T <Aggregate> get_Aggregates (void) const;

    size_t get_Collections (std::vector <Collection> & items) const;
    ::GAME::Mga::Collection_T <Collection> get_Collections (void) const;

    size_t get_Aliass (std::vector <Alias> & items) const;
    ::GAME::Mga::Collection_T <Alias> get_Aliass (void) const;

    size_t get_Enums (std::vector <Enum> & items) const;
    ::GAME::Mga::Collection_T <Enum> get_Enums (void) const;

    size_t get_SwitchedAggregates (std::vector <SwitchedAggregate> & items) const;
    ::GAME::Mga::Collection_T <SwitchedAggregate> get_SwitchedAggregates (void) const;

    size_t get_ComponentFactorys (std::vector <ComponentFactory> & items) const;
    ::GAME::Mga::Collection_T <ComponentFactory> get_ComponentFactorys (void) const;

    size_t get_Objects (std::vector <Object> & items) const;
    ::GAME::Mga::Collection_T <Object> get_Objects (void) const;

    size_t get_Events (std::vector <Event> & items) const;
    ::GAME::Mga::Collection_T <Event> get_Events (void) const;

    size_t get_ValueObjects (std::vector <ValueObject> & items) const;
    ::GAME::Mga::Collection_T <ValueObject> get_ValueObjects (void) const;

    size_t get_Components (std::vector <Component> & items) const;
    ::GAME::Mga::Collection_T <Component> get_Components (void) const;

    size_t get_ConnectorObjects (std::vector <ConnectorObject> & items) const;
    ::GAME::Mga::Collection_T <ConnectorObject> get_ConnectorObjects (void) const;

    size_t get_Boxeds (std::vector <Boxed> & items) const;
    ::GAME::Mga::Collection_T <Boxed> get_Boxeds (void) const;

    size_t get_ComponentRefs (std::vector <ComponentRef> & items) const;
    ::GAME::Mga::Collection_T <ComponentRef> get_ComponentRefs (void) const;

    size_t get_ManagesComponents (std::vector <ManagesComponent> & items) const;
    ::GAME::Mga::Collection_T <ManagesComponent> get_ManagesComponents (void) const;

    size_t get_Exceptions (std::vector <Exception> & items) const;
    ::GAME::Mga::Collection_T <Exception> get_Exceptions (void) const;

    size_t get_Packages (std::vector <Package> & items) const;
    ::GAME::Mga::Collection_T <Package> get_Packages (void) const;

    size_t get_TemplatePackageInstances (std::vector <TemplatePackageInstance> & items) const;
    ::GAME::Mga::Collection_T <TemplatePackageInstance> get_TemplatePackageInstances (void) const;

    size_t get_TemplatePackageAliass (std::vector <TemplatePackageAlias> & items) const;
    ::GAME::Mga::Collection_T <TemplatePackageAlias> get_TemplatePackageAliass (void) const;

    size_t get_NativeValues (std::vector <NativeValue> & items) const;
    ::GAME::Mga::Collection_T <NativeValue> get_NativeValues (void) const;

    size_t get_Constants (std::vector <Constant> & items) const;
    ::GAME::Mga::Collection_T <Constant> get_Constants (void) const;

    size_t get_FileRefs (std::vector <FileRef> & items) const;
    ::GAME::Mga::Collection_T <FileRef> get_FileRefs (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "File.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_FILE
