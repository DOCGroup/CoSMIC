// -*- C++ -*-

//============================================================================
/**
 * @file    Component.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/NamedType.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Manageable.h"
#include "PICML/InheritableTypes/SupportsInterfaces.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Component_Impl;
  typedef Component_Impl * Component_in;
  typedef ::GAME::Mga::Smart_Ptr < Component_Impl > Component;

  // Forward decl.
  class Visitor;

  /**
   * @class Component_Impl
   *
   * Implementation for the Component model element.
   */
  class PICML_Export Component_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual NamedType_Impl,
    public virtual Manageable_Impl,
    public virtual SupportsInterfaces_Impl,
    public virtual TopLevelBehavior_Impl
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
    static Component _create (const Package_in parent);
    static Component _create (const File_in parent);
    ///@}

    // Default constructor.
    Component_Impl (void);

    // Initializing constructor.
    Component_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Component_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of UUID
    void UUID (const std::string & val);

    /// Get the value of UUID
    std::string UUID (void) const;

    /// Set the value of label
    void label (const std::string & val);

    /// Get the value of label
    std::string label (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ComponentInherits (void) const;
    ComponentInherits get_ComponentInherits (void) const;
    size_t get_ProvidedRequestPorts (std::vector <ProvidedRequestPort> & items) const;
    ::GAME::Mga::Collection_T <ProvidedRequestPort> get_ProvidedRequestPorts (void) const;

    size_t get_RequiredRequestPorts (std::vector <RequiredRequestPort> & items) const;
    ::GAME::Mga::Collection_T <RequiredRequestPort> get_RequiredRequestPorts (void) const;

    size_t get_OutEventPorts (std::vector <OutEventPort> & items) const;
    ::GAME::Mga::Collection_T <OutEventPort> get_OutEventPorts (void) const;

    size_t get_InEventPorts (std::vector <InEventPort> & items) const;
    ::GAME::Mga::Collection_T <InEventPort> get_InEventPorts (void) const;

    size_t get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const;
    ::GAME::Mga::Collection_T <ReadonlyAttribute> get_ReadonlyAttributes (void) const;

    size_t get_Attributes (std::vector <Attribute> & items) const;
    ::GAME::Mga::Collection_T <Attribute> get_Attributes (void) const;

    size_t get_MirrorPorts (std::vector <MirrorPort> & items) const;
    ::GAME::Mga::Collection_T <MirrorPort> get_MirrorPorts (void) const;

    size_t get_ExtendedPorts (std::vector <ExtendedPort> & items) const;
    ::GAME::Mga::Collection_T <ExtendedPort> get_ExtendedPorts (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Component.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENT
