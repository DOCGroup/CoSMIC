// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentOperation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_COMPONENTOPERATION_H_
#define _PICML_COMPONENTBENCHMARK_COMPONENTOPERATION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentOperation_Impl;
  typedef ComponentOperation_Impl * ComponentOperation_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentOperation_Impl > ComponentOperation;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentOperation_Impl
   *
   * Implementation for the ComponentOperation model element.
   */
  class PICML_Export ComponentOperation_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentOperation _create (const BenchmarkAnalysis_in parent, OperationRef_in src, CompRef_in dst);
    ///@}

    // Default constructor.
    ComponentOperation_Impl (void);

    // Initializing constructor.
    ComponentOperation_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ComponentOperation_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}
    OperationRef src_OperationRef (void) const;
    CompRef dst_CompRef (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentOperation.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_COMPONENTOPERATION
