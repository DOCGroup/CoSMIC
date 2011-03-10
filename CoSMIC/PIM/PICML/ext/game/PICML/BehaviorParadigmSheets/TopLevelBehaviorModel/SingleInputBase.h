// -*- C++ -*-

//============================================================================
/**
 * @file    SingleInputBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_SINGLEINPUTBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_SINGLEINPUTBASE_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SingleInputBase_Impl;
  typedef SingleInputBase_Impl * SingleInputBase_in;
  typedef ::GAME::Mga::Smart_Ptr <SingleInputBase_Impl> SingleInputBase;

  class PICML_Export SingleInputBase_Impl :
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
    SingleInputBase_Impl (void);

    /// Initializing constructor
    SingleInputBase_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~SingleInputBase_Impl (void) = 0;
    size_t in_Input_connections (std::vector <Input> & conns) const;

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
