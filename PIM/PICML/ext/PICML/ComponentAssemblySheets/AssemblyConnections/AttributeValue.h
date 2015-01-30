// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeValue.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEVALUE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEVALUE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeValue_Impl;
  typedef AttributeValue_Impl * AttributeValue_in;
  typedef ::GAME::Mga::Smart_Ptr < AttributeValue_Impl > AttributeValue;

  // Forward decl.
  class Visitor;

  /**
   * @class AttributeValue_Impl
   *
   * Implementation for the AttributeValue model element.
   */
  class PICML_Export AttributeValue_Impl :
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
    static AttributeValue _create (const ComponentAssembly_in parent, AttributeInstance_in src, Property_in dst);
    ///@}

    // Default constructor.
    AttributeValue_Impl (void);

    // Initializing constructor.
    AttributeValue_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~AttributeValue_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    AttributeInstance src_AttributeInstance (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "AttributeValue.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ATTRIBUTEVALUE
