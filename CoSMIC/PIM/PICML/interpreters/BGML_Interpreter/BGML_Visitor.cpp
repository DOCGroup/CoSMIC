#include "BGML_Visitor.h"
#include "MetricEmitter.h"
#include "Timer_Stream.h"
#include "Uml.h"
#include "Global_Data.h"

BGML_Visitor::BGML_Visitor (std::string &outputPath)
{
	bgml_state.output_path = outputPath;
}

BGML_Visitor::~BGML_Visitor ()
{
	
}

void
BGML_Visitor::write_timer_information (std::string& file_name)
{
	// Write out the Benchmark files
	std::ofstream timer_stream (file_name.c_str ());
	Timer_Stream timer (timer_stream);
	
	timer.write_includes ();
	timer.write_start_time_probe ();
	timer.write_stop_time_probe ();
	
}

void
BGML_Visitor::Visit_TimeProbe (const PICML::TimeProbe& probe)
{
	// Obtain the name of the Operation
	std::string file_name;
	PICML::TimerConnection timer_conn = probe.srcTimerConnection ();
	if (timer_conn != Udm::null)
	{
		PICML::OperationRef op_ref = timer_conn.srcTimerConnection_end();
		std::string name;

		if (op_ref != Udm::null)
		{
			PICML::OperationBase op_base = op_ref.ref ();
			op_base.GetStrValue ("name", name);

			// Write out the Timer information 
			file_name = bgml_state.output_path + "\\" + name + "_Timer.h";
		}
	}

	// Reference to an Event
	PICML::TimerEventSinkConn event_conn = probe.srcTimerEventSinkConn();
	if (event_conn != Udm::null)
	{
		PICML::EventRef evt_ref = event_conn.srcTimerEventSinkConn_end ();

		if (evt_ref != Udm::null)
		{
			std::string name;
			PICML::Event event = evt_ref.ref ();
			event.GetStrValue ("name", name);
			
			// Write out the Timer information 
			file_name = bgml_state.output_path + "\\" + name + "_Timer.h";
		
		}
	}

	// Write out the timing information
	write_timer_information (file_name);

}

void
BGML_Visitor::Visit_BenchmarkAnalysis (const PICML::BenchmarkAnalysis& model)
{
	// Model contains all the required benchmarking information aspects
	// Steps 
	// 1: First get all the operation references that are present in this
	//    aspect.
	// 2: For each of the operations then obtain what is the metric that
	//    needs to be measured.
	// 3: Obtain the name of the component that this operation is associated
	//    with
	
	std::set<PICML::MetricsBase> metrics = model.MetricsBase_children();
	for (std::set<PICML::MetricsBase>::iterator iter = metrics.begin ();
	iter != metrics.end ();
	iter ++)
	{
		// The two-way operation that it is measuring
		PICML::MetricConnection conn = iter->srcMetricConnection ();
		PICML::OperationRef op_ref = conn.srcMetricConnection_end();
		PICML::OperationBase operation = op_ref.ref ();

		/// Check if there is a priority or rate for the main task
		bgml_state.benchmark_priority = (* iter).priority ();
		bgml_state.benchmark_rate     = (* iter).rate ();
		
		// Check if there are any connections to Task Sets
		PICML::WorkloadCharacteristics task_set = iter->dstWorkloadCharacteristics();
		

		if (task_set != Udm::null)
		{
			PICML::TaskSet set = task_set.dstWorkloadCharacteristics_end();

			BGML_Task_Data this_task;
			std::set<PICML::Task> tasks = set.members ();
			this_task.number_of_tasks = tasks.size ();
			this_task.task_priority = ((*iter).priority());
			this_task.task_rate = ((*iter).rate ());
			bgml_state.task_group_data.push_back (this_task);
		}
		
		// If the metrics is a latencyMetric
		std::string kindName = (*iter).type().name();
		
		// Check if this operation is a two-way operation
		std::string op_kind = operation.type().name();

		if (kindName == "Latency" &&
			op_kind  == "TwowayOperation")
		{
			// Write out the Latency information for this guy
			PICML::Latency latency = PICML::Latency::Cast (* iter);
			MetricEmitter<PICML::Latency> emitter (operation, 
												   latency, 
												   kindName);
			emitter.generate_benchmark ();		
		 }
		 else if (kindName == "Throughput" &&
		    	  op_kind  == "TwowayOperation")
		  {
			// Write out the Latency information for this guy
			PICML::Throughput thr = PICML::Throughput::Cast (* iter);
			MetricEmitter<PICML::Throughput> thr_emitter (operation, 
														  thr, 
														  kindName);
			thr_emitter.generate_benchmark ();
		  }
	}

	// Generate timining information for all the timer elements
	std::set<PICML::TimeProbe> timers = model.TimeProbe_children();
	for (std::set<PICML::TimeProbe>::iterator iter2 = timers.begin ();
	     iter2 != timers.end ();
	     iter2 ++)
	{
	   this->Visit_TimeProbe (* iter2);
	}
}

