// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentInherits.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTINHERITS_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTINHERITS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentInherits_Impl;
  typedef ComponentInherits_Impl * ComponentInherits_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentInherits_Impl > ComponentInherits;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentInherits_Impl
   *
   * Implementation for the ComponentInherits model element.
   */
  class PICML_Export ComponentInherits_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentInherits _create (const Component_in parent);
    ///@}

    // Default constructor.
    ComponentInherits_Impl (void);

    // Initializing constructor.
    ComponentInherits_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ComponentInherits_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Component parent_Component (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Component_is_nil (void) const;
    Component refers_to_Component (void) const;
    void refers_to_Component (Component_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentInherits.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTINHERITS
