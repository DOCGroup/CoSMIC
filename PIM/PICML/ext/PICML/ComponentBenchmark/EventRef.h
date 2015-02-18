// -*- C++ -*-

//============================================================================
/**
 * @file    EventRef.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_EVENTREF_H_
#define _PICML_COMPONENTBENCHMARK_EVENTREF_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EventRef_Impl;
  typedef EventRef_Impl * EventRef_in;
  typedef ::GAME::Mga::Smart_Ptr < EventRef_Impl > EventRef;

  // Forward decl.
  class Visitor;

  /**
   * @class EventRef_Impl
   *
   * Implementation for the EventRef model element.
   */
  class PICML_Export EventRef_Impl :
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
    static EventRef _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    EventRef_Impl (void);

    // Initializing constructor.
    EventRef_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~EventRef_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src TimerEventSinkConn connection.
    size_t src_of_TimerEventSinkConn (std::vector <TimerEventSinkConn> & items) const;
    bool has_src_of_TimerEventSinkConn (void) const;
    TimerEventSinkConn src_of_TimerEventSinkConn (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Event_is_nil (void) const;
    Event refers_to_Event (void) const;
    void refers_to_Event (Event_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "EventRef.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_EVENTREF
