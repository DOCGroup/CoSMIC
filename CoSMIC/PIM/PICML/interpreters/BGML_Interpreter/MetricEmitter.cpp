#ifndef METRIC_EMITTER_C
#define METRIC_EMITTER_C

#include <fstream>

#include "MetricEmitter.h"
#include "IDL_Util.h"
#include "Benchmark_Stream.h"

template <class T>
MetricEmitter<T>::MetricEmitter (PICML::OperationBase &base, 
								 T& latency,
								 std::string& output_path,
								 std::vector<__int64>& task_priorities,
								 std::vector<__int64>& task_rates,
								 std::string& metric)
: operation_ (base), 
  latency_ (latency), 
  output_path_ (output_path),
  task_priorities_ (task_priorities),
  task_rates_ (task_rates),
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
										std::vector<string>& arg_list)
{
	std::string output_file = this->output_path_ + "\\" + class_name + ".h";
	std::ofstream output_stream (output_file.c_str (), ios::out);
	BenchmarkStream bench_stream (component_name, 
								  operation_name, 
								  arg_list,
								  output_stream,
								  this->task_priorities_,
								  this->task_rates_,
								  this->output_path_);
	bench_stream.generate_task_header (class_name);
}

template <class T>
void
MetricEmitter<T>::create_build_file (std::vector<std::string>& file_list, 
									 std::string& project_name)
{
	// Open the build stream
	std::string build_file = this->output_path_ + "\\" + project_name + ".mpc";
	std::ofstream build_stream (build_file.c_str (), ios::out);
	
	// Create project
	build_stream << "project (";
	build_stream << project_name << ") : acelib, ciao_client {";
	build_stream << "\n";
	
	// Create include definition and libs+
	build_stream << "  includes += $(BGML_HOME) \n";
	build_stream << "  libs     += BGML_Base \n";
	build_stream << "  libpaths += $(BGML_HOME) \n";
	
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
	__int64 warmup = latency_.warmup(); 
	std::string file_name = latency_.fileName(); 
	__int64 iterations = latency_.iterations ();
	
	// Use the operation Name to get the name of the Component
	// This is necessary to get the signature of the remote operation
	
	// PART 1: Obtaing Component Name
	PICML::TwowayOperation twoway_op = PICML::TwowayOperation::Cast (operation_);
	
	std::string& component_name = IDL_Util::component_name (twoway_op);
	std::string& operation_name = IDL_Util::operation_name (twoway_op);
	std::vector<std::string>& arg_list = IDL_Util::argument_list (twoway_op);

	//// Generate the Benchmarking Header
	std::string class_name = "Benchmark_" + operation_name;
	this->generate_header_file (class_name, component_name, operation_name, arg_list);

	std::vector<std::string> source_file_list;
	if (this->task_priorities_.size ())
	{
		class_name = operation_name + "_Workload";

		// Add a barrier to the list of arguments
		std::vector<std::string> temp_list (arg_list);
		temp_list.push_back ("ACE_Barrier&");
		this->generate_header_file (class_name, component_name, operation_name, temp_list);

		std::string workload_cpp_file = 
			this->output_path_ + "\\" + operation_name + "_Workload.cpp";
		source_file_list.push_back (operation_name + "_Workload.cpp");

		std::ofstream workload_stream (workload_cpp_file.c_str (), ios::out);
		BenchmarkStream workload_cpp_stream (component_name, 
											 operation_name, 
											 temp_list,
											 workload_stream,
											 this->task_priorities_,
											 this->task_rates_,
											 this->output_path_);

		workload_cpp_stream.generate_workload_def (iterations);
		
	}
	

	///// Generate .cpp file for the task ///////////////////////////
	std::string cpp_file = this->output_path_ + "\\" + "Benchmark_" + operation_name + ".cpp";
	source_file_list.push_back ("Benchmark_" + operation_name + ".cpp");

	std::ofstream cpp_stream (cpp_file.c_str (), ios::out);
	BenchmarkStream bench_cpp_stream (component_name, 
									  operation_name, 
									  arg_list,
									  cpp_stream,
									  this->task_priorities_,
									  this->task_rates_,
									  this->output_path_);
	
	bench_cpp_stream.generate_task_def (warmup, 
										iterations, 
										file_name,
										this->metric_);

	// Create the mpc file for building the benchmarks
	std::string project_name = "Benchmark_" + operation_name;
	this->create_build_file (source_file_list, project_name);
}

#endif // METRIC_EMITTER_C