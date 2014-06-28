// -*- C++ -*-

//============================================================================
/**
 * @file    InterfaceDefinitions.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_INTERFACEDEFINITIONS_H_
#define _PICML_INTERFACEDEFINITION_INTERFACEDEFINITIONS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InterfaceDefinitions_Impl;
  typedef InterfaceDefinitions_Impl * InterfaceDefinitions_in;
  typedef ::GAME::Mga::Smart_Ptr < InterfaceDefinitions_Impl > InterfaceDefinitions;

  // Forward decl.
  class Visitor;

  /**
   * @class InterfaceDefinitions_Impl
   *
   * Implementation for the InterfaceDefinitions model element.
   */
  class PICML_Export InterfaceDefinitions_Impl :
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
    static InterfaceDefinitions _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    InterfaceDefinitions_Impl (void);

    // Initializing constructor.
    InterfaceDefinitions_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~InterfaceDefinitions_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RootFolder parent_RootFolder (void);
    ///@}

    size_t get_Files (std::vector <File> & items) const;
  };
}

#if defined (__GAME_INLINE__)
#include "InterfaceDefinitions.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_INTERFACEDEFINITIONS
