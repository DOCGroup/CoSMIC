// -*- C++ -*-

//============================================================================
/**
 * @file    Effect.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_EFFECT_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_EFFECT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/EffectTypes/EffectBase.h"
#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Effect_Impl;
  typedef Effect_Impl * Effect_in;
  typedef ::GAME::Mga::Smart_Ptr < Effect_Impl > Effect;

  // Forward decl.
  class Visitor;

  /**
   * @class Effect_Impl
   *
   * Implementation for the Effect model element.
   */
  class PICML_Export Effect_Impl :
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

    /**
     * @name Factory Methods
     */
    ///@{
    static Effect _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    Effect_Impl (void);

    // Initializing constructor.
    Effect_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~Effect_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BehaviorModel parent_BehaviorModel (void);
    ///@}
    ActionBase src_ActionBase (void) const;
    StateBase dst_StateBase (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "Effect.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_EFFECT
