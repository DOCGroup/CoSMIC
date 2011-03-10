// -*- C++ -*-

//============================================================================
/**
 * @file    Aggregate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_AGGREGATE_H_
#define _PICML_NAMEDTYPES_AGGREGATE_H_

#include "game/mga/Model.h"
#include "PICML/NamedTypes/NoInheritable.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Aggregate_Impl;
  typedef Aggregate_Impl * Aggregate_in;
  typedef ::GAME::Mga::Smart_Ptr <Aggregate_Impl> Aggregate;

  // Forward decl.
  class Visitor;

  class PICML_Export Aggregate_Impl :
    public virtual NoInheritable_Impl,
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Aggregate_Impl (void);

    /// Initializing constructor
    Aggregate_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Aggregate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_KeyMembers (std::vector <KeyMember> & items) const;
    size_t get_Members (std::vector <Member> & items) const;

    Key get_Key (void) const;
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
