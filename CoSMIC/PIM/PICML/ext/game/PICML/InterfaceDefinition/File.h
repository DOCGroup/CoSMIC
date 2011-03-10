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

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class File_Impl;
  typedef File_Impl * File_in;
  typedef ::GAME::Mga::Smart_Ptr <File_Impl> File;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    File_Impl (void);

    /// Initializing constructor
    File_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~File_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static File _create (const InterfaceDefinitions_in parent);
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
    size_t get_NativeValues (std::vector <NativeValue> & items) const;
    size_t get_ManagesComponents (std::vector <ManagesComponent> & items) const;
    size_t get_ComponentRefs (std::vector <ComponentRef> & items) const;
    size_t get_NamedTypes (std::vector <NamedType> & items) const;
    size_t get_Constants (std::vector <Constant> & items) const;
    size_t get_FileRefs (std::vector <FileRef> & items) const;
    size_t get_Exceptions (std::vector <Exception> & items) const;
    size_t get_Packages (std::vector <Package> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    InterfaceDefinitions parent_InterfaceDefinitions (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
