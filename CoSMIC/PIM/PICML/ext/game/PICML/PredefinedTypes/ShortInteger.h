// -*- C++ -*-

//============================================================================
/**
 * @file    ShortInteger.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_SHORTINTEGER_H_
#define _PICML_PREDEFINEDTYPES_SHORTINTEGER_H_

#include "game/mga/Atom.h"
#include "PICML/PredefinedTypes/SignedIntegerType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ShortInteger_Impl;
  typedef ShortInteger_Impl * ShortInteger_in;
  typedef ::GAME::Mga::Smart_Ptr <ShortInteger_Impl> ShortInteger;

  // Forward decl.
  class Visitor;

  class PICML_Export ShortInteger_Impl :
    public virtual SignedIntegerType_Impl,
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
    ShortInteger_Impl (void);

    /// Initializing constructor
    ShortInteger_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~ShortInteger_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
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
