/**
 * Definition of the basic (integer, string, boolean) options.
 *
 * @file BasicOptions.hpp
 * @author Emre Turkay <turkaye@dre.vanderbilt.edu>
 */

#ifndef BASIC_OPTIONS_HPP
#define BASIC_OPTIONS_HPP

#include <string>
#include <memory>
#include <exception>
#include <list>

#include "Option.hpp"

/**
 * class BasicOption is the base class for boolean, integer, and string
 * options.
 *
 * Template argument VALUE_TYPE specifies the data type of the option value.
 */
template <typename VALUE_TYPE>
class BasicOption: public Option
{
protected:
  /// Constructor.
  BasicOption(value_kind_type value_kind,
	      const char* name, const char* description);

public:
  /// Template value type.
  typedef VALUE_TYPE value_type;

public:
  /// Descructor.
  virtual ~BasicOption();

  // First defined at DescribedItem, reimplemented at Option.
  virtual xercesc::DOMElement* write(xercesc::DOMDocument* doc) const;

  // Defined as abstract at Option.
  virtual void clear();

  // Defined as abstract at Option.
  virtual bool assigned() const;

  /// Set method for the option value.
  virtual void set(value_type value);

  /// Getter method for the option value. Throws NotAssigned.
  virtual value_type get() const;

  /// Returns the value as string to export files or display via GUI widgets.
  virtual std::string get_str_value() const = 0;

private:
  /// Pointer to the option value.
  std::auto_ptr<value_type> value_;
};

/**
 * Option for boolean values.
 */
class BooleanOption: public BasicOption<bool>
{
public:
  /// Constructor.
  BooleanOption(const char* name, const char* description);

  // Defined as abstract at DescribedItem.
  virtual const char* type_string() const;

  // Defined as abstract at BasicOption.
  virtual std::string get_str_value() const;
};

/**
 * Option for string values.
 */
class StringOption: public BasicOption<std::string>
{
public:
  /// Constructor.
  StringOption(const char* name, const char* description);

  // Defined as abstract at DescribedItem.
  const char* type_string() const;

  // Defined as abstract at BasicOption.
  virtual std::string get_str_value() const;
};

/**
 * Option for integer values.
 */
class IntegerOption: public BasicOption<int>
{
public:
  /// Constructor.
  IntegerOption(const char* name, const char* description);

  // Defined as abstract at DescribedItem.
  const char* type_string() const;

  // Defined as abstract at BasicOption.
  virtual std::string get_str_value() const;
};

/**
 * Option for enumerated values.
 */
class EnumOption: public BasicOption<std::string>
{
private:
  typedef std::list<std::string> items_type;

public:
  typedef items_type::iterator item_iterator;

  class InvalidItem: public std::exception
  {
  public:
    InvalidItem(const std::string& msg)
      : msg_(std::string("EnumOption:InvalidItem ") +
             std::string("\"") +
             msg +
             std::string("\""))
    {
    }

    virtual ~InvalidItem() throw()
    {
    }

    virtual const char* what() const throw()
    {
      return msg_.c_str();
    }

  private:
    std::string msg_;
  };

public:
  /// Constructor.
  EnumOption(const char* name, const char* description);

  /// Defined as abstract at DescribedItem.
  const char* type_string() const;

  /// Defined at BasicOption, reimplemented by EnumOption.
  virtual void set(value_type value);

  /// Defined as abstract at BasicOption.
  virtual std::string get_str_value() const;

  /// Appends a new item to the items list.
  void add_item(const char* item_name);

  /// Begin marker for the enum items
  item_iterator begin_items();
  /// End marker for the enum items
  item_iterator end_items();

private:
  items_type items_;
};

#include "BasicOptions.ipp"
#include "BasicOptions.tpp"

#endif // BASIC_OPTIONS_HPP
