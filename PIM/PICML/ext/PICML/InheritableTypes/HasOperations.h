// -*- C++ -*-

//============================================================================
/**
 * @file    HasOperations.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_HASOPERATIONS_H_
#define _PICML_INHERITABLETYPES_HASOPERATIONS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InheritableTypes/Inheritable.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class HasOperations_Impl;
  typedef HasOperations_Impl * HasOperations_in;
  typedef ::GAME::Mga::Smart_Ptr < HasOperations_Impl > HasOperations;

  /**
   * @class HasOperations_Impl
   *
   * Implementation for the HasOperations model element.
   */
  class PICML_Export HasOperations_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual Inheritable_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    HasOperations_Impl (void);

    // Initializing constructor.
    HasOperations_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~HasOperations_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_OnewayOperations (std::vector <OnewayOperation> & items) const;
    ::GAME::Mga::Collection_T <OnewayOperation> get_OnewayOperations (void) const;

    size_t get_Exceptions (std::vector <Exception> & items) const;
    ::GAME::Mga::Collection_T <Exception> get_Exceptions (void) const;

    size_t get_TwowayOperations (std::vector <TwowayOperation> & items) const;
    ::GAME::Mga::Collection_T <TwowayOperation> get_TwowayOperations (void) const;

    size_t get_Constants (std::vector <Constant> & items) const;
    ::GAME::Mga::Collection_T <Constant> get_Constants (void) const;

    size_t get_PortTypes (std::vector <PortType> & items) const;
    ::GAME::Mga::Collection_T <PortType> get_PortTypes (void) const;

    size_t get_Aggregates (std::vector <Aggregate> & items) const;
    ::GAME::Mga::Collection_T <Aggregate> get_Aggregates (void) const;

    size_t get_Collections (std::vector <Collection> & items) const;
    ::GAME::Mga::Collection_T <Collection> get_Collections (void) const;

    size_t get_SwitchedAggregates (std::vector <SwitchedAggregate> & items) const;
    ::GAME::Mga::Collection_T <SwitchedAggregate> get_SwitchedAggregates (void) const;

    size_t get_Enums (std::vector <Enum> & items) const;
    ::GAME::Mga::Collection_T <Enum> get_Enums (void) const;

    size_t get_Aliass (std::vector <Alias> & items) const;
    ::GAME::Mga::Collection_T <Alias> get_Aliass (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "HasOperations.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_HASOPERATIONS
