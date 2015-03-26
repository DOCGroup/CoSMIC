// -*- C++ -*-

//============================================================================
/**
 * @file    TerminalEffect.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_TERMINALEFFECT_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_TERMINALEFFECT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/EffectTypes/EffectBase.h"
#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TerminalEffect_Impl;
  typedef TerminalEffect_Impl * TerminalEffect_in;
  typedef ::GAME::Mga::Smart_Ptr < TerminalEffect_Impl > TerminalEffect;

  // Forward decl.
  class Visitor;

  /**
   * @class TerminalEffect_Impl
   *
   * Implementation for the TerminalEffect model element.
   */
  class PICML_Export TerminalEffect_Impl :
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
    TerminalEffect_Impl (void);

    // Initializing constructor.
    TerminalEffect_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~TerminalEffect_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BehaviorModel parent_BehaviorModel (void);
    ///@}
    Terminal src_Terminal (void) const;
    StateBase dst_StateBase (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "TerminalEffect.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_TERMINALEFFECT
