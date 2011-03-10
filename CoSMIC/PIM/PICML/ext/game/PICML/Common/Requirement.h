// -*- C++ -*-

//============================================================================
/**
 * @file    Requirement.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_REQUIREMENT_H_
#define _PICML_COMMON_REQUIREMENT_H_

#include "game/mga/Model.h"
#include "PICML/Common/RequirementBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Requirement_Impl;
  typedef Requirement_Impl * Requirement_in;
  typedef ::GAME::Mga::Smart_Ptr <Requirement_Impl> Requirement;

  // Forward decl.
  class Visitor;

  class PICML_Export Requirement_Impl :
    public virtual RequirementBase_Impl,
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
    Requirement_Impl (void);

    /// Initializing constructor
    Requirement_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Requirement_Impl (void);

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
