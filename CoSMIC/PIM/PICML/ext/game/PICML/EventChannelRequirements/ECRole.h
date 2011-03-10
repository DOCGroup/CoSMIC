// -*- C++ -*-

//============================================================================
/**
 * @file    ECRole.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_EVENTCHANNELREQUIREMENTS_ECROLE_H_
#define _PICML_EVENTCHANNELREQUIREMENTS_ECROLE_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ECRole_Impl;
  typedef ECRole_Impl * ECRole_in;
  typedef ::GAME::Mga::Smart_Ptr <ECRole_Impl> ECRole;

  // Forward decl.
  class Visitor;

  class PICML_Export ECRole_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ECRole_Impl (void);

    /// Initializing constructor
    ECRole_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~ECRole_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ECRole _create (const ECRequirements_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of rolekind
    void rolekind (const std::string & val);

    /// Get the value of rolekind
    std::string rolekind (void) const;

    /// Set the value of ECFilterType
    void ECFilterType (const std::string & val);

    /// Get the value of ECFilterType
    std::string ECFilterType (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ECRequirements parent_ECRequirements (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
