// -*- C++ -*-

//============================================================================
/**
 * @file    ExceptionType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_EXCEPTIONTYPE_H_
#define _PICML_INTERFACEDEFINITION_EXCEPTIONTYPE_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExceptionType_Impl;
  typedef ExceptionType_Impl * ExceptionType_in;
  typedef ::GAME::Mga::Smart_Ptr <ExceptionType_Impl> ExceptionType;

  class PICML_Export ExceptionType_Impl :
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
    ExceptionType_Impl (void);

    /// Initializing constructor
    ExceptionType_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~ExceptionType_Impl (void) = 0;

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
