// -*- C++ -*-

//============================================================================
/**
 * @file    KeyMember.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_KEYMEMBER_H_
#define _PICML_NAMEDTYPES_KEYMEMBER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class KeyMember_Impl;
  typedef KeyMember_Impl * KeyMember_in;
  typedef ::GAME::Mga::Smart_Ptr < KeyMember_Impl > KeyMember;

  // Forward decl.
  class Visitor;

  /**
   * @class KeyMember_Impl
   *
   * Implementation for the KeyMember model element.
   */
  class PICML_Export KeyMember_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static KeyMember _create (const Aggregate_in parent, Key_in src, Member_in dst);
    ///@}

    // Default constructor.
    KeyMember_Impl (void);

    // Initializing constructor.
    KeyMember_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~KeyMember_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Aggregate parent_Aggregate (void);
    ///@}
    Key src_Key (void) const;
    Member dst_Member (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "KeyMember.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_KEYMEMBER
