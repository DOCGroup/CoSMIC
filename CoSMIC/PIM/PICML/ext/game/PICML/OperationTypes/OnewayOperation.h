// -*- C++ -*-

//============================================================================
/**
 * @file    OnewayOperation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_ONEWAYOPERATION_H_
#define _PICML_OPERATIONTYPES_ONEWAYOPERATION_H_

#include "game/mga/Model.h"
#include "PICML/OperationTypes/OperationBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OnewayOperation_Impl;
  typedef OnewayOperation_Impl * OnewayOperation_in;
  typedef ::GAME::Mga::Smart_Ptr <OnewayOperation_Impl> OnewayOperation;

  // Forward decl.
  class Visitor;

  class PICML_Export OnewayOperation_Impl :
    public virtual OperationBase_Impl,
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
    OnewayOperation_Impl (void);

    /// Initializing constructor
    OnewayOperation_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~OnewayOperation_Impl (void);

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
