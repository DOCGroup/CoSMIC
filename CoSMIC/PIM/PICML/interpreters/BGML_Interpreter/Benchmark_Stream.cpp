#include "Benchmark_Stream.h"
#include "ctype.h"

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
								  std::vector<__int64>& task_priorities,
								  std::vector<__int64>& task_rates)
: component_name_ (component_name),
  operation_name_ (operation_name),
  arg_list_ (arg_list),
  strm_ (strm),
  task_priorities_ (task_priorities),
  task_rates_ (task_rates),
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
	this->strm_ << " (T remote_ref";
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
BenchmarkStream::gen_private_mem_decl ()
{
	if (this->arg_list_.size ())
	{
		this->nl ();
		this->strm_ << "protected:";
		this->nl ();
		this->incr_indent ();
		this->indent ();
		this->strm_ << "T remote_ref_;";
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

		this->decr_indent ();
	}
}

void
BenchmarkStream::generate_task_header (std::string& header_name)
{
	///// Generate the #ifdef macros
	this->gen_ifdef_macro (header_name);
	
	///// Step 2 generate the include files necessary
	std::string base_task = "BGML_Task_Base.h";
	std::string component_exec_header = this->component_name_ + "_exec.h";
	this->nl ();

	this->gen_include_file (base_task);
	this->gen_include_file (component_exec_header);
	this->nl ();
	
	///// Step 3: Generate the "class" definition
	this->strm_ << "template <typename T>";
	this->nl ();
	this->strm_ << "class ";
	this->strm_ << header_name.c_str ();
	this->strm_ << " : BGML_Task_Base";
	this->nl ();
	this->strm_ << "{";
	this->nl ();
	this->strm_ << "public:";
	this->nl ();
	
	//// Step 4: Write out the constructor/Destructor for the tasks
	this->gen_constructor_decl (header_name);
	this->gen_destructor_decl  (header_name);
	
	//// Step 5: Write out the hook svc method for ACE_Task_Base
	this->incr_indent ();
	this->nl ();
	this->indent ();
	this->strm_ << "int svc (void);";
	this->decr_indent ();
	this->nl ();
	
	//// Step 6: Write out the private members
	this->gen_private_mem_decl ();

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
BenchmarkStream::gen_warmup_iterations (__int64 iterations)
{
	this->incr_indent ();
	this->nl ();
	this->indent ();
	this->strm_ << "for (int warm_up = 0; warm_up < ";
	if (iterations)
		this->strm_ << (long) iterations;
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
		this->strm_ << "arg";
		this->strm_ << i;
	}
	this->strm_ << " ACE_ENV_ARG_PARAMETER";
	this->strm_ << ");";
	this->decr_indent ();
	this->nl ();
}

void
BenchmarkStream::gen_background_load (std::string& class_name)
{
	// For the number of tasks assigned 
	this->nl ();
	this->indent ();
	this->strm_ << "// Generate the Background workload \n";
	for (size_t i = 0; i < this->task_priorities_.size (); i++)
	{
		this->indent ();
		this->strm_ << class_name.c_str ();
		
		// Instantiate the workload template
		this->strm_ << "<T>";

		this->strm_ << " task";
		this->strm_ << i << " (this->remote_ref_,";
		bool arg_flag = 0;
		for (size_t t = 0; t < this->arg_list_.size (); t++)
		{
			if (arg_flag)
				this->strm_ << ",";
			this->strm_ << " arg" << t;
			arg_flag = 1;
		}

		/// Add the priority of the task
		if (arg_flag)
			this->strm_ << ", " << (long) this->task_priorities_ [i] << ");";
		else
			this->strm_ << " " << (long) this->task_priorities_ [i] << ");";
		this->nl ();
	}

	this->nl ();

	this->indent ();
	this->strm_ << "// Activate the Background tasks \n";
	
	for (i = 0; i < this->task_priorities_.size (); i++)
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

}

void
BenchmarkStream::gen_bench_def (__int64 iterations)
{
   this->indent ();
   this->strm_ << "ACE_Sample_History history (";
   __int64 iter = (iterations) ? iterations : BGML_DEFAULT_BENCH_ITER;
   this->strm_ << (long) iter;
   this->strm_ << ");";
   
   this->nl ();
   this->indent ();
   this->strm_ << "ACE_hrtime_t test_start = ACE_OS::gethrtime ();\n";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_UINT32 gsf = ACE_High_Res_Timer::global_scale_factor ();";
   this->nl ();

   this->indent ();
   this->strm_ << "for (i = 0; ";
   this->strm_ << "i < ";
   this->strm_ << (long) iter;
   this->strm_ << "; i++)\n";
   
   this->indent ();
   this->strm_ << "{\n";

   this->incr_indent ();
   this->indent ();
   this->strm_ << "ACE_hrtime_t start = ACE_OS::gethrtime ();\n";
   this->indent ();

   /// Cast the operation return-type as a (void)
   this->strm_ << "(void)this->remote_ref_->";
   this->strm_ << this->operation_name_;
   this->strm_ << " (";
   for (size_t i =0; i < this->arg_list_.size (); i++)
	{
		if (i)
			this->strm_ << ",";
		this->strm_ << "arg";
		this->strm_ << i;
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

   this->nl ();
   this->decr_indent ();
   this->indent ();
   this->strm_ << "}\n";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_hrtime_t test_end = ACE_OS::gethrtime ();";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_DEBUG ((LM_DEBUG, \"test finished\"));";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_DEBUG ((LM_DEBUG, \"High resolution timer calibration....\"));";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_DEBUG ((LM_DEBUG, \"done\"));";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_Basic_Stats stats;";

   this->nl ();
   this->indent ();
   this->strm_ << "history.collect_basic_stats (stats);";

   this->nl ();
   this->indent ();
   this->strm_ << "stats.dump_results (\"Total\", gsf);";

   this->nl ();
   this->indent ();
   this->strm_ << "ACE_Throughput_Stats::dump_throughput (\"Total\", gsf, test_end - test_start, stats.samples_count ());\n";

   this->nl ();
   this->decr_indent ();
   this->strm_ << "}\n";

}

void
BenchmarkStream::generate_workload_def (__int64 iterations)
{
	/// Step 1: Generate the ifdef macros
	std::string header_name = this->component_name_ + "_Workload";
	this->gen_ifdefc_macro (header_name);
	this->nl ();
	
	//// Step 1.1: Generate the #include definitions
	std::string include_file = header_name + ".h";
	this->nl ();

	this->gen_constructor_defn (header_name);
	this->gen_destructor_defn (header_name);

	/// Step 2: Generate the svc hook function to run it in a thread
	std::vector<std::string> param_list;
	this->gen_template_function_def ("svc",
									 header_name,
									 "void",
									 param_list);
   this->incr_indent ();
   this->indent ();

   /// If rate 

   this->strm_ << "for (i = 0; ";
   this->strm_ << "i < ";
   __int64 iter = (iterations) ? iterations : BGML_DEFAULT_BENCH_ITER;
   this->strm_ << (long) iter;
   this->strm_ << "; i++)\n";
   
   this->indent ();
   this->strm_ << "{\n";
   this->incr_indent ();
   
   /// Cast the operation return-type as a (void)
   this->indent ();
   this->strm_ << "(void)this->remote_ref_->";
   this->strm_ << this->operation_name_;
   this->strm_ << " (";
   for (size_t i =0; i < this->arg_list_.size (); i++)
	{
		if (i)
			this->strm_ << ",";
		this->strm_ << "arg";
		this->strm_ << i;
	}
   this->strm_ << " ACE_ENV_ARG_PARAMETER";
   this->strm_ << ");\n";

   this->indent ();
   this->strm_ << "ACE_CHECK;";
   
   this->nl ();
   this->decr_indent ();
   this->indent ();
   this->strm_ << "}\n";

   this->decr_indent ();
   this->strm_ << "}\n";

	//// Step 5: Generate the endif macro to close the cpp file
	this->gen_endifc (header_name);
	
}

void
BenchmarkStream::gen_constructor_defn (std::string& name)
{
	this->strm_ << "template<typename T>";
	this->nl ();
	this->strm_ << name.c_str ();
	this->strm_ << "<T>::";
	this->strm_ << name.c_str ();
	this->strm_ << " (T remote_ref";
	
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
BenchmarkStream::generate_task_def (__int64 warmup, 
									__int64 iterations, 
									std::string& file_name,
									std::string& metrics)
{
	/// Step 1: Generate the ifdef macros
	std::string header_name = "Benchmark_" + this->operation_name_;
	this->gen_ifdefc_macro (header_name);
	this->nl ();

	//// Step 1.1: Generate the #include definitions
	std::string include_file = header_name + ".h";
	this->gen_include_file (include_file);
	if (this->task_priorities_.size ())
	{
		std::string workload_name = this->operation_name_ + "_Workload.h";
		this->gen_include_file (workload_name);
	}
	this->nl ();

	this->gen_constructor_defn (header_name);
	this->gen_destructor_defn (header_name);

	/// Step 2: Generate the svc hook function to run it in a thread
	std::vector<std::string> param_list;
	this->gen_template_function_def ("svc",
									 header_name,
									 "void",
									 param_list);

	/// Step 3: Generate the warm_up iterations
	this->gen_warmup_iterations (warmup);

	if (this->task_priorities_.size ())
	{
		std::string class_name = this->operation_name_ + "_Workload";
		this->gen_background_load (class_name);
	}

	/// Step 4: Generate the code for benchmarking
	this->gen_bench_def (iterations);

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