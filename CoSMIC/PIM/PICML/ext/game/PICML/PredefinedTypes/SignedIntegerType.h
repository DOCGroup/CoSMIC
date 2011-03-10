// -*- C++ -*-

//============================================================================
/**
 * @file    SignedIntegerType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_SIGNEDINTEGERTYPE_H_
#define _PICML_PREDEFINEDTYPES_SIGNEDINTEGERTYPE_H_

#include "game/mga/Atom.h"
#include "PICML/PredefinedTypes/IntegerType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SignedIntegerType_Impl;
  typedef SignedIntegerType_Impl * SignedIntegerType_in;
  typedef ::GAME::Mga::Smart_Ptr <SignedIntegerType_Impl> SignedIntegerType;

  class PICML_Export SignedIntegerType_Impl :
    public virtual IntegerType_Impl,
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
    SignedIntegerType_Impl (void);

    /// Initializing constructor
    SignedIntegerType_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~SignedIntegerType_Impl (void) = 0;

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
