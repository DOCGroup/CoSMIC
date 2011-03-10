// -*- C++ -*-

//============================================================================
/**
 * @file    RequestAction.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_REQUESTACTION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_REQUESTACTION_H_

#include "game/mga/Model.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequestAction_Impl;
  typedef RequestAction_Impl * RequestAction_in;
  typedef ::GAME::Mga::Smart_Ptr <RequestAction_Impl> RequestAction;

  // Forward decl.
  class Visitor;

  class PICML_Export RequestAction_Impl :
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
    RequestAction_Impl (void);

    /// Initializing constructor
    RequestAction_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~RequestAction_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
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

    /**
     * @name Containment Methods
     */
    ///@{
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
