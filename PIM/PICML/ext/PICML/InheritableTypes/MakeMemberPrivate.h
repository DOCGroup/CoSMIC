// -*- C++ -*-

//============================================================================
/**
 * @file    MakeMemberPrivate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_MAKEMEMBERPRIVATE_H_
#define _PICML_INHERITABLETYPES_MAKEMEMBERPRIVATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MakeMemberPrivate_Impl;
  typedef MakeMemberPrivate_Impl * MakeMemberPrivate_in;
  typedef ::GAME::Mga::Smart_Ptr < MakeMemberPrivate_Impl > MakeMemberPrivate;

  // Forward decl.
  class Visitor;

  /**
   * @class MakeMemberPrivate_Impl
   *
   * Implementation for the MakeMemberPrivate model element.
   */
  class PICML_Export MakeMemberPrivate_Impl :
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
    static MakeMemberPrivate _create (const ObjectByValue_in parent, Member_in src, PrivateFlag_in dst);
    ///@}

    // Default constructor.
    MakeMemberPrivate_Impl (void);

    // Initializing constructor.
    MakeMemberPrivate_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~MakeMemberPrivate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ObjectByValue parent_ObjectByValue (void);
    ///@}
    Member src_Member (void) const;
    PrivateFlag dst_PrivateFlag (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "MakeMemberPrivate.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_MAKEMEMBERPRIVATE
