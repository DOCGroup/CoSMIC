// -*- C++ -*-

//============================================================================
/**
 * @file    Exception.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_EXCEPTION_H_
#define _PICML_INTERFACEDEFINITION_EXCEPTION_H_

#include "game/mga/Model.h"
#include "PICML/InterfaceDefinition/ExceptionType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Exception_Impl;
  typedef Exception_Impl * Exception_in;
  typedef ::GAME::Mga::Smart_Ptr <Exception_Impl> Exception;

  // Forward decl.
  class Visitor;

  class PICML_Export Exception_Impl :
    public virtual ExceptionType_Impl,
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
    Exception_Impl (void);

    /// Initializing constructor
    Exception_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Exception_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Exception _create (const File_in parent);
    static Exception _create (const Package_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Members (std::vector <Member> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    File parent_File (void) const;
    Package parent_Package (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
