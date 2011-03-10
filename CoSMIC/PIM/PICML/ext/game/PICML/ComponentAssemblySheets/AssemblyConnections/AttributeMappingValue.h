// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeMappingValue.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPINGVALUE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPINGVALUE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeMappingValue_Impl;
  typedef AttributeMappingValue_Impl * AttributeMappingValue_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeMappingValue_Impl> AttributeMappingValue;

  // Forward decl.
  class Visitor;

  class PICML_Export AttributeMappingValue_Impl :
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
    AttributeMappingValue_Impl (void);

    /// Initializing constructor
    AttributeMappingValue_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~AttributeMappingValue_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src AttributeMapping connection point.
    AttributeMapping src_AttributeMapping (void);

    /// Get the dst Property connection point.
    Property dst_Property (void);

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
