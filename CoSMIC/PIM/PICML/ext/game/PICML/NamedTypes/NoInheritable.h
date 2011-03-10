// -*- C++ -*-

//============================================================================
/**
 * @file    NoInheritable.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_NOINHERITABLE_H_
#define _PICML_NAMEDTYPES_NOINHERITABLE_H_

#include "game/mga/FCO.h"
#include "PICML/NamedTypes/NamedType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class NoInheritable_Impl;
  typedef NoInheritable_Impl * NoInheritable_in;
  typedef ::GAME::Mga::Smart_Ptr <NoInheritable_Impl> NoInheritable;

  class PICML_Export NoInheritable_Impl :
    public virtual NamedType_Impl,
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
    NoInheritable_Impl (void);

    /// Initializing constructor
    NoInheritable_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~NoInheritable_Impl (void) = 0;

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
