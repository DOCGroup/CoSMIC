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

#include "game/mga/Connection.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/EffectBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InputEffect_Impl;
  typedef InputEffect_Impl * InputEffect_in;
  typedef ::GAME::Mga::Smart_Ptr <InputEffect_Impl> InputEffect;

  // Forward decl.
  class Visitor;

  class PICML_Export InputEffect_Impl :
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
    InputEffect_Impl (void);

    /// Initializing constructor
    InputEffect_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~InputEffect_Impl (void);

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
