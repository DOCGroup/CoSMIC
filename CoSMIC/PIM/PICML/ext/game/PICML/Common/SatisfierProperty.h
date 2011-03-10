// -*- C++ -*-

//============================================================================
/**
 * @file    SatisfierProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_SATISFIERPROPERTY_H_
#define _PICML_COMMON_SATISFIERPROPERTY_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SatisfierProperty_Impl;
  typedef SatisfierProperty_Impl * SatisfierProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <SatisfierProperty_Impl> SatisfierProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export SatisfierProperty_Impl :
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
    SatisfierProperty_Impl (void);

    /// Initializing constructor
    SatisfierProperty_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~SatisfierProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static SatisfierProperty _create (const RequirementSatisfier_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    DataType get_DataType (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    RequirementSatisfier parent_RequirementSatisfier (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
