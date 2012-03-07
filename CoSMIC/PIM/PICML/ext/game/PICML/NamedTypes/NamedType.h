// -*- C++ -*-

//============================================================================
/**
 * @file    NamedType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_NAMEDTYPE_H_
#define _PICML_NAMEDTYPES_NAMEDTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class NamedType_Impl;
  typedef NamedType_Impl * NamedType_in;
  typedef ::GAME::Mga::Smart_Ptr < NamedType_Impl > NamedType;

  /**
   * @class NamedType_Impl
   *
   * Implementation for the NamedType model element.
   */
  class PICML_Export NamedType_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    NamedType_Impl (void);

    // Initializing constructor.
    NamedType_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~NamedType_Impl (void) = 0;
  };
}

#if defined (__GAME_INLINE__)
#include "NamedType.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_NAMEDTYPE
