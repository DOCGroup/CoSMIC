// -*- C++ -*-

//============================================================================
/**
 * @file    Aggregate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_AGGREGATE_H_
#define _PICML_NAMEDTYPES_AGGREGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/NoInheritable.h"
#include "PICML/Common/ComplexType.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Aggregate_Impl;
  typedef Aggregate_Impl * Aggregate_in;
  typedef ::GAME::Mga::Smart_Ptr < Aggregate_Impl > Aggregate;

  // Forward decl.
  class Visitor;

  /**
   * @class Aggregate_Impl
   *
   * Implementation for the Aggregate model element.
   */
  class PICML_Export Aggregate_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual NoInheritable_Impl,
    public virtual ComplexType_Impl
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
    static Aggregate _create (const ConnectorObject_in parent);
    static Aggregate _create (const HasOperations_in parent);
    static Aggregate _create (const File_in parent);
    static Aggregate _create (const Package_in parent);
    ///@}

    // Default constructor.
    Aggregate_Impl (void);

    // Initializing constructor.
    Aggregate_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Aggregate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorObject parent_ConnectorObject (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_Key (void) const;
    Key get_Key (void) const;
    size_t get_Members (std::vector <Member> & items) const;
    ::GAME::Mga::Collection_T <Member> get_Members (void) const;

    size_t get_ArrayMembers (std::vector <ArrayMember> & items) const;
    ::GAME::Mga::Collection_T <ArrayMember> get_ArrayMembers (void) const;

    size_t get_KeyMembers (std::vector <KeyMember> & items) const;
    ::GAME::Mga::Collection_T <KeyMember> get_KeyMembers (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Aggregate.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_AGGREGATE
