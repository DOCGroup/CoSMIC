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

#include "cuts/CUTSC.h"

namespace OBV_CUTS
{
  //===========================================================================
  /**
   * @class Payload_Event_i
   *
   * Implementation of a dummy message that has a payload.
   */
  //===========================================================================

  class CUTS_STUB_Export Payload_Event_i :
    public OBV_CUTS::Payload_Event
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

  private:
    void fill (char * buf, size_t size);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/events_i.inl"
#endif

#endif  // !defined _CUTS_EVENTS_I_H_
