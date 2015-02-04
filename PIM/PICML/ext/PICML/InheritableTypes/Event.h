// -*- C++ -*-

//============================================================================
/**
 * @file    Event.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_EVENT_H_
#define _PICML_INHERITABLETYPES_EVENT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventType.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Event_Impl;
  typedef Event_Impl * Event_in;
  typedef ::GAME::Mga::Smart_Ptr < Event_Impl > Event;

  // Forward decl.
  class Visitor;

  /**
   * @class Event_Impl
   *
   * Implementation for the Event model element.
   */
  class PICML_Export Event_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual ObjectByValue_Impl,
    public virtual EventType_Impl
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
    static Event _create (const BenchmarkAnalysis_in parent);
    static Event _create (const Package_in parent);
    static Event _create (const File_in parent);
    ///@}

    // Default constructor.
    Event_Impl (void);

    // Initializing constructor.
    Event_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Event_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Event.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_EVENT
