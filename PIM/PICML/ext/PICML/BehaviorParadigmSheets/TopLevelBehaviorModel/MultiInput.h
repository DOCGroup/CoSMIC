// -*- C++ -*-

//============================================================================
/**
 * @file    MultiInput.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIINPUT_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIINPUT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MultiInput_Impl;
  typedef MultiInput_Impl * MultiInput_in;
  typedef ::GAME::Mga::Smart_Ptr < MultiInput_Impl > MultiInput;

  // Forward decl.
  class Visitor;

  /**
   * @class MultiInput_Impl
   *
   * Implementation for the MultiInput model element.
   */
  class PICML_Export MultiInput_Impl :
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

    /**
     * @name Factory Methods
     */
    ///@{
    static MultiInput _create (const TopLevelBehavior_in parent, MultiInputBase_in src, MultiInputAction_in dst);
    ///@}

    // Default constructor.
    MultiInput_Impl (void);

    // Initializing constructor.
    MultiInput_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~MultiInput_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelBehavior parent_TopLevelBehavior (void);
    ///@}
    MultiInputBase src_MultiInputBase (void) const;
    MultiInputAction dst_MultiInputAction (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "MultiInput.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIINPUT
