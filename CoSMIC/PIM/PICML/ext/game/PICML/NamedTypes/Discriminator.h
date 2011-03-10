// -*- C++ -*-

//============================================================================
/**
 * @file    Discriminator.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_DISCRIMINATOR_H_
#define _PICML_NAMEDTYPES_DISCRIMINATOR_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Discriminator_Impl;
  typedef Discriminator_Impl * Discriminator_in;
  typedef ::GAME::Mga::Smart_Ptr <Discriminator_Impl> Discriminator;

  // Forward decl.
  class Visitor;

  class PICML_Export Discriminator_Impl :
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
    Discriminator_Impl (void);

    /// Initializing constructor
    Discriminator_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~Discriminator_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Discriminator _create (const SwitchedAggregate_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    SwitchedAggregate parent_SwitchedAggregate (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
