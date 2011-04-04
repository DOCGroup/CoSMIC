// -*- C++ -*-

//============================================================================
/**
 * @file    TemplateParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETER_H_
#define _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETER_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TemplateParameter_Impl;
  typedef TemplateParameter_Impl * TemplateParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <TemplateParameter_Impl> TemplateParameter;

  class PICML_Export TemplateParameter_Impl :
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
    TemplateParameter_Impl (void);

    /// Initializing constructor
    TemplateParameter_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~TemplateParameter_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    Package parent_Package (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif