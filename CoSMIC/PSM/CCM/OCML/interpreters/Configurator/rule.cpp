/*
 * @file: rule.cpp
 *
 * Functions checking options for certain conditions used by the generated code.
 * 
 * @author: Emre Turkay <emre.turkay@vanderbilt.edu>
 */

#include "options.h"

// maximum
bool check_max(const Integer_Option* option, int max_value)
{
	return option->get() <= max_value;
}

// minimum
bool check_min(const Integer_Option* option, int min_value)
{
	return option->get() >= min_value;
}

// range
bool check_range(const Integer_Option* option, int max_value, int min_value)
{
	return
		check_max(option, max_value) &&
		check_min(option, min_value);
}

// equal to value
bool check_int_eq(const Integer_Option* option, int value)
{
	return (option->get() == value);
}

bool check_str_eq(const String_Option* option, const char* value)
{
	return (option->get() == value);
}

bool check_flag_eq(const Flag_Option* option, bool value)
{
	return (option->get() == value);
}

// has a value
bool check_selected(const Option* option)
{
	return option->selected();
}

// equal to another option
bool check_flag_val_eq(const Flag_Option* option1, const Flag_Option* option2)
{
	return option1->get() == option2->get();
}

bool check_int_val_eq(const Integer_Option* option1, const Integer_Option* option2)
{
	return option1->get() == option2->get();
}

bool check_str_val_eq(const String_Option* option1, const String_Option* option2)
{
	return option1->get() == option2->get();
}

