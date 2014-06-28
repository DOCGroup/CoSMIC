// -*- C++ -*-

//============================================================================
/**
 * @file    Targets.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DOMAIN_TARGETS_H_
#define _PICML_DOMAIN_TARGETS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Targets_Impl;
  typedef Targets_Impl * Targets_in;
  typedef ::GAME::Mga::Smart_Ptr < Targets_Impl > Targets;

  // Forward decl.
  class Visitor;

  /**
   * @class Targets_Impl
   *
   * Implementation for the Targets model element.
   */
  class PICML_Export Targets_Impl :
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
    static Targets _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    Targets_Impl (void);

    // Initializing constructor.
    Targets_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~Targets_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RootFolder parent_RootFolder (void);
    ///@}

    size_t get_Domains (std::vector <Domain> & items) const;
  };
}

#if defined (__GAME_INLINE__)
#include "Targets.inl"
#endif

#endif  // !defined _PICML_DOMAIN_TARGETS
