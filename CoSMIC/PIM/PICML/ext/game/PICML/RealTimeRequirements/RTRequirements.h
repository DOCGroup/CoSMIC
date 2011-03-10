// -*- C++ -*-

//============================================================================
/**
 * @file    RTRequirements.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_REALTIMEREQUIREMENTS_RTREQUIREMENTS_H_
#define _PICML_REALTIMEREQUIREMENTS_RTREQUIREMENTS_H_

#include "game/mga/Model.h"
#include "PICML/Common/Requirement.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RTRequirements_Impl;
  typedef RTRequirements_Impl * RTRequirements_in;
  typedef ::GAME::Mga::Smart_Ptr <RTRequirements_Impl> RTRequirements;

  // Forward decl.
  class Visitor;

  class PICML_Export RTRequirements_Impl :
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
    RTRequirements_Impl (void);

    /// Initializing constructor
    RTRequirements_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~RTRequirements_Impl (void);

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

    ServiceProvider get_ServiceProvider (void) const;

    ServiceConsumer get_ServiceConsumer (void) const;
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
