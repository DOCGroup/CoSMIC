/*
 * @file: rule.h
 *
 * Utility functions for the rule processor.
 * These functions are used by the generated rule_validator code.
 * 
 * @author: Emre Turkay <emre.turkay@vanderbilt.edu>
 */
#ifndef _RULE_H_
#define _RULE_H_

// These classes are defined in the "options.h" file
// That file is not included for compile time performance
class Integer_Option;
class Flag_Option;
class String_Option;
class Option;

// Integer range check functions
// returns true if value of the option is smaller/greater/in the range than/of given value(s)
bool check_max(const Integer_Option* option, int max_value);
bool check_min(const Integer_Option* option, int min_value);
bool check_range(const Integer_Option* option, int max_value, int min_value);

// Checks if the value of given integer/string/flag option is equal to the given "value"
bool check_int_eq(const Integer_Option* option, int value);
bool check_str_eq(const String_Option* option, const char* value);
bool check_flag_eq(const Flag_Option* option, bool value);

// Returns true if the specified option is selected (the user has set a value for it)
bool check_selected(const Option* option);

// Returns true if the given two options have the same value
bool check_flag_val_eq(const Flag_Option* option1, const Flag_Option* option2);
bool check_int_val_eq(const Integer_Option* option1, const Integer_Option* option2);
bool check_str_val_eq(const String_Option* option1, const String_Option* option2);

#endif // _RULE_H_

