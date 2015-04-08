// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeMappingDelegate.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPINGDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPINGDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeMappingDelegate_Impl;
  typedef AttributeMappingDelegate_Impl * AttributeMappingDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < AttributeMappingDelegate_Impl > AttributeMappingDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class AttributeMappingDelegate_Impl
   *
   * Implementation for the AttributeMappingDelegate model element.
   */
  class PICML_Export AttributeMappingDelegate_Impl :
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
    static AttributeMappingDelegate _create (const ComponentAssembly_in parent, AttributeMapping_in src, AttributeMapping_in dst);
    ///@}

    // Default constructor.
    AttributeMappingDelegate_Impl (void);

    // Initializing constructor.
    AttributeMappingDelegate_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~AttributeMappingDelegate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    AttributeMapping src_AttributeMapping (void) const;
    AttributeMapping dst_AttributeMapping (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "AttributeMappingDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPINGDELEGATE
