// -*- C++ -*-

//============================================================================
/**
 * @file    AssemblyConfigPropertyEnd.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ASSEMBLYCONFIGPROPERTYEND_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ASSEMBLYCONFIGPROPERTYEND_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AssemblyConfigPropertyEnd_Impl;
  typedef AssemblyConfigPropertyEnd_Impl * AssemblyConfigPropertyEnd_in;
  typedef ::GAME::Mga::Smart_Ptr <AssemblyConfigPropertyEnd_Impl> AssemblyConfigPropertyEnd;

  class PICML_Export AssemblyConfigPropertyEnd_Impl :
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
    AssemblyConfigPropertyEnd_Impl (void);

    /// Initializing constructor
    AssemblyConfigPropertyEnd_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~AssemblyConfigPropertyEnd_Impl (void) = 0;
    size_t in_AssemblyselectRequirement_connections (std::vector <AssemblyselectRequirement> & conns) const;
    size_t in_AssemblyConfigProperty_connections (std::vector <AssemblyConfigProperty> & conns) const;

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
