/*
 *  @file: items.h
 *
 *  Contains classes Named_Item & Described_Item (generic base classes for all the options)
 *  
 *  @author: Emre Turkay <emre.turkay@vanderbilt.edu>
 */

#ifndef _ITEMS_H_
#define _ITEMS_H_

#include <string>

/*
 * class Named_Item
 *
 * A class which holds a constant name attribute
 */
class Named_Item {
public:
	// Constructor - name can be set only at constructor
	Named_Item(const char* name_value);

	// name() method returns the name of the object
	const std::string& name() const;

private:
	// The name of the object
	std::string name_;
};

/*
 * class Described_Item
 *
 * A class which holds a constant description attribute
 */
class Described_Item {
public:
	// Constructor - description can be set only at constructor
	Described_Item(const char* name_value);

	// description() method returns the description of the object
	const std::string& description() const;

private:
	// The description of the object
	std::string description_;
};

/*
 * All Named_Item & Described_Item methods are inline
 */

inline
Named_Item::Named_Item(const char* name)
	: name_(name)
{
}

inline const std::string&
Named_Item::name() const
{
	return name_;
}

inline
Described_Item::Described_Item(const char* description)
	: description_(description)
{
}

inline const std::string&
Described_Item::description() const
{
	return description_;
}

#endif // _ITEMS_H_

