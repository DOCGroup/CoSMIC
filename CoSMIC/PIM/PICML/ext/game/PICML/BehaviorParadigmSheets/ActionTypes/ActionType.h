// -*- C++ -*-

//============================================================================
/**
 * @file    ActionType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_ACTIONTYPE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_ACTIONTYPE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ActionType_Impl;
  typedef ActionType_Impl * ActionType_in;
  typedef ::GAME::Mga::Smart_Ptr <ActionType_Impl> ActionType;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    ActionType_Impl (void);

    /// Initializing constructor
    ActionType_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ActionType_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ActionType _create (const Action_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    Action parent_Action (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
