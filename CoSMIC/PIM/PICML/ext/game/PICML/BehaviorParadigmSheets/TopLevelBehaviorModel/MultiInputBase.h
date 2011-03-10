// -*- C++ -*-

//============================================================================
/**
 * @file    MultiInputBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIINPUTBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIINPUTBASE_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MultiInputBase_Impl;
  typedef MultiInputBase_Impl * MultiInputBase_in;
  typedef ::GAME::Mga::Smart_Ptr <MultiInputBase_Impl> MultiInputBase;

  class PICML_Export MultiInputBase_Impl :
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
    MultiInputBase_Impl (void);

    /// Initializing constructor
    MultiInputBase_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~MultiInputBase_Impl (void) = 0;
    size_t in_MultiInput_connections (std::vector <MultiInput> & conns) const;

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
