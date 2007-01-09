// -*- C++ -*-

#ifndef _CUTS_PENDING_OP_LIST_H_
#define _CUTS_PENDING_OP_LIST_H_

#include "cuts/config.h"
#include "ace/Unbounded_Queue.h"

// Forward decl.
template <typename T>
class CUTS_Pending_Op_T;

template <typename T>
class CUTS_Pending_Op_List_T
{
public:
  /// Default constructor.
  CUTS_Pending_Op_List_T (void);

  /// Destructor.
  ~CUTS_Pending_Op_List_T (void);

  /**
   * Get the number of pending operations.
   *
   * @return      Number of pending operations.
   */
  size_t size (void) const;

  /**
   * Insert a pending operation into the listing. This will place
   * the new operation at the end of the list so ensure excution
   * consistency. Once the operation is in the listing, this class
   * will take care of managing it's memory.
   *
   * @param[in]       op          Pointer to the pending operation.
   */
  int insert (CUTS_Pending_Op_T <T> * op);

  /**
   * Process all the pending operations. The return value is the
   * number of operations that we failed to process.
   *
   * @param[in]     object      Target object for the operations.
   * @return        Number of failed operations.
   */
  int process (T * object);

  /// Remove all the pending operations and their allocated resources.
  /// This will not process any of the pending operations. If you need
  /// to process the pending operations, use the process () method.
  void reset (void);

private:
  /// Type definition for the queue of pending operations.
  typedef ACE_Unbounded_Queue <CUTS_Pending_Op_T <T> *> Pending_Op_Queue;

  /// Queue of pending operations.
  Pending_Op_Queue queue_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Pending_Op_List_T.inl"
#endif

#include "cuts/Pending_Op_List_T.cpp"

#endif  // !defined _CUTS_PENDING_OP_LIST_H_
