// -*- C++ -*-

//============================================================================
/**
 * @file    ECRequirements.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_EVENTCHANNELREQUIREMENTS_ECREQUIREMENTS_H_
#define _PICML_EVENTCHANNELREQUIREMENTS_ECREQUIREMENTS_H_

#include "game/mga/Model.h"
#include "PICML/Common/Requirement.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ECRequirements_Impl;
  typedef ECRequirements_Impl * ECRequirements_in;
  typedef ::GAME::Mga::Smart_Ptr <ECRequirements_Impl> ECRequirements;

  // Forward decl.
  class Visitor;

  class PICML_Export ECRequirements_Impl :
    public virtual Requirement_Impl,
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
    ECRequirements_Impl (void);

    /// Initializing constructor
    ECRequirements_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ECRequirements_Impl (void);

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

    /// Set the value of ConfigureRTQoS
    void ConfigureRTQoS (bool val);

    /// Get the value of ConfigureRTQoS
    bool ConfigureRTQoS (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    ECBehavior get_ECBehavior (void) const;
    size_t get_ECRoles (std::vector <ECRole> & items) const;
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