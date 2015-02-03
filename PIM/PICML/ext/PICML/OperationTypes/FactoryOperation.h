// -*- C++ -*-

//============================================================================
/**
 * @file    FactoryOperation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_FACTORYOPERATION_H_
#define _PICML_OPERATIONTYPES_FACTORYOPERATION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/OperationTypes/HasExceptions.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class FactoryOperation_Impl;
  typedef FactoryOperation_Impl * FactoryOperation_in;
  typedef ::GAME::Mga::Smart_Ptr < FactoryOperation_Impl > FactoryOperation;

  // Forward decl.
  class Visitor;

  /**
   * @class FactoryOperation_Impl
   *
   * Implementation for the FactoryOperation model element.
   */
  class PICML_Export FactoryOperation_Impl :
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


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static FactoryOperation _create (const ComponentFactory_in parent);
    static FactoryOperation _create (const ObjectByValue_in parent);
    static FactoryOperation _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    FactoryOperation_Impl (void);

    // Initializing constructor.
    FactoryOperation_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~FactoryOperation_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentFactory parent_ComponentFactory (void);
    ObjectByValue parent_ObjectByValue (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "FactoryOperation.inl"
#endif

#endif  // !defined _PICML_OPERATIONTYPES_FACTORYOPERATION
