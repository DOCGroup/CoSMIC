// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorInherits.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINTERFACE_CONNECTORINHERITS_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINTERFACE_CONNECTORINHERITS_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorInherits_Impl;
  typedef ConnectorInherits_Impl * ConnectorInherits_in;
  typedef ::GAME::Mga::Smart_Ptr <ConnectorInherits_Impl> ConnectorInherits;

  // Forward decl.
  class Visitor;

  class PICML_Export ConnectorInherits_Impl :
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
    ConnectorInherits_Impl (void);

    /// Initializing constructor
    ConnectorInherits_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ConnectorInherits_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ConnectorInherits _create (const ConnectorObject_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorObject parent_ConnectorObject (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ConnectorObject refers_to_ConnectorObject (void) const;
    ///@}
  };
}

#endif
