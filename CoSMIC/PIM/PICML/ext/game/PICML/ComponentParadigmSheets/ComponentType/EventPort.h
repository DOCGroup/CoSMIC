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

#include "game/mga/FCO.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EventPort_Impl;
  typedef EventPort_Impl * EventPort_in;
  typedef ::GAME::Mga::Smart_Ptr <EventPort_Impl> EventPort;

  class PICML_Export EventPort_Impl :
    public virtual Port_Impl,
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    EventPort_Impl (void);

    /// Initializing constructor
    EventPort_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~EventPort_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
