// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeMember.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_ATTRIBUTEMEMBER_H_
#define _PICML_INHERITABLETYPES_ATTRIBUTEMEMBER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeMember_Impl;
  typedef AttributeMember_Impl * AttributeMember_in;
  typedef ::GAME::Mga::Smart_Ptr < AttributeMember_Impl > AttributeMember;

  // Forward decl.
  class Visitor;

  /**
   * @class AttributeMember_Impl
   *
   * Implementation for the AttributeMember model element.
   */
  class PICML_Export AttributeMember_Impl :
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
    static AttributeMember _create (const ReadonlyAttribute_in parent);
    ///@}

    // Default constructor.
    AttributeMember_Impl (void);

    // Initializing constructor.
    AttributeMember_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~AttributeMember_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

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
#include "AttributeMember.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_ATTRIBUTEMEMBER
