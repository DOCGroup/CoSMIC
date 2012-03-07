// -*- C++ -*-

//============================================================================
/**
 * @file    SetException.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_SETEXCEPTION_H_
#define _PICML_INHERITABLETYPES_SETEXCEPTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SetException_Impl;
  typedef SetException_Impl * SetException_in;
  typedef ::GAME::Mga::Smart_Ptr < SetException_Impl > SetException;

  // Forward decl.
  class Visitor;

  /**
   * @class SetException_Impl
   *
   * Implementation for the SetException model element.
   */
  class PICML_Export SetException_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static SetException _create (const Attribute_in parent);
    ///@}

    // Default constructor.
    SetException_Impl (void);

    // Initializing constructor.
    SetException_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~SetException_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ExceptionType_is_nil (void) const;
    ExceptionType get_ExceptionType (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SetException.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_SETEXCEPTION
