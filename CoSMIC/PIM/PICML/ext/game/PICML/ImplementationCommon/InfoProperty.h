// -*- C++ -*-

//============================================================================
/**
 * @file    InfoProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_INFOPROPERTY_H_
#define _PICML_IMPLEMENTATIONCOMMON_INFOPROPERTY_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InfoProperty_Impl;
  typedef InfoProperty_Impl * InfoProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <InfoProperty_Impl> InfoProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export InfoProperty_Impl :
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
    InfoProperty_Impl (void);

    /// Initializing constructor
    InfoProperty_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~InfoProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static InfoProperty _create (const ImplementationContainer_in parent);
    ///@}

    /// Get the src Implemenation connection point.
    Implemenation src_Implemenation (void);

    /// Get the dst Property connection point.
    Property dst_Property (void);

    /**
     * @name Parent Methods
     */
    ///@{
    ImplementationContainer parent_ImplementationContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
