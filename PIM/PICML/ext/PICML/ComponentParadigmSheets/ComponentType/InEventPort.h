// -*- C++ -*-

//============================================================================
/**
 * @file    InEventPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_INEVENTPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_INEVENTPORT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentType/EventPort.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/QueryInputBase.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/SingleInputBase.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InEventPort_Impl;
  typedef InEventPort_Impl * InEventPort_in;
  typedef ::GAME::Mga::Smart_Ptr < InEventPort_Impl > InEventPort;

  // Forward decl.
  class Visitor;

  /**
   * @class InEventPort_Impl
   *
   * Implementation for the InEventPort model element.
   */
  class PICML_Export InEventPort_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual EventPort_Impl,
    public virtual QueryInputBase_Impl,
    public virtual SingleInputBase_Impl
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
    static InEventPort _create (const ConnectedComponent_in parent);
    static InEventPort _create (const Component_in parent);
    static InEventPort _create (const Path_in parent);
    ///@}

    // Default constructor.
    InEventPort_Impl (void);

    // Initializing constructor.
    InEventPort_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~InEventPort_Impl (void);

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
    bool EventType_is_nil (void) const;
    EventType refers_to_EventType (void) const;
    void refers_to_EventType (EventType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "InEventPort.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_INEVENTPORT
