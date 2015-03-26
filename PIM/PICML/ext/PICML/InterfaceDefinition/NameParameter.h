// -*- C++ -*-

//============================================================================
/**
 * @file    NameParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_NAMEPARAMETER_H_
#define _PICML_INTERFACEDEFINITION_NAMEPARAMETER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class NameParameter_Impl;
  typedef NameParameter_Impl * NameParameter_in;
  typedef ::GAME::Mga::Smart_Ptr < NameParameter_Impl > NameParameter;

  // Forward decl.
  class Visitor;

  /**
   * @class NameParameter_Impl
   *
   * Implementation for the NameParameter model element.
   */
  class PICML_Export NameParameter_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual TemplateParameter_Impl
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
    static NameParameter _create (const Package_in parent);
    ///@}

    // Default constructor.
    NameParameter_Impl (void);

    // Initializing constructor.
    NameParameter_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~NameParameter_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "NameParameter.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_NAMEPARAMETER
