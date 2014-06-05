// -*- C++ -*-

//============================================================================
/**
 * @file    SwitchedAggregate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_SWITCHEDAGGREGATE_H_
#define _PICML_NAMEDTYPES_SWITCHEDAGGREGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/NoInheritable.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SwitchedAggregate_Impl;
  typedef SwitchedAggregate_Impl * SwitchedAggregate_in;
  typedef ::GAME::Mga::Smart_Ptr < SwitchedAggregate_Impl > SwitchedAggregate;

  // Forward decl.
  class Visitor;

  /**
   * @class SwitchedAggregate_Impl
   *
   * Implementation for the SwitchedAggregate model element.
   */
  class PICML_Export SwitchedAggregate_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual NoInheritable_Impl
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
    static SwitchedAggregate _create (const HasOperations_in parent);
    static SwitchedAggregate _create (const File_in parent);
    static SwitchedAggregate _create (const Package_in parent);
    ///@}

    // Default constructor.
    SwitchedAggregate_Impl (void);

    // Initializing constructor.
    SwitchedAggregate_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~SwitchedAggregate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_Discriminator (void) const;
    Discriminator get_Discriminator (void) const;
    size_t get_Members (std::vector <Member> & items) const;
    ::GAME::Mga::Collection_T <Member> get_Members (void) const;

    size_t get_ArrayMembers (std::vector <ArrayMember> & items) const;
    ::GAME::Mga::Collection_T <ArrayMember> get_ArrayMembers (void) const;

    size_t get_Labels (std::vector <Label> & items) const;
    ::GAME::Mga::Collection_T <Label> get_Labels (void) const;

    size_t get_LabelConnections (std::vector <LabelConnection> & items) const;
    ::GAME::Mga::Collection_T <LabelConnection> get_LabelConnections (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SwitchedAggregate.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_SWITCHEDAGGREGATE
