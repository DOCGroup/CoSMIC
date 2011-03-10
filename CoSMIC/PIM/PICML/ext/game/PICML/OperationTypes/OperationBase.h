// -*- C++ -*-

//============================================================================
/**
 * @file    OperationBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_OPERATIONBASE_H_
#define _PICML_OPERATIONTYPES_OPERATIONBASE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OperationBase_Impl;
  typedef OperationBase_Impl * OperationBase_in;
  typedef ::GAME::Mga::Smart_Ptr <OperationBase_Impl> OperationBase;

  class PICML_Export OperationBase_Impl :
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
    OperationBase_Impl (void);

    /// Initializing constructor
    OperationBase_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~OperationBase_Impl (void) = 0;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_InParameters (std::vector <InParameter> & items) const;
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
