#ifndef _GLOBAL_DATA_H
#define _GLOBAL_DATA_H

#include <vector>
#include <string>

struct BGML_Task_Data
{
	__int64 task_rate;
	__int64 task_priority;
	__int64 number_of_tasks;

};

struct BGML_Data
{
	__int64 benchmark_priority;
	__int64 benchmark_rate;
	// Benchmarking Rate and priority 
	// for the tasks
	
	std::vector<BGML_Task_Data> task_group_data;
	/// Task information, their rates, 
	/// priorities and number of tasks
	
	std::string file_name;
	// A File to dump data to
	
	__int64 warmup_iterations;
	// Number of warmup iterations
	
	__int64 benchmark_iterations;
	// Number of actual benchmarking iterations
	// required

	std::string output_path;
	// Directory path were the generated data should
	// be written out
};

// Struct Definition
static BGML_Data bgml_state;

#endif /* _GLOBAL_DATA_H */
