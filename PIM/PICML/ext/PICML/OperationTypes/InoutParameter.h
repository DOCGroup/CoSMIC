// -*- C++ -*-

//============================================================================
/**
 * @file    InoutParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_INOUTPARAMETER_H_
#define _PICML_OPERATIONTYPES_INOUTPARAMETER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/OperationTypes/ParameterType.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InoutParameter_Impl;
  typedef InoutParameter_Impl * InoutParameter_in;
  typedef ::GAME::Mga::Smart_Ptr < InoutParameter_Impl > InoutParameter;

  // Forward decl.
  class Visitor;

  /**
   * @class InoutParameter_Impl
   *
   * Implementation for the InoutParameter model element.
   */
  class PICML_Export InoutParameter_Impl :
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
    static InoutParameter _create (const TwowayOperation_in parent);
    static InoutParameter _create (const Operation_in parent);
    ///@}

    // Default constructor.
    InoutParameter_Impl (void);

    // Initializing constructor.
    InoutParameter_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~InoutParameter_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TwowayOperation parent_TwowayOperation (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "InoutParameter.inl"
#endif

#endif  // !defined _PICML_OPERATIONTYPES_INOUTPARAMETER
