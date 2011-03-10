// -*- C++ -*-

//============================================================================
/**
 * @file    KeyMember.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_KEYMEMBER_H_
#define _PICML_NAMEDTYPES_KEYMEMBER_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class KeyMember_Impl;
  typedef KeyMember_Impl * KeyMember_in;
  typedef ::GAME::Mga::Smart_Ptr <KeyMember_Impl> KeyMember;

  // Forward decl.
  class Visitor;

  class PICML_Export KeyMember_Impl :
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
    KeyMember_Impl (void);

    /// Initializing constructor
    KeyMember_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~KeyMember_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static KeyMember _create (const Aggregate_in parent);
    ///@}

    /// Get the src Key connection point.
    Key src_Key (void);

    /// Get the dst Member connection point.
    Member dst_Member (void);

    /**
     * @name Parent Methods
     */
    ///@{
    Aggregate parent_Aggregate (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
