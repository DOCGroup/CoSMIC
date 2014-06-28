// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentImplementations.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONS_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentImplementations_Impl;
  typedef ComponentImplementations_Impl * ComponentImplementations_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentImplementations_Impl > ComponentImplementations;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentImplementations_Impl
   *
   * Implementation for the ComponentImplementations model element.
   */
  class PICML_Export ComponentImplementations_Impl :
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
    static ComponentImplementations _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    ComponentImplementations_Impl (void);

    // Initializing constructor.
    ComponentImplementations_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~ComponentImplementations_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RootFolder parent_RootFolder (void);
    ///@}

    size_t get_ComponentImplementationContainers (std::vector <ComponentImplementationContainer> & items) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentImplementations.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONS
