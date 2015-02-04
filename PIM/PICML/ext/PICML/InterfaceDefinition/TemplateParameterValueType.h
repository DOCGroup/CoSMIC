// -*- C++ -*-

//============================================================================
/**
 * @file    TemplateParameterValueType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETERVALUETYPE_H_
#define _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETERVALUETYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TemplateParameterValueType_Impl;
  typedef TemplateParameterValueType_Impl * TemplateParameterValueType_in;
  typedef ::GAME::Mga::Smart_Ptr < TemplateParameterValueType_Impl > TemplateParameterValueType;

  /**
   * @class TemplateParameterValueType_Impl
   *
   * Implementation for the TemplateParameterValueType model element.
   */
  class PICML_Export TemplateParameterValueType_Impl :
    public virtual ::GAME::Mga::FCO_Impl
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
    TemplateParameterValueType_Impl (void);

    // Initializing constructor.
    TemplateParameterValueType_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~TemplateParameterValueType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TemplateParameterValueType.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETERVALUETYPE
