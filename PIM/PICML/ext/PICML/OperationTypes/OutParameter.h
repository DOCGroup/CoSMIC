// -*- C++ -*-

//============================================================================
/**
 * @file    OutParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_OUTPARAMETER_H_
#define _PICML_OPERATIONTYPES_OUTPARAMETER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/OperationTypes/ParameterType.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OutParameter_Impl;
  typedef OutParameter_Impl * OutParameter_in;
  typedef ::GAME::Mga::Smart_Ptr < OutParameter_Impl > OutParameter;

  // Forward decl.
  class Visitor;

  /**
   * @class OutParameter_Impl
   *
   * Implementation for the OutParameter model element.
   */
  class PICML_Export OutParameter_Impl :
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
    static OutParameter _create (const TwowayOperation_in parent);
    static OutParameter _create (const Operation_in parent);
    ///@}

    // Default constructor.
    OutParameter_Impl (void);

    // Initializing constructor.
    OutParameter_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~OutParameter_Impl (void);

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
#include "OutParameter.inl"
#endif

#endif  // !defined _PICML_OPERATIONTYPES_OUTPARAMETER
