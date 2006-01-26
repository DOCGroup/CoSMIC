#ifndef _CUTS_WORKER_T_H_
#define _CUTS_WORKER_T_H_

template <typename WORKER_TYPE>
class CUTS_Worker_Traits
{
public:
  static const long worker_id_ = 0;
};


template <typename ACTION_TYPE>
class CUTS_Action_Traits
{
public:
  /// Type definition for the id of the action.
  static const long action_id_ = 0;
};

template <typename WORKER_TYPE>
class CUTS_Action_T
{
public:
  typedef WORKER_TYPE Worker_Type;
};

#endif  // !define _CUTS_WORKER_T_H_
