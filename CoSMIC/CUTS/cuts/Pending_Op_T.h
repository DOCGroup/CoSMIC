// -*- C++ -*-

#ifndef _CUTS_PENDING_OP_H_
#define _CUTS_PENDING_OP_H_

#include "cuts/config.h"

//=============================================================================
/**
 * CUTS_Pending_Op_T
 */
//=============================================================================

template <typename T>
class CUTS_Pending_Op_T
{
public:
  virtual ~CUTS_Pending_Op_T (void);

  virtual void execute (T * object) = 0;

protected:
  CUTS_Pending_Op_T (void);
};

//=============================================================================
/**
 * CUTS_Pending_Op0_T
 */
//=============================================================================

template <typename T>
class CUTS_Pending_Op0_T :
  public CUTS_Pending_Op_T <T>
{
public:
  typedef void (T::*method_type) (void);

  inline CUTS_Pending_Op0_T (method_type method)
    : method_ (method)
  {

  }

  virtual void execute (T * object)
  {
    (object->*(this->method_)) ();
  }

private:
  method_type method_;
};

//=============================================================================
/**
 * CUTS_Pending_Op1_T
 */
//=============================================================================

template <typename T,
          typename P1, typename A1>
class CUTS_Pending_Op1_T :
  public CUTS_Pending_Op_T <T>
{
public:
  typedef void (T::*method_type) (P1);

  inline CUTS_Pending_Op1_T (method_type method,
                             A1 arg1)
    : method_ (method),
      arg1_ (arg1)
  {

  }

  virtual void execute (T * object)
  {
    (object->*(this->method_)) (this->arg1_);
  }

private:
  method_type method_;

  A1 arg1_;
};

//=============================================================================
/**
 * CUTS_Pending_Op
 */
//=============================================================================

template <typename T>
CUTS_Pending_Op0_T <T> *
CUTS_Pending_Op (void (T::*method) (void))
{
  return new CUTS_Pending_Op0_T <T> (method);
}

template <typename T, typename P1, typename A1>
CUTS_Pending_Op1_T <T, P1, A1> *
CUTS_Pending_Op (void (T::*method) (P1), A1 arg1)
{
  return new CUTS_Pending_Op1_T <T, P1, A1> (method, arg1);
}

#if defined (__CUTS_INLINE__)
#include "cuts/Pending_Op_T.inl"
#endif

#include "cuts/Pending_Op_T.cpp"

#endif // !defined _CUTS_PENDING_OP_H_
