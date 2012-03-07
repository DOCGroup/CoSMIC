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
    size_t get_ObjectPorts (std::vector <ObjectPort> & items) const;
    ::GAME::Mga::Iterator <ObjectPort> get_ObjectPorts (void) const;

    size_t get_ExtendedPortBases (std::vector <ExtendedPortBase> & items) const;
    ::GAME::Mga::Iterator <ExtendedPortBase> get_ExtendedPortBases (void) const;

    size_t get_Aggregates (std::vector <Aggregate> & items) const;
    ::GAME::Mga::Iterator <Aggregate> get_Aggregates (void) const;

    size_t get_Collections (std::vector <Collection> & items) const;
    ::GAME::Mga::Iterator <Collection> get_Collections (void) const;

    size_t get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const;
    ::GAME::Mga::Iterator <ReadonlyAttribute> get_ReadonlyAttributes (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectorObject.inl"
#endif

#endif  // !defined _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINTERFACE_CONNECTOROBJECT
