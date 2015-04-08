// -*- C++ -*-

//============================================================================
/**
 * @file    TypeParameter.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_TYPEPARAMETER_H_
#define _PICML_INTERFACEDEFINITION_TYPEPARAMETER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/ExceptionType.h"
#include "PICML/ComponentParadigmSheets/ComponentType/LookupKeyType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TypeParameter_Impl;
  typedef TypeParameter_Impl * TypeParameter_in;
  typedef ::GAME::Mga::Smart_Ptr < TypeParameter_Impl > TypeParameter;

  // Forward decl.
  class Visitor;

  /**
   * @class TypeParameter_Impl
   *
   * Implementation for the TypeParameter model element.
   */
  class PICML_Export TypeParameter_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual TemplateParameter_Impl,
    public virtual ExceptionType_Impl,
    public virtual LookupKeyType_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static TypeParameter _create (const Package_in parent);
    ///@}

    // Default constructor.
    TypeParameter_Impl (void);

    // Initializing constructor.
    TypeParameter_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~TypeParameter_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Type
    void Type (const std::string & val);

    /// Get the value of Type
    std::string Type (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TypeParameter.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_TYPEPARAMETER
