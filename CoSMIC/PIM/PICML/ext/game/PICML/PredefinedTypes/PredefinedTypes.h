// -*- C++ -*-

//============================================================================
/**
 * @file    PredefinedTypes.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_PREDEFINEDTYPES_H_
#define _PICML_PREDEFINEDTYPES_PREDEFINEDTYPES_H_

#include "game/mga/Folder.h"
#include "game/mga/RootFolder.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PredefinedTypes_Impl;
  typedef PredefinedTypes_Impl * PredefinedTypes_in;
  typedef ::GAME::Mga::Smart_Ptr <PredefinedTypes_Impl> PredefinedTypes;

  // Forward decl.
  class Visitor;

  class PICML_Export PredefinedTypes_Impl :
    public virtual ::GAME::Mga::Folder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    PredefinedTypes_Impl (void);

    /// Initializing constructor
    PredefinedTypes_Impl (IMgaFolder * ptr);

    /// Destructor
    virtual ~PredefinedTypes_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PredefinedTypes _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ::GAME::Mga::RootFolder parent_RootFolder (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
