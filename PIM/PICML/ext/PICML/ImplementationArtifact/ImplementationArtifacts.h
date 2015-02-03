// -*- C++ -*-

//============================================================================
/**
 * @file    ImplementationArtifacts.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONARTIFACT_IMPLEMENTATIONARTIFACTS_H_
#define _PICML_IMPLEMENTATIONARTIFACT_IMPLEMENTATIONARTIFACTS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationArtifacts_Impl;
  typedef ImplementationArtifacts_Impl * ImplementationArtifacts_in;
  typedef ::GAME::Mga::Smart_Ptr < ImplementationArtifacts_Impl > ImplementationArtifacts;

  // Forward decl.
  class Visitor;

  /**
   * @class ImplementationArtifacts_Impl
   *
   * Implementation for the ImplementationArtifacts model element.
   */
  class PICML_Export ImplementationArtifacts_Impl :
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
    static ImplementationArtifacts _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    ImplementationArtifacts_Impl (void);

    // Initializing constructor.
    ImplementationArtifacts_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~ImplementationArtifacts_Impl (void);

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

    size_t get_ArtifactContainers (std::vector <ArtifactContainer> & items) const;

    ::GAME::Mga::Collection_T <ArtifactContainer> get_ArtifactContainers (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ImplementationArtifacts.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONARTIFACT_IMPLEMENTATIONARTIFACTS
