// -*- C++ -*-

//============================================================================
/**
 * @file    MultiInput.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIINPUT_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIINPUT_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MultiInput_Impl;
  typedef MultiInput_Impl * MultiInput_in;
  typedef ::GAME::Mga::Smart_Ptr <MultiInput_Impl> MultiInput;

  // Forward decl.
  class Visitor;

  class PICML_Export MultiInput_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    MultiInput_Impl (void);

    /// Initializing constructor
    MultiInput_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~MultiInput_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static MultiInput _create (const TopLevelBehavior_in parent);
    ///@}

    /// Get the src MultiInputBase connection point.
    MultiInputBase src_MultiInputBase (void);

    /// Get the dst MultiInputAction connection point.
    MultiInputAction dst_MultiInputAction (void);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelBehavior parent_TopLevelBehavior (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
