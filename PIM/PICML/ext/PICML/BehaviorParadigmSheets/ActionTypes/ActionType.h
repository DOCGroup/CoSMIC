// -*- C++ -*-

//============================================================================
/**
 * @file    ActionType.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_ACTIONTYPE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_ACTIONTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ActionType_Impl;
  typedef ActionType_Impl * ActionType_in;
  typedef ::GAME::Mga::Smart_Ptr < ActionType_Impl > ActionType;

  // Forward decl.
  class Visitor;

  /**
   * @class ActionType_Impl
   *
   * Implementation for the ActionType model element.
   */
  class PICML_Export ActionType_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ActionType _create (const Action_in parent);
    ///@}

    // Default constructor.
    ActionType_Impl (void);

    // Initializing constructor.
    ActionType_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ActionType_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Action parent_Action (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Operation_is_nil (void) const;
    Operation refers_to_Operation (void) const;
    void refers_to_Operation (Operation_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ActionType.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_ACTIONTYPE
