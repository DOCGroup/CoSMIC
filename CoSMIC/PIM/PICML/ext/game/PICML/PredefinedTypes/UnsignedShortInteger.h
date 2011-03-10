// -*- C++ -*-

//============================================================================
/**
 * @file    UnsignedShortInteger.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_UNSIGNEDSHORTINTEGER_H_
#define _PICML_PREDEFINEDTYPES_UNSIGNEDSHORTINTEGER_H_

#include "game/mga/Atom.h"
#include "PICML/PredefinedTypes/UnsignedIntegerType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class UnsignedShortInteger_Impl;
  typedef UnsignedShortInteger_Impl * UnsignedShortInteger_in;
  typedef ::GAME::Mga::Smart_Ptr <UnsignedShortInteger_Impl> UnsignedShortInteger;

  // Forward decl.
  class Visitor;

  class PICML_Export UnsignedShortInteger_Impl :
    public virtual UnsignedIntegerType_Impl,
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
    UnsignedShortInteger_Impl (void);

    /// Initializing constructor
    UnsignedShortInteger_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~UnsignedShortInteger_Impl (void);

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
