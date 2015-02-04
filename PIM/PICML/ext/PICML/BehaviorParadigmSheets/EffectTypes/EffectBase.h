// -*- C++ -*-

//============================================================================
/**
 * @file    EffectBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_EFFECTBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_EFFECTBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EffectBase_Impl;
  typedef EffectBase_Impl * EffectBase_in;
  typedef ::GAME::Mga::Smart_Ptr < EffectBase_Impl > EffectBase;

  /**
   * @class EffectBase_Impl
   *
   * Implementation for the EffectBase model element.
   */
  class PICML_Export EffectBase_Impl :
    public virtual ::GAME::Mga::Connection_Impl
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

    // Default constructor.
    EffectBase_Impl (void);

    // Initializing constructor.
    EffectBase_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~EffectBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Postcondition
    void Postcondition (const std::string & val);

    /// Get the value of Postcondition
    std::string Postcondition (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "EffectBase.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_EFFECTTYPES_EFFECTBASE
