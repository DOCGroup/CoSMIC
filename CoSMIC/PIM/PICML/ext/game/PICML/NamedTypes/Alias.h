// -*- C++ -*-

//============================================================================
/**
 * @file    Alias.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_ALIAS_H_
#define _PICML_NAMEDTYPES_ALIAS_H_

#include "game/mga/Reference.h"
#include "PICML/NamedTypes/NoInheritable.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Alias_Impl;
  typedef Alias_Impl * Alias_in;
  typedef ::GAME::Mga::Smart_Ptr <Alias_Impl> Alias;

  // Forward decl.
  class Visitor;

  class PICML_Export Alias_Impl :
    public virtual NoInheritable_Impl,
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
    Alias_Impl (void);

    /// Initializing constructor
    Alias_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~Alias_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    MemberType refers_to_MemberType (void) const;
    ///@}
  };
}

#endif
