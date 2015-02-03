// -*- C++ -*-

//============================================================================
/**
 * @file    SendsTo.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_SENDSTO_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_SENDSTO_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SendsTo_Impl;
  typedef SendsTo_Impl * SendsTo_in;
  typedef ::GAME::Mga::Smart_Ptr < SendsTo_Impl > SendsTo;

  // Forward decl.
  class Visitor;

  /**
   * @class SendsTo_Impl
   *
   * Implementation for the SendsTo model element.
   */
  class PICML_Export SendsTo_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static SendsTo _create (const ComponentAssembly_in parent, OutEventPortEnd_in src, InEventPortEnd_in dst);
    ///@}

    // Default constructor.
    SendsTo_Impl (void);

    // Initializing constructor.
    SendsTo_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~SendsTo_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    OutEventPortEnd src_OutEventPortEnd (void) const;
    InEventPortEnd dst_InEventPortEnd (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "SendsTo.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_SENDSTO
