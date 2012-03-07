// -*- C++ -*-

//============================================================================
/**
 * @file    Inherits.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_INHERITS_H_
#define _PICML_INHERITABLETYPES_INHERITS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Inherits_Impl;
  typedef Inherits_Impl * Inherits_in;
  typedef ::GAME::Mga::Smart_Ptr < Inherits_Impl > Inherits;

  // Forward decl.
  class Visitor;

  /**
   * @class Inherits_Impl
   *
   * Implementation for the Inherits model element.
   */
  class PICML_Export Inherits_Impl :
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
    static Inherits _create (const Inheritable_in parent);
    ///@}

    // Default constructor.
    Inherits_Impl (void);

    // Initializing constructor.
    Inherits_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~Inherits_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Inheritable_is_nil (void) const;
    Inheritable get_Inheritable (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Inherits.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_INHERITS
