// -*- C++ -*-

//============================================================================
/**
 * @file    TargetRequiredRequestPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_TARGETREQUIREDREQUESTPORT_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_TARGETREQUIREDREQUESTPORT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TargetRequiredRequestPort_Impl;
  typedef TargetRequiredRequestPort_Impl * TargetRequiredRequestPort_in;
  typedef ::GAME::Mga::Smart_Ptr < TargetRequiredRequestPort_Impl > TargetRequiredRequestPort;

  // Forward decl.
  class Visitor;

  /**
   * @class TargetRequiredRequestPort_Impl
   *
   * Implementation for the TargetRequiredRequestPort model element.
   */
  class PICML_Export TargetRequiredRequestPort_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static TargetRequiredRequestPort _create (const CallAction_in parent);
    ///@}

    // Default constructor.
    TargetRequiredRequestPort_Impl (void);

    // Initializing constructor.
    TargetRequiredRequestPort_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~TargetRequiredRequestPort_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    CallAction parent_CallAction (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool RequiredRequestPort_is_nil (void) const;
    RequiredRequestPort get_RequiredRequestPort (void) const;
    void set_RequiredRequestPort (RequiredRequestPort_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TargetRequiredRequestPort.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_TARGETREQUIREDREQUESTPORT
