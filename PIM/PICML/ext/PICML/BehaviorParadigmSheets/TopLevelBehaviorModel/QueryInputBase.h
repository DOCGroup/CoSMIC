// -*- C++ -*-

//============================================================================
/**
 * @file    QueryInputBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_QUERYINPUTBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_QUERYINPUTBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class QueryInputBase_Impl;
  typedef QueryInputBase_Impl * QueryInputBase_in;
  typedef ::GAME::Mga::Smart_Ptr < QueryInputBase_Impl > QueryInputBase;

  /**
   * @class QueryInputBase_Impl
   *
   * Implementation for the QueryInputBase model element.
   */
  class PICML_Export QueryInputBase_Impl :
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
    QueryInputBase_Impl (void);

    // Initializing constructor.
    QueryInputBase_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~QueryInputBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src QueryInput connection.
    size_t src_of_QueryInput (std::vector <QueryInput> & items) const;
    GAME::Mga::Collection_T <QueryInput> src_of_QueryInput (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "QueryInputBase.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_QUERYINPUTBASE
