// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorObject.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINTERFACE_CONNECTOROBJECT_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINTERFACE_CONNECTOROBJECT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/NamedType.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorObject_Impl;
  typedef ConnectorObject_Impl * ConnectorObject_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectorObject_Impl > ConnectorObject;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectorObject_Impl
   *
   * Implementation for the ConnectorObject model element.
   */
  class PICML_Export ConnectorObject_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual NamedType_Impl
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
    static ConnectorObject _create (const Package_in parent);
    static ConnectorObject _create (const File_in parent);
    ///@}

    // Default constructor.
    ConnectorObject_Impl (void);

    // Initializing constructor.
    ConnectorObject_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ConnectorObject_Impl (void);

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
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ConnectorInherits (void) const;
    ConnectorInherits get_ConnectorInherits (void) const;
    size_t get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const;
    ::GAME::Mga::Collection_T <ReadonlyAttribute> get_ReadonlyAttributes (void) const;

    size_t get_Attributes (std::vector <Attribute> & items) const;
    ::GAME::Mga::Collection_T <Attribute> get_Attributes (void) const;

    size_t get_MirrorPorts (std::vector <MirrorPort> & items) const;
    ::GAME::Mga::Collection_T <MirrorPort> get_MirrorPorts (void) const;

    size_t get_ExtendedPorts (std::vector <ExtendedPort> & items) const;
    ::GAME::Mga::Collection_T <ExtendedPort> get_ExtendedPorts (void) const;

    size_t get_RequiredRequestPorts (std::vector <RequiredRequestPort> & items) const;
    ::GAME::Mga::Collection_T <RequiredRequestPort> get_RequiredRequestPorts (void) const;

    size_t get_ProvidedRequestPorts (std::vector <ProvidedRequestPort> & items) const;
    ::GAME::Mga::Collection_T <ProvidedRequestPort> get_ProvidedRequestPorts (void) const;

    size_t get_Aggregates (std::vector <Aggregate> & items) const;
    ::GAME::Mga::Collection_T <Aggregate> get_Aggregates (void) const;

    size_t get_Collections (std::vector <Collection> & items) const;
    ::GAME::Mga::Collection_T <Collection> get_Collections (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectorObject.inl"
#endif

#endif  // !defined _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINTERFACE_CONNECTOROBJECT
