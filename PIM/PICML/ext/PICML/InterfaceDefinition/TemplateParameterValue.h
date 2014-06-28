// -*- C++ -*-

//============================================================================
/**
 * @file    TemplateParameterValue.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETERVALUE_H_
#define _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETERVALUE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TemplateParameterValue_Impl;
  typedef TemplateParameterValue_Impl * TemplateParameterValue_in;
  typedef ::GAME::Mga::Smart_Ptr < TemplateParameterValue_Impl > TemplateParameterValue;

  // Forward decl.
  class Visitor;

  /**
   * @class TemplateParameterValue_Impl
   *
   * Implementation for the TemplateParameterValue model element.
   */
  class PICML_Export TemplateParameterValue_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static TemplateParameterValue _create (const TemplatePackageInstance_in parent);
    ///@}

    // Default constructor.
    TemplateParameterValue_Impl (void);

    // Initializing constructor.
    TemplateParameterValue_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~TemplateParameterValue_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TemplatePackageInstance parent_TemplatePackageInstance (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool TemplateParameterValueType_is_nil (void) const;
    TemplateParameterValueType get_TemplateParameterValueType (void) const;
    void set_TemplateParameterValueType (TemplateParameterValueType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TemplateParameterValue.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETERVALUE
