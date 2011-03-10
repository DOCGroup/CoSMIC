// -*- C++ -*-

//============================================================================
/**
 * @file    BehaviorInputAction.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_BEHAVIORINPUTACTION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_BEHAVIORINPUTACTION_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BehaviorInputAction_Impl;
  typedef BehaviorInputAction_Impl * BehaviorInputAction_in;
  typedef ::GAME::Mga::Smart_Ptr <BehaviorInputAction_Impl> BehaviorInputAction;

  class PICML_Export BehaviorInputAction_Impl :
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
    BehaviorInputAction_Impl (void);

    /// Initializing constructor
    BehaviorInputAction_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~BehaviorInputAction_Impl (void) = 0;
    size_t in_InputEffect_connections (std::vector <InputEffect> & conns) const;
    size_t in_Finish_connections (std::vector <Finish> & conns) const;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Propertys (std::vector <Property> & items) const;
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
