// -*- C++ -*-

//============================================================================
/**
 * @file    Member.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_MEMBER_H_
#define _PICML_NAMEDTYPES_MEMBER_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Member_Impl;
  typedef Member_Impl * Member_in;
  typedef ::GAME::Mga::Smart_Ptr <Member_Impl> Member;

  // Forward decl.
  class Visitor;

  class PICML_Export Member_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Member_Impl (void);

    /// Initializing constructor
    Member_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~Member_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Member _create (const Aggregate_in parent);
    static Member _create (const SwitchedAggregate_in parent);
    ///@}
    size_t in_LabelConnection_connections (std::vector <LabelConnection> & conns) const;
    size_t in_KeyMember_connections (std::vector <KeyMember> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    Aggregate parent_Aggregate (void) const;
    SwitchedAggregate parent_SwitchedAggregate (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    MemberType refers_to_MemberType (void) const;
    ///@}
  };
}

#endif
