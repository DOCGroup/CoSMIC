// -*- C++ -*-

//============================================================================
/**
 * @file    SingleOutputBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_SINGLEOUTPUTBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_SINGLEOUTPUTBASE_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SingleOutputBase_Impl;
  typedef SingleOutputBase_Impl * SingleOutputBase_in;
  typedef ::GAME::Mga::Smart_Ptr <SingleOutputBase_Impl> SingleOutputBase;

  class PICML_Export SingleOutputBase_Impl :
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
    SingleOutputBase_Impl (void);

    /// Initializing constructor
    SingleOutputBase_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~SingleOutputBase_Impl (void) = 0;

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
