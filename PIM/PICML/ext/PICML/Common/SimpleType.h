// -*- C++ -*-

//============================================================================
/**
 * @file    SimpleType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_SIMPLETYPE_H_
#define _PICML_COMMON_SIMPLETYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SimpleType_Impl;
  typedef SimpleType_Impl * SimpleType_in;
  typedef ::GAME::Mga::Smart_Ptr < SimpleType_Impl > SimpleType;

  /**
   * @class SimpleType_Impl
   *
   * Implementation for the SimpleType model element.
   */
  class PICML_Export SimpleType_Impl :
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
    SimpleType_Impl (void);

    // Initializing constructor.
    SimpleType_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~SimpleType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SimpleType.inl"
#endif

#endif  // !defined _PICML_COMMON_SIMPLETYPE
