// -*- C++ -*-

//============================================================================
/**
 * @file    Supports.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_SUPPORTS_H_
#define _PICML_INHERITABLETYPES_SUPPORTS_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Supports_Impl;
  typedef Supports_Impl * Supports_in;
  typedef ::GAME::Mga::Smart_Ptr <Supports_Impl> Supports;

  // Forward decl.
  class Visitor;

  class PICML_Export Supports_Impl :
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
    Supports_Impl (void);

    /// Initializing constructor
    Supports_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~Supports_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Supports _create (const SupportsInterfaces_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    SupportsInterfaces parent_SupportsInterfaces (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    Object refers_to_Object (void) const;
    ///@}
  };
}

#endif
