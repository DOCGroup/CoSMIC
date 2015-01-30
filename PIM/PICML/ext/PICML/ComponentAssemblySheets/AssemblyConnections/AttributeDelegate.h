// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeDelegate_Impl;
  typedef AttributeDelegate_Impl * AttributeDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < AttributeDelegate_Impl > AttributeDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class AttributeDelegate_Impl
   *
   * Implementation for the AttributeDelegate model element.
   */
  class PICML_Export AttributeDelegate_Impl :
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
    static AttributeDelegate _create (const ComponentAssembly_in parent, AttributeMapping_in src, AttributeInstance_in dst);
    ///@}

    // Default constructor.
    AttributeDelegate_Impl (void);

    // Initializing constructor.
    AttributeDelegate_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~AttributeDelegate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    AttributeMapping src_AttributeMapping (void) const;
    AttributeInstance dst_AttributeInstance (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "AttributeDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEDELEGATE
