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
								 std::string& metric)
: operation_ (base), 
  latency_ (latency), 
  output_path_ (output_path),
  task_priorities_ (task_priorities),
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
								  this->task_priorities_);
	bench_stream.generate_task_header (class_name);
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
	
	//// Generate the Header file /////////////////////////////////
	std::string class_name = "Benchmark_" + operation_name;
	this->generate_header_file (class_name, component_name, operation_name, arg_list);
	if (this->task_priorities_.size ())
	{
		class_name = operation_name + "_Workload";
		this->generate_header_file (class_name, component_name, operation_name, arg_list);
	}
	

	///// Generate .cpp file for the task ///////////////////////////
	std::string cpp_file = this->output_path_ + "\\" + "Benchmark_" + operation_name + ".cpp";
	std::string workload_cpp_file = this->output_path_ + "\\" + operation_name + "_Workload.cpp";

	std::ofstream cpp_stream (cpp_file.c_str (), ios::out);
	std::ofstream workload_stream (workload_cpp_file.c_str (), ios::out);
	
	BenchmarkStream bench_cpp_stream (component_name, 
									  operation_name, 
									  arg_list,
									  cpp_stream,
									  this->task_priorities_);
	
	bench_cpp_stream.generate_task_def (warmup, 
										iterations, 
										file_name,
										this->metric_);

	BenchmarkStream workload_cpp_stream (component_name, 
										 operation_name, 
										 arg_list,
										 workload_stream,
										 this->task_priorities_);

	workload_cpp_stream.generate_workload_def (iterations);

	////////////////////////////////////////////////////////////////////////
}

#endif // METRIC_EMITTER_C