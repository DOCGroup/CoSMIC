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

#include "game/mga/Connection.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/EffectBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Effect_Impl;
  typedef Effect_Impl * Effect_in;
  typedef ::GAME::Mga::Smart_Ptr <Effect_Impl> Effect;

  // Forward decl.
  class Visitor;

  class PICML_Export Effect_Impl :
    public virtual EffectBase_Impl,
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Effect_Impl (void);

    /// Initializing constructor
    Effect_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~Effect_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
