// -*- C++ -*-

//============================================================================
/**
 * @file    ReadonlyAttribute.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_READONLYATTRIBUTE_H_
#define _PICML_INHERITABLETYPES_READONLYATTRIBUTE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ReadonlyAttribute_Impl;
  typedef ReadonlyAttribute_Impl * ReadonlyAttribute_in;
  typedef ::GAME::Mga::Smart_Ptr <ReadonlyAttribute_Impl> ReadonlyAttribute;

  // Forward decl.
  class Visitor;

  class PICML_Export ReadonlyAttribute_Impl :
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
    ReadonlyAttribute_Impl (void);

    /// Initializing constructor
    ReadonlyAttribute_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ReadonlyAttribute_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ReadonlyAttribute _create (const Inheritable_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_GetExceptions (std::vector <GetException> & items) const;

    AttributeMember get_AttributeMember (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    Inheritable parent_Inheritable (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
