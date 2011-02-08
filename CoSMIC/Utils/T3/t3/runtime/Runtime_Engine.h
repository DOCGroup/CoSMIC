// -*- C++ -*-

//=============================================================================
/**
 *  @file         T3_Runtime_Engine.h
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _T3_RUNTIME_ENGINE_H_
#define _T3_RUNTIME_ENGINE_H_

#include "game/mga/utils/modelgen.h"
#include "game/mga/Model.h"

#include "ace/Null_Mutex.h"
#include "ace/Singleton.h"
#include "ace/SString.h"
#include "ace/Hash_Map_Manager.h"

#include "Runtime_export.h"
#include "Event_Listener.h"
#include "algorithm.h"

namespace T3
{
  /**
   * @class create_failed
   *
   * Exception thrown when creating an element fails for unknown
   * reasons.
   */
  class T3_RUNTIME_Export create_failed
  {
  public:
    create_failed (GAME::Mga::Object_in parent, const std::string & type)
      : parent_ (parent),
        type_ (type)
    {

    }

    GAME::Mga::Object parent (void) const
    {
      return this->parent_;
    }

    const std::string & type (void) const
    {
      return this->type_;
    }

  private:
    /// Parent for the creation.
    GAME::Mga::Object parent_;

    /// Target type to create.
    std::string type_;
  };

  /**
   * @class bad_parent
   *
   * Exception thrown when the specified parent object is not
   * eligible l to be a parent (i.e., not a Model or Folder).
   */
  class T3_RUNTIME_Export bad_parent
  {
  public:
    bad_parent (GAME::Mga::Object_in parent)
      : parent_ (parent)
    {

    }

  private:
    GAME::Mga::Object parent_;
  };

  /**
   * @class invalid_type
   *
   * Exception thrown when the specified type is not valid. This
   * can occur when creating an child element, or setting the value
   * of an attribute.
   */
  class T3_RUNTIME_Export invalid_type
  {
  public:
    invalid_type (GAME::Mga::Object_in parent, const std::string & type)
      : parent_ (parent),
        type_ (type)
    {

    }

  private:
    GAME::Mga::Object parent_;

    std::string type_;
  };

  /**
   * @class invalid_attr
   *
   * Exception thrown when the specified type is not valid. This
   * can occur when creating an child element, or setting the value
   * of an attribute.
   */
  class T3_RUNTIME_Export invalid_attr
  {
  public:
    invalid_attr (GAME::Mga::FCO_in fco, const std::string & attr)
      : fco_ (fco),
        attr_ (attr)
    {

    }

  private:
    GAME::Mga::FCO fco_;

    std::string attr_;
  };
}

/**
 * @class T3_Runtime_Engine
 */
class T3_RUNTIME_Export T3_Runtime_Engine
{
public:
  typedef ACE_Hash_Map_Manager <ACE_CString, GAME::Mga::FCO, ACE_Null_Mutex>
    SYMBOL_TABLE;

  typedef ACE_Hash_Map_Manager <ACE_CString, bool, ACE_Null_Mutex>
    FLAG_TABLE;

  typedef ACE_Hash_Map_Manager <ACE_CString, std::string, ACE_Null_Mutex>
    STRING_TABLE;

  typedef ACE_Hash_Map_Manager <ACE_CString, int, ACE_Null_Mutex>
    INT_TABLE;

  typedef ACE_Hash_Map_Manager <ACE_CString, double, ACE_Null_Mutex>
    DOUBLE_TABLE;

  /// Default constructor.
  T3_Runtime_Engine (void);

  /// Destructor.
  ~T3_Runtime_Engine (void);

  GAME::Mga::Object create_element (GAME::Mga::Object_in parent,
                               const std::string & type);

  template <typename Cond>
  GAME::Mga::Object create_element_if_not (GAME::Mga::Object_in parent,
                                           const std::string & type,
                                           Cond cond)
  {
    switch (parent->type ())
    {
    case OBJTYPE_MODEL:
      return create_element_if_not (GAME::Mga::Model::_narrow (parent), type, cond);
      break;

    case OBJTYPE_FOLDER:
      // ignore for now
      throw T3::bad_parent (parent);
      break;

    default:
      throw T3::bad_parent (parent);
    }
  }

  template <typename Cond>
  GAME::Mga::Object create_element_if_not (GAME::Mga::Model_in parent,
                                           const std::string & type,
                                           Cond cond)
  {
    // Get the children of the specified type.
    std::vector <GAME::Mga::FCO> children;
    GAME::Mga::Object object;

    if (parent->children (type, children))
    {
      std::vector <GAME::Mga::FCO>::const_iterator result;

      result = std::find_if (children.begin (),
                             children.end (),
                             cond);

      if (result != children.end ())
      {
        object = *result;

        if (0 != this->listener_)
          this->listener_->handle_new_object (object);
      }
    }

    // Since we could not find the object, we need to create
    // a new one for the model.
    if (object.is_nil ())
      object = this->create_element (parent, type);

    // Initialize the FCO.
    this->init_fco (GAME::Mga::FCO::_narrow (object));
    return object;
  }

  GAME::Mga::Object create_element (GAME::Mga::Folder_in parent,
                                    const std::string & type);

  GAME::Mga::Object create_element (GAME::Mga::Model_in parent,
                                    const std::string & type);

  bool create_connection_to (const GAME::Mga::Object_in src,
                             const std::string & dest,
                             const std::string & type);

  /**
   * Set the value of an attribute for the active object.
   *
   * @param[in]       name        Name of the target attribute
   * @param[in]       value       Value of the target attribute
   */
  void set_attribute (GAME::Mga::FCO_in fco, const std::string & name, const std::string & value);

  void set_attribute (GAME::Mga::FCO_in fco, const std::string & name, long value);

  void set_attribute (GAME::Mga::FCO_in fco, const std::string & name, bool value);

  void set_attribute (GAME::Mga::FCO_in fco, const std::string & name, double value);

  bool store_reference (const GAME::Mga::Object_in obj, const std::string & symbol);

  bool resolve (const GAME::Mga::Object_in obj, const std::string & symbol, GAME::Mga::FCO & fco);

  bool store_attribute (const std::string & name, bool value);

  bool store_attribute (const std::string & name, double value);

  bool store_attribute (const std::string & name, int value);

  bool store_attribute (const std::string & name, const std::string & value);

  bool store_predefined_reference (const GAME::Mga::Object_in obj, const char * pt);

  const SYMBOL_TABLE & symbols (void) const;

  SYMBOL_TABLE & symbols (void);

  void preprocess (GAME::Mga::Object_in parent, const std::string & include_file);

  bool create_unique_reference (GAME::Mga::Object_in parent,
                                const std::string & symbol,
                                const std::string & type);

  bool create_unique_reference (GAME::Mga::Object_in parent,
                                const std::string & symbol,
                                const std::string & type,
                                GAME::Mga::FCO & ref_element);

  T3_Event_Listener * event_listener (void);

  void event_listener (T3_Event_Listener * listener);

private:
  void preprocess_impl (GAME::Mga::Model_in model);

  void init_fco (GAME::Mga::FCO_in fco);

  void resolve_reference (GAME::Mga::FCO_in fco);

  /// Symbol table for the engine.
  SYMBOL_TABLE sym_table_;

  FLAG_TABLE stored_flags_;

  INT_TABLE stored_ints_;

  STRING_TABLE stored_strings_;

  DOUBLE_TABLE stored_doubles_;

  GAME::Mga::FCO stored_ref_;

  /// Event listener for the runtime engine.
  T3_Event_Listener * listener_;

  void get_scope (const GAME::Mga::Object_in obj, std::string & scope);
};

#define T3_RUNTIME_ENGINE_SINGLETON \
  ACE_Singleton <T3_Runtime_Engine, ACE_Null_Mutex>;

T3_RUNTIME_SINGLETON_DECLARATION (T3_RUNTIME_ENGINE_SINGLETON);

#define T3_RUNTIME_ENGINE \
  ACE_Singleton <T3_Runtime_Engine, ACE_Null_Mutex>::instance ()

#include "Runtime_Engine.inl"

#endif  // !defined _T3_RUNTIME_ENGINE_H_
