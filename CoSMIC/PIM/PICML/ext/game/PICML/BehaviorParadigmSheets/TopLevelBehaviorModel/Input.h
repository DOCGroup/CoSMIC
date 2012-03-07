// -*- C++ -*-

//============================================================================
/**
 * @file    Input.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_INPUT_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_INPUT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Input_Impl;
  typedef Input_Impl * Input_in;
  typedef ::GAME::Mga::Smart_Ptr < Input_Impl > Input;

  // Forward decl.
  class Visitor;

  /**
   * @class Input_Impl
   *
   * Implementation for the Input model element.
   */
  class PICML_Export Input_Impl :
    public virtual ::GAME::Mga::Connection_Impl
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
    static Input _create (const TopLevelBehavior_in parent);
    ///@}

    // Default constructor.
    Input_Impl (void);

    // Initializing constructor.
    Input_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~Input_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
    SingleInputBase src_SingleInputBase (void) const;
    InputAction dst_InputAction (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "Input.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_INPUT
