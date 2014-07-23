// -*- C++ -*-

//============================================================================
/**
 * @file    DataValueBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_DATAVALUEBASE_H_
#define _PICML_COMMON_DATAVALUEBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DataValueBase_Impl;
  typedef DataValueBase_Impl * DataValueBase_in;
  typedef ::GAME::Mga::Smart_Ptr < DataValueBase_Impl > DataValueBase;

  /**
   * @class DataValueBase_Impl
   *
   * Implementation for the DataValueBase model element.
   */
  class PICML_Export DataValueBase_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    DataValueBase_Impl (void);

    // Initializing constructor.
    DataValueBase_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~DataValueBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    DataValueContainer parent_DataValueContainer (void);
    ComplexProperty parent_ComplexProperty (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DataValueBase.inl"
#endif

#endif  // !defined _PICML_COMMON_DATAVALUEBASE
