// -*- C++ -*-

//============================================================================
/**
 * @file    ActionBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_ACTIONBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_ACTIONBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ActionBase_Impl;
  typedef ActionBase_Impl * ActionBase_in;
  typedef ::GAME::Mga::Smart_Ptr < ActionBase_Impl > ActionBase;

  /**
   * @class ActionBase_Impl
   *
   * Implementation for the ActionBase model element.
   */
  class PICML_Export ActionBase_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    ActionBase_Impl (void);

    // Initializing constructor.
    ActionBase_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ActionBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    BehaviorModel parent_BehaviorModel (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Duration
    void Duration (long val);

    /// Get the value of Duration
    long Duration (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src Effect connection.
    size_t src_Effect (std::vector <Effect> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst LoopTransition connection.
    size_t dst_LoopTransition (std::vector <LoopTransition> & items) const;

    /// Get the dst BranchTransition connection.
    size_t dst_BranchTransition (std::vector <BranchTransition> & items) const;

    /// Get the dst Transition connection.
    size_t dst_Transition (std::vector <Transition> & items) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Iterator <ComplexProperty> get_ComplexPropertys (void) const;

    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Iterator <SimpleProperty> get_SimplePropertys (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ActionBase.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_ACTIONBASE