// -*- C++ -*-

//============================================================================
/**
 * @file    ComplexType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_COMPLEXTYPE_H_
#define _PICML_COMMON_COMPLEXTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComplexType_Impl;
  typedef ComplexType_Impl * ComplexType_in;
  typedef ::GAME::Mga::Smart_Ptr < ComplexType_Impl > ComplexType;

  /**
   * @class ComplexType_Impl
   *
   * Implementation for the ComplexType model element.
   */
  class PICML_Export ComplexType_Impl :
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
    ComplexType_Impl (void);

    // Initializing constructor.
    ComplexType_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~ComplexType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComplexType.inl"
#endif

#endif  // !defined _PICML_COMMON_COMPLEXTYPE
