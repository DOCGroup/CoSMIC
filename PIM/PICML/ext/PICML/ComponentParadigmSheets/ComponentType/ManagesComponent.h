// -*- C++ -*-

//============================================================================
/**
 * @file    ManagesComponent.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MANAGESCOMPONENT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MANAGESCOMPONENT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ManagesComponent_Impl;
  typedef ManagesComponent_Impl * ManagesComponent_in;
  typedef ::GAME::Mga::Smart_Ptr < ManagesComponent_Impl > ManagesComponent;

  // Forward decl.
  class Visitor;

  /**
   * @class ManagesComponent_Impl
   *
   * Implementation for the ManagesComponent model element.
   */
  class PICML_Export ManagesComponent_Impl :
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
    static ManagesComponent _create (const Package_in parent, ComponentFactory_in src, Manageable_in dst);
    static ManagesComponent _create (const File_in parent, ComponentFactory_in src, Manageable_in dst);
    ///@}

    // Default constructor.
    ManagesComponent_Impl (void);

    // Initializing constructor.
    ManagesComponent_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ManagesComponent_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Package parent_Package (void);
    File parent_File (void);
    ///@}
    ComponentFactory src_ComponentFactory (void) const;
    Manageable dst_Manageable (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ManagesComponent.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MANAGESCOMPONENT
