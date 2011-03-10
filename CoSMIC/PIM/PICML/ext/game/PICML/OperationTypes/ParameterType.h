// -*- C++ -*-

//============================================================================
/**
 * @file    ParameterType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_PARAMETERTYPE_H_
#define _PICML_OPERATIONTYPES_PARAMETERTYPE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ParameterType_Impl;
  typedef ParameterType_Impl * ParameterType_in;
  typedef ::GAME::Mga::Smart_Ptr <ParameterType_Impl> ParameterType;

  class PICML_Export ParameterType_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ParameterType_Impl (void);

    /// Initializing constructor
    ParameterType_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ParameterType_Impl (void) = 0;

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
