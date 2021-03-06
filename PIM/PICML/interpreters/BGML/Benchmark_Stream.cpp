#include "BGML/Benchmark_Stream.h"
#include <ctype.h>
#include "BGML/Global_Data.h"
#include "BGML/IDL_Util.h"
#include "Uml.h"
#include <algorithm>

NL::NL (void)
{
}

INDENT::INDENT (int do_now)
:  do_now_ (do_now)
{
}

UNINDENT::UNINDENT (int do_now)
:  do_now_ (do_now)
{
}

const NL nl;
const INDENT idt;
const INDENT idt_nl (1);
const UNINDENT uidt;
const UNINDENT uidt_nl (1);

BenchmarkStream::BenchmarkStream (std::string& component_name,
								  std::string& operation_name,
								  std::vector<std::string>& arg_list,
								  std::ostream& strm,
								  BGML_Data &state)

: component_name_ (component_name),
  operation_name_ (operation_name),
  arg_list_ (arg_list),
  strm_ (strm),
  bgml_state_ (state),
  indent_level_ (0)
{

}

BenchmarkStream::~BenchmarkStream (void)
{
}

void
BenchmarkStream::incr_indent (unsigned short flag)
{
	++indent_level_;
}

// Indentation
void
BenchmarkStream::decr_indent (unsigned short flag)
{
	if (this->indent_level_ > 0)
    {
		--this->indent_level_;
    }
}

void
BenchmarkStream::reset (void)
{
	this->indent_level_ = 0;
}

// Indented print.
void
BenchmarkStream::indent (void)
{
	// Based on the current indentation level, leave appropriate number of blank
	// spaces in the output.
	if (this->indent_level_ > 0)
    {
		for (int i = 0; i < this->indent_level_; ++i)
        {
			this->strm_ << "  ";
        }
    }
}

void
BenchmarkStream::gen_include_file (std::string& file_name)
{
	this->strm_ << "#include ";
	this->strm_ << "\"";
	this->strm_ << file_name.c_str ();
	this->strm_ << "\"";
	this->nl ();
}


void
BenchmarkStream::gen_constructor_decl (std::string& name)
{
	this->incr_indent ();
	this->indent ();
	this->strm_ << name.c_str ();
	this->strm_ << " (T* remote_ref";
	if (this->arg_list_.size ())
		for (size_t i=0; i < this->arg_list_.size (); i++)
		{
			this->strm_ << ", ";
			this->strm_ << this->arg_list_[i];
			this->strm_ << " ";
			this->strm_ << "arg";
			this->strm_ << i;
		}
		this->strm_ << ");";
		this->nl ();
		this->decr_indent ();
}

void
BenchmarkStream::gen_destructor_decl (std::string& name)
{
	this->incr_indent ();
	this->indent ();
	this->strm_ << "~";
	this->strm_ << name.c_str ();
	this->strm_ << " ();";
	this->nl ();
	this->decr_indent ();
}

void
BenchmarkStream::gen_private_mem_decl (bool is_main)
{
	this->nl ();
	this->strm_ << "protected:";
	this->nl ();
	this->incr_indent ();
	this->indent ();
	this->strm_ << "T* remote_ref_;";
	this->nl ();

	for (size_t i = 0; i < this->arg_list_.size (); i++)
	{
		this->indent ();
		this->strm_ << this->arg_list_ [i];
		this->strm_ << " ";
		this->strm_ << "arg";
		this->strm_ << i << "_;";
		this->nl ();
	}

	/// If this is the main task add the interface to fetch data
	if (is_main)
	{
		this->indent ();
		this->strm_ << "BGML_Data benchmark_data_;";
		this->nl ();
	}

	this->decr_indent ();
}

void
BenchmarkStream::generate_tool_description ()
{
this->strm_ << "// -*- C++ -*-\n";
this->strm_ << "// ****  Code generated by the Benchmark Generation Modeling Language (BGML) Interpreter  ****\n";

this->strm_ << "// Benchmark Generation Modeling Language (BGML)\n";
this->strm_ << "// has been developed by \n";
this->strm_ << "//       Institute for Software Integrated Systems \n";
this->strm_ << "//       Vanderbilt University\n";
this->strm_ << "//       Nashville, TN\n";
this->strm_ << "//       USA\n";
this->strm_ << "//       http://www.isis.vanderbilt.edu/ \n";
this->strm_ << "//\n";
this->strm_ << "// Information about BGML is available from:\n";
this->strm_ << "//     http://www.dre.vanderbilt.edu/cosmic\n";
}

void
BenchmarkStream::gen_run_method (std::string &name)
{
	this->indent ();
	this->strm_ << "template <class T> void \n";

	this->indent ();
	this->strm_ << name << ":: run (";
	this->strm_ << " (T* remote_ref";

	if (this->arg_list_.size ())
		for (size_t i=0; i < this->arg_list_.size (); i++)
		{
			this->strm_ << ", ";
			this->strm_ << this->arg_list_[i];
			this->strm_ << " ";
			this->strm_ << "arg";
			this->strm_ << i;
		}
	this->strm_ << ")\n";

	this->indent ();
	this->strm_ << "{\n";

	this->incr_indent ();
	this->indent ();

	/// Check what type of benchmark
	if (this->bgml_state_.benchmark_type != Udm::null)
	{
		std::string bench_kind = this->bgml_state_.benchmark_type.type().name();
		if (bench_kind == "FixedIterationBenchmarks")
		{

		}
		else if (bench_kind == "PeriodicBenchmarks")
		{

		}
	}

	/// Default case same as "Trigger Benchmarks"


}

void
BenchmarkStream::generate_task_header (std::string& header_name,
									   bool is_main_class)
{
	// Generate the tool description
	this->generate_tool_description ();

	///// Generate the #ifdef macros
	this->gen_ifdef_macro (header_name);

	///// Step 2 generate the include files necessary
	std::string base_task = "BGML_Task_Base.h";
	std::string component_exec_header = this->component_name_ + "_exec.h";
	this->nl ();

	this->gen_include_file (base_task);
	this->gen_include_file (component_exec_header);

	/* ------- NEED NOT GENERATE THE EXPORT INFORMATION FOR NOW
	/// Generate the export files for benchmarking
	if (output_path.size ())
		this->create_export_macro (header_name, output_path);

	std::string export_header_name =  "Benchmark_" + this->operation_name_ + "_export.h";
	this->gen_include_file (export_header_name);
	*/

	/// Check for ACE_Barrier in the list
	if (std::find (this->arg_list_.begin (), this->arg_list_.end (), "ACE_Barrier&") !=
		this->arg_list_.end ())
	{
		std::string barrier_include = "ace/Barrier.h";
		this->gen_include_file (barrier_include);
	}

	this->nl ();

	// Step 3: Generate the "class" definition
	this->strm_ << "template <typename T>";
	this->nl ();
	this->strm_ << "class ";

	/* ----- NEED NOT GENERATE THE EXPORT MACRO FOR NOW
	// Generate the export macro for the workload generation
	this->strm_ << "BENCHMARK_";
	this->upcase (this->operation_name_.c_str ());
	this->strm_ << "_Export ";
	*/

	this->strm_ << header_name.c_str ();
	this->strm_ << " : public BGML_Task_Base";
	this->nl ();
	this->strm_ << "{";
	this->nl ();
	this->strm_ << "public:";
	this->nl ();

	//// Step 4: Write out the constructor/Destructor for the tasks
	this->gen_constructor_decl (header_name);
	this->gen_destructor_decl  (header_name);

	/// Step 5: Add the static run method
	this->incr_indent ();
	this->nl ();
	this->indent ();
	this->strm_ << "// Static entry point for benchmarking \n";
	this->indent ();
	this->strm_ << "int static run (T* remote_ref";
	if (this->arg_list_.size ())
		for (size_t i=0; i < this->arg_list_.size (); i++)
		{
			this->strm_ << ", ";
			this->strm_ << this->arg_list_[i];
			this->strm_ << " ";
			this->strm_ << "arg";
			this->strm_ << i;
		}
	this->strm_ << ");";
	this->nl ();
	this->decr_indent ();

	//// Step 5: Write out the hook svc method for ACE_Task_Base
	this->incr_indent ();
	this->nl ();
	this->indent ();
	this->strm_ << "int svc (void);";

	// If main task generate the get_stats operation
	if (is_main_class)
	{
		this->nl ();
		this->indent ();
		this->strm_ << "// Interface to fetch data from benchmarks \n";
		this->indent ();
		this->strm_ << "BGML_Data& get_stats (void);";
	}

	this->decr_indent ();
	this->nl ();

	//// Step 6: Write out the private members
	this->gen_private_mem_decl (is_main_class);

	/// Step 7: Write out the close the class
	this->nl ();
	this->strm_ << "};";
	this->nl ();

	/// Step 8: Include the template
	this->nl ();
	this->strm_ << "#include ";
	this->strm_ << "\"";
	this->strm_ << header_name.c_str ();
	this->strm_ << ".cpp\"";

	//// Step 9: Close the header file
	this->gen_endif (header_name.c_str ());
}


void
BenchmarkStream::create_export_macro (std::string& shared_name,
									  std::string& output_path)
{
	// Generate the stub export file name as well
	std::string command = "generate_export_file.pl -s ";

	// Convert the export to upper case
	const char* str = shared_name.c_str ();
	int i = 0;
	char c;

	while ((c = str[i++]) != '\0')
    {
		command += toupper (c);
    }

	// Redirect to required file
	command.append (" > ");

	// The output path should be within quotes otherwise it is going to crib if
	// the output directory has spaces in it somewhere
	command.append ("\"");
	command.append (output_path);
	command.append ("\"");

	command.append ("\\");
	command.append (shared_name);
	command.append ("_export.h");
	command.append (" 2>&1");
	system (command.c_str ());
}

void
BenchmarkStream::gen_template_function_def (const std::string& name,
											const std::string& class_name,
											const std::string& return_type,
											const std::vector<std::string>& param_list)
{

	this->strm_ << "template <typename T>\n";
	this->strm_ << return_type;
	this->nl ();
	this->strm_ << class_name;
	this->strm_ << "<T>::";
	this->strm_ << name;
	this->strm_ << " (";
	if (param_list.size ())
	{
		for (size_t i = 0; i < param_list.size (); i++)
		{
			if (i)
				this->strm_ << ", ";

			this->strm_ << param_list [i];
			this->strm_ << " ";
			this->strm_ << "arg";
			this->strm_ << i;
		}
	}
	else
		this->strm_ << "void";

	this->strm_ << ")\n";

	this->strm_ << "{\n";

}

void
BenchmarkStream::gen_warmup_iterations (__int64 iterations,
										__int64 benchmark_priority)
{
	this->incr_indent ();
	this->nl ();

	// check for priority if so set the proper priority
	if (benchmark_priority != -1)
	{
		this->indent ();
		this->strm_ << "// Set right priority for this thread \n";
		this->indent ();
		this->strm_ << "this->set_priority (";
		this->strm_ << (int) benchmark_priority;
		this->strm_ << ");\n";
	}

	this->nl ();
	this->indent ();
	this->strm_ << "// Warm up the system before benchmark generation \n";
	this->indent ();
	this->strm_ << "for (int warm_up = 0; warm_up < ";
	if (iterations)
		this->strm_ << (int) iterations;
	else
		this->strm_ << BGML_DEFAULT_WARMUP_ITER;
	this->strm_ << "; warm_up++)\n";
	this->incr_indent ();
	this->indent ();

	// Generate the operation signature to invoke
	this->strm_ << "(void) this->remote_ref_->";
	this->strm_ << this->operation_name_;
	this->strm_ << " (";

	for (size_t i =0; i < this->arg_list_.size (); i++)
	{
		if (i)
			this->strm_ << ",";
		this->strm_ << "arg" << i << "_";
	}
	this->strm_ << " ACE_ENV_ARG_PARAMETER";
	this->strm_ << ");";
	this->decr_indent ();
	this->nl ();
}

void
BenchmarkStream::gen_bench_def (__int64 iterations)
{
   this->indent ();
   this->strm_ << "ACE_Sample_History history (";
   __int64 iter = (iterations) ? iterations : BGML_DEFAULT_BENCH_ITER;
   this->strm_ << (int) iter;
   this->strm_ << ");";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_UINT32 gsf = ACE_High_Res_Timer::global_scale_factor ();";
   this->nl ();

   // Check if the tasks have to perform benchmarking at a given rate
   if (this->bgml_state_.benchmark_rate != -1)
   {
	   this->indent ();
	   this->strm_ << "ACE_hrtime_t deadline_for_call = 0;\n";
	   this->indent ();
	   this->strm_ << "ACE_hrtime_t interval_between_calls = 1/double ("
				   << (int) this->bgml_state_.benchmark_rate
				   << ") * gsf * ACE_HR_SCALE_CONVERSION; \n";
   }

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_hrtime_t test_start = ACE_OS::gethrtime ();\n";

   this->indent ();
   this->strm_ << "for (int i = 0; ";
   this->strm_ << "i < ";
   this->strm_ << (long) iter;
   this->strm_ << "; i++)\n";

   this->indent ();
   this->strm_ << "{\n";

   this->incr_indent ();
   this->indent ();
   this->strm_ << "ACE_hrtime_t start = ACE_OS::gethrtime ();\n";


   // Check for rate based events
   if (this->bgml_state_.benchmark_rate != -1)
   {
	  this->nl ();
	  this->indent ();
	  this->strm_ << "deadline_for_call = interval_between_calls * (i + 1);\n";
	  this->indent ();
	  this->strm_ << "deadline_for_call += test_start; \n";
   }

   /// Cast the operation return-type as a (void)
   this->indent ();
   this->strm_ << "(void)this->remote_ref_->";
   this->strm_ << this->operation_name_;
   this->strm_ << " (";

   for (size_t i =0; i < this->arg_list_.size (); i++)
	{
		if (i)
			this->strm_ << ",";
		this->strm_ << "arg" << i << "_";
	}

   this->strm_ << " ACE_ENV_ARG_PARAMETER";
   this->strm_ << ");\n";

   this->indent ();
   this->strm_ << "ACE_CHECK;";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_hrtime_t now = ACE_OS::gethrtime ();\n";

   this->nl ();
   this->indent ();
   this->strm_ << "history.sample (now - start);";

   // Check if this is a rate based invocation
   if (this->bgml_state_.benchmark_rate != -1)
   {
		this->nl ();
		this->indent ();
		this->strm_ << "if (now < deadline_for_call)\n";
		this->indent ();
		this->strm_ << "{\n";
		this->incr_indent ();
		this->indent ();
		this->strm_ << "ACE_hrtime_t sleep_time = deadline_for_call - now;\n";
		this->indent ();
		this->strm_ << "ACE_OS::sleep (ACE_Time_Value (0, long (to_seconds (sleep_time, gsf) * ACE_ONE_SECOND_IN_USECS)));\n";
		this->decr_indent ();
		this->indent ();
		this->strm_ << "}";
   }

   this->nl ();
   this->decr_indent ();
   this->indent ();
   this->strm_ << "}\n";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_hrtime_t test_end = ACE_OS::gethrtime ();";
   this->nl ();

   // If there were workloads asociated , then wait for them to finish
   if (this->bgml_state_.task_group_data.size ())
   {
	   this->nl ();
	   this->indent ();
	   this->strm_ << "// Wait for tasks to finish\n";
   }

   __int64 total_task_counter = 0; // Count of total number of tasks

   for (__int64 counter = 0;
		counter < this->bgml_state_.task_group_data.size ();
		counter++)
   {
	 for (size_t inner_counter = 0;
	       inner_counter < this->bgml_state_.task_group_data[ (int) counter].size;
		   inner_counter ++)
		 {
			this->indent ();
			this->strm_ << "task"
				     	<< (int) total_task_counter ++
				        << ".wait ();";
			this->nl ();
		  }
   }

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_DEBUG ((LM_DEBUG, \"test finished \\n\"));";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_DEBUG ((LM_DEBUG, \"High resolution timer calibration.... \"));";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_DEBUG ((LM_DEBUG, \"done \\n\"));";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_Basic_Stats stats;";

   this->nl ();
   this->indent ();
   this->strm_ << "history.collect_basic_stats (stats);";
   this->nl ();
   this->nl ();

   /// Find the resolution of the individual samples
   if (this->bgml_state_.resolution == "miliseconds")
   {
	   this->indent ();
	   this->strm_ << "// Converting to milisecond resolution";
	   this->nl ();
	   this->indent ();
	   this->strm_ << "gsf *= 1000;";
	   this->nl ();
   }
   else if (this->bgml_state_.resolution == "seconds")
   {
	   this->indent ();
	   this->strm_ << "// Converting to seconds resolution \n";
	   this->nl ();
	   this->strm_ << "gsf *= 1000000;";
	   this->nl ();
   }

   /// Check if we need to dump the data out to a file
   if (this->bgml_state_.file_name.size ())
   {
	   this->nl ();
	   this->indent ();

	   // Dump samples to the file
	   this->strm_ << "FILE *output_file= ACE_OS::fopen ("
		   << "\""
		   << this->bgml_state_.file_name
		   << "\""
		   << ", \"w\");\n";

	   this->indent ();
	   this->strm_ << "// Iterate on the Samples and print them to a file";
	   this->nl ();
	   this->indent ();

	   this->strm_ << "for (size_t j =0; j < "
		   << (int) this->bgml_state_.benchmark_iterations
		   << "; j++) \n";
	   this->incr_indent ();
	   this->indent ();
	   this->strm_ << " { \n";
	   this->incr_indent ();

	   this->nl ();
	   this->indent ();
	   this->strm_ << "const ACE_UINT64 x = history.get_sample (j) / gsf; \n";
	   this->indent ();
	   this->strm_ << "const ACE_UINT32 val = ACE_CU64_TO_CU32 (x); \n";

	   this->indent ();
	   this->strm_ << "ACE_OS::fprintf (output_file, \"%d %u\\n\", j, val);";
	   this->decr_indent ();

	   this->nl ();
	   this->indent ();
	   this->strm_ << "}\n";
	   this->decr_indent ();
	   this->indent ();
	   this->strm_ << "ACE_OS::fclose (output_file); \n";
	   this->nl ();
   }

   this->nl ();
   this->indent ();
   this->strm_ << "stats.dump_results (\"Total\", gsf);";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_Throughput_Stats::dump_throughput (\"Total\", gsf, test_end - test_start, stats.samples_count ());\n";

   this->nl ();

   /// Populate the results in BGML_Data
   this->indent ();
   this->strm_ << "// Store Benchmark Data for future retrieval \n";

   this->indent ();
   this->strm_ << "this->benchmark_data_.min_ = stats.min_ / gsf;\n";
   this->indent ();
   this->strm_ << "this->benchmark_data_.max_ = stats.max_ / gsf; \n";

   this->indent ();
   this->strm_ << "this->benchmark_data_.average_ = stats.sum_ / stats.samples_count_; \n";
   this->indent ();
   this->strm_ << "this->benchmark_data_.average_ /= gsf; \n";
   this->nl ();


   // Return success status
   this->indent ();
   this->strm_ << "return 1;";
   this->nl ();

   this->decr_indent ();
   this->strm_ << "}\n";

}

void
BenchmarkStream::generate_workload_def (__int64 iterations,
										BGML_Task_Group_Data &data)
{
	/// Step 1: Generate the ifdef macros
	std::string macro_name = this->component_name_ + "_" + this->operation_name_ + "_Workload";
	this->gen_ifdefc_macro (macro_name);
	this->nl ();

	//// Step 1.1: Generate the #include definitions
	std::string include_file = macro_name + ".h";
	this->gen_include_file (include_file);
	this->nl ();

	if (data.task_rate > 0)
	{
		include_file = "ace/High_Res_Timer.h";
		this->gen_include_file (include_file);
	}

	this->gen_constructor_defn (macro_name);
	this->gen_destructor_defn  (macro_name);

	/// Step 2: Generate the svc hook function to run it in a thread
	std::vector<std::string> param_list;
	this->gen_template_function_def ("svc",
									 macro_name,
									 "int",
									 param_list);
   this->incr_indent ();

   /// Set the thread to the appropriate priority
   if (data.task_priority >= 0)
   {
	this->indent ();
	this->strm_ << "// Set the thread to the appropriate priority \n";
	this->nl ();
	this->indent ();
	this->strm_ << "this->set_priority ("
				<< (int) data.task_priority
			    << ");";
	this->nl ();
	this->nl ();
   }

   // Wait on the barrier
   this->indent ();
   this->strm_ << "// Wait on the Barrier for tasks to start";
   this->nl ();
   this->indent ();
   this->strm_ << "this->arg" << (this->arg_list_.size() -1) << "_.wait ();";
   this->nl ();

   /// If this is a rate based invocation
   if (data.task_rate > 0)
   {
	   this->indent ();
	   this->strm_ << "ACE_UINT32 gsf = ACE_High_Res_Timer::global_scale_factor ();";
       this->nl ();
	   this->indent ();
	   this->strm_ << "ACE_hrtime_t deadline_for_call = 0;\n";
	   this->indent ();
	   this->strm_ << "ACE_hrtime_t interval_between_calls = 1/double ("
				   << (int) data.task_rate
				   << ") * gsf * ACE_HR_SCALE_CONVERSION; \n";
   }

   this->indent ();
   this->strm_ << "ACE_hrtime_t test_start = ACE_OS::gethrtime ();\n";

   this->indent ();
   this->strm_ << "for (int i = 0; ";
   this->strm_ << "i < ";
   __int64 iter = (iterations) ? iterations : BGML_DEFAULT_BENCH_ITER;
   this->strm_ << (long) iter;
   this->strm_ << "; i++)\n";

   this->indent ();
   this->strm_ << "{\n";
   this->incr_indent ();

   /// Check if this a rate based invocation
   if (data.task_rate > 0)
   {
	  this->indent ();
	  this->strm_ << "ACE_hrtime_t start = ACE_OS::gethrtime ();\n";
	  this->indent ();
	  this->strm_ << "deadline_for_call = interval_between_calls * (i + 1);\n";
	  this->indent ();
	  this->strm_ << "deadline_for_call += test_start; \n";
	  this->nl ();
	}

   /// Cast the operation return-type as a (void)
   this->indent ();
   this->strm_ << "(void)this->remote_ref_->";
   this->strm_ << this->operation_name_;
   this->strm_ << " (";

   // Stop one short of the size as ACE_Barrier& is the last
   // argument
   for (size_t i =0; i < this->arg_list_.size () - 1; i++)
	{
		if (i)
			this->strm_ << ",";
		this->strm_ << "arg";
		this->strm_ << i;
		this->strm_ << "_";
	}
   this->strm_ << " ACE_ENV_ARG_PARAMETER";
   this->strm_ << ");\n";

   this->indent ();
   this->strm_ << "ACE_CHECK;";
   this->nl ();

   /// Check if this is a rate based invocation
   if (data.task_rate > 0)
   {
	   this->nl ();
	   this->indent ();
	   this->strm_ << "ACE_hrtime_t now = ACE_OS::gethrtime ();\n";
	   this->nl ();
	   this->indent ();
	   this->strm_ << "if (now < deadline_for_call)\n";
	   this->indent ();
	   this->strm_ << "{\n";
	   this->incr_indent ();
	   this->indent ();
	   this->strm_ << "ACE_hrtime_t sleep_time = deadline_for_call - now;\n";
	   this->indent ();
	   this->strm_ << "ACE_OS::sleep (ACE_Time_Value (0, long (to_seconds (sleep_time, gsf) * ACE_ONE_SECOND_IN_USECS)));\n";
	   this->decr_indent ();
	   this->indent ();
	   this->strm_ << "}\n";
   }

   this->decr_indent ();
   this->indent ();
   this->strm_ << "}\n";

   this->indent ();
   this->strm_ << "// Indicate success \n";
   this->indent ();
   this->strm_ << "return 1; \n";

   this->decr_indent ();
   this->strm_ << "}\n";

   //// Step 5: Generate the endif macro to close the cpp file
   this->gen_endifc (macro_name);

}

void
BenchmarkStream::gen_constructor_defn (std::string& name)
{
	this->strm_ << "template<typename T>";
	this->nl ();
	this->strm_ << name.c_str ();
	this->strm_ << "<T>::";
	this->strm_ << name.c_str ();
	this->strm_ << " (T* remote_ref";

	if (this->arg_list_.size ())
		for (size_t i=0; i < this->arg_list_.size (); i++)
		{
			this->strm_ << ", ";
			this->strm_ << this->arg_list_[i];
			this->strm_ << " ";
			this->strm_ << "arg";
			this->strm_ << i;
		}
	this->strm_ << ")\n";
	this->strm_ << ": remote_ref_ (remote_ref)";
	if (this->arg_list_.size ())
		for (size_t j=0; j < this->arg_list_.size (); j++)
		{
			this->strm_ << ", ";
			this->strm_ << "arg" << j << "_";
			this->strm_ << " (arg" << j << ")";
		}

	this->nl ();
	this->strm_ << "{\n";
	this->nl ();
	this->strm_ << "}\n";

}

void
BenchmarkStream::gen_destructor_defn (std::string& name)
{
	this->strm_ << "template<typename T>";
	this->nl ();
	this->strm_ << name.c_str ();
	this->strm_ << "<T>::";
	this->strm_ << "~";
	this->strm_ << name.c_str ();
	this->strm_ << " ()";
	this->nl ();
	this->strm_ << "{\n";
	this->nl ();
	this->strm_ << "}\n";
	this->nl ();
}

void
BenchmarkStream::generate_rate_helper ()
{
	this->nl ();
	this->strm_ << "double \n"
				<< "to_seconds (ACE_UINT64 hrtime,"
				<< "ACE_UINT32 sf)\n"
				<< "{\n";
	this->incr_indent ();
	this->indent ();
	this->strm_ << "double seconds = \n";
	this->strm_ << "#if defined ACE_LACKS_LONGLONG_T\n";
	this->indent ();
	this->strm_ << "hrtime / sf;\n";
	this->strm_ << "#else  /* ! ACE_LACKS_LONGLONG_T */ \n";
	this->indent ();
	this->strm_ << "ACE_static_cast (double, ACE_UINT64_DBLCAST_ADAPTER (hrtime / sf)); \n";
	this->strm_ << "#endif /* ! ACE_LACKS_LONGLONG_T */ \n";
	this->indent ();
	this->strm_ << "seconds /= ACE_HR_SCALE_CONVERSION; \n";
	this->decr_indent ();
	this->indent ();
	this->strm_ << "return seconds; \n";
	this->strm_ << "}\n";
	this->nl ();
}

void
BenchmarkStream::gen_background_load (std::string& class_name, __int64 start_index, __int64 end_index)
{

	for (; start_index < end_index; start_index++)
	{
		this->indent ();
		this->strm_ << class_name.c_str ();

		// Instantiate the workload template
		this->strm_ << "<T>";

		this->strm_ << " task";
		this->strm_ << start_index << " (this->remote_ref_,";
		bool arg_flag = 0;
		for (size_t t = 0; t < this->arg_list_.size (); t++)
		{
			if (arg_flag)
				this->strm_ << ",";
			this->strm_ << " arg" << t << "_";
			arg_flag = 1;
		}

		// Insert barrier code
		arg_flag ? this->strm_ << ", barrier" : this->strm_ << " barrier";
		this->strm_ << ");";
		this->nl ();
	}
}

void
BenchmarkStream::activate_background_tasks (int task_size)
{
	if (task_size)
	{
		this->nl ();
		this->indent ();
	}

	this->strm_ << "// Activate the Background tasks \n";
	for (int i = 0; i < task_size; i++)
	{
		this->indent ();
		this->strm_ << "if (task" << i << ".activate (THR_NEW_LWP | THR_JOINABLE, 1, 1) == -1)";
		this->nl ();
		this->incr_indent ();
		this->indent ();
		this->strm_ << "ACE_ERROR ((LM_ERROR, \"Error activating workload task" << i
			        << " \\n\"));";
		this->decr_indent ();
		this->nl ();
	}

	this->nl ();
	this->indent ();
	this->strm_ << "// Wait on Barrier for tasks to start \n";
	this->indent ();
	this->strm_ << "barrier.wait ();\n";
	this->nl ();

}

int
BenchmarkStream::gen_barrier ()
{
	/// Compute total number of tasks
	int total_size = 0;
	for (size_t i = 0; i < this->bgml_state_.task_group_data.size (); i++)
		for (size_t j = 0; j < this->bgml_state_.task_group_data [i].size; j++, total_size ++);

	if (total_size)
	{
		// For the number of tasks assigned
		this->nl ();
		this->indent ();

		// Create Barrier
		this->strm_ << "ACE_Barrier barrier ("
					<<  (total_size + 1)
					<< ");";
		this->nl ();
	}

	/// Return this information
	return total_size;
}

void
BenchmarkStream::generate_task_def (std::string& metrics,
									BGML_Data &bgml_state)
{
	/// Step 1: Generate the ifdef macros
	std::string header_name = "Benchmark_" + this->component_name_ + "_" + this->operation_name_;
	this->gen_ifdefc_macro (header_name);
	this->nl ();

	//// Step 1.1: Generate the #include definitions
	std::string include_file = header_name + ".h";
	this->gen_include_file (include_file);

	/// Step 2: Generate the include files required for Benchmarking
	include_file = "ace/High_Res_Timer.h";
	this->gen_include_file (include_file);
	include_file = "ace/Stats.h";
	this->gen_include_file (include_file);
	include_file = "ace/Sample_History.h";
	this->gen_include_file (include_file);

	if (this->bgml_state_.task_group_data.size ())
	{
		std::string workload_name =
			this->component_name_ + "_" + this->operation_name_ + "_Workload.h";
		this->gen_include_file (workload_name);

		/// Generate the header file
		include_file = "ace/Barrier.h";
		this->gen_include_file (include_file);
	}

	this->nl ();

	this->gen_constructor_defn (header_name);
	this->gen_destructor_defn (header_name);

	/// Check if the invocations are rate based
	if (this->bgml_state_.benchmark_rate != -1)
	{
		this->generate_rate_helper ();
	}

	/// Step 2: Generate the svc hook function to run it in a thread
	std::vector<std::string> param_list;
	this->gen_template_function_def ("svc",
									 header_name,
									 "int",
									 param_list);

	/// Step 3: Generate the warm_up iterations
	this->gen_warmup_iterations (this->bgml_state_.warmup_iterations,
								 this->bgml_state_.benchmark_priority);

	/// Generate barrier information if there are background tasks
	int total_size = this->gen_barrier ();

	__int64 start_index = 0; /* Start the number for tasks */
	__int64 end_index = 0; /* Ending index for tasks */

	if (this->bgml_state_.task_group_data.size ())
	{
		this->nl ();
		this->indent ();
		this->strm_ << "// Generate the Background workload \n";
	}

	for (size_t i = 0; i < this->bgml_state_.task_group_data.size (); i++)
	{
		BGML_Task_Group_Data &task_data =
			this->bgml_state_.task_group_data [i];

		if (! task_data.background_operations.size ())
		{
			std::string class_name = this->component_name_ + "_" + this->operation_name_ + "_Workload";
			end_index = start_index + task_data.size;
			this->gen_background_load (class_name, start_index, end_index);

		} else if (task_data.background_operations.size () == task_data.size)
		{
			end_index = start_index + task_data.size;
			for (size_t j = 0; j < task_data.background_operations.size (); j++)
			{
				PICML::TwowayOperation twoway_op =
					PICML::TwowayOperation::Cast (task_data.background_operations [j]);
				std::string& operation_name = IDL_Util::operation_name (twoway_op);
				std::string class_name = this->component_name_ + "_" +
					this->operation_name_ + "_Workload";
				this->gen_background_load (class_name, start_index, start_index + 1);
				++ start_index;
			}
			// start is one more than what it should be, but we reset it later, hence
			// ignore the subtraction for now here.
		} else
		{
			end_index = start_index + task_data.background_operations.size () ;
			for (size_t j = 0; j < task_data.background_operations.size (); j++)
			{
				PICML::TwowayOperation twoway_op =
					PICML::TwowayOperation::Cast (task_data.background_operations [j]);
				std::string& operation_name = IDL_Util::operation_name (twoway_op);
				std::string class_name = this->component_name_ + "_" +
					operation_name + "_Workload";
				this->gen_background_load (class_name, start_index, start_index + 1);
				start_index ++;
			}

			// Start will now be from the end
			start_index = end_index;

			std::string class_name = this->component_name_ + "_" + this->operation_name_ + "_Workload";
			end_index = start_index + task_data.size -1;
			this->gen_background_load (class_name, start_index, end_index);
		}

		start_index = end_index; // After each interation, start is now finish
	}

	this->activate_background_tasks (total_size);

	/// Step 4: Generate the code for benchmarking
	this->gen_bench_def (this->bgml_state_.benchmark_iterations);

	/// Step 5: Implement the get_stats operation
	this->gen_template_function_def ("get_stats",
									 header_name,
									 "BGML_Data&",
									 param_list);

	this->incr_indent ();
	this->indent ();
	this->strm_ << "return this->benchmark_data_;\n";
	this->decr_indent ();
	this->indent ();
	this->strm_ << "}\n";

	//// Step 5: Generate the endif macro to close the cpp file
	this->gen_endifc (header_name);
}

void
BenchmarkStream::nl (void)
{
	this->strm_ << std::endl;
}

BenchmarkStream &
BenchmarkStream::operator<< (const std::string &s)
{
	this->strm_ << s.c_str ();
	return *this;
}

BenchmarkStream &
BenchmarkStream::operator<< (const char *str)
{
	this->strm_ << str;
	return *this;
}

BenchmarkStream &
BenchmarkStream::operator<< (const long &l)
{
	this->strm_ << l;
	return *this;
}

BenchmarkStream &
BenchmarkStream::operator<< (const unsigned long &ul)
{
	this->strm_ << ul;
	return *this;
}

BenchmarkStream &
BenchmarkStream::operator<< (const double &d)
{
	this->strm_ << d;
	return *this;
}

BenchmarkStream &
BenchmarkStream::operator<< (const char &c)
{
	this->strm_ << c;
	return *this;
}

BenchmarkStream &
BenchmarkStream::operator<< (const NL&)
{
	(void) this->nl ();
	return *this;
}

BenchmarkStream &
BenchmarkStream::operator<< (const INDENT& i)
{
	this->incr_indent (0);

	if (i.do_now_)
    {
		(void) this->nl ();
    }

	return *this;
}

BenchmarkStream &
BenchmarkStream::operator<< (const UNINDENT& i)
{
	this->decr_indent (0);

	if (i.do_now_)
    {
		this->nl ();
    }

	return *this;
}

void
BenchmarkStream::upcase (const char *str)
{
	int i = 0;
	char c;

	while ((c = str[i++]) != '\0')
    {
		this->strm_ << static_cast<char> (toupper (c));
    }
}

void
BenchmarkStream::gen_endif (const std::string &name)
{
	this->gen_endif (name.c_str ());
}

void
BenchmarkStream::gen_endif (const char *name)
{
	this->strm_ << "\n\n#endif // ";
	this->upcase (name);
	this->strm_ << "_H\n\n";
}

void
BenchmarkStream::gen_endifc (const std::string &name)
{
	this->gen_endif (name.c_str ());
}

void
BenchmarkStream::gen_endifc (const char *name)
{
	this->strm_ << "\n\n#endif // ";
	this->upcase (name);
	this->strm_ << "_C\n\n";
}

// Macro generation.
void
BenchmarkStream::gen_ifdef_macro (const std::string &name)
{
	this->gen_ifdef_macro (name.c_str ());
}

void
BenchmarkStream::gen_ifdef_macro (const char *name)
{
	this->strm_ << "\n#ifndef ";
	this->upcase (name);
	this->strm_ << "_H\n"
		<< "#define ";
	this->upcase (name);
	this->strm_ << "_H";
	this->strm_ << std::endl;
	this->indent ();
}

void
BenchmarkStream::gen_ifdefc_macro (const std::string& name)
{
	this->gen_ifdefc_macro (name.c_str ());
}

void
BenchmarkStream::gen_ifdefc_macro (const char *name)
{
	this->strm_ << "\n#ifndef ";
	this->upcase (name);
	this->strm_ << "_C\n"
		<< "#define ";
	this->upcase (name);
	this->strm_ << "_C";
	this->strm_ << std::endl;
	this->indent ();
}
