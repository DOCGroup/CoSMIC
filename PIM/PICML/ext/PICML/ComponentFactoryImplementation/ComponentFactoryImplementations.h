// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentFactoryImplementations.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTFACTORYIMPLEMENTATION_COMPONENTFACTORYIMPLEMENTATIONS_H_
#define _PICML_COMPONENTFACTORYIMPLEMENTATION_COMPONENTFACTORYIMPLEMENTATIONS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentFactoryImplementations_Impl;
  typedef ComponentFactoryImplementations_Impl * ComponentFactoryImplementations_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentFactoryImplementations_Impl > ComponentFactoryImplementations;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentFactoryImplementations_Impl
   *
   * Implementation for the ComponentFactoryImplementations model element.
   */
  class PICML_Export ComponentFactoryImplementations_Impl :
    public virtual ::GAME::Mga::Folder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentFactoryImplementations _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    ComponentFactoryImplementations_Impl (void);

    // Initializing constructor.
    ComponentFactoryImplementations_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~ComponentFactoryImplementations_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RootFolder parent_RootFolder (void);
    ///@}

    /**
     * @name Folder Getters
     */
    ///@{

    size_t get_ComponentFactoryImplementationContainers (std::vector <ComponentFactoryImplementationContainer> & items) const;

    ::GAME::Mga::Collection_T <ComponentFactoryImplementationContainer> get_ComponentFactoryImplementationContainers (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentFactoryImplementations.inl"
#endif

#endif  // !defined _PICML_COMPONENTFACTORYIMPLEMENTATION_COMPONENTFACTORYIMPLEMENTATIONS
