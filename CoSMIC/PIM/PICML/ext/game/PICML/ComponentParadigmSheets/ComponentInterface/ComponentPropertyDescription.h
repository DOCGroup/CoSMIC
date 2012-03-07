// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentPropertyDescription.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTPROPERTYDESCRIPTION_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTPROPERTYDESCRIPTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentPropertyDescription_Impl;
  typedef ComponentPropertyDescription_Impl * ComponentPropertyDescription_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentPropertyDescription_Impl > ComponentPropertyDescription;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentPropertyDescription_Impl
   *
   * Implementation for the ComponentPropertyDescription model element.
   */
  class PICML_Export ComponentPropertyDescription_Impl :
    public virtual ::GAME::Mga::Model_Impl
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
    static ComponentPropertyDescription _create (const ComponentContainer_in parent);
    ///@}

    // Default constructor.
    ComponentPropertyDescription_Impl (void);

    // Initializing constructor.
    ComponentPropertyDescription_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ComponentPropertyDescription_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ComponentProperty connection.
    size_t dst_ComponentProperty (std::vector <ComponentProperty> & items) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    DataType get_DataType (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentPropertyDescription.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTPROPERTYDESCRIPTION
