/*
 * @file: options.h
 *
 * All the options are stored in a tree structure at run-time.
 * The definitions of these options are contained in this file.
 * 
 * @author: Emre Turkay <emre.turkay@vanderbilt.edu>
 */

#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include "items.h"
#include "rule_validator.h"

#include <iostream>
#include <list>

/*
 *  Option classes
 */

// forward class declerations
class Rule;
class Option_Category;

/*
 *  class Tree_Node
 *
 *  Base class of the Option class.
 *  All options are tree nodes.
 */
class Tree_Node: public Named_Item {
public:
	// Exception thrown when the item is not in the 
	// contained items list
	class Exception_No_Child { };

	Tree_Node(const char* name);

	// get_child() method is accessed through operator[] - see get_child() method -
	Tree_Node& operator[](std::string child_name);

protected:
	// get_child method finds the child given it's name.
	// by default this method throws an exception.
	// This method is only overriden in the Option_Category class,
	// which is the only tree node with branches
	virtual Tree_Node& get_child(std::string);
};

/*
 * class Option
 *
 * Base class of all the options.
 */
class Option: public Tree_Node, public Described_Item {
public:
	Option(const char* name, const char* description);

	// write_xml() method prints out the value in xml format into the given stream
	virtual void write_xml(std::ostream&) = 0;

	// get & set methods for the selected attribute
	virtual bool selected() const;
	void selected(bool value);

	// static ptr to the rule instance
	static Rule *rule_;

private:
	// selected attribute holds the state of the option
	// If the option is set to a value by the user it is set to "true"
	// it's default value is "false"
	bool selected_;
};

/*
 *  Option values
 */

/*
 * class Option_Value
 *
 * Base class for enum and set option values
 */
class Option_Value: public Option {
public:
	Option_Value(const char* name, const char* description);

	// set and get methods for the selected attribute
	const std::string* set(bool value);

	bool get();

private:
	// selected_ attribute is the value of the option value (different from Option::selected_)
	bool selected_;
};

/*
 * class Enum_Value
 *
 * Enumerated value option.
 */
class Enum_Value: public Option_Value {
public:
	Enum_Value(const char* name, const char* description);

	// prints out the value in the given stream in xml format
	virtual void write_xml(std::ostream& os);
};

/*
 * class Set_Value
 *
 * Set value option.
 */
class Set_Value: public Option_Value {
public:
	Set_Value(const char* name, const char* description);

	// prints out the value in the given stream in xml format
	virtual void write_xml(std::ostream& os);
};

/*
 *  class Model_Option
 *
 *  Container for option values and the base class of Enum and Set options
 */
template<typename OPTION_VALUE>
class Model_Option: public Option, public std::list<OPTION_VALUE*> {
public:
	Model_Option(const char* name, const char* description)
		: Option(name, description) { }

	// prints out the value in the given stream in xml format
	virtual void write_xml(std::ostream& os) {
		if (selected()) {
			os << "-" << name();
			for (iterator iter=begin(); iter!=end(); ++iter)
				(*iter)->write_xml(os);
		}
	}

	virtual bool selected() {
		for (iterator iter=begin(); iter!=end(); ++iter)
			if ((*iter)->selected())
				return true;
		return false;
	}
};

/*
 * class Enum_Option
 *
 * Container for the Enum_Value options
 */
class Enum_Option: public Model_Option<Enum_Value> {
public:
	Enum_Option(const char* name, const char* description);
};

/*
 * class Set_Option
 *
 * Container for the Set_Value options
 */
class Set_Option: public Model_Option<Set_Value> {
public:
	Set_Option(const char* name, const char* description);
};

/*
 * class Atom_Option
 *
 * Base class of flag/string/integer options
 */
template<typename VALUE_TYPE>
class Atom_Option: public Option {
public:
	// value_type is bool/int/string for Flag/Integer/String options
	typedef VALUE_TYPE value_type;

	Atom_Option(const char* name, const char* description);

	Atom_Option(const char* name, const char* description, value_type value);

	// set and get methods for the value
	const std::string* set(value_type value);

	value_type get() const;

	// prints out the value in the given stream in xml format
	virtual void write_xml(std::ostream& os);

private:
	// The value of the option
	value_type value_;
};

// class Integer_Option: holds integer value
class Integer_Option: public Atom_Option<int> {
public:
	Integer_Option(const char* name, const char* description);
};

// class String_Option: holds string value
class String_Option: public Atom_Option<std::string> {
public:
	String_Option(const char* name, const char* description);
};

// class Flag_Option: holds boolean value
class Flag_Option: public Atom_Option<bool> {
public:
	Flag_Option(const char* name, const char* description);
};

/*
 * class Option_Category
 *
 * Container for other options (including other option categories)
 */
class Option_Category: public Option, public std::list<Option*> {
public:
	Option_Category(const char* name, const char* description);
	~Option_Category();

	// prints out the value in the given stream in xml format
	virtual void write_xml(std::ostream& os);

protected:
	// see Tree_Node::get_child() method description
	virtual Tree_Node& get_child(std::string child_name);
};

template<typename T>
Atom_Option<T>::Atom_Option(const char* name, const char* description)
	: Option(name, description)
{
}

template<typename T>
Atom_Option<T>::Atom_Option(const char* name, const char* description,
							Atom_Option<T>::value_type value)
	: Option(name, description), value_(value)
{
}

template<typename T> const std::string* 
Atom_Option<T>::set(T value)
{
	value_ = value;
	selected(true);
	
	// validate against rule violations
	if (!rule_->validate())
		return new std::string("Rule violation");

	return 0;
}

template<typename T> Atom_Option<T>::value_type 
Atom_Option<T>::get() const
{
	return value_;
}

template<typename T> void
Atom_Option<T>::write_xml(std::ostream& os)
{
	if (selected())
		os << "-" << name() << " " << value_ << " ";
}

#endif // _OPTIONS_H_

