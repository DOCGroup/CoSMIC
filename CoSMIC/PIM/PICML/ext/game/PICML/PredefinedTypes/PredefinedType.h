// -*- C++ -*-

//============================================================================
/**
 * @file    PredefinedType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_PREDEFINEDTYPE_H_
#define _PICML_PREDEFINEDTYPES_PREDEFINEDTYPE_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PredefinedType_Impl;
  typedef PredefinedType_Impl * PredefinedType_in;
  typedef ::GAME::Mga::Smart_Ptr <PredefinedType_Impl> PredefinedType;

  class PICML_Export PredefinedType_Impl :
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
    PredefinedType_Impl (void);

    /// Initializing constructor
    PredefinedType_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~PredefinedType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    PredefinedTypes parent_PredefinedTypes (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
