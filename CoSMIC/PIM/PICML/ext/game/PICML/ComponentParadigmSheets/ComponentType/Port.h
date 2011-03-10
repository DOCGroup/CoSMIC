// -*- C++ -*-

//============================================================================
/**
 * @file    Port.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PORT_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Port_Impl;
  typedef Port_Impl * Port_in;
  typedef ::GAME::Mga::Smart_Ptr <Port_Impl> Port;

  class PICML_Export Port_Impl :
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
    Port_Impl (void);

    /// Initializing constructor
    Port_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~Port_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    Component parent_Component (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
