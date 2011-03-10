// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeMapping.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPING_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPING_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeMapping_Impl;
  typedef AttributeMapping_Impl * AttributeMapping_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeMapping_Impl> AttributeMapping;

  // Forward decl.
  class Visitor;

  class PICML_Export AttributeMapping_Impl :
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
    AttributeMapping_Impl (void);

    /// Initializing constructor
    AttributeMapping_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~AttributeMapping_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_AttributeDelegate_connections (std::vector <AttributeDelegate> & conns) const;
    size_t in_AttributeMappingDelegate_connections (std::vector <AttributeMappingDelegate> & conns) const;
    size_t in_AttributeMappingValue_connections (std::vector <AttributeMappingValue> & conns) const;

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
