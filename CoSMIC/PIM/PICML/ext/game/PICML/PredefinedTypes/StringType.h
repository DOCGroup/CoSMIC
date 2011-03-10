// -*- C++ -*-

//============================================================================
/**
 * @file    StringType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_STRINGTYPE_H_
#define _PICML_PREDEFINEDTYPES_STRINGTYPE_H_

#include "game/mga/Atom.h"
#include "PICML/PredefinedTypes/PredefinedType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class StringType_Impl;
  typedef StringType_Impl * StringType_in;
  typedef ::GAME::Mga::Smart_Ptr <StringType_Impl> StringType;

  class PICML_Export StringType_Impl :
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
    StringType_Impl (void);

    /// Initializing constructor
    StringType_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~StringType_Impl (void) = 0;

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
