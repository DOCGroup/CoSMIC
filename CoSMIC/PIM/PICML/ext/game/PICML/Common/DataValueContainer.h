// -*- C++ -*-

//============================================================================
/**
 * @file    DataValueContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_DATAVALUECONTAINER_H_
#define _PICML_COMMON_DATAVALUECONTAINER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/Common/DataValueBase.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DataValueContainer_Impl;
  typedef DataValueContainer_Impl * DataValueContainer_in;
  typedef ::GAME::Mga::Smart_Ptr < DataValueContainer_Impl > DataValueContainer;

  // Forward decl.
  class Visitor;

  /**
   * @class DataValueContainer_Impl
   *
   * Implementation for the DataValueContainer model element.
   */
  class PICML_Export DataValueContainer_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual DataValueBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static DataValueContainer _create (const ComplexProperty_in parent);
    static DataValueContainer _create (const DataValueContainer_in parent);
    ///@}

    // Default constructor.
    DataValueContainer_Impl (void);

    // Initializing constructor.
    DataValueContainer_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~DataValueContainer_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ComplexTypeReference (void) const;
    ComplexTypeReference get_ComplexTypeReference (void) const;
    size_t get_DataValueContainers (std::vector <DataValueContainer> & items) const;
    ::GAME::Mga::Iterator <DataValueContainer> get_DataValueContainers (void) const;

    size_t get_DataValues (std::vector <DataValue> & items) const;
    ::GAME::Mga::Iterator <DataValue> get_DataValues (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DataValueContainer.inl"
#endif

#endif  // !defined _PICML_COMMON_DATAVALUECONTAINER
