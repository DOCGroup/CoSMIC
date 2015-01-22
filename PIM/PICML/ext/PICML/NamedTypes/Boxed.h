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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/NamedType.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Boxed_Impl;
  typedef Boxed_Impl * Boxed_in;
  typedef ::GAME::Mga::Smart_Ptr < Boxed_Impl > Boxed;

  // Forward decl.
  class Visitor;

  /**
   * @class Boxed_Impl
   *
   * Implementation for the Boxed model element.
   */
  class PICML_Export Boxed_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual NamedType_Impl
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
    static Boxed _create (const Package_in parent);
    static Boxed _create (const File_in parent);
    ///@}

    // Default constructor.
    Boxed_Impl (void);

    // Initializing constructor.
    Boxed_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~Boxed_Impl (void);

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
    MemberType refers_to_MemberType (void) const;
    void refers_to_MemberType (MemberType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Boxed.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_BOXED
