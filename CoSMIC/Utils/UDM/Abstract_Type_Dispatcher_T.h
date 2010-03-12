// -*- C++ -*-

//=============================================================================
/**
 * @file            UDM_Abstract_Type_Dispatcher_T.h
 *
 * $Id$
 *
 * @author          James H. Hill
 */
//=============================================================================

#ifndef _UDM_ABSTRACT_TYPE_DISPATCHER_H_
#define _UDM_ABSTRACT_TYPE_DISPATCHER_H_

#include <map>
#include "Uml.h"

/**
 * @class UDM_Abstract_Type_Acceptor_Base_T
 */
template <typename VISITOR>
class UDM_Abstract_Type_Acceptor_Base_T
{
public:
  /**
   * Invoke the accept method on the object using the supplied
   * visitor.
   */
  virtual void accept (VISITOR & visitor, const Udm::Object & object) = 0;
};

/**
 * @class UDM_Abstract_Type_Acceptor_T
 */
template <typename T, typename VISITOR>
class UDM_Abstract_Type_Acceptor_T :
  public UDM_Abstract_Type_Acceptor_Base_T <VISITOR>
{
public:
  /**
   * Invoke the accept method on the object using the supplied
   * visitor.
   *
   * @param[in]         visitor         The target visitor.
   * @param[in]         object          The target object.
   */
  virtual void accept (VISITOR & v, const Udm::Object & object)
  {
    T type = T::Cast (object);
    type.Accept (v);
  }
};

/**
 * @class UDM_Abstract_Type_Dispatcher_T
 */
template <typename VISITOR>
class UDM_Abstract_Type_Dispatcher_T
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     parent          Parent of the dispatcher.
   */
  UDM_Abstract_Type_Dispatcher_T (void);

  /// Destructor.
  ~UDM_Abstract_Type_Dispatcher_T (void);

  /**
   * Insert a new acceptor into the dispatcher for the specified
   * type.
   *
   * @param[in]     type            The UML type.
   * @param[in]     acceptor        The acceptor for the type.
   */
  template <typename T>
  void insert (void);

  /**
   * Dispatch a UDM object. This method will locate the correct
   * acceptor and call its accept method. If a acceptor does not
   * exist, then the function will return immediately.
   *
   * @param[in]     object          Dispatch the object.
   */
  bool dispatch (VISITOR & v, const Udm::Object & object) const;

  /// Test if the object is empty, i.e., has no elements.
  bool is_empty (void) const;


private:
  /// Type definition for the acceptor map.
  typedef std::map <Uml::Class,
                    UDM_Abstract_Type_Acceptor_Base_T <VISITOR> *>
                    UDM_Acceptor_Map;

  /// Collection of acceptors for this dispatcher.
  UDM_Acceptor_Map acceptors_;
};

#include "Abstract_Type_Dispatcher_T.cpp"

#endif  // !defined _UDM_ABSTRACT_TYPE_DISPATCHER_T_H_
