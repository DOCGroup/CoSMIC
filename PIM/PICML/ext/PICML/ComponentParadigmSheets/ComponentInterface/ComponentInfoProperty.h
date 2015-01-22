// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentInfoProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTINFOPROPERTY_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTINFOPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentInfoProperty_Impl;
  typedef ComponentInfoProperty_Impl * ComponentInfoProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentInfoProperty_Impl > ComponentInfoProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentInfoProperty_Impl
   *
   * Implementation for the ComponentInfoProperty model element.
   */
  class PICML_Export ComponentInfoProperty_Impl :
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
    static ComponentInfoProperty _create (const ComponentContainer_in parent, ComponentRef_in src, Property_in dst);
    ///@}

    // Default constructor.
    ComponentInfoProperty_Impl (void);

    // Initializing constructor.
    ComponentInfoProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ComponentInfoProperty_Impl (void);

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
#include "ComponentInfoProperty.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTINFOPROPERTY
