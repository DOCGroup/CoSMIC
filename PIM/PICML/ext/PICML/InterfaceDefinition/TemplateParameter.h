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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentType/EventType.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Provideable.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TemplateParameter_Impl;
  typedef TemplateParameter_Impl * TemplateParameter_in;
  typedef ::GAME::Mga::Smart_Ptr < TemplateParameter_Impl > TemplateParameter;

  /**
   * @class TemplateParameter_Impl
   *
   * Implementation for the TemplateParameter model element.
   */
  class PICML_Export TemplateParameter_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual EventType_Impl,
    public virtual MemberType_Impl,
    public virtual Provideable_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    TemplateParameter_Impl (void);

    // Initializing constructor.
    TemplateParameter_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~TemplateParameter_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    Package parent_Package (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TemplateParameter.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETER
