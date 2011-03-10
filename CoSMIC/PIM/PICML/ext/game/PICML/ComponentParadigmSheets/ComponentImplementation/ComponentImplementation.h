// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentImplementation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATION_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATION_H_

#include "game/mga/FCO.h"
#include "PICML/ImplementationCommon/Implemenation.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentImplementation_Impl;
  typedef ComponentImplementation_Impl * ComponentImplementation_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentImplementation_Impl> ComponentImplementation;

  class PICML_Export ComponentImplementation_Impl :
    public virtual Implemenation_Impl,
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
    ComponentImplementation_Impl (void);

    /// Initializing constructor
    ComponentImplementation_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~ComponentImplementation_Impl (void) = 0;
    size_t in_ImplementationDependsOn_connections (std::vector <ImplementationDependsOn> & conns) const;
    size_t in_Implements_connections (std::vector <Implements> & conns) const;
    size_t in_ImplementationCapability_connections (std::vector <ImplementationCapability> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentImplementationContainer parent_ComponentImplementationContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
