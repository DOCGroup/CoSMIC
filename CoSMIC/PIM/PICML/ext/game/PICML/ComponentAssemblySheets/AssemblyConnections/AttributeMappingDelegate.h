// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeMappingDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPINGDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPINGDELEGATE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeMappingDelegate_Impl;
  typedef AttributeMappingDelegate_Impl * AttributeMappingDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeMappingDelegate_Impl> AttributeMappingDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export AttributeMappingDelegate_Impl :
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
    AttributeMappingDelegate_Impl (void);

    /// Initializing constructor
    AttributeMappingDelegate_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~AttributeMappingDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src AttributeMapping connection point.
    AttributeMapping src_AttributeMapping (void);

    /// Get the dst AttributeMapping connection point.
    AttributeMapping dst_AttributeMapping (void);

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
