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

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ActionBase_Impl;
  typedef ActionBase_Impl * ActionBase_in;
  typedef ::GAME::Mga::Smart_Ptr <ActionBase_Impl> ActionBase;

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

    /// Default constructor
    ActionBase_Impl (void);

    /// Initializing constructor
    ActionBase_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ActionBase_Impl (void) = 0;

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Duration
    void Duration (long val);

    /// Get the value of Duration
    long Duration (void) const;
    ///@}
    size_t in_Effect_connections (std::vector <Effect> & conns) const;

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
