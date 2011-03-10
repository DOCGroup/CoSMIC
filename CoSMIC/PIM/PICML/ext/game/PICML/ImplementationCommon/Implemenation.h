// -*- C++ -*-

//============================================================================
/**
 * @file    Implemenation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_IMPLEMENATION_H_
#define _PICML_IMPLEMENTATIONCOMMON_IMPLEMENATION_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Implemenation_Impl;
  typedef Implemenation_Impl * Implemenation_in;
  typedef ::GAME::Mga::Smart_Ptr <Implemenation_Impl> Implemenation;

  class PICML_Export Implemenation_Impl :
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
    Implemenation_Impl (void);

    /// Initializing constructor
    Implemenation_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~Implemenation_Impl (void) = 0;
    size_t in_InfoProperty_connections (std::vector <InfoProperty> & conns) const;
    size_t in_ConfigProperty_connections (std::vector <ConfigProperty> & conns) const;

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
