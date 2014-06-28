// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeMapping.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPING_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPING_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeMapping_Impl;
  typedef AttributeMapping_Impl * AttributeMapping_in;
  typedef ::GAME::Mga::Smart_Ptr < AttributeMapping_Impl > AttributeMapping;

  // Forward decl.
  class Visitor;

  /**
   * @class AttributeMapping_Impl
   *
   * Implementation for the AttributeMapping model element.
   */
  class PICML_Export AttributeMapping_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static AttributeMapping _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    AttributeMapping_Impl (void);

    // Initializing constructor.
    AttributeMapping_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~AttributeMapping_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src AttributeMappingValue connection.
    size_t src_AttributeMappingValue (std::vector <AttributeMappingValue> & items) const;

    /// Get the src AttributeDelegate connection.
    size_t src_AttributeDelegate (std::vector <AttributeDelegate> & items) const;

    /// Get the src AttributeMappingDelegate connection.
    size_t src_AttributeMappingDelegate (std::vector <AttributeMappingDelegate> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst AttributeMappingDelegate connection.
    size_t dst_AttributeMappingDelegate (std::vector <AttributeMappingDelegate> & items) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool AttributeInstance_is_nil (void) const;
    AttributeInstance get_AttributeInstance (void) const;
    void set_AttributeInstance (AttributeInstance_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "AttributeMapping.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEMAPPING
