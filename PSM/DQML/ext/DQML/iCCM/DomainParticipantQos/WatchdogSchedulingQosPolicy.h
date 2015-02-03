// -*- C++ -*-

//============================================================================
/**
 * @file    WatchdogSchedulingQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_DOMAINPARTICIPANTQOS_WATCHDOGSCHEDULINGQOSPOLICY_H_
#define _DQML_ICCM_DOMAINPARTICIPANTQOS_WATCHDOGSCHEDULINGQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/SchedulingQosPolicy/SchedulingQosPolicy.h"
#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class WatchdogSchedulingQosPolicy_Impl;
  typedef WatchdogSchedulingQosPolicy_Impl * WatchdogSchedulingQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < WatchdogSchedulingQosPolicy_Impl > WatchdogSchedulingQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class WatchdogSchedulingQosPolicy_Impl
   *
   * Implementation for the WatchdogSchedulingQosPolicy model element.
   */
  class DQML_Export WatchdogSchedulingQosPolicy_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual SchedulingQosPolicy_Impl
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
    static WatchdogSchedulingQosPolicy _create (const Participant_in parent);
    ///@}

    // Default constructor.
    WatchdogSchedulingQosPolicy_Impl (void);

    // Initializing constructor.
    WatchdogSchedulingQosPolicy_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~WatchdogSchedulingQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Participant parent_Participant (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "WatchdogSchedulingQosPolicy.inl"
#endif

#endif  // !defined _DQML_ICCM_DOMAINPARTICIPANTQOS_WATCHDOGSCHEDULINGQOSPOLICY
