// -*- C++ -*-

//============================================================================
/**
 * @file    MemberType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_MEMBERTYPE_H_
#define _PICML_NAMEDTYPES_MEMBERTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InterfaceDefinition/TemplateParameterValueType.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MemberType_Impl;
  typedef MemberType_Impl * MemberType_in;
  typedef ::GAME::Mga::Smart_Ptr < MemberType_Impl > MemberType;

  /**
   * @class MemberType_Impl
   *
   * Implementation for the MemberType model element.
   */
  class PICML_Export MemberType_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual TemplateParameterValueType_Impl
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
    MemberType_Impl (void);

    // Initializing constructor.
    MemberType_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~MemberType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "MemberType.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_MEMBERTYPE
