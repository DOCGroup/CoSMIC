// -*- C++ -*-

//============================================================================
/**
 * @file    ExternalResources.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_EXTERNALRESOURCES_H_
#define _PICML_COMPONENTBUILD_EXTERNALRESOURCES_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExternalResources_Impl;
  typedef ExternalResources_Impl * ExternalResources_in;
  typedef ::GAME::Mga::Smart_Ptr <ExternalResources_Impl> ExternalResources;

  // Forward decl.
  class Visitor;

  class PICML_Export ExternalResources_Impl :
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
    ExternalResources_Impl (void);

    /// Initializing constructor
    ExternalResources_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ExternalResources_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ExternalResources _create (const Project_in parent);
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
