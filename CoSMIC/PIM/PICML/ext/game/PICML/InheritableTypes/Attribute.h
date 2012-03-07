// -*- C++ -*-

//============================================================================
/**
 * @file    Attribute.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_ATTRIBUTE_H_
#define _PICML_INHERITABLETYPES_ATTRIBUTE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Attribute_Impl;
  typedef Attribute_Impl * Attribute_in;
  typedef ::GAME::Mga::Smart_Ptr < Attribute_Impl > Attribute;

  // Forward decl.
  class Visitor;

  /**
   * @class Attribute_Impl
   *
   * Implementation for the Attribute model element.
   */
  class PICML_Export Attribute_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual ReadonlyAttribute_Impl
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
    static Attribute _create (const ConnectorObject_in parent);
    static Attribute _create (const Component_in parent);
    static Attribute _create (const PortType_in parent);
    static Attribute _create (const Inheritable_in parent);
    static Attribute _create (const ReadonlyAttribute_in parent);
    ///@}

    // Default constructor.
    Attribute_Impl (void);

    // Initializing constructor.
    Attribute_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Attribute_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_SetExceptions (std::vector <SetException> & items) const;
    ::GAME::Mga::Iterator <SetException> get_SetExceptions (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Attribute.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_ATTRIBUTE
