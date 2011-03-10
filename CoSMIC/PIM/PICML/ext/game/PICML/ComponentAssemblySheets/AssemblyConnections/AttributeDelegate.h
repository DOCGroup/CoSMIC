// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEDELEGATE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeDelegate_Impl;
  typedef AttributeDelegate_Impl * AttributeDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeDelegate_Impl> AttributeDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export AttributeDelegate_Impl :
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
    AttributeDelegate_Impl (void);

    /// Initializing constructor
    AttributeDelegate_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~AttributeDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src AttributeMapping connection point.
    AttributeMapping src_AttributeMapping (void);

    /// Get the dst AttributeInstance connection point.
    AttributeInstance dst_AttributeInstance (void);

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
