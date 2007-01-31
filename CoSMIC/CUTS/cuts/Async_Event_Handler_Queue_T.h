// -*- C++ -*-

//=============================================================================
/**
 * @file      Async_Event_Handler_Queue_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_ASYNC_EVENT_HANDLER_QUEUE_T_H_
#define _CUTS_ASYNC_EVENT_HANDLER_QUEUE_T_H_

#include "cuts/config.h"
#include "ace/Free_List.h"
#include "ace/Message_Queue_T.h"
#include "ace/Condition_Thread_Mutex.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/Time_Value.h"

//=============================================================================
/**
 * @class CUTS_Async_Event_Handler_Queue_Node_T
 */
//=============================================================================

template <typename EVENTTYPE>
class CUTS_Async_Event_Handler_Queue_Node_T
{
public:
  /// Type definition of the node type.
  typedef EVENTTYPE _type;

  /// Pointer to the event.
  EVENTTYPE * event_;

  /// The time of creation of the node.
  ACE_Time_Value toc_;
};


template <typename EVENTTYPE>
class CUTS_Cached_Async_Event_Handler_Queue_Node_T :
  public CUTS_Async_Event_Handler_Queue_Node_T <EVENTTYPE>
{
public:
  CUTS_Cached_Async_Event_Handler_Queue_Node_T * get_next (void) const;

  void set_next (CUTS_Cached_Async_Event_Handler_Queue_Node_T * next);

private:
  CUTS_Cached_Async_Event_Handler_Queue_Node_T * next_;
};

//=============================================================================
/**
 * @class CUTS_Async_Event_Handler_Queue_T
 */
//=============================================================================

template <typename EVENTTYPE>
class CUTS_Async_Event_Handler_Queue_T
{
public:
  /// Type definition of the event type for th queue.
  typedef EVENTTYPE _type;

  /// Type definition for the node type.
  typedef CUTS_Async_Event_Handler_Queue_Node_T <EVENTTYPE> _node_type;

  /// Default constructor.
  CUTS_Async_Event_Handler_Queue_T (void);

  /// Destructor.
  ~CUTS_Async_Event_Handler_Queue_T (void);

  /**
   * Insert an event into the message queue.
   *
   * @param[in]         event         The new event.
   * @return            Status of the operation.
   */
  int enqueue (EVENTTYPE * event);

  /**
   * Remove an event into the message queue.
   *
   * @param[out]        event     The new event.
   * @param[out]        toc       Get time of creation for event.
   * @return            Status of the operation.
   */
  int dequeue (EVENTTYPE * & event, ACE_Time_Value * toc = 0);

  /**
   * Get the size of the queue.
   *
   * @return      Number number of events in the queue.
   */
  size_t current_size (void) const;

  int is_empty (void);

private:
  /// Type definition of the cached node type.
  typedef CUTS_Cached_Async_Event_Handler_Queue_Node_T <
    typename _node_type::_type> _cache_type;

  /// Event queue for the underlying queue.
  ACE_Message_Queue_Ex <_node_type,
                        ACE_MT_SYNCH> event_queue_;

  /// Collection of free nodes to prevent (re)allocation.
  ACE_Locked_Free_List <
    _cache_type,
    ACE_RW_Thread_Mutex> free_list_;
};

#if defined (__CUTS_INLINE__)
#include "Async_Event_Handler_Queue_T.inl"
#endif

#include "Async_Event_Handler_Queue_T.cpp"

#endif  // !defined _CUTS_ASYNC_EVENT_HANDLER_QUEUE_T_H_
