// -*- C++ -*-

//============================================================================
/**
 * @file    RequirementBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_REQUIREMENTBASE_H_
#define _PICML_COMMON_REQUIREMENTBASE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequirementBase_Impl;
  typedef RequirementBase_Impl * RequirementBase_in;
  typedef ::GAME::Mga::Smart_Ptr <RequirementBase_Impl> RequirementBase;

  class PICML_Export RequirementBase_Impl :
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
    RequirementBase_Impl (void);

    /// Initializing constructor
    RequirementBase_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~RequirementBase_Impl (void) = 0;

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
