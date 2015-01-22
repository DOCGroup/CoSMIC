// -*- C++ -*-

//============================================================================
/**
 * @file    DataValue.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_DATAVALUE_H_
#define _PICML_COMMON_DATAVALUE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/Common/DataValueBase.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DataValue_Impl;
  typedef DataValue_Impl * DataValue_in;
  typedef ::GAME::Mga::Smart_Ptr < DataValue_Impl > DataValue;

  // Forward decl.
  class Visitor;

  /**
   * @class DataValue_Impl
   *
   * Implementation for the DataValue model element.
   */
  class PICML_Export DataValue_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual DataValueBase_Impl
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
    static DataValue _create (const ComplexProperty_in parent);
    static DataValue _create (const DataValueContainer_in parent);
    ///@}

    // Default constructor.
    DataValue_Impl (void);

    // Initializing constructor.
    DataValue_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~DataValue_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Value
    void Value (const std::string & val);

    /// Get the value of Value
    std::string Value (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool SimpleType_is_nil (void) const;
    SimpleType refers_to_SimpleType (void) const;
    void refers_to_SimpleType (SimpleType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DataValue.inl"
#endif

#endif  // !defined _PICML_COMMON_DATAVALUE
