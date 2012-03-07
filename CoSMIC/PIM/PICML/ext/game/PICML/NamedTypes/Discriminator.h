// -*- C++ -*-

//============================================================================
/**
 * @file    Discriminator.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_DISCRIMINATOR_H_
#define _PICML_NAMEDTYPES_DISCRIMINATOR_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Discriminator_Impl;
  typedef Discriminator_Impl * Discriminator_in;
  typedef ::GAME::Mga::Smart_Ptr < Discriminator_Impl > Discriminator;

  // Forward decl.
  class Visitor;

  /**
   * @class Discriminator_Impl
   *
   * Implementation for the Discriminator model element.
   */
  class PICML_Export Discriminator_Impl :
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
    static Discriminator _create (const SwitchedAggregate_in parent);
    ///@}

    // Default constructor.
    Discriminator_Impl (void);

    // Initializing constructor.
    Discriminator_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~Discriminator_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ConstantType_is_nil (void) const;
    ConstantType get_ConstantType (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Discriminator.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_DISCRIMINATOR
