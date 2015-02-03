// -*- C++ -*-

//============================================================================
/**
 * @file    DataType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_DATATYPE_H_
#define _PICML_COMMON_DATATYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DataType_Impl;
  typedef DataType_Impl * DataType_in;
  typedef ::GAME::Mga::Smart_Ptr < DataType_Impl > DataType;

  // Forward decl.
  class Visitor;

  /**
   * @class DataType_Impl
   *
   * Implementation for the DataType model element.
   */
  class PICML_Export DataType_Impl :
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
    static DataType _create (const ComponentPropertyDescription_in parent);
    static DataType _create (const SatisfierProperty_in parent);
    ///@}

    // Default constructor.
    DataType_Impl (void);

    // Initializing constructor.
    DataType_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~DataType_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentPropertyDescription parent_ComponentPropertyDescription (void);
    SatisfierProperty parent_SatisfierProperty (void);
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
#include "DataType.inl"
#endif

#endif  // !defined _PICML_COMMON_DATATYPE
