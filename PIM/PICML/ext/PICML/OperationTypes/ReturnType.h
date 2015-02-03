// -*- C++ -*-

//============================================================================
/**
 * @file    ReturnType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_RETURNTYPE_H_
#define _PICML_OPERATIONTYPES_RETURNTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ReturnType_Impl;
  typedef ReturnType_Impl * ReturnType_in;
  typedef ::GAME::Mga::Smart_Ptr < ReturnType_Impl > ReturnType;

  // Forward decl.
  class Visitor;

  /**
   * @class ReturnType_Impl
   *
   * Implementation for the ReturnType model element.
   */
  class PICML_Export ReturnType_Impl :
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

    /**
     * @name Factory Methods
     */
    ///@{
    static ReturnType _create (const TwowayOperation_in parent);
    static ReturnType _create (const Operation_in parent);
    ///@}

    // Default constructor.
    ReturnType_Impl (void);

    // Initializing constructor.
    ReturnType_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ReturnType_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TwowayOperation parent_TwowayOperation (void);
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
#include "ReturnType.inl"
#endif

#endif  // !defined _PICML_OPERATIONTYPES_RETURNTYPE
