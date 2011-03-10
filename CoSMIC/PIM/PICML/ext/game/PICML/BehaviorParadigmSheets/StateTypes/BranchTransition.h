// -*- C++ -*-

//============================================================================
/**
 * @file    BranchTransition.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_BRANCHTRANSITION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_BRANCHTRANSITION_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BranchTransition_Impl;
  typedef BranchTransition_Impl * BranchTransition_in;
  typedef ::GAME::Mga::Smart_Ptr <BranchTransition_Impl> BranchTransition;

  // Forward decl.
  class Visitor;

  class PICML_Export BranchTransition_Impl :
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
    BranchTransition_Impl (void);

    /// Initializing constructor
    BranchTransition_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~BranchTransition_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src BranchState connection point.
    BranchState src_BranchState (void);

    /// Get the dst ActionBase connection point.
    ActionBase dst_ActionBase (void);

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Condition
    void Condition (const std::string & val);

    /// Get the value of Condition
    std::string Condition (void) const;
    ///@}

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
