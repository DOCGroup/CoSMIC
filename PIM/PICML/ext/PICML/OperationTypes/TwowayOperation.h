// -*- C++ -*-

//============================================================================
/**
 * @file    TwowayOperation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_TWOWAYOPERATION_H_
#define _PICML_OPERATIONTYPES_TWOWAYOPERATION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/OperationTypes/HasExceptions.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TwowayOperation_Impl;
  typedef TwowayOperation_Impl * TwowayOperation_in;
  typedef ::GAME::Mga::Smart_Ptr < TwowayOperation_Impl > TwowayOperation;

  // Forward decl.
  class Visitor;

  /**
   * @class TwowayOperation_Impl
   *
   * Implementation for the TwowayOperation model element.
   */
  class PICML_Export TwowayOperation_Impl :
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
    static TwowayOperation _create (const HasOperations_in parent);
    static TwowayOperation _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    TwowayOperation_Impl (void);

    // Initializing constructor.
    TwowayOperation_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~TwowayOperation_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    HasOperations parent_HasOperations (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ReturnType (void) const;
    ReturnType get_ReturnType (void) const;
    size_t get_OutParameters (std::vector <OutParameter> & items) const;
    ::GAME::Mga::Collection_T <OutParameter> get_OutParameters (void) const;

    size_t get_InoutParameters (std::vector <InoutParameter> & items) const;
    ::GAME::Mga::Collection_T <InoutParameter> get_InoutParameters (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TwowayOperation.inl"
#endif

#endif  // !defined _PICML_OPERATIONTYPES_TWOWAYOPERATION
