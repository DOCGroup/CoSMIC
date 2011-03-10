// -*- C++ -*-

//============================================================================
/**
 * @file    ConstantType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_CONSTANTTYPE_H_
#define _PICML_INTERFACEDEFINITION_CONSTANTTYPE_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConstantType_Impl;
  typedef ConstantType_Impl * ConstantType_in;
  typedef ::GAME::Mga::Smart_Ptr <ConstantType_Impl> ConstantType;

  class PICML_Export ConstantType_Impl :
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
    ConstantType_Impl (void);

    /// Initializing constructor
    ConstantType_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~ConstantType_Impl (void) = 0;

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
