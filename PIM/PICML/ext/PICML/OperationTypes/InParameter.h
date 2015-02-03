// -*- C++ -*-

//============================================================================
/**
 * @file    InParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_INPARAMETER_H_
#define _PICML_OPERATIONTYPES_INPARAMETER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/OperationTypes/ParameterType.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InParameter_Impl;
  typedef InParameter_Impl * InParameter_in;
  typedef ::GAME::Mga::Smart_Ptr < InParameter_Impl > InParameter;

  // Forward decl.
  class Visitor;

  /**
   * @class InParameter_Impl
   *
   * Implementation for the InParameter model element.
   */
  class PICML_Export InParameter_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual ParameterType_Impl
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
    static InParameter _create (const OperationBase_in parent);
    static InParameter _create (const Operation_in parent);
    ///@}

    // Default constructor.
    InParameter_Impl (void);

    // Initializing constructor.
    InParameter_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~InParameter_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    OperationBase parent_OperationBase (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "InParameter.inl"
#endif

#endif  // !defined _PICML_OPERATIONTYPES_INPARAMETER
