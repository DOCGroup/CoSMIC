#ifndef IDL_UTIL_H
#define IDL_UTIL_H

#include "PICML.h"


class IDL_Util
{
public:
	static std::string component_name (PICML::TwowayOperation& op);
	static void return_type_signature (PICML::MemberType& mem_type,
									   std::string& operation_name,
									   int type);
	static std::string operation_name (PICML::TwowayOperation& op);
	static std::vector<std::string> argument_list (PICML::TwowayOperation& op);
	
};

#endif /* IDL_UTIL_H */