// -*- C++ -*-

//============================================================================
/**
 * @file    Manageable.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MANAGEABLE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MANAGEABLE_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Manageable_Impl;
  typedef Manageable_Impl * Manageable_in;
  typedef ::GAME::Mga::Smart_Ptr <Manageable_Impl> Manageable;

  class PICML_Export Manageable_Impl :
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
    Manageable_Impl (void);

    /// Initializing constructor
    Manageable_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~Manageable_Impl (void) = 0;
    size_t in_ManagesComponent_connections (std::vector <ManagesComponent> & conns) const;

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
