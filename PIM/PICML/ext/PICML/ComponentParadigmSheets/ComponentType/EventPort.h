// -*- C++ -*-

//============================================================================
/**
 * @file    EventPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EVENTPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EVENTPORT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EventPort_Impl;
  typedef EventPort_Impl * EventPort_in;
  typedef ::GAME::Mga::Smart_Ptr < EventPort_Impl > EventPort;

  /**
   * @class EventPort_Impl
   *
   * Implementation for the EventPort model element.
   */
  class PICML_Export EventPort_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual Port_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    EventPort_Impl (void);

    // Initializing constructor.
    EventPort_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~EventPort_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "EventPort.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EVENTPORT
