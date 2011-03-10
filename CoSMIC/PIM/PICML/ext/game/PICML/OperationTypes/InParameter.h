// -*- C++ -*-

//============================================================================
/**
 * @file    InParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_INPARAMETER_H_
#define _PICML_OPERATIONTYPES_INPARAMETER_H_

#include "game/mga/Reference.h"
#include "PICML/OperationTypes/ParameterType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InParameter_Impl;
  typedef InParameter_Impl * InParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <InParameter_Impl> InParameter;

  // Forward decl.
  class Visitor;

  class PICML_Export InParameter_Impl :
    public virtual ParameterType_Impl,
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    InParameter_Impl (void);

    /// Initializing constructor
    InParameter_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~InParameter_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static InParameter _create (const OperationBase_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    OperationBase parent_OperationBase (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
