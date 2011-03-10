// -*- C++ -*-

//============================================================================
/**
 * @file    GetException.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_GETEXCEPTION_H_
#define _PICML_INHERITABLETYPES_GETEXCEPTION_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class GetException_Impl;
  typedef GetException_Impl * GetException_in;
  typedef ::GAME::Mga::Smart_Ptr <GetException_Impl> GetException;

  // Forward decl.
  class Visitor;

  class PICML_Export GetException_Impl :
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
    GetException_Impl (void);

    /// Initializing constructor
    GetException_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~GetException_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static GetException _create (const ReadonlyAttribute_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ReadonlyAttribute parent_ReadonlyAttribute (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
