#ifndef METRIC_EMITTER_C
#define METRIC_EMITTER_C

#include <fstream>
#include "ctype.h"

#include "MetricEmitter.h"
#include "IDL_Util.h"
#include "Benchmark_Stream.h"
#include <algorithm>
#include "Global_Data.h"

template <class T>
MetricEmitter<T>::MetricEmitter (PICML::OperationBase &base, 
								 T& latency,
								 std::string& metric)
: operation_ (base), 
  latency_ (latency), 
  metric_ (metric)
{
	
}


template <class T>
MetricEmitter<T>::~MetricEmitter ()
{	
	
}

template<class T>
void 
MetricEmitter<T>::generate_header_file (std::string& class_name,
										std::string& component_name,
										std::string& operation_name,
										std::vector<string>& arg_list, 
										std::string &path)
{
	std::string output_file = bgml_state.output_path + "\\" + class_name + ".h";
	std::ofstream output_stream (output_file.c_str (), ios::out);
	BenchmarkStream bench_stream (component_name, 
								  operation_name, 
								  arg_list,
								  output_stream);
	bench_stream.generate_task_header (class_name, path);
}

template <class T>
void
MetricEmitter<T>::create_build_file (std::vector<std::string>& file_list, 
									 std::string& project_name, 
									 std::string& dependant_list)
{
	// Open the build stream
	std::string build_file = bgml_state.output_path + "\\" + project_name + ".mpc";
	std::ofstream build_stream (build_file.c_str (), ios::out);
	
	// Create project
	build_stream << "project (";
	build_stream << project_name << ") : acelib, ciao_component_dnc {";
	build_stream << "\n";
	
	// Create include definition and libs+
	std::string home_include = "\"$(BGML_HOME)\"";
	build_stream << "  includes += "
				 << home_include.c_str () 
				 << " \n";
	build_stream << "  libs     += BGML_Base ";
	build_stream << dependant_list.c_str ();
	build_stream << "\n  dynamicflags = ";

	std::transform (project_name.begin(), 
				    project_name.end(), 
					ostream_iterator <char> (build_stream), 
					toupper);
	build_stream << "\n";
	
	// Add the Benchmarking Source files
	build_stream << "  Source_Files { \n";
	for (size_t i = 0; i < file_list.size (); i++)
	{
		build_stream << "    ";
		build_stream << file_list [i];
		build_stream << "\n";
	}

	build_stream << "  }\n";
	build_stream << "}\n";
	
	// Close the file
	build_stream.close ();
}


template <class T>
void
MetricEmitter<T>::generate_benchmark ()
{
	// First obtain the file_name, warmup and iterations
	bgml_state.warmup_iterations = latency_.warmup(); 
	bgml_state.file_name = latency_.fileName(); 
	bgml_state.benchmark_iterations = latency_.iterations ();
	
	// Use the operation Name to get the name of the Component
	// This is necessary to get the signature of the remote operation
	
	// PART 1: Obtaing Component Name
	PICML::TwowayOperation twoway_op = PICML::TwowayOperation::Cast (operation_);
	
	std::string& component_name = IDL_Util::component_name (twoway_op);
	std::string& operation_name = IDL_Util::operation_name (twoway_op);
	std::vector<std::string>& arg_list = IDL_Util::argument_list (twoway_op);

	//// Generate the Benchmarking Header
	std::string class_name = "Benchmark_" + operation_name;
	this->generate_header_file (class_name, 
								component_name, 
								operation_name, 
								arg_list,
								bgml_state.output_path);


	//@@ When we have more than one task group associated, we will need to change
	// this code to make it more generalizable
	std::vector<std::string> source_file_list;
	
	for (size_t i =0; i < bgml_state.task_group_data.size (); i++)
	{
		class_name = operation_name + "_Workload";

		// Add a barrier to the list of arguments
		std::vector<std::string> temp_list (arg_list);
		temp_list.push_back ("ACE_Barrier&");
		std::string dummy;
		this->generate_header_file (class_name, 
									component_name, 
									operation_name, 
									temp_list, 
									dummy);

		std::string workload_cpp_file = 
			bgml_state.output_path + "\\" + operation_name + "_Workload.cpp";
		source_file_list.push_back (operation_name + "_Workload.cpp");

		std::ofstream workload_stream (workload_cpp_file.c_str (), ios::out);
		BenchmarkStream workload_cpp_stream (component_name, 
											 operation_name, 
											 temp_list,
											 workload_stream);

		workload_cpp_stream.generate_workload_def (bgml_state.benchmark_iterations,
												   bgml_state.task_group_data[i]);

	}

	///// Generate .cpp file for the task ///////////////////////////
	std::string cpp_file = bgml_state.output_path + "\\" + "Benchmark_" + operation_name + ".cpp";
	source_file_list.push_back ("Benchmark_" + operation_name + ".cpp");

	std::ofstream cpp_stream (cpp_file.c_str (), ios::out);

	bgml_state.benchmark_rate = (bgml_state.benchmark_rate <= 0) ? -1 : bgml_state.benchmark_rate;
	bgml_state.benchmark_priority = (bgml_state.benchmark_priority < 0) ? -1 : bgml_state.benchmark_priority;

	BenchmarkStream bench_cpp_stream (component_name, 
									  operation_name, 
									  arg_list,
									  cpp_stream);
	
	bench_cpp_stream.generate_task_def (this->metric_);

	// Create the mpc file for building the benchmarks
	std::string project_name = "Benchmark_" + operation_name;
	std::string dependant_libs = IDL_Util::dependant_idls (twoway_op);

	this->create_build_file (source_file_list, project_name, dependant_libs);
}

#endif // METRIC_EMITTER_C