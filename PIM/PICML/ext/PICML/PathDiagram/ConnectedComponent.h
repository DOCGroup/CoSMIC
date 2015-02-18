// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectedComponent.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_CONNECTEDCOMPONENT_H_
#define _PICML_PATHDIAGRAM_CONNECTEDCOMPONENT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PathDiagram/GraphVertex.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectedComponent_Impl;
  typedef ConnectedComponent_Impl * ConnectedComponent_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectedComponent_Impl > ConnectedComponent;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectedComponent_Impl
   *
   * Implementation for the ConnectedComponent model element.
   */
  class PICML_Export ConnectedComponent_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual GraphVertex_Impl
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
    static ConnectedComponent _create (const Path_in parent);
    ///@}

    // Default constructor.
    ConnectedComponent_Impl (void);

    // Initializing constructor.
    ConnectedComponent_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ConnectedComponent_Impl (void);

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
    size_t get_RequiredRequestPorts (std::vector <RequiredRequestPort> & items) const;
    ::GAME::Mga::Collection_T <RequiredRequestPort> get_RequiredRequestPorts (void) const;

    size_t get_ProvidedRequestPorts (std::vector <ProvidedRequestPort> & items) const;
    ::GAME::Mga::Collection_T <ProvidedRequestPort> get_ProvidedRequestPorts (void) const;

    size_t get_InEventPorts (std::vector <InEventPort> & items) const;
    ::GAME::Mga::Collection_T <InEventPort> get_InEventPorts (void) const;

    size_t get_OutEventPorts (std::vector <OutEventPort> & items) const;
    ::GAME::Mga::Collection_T <OutEventPort> get_OutEventPorts (void) const;

    size_t get_DstEdges (std::vector <DstEdge> & items) const;
    ::GAME::Mga::Collection_T <DstEdge> get_DstEdges (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectedComponent.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_CONNECTEDCOMPONENT
