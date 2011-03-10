// -*- C++ -*-

//============================================================================
/**
 * @file    TopLevelBehavior.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_TOPLEVELBEHAVIOR_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_TOPLEVELBEHAVIOR_H_

#include "game/mga/Model.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TopLevelBehavior_Impl;
  typedef TopLevelBehavior_Impl * TopLevelBehavior_in;
  typedef ::GAME::Mga::Smart_Ptr <TopLevelBehavior_Impl> TopLevelBehavior;

  class PICML_Export TopLevelBehavior_Impl :
    public virtual BehaviorModel_Impl,
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
    TopLevelBehavior_Impl (void);

    /// Initializing constructor
    TopLevelBehavior_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~TopLevelBehavior_Impl (void) = 0;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_QueryInputs (std::vector <QueryInput> & items) const;
    size_t get_WorkerTypes (std::vector <WorkerType> & items) const;
    size_t get_Inputs (std::vector <Input> & items) const;
    size_t get_MultiInputs (std::vector <MultiInput> & items) const;
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
