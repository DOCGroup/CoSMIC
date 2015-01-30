// -*- C++ -*-

//============================================================================
/**
 * @file    TemplateParameterReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETERREFERENCE_H_
#define _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETERREFERENCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/MemberType.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TemplateParameterReference_Impl;
  typedef TemplateParameterReference_Impl * TemplateParameterReference_in;
  typedef ::GAME::Mga::Smart_Ptr < TemplateParameterReference_Impl > TemplateParameterReference;

  // Forward decl.
  class Visitor;

  /**
   * @class TemplateParameterReference_Impl
   *
   * Implementation for the TemplateParameterReference model element.
   */
  class PICML_Export TemplateParameterReference_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual MemberType_Impl
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
    static TemplateParameterReference _create (const TemplatePackageAlias_in parent);
    ///@}

    // Default constructor.
    TemplateParameterReference_Impl (void);

    // Initializing constructor.
    TemplateParameterReference_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~TemplateParameterReference_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TemplatePackageAlias parent_TemplatePackageAlias (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool TemplateParameter_is_nil (void) const;
    TemplateParameter refers_to_TemplateParameter (void) const;
    void refers_to_TemplateParameter (TemplateParameter_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TemplateParameterReference.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_TEMPLATEPARAMETERREFERENCE
