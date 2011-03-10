// -*- C++ -*-

//============================================================================
/**
 * @file    SendsTo.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_SENDSTO_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_SENDSTO_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SendsTo_Impl;
  typedef SendsTo_Impl * SendsTo_in;
  typedef ::GAME::Mga::Smart_Ptr <SendsTo_Impl> SendsTo;

  // Forward decl.
  class Visitor;

  class PICML_Export SendsTo_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    SendsTo_Impl (void);

    /// Initializing constructor
    SendsTo_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~SendsTo_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src OutEventPortEnd connection point.
    OutEventPortEnd src_OutEventPortEnd (void);

    /// Get the dst InEventPortEnd connection point.
    InEventPortEnd dst_InEventPortEnd (void);

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
