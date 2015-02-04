// -*- C++ -*-

//============================================================================
/**
 * @file    InputEffect.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_INPUTEFFECT_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_INPUTEFFECT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/EffectTypes/EffectBase.h"
#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InputEffect_Impl;
  typedef InputEffect_Impl * InputEffect_in;
  typedef ::GAME::Mga::Smart_Ptr < InputEffect_Impl > InputEffect;

  // Forward decl.
  class Visitor;

  /**
   * @class InputEffect_Impl
   *
   * Implementation for the InputEffect model element.
   */
  class PICML_Export InputEffect_Impl :
    public virtual ::GAME::Mga::Connection_Impl,
    public virtual EffectBase_Impl
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
    ///@}

    // Default constructor.
    InputEffect_Impl (void);

    // Initializing constructor.
    InputEffect_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~InputEffect_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BehaviorModel parent_BehaviorModel (void);
    ///@}
    BehaviorInputAction src_BehaviorInputAction (void) const;
    StateBase dst_StateBase (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "InputEffect.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_INPUTEFFECT
