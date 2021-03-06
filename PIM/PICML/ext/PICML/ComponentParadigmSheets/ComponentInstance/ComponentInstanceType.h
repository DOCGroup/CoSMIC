// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentInstanceType.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_COMPONENTINSTANCETYPE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_COMPONENTINSTANCETYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentInstanceType_Impl;
  typedef ComponentInstanceType_Impl * ComponentInstanceType_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentInstanceType_Impl > ComponentInstanceType;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentInstanceType_Impl
   *
   * Implementation for the ComponentInstanceType model element.
   */
  class PICML_Export ComponentInstanceType_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentInstanceType _create (const ComponentInstance_in parent);
    ///@}

    // Default constructor.
    ComponentInstanceType_Impl (void);

    // Initializing constructor.
    ComponentInstanceType_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ComponentInstanceType_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentInstance parent_ComponentInstance (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool MonolithicImplementation_is_nil (void) const;
    MonolithicImplementation refers_to_MonolithicImplementation (void) const;
    void refers_to_MonolithicImplementation (MonolithicImplementation_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentInstanceType.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_COMPONENTINSTANCETYPE
