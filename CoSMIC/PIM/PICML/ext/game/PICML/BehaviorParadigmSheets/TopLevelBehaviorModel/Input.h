// -*- C++ -*-

//============================================================================
/**
 * @file    Input.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_INPUT_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_INPUT_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Input_Impl;
  typedef Input_Impl * Input_in;
  typedef ::GAME::Mga::Smart_Ptr <Input_Impl> Input;

  // Forward decl.
  class Visitor;

  class PICML_Export Input_Impl :
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
    Input_Impl (void);

    /// Initializing constructor
    Input_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~Input_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Input _create (const TopLevelBehavior_in parent);
    ///@}

    /// Get the src SingleInputBase connection point.
    SingleInputBase src_SingleInputBase (void);

    /// Get the dst InputAction connection point.
    InputAction dst_InputAction (void);

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
