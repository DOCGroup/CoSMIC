// -*- C++ -*-

//=============================================================================
/**
 * @file      events_i.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_EVENTS_I_H_
#define _CUTS_EVENTS_I_H_

#include "cuts/config.h"
#include "cuts/eventsC.h"

namespace CUTS
{
  //===========================================================================
  /**
   * @class Empty_Event_i
   *
   * Implementation of a dummy message that has no payload.
   */
  //===========================================================================

  class Empty_Event_i :
    public virtual OBV_CUTS::Empty_Event,
    public virtual CORBA::DefaultValueRefCountBase
  {
  public:
    /// Default contructor.
    Empty_Event_i (void);

    /// Destructor.
    virtual ~Empty_Event_i (void);
  };

  //===========================================================================
  /**
   * @class Empty_Event_i
   *
   * Implementation of a dummy message that has a payload.
   */
  //===========================================================================

  class Payload_Event_i :
    public virtual OBV_CUTS::Payload_Event,
    public virtual CORBA::DefaultValueRefCountBase
  {
  public:
    /// Default constructor.
    Payload_Event_i (void);

    /// Destructor.
    virtual ~Payload_Event_i (void);

    /**
     * Initialize the payload of the event. This will set the
     * payload equal to \a size in bytes.
     */
    virtual void size (const ::CORBA::Long size);
  };
};

#if defined (__CUTS_INLINE__)
#include "cuts/events_i.inl"
#endif

#endif  // !defined _CUTS_EVENTS_I_H_
