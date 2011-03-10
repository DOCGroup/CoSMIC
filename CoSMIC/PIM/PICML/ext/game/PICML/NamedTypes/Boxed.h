// -*- C++ -*-

//============================================================================
/**
 * @file    Boxed.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_BOXED_H_
#define _PICML_NAMEDTYPES_BOXED_H_

#include "game/mga/Reference.h"
#include "PICML/NamedTypes/NamedType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Boxed_Impl;
  typedef Boxed_Impl * Boxed_in;
  typedef ::GAME::Mga::Smart_Ptr <Boxed_Impl> Boxed;

  // Forward decl.
  class Visitor;

  class PICML_Export Boxed_Impl :
    public virtual NamedType_Impl,
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
    Boxed_Impl (void);

    /// Initializing constructor
    Boxed_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~Boxed_Impl (void);

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
