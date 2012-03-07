// -*- C++ -*-

//============================================================================
/**
 * @file    ExtResourceConn.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_EXTRESOURCECONN_H_
#define _PICML_COMPONENTBUILD_EXTRESOURCECONN_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtResourceConn_Impl;
  typedef ExtResourceConn_Impl * ExtResourceConn_in;
  typedef ::GAME::Mga::Smart_Ptr < ExtResourceConn_Impl > ExtResourceConn;

  // Forward decl.
  class Visitor;

  /**
   * @class ExtResourceConn_Impl
   *
   * Implementation for the ExtResourceConn model element.
   */
  class PICML_Export ExtResourceConn_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ExtResourceConn _create (const Project_in parent);
    ///@}

    // Default constructor.
    ExtResourceConn_Impl (void);

    // Initializing constructor.
    ExtResourceConn_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ExtResourceConn_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
    ComponentLib src_ComponentLib (void) const;
    ExternalResources dst_ExternalResources (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ExtResourceConn.inl"
#endif

#endif  // !defined _PICML_COMPONENTBUILD_EXTRESOURCECONN
