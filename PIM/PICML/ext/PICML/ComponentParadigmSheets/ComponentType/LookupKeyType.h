// -*- C++ -*-

//============================================================================
/**
 * @file    LookupKeyType.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_LOOKUPKEYTYPE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_LOOKUPKEYTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LookupKeyType_Impl;
  typedef LookupKeyType_Impl * LookupKeyType_in;
  typedef ::GAME::Mga::Smart_Ptr < LookupKeyType_Impl > LookupKeyType;

  /**
   * @class LookupKeyType_Impl
   *
   * Implementation for the LookupKeyType model element.
   */
  class PICML_Export LookupKeyType_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    LookupKeyType_Impl (void);

    // Initializing constructor.
    LookupKeyType_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~LookupKeyType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "LookupKeyType.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_LOOKUPKEYTYPE
