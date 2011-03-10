// -*- C++ -*-

//============================================================================
/**
 * @file    EdgeProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_EDGEPROPERTY_H_
#define _PICML_PATHDIAGRAM_EDGEPROPERTY_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EdgeProperty_Impl;
  typedef EdgeProperty_Impl * EdgeProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <EdgeProperty_Impl> EdgeProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export EdgeProperty_Impl :
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
    EdgeProperty_Impl (void);

    /// Initializing constructor
    EdgeProperty_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~EdgeProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static EdgeProperty _create (const Path_in parent);
    ///@}

    /// Get the src Property connection point.
    Property src_Property (void);

    /// Get the dst Edge connection point.
    Edge dst_Edge (void);

    /**
     * @name Parent Methods
     */
    ///@{
    Path parent_Path (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
