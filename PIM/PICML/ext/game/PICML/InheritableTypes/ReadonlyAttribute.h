// -*- C++ -*-

//============================================================================
/**
 * @file    ReadonlyAttribute.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_READONLYATTRIBUTE_H_
#define _PICML_INHERITABLETYPES_READONLYATTRIBUTE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/IdTags/Taggable.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ReadonlyAttribute_Impl;
  typedef ReadonlyAttribute_Impl * ReadonlyAttribute_in;
  typedef ::GAME::Mga::Smart_Ptr < ReadonlyAttribute_Impl > ReadonlyAttribute;

  // Forward decl.
  class Visitor;

  /**
   * @class ReadonlyAttribute_Impl
   *
   * Implementation for the ReadonlyAttribute model element.
   */
  class PICML_Export ReadonlyAttribute_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual Taggable_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ReadonlyAttribute _create (const Inheritable_in parent);
    static ReadonlyAttribute _create (const Component_in parent);
    static ReadonlyAttribute _create (const PortType_in parent);
    static ReadonlyAttribute _create (const ConnectorObject_in parent);
    ///@}

    // Default constructor.
    ReadonlyAttribute_Impl (void);

    // Initializing constructor.
    ReadonlyAttribute_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ReadonlyAttribute_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Inheritable parent_Inheritable (void);
    Component parent_Component (void);
    PortType parent_PortType (void);
    ConnectorObject parent_ConnectorObject (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_AttributeMember (void) const;
    AttributeMember get_AttributeMember (void) const;
    size_t get_GetExceptions (std::vector <GetException> & items) const;
    ::GAME::Mga::Collection_T <GetException> get_GetExceptions (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ReadonlyAttribute.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_READONLYATTRIBUTE
