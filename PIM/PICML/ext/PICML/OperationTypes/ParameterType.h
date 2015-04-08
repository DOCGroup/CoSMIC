// -*- C++ -*-

//============================================================================
/**
 * @file    ParameterType.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_PARAMETERTYPE_H_
#define _PICML_OPERATIONTYPES_PARAMETERTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ParameterType_Impl;
  typedef ParameterType_Impl * ParameterType_in;
  typedef ::GAME::Mga::Smart_Ptr < ParameterType_Impl > ParameterType;

  /**
   * @class ParameterType_Impl
   *
   * Implementation for the ParameterType model element.
   */
  class PICML_Export ParameterType_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    ParameterType_Impl (void);

    // Initializing constructor.
    ParameterType_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ParameterType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    Operation parent_Operation (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool MemberType_is_nil (void) const;
    MemberType refers_to_MemberType (void) const;
    void refers_to_MemberType (MemberType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ParameterType.inl"
#endif

#endif  // !defined _PICML_OPERATIONTYPES_PARAMETERTYPE
