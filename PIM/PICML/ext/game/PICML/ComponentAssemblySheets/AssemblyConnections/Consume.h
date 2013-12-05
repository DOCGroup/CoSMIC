// -*- C++ -*-

//============================================================================
/**
 * @file    Consume.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONSUME_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONSUME_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Consume_Impl;
  typedef Consume_Impl * Consume_in;
  typedef ::GAME::Mga::Smart_Ptr < Consume_Impl > Consume;

  // Forward decl.
  class Visitor;

  /**
   * @class Consume_Impl
   *
   * Implementation for the Consume model element.
   */
  class PICML_Export Consume_Impl :
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
    static Consume _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    Consume_Impl (void);

    // Initializing constructor.
    Consume_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~Consume_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    ConnectorInstance src_ConnectorInstance (void) const;
    ExtendPortEnd dst_ExtendPortEnd (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "Consume.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONSUME
