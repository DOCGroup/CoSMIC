#include "OCML_BON_Extension.h"

#include "fco_utils.h"

namespace BON {

/*
 * BON macros for defining the implementations of the extensions for new classes
 */
IMPLEMENT_BONEXTENSION(Option_Category, "OptionCategory");

IMPLEMENT_BONEXTENSION(Flag_Option, "flag_option");
IMPLEMENT_BONEXTENSION(Integer_Option, "integer_option");
IMPLEMENT_BONEXTENSION(String_Option, "string_Ooption");
IMPLEMENT_BONEXTENSION(Set_Option, "set_option");
IMPLEMENT_BONEXTENSION(Enum_Option, "enum_option");

IMPLEMENT_BONEXTENSION(Set_Value, "set_value");
IMPLEMENT_BONEXTENSION(Enum_Value, "enum_value");

IMPLEMENT_BONEXTENSION(Rule, "Rule");

IMPLEMENT_BONEXTENSION(Not_Logic, "NOT");
IMPLEMENT_BONEXTENSION(Or_Logic, "OR");
IMPLEMENT_BONEXTENSION(Equal_Logic, "Equal");

IMPLEMENT_BONEXTENSION(Select_Conn, "SelectConnection");
IMPLEMENT_BONEXTENSION(Range_Conn, "Range_Connection");
IMPLEMENT_BONEXTENSION(Int_Eq_Conn, "IntEqConnection");
IMPLEMENT_BONEXTENSION(Str_Eq_Conn, "StrEqConnection");
IMPLEMENT_BONEXTENSION(Flag_Eq_Conn, "FlagEqConnection");
IMPLEMENT_BONEXTENSION(Logic_Conn, "LogicConnection");
IMPLEMENT_BONEXTENSION(Int_Val_Eq_Conn, "IntValEqConnection");
IMPLEMENT_BONEXTENSION(Str_Val_Eq_Conn, "StrValEqConnection");
IMPLEMENT_BONEXTENSION(Flag_Val_Eq_Conn, "FlagValEqConnection");

/*
 *  Methods
 */

/*
 *  Option Category extension class definitions
 */

void Option_Category_Impl::print_toc(std::ostream& os)
{
	// Make it a link
	os << "<A HREF=\"#" << getName() << "\">"
	   << title(this) << "</A>";

	// Write the contained Option Categories' ToC descriptions
	os << "<UL>";
	std::set<FCO> unsorted_children = getChildFCOsAs("OptionCategory");
	std::set<FCO, lt_fco> children(unsorted_children.begin(),
								   unsorted_children.end());
	for (std::set<FCO, lt_fco>::iterator iter = children.begin();
		 iter != children.end(); ++iter) {
		os << "<LI>";
		Option_Category(*iter)->print_toc(os);
		os << "</LI>";
	}
	os << "</UL>";
}

void Option_Category_Impl::print_html_body(std::ostream& os, unsigned int indent_level)
{
	// Write the title and it's own description
	os << "<A NAME=\"" << getName() << "\"/>"
	   << "<H" << indent_level << ">"
	   << title(this) << "</H" << indent_level << ">"
	   << description(this);

	// Write the contained options' descriptions
	{
		std::set<FCO, lt_fco> options;
		char* option_types[] = {
			"enum_option", "set_option", "flag_option", "integer_option", "string_option"
		};

		std::set<FCO> tmp_options;
		for (size_t i = 0; i < 5; ++i) {
			tmp_options = getChildFCOsAs(option_types[i]);
			options.insert(tmp_options.begin(), tmp_options.end());
		}

		if (options.size() != 0) {
			os << "<BLOCKQUOTE>"
			   << "<TABLE cellSpacing='2' cellPadding='0' border='2'>"
			   << "<TBODY>"
			   <<   "<TR>"
			   <<     "<TH> Option </TH>"
			   <<     "<TH> Description </TH>"
			   <<   "</TR>";

			for (std::set<FCO, lt_fco>::iterator iter = options.begin();
				 iter != options.end(); ++iter) {
				os << "<TR> <TD> <CODE>" << title(*iter) << "</CODE></TD>"
				   << "<TD>" << cpp_string(description(*iter)) << "</TD>";
			}

			os << "</TBODY>" << "</TABLE>" << "</BLOCKQUOTE>";
		}
	}

	// Write the contained Option Categories' descriptions
	{
		os << "<UL>";
		std::set<FCO> unsorted_children = getChildFCOsAs("OptionCategory");
		std::set<FCO, lt_fco> children(unsorted_children.begin(),
									   unsorted_children.end());
		for (std::set<FCO, lt_fco>::iterator iter = children.begin();
			 iter != children.end(); ++iter) {
			os << "<LI>";
			Option_Category(*iter)->print_html_body(os, indent_level+1);
			os << "</LI>";
		}
		os << "</UL>";
	}
}

void Option_Category_Impl::print_init_body(std::ostream& os)
{
	std::set<FCO> categories = getChildFCOsAs("OptionCategory");

	// Print out each category's initialization code - recursively
	for (std::set<FCO>::iterator iter1 = categories.begin();
		 iter1!= categories.end(); ++iter1)
			Option_Category(*iter1)->print_init_body(os);

	// Function header
	os << "Option_Category* initialize_category_" << getName() << "()\n"
	   << "{\n"
	   << "    Option_Category *category = new Option_Category(\"" 
	   << getName() << "\", \"" << cpp_string(description(this)) << "\");\n\n"
	   << "\n"
	   << "    Set_Option* set_option;\n"
	   << "    Enum_Option* enum_option;\n"
	   << "    String_Option* string_option;\n"
	   << "    Integer_Option* integer_option;\n"
	   << "    Flag_Option* flag_option;\n"
	   << "\n"
	   << "    // Here add contained categories\n";
	
	// Contained categories
	for (std::set<FCO>::iterator iter2 = categories.begin();
		 iter2!= categories.end(); ++iter2)
			os << "    category->push_back(initialize_category_" << Option_Category(*iter2)->getName() << "());\n";

	os << "    // Here add contained options\n";

	char* option_types[] = {
		"enum", "set", "flag", "integer", "string"
	};

	char* Option_Types[] = {
		"Enum", "Set", "Flag", "Integer", "String"
	};

	std::set<FCO> options;
	std::set<FCO> option_values;
	Model model_option;

	// Contained options
	for (size_t i = 0; i < 5; ++i) {
		options = getChildFCOsAs(std::string(option_types[i]) + "_option");
		for (std::set<FCO>::iterator iter = options.begin();
			 iter != options.end(); ++iter) {
			os << "    " << option_types[i] << "_option"
			   << " = new " << Option_Types[i] << "_Option("
			   << "\"" << (*iter)->getName() << "\", \""
			   << cpp_string(description(*iter)) << "\");"
			   << std::endl;

			// Add option values of model options
			if (Model(*iter)) {
				model_option = *iter;
				option_values = model_option->getChildFCOsAs(std::string(option_types[i])+"_value");
				for (std::set<FCO>::iterator value_iter = option_values.begin();
					 value_iter != option_values.end(); ++value_iter) {
					os << "    " << option_types[i] << "_option->push_back(new " << Option_Types[i] << "_Value("
					   << "\"" << (*iter)->getName() << "\", \""
					   << cpp_string(description(*iter)) << "\"));"
					   << std::endl;
				}
			}
			os << "    category->push_back(" << option_types[i] << "_option);" << std::endl;
		}
	}

	os << "    return category;\n"
	   << "}\n\n";
}

/*
 *  Rule paradigm extension implementations
 */

void Rule_Impl::add_ignore_list(std::string id)
{
	ignore_list_.insert(id);
}

void Rule_Impl::print_rule_body(std::ostream& os)
{
	// TODO: There is a problem with FCO::getChildFCOsAs() method implementation.
	// getChildFCOs() call in the line below should be replaced 
	// with getChildFCOsAs("BoxItem") when the problem is fixed.
	// ** see the comment below **
	std::set<FCO> children = getChildFCOs();
	for (std::set<FCO>::iterator iter = children.begin();
		 iter != children.end(); ++iter)
		// TODO: the first "if" below is not necessary when the BON problem
		// mentioned above is fixed
		if (Rule(*iter) || Not_Logic(*iter) || Or_Logic(*iter) || Equal_Logic(*iter))
		if (ignore_list_.find((*iter)->getID()) == ignore_list_.end())
			os << "    " << get_func_name((*iter)->getID())
			   << "(root) &&" << std::endl;

	os << "    true;" << std::endl;
}

void Not_Logic_Impl::print_rule_body(std::ostream& os)
{
	// print !connection_function()
	std::set<Connection> conn = getInConnLinks();
	os << "  !" << get_func_name((*(conn.begin()))->getID())
	   << "(root);" << std::endl;
}

void Or_Logic_Impl::print_rule_body(std::ostream& os)
{
	// print conn_func1() || conn_func2() || ...
	std::set<Connection> conns = getInConnLinks();
	for (std::set<Connection>::iterator iter = conns.begin();
		 iter != conns.end(); ++iter)
		os << "    " << get_func_name((*iter)->getID())
		   << "(root) ||" << std::endl;

	 os << "    false;" << std::endl;
}

void Equal_Logic_Impl::print_rule_body(std::ostream& os)
{
	// print check_val_eq(opt1, opt2) && check_val_eq(opt1, opt3) && ...
	std::set<Connection> conns = getInConnLinks();
	FCO fco = get_ref((*conns.begin())->getSrc());

	pivot_ = std::string("(Option*)&((Tree_Node&)(root)") + option_path(fco) + std::string(")");

	for (std::set<Connection>::iterator iter = conns.begin();
		 iter != conns.end(); ++iter)
		os << "    " << get_func_name((*iter)->getID())
		   << "(root) &&" << std::endl;

	os << "    true;" << std::endl;
}

const std::string& Equal_Logic_Impl::pivot()
{
	return pivot_;
}

void Select_Conn_Impl::print_rule_body(std::ostream& os)
{
	// prints the call to check_selected(option)
	os << "    check_selected((Option*)&((Tree_Node&)(root)" << option_path(get_ref(getSrc())) << "));" << std::endl;
}

void Range_Conn_Impl::print_rule_body(std::ostream& os)
{
	// prints the call to check_range(integer_option, min, max)
	os << "    check_range((Option*)&((Tree_Node&)(root)" << option_path(get_ref(getSrc())) << "), "
	   << getAttribute("min") << ", " << getAttribute("max")
	   << ");" << std::endl;
}

void Int_Eq_Conn_Impl::print_rule_body(std::ostream& os)
{
	// prints the call to check_int_eq(integer_option, int)
	os << "    check_int_eq((Integer_Option*)&((Tree_Node&)(root)" << option_path(get_ref(getSrc())) << "), "
	   << getAttribute("EqualityIntAttribute")->getIntegerValue()
	   << ");" << std::endl;
}

void Str_Eq_Conn_Impl::print_rule_body(std::ostream& os)
{
	// prints the call to check_str_eq(string_option, const char*)
	os << "    check_str_eq((String_Option*)&((Tree_Node&)(root)" << option_path(get_ref(getSrc())) << "), "
	   << "\"" << getAttribute("EqualityStrAttribute")->getStringValue() << "\""
	   << ");" << std::endl;
}

void Flag_Eq_Conn_Impl::print_rule_body(std::ostream& os)
{
	// prints the call to "check_flag_eq(flag_option, bool)
	os << "    check_flag_eq((Flag_Option*)&((Tree_Node&)(root)" << option_path(get_ref(getSrc())) << "), "
	   << (getAttribute("EqualityBooleanAttribute")->getBooleanValue() ? "true" : "false")
	   << ");" << std::endl;
}

void Logic_Conn_Impl::print_rule_body(std::ostream& os)
{
	// First adds the source option to the contained rule's ignore list
	// to not to include it twice (at both connection function and rule's and list
	FCO src = FCO(getSrc());
	Rule(getParent())->add_ignore_list(src->getID());
	// prints the call to the connection rule validation function
	os << get_func_name(src) << "(root);" << std::endl;
}

void Int_Val_Eq_Conn_Impl::print_rule_body(std::ostream& os)
{
	// prints the call to check_int_val_eq(integer_option1 /*pivot*/, integer_option2)
	os << "    check_int_val_eq((Integer_Option*)&((Tree_Node&)(root)" << option_path(get_ref(getSrc())) << "), "
	   << "(Integer_Option*)" << Equal_Logic(getDst())->pivot() << ");" << std::endl;
}

void Str_Val_Eq_Conn_Impl::print_rule_body(std::ostream& os)
{
	// prints the call to check_str_val_eq(string_option1 /*pivot*/, string_option2)
	os << "    check_str_val_eq((String_Option*)&((Tree_Node&)(root)" << option_path(get_ref(getSrc())) << "), "
	   << "(String_Option*)" << Equal_Logic(getDst())->pivot() << ");" << std::endl;
}

void Flag_Val_Eq_Conn_Impl::print_rule_body(std::ostream& os)
{
	// prints the call to check_flag_val_eq(flag_option1 /*pivot*/, flag_option2)
	os << "    check_flag_val_eq((Flag_Option*)&((Tree_Node&)(root)" << option_path(get_ref(getSrc())) << "), "
	   << "(Flag_Option*)" << Equal_Logic(getDst())->pivot() << ");" << std::endl;
}

}; // namespace BON
