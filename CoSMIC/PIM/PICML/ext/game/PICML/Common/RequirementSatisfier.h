// -*- C++ -*-

//============================================================================
/**
 * @file    RequirementSatisfier.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_REQUIREMENTSATISFIER_H_
#define _PICML_COMMON_REQUIREMENTSATISFIER_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequirementSatisfier_Impl;
  typedef RequirementSatisfier_Impl * RequirementSatisfier_in;
  typedef ::GAME::Mga::Smart_Ptr <RequirementSatisfier_Impl> RequirementSatisfier;

  class PICML_Export RequirementSatisfier_Impl :
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
    RequirementSatisfier_Impl (void);

    /// Initializing constructor
    RequirementSatisfier_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~RequirementSatisfier_Impl (void) = 0;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_SatisfierPropertys (std::vector <SatisfierProperty> & items) const;
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
