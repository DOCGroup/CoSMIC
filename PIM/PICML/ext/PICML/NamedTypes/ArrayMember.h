// -*- C++ -*-

//============================================================================
/**
 * @file    ArrayMember.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_ARRAYMEMBER_H_
#define _PICML_NAMEDTYPES_ARRAYMEMBER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/Member.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ArrayMember_Impl;
  typedef ArrayMember_Impl * ArrayMember_in;
  typedef ::GAME::Mga::Smart_Ptr < ArrayMember_Impl > ArrayMember;

  // Forward decl.
  class Visitor;

  /**
   * @class ArrayMember_Impl
   *
   * Implementation for the ArrayMember model element.
   */
  class PICML_Export ArrayMember_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual Member_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ArrayMember _create (const Aggregate_in parent);
    static ArrayMember _create (const ObjectByValue_in parent);
    static ArrayMember _create (const SwitchedAggregate_in parent);
    static ArrayMember _create (const Exception_in parent);
    ///@}

    // Default constructor.
    ArrayMember_Impl (void);

    // Initializing constructor.
    ArrayMember_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ArrayMember_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
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
  };
}

#if defined (__GAME_INLINE__)
#include "ArrayMember.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_ARRAYMEMBER
