#ifndef METRIC_EMITTER_H
#define METRIC_EMITTER_H

#include "PICML.h"

#include <string>
#include <vector>

#include "Global_Data.h"

template <class T>
class MetricEmitter 
{
public:
	MetricEmitter (PICML::OperationRef &base, 
				   T& latency,
			       std::string& metric,
				   BGML_Data &state);
	~MetricEmitter ();
	
	void generate_benchmark ();

	std::string component_name (PICML::TwowayOperation& op);

	void return_type_signature (PICML::MemberType& mem_type,
								std::string& operation_name,
								int type);

	std::string operation_signature (PICML::TwowayOperation& op);

protected:
	void generate_header_file (std::string& class_name,
							   std::string& component_name,
							   std::string& operation_name,
							   std::vector<string>& arg_list,
							   std::string &path);
	// Generate the header file information

	void create_build_file (std::vector<std::string>& file_list, 
							std::string& project_name,
							std::string& dependancy_list);
	// Generate the build file building benchmarking library
	
private:
	PICML::OperationRef &operation_ref_;
	T& latency_;
	std::string& metric_;
	BGML_Data &bgml_state_;
		
};

#include "MetricEmitter.cpp"

#endif /* LATENCY_EMITTER_H */