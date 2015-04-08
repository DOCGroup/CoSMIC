// -*- C++ -*-

//============================================================================
/**
 * @file    QueryInputAction.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_QUERYINPUTACTION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_QUERYINPUTACTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class QueryInputAction_Impl;
  typedef QueryInputAction_Impl * QueryInputAction_in;
  typedef ::GAME::Mga::Smart_Ptr < QueryInputAction_Impl > QueryInputAction;

  // Forward decl.
  class Visitor;

  /**
   * @class QueryInputAction_Impl
   *
   * Implementation for the QueryInputAction model element.
   */
  class PICML_Export QueryInputAction_Impl :
    public virtual ::GAME::Mga::Model_Impl
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
    static QueryInputAction _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    QueryInputAction_Impl (void);

    // Initializing constructor.
    QueryInputAction_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~QueryInputAction_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BehaviorModel parent_BehaviorModel (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst QueryInput connection.
    size_t dst_of_QueryInput (std::vector <QueryInput> & items) const;
    bool has_dst_of_QueryInput (void) const;
    QueryInput dst_of_QueryInput (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "QueryInputAction.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_QUERYINPUTACTION
