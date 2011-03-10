// -*- C++ -*-

//============================================================================
/**
 * @file    PathProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_PATHPROPERTY_H_
#define _PICML_PATHDIAGRAM_PATHPROPERTY_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PathProperty_Impl;
  typedef PathProperty_Impl * PathProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <PathProperty_Impl> PathProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export PathProperty_Impl :
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
    PathProperty_Impl (void);

    /// Initializing constructor
    PathProperty_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~PathProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PathProperty _create (const Paths_in parent);
    ///@}

    /// Get the src Path connection point.
    Path src_Path (void);

    /// Get the dst Property connection point.
    Property dst_Property (void);

    /**
     * @name Parent Methods
     */
    ///@{
    Paths parent_Paths (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
