// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentLib.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_COMPONENTLIB_H_
#define _PICML_COMPONENTBUILD_COMPONENTLIB_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentLib_Impl;
  typedef ComponentLib_Impl * ComponentLib_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentLib_Impl> ComponentLib;

  class PICML_Export ComponentLib_Impl :
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
    ComponentLib_Impl (void);

    /// Initializing constructor
    ComponentLib_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~ComponentLib_Impl (void) = 0;

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of ORBServices
    void ORBServices (const std::string & val);

    /// Get the value of ORBServices
    std::string ORBServices (void) const;

    /// Set the value of sharedname
    void sharedname (const std::string & val);

    /// Get the value of sharedname
    std::string sharedname (void) const;

    /// Set the value of libraryexport
    void libraryexport (const std::string & val);

    /// Get the value of libraryexport
    std::string libraryexport (void) const;
    ///@}
    size_t in_ExtResourceConn_connections (std::vector <ExtResourceConn> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    Project parent_Project (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
