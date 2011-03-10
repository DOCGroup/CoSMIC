// -*- C++ -*-

//============================================================================
/**
 * @file    Action.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_ACTION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_ACTION_H_

#include "game/mga/Model.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Action_Impl;
  typedef Action_Impl * Action_in;
  typedef ::GAME::Mga::Smart_Ptr <Action_Impl> Action;

  // Forward decl.
  class Visitor;

  class PICML_Export Action_Impl :
    public virtual ActionBase_Impl,
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Action_Impl (void);

    /// Initializing constructor
    Action_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Action_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    ActionType get_ActionType (void) const;
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
