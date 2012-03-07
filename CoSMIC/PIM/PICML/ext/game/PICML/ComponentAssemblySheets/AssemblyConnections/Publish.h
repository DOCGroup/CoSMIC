// -*- C++ -*-

//============================================================================
/**
 * @file    Publish.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PUBLISH_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PUBLISH_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Publish_Impl;
  typedef Publish_Impl * Publish_in;
  typedef ::GAME::Mga::Smart_Ptr < Publish_Impl > Publish;

  // Forward decl.
  class Visitor;

  /**
   * @class Publish_Impl
   *
   * Implementation for the Publish model element.
   */
  class PICML_Export Publish_Impl :
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
    static Publish _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    Publish_Impl (void);

    // Initializing constructor.
    Publish_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~Publish_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
    ExtendPortEnd src_ExtendPortEnd (void) const;
    ConnectorInstance dst_ConnectorInstance (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "Publish.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PUBLISH
