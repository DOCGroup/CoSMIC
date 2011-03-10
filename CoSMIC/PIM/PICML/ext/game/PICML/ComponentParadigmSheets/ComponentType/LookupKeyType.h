// -*- C++ -*-

//============================================================================
/**
 * @file    LookupKeyType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_LOOKUPKEYTYPE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_LOOKUPKEYTYPE_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LookupKeyType_Impl;
  typedef LookupKeyType_Impl * LookupKeyType_in;
  typedef ::GAME::Mga::Smart_Ptr <LookupKeyType_Impl> LookupKeyType;

  class PICML_Export LookupKeyType_Impl :
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
    LookupKeyType_Impl (void);

    /// Initializing constructor
    LookupKeyType_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~LookupKeyType_Impl (void) = 0;

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
