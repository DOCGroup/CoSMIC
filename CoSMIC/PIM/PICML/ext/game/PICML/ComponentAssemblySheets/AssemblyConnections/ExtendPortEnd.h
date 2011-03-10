// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendPortEnd.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDPORTEND_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EXTENDPORTEND_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendPortEnd_Impl;
  typedef ExtendPortEnd_Impl * ExtendPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendPortEnd_Impl> ExtendPortEnd;

  class PICML_Export ExtendPortEnd_Impl :
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
    ExtendPortEnd_Impl (void);

    /// Initializing constructor
    ExtendPortEnd_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~ExtendPortEnd_Impl (void) = 0;
    size_t in_Publish_connections (std::vector <Publish> & conns) const;
    size_t in_Consume_connections (std::vector <Consume> & conns) const;

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
