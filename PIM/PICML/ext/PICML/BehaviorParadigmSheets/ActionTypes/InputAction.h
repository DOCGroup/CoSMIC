// -*- C++ -*-

//============================================================================
/**
 * @file    InputAction.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_INPUTACTION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_INPUTACTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InputAction_Impl;
  typedef InputAction_Impl * InputAction_in;
  typedef ::GAME::Mga::Smart_Ptr < InputAction_Impl > InputAction;

  // Forward decl.
  class Visitor;

  /**
   * @class InputAction_Impl
   *
   * Implementation for the InputAction model element.
   */
  class PICML_Export InputAction_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual BehaviorInputAction_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static InputAction _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    InputAction_Impl (void);

    // Initializing constructor.
    InputAction_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~InputAction_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst Input connection.
    size_t dst_of_Input (std::vector <Input> & items) const;
    GAME::Mga::Collection_T <Input> dst_of_Input (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "InputAction.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_INPUTACTION
