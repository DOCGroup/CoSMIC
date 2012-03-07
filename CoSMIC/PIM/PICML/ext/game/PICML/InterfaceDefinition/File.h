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
    size_t get_ComponentRefs (std::vector <ComponentRef> & items) const;
    ::GAME::Mga::Iterator <ComponentRef> get_ComponentRefs (void) const;

    size_t get_ManagesComponents (std::vector <ManagesComponent> & items) const;
    ::GAME::Mga::Iterator <ManagesComponent> get_ManagesComponents (void) const;

    size_t get_Packages (std::vector <Package> & items) const;
    ::GAME::Mga::Iterator <Package> get_Packages (void) const;

    size_t get_Exceptions (std::vector <Exception> & items) const;
    ::GAME::Mga::Iterator <Exception> get_Exceptions (void) const;

    size_t get_FileRefs (std::vector <FileRef> & items) const;
    ::GAME::Mga::Iterator <FileRef> get_FileRefs (void) const;

    size_t get_Constants (std::vector <Constant> & items) const;
    ::GAME::Mga::Iterator <Constant> get_Constants (void) const;

    size_t get_NativeValues (std::vector <NativeValue> & items) const;
    ::GAME::Mga::Iterator <NativeValue> get_NativeValues (void) const;

    size_t get_NamedTypes (std::vector <NamedType> & items) const;
    ::GAME::Mga::Iterator <NamedType> get_NamedTypes (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "File.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_FILE
