// -*- C++ -*-

//============================================================================
/**
 * @file    ArrayMember.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_ARRAYMEMBER_H_
#define _PICML_NAMEDTYPES_ARRAYMEMBER_H_

#include "game/mga/Reference.h"
#include "PICML/NamedTypes/Member.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ArrayMember_Impl;
  typedef ArrayMember_Impl * ArrayMember_in;
  typedef ::GAME::Mga::Smart_Ptr <ArrayMember_Impl> ArrayMember;

  // Forward decl.
  class Visitor;

  class PICML_Export ArrayMember_Impl :
    public virtual Member_Impl,
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
    ArrayMember_Impl (void);

    /// Initializing constructor
    ArrayMember_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ArrayMember_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Size
    void Size (long val);

    /// Get the value of Size
    long Size (void) const;
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
    ///@}
  };
}

#endif
