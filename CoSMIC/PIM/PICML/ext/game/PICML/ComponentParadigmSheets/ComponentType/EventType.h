// -*- C++ -*-

//============================================================================
/**
 * @file    EventType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EVENTTYPE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EVENTTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EventType_Impl;
  typedef EventType_Impl * EventType_in;
  typedef ::GAME::Mga::Smart_Ptr < EventType_Impl > EventType;

  /**
   * @class EventType_Impl
   *
   * Implementation for the EventType model element.
   */
  class PICML_Export EventType_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    EventType_Impl (void);

    // Initializing constructor.
    EventType_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~EventType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "EventType.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EVENTTYPE
