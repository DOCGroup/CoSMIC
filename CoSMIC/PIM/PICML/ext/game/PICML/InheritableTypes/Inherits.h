// -*- C++ -*-

//============================================================================
/**
 * @file    Inherits.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_INHERITS_H_
#define _PICML_INHERITABLETYPES_INHERITS_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Inherits_Impl;
  typedef Inherits_Impl * Inherits_in;
  typedef ::GAME::Mga::Smart_Ptr <Inherits_Impl> Inherits;

  // Forward decl.
  class Visitor;

  class PICML_Export Inherits_Impl :
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
    Inherits_Impl (void);

    /// Initializing constructor
    Inherits_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~Inherits_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Inherits _create (const Inheritable_in parent);
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
    Inheritable refers_to_Inheritable (void) const;
    ///@}
  };
}

#endif
