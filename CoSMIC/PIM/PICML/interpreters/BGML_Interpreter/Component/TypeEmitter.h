#ifndef TYPE_EMITTER_H
#define TYPE_EMITTER_H

#include <string>

class ReturnTypeEmitter 
{
public:
	static std::string generate_type_defn (std::string& kindName,
		std::string& scope_name);
};


class InTypeEmitter
{
public:
	static std::string generate_type_defn (std::string& kindName,
		std::string& scope_name);
};


class InoutTypeEmitter
{
public:
	static std::string generate_type_defn (std::string& kindName,
		std::string& scope_name);
};

class OutTypeEmitter
{
	
public:
	static std::string generate_type_defn (std::string& kindName,
		std::string& scope_name);
};


#endif // TYPE_EMITTER