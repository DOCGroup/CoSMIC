// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorImplementation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATION_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorImplementation_Impl;
  typedef ConnectorImplementation_Impl * ConnectorImplementation_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectorImplementation_Impl > ConnectorImplementation;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectorImplementation_Impl
   *
   * Implementation for the ConnectorImplementation model element.
   */
  class PICML_Export ConnectorImplementation_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual MonolithicImplementationBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ConnectorImplementation _create (const ConnectorImplementationContainer_in parent);
    ///@}

    // Default constructor.
    ConnectorImplementation_Impl (void);

    // Initializing constructor.
    ConnectorImplementation_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ConnectorImplementation_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorImplementationContainer parent_ConnectorImplementationContainer (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src ConnectorImplements connection.
    size_t src_of_ConnectorImplements (std::vector <ConnectorImplements> & items) const;
    bool has_src_of_ConnectorImplements (void) const;
    ConnectorImplements src_of_ConnectorImplements (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectorImplementation.inl"
#endif

#endif  // !defined _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTATION
