//

#ifndef _GAME_MGA_SMART_PTR_H_
#define _GAME_MGA_SMART_PTR_H_

#include "game/config.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Smart_Ptr_Base
 *
 * Base class for all smart pointers. It defines common operations that
 * must exist in all smart pointers to provide consistent behavior.
 */
template <typename T>
class Smart_Ptr_Base
{
protected:
  /// Type definition for the implementation type.
  typedef T impl_type;

  /// Type definition of the interface type.
  typedef typename T::interface_type interface_type;

  /// Default constructor.
  Smart_Ptr_Base (void);

  /**
   * Initializing constructor.
   */
  Smart_Ptr_Base (T * impl);

  /**
   * Initializing constructor.
   */
  template <typename T1>
  Smart_Ptr_Base (T1 * impl);

  /**
   * Copy constructor.
   */
  Smart_Ptr_Base (const Smart_Ptr_Base & copy);

  /**
   * Copy constructor.
   */
  template <typename T1>
  Smart_Ptr_Base (const Smart_Ptr_Base <T1> & copy);

  /// Destructor.
  ~Smart_Ptr_Base (void);

public:
  T * operator -> (void);
  const T * operator -> (void) const;

  T * get (void);
  const T * get (void) const;

  T & operator * (void);
  const T & operator * (void) const;

  /// Compute the hash value of the smart pointer.
  unsigned long hash (void) const;

  operator T * (void);

  bool is_nil (void) const;

protected:
  /// Pointer to the actual implementation.
  T * impl_;
};

/**
 * @class Smart_Ptr
 *
 * Smart pointer class for standard object types, and return values.
 */
template <typename T>
class Smart_Ptr : public Smart_Ptr_Base <T>
{
public:
  /// Type definition of the base type.
  typedef Smart_Ptr_Base <T> base_type;

  /// Type definition for the implementation type.
  typedef typename base_type::impl_type impl_type;

  /// Type definition for the interface type.
  typedef typename base_type::interface_type interface_type;

  /// Default constructor.
  Smart_Ptr (void);

  /// Copy constructor.
  Smart_Ptr (const Smart_Ptr & ptr);

  template <typename T1>
  Smart_Ptr (const Smart_Ptr <T1> & ptr);

  template <typename T1>
  Smart_Ptr (T1 * impl);

  Smart_Ptr (typename T::interface_type * it);

  /// Destructor.
  ~Smart_Ptr (void);

  const Smart_Ptr & operator = (const Smart_Ptr & rhs);
  const Smart_Ptr & operator = (T * impl);

  template <typename T1>
  const Smart_Ptr & operator = (const Smart_Ptr <T1> & ptr);

  /**
   * Cast the implementation type to this implementation type.
   *
   * @param[in]     impl        Pointer to the implementation.
   * @return        Pointer
   */
  template <typename T1>
  static T * _narrow (T1 * impl);

  template <typename T1>
  static T * _narrow (const Smart_Ptr <T1> & impl);

  /// Release the contained implementation. This will not decrement
  /// the reference count for the previously contained implementation.
  T * _retn (void);

  bool operator < (const Smart_Ptr & ptr) const;
  bool operator > (const Smart_Ptr & ptr) const;

  template <typename T1>
  bool operator == (const Smart_Ptr <T1> & rhs) const;

  template <typename T1>
  bool operator != (const Smart_Ptr <T1> & rhs) const;

private:
  /// Helper method to reset this object's implementation.
  void reset (T * impl);
};

}
}

#if defined (__GAME_INLINE__)
#include "Smart_Ptr.inl"
#endif

#include "Smart_Ptr.cpp"

#endif
