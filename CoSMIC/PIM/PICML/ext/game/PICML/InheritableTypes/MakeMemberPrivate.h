// -*- C++ -*-

//============================================================================
/**
 * @file    MakeMemberPrivate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_MAKEMEMBERPRIVATE_H_
#define _PICML_INHERITABLETYPES_MAKEMEMBERPRIVATE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MakeMemberPrivate_Impl;
  typedef MakeMemberPrivate_Impl * MakeMemberPrivate_in;
  typedef ::GAME::Mga::Smart_Ptr <MakeMemberPrivate_Impl> MakeMemberPrivate;

  // Forward decl.
  class Visitor;

  class PICML_Export MakeMemberPrivate_Impl :
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
    MakeMemberPrivate_Impl (void);

    /// Initializing constructor
    MakeMemberPrivate_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~MakeMemberPrivate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static MakeMemberPrivate _create (const ObjectByValue_in parent);
    ///@}

    /// Get the src Member connection point.
    Member src_Member (void);

    /// Get the dst PrivateFlag connection point.
    PrivateFlag dst_PrivateFlag (void);

    /**
     * @name Parent Methods
     */
    ///@{
    ObjectByValue parent_ObjectByValue (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
