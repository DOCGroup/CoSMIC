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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/OperationTypes/HasExceptions.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LookupOperation_Impl;
  typedef LookupOperation_Impl * LookupOperation_in;
  typedef ::GAME::Mga::Smart_Ptr < LookupOperation_Impl > LookupOperation;

  // Forward decl.
  class Visitor;

  /**
   * @class LookupOperation_Impl
   *
   * Implementation for the LookupOperation model element.
   */
  class PICML_Export LookupOperation_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual HasExceptions_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static LookupOperation _create (const ComponentFactory_in parent);
    static LookupOperation _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    LookupOperation_Impl (void);

    // Initializing constructor.
    LookupOperation_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~LookupOperation_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentFactory parent_ComponentFactory (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "LookupOperation.inl"
#endif

#endif  // !defined _PICML_OPERATIONTYPES_LOOKUPOPERATION
