// -*- C++ -*-

//=============================================================================
/**
 *
 */
//=============================================================================

#ifndef _CUTS_AUTO_FUNCTOR_T_H_
#define _CUTS_AUTO_FUNCTOR_T_H_

template <typename T>
class CUTS_Auto_Functor_T
{
public:
  /// Type definition for the pointer type.
  typedef T _type;

  /**
   * Initializing constructor.
   *
   * @param[in]     ptr     Pointer to the object to manage.
   */
  CUTS_Auto_Functor_T (T * ptr, void (T::*method) (void));

  /// Destructor.
  ~CUTS_Auto_Functor_T (void);

  /**
   * Detach from the current object. This will prevent the contained
   * element from being released when this object is destroyed. The
   * contained object is returned to the client.
   *
   * @return      Pointer to the contained object.
   */
  T * detach (void);

  /**
   * Force the object to manager a new element. This will cause
   * the current element to be released. To prevent the current
   * element from being released, the detach () method should
   * be invoked prior to this method.
   *
   * @param[in]     ptr     Pointer to the new element.
   */
  void reset (T * ptr = 0);

  /**
   * Get an unmanaged pointer to the element.
   *
   * @return    Pointer to the element.
   */
  T * get (void);

  /**
   * Pointer operator. This allows clients to use this class
   * as if it was a \a T pointer itself.
   *
   * @return    Pointer to the element.
   */
  T * operator -> (void);

  /**
   * Deference operator. This method returns a reference to the
   *contained element. If the \a ptr_ == 0, this a segmentation
   * fault will occur.
   *
   * @return      Reference to the element.
   */
  T & operator * (void);

private:
  /// Pointer to the element.
  T * ptr_;

  /// The method to invoke on \a ptr_ when reset.
  void (T::*method_) (void);
};

#if defined (__CUTS_INLINE__)
#include "cuts/Auto_Functor_T.inl"
#endif

#include "cuts/Auto_Functor_T.cpp"

#endif  // !defined _CUTS_AUTO_FUNCTOR_T_H_
