// -*- C++ -*-

//============================================================================
/**
 * @file    ObjectPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_OBJECTPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_OBJECTPORT_H_

#include "game/mga/FCO.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ObjectPort_Impl;
  typedef ObjectPort_Impl * ObjectPort_in;
  typedef ::GAME::Mga::Smart_Ptr <ObjectPort_Impl> ObjectPort;

  class PICML_Export ObjectPort_Impl :
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
    ObjectPort_Impl (void);

    /// Initializing constructor
    ObjectPort_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~ObjectPort_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    PortType parent_PortType (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
