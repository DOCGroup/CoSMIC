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

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DataType_Impl;
  typedef DataType_Impl * DataType_in;
  typedef ::GAME::Mga::Smart_Ptr <DataType_Impl> DataType;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    DataType_Impl (void);

    /// Initializing constructor
    DataType_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~DataType_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static DataType _create (const SatisfierProperty_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    SatisfierProperty parent_SatisfierProperty (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
