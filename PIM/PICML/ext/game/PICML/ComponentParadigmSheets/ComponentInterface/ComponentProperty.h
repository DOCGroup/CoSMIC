// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTPROPERTY_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentProperty_Impl;
  typedef ComponentProperty_Impl * ComponentProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentProperty_Impl > ComponentProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentProperty_Impl
   *
   * Implementation for the ComponentProperty model element.
   */
  class PICML_Export ComponentProperty_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentProperty _create (const ComponentContainer_in parent);
    ///@}

    // Default constructor.
    ComponentProperty_Impl (void);

    // Initializing constructor.
    ComponentProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ComponentProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentContainer parent_ComponentContainer (void);
    ///@}
    ComponentRef src_ComponentRef (void) const;
    ComponentPropertyDescription dst_ComponentPropertyDescription (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentProperty.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTPROPERTY
