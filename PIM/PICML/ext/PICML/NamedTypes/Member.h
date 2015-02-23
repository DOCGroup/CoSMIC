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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Member _create (const Exception_in parent);
    static Member _create (const Aggregate_in parent);
    static Member _create (const ObjectByValue_in parent);
    static Member _create (const SwitchedAggregate_in parent);
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
     * @name Parent Methods
     */
    ///@{
    Exception parent_Exception (void);
    Aggregate parent_Aggregate (void);
    ObjectByValue parent_ObjectByValue (void);
    SwitchedAggregate parent_SwitchedAggregate (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src MakeMemberPrivate connection.
    size_t src_of_MakeMemberPrivate (std::vector <MakeMemberPrivate> & items) const;
    bool has_src_of_MakeMemberPrivate (void) const;
    MakeMemberPrivate src_of_MakeMemberPrivate (void) const;

    /// Get the src LabelConnection connection.
    size_t src_of_LabelConnection (std::vector <LabelConnection> & items) const;
    GAME::Mga::Collection_T <LabelConnection> src_of_LabelConnection (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst KeyMember connection.
    size_t dst_of_KeyMember (std::vector <KeyMember> & items) const;
    bool has_dst_of_KeyMember (void) const;
    KeyMember dst_of_KeyMember (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool MemberType_is_nil (void) const;
    MemberType refers_to_MemberType (void) const;
    void refers_to_MemberType (MemberType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Member.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_MEMBER
