// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeMappingValue.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPINGVALUE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPINGVALUE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeMappingValue_Impl;
  typedef AttributeMappingValue_Impl * AttributeMappingValue_in;
  typedef ::GAME::Mga::Smart_Ptr < AttributeMappingValue_Impl > AttributeMappingValue;

  // Forward decl.
  class Visitor;

  /**
   * @class AttributeMappingValue_Impl
   *
   * Implementation for the AttributeMappingValue model element.
   */
  class PICML_Export AttributeMappingValue_Impl :
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
    static AttributeMappingValue _create (const ComponentAssembly_in parent, AttributeMapping_in src, Property_in dst);
    ///@}

    // Default constructor.
    AttributeMappingValue_Impl (void);

    // Initializing constructor.
    AttributeMappingValue_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~AttributeMappingValue_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    AttributeMapping src_AttributeMapping (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "AttributeMappingValue.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPINGVALUE
