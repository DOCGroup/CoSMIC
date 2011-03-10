// -*- C++ -*-

//============================================================================
/**
 * @file    LookupOperation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_LOOKUPOPERATION_H_
#define _PICML_OPERATIONTYPES_LOOKUPOPERATION_H_

#include "game/mga/Model.h"
#include "PICML/OperationTypes/HasExceptions.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LookupOperation_Impl;
  typedef LookupOperation_Impl * LookupOperation_in;
  typedef ::GAME::Mga::Smart_Ptr <LookupOperation_Impl> LookupOperation;

  // Forward decl.
  class Visitor;

  class PICML_Export LookupOperation_Impl :
    public virtual HasExceptions_Impl,
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
    LookupOperation_Impl (void);

    /// Initializing constructor
    LookupOperation_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~LookupOperation_Impl (void);

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
