// -*- C++ -*-

//============================================================================
/**
 * @file    CriticalPath.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_CRITICALPATH_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_CRITICALPATH_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CriticalPath_Impl;
  typedef CriticalPath_Impl * CriticalPath_in;
  typedef ::GAME::Mga::Smart_Ptr <CriticalPath_Impl> CriticalPath;

  // Forward decl.
  class Visitor;

  class PICML_Export CriticalPath_Impl :
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
    CriticalPath_Impl (void);

    /// Initializing constructor
    CriticalPath_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~CriticalPath_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static CriticalPath _create (const ComponentImplementationContainer_in parent);
    ///@}

    /// Get the src ComponentAssembly connection point.
    ComponentAssembly src_ComponentAssembly (void);

    /// Get the dst PathReference connection point.
    PathReference dst_PathReference (void);

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
