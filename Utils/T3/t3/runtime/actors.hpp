// -*- C++ -*-

//=============================================================================
/**
 *  @file         actors.hpp
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _T3_ACTORS_HPP_
#define _T3_ACTORS_HPP_

#include "boost/config/warning_disable.hpp"
#include "boost/bind.hpp"
#include "ace/streams.h"
#include "Runtime_Engine.h"
#include "Symbol.h"

namespace T3
{
  namespace qi = ::boost::spirit::qi;
  namespace fusion = ::boost::fusion;

  template <typename COND>
  struct negate
  {
    negate (COND cond)
      : cond_ (cond)
    {

    }

    template <typename T>
    bool operator () (T element) const
    {
      return !this->cond_ (element);
    }

  private:
    /// The condition to negate.
    COND cond_;

    negate (negate &);
    const negate & operator = (const negate & rhs);
  };

  /**
   * @struct new_element
   */
  struct new_element
  {
    new_element (const char * type)
      : type_ (type)
    {

    }

    template <typename Context>
    void operator () (const std::string & name, Context & ctx, bool & result) const
    {
      try
      {
        // Get parent from the context, which is qi::_r1.
        Auto_Model & parent = fusion::at_c <1> (ctx.attributes);

        // Create the new element based on its type and store
        GAME::Mga::Object object = parent.create_element (this->type_);

        // Since we know its the name, let's set the name.
        object.name (name);

        // Store the new object as the return value (i.e., qi::_val).
        fusion::at_c <0> (ctx.attributes) = object;
        result = true;
      }
      catch (...)
      {
        result = false;
      }
    }

  private:
    /// Type of element to create.
    const char * type_;
  };

  /**
   * @struct new_unique_element
   */
  struct new_unique_element
  {
    new_unique_element (const char * type)
      : type_ (type)
    {

    }

    template <typename Context>
    void operator () (const std::string & name, Context & ctx, bool & result) const
    {
      try
      {
        // Get parent from the context, which is qi::_r1.
        Auto_Model & parent = fusion::at_c <1> (ctx.attributes);

        // Create the new element based on its type and store
        GAME::Mga::Object object =
          parent.create_element_if_not (this->type_,
                                        boost::bind (std::equal_to <std::string> (),
                                                     name,
                                                     boost::bind (&GAME::Mga::FCO::impl_type::name,
                                                                  boost::bind (&GAME::Mga::FCO::get, _1))));

        // Since we know its the name, let's set the name.
        object->name (name);

        // Store the new object as the return value (i.e., qi::_val).
        fusion::at_c <0> (ctx.attributes) = object.get ();
        result = true;
      }
      catch (...)
      {
        result = false;
      }
    }

  private:
    /// Type of element to create.
    const char * type_;
  };

  /**
   * @struct new_unique_element
   */
  struct create_connection_to
  {
    create_connection_to (const char * type)
      : type_ (type)
    {

    }

    template <typename Context>
    void operator () (const std::string & dest, Context & ctx, bool & result) const
    {
      try
      {
        // Get this object from the context, which is qi::_val.
        Auto_Model & object = fusion::at_c <0> (ctx.attributes);

        // Create the new element based on its type and store
        result =
          T3_RUNTIME_ENGINE->create_connection_to (object.model (),
                                                   dest,
                                                   this->type_);
      }
      catch (...)
      {
        result = false;
      }
    }

  private:
    /// Type of element to create.
    const char * type_;
  };

  /**
   * @struct set_attribute
   */
  struct set_attribute
  {
    set_attribute (const char * attr_name)
      : attr_name_ (attr_name)
    {

    }

    template <typename T, typename Context>
    void operator () (T value, Context & ctx, bool & result) const
    {
      try
      {
        // Get parent from the context, which is qi::_r1.
        Auto_Model & model = fusion::at_c <0> (ctx.attributes);
        GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (model.model ());

        T3_RUNTIME_ENGINE->set_attribute (fco, this->attr_name_, value);
        result = true;
      }
      catch (...)
      {
        // The semantic action failed.
        result = false;
      }
    }

  private:
    const char * attr_name_;
  };

  /**
   * @struct new_unique_reference
   *
   * Functor for creating a unique element based on its
   * referenced value.
   */
  struct new_unique_reference
  {
    /**
     * Initializing constructor.
     */
    new_unique_reference (const char * type)
      : type_ (type)
    {

    }

    template <typename Context>
    void operator () (const std::string & symbol, Context & ctx, bool & result) const
    {
      try
      {
        // Get parent from the context, which is qi::_r1.
        Auto_Model & parent = fusion::at_c <1> (ctx.attributes);
        result = parent.create_unique_reference (symbol, this->type_);
      }
      catch (...)
      {
        // The semantic action failed.
        result = false;
      }
    }

  private:
    const char * type_;
  };

  /**
   * @struct store_predefined_reference
   */
  struct store_predefined_reference
  {
    store_predefined_reference (const char * type)
      : type_ (type)
    {

    }

    template <typename Context>
    void operator () (qi::unused_type, Context & ctx, bool & result) const
    {
      try
      {
        // Locate the type in the project.
        Auto_Model & model = fusion::at_c <1> (ctx.attributes);
        result = T3_RUNTIME_ENGINE->store_predefined_reference (model.model (), this->type_);
      }
      catch (...)
      {
        // The semantic action failed.
        result = false;
      }
    }

  private:
    const char * type_;
  };

  /**
   * @struct store_reference
   */
  struct store_reference
  {
    template <typename Context>
    void operator () (const std::string & symbol, Context & ctx, bool & result) const
    {
      try
      {
        Auto_Model & model = fusion::at_c <1> (ctx.attributes);
        result = T3_RUNTIME_ENGINE->store_reference (model.model (), symbol);
      }
      catch (...)
      {
        // The semantic action failed.
        result = false;
      }
    }
  };

  /**
   * @struct preprocess
   */
  struct preprocess
  {
    template <typename Context>
    void operator () (const std::string & include_file, Context & ctx, bool & result) const
    {
      try
      {
        Auto_Model & model = fusion::at_c <1> (ctx.attributes);
        T3_RUNTIME_ENGINE->preprocess (model.model (), include_file);
      }
      catch (...)
      {
        // The semantic action failed.
        result = false;
      }
    }
  };

  /**
   * @struct store_attribute_bool
   *
   * Functor that caches the value of boolean attribute. The attribute
   * is then set for the next object that is created.
   */
  template <bool value>
  struct store_attribute_bool
  {
    store_attribute_bool (const char * name)
      : name_ (name)
    {

    }

    template <typename Context>
    void operator () (qi::unused_type, Context & ctx, bool & result) const
    {
      try
      {
        result = T3_RUNTIME_ENGINE->store_attribute (this->name_, value);
      }
      catch (...)
      {
        // The semantic action failed.
        result = false;
      }
    }

  private:
    const char * name_;
  };

  /**
   * @struct store_attribute
   *
   * Functor that caches the value of an attribute. The attribute
   * is then set for the next object that is created.
   */
  struct store_attribute
  {
    store_attribute (const char * name)
      : name_ (name)
    {

    }

    template <typename T, typename Context>
    void operator () (T value, Context & ctx, bool & result) const
    {
      try
      {
        result = T3_RUNTIME_ENGINE->store_attribute (this->name_, value);
      }
      catch (...)
      {
        // The semantic action failed.
        result = false;
      }
    }

  private:
    const char * name_;
  };

  /**
   * @struct create_symbol
   */
  struct create_symbol
  {
    create_symbol (T3_Symbol & symbol_gen)
      : symbol_gen_ (symbol_gen)
    {

    }

    template <typename Context>
    void operator () (qi::unused_type, Context & ctx, bool & result) const
    {
      try
      {
        // Get the current qi::_val
        Auto_Model & model = fusion::at_c <0> (ctx.attributes);
        GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (model.model ());

        ACE_CString symbol;
        if (this->symbol_gen_.generate (fco, symbol) == 0)
        {
          // Try to insert the symbol into the table.
          int result = T3_RUNTIME_ENGINE->symbols ().bind (symbol, fco);

          switch (result)
          {
          case -1:
            std::cerr << "*** internal error: failed to create symbol" << std::endl;
            result = false;
            break;

          case 1:
            std::cerr << "*** error: duplicate symbol" << std::endl;
            result = false;
            break;

          case 0:
            result = true;
            break;
          }
        }
        else
        {
          result = false;
        }
      }
      catch (...)
      {
        // The semantic action failed.
        result = false;
      }
    }

  private:
    T3_Symbol & symbol_gen_;
  };
}

#endif  // !defined _T3_ACTORS_HPP_
