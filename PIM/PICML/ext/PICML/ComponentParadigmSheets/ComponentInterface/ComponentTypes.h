// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentTypes.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTTYPES_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTTYPES_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentTypes_Impl;
  typedef ComponentTypes_Impl * ComponentTypes_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentTypes_Impl > ComponentTypes;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentTypes_Impl
   *
   * Implementation for the ComponentTypes model element.
   */
  class PICML_Export ComponentTypes_Impl :
    public virtual ::GAME::Mga::Folder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentTypes _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    ComponentTypes_Impl (void);

    // Initializing constructor.
    ComponentTypes_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~ComponentTypes_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RootFolder parent_RootFolder (void);
    ///@}

    size_t get_ComponentContainers (std::vector <ComponentContainer> & items) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentTypes.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTTYPES
