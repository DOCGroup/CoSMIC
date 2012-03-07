// -*- C++ -*-

//============================================================================
/**
 * @file    Member.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_MEMBER_H_
#define _PICML_NAMEDTYPES_MEMBER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Member_Impl;
  typedef Member_Impl * Member_in;
  typedef ::GAME::Mga::Smart_Ptr < Member_Impl > Member;

  // Forward decl.
  class Visitor;

  /**
   * @class Member_Impl
   *
   * Implementation for the Member model element.
   */
  class PICML_Export Member_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static Member _create (const Exception_in parent);
    static Member _create (const Aggregate_in parent);
    static Member _create (const SwitchedAggregate_in parent);
    static Member _create (const ObjectByValue_in parent);
    ///@}

    // Default constructor.
    Member_Impl (void);

    // Initializing constructor.
    Member_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~Member_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src LabelConnection connection.
    size_t src_LabelConnection (std::vector <LabelConnection> & items) const;

    /// Get the src MakeMemberPrivate connection.
    size_t src_MakeMemberPrivate (std::vector <MakeMemberPrivate> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst KeyMember connection.
    size_t dst_KeyMember (std::vector <KeyMember> & items) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool MemberType_is_nil (void) const;
    MemberType get_MemberType (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Member.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_MEMBER
