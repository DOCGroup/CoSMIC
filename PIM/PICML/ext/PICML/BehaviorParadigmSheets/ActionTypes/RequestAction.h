// -*- C++ -*-

//============================================================================
/**
 * @file    RequestAction.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_REQUESTACTION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_REQUESTACTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequestAction_Impl;
  typedef RequestAction_Impl * RequestAction_in;
  typedef ::GAME::Mga::Smart_Ptr < RequestAction_Impl > RequestAction;

  // Forward decl.
  class Visitor;

  /**
   * @class RequestAction_Impl
   *
   * Implementation for the RequestAction model element.
   */
  class PICML_Export RequestAction_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual ActionBase_Impl
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
    static RequestAction _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    RequestAction_Impl (void);

    // Initializing constructor.
    RequestAction_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~RequestAction_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of MethodName
    void MethodName (const std::string & val);

    /// Get the value of MethodName
    std::string MethodName (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "RequestAction.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_REQUESTACTION
