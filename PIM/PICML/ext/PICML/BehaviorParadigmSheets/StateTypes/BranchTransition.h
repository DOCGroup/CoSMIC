// -*- C++ -*-

//============================================================================
/**
 * @file    BranchTransition.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_BRANCHTRANSITION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_BRANCHTRANSITION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BranchTransition_Impl;
  typedef BranchTransition_Impl * BranchTransition_in;
  typedef ::GAME::Mga::Smart_Ptr < BranchTransition_Impl > BranchTransition;

  // Forward decl.
  class Visitor;

  /**
   * @class BranchTransition_Impl
   *
   * Implementation for the BranchTransition model element.
   */
  class PICML_Export BranchTransition_Impl :
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
    static BranchTransition _create (const BehaviorModel_in parent, BranchState_in src, ActionBase_in dst);
    ///@}

    // Default constructor.
    BranchTransition_Impl (void);

    // Initializing constructor.
    BranchTransition_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~BranchTransition_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

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

    /// Set the value of Condition
    void Condition (const std::string & val);

    /// Get the value of Condition
    std::string Condition (void) const;
    ///@}
    BranchState src_BranchState (void) const;
    ActionBase dst_ActionBase (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "BranchTransition.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_BRANCHTRANSITION
