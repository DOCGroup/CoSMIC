#ifndef _OCML_BON_EXTENSION_H_
#define _OCML_BON_EXTENSION_H_

#include "Extensions.h"
#include "BONImpl.h"
#include <ComponentConfig.h>
#include "BON.h"

#include <iostream>
#include <set>

#include "fco_utils.h"

namespace BON {

// Forward class declerations

class Option_Category_Impl;
class Flag_Option_Impl;
class Integer_Option_Impl;
class String_Option_Impl;
class Set_Option_Impl;
class Enum_Option_Impl;

class Set_Value_Impl;
class Enum_Value_Impl;

class Rule_Impl;
class Not_Logic_Impl;
class Or_Logic_Impl;
class Equal_Logic_Impl;

class Select_Conn_Impl;
class Range_Conn_Impl;
class Int_Eq_Conn_Impl;
class Str_Eq_Conn_Impl;
class Flag_Eq_Conn_Impl;
class Logic_Conn_Impl;
class Int_Val_Eq_Conn_Impl;
class Str_Val_Eq_Conn_Impl;
class Flag_Val_Eq_Conn_Impl;

// BON macros for defining extensions for new classes
// These classes matches the OCML metamodel

// TODO: When BON FCO extension support is fixed
//       Instead of declaring all the following classes
//       It will be enough to decleare their corresponding base class
//       which is "has_description".
DECLARE_BONEXTENSION(Model, Option_Category_Impl, Option_Category);

DECLARE_BONEXTENSION(Atom, Flag_Option_Impl, Flag_Option);
DECLARE_BONEXTENSION(Atom, Integer_Option_Impl, Integer_Option);
DECLARE_BONEXTENSION(Atom, String_Option_Impl, String_Option);
DECLARE_BONEXTENSION(Model, Set_Option_Impl, Set_Option);
DECLARE_BONEXTENSION(Model, Enum_Option_Impl, Enum_Option);

DECLARE_BONEXTENSION(Atom, Set_Value_Impl, Set_Value);
DECLARE_BONEXTENSION(Atom, Enum_Value_Impl, Enum_Value);

DECLARE_BONEXTENSION(Model, Rule_Impl, Rule);

DECLARE_BONEXTENSION(Atom, Not_Logic_Impl, Not_Logic);
DECLARE_BONEXTENSION(Atom, Or_Logic_Impl, Or_Logic);
DECLARE_BONEXTENSION(Atom, Equal_Logic_Impl, Equal_Logic);

DECLARE_BONEXTENSION(Connection, Select_Conn_Impl, Select_Conn);
DECLARE_BONEXTENSION(Connection, Range_Conn_Impl, Range_Conn);
DECLARE_BONEXTENSION(Connection, Int_Eq_Conn_Impl, Int_Eq_Conn);
DECLARE_BONEXTENSION(Connection, Str_Eq_Conn_Impl, Str_Eq_Conn);
DECLARE_BONEXTENSION(Connection, Flag_Eq_Conn_Impl, Flag_Eq_Conn);
DECLARE_BONEXTENSION(Connection, Logic_Conn_Impl, Logic_Conn);
DECLARE_BONEXTENSION(Connection, Int_Val_Eq_Conn_Impl, Int_Val_Eq_Conn);
DECLARE_BONEXTENSION(Connection, Str_Val_Eq_Conn_Impl, Str_Val_Eq_Conn);
DECLARE_BONEXTENSION(Connection, Flag_Val_Eq_Conn_Impl, Flag_Val_Eq_Conn);

/*
 *  Extension class definitions
 */

/*
 *  OCML BON-Extension classes
 *
 *  The descriptions of the methods below:
 *
 *  print_toc(): prints out html table of contents section
 *  print_html_body(): prints out html code
 *  print_init_body(): prints out C++ tree initialization code
 *  print_rule_body(): prints out C++ rule validation code
 */

class Option_Category_Impl: public ModelImpl {
public:
	void print_toc(std::ostream& os);

	void print_html_body(std::ostream& os, unsigned int indent_level = 1);
	void print_init_body(std::ostream& os);
};

class Flag_Option_Impl: public AtomImpl {
public:
	void print_rule_body(std::ostream& os);
	void print_init_body(std::ostream& os);
};

class Integer_Option_Impl: public AtomImpl {
public:
	void print_rule_body(std::ostream& os);
	void print_init_body(std::ostream& os);
};

class String_Option_Impl: public AtomImpl {
public:
	void print_rule_body(std::ostream& os);
	void print_init_body(std::ostream& os);
};

class Set_Option_Impl: public ModelImpl {
public:
	void print_rule_body(std::ostream& os);
	void print_init_body(std::ostream& os);
};

class Enum_Option_Impl: public ModelImpl {
public:
	void print_rule_body(std::ostream& os);
	void print_init_body(std::ostream& os);
};

class Set_Value_Impl: public AtomImpl {
public:
	void print_rule_body(std::ostream& os);
	void print_init_body(std::ostream& os);
};

class Enum_Value_Impl: public AtomImpl {
public:
	void print_rule_body(std::ostream& os);
	void print_init_body(std::ostream& os);
};

/*
 *  Rule paradigm extension implementations
 */

class Rule_Impl: public ModelImpl {
public:
	// adds given id into ignore_list_
	void add_ignore_list(std::string id);
	void print_rule_body(std::ostream& os);

private:
	// the fco's which has id's matched in the ignore list are not printed
	// in the ended list of rule's rule validation code
	std::set<std::string> ignore_list_;
};

class Not_Logic_Impl: public AtomImpl {
public:
	void print_rule_body(std::ostream& os);
};

class Or_Logic_Impl: public AtomImpl {
public:
	void print_rule_body(std::ostream& os);
};

class Equal_Logic_Impl: public AtomImpl {
public:
	void print_rule_body(std::ostream& os);
	// returns the pivot
	const std::string& pivot();

private:
	// pivot is one of the options connected to the "equal logic"
	// all the other options connected to the same "equal logic" is compared with pivot
	std::string pivot_;
};

class Select_Conn_Impl: public ConnectionImpl {
public:
	void print_rule_body(std::ostream& os);
};

class Range_Conn_Impl: public ConnectionImpl {
public:
	void print_rule_body(std::ostream& os);
};

class Int_Eq_Conn_Impl: public ConnectionImpl {
public:
	void print_rule_body(std::ostream& os);
};

class Str_Eq_Conn_Impl: public ConnectionImpl {
public:
	void print_rule_body(std::ostream& os);
};

class Flag_Eq_Conn_Impl: public ConnectionImpl {
public:
	void print_rule_body(std::ostream& os);
};

class Logic_Conn_Impl: public ConnectionImpl {
public:
	void print_rule_body(std::ostream& os);
};

class Int_Val_Eq_Conn_Impl: public ConnectionImpl {
public:
	void print_rule_body(std::ostream& os);
};

class Str_Val_Eq_Conn_Impl: public ConnectionImpl {
public:
	void print_rule_body(std::ostream& os);
};

class Flag_Val_Eq_Conn_Impl: public ConnectionImpl {
public:
	void print_rule_body(std::ostream& os);
};

}; // namespace BON

#endif // _OCML_BON_EXTENSION_H_
