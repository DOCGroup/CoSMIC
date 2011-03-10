// -*- C++ -*-

//============================================================================
/**
 * @file    SetException.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_SETEXCEPTION_H_
#define _PICML_INHERITABLETYPES_SETEXCEPTION_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SetException_Impl;
  typedef SetException_Impl * SetException_in;
  typedef ::GAME::Mga::Smart_Ptr <SetException_Impl> SetException;

  // Forward decl.
  class Visitor;

  class PICML_Export SetException_Impl :
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
    SetException_Impl (void);

    /// Initializing constructor
    SetException_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~SetException_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static SetException _create (const Attribute_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    Attribute parent_Attribute (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
