// -*- C++ -*-

//============================================================================
/**
 * @file    StateBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_STATEBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_STATEBASE_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class StateBase_Impl;
  typedef StateBase_Impl * StateBase_in;
  typedef ::GAME::Mga::Smart_Ptr <StateBase_Impl> StateBase;

  class PICML_Export StateBase_Impl :
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
    StateBase_Impl (void);

    /// Initializing constructor
    StateBase_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~StateBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
