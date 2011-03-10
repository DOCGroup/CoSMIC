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

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class QueryInputBase_Impl;
  typedef QueryInputBase_Impl * QueryInputBase_in;
  typedef ::GAME::Mga::Smart_Ptr <QueryInputBase_Impl> QueryInputBase;

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

    /// Default constructor
    QueryInputBase_Impl (void);

    /// Initializing constructor
    QueryInputBase_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~QueryInputBase_Impl (void) = 0;
    size_t in_QueryInput_connections (std::vector <QueryInput> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
