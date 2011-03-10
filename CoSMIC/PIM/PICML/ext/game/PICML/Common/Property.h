// -*- C++ -*-

//============================================================================
/**
 * @file    Property.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_PROPERTY_H_
#define _PICML_COMMON_PROPERTY_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Property_Impl;
  typedef Property_Impl * Property_in;
  typedef ::GAME::Mga::Smart_Ptr <Property_Impl> Property;

  class PICML_Export Property_Impl :
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
    Property_Impl (void);

    /// Initializing constructor
    Property_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~Property_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    RequirementBase parent_RequirementBase (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
