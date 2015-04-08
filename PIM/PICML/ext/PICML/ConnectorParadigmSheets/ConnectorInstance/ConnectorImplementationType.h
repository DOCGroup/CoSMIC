// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorImplementationType.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINSTANCE_CONNECTORIMPLEMENTATIONTYPE_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINSTANCE_CONNECTORIMPLEMENTATIONTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorImplementationType_Impl;
  typedef ConnectorImplementationType_Impl * ConnectorImplementationType_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectorImplementationType_Impl > ConnectorImplementationType;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectorImplementationType_Impl
   *
   * Implementation for the ConnectorImplementationType model element.
   */
  class PICML_Export ConnectorImplementationType_Impl :
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
    static ConnectorImplementationType _create (const ConnectorInstance_in parent);
    ///@}

    // Default constructor.
    ConnectorImplementationType_Impl (void);

    // Initializing constructor.
    ConnectorImplementationType_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ConnectorImplementationType_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorInstance parent_ConnectorInstance (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ConnectorImplementation_is_nil (void) const;
    ConnectorImplementation refers_to_ConnectorImplementation (void) const;
    void refers_to_ConnectorImplementation (ConnectorImplementation_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectorImplementationType.inl"
#endif

#endif  // !defined _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINSTANCE_CONNECTORIMPLEMENTATIONTYPE
