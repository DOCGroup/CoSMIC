// -*- C++ -*-

//============================================================================
/**
 * @file    ComplexProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_COMPLEXPROPERTY_H_
#define _PICML_COMMON_COMPLEXPROPERTY_H_

#include "game/mga/Model.h"
#include "PICML/Common/Property.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComplexProperty_Impl;
  typedef ComplexProperty_Impl * ComplexProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <ComplexProperty_Impl> ComplexProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export ComplexProperty_Impl :
    public virtual Property_Impl,
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
    ComplexProperty_Impl (void);

    /// Initializing constructor
    ComplexProperty_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ComplexProperty_Impl (void);

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
    size_t get_DataValueBases (std::vector <DataValueBase> & items) const;

    ComplexTypeReference get_ComplexTypeReference (void) const;
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
