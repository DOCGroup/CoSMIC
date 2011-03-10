// -*- C++ -*-

//============================================================================
/**
 * @file    SwitchedAggregate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_SWITCHEDAGGREGATE_H_
#define _PICML_NAMEDTYPES_SWITCHEDAGGREGATE_H_

#include "game/mga/Model.h"
#include "PICML/NamedTypes/NoInheritable.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SwitchedAggregate_Impl;
  typedef SwitchedAggregate_Impl * SwitchedAggregate_in;
  typedef ::GAME::Mga::Smart_Ptr <SwitchedAggregate_Impl> SwitchedAggregate;

  // Forward decl.
  class Visitor;

  class PICML_Export SwitchedAggregate_Impl :
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
    SwitchedAggregate_Impl (void);

    /// Initializing constructor
    SwitchedAggregate_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~SwitchedAggregate_Impl (void);

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
    size_t get_Members (std::vector <Member> & items) const;
    size_t get_Labels (std::vector <Label> & items) const;

    Discriminator get_Discriminator (void) const;
    size_t get_LabelConnections (std::vector <LabelConnection> & items) const;
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
