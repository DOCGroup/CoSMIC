// -*- C++ -*-

//============================================================================
/**
 * @file    Invoke.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_INVOKE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_INVOKE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Invoke_Impl;
  typedef Invoke_Impl * Invoke_in;
  typedef ::GAME::Mga::Smart_Ptr < Invoke_Impl > Invoke;

  // Forward decl.
  class Visitor;

  /**
   * @class Invoke_Impl
   *
   * Implementation for the Invoke model element.
   */
  class PICML_Export Invoke_Impl :
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
    static Invoke _create (const ComponentAssembly_in parent, RequiredRequestPortEnd_in src, ProvidedRequestPortEnd_in dst);
    ///@}

    // Default constructor.
    Invoke_Impl (void);

    // Initializing constructor.
    Invoke_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~Invoke_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    RequiredRequestPortEnd src_RequiredRequestPortEnd (void) const;
    ProvidedRequestPortEnd dst_ProvidedRequestPortEnd (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "Invoke.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_INVOKE
