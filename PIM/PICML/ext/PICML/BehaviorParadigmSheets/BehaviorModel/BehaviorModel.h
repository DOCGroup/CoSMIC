// -*- C++ -*-

//============================================================================
/**
 * @file    BehaviorModel.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_BEHAVIORMODEL_BEHAVIORMODEL_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_BEHAVIORMODEL_BEHAVIORMODEL_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BehaviorModel_Impl;
  typedef BehaviorModel_Impl * BehaviorModel_in;
  typedef ::GAME::Mga::Smart_Ptr < BehaviorModel_Impl > BehaviorModel;

  /**
   * @class BehaviorModel_Impl
   *
   * Implementation for the BehaviorModel model element.
   */
  class PICML_Export BehaviorModel_Impl :
    public virtual ::GAME::Mga::Model_Impl
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

    // Default constructor.
    BehaviorModel_Impl (void);

    // Initializing constructor.
    BehaviorModel_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~BehaviorModel_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_LoopTransitions (std::vector <LoopTransition> & items) const;
    ::GAME::Mga::Collection_T <LoopTransition> get_LoopTransitions (void) const;

    size_t get_Finishs (std::vector <Finish> & items) const;
    ::GAME::Mga::Collection_T <Finish> get_Finishs (void) const;

    size_t get_InputEffects (std::vector <InputEffect> & items) const;
    ::GAME::Mga::Collection_T <InputEffect> get_InputEffects (void) const;

    size_t get_TerminalEffects (std::vector <TerminalEffect> & items) const;
    ::GAME::Mga::Collection_T <TerminalEffect> get_TerminalEffects (void) const;

    size_t get_Variables (std::vector <Variable> & items) const;
    ::GAME::Mga::Collection_T <Variable> get_Variables (void) const;

    size_t get_Effects (std::vector <Effect> & items) const;
    ::GAME::Mga::Collection_T <Effect> get_Effects (void) const;

    size_t get_Transitions (std::vector <Transition> & items) const;
    ::GAME::Mga::Collection_T <Transition> get_Transitions (void) const;

    size_t get_TerminalTransitions (std::vector <TerminalTransition> & items) const;
    ::GAME::Mga::Collection_T <TerminalTransition> get_TerminalTransitions (void) const;

    size_t get_BranchTransitions (std::vector <BranchTransition> & items) const;
    ::GAME::Mga::Collection_T <BranchTransition> get_BranchTransitions (void) const;

    size_t get_MultiInputActions (std::vector <MultiInputAction> & items) const;
    ::GAME::Mga::Collection_T <MultiInputAction> get_MultiInputActions (void) const;

    size_t get_InputActions (std::vector <InputAction> & items) const;
    ::GAME::Mga::Collection_T <InputAction> get_InputActions (void) const;

    size_t get_CallActions (std::vector <CallAction> & items) const;
    ::GAME::Mga::Collection_T <CallAction> get_CallActions (void) const;

    size_t get_RequestActions (std::vector <RequestAction> & items) const;
    ::GAME::Mga::Collection_T <RequestAction> get_RequestActions (void) const;

    size_t get_QueryActions (std::vector <QueryAction> & items) const;
    ::GAME::Mga::Collection_T <QueryAction> get_QueryActions (void) const;

    size_t get_OutputActions (std::vector <OutputAction> & items) const;
    ::GAME::Mga::Collection_T <OutputAction> get_OutputActions (void) const;

    size_t get_Actions (std::vector <Action> & items) const;
    ::GAME::Mga::Collection_T <Action> get_Actions (void) const;

    size_t get_QueryInputActions (std::vector <QueryInputAction> & items) const;
    ::GAME::Mga::Collection_T <QueryInputAction> get_QueryInputActions (void) const;

    size_t get_Terminals (std::vector <Terminal> & items) const;
    ::GAME::Mga::Collection_T <Terminal> get_Terminals (void) const;

    size_t get_BranchStates (std::vector <BranchState> & items) const;
    ::GAME::Mga::Collection_T <BranchState> get_BranchStates (void) const;

    size_t get_WhileStates (std::vector <WhileState> & items) const;
    ::GAME::Mga::Collection_T <WhileState> get_WhileStates (void) const;

    size_t get_DoWhileStates (std::vector <DoWhileState> & items) const;
    ::GAME::Mga::Collection_T <DoWhileState> get_DoWhileStates (void) const;

    size_t get_ForStates (std::vector <ForState> & items) const;
    ::GAME::Mga::Collection_T <ForState> get_ForStates (void) const;

    size_t get_States (std::vector <State> & items) const;
    ::GAME::Mga::Collection_T <State> get_States (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "BehaviorModel.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_BEHAVIORMODEL_BEHAVIORMODEL
