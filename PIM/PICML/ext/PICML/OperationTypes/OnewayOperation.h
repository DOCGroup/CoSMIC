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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/OperationTypes/OperationBase.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OnewayOperation_Impl;
  typedef OnewayOperation_Impl * OnewayOperation_in;
  typedef ::GAME::Mga::Smart_Ptr < OnewayOperation_Impl > OnewayOperation;

  // Forward decl.
  class Visitor;

  /**
   * @class OnewayOperation_Impl
   *
   * Implementation for the OnewayOperation model element.
   */
  class PICML_Export OnewayOperation_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual OperationBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static OnewayOperation _create (const HasOperations_in parent);
    static OnewayOperation _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    OnewayOperation_Impl (void);

    // Initializing constructor.
    OnewayOperation_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~OnewayOperation_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    HasOperations parent_HasOperations (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "OnewayOperation.inl"
#endif

#endif  // !defined _PICML_OPERATIONTYPES_ONEWAYOPERATION
