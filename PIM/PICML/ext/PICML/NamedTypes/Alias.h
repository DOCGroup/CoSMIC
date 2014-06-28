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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/NoInheritable.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Alias_Impl;
  typedef Alias_Impl * Alias_in;
  typedef ::GAME::Mga::Smart_Ptr < Alias_Impl > Alias;

  // Forward decl.
  class Visitor;

  /**
   * @class Alias_Impl
   *
   * Implementation for the Alias model element.
   */
  class PICML_Export Alias_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual NoInheritable_Impl
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
    static Alias _create (const HasOperations_in parent);
    static Alias _create (const Package_in parent);
    static Alias _create (const File_in parent);
    ///@}

    // Default constructor.
    Alias_Impl (void);

    // Initializing constructor.
    Alias_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~Alias_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool MemberType_is_nil (void) const;
    MemberType get_MemberType (void) const;
    void set_MemberType (MemberType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Alias.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_ALIAS
