// -*- C++ -*-

//============================================================================
/**
 * @file    MultiOutputBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIOUTPUTBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIOUTPUTBASE_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MultiOutputBase_Impl;
  typedef MultiOutputBase_Impl * MultiOutputBase_in;
  typedef ::GAME::Mga::Smart_Ptr <MultiOutputBase_Impl> MultiOutputBase;

  class PICML_Export MultiOutputBase_Impl :
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
    MultiOutputBase_Impl (void);

    /// Initializing constructor
    MultiOutputBase_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~MultiOutputBase_Impl (void) = 0;

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
