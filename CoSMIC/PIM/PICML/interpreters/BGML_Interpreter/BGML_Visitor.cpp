#include "BGML_Visitor.h"
#include "MetricEmitter.h"
#include "Timer_Stream.h"
#include "Uml.h"

BGML_Visitor::BGML_Visitor (const std::string& outputPath)
: outputPath_ (outputPath)
{
	
}

BGML_Visitor::~BGML_Visitor ()
{
	
}

void
BGML_Visitor::Visit_TimeProbe (const PICML::TimeProbe& probe)
{
	// Obtain the name of the Operation 
	PICML::TimerConnection timer_conn = probe.srcTimerConnection ();
	PICML::OperationRef op_ref = timer_conn.srcTimerConnection_end();
	std::string name;

	if (op_ref != Udm::null)
	{
		PICML::OperationBase op_base = op_ref.ref ();
		op_base.GetStrValue ("name", name);
		// Write out the Timer information 
		std::string file_name = this->outputPath_ + "\\" + name + "_Timer.h";
		
		// Write out the Benchmark files
		std::ofstream timer_stream (file_name.c_str ());
		Timer_Stream timer (timer_stream);
		
		timer.write_includes ();
		timer.write_start_time_probe ();
		timer.write_stop_time_probe ();
	}

	// Reference to an Event
	PICML::TimerEventSinkConn event_conn = probe.srcTimerEventSinkConn();
	PICML::EventRef evt_ref = event_conn.srcTimerEventSinkConn_end ();

	if (evt_ref != Udm::null)
	{
		PICML::Event event = evt_ref.ref ();
		event.GetStrValue ("name", name);
		// Write out the Timer information 
		std::string file_name = this->outputPath_ + "\\" + name + "_Timer.h";
		
		// Write out the Benchmark files
		std::ofstream timer_stream (file_name.c_str ());
		Timer_Stream timer (timer_stream);
		
		timer.write_includes ();
		timer.write_start_time_probe ();
		timer.write_stop_time_probe ();
	}

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
		
		// Check if there are any connections to Task Sets
		PICML::WorkloadCharacteristics task_set = iter->dstWorkloadCharacteristics();
		std::vector<__int64> task_priorities;

		if (task_set != Udm::null)
		{
			PICML::TaskSet set = task_set.dstWorkloadCharacteristics_end();
			std::set<PICML::Task> tasks = set.members ();
			int index = 0;
			for (std::set<PICML::Task>::iterator iter = tasks.begin ();
				 iter != tasks.end ();
				 iter ++)
			{
				__int64 temp = (*iter).priority();
				task_priorities.push_back (temp);
			}
			
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
													this->outputPath_,
													task_priorities,
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
														  this->outputPath_,
														  task_priorities,
														  kindName);
			thr_emitter.generate_benchmark ();
		  }
	}

	std::set<PICML::TimeProbe> timers = model.TimeProbe_children();
	for (std::set<PICML::TimeProbe>::iterator iter2 = timers.begin ();
	     iter2 != timers.end ();
	     iter2 ++)
	{
	   this->Visit_TimeProbe (* iter2);
	}
}

