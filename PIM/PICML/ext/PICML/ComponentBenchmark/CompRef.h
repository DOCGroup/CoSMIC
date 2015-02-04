// -*- C++ -*-

//============================================================================
/**
 * @file    CompRef.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_COMPREF_H_
#define _PICML_COMPONENTBENCHMARK_COMPREF_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CompRef_Impl;
  typedef CompRef_Impl * CompRef_in;
  typedef ::GAME::Mga::Smart_Ptr < CompRef_Impl > CompRef;

  // Forward decl.
  class Visitor;

  /**
   * @class CompRef_Impl
   *
   * Implementation for the CompRef model element.
   */
  class PICML_Export CompRef_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static CompRef _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    CompRef_Impl (void);

    // Initializing constructor.
    CompRef_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~CompRef_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ComponentOperation connection.
    size_t dst_of_ComponentOperation (std::vector <ComponentOperation> & items) const;
    GAME::Mga::Collection_T <ComponentOperation> dst_of_ComponentOperation (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Component_is_nil (void) const;
    Component refers_to_Component (void) const;
    void refers_to_Component (Component_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "CompRef.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_COMPREF
