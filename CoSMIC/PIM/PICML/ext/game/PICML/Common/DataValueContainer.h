// -*- C++ -*-

//============================================================================
/**
 * @file    DataValueContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_DATAVALUECONTAINER_H_
#define _PICML_COMMON_DATAVALUECONTAINER_H_

#include "game/mga/Model.h"
#include "PICML/Common/DataValueBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DataValueContainer_Impl;
  typedef DataValueContainer_Impl * DataValueContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <DataValueContainer_Impl> DataValueContainer;

  // Forward decl.
  class Visitor;

  class PICML_Export DataValueContainer_Impl :
    public virtual DataValueBase_Impl,
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
    DataValueContainer_Impl (void);

    /// Initializing constructor
    DataValueContainer_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~DataValueContainer_Impl (void);

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
