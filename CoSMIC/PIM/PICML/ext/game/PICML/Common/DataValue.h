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

#include "game/mga/Reference.h"
#include "PICML/Common/DataValueBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DataValue_Impl;
  typedef DataValue_Impl * DataValue_in;
  typedef ::GAME::Mga::Smart_Ptr <DataValue_Impl> DataValue;

  // Forward decl.
  class Visitor;

  class PICML_Export DataValue_Impl :
    public virtual DataValueBase_Impl,
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    DataValue_Impl (void);

    /// Initializing constructor
    DataValue_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~DataValue_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
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
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    SimpleType refers_to_SimpleType (void) const;
    ///@}
  };
}

#endif
