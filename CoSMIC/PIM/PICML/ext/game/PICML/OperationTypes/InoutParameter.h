// -*- C++ -*-

//============================================================================
/**
 * @file    InoutParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_INOUTPARAMETER_H_
#define _PICML_OPERATIONTYPES_INOUTPARAMETER_H_

#include "game/mga/Reference.h"
#include "PICML/OperationTypes/ParameterType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InoutParameter_Impl;
  typedef InoutParameter_Impl * InoutParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <InoutParameter_Impl> InoutParameter;

  // Forward decl.
  class Visitor;

  class PICML_Export InoutParameter_Impl :
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
    InoutParameter_Impl (void);

    /// Initializing constructor
    InoutParameter_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~InoutParameter_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static InoutParameter _create (const TwowayOperation_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    TwowayOperation parent_TwowayOperation (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
