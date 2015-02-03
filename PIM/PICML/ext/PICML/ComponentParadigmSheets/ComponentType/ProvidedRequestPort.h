// -*- C++ -*-

//============================================================================
/**
 * @file    ProvidedRequestPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PROVIDEDREQUESTPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PROVIDEDREQUESTPORT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/MultiInputBase.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ProvidedRequestPort_Impl;
  typedef ProvidedRequestPort_Impl * ProvidedRequestPort_in;
  typedef ::GAME::Mga::Smart_Ptr < ProvidedRequestPort_Impl > ProvidedRequestPort;

  // Forward decl.
  class Visitor;

  /**
   * @class ProvidedRequestPort_Impl
   *
   * Implementation for the ProvidedRequestPort model element.
   */
  class PICML_Export ProvidedRequestPort_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual MultiInputBase_Impl,
    public virtual ObjectPort_Impl
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
    static ProvidedRequestPort _create (const PortType_in parent);
    static ProvidedRequestPort _create (const ConnectorObject_in parent);
    static ProvidedRequestPort _create (const Component_in parent);
    static ProvidedRequestPort _create (const ConnectedComponent_in parent);
    static ProvidedRequestPort _create (const Path_in parent);
    ///@}

    // Default constructor.
    ProvidedRequestPort_Impl (void);

    // Initializing constructor.
    ProvidedRequestPort_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ProvidedRequestPort_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Provideable_is_nil (void) const;
    Provideable refers_to_Provideable (void) const;
    void refers_to_Provideable (Provideable_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ProvidedRequestPort.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PROVIDEDREQUESTPORT
