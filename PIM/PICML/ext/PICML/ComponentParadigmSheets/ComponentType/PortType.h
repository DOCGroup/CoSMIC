// -*- C++ -*-

//============================================================================
/**
 * @file    PortType.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PORTTYPE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PORTTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/NoInheritable.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PortType_Impl;
  typedef PortType_Impl * PortType_in;
  typedef ::GAME::Mga::Smart_Ptr < PortType_Impl > PortType;

  // Forward decl.
  class Visitor;

  /**
   * @class PortType_Impl
   *
   * Implementation for the PortType model element.
   */
  class PICML_Export PortType_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual NoInheritable_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static PortType _create (const HasOperations_in parent);
    static PortType _create (const Package_in parent);
    static PortType _create (const File_in parent);
    ///@}

    // Default constructor.
    PortType_Impl (void);

    // Initializing constructor.
    PortType_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~PortType_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const;
    ::GAME::Mga::Collection_T <ReadonlyAttribute> get_ReadonlyAttributes (void) const;

    size_t get_Attributes (std::vector <Attribute> & items) const;
    ::GAME::Mga::Collection_T <Attribute> get_Attributes (void) const;

    size_t get_ProvidedRequestPorts (std::vector <ProvidedRequestPort> & items) const;
    ::GAME::Mga::Collection_T <ProvidedRequestPort> get_ProvidedRequestPorts (void) const;

    size_t get_RequiredRequestPorts (std::vector <RequiredRequestPort> & items) const;
    ::GAME::Mga::Collection_T <RequiredRequestPort> get_RequiredRequestPorts (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PortType.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PORTTYPE
