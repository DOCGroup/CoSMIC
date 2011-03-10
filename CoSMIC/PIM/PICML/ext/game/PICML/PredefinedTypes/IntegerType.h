// -*- C++ -*-

//============================================================================
/**
 * @file    IntegerType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_INTEGERTYPE_H_
#define _PICML_PREDEFINEDTYPES_INTEGERTYPE_H_

#include "game/mga/Atom.h"
#include "PICML/PredefinedTypes/PredefinedType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class IntegerType_Impl;
  typedef IntegerType_Impl * IntegerType_in;
  typedef ::GAME::Mga::Smart_Ptr <IntegerType_Impl> IntegerType;

  class PICML_Export IntegerType_Impl :
    public virtual PredefinedType_Impl,
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
    IntegerType_Impl (void);

    /// Initializing constructor
    IntegerType_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~IntegerType_Impl (void) = 0;

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
