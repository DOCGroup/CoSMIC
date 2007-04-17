// -*- C++ -*-

//=============================================================================
/**
 * @file      mem_action_t.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_MEM_ACTION_T_H_
#define _CUTS_MEM_ACTION_T_H_

//=============================================================================
/**
 * CUTS_mem_action0_t
 */
//=============================================================================

template <typename R, typename T>
struct CUTS_mem_action0_t
{
  typedef R (T::*method_type) (void);

  inline CUTS_mem_action0_t (method_type method, T & object)
  : method_ (method),
    object_ (object)
  {
  }

  inline R operator () (void) const
  {
    return (this->object_.*(this->method_)) ();
  }

private:
  method_type method_;

  T & object_;
};

//=============================================================================
/**
 * CUTS_mem_action1_t
 */
//=============================================================================

template <typename R,  typename T, typename P1>
struct CUTS_mem_action1_t
{
  typedef R (T::*method_type) (P1);

  inline CUTS_mem_action1_t (method_type method, T & object)
  : method_ (method),
    object_ (object)
  {

  }

  template <typename A1>
  inline R operator () (A1 arg1) const
  {
    return (this->object_.*(this->method_)) (arg1);
  }

private:
  method_type method_;

  T & object_;
};

//=============================================================================
/**
 * CUTS_mem_action2_t
 */
//=============================================================================

template <typename R,  typename T, typename P1, typename P2>
struct CUTS_mem_action2_t
{
  typedef R (T::*method_type) (P1, P2);

  inline CUTS_mem_action2_t (method_type method, T & object)
  : method_ (method),
    object_ (object)
  {

  }

  template <typename A1, typename A2>
  inline R operator () (A1 arg1, A2 arg2) const
  {
    return (this->object_.*(this->method_)) (arg1, arg2);
  }

private:
  method_type method_;

  T & object_;
};

//=============================================================================
/**
 * CUTS_mem_action3_t
 */
//=============================================================================

template <typename R,  typename T,
          typename P1, typename P2, typename P3>
struct CUTS_mem_action3_t
{
  typedef R (T::*method_type) (P1, P2, P3);

  inline CUTS_mem_action3_t (method_type method, T & object)
  : method_ (method),
    object_ (object)
  {

  }

  template <typename A1, typename A2, typename A3>
  inline R operator () (A1 arg1, A2 arg2, A3 arg3) const
  {
    return (this->object_.*(this->method_)) (arg1, arg2, arg3);
  }

private:
  method_type method_;

  T & object_;
};

//=============================================================================
/**
 * CUTS_mem_action4_t
 */
//=============================================================================

template <typename R,  typename T,
          typename P1, typename P2, typename P3, typename P4>
struct CUTS_mem_action4_t
{
  typedef R (T::*method_type) (P1, P2, P3, P4);

  inline CUTS_mem_action4_t (method_type method, T & object)
  : method_ (method),
    object_ (object)
  {

  }

  template <typename A1, typename A2, typename A3, typename A4>
  inline R operator () (A1 arg1, A2 arg2, A3 arg3, A4 arg4) const
  {
    return (this->object_.*(this->method_)) (arg1, arg2, arg3, arg4);
  }

private:
  method_type method_;

  T & object_;
};

//=============================================================================
/**
 * CUTS_mem_action5_t
 */
//=============================================================================

template <typename R,  typename T,
          typename P1, typename P2, typename P3, typename P4, typename P5>
struct CUTS_mem_action5_t
{
  typedef R (T::*method_type) (P1, P2, P3, P4, P5);

  inline CUTS_mem_action5_t (method_type method, T & object)
  : method_ (method),
    object_ (object)
  {

  }

  template <typename A1, typename A2, typename A3,
            typename A4, typename A5>
  inline R operator () (A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5) const
  {
    return (this->object_.*(this->method_)) (arg1, arg2, arg3, arg4, arg5);
  }

private:
  method_type method_;

  T & object_;
};

//=============================================================================
/**
 * CUTS_mem_action
 *
 * Factory operation(s) that create the appropriate member action functor
 * for object methods.
 */
//=============================================================================

template <typename R, typename T>
CUTS_mem_action0_t <R, T>
CUTS_action (R (T::*method) (void), T & object)
{
  typedef CUTS_mem_action0_t <R, T> mem_action_t;
  return mem_action_t (method, object);
}

template <typename R,  typename T, typename P1>
CUTS_mem_action1_t <R, T, P1>
CUTS_action (R (T::*method) (P1), T & object)
{
  typedef
    CUTS_mem_action1_t <R, T, P1> mem_action_t;

  return mem_action_t (method, object);
}

template <typename R,  typename T,
          typename P1, typename P2>
CUTS_mem_action2_t <R,  T, P1, P2>
CUTS_action (R (T::*method) (P1, P2), T & object)
{
  typedef
    CUTS_mem_action2_t <R, T, P1, P2> mem_action_t;

  return mem_action_t (method, object);
}

template <typename R,  typename T,
          typename P1, typename P2, typename P3>
CUTS_mem_action3_t <R,  T, P1, P2, P3>
CUTS_action (R (T::*method) (P1, P2, P3), T & object)
{
  typedef
    CUTS_mem_action3_t <R, T, P1, P2, P3> mem_action_t;

  return mem_action_t (method, object);
}

#endif  // !defined _CUTS_MEM_ACTION_T_H_
