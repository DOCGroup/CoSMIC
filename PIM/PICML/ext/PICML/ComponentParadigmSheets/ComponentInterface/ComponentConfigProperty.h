// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentConfigProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTCONFIGPROPERTY_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTCONFIGPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentConfigProperty_Impl;
  typedef ComponentConfigProperty_Impl * ComponentConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentConfigProperty_Impl > ComponentConfigProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentConfigProperty_Impl
   *
   * Implementation for the ComponentConfigProperty model element.
   */
  class PICML_Export ComponentConfigProperty_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentConfigProperty _create (const ComponentContainer_in parent, ComponentRef_in src, Property_in dst);
    ///@}

    // Default constructor.
    ComponentConfigProperty_Impl (void);

    // Initializing constructor.
    ComponentConfigProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ComponentConfigProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentContainer parent_ComponentContainer (void);
    ///@}
    ComponentRef src_ComponentRef (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentConfigProperty.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTCONFIGPROPERTY
