// -*- C++ -*-

//============================================================================
/**
 * @file    CommonPortAttrs.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMMONPORTATTRS_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMMONPORTATTRS_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CommonPortAttrs_Impl;
  typedef CommonPortAttrs_Impl * CommonPortAttrs_in;
  typedef ::GAME::Mga::Smart_Ptr <CommonPortAttrs_Impl> CommonPortAttrs;

  class PICML_Export CommonPortAttrs_Impl :
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
    CommonPortAttrs_Impl (void);

    /// Initializing constructor
    CommonPortAttrs_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~CommonPortAttrs_Impl (void) = 0;

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
