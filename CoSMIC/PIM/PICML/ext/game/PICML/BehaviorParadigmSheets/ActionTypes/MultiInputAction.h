// -*- C++ -*-

//============================================================================
/**
 * @file    MultiInputAction.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_MULTIINPUTACTION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_MULTIINPUTACTION_H_

#include "game/mga/Model.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MultiInputAction_Impl;
  typedef MultiInputAction_Impl * MultiInputAction_in;
  typedef ::GAME::Mga::Smart_Ptr <MultiInputAction_Impl> MultiInputAction;

  // Forward decl.
  class Visitor;

  class PICML_Export MultiInputAction_Impl :
    public virtual BehaviorInputAction_Impl,
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
    MultiInputAction_Impl (void);

    /// Initializing constructor
    MultiInputAction_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~MultiInputAction_Impl (void);

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
