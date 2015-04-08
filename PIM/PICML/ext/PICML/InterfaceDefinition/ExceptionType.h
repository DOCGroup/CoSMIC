// -*- C++ -*-

//============================================================================
/**
 * @file    ExceptionType.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_EXCEPTIONTYPE_H_
#define _PICML_INTERFACEDEFINITION_EXCEPTIONTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExceptionType_Impl;
  typedef ExceptionType_Impl * ExceptionType_in;
  typedef ::GAME::Mga::Smart_Ptr < ExceptionType_Impl > ExceptionType;

  /**
   * @class ExceptionType_Impl
   *
   * Implementation for the ExceptionType model element.
   */
  class PICML_Export ExceptionType_Impl :
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
    ExceptionType_Impl (void);

    // Initializing constructor.
    ExceptionType_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~ExceptionType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ExceptionType.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_EXCEPTIONTYPE
