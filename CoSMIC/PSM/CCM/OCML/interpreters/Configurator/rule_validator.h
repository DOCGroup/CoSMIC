/*
 * @file: rule_validator.h
 *
 * Rule validator class
 * 
 * @author: Emre Turkay <emre.turkay@vanderbilt.edu>
 */

#ifndef _RULE_VALIDATOR_
#define _RULE_VALIDATOR_

#include "options.h"
#include "rule.h"

class Option_Category;

// The implementation of rule_check is automatically generated
bool rule_check(Option_Category& root);

class Rule {
public:
	Rule(Option_Category* root);
	// returns true if the category is valid
	bool validate();

private:
	Option_Category* root_;
};

inline
Rule::Rule(Option_Category *root)
	: root_(root)
{
}

inline bool
Rule::validate()
{
	return rule_check(*root_);
}

#endif 