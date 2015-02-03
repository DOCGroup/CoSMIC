// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorImplementationContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATIONCONTAINER_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATIONCONTAINER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorImplementationContainer_Impl;
  typedef ConnectorImplementationContainer_Impl * ConnectorImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectorImplementationContainer_Impl > ConnectorImplementationContainer;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectorImplementationContainer_Impl
   *
   * Implementation for the ConnectorImplementationContainer model element.
   */
  class PICML_Export ConnectorImplementationContainer_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual ImplementationContainer_Impl
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
    static ConnectorImplementationContainer _create (const ConnectorImplementations_in parent);
    ///@}

    // Default constructor.
    ConnectorImplementationContainer_Impl (void);

    // Initializing constructor.
    ConnectorImplementationContainer_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ConnectorImplementationContainer_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorImplementations parent_ConnectorImplementations (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ConnectorImplementations (std::vector <ConnectorImplementation> & items) const;
    ::GAME::Mga::Collection_T <ConnectorImplementation> get_ConnectorImplementations (void) const;

    size_t get_ConnectorImplementss (std::vector <ConnectorImplements> & items) const;
    ::GAME::Mga::Collection_T <ConnectorImplements> get_ConnectorImplementss (void) const;

    size_t get_ConnectorTypes (std::vector <ConnectorType> & items) const;
    ::GAME::Mga::Collection_T <ConnectorType> get_ConnectorTypes (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectorImplementationContainer.inl"
#endif

#endif  // !defined _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATIONCONTAINER
