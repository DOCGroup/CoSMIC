// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorImplementations.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATIONS_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATIONS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorImplementations_Impl;
  typedef ConnectorImplementations_Impl * ConnectorImplementations_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectorImplementations_Impl > ConnectorImplementations;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectorImplementations_Impl
   *
   * Implementation for the ConnectorImplementations model element.
   */
  class PICML_Export ConnectorImplementations_Impl :
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
    static ConnectorImplementations _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    ConnectorImplementations_Impl (void);

    // Initializing constructor.
    ConnectorImplementations_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~ConnectorImplementations_Impl (void);

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

    size_t get_ConnectorImplementationContainers (std::vector <ConnectorImplementationContainer> & items) const;

    ::GAME::Mga::Collection_T <ConnectorImplementationContainer> get_ConnectorImplementationContainers (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectorImplementations.inl"
#endif

#endif  // !defined _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATIONS
