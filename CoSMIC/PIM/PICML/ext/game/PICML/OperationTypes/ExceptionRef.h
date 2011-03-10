// -*- C++ -*-

//============================================================================
/**
 * @file    ExceptionRef.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_EXCEPTIONREF_H_
#define _PICML_OPERATIONTYPES_EXCEPTIONREF_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExceptionRef_Impl;
  typedef ExceptionRef_Impl * ExceptionRef_in;
  typedef ::GAME::Mga::Smart_Ptr <ExceptionRef_Impl> ExceptionRef;

  // Forward decl.
  class Visitor;

  class PICML_Export ExceptionRef_Impl :
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
    ExceptionRef_Impl (void);

    /// Initializing constructor
    ExceptionRef_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ExceptionRef_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ExceptionRef _create (const HasExceptions_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    HasExceptions parent_HasExceptions (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
