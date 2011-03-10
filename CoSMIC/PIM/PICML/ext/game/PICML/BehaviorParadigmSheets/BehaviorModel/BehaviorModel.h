// -*- C++ -*-

//============================================================================
/**
 * @file    BehaviorModel.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_BEHAVIORMODEL_BEHAVIORMODEL_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_BEHAVIORMODEL_BEHAVIORMODEL_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BehaviorModel_Impl;
  typedef BehaviorModel_Impl * BehaviorModel_in;
  typedef ::GAME::Mga::Smart_Ptr <BehaviorModel_Impl> BehaviorModel;

  class PICML_Export BehaviorModel_Impl :
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
    BehaviorModel_Impl (void);

    /// Initializing constructor
    BehaviorModel_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~BehaviorModel_Impl (void) = 0;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Variables (std::vector <Variable> & items) const;
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
