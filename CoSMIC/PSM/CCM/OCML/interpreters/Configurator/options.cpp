/*
 * @file: options.cpp
 *
 * All the options are stored in a tree structure at run-time.
 * The implementations of these options are contained in this file.
 * 
 * @author: Emre Turkay <emre.turkay@vanderbilt.edu>
 */

#include "options.h"
#include "rule_validator.h"

Tree_Node::Tree_Node(const char* name)
	: Named_Item(name)
{
}

Tree_Node&
Tree_Node::operator[](std::string child_name)
{
	return this->get_child(child_name);
}

Tree_Node&
Tree_Node::get_child(std::string)
{
	throw Exception_No_Child();
}

Option::Option(const char* name, const char* description)
	: Tree_Node(name), Described_Item(description), selected_(false)
{
}

bool
Option::selected() const
{
	return selected_;
}

void
Option::selected(bool value)
{
	selected_ = value;
}

Option_Value::Option_Value(const char* name, const char* description)
	: Option(name, description), selected_(false)
{
}

const std::string*
Option_Value::set(bool value)
{
	selected_ = value;
	selected(true);

	if (!rule_->validate())
		return new std::string("Rule violation");

	return 0;
}

bool Option_Value::get()
{
	return selected_;
}

Enum_Value::Enum_Value(const char* name, const char* description)
	: Option_Value(name, description) 
{
}

// prints out the value in the given stream in xml format
void
Enum_Value::write_xml(std::ostream& os)
{
	if (get())
		os << " " << name();
}

Set_Value::Set_Value(const char* name, const char* description)
	: Option_Value(name, description)
{
}

void Set_Value::write_xml(std::ostream& os)
{
	if (get())
		os << " | " << name();
}

Enum_Option::Enum_Option(const char* name, const char* description)
	: Model_Option<Enum_Value>(name, description)
{
}

Set_Option::Set_Option(const char* name, const char* description)
	: Model_Option<Set_Value>(name, description)
{
}

Integer_Option::Integer_Option(const char* name, const char* description)
	: Atom_Option<int>(name, description)
{
}

String_Option::String_Option(const char* name, const char* description)
	: Atom_Option<std::string>(name, description)
{
}

Flag_Option::Flag_Option(const char* name, const char* description)
	: Atom_Option<bool>(name, description, false)
{
}

Option_Category::Option_Category(const char* name, const char* description)
	: Option(name, description)
{
}

void
Option_Category::write_xml(std::ostream& os)
{
	Option_Category* category;

	for (iterator iter = begin(); iter != end(); ++iter) {
		category = dynamic_cast<Option_Category*>(*iter);
		if (category)
			category->write_xml(os);
	}

	os << std::endl 
	   << "<static id=\"" << name() << "\" params=\"";
	for (iterator iter1 = begin(); iter1 != end(); ++iter1)
		if (!dynamic_cast<Option_Category*>(*iter1)) {
			if (iter != begin())
				os << " ";
			(*iter1)->write_xml(os);
		}
	os << "\"/>\n";
}

Tree_Node&
Option_Category::get_child(std::string child_name)
{
	for (iterator iter = begin(); iter != end(); ++iter)
		if ((*iter)->name() == child_name)
			return **iter;
	throw Exception_No_Child();
}

// Delete all options
Option_Category::~Option_Category()
{
	for (iterator iter = begin(); iter != end(); ++iter)
		delete *iter;
}
