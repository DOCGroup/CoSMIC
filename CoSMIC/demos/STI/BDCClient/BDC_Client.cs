using System;
using System.Threading;

namespace CUTS
{
    class BDCClient
    {
        static CUTSPath_Element[] createPathId(String pathId)
        {
            char[] pathSeparator = { ';' };
            char[] pathElementSeparator = { ',' };
            string[] pathElements = pathId.Split(pathSeparator);
            foreach (string nodes in pathElements)
            {
                Console.WriteLine(nodes);
            }
            CUTSPath_Element[] pathSeq = new CUTSPath_Element[pathElements.Length];
            int counter = 0;
            foreach (string path in pathElements)
            {
                string[] components = path.Split(pathElementSeparator);
                foreach (string component in components)
                {
                    Console.WriteLine(component);
                }
                CUTSPath_Element pathElement = new CUTSPath_Element();
                pathElement.node = components[0];
                pathElement.src = components[1];
                pathElement.dst = components[2];
                pathSeq[counter++] = pathElement;
            }
            return pathSeq;
        }

        static void Main()
        {
            CUTSBenchmark_Data_Collector_SE_online_measurements
            bdc_measurements = new CUTSBenchmark_Data_Collector_SE_online_measurements();
            string pathId = "SLICE.CoWorkEr_ComponentImplementations.SLICE.SLICE.PlannerOne,CommandEvent,CommandEvent;SLICE.CoWorkEr_ComponentImplementations.SLICE.SLICE.SensorMain,CommandEvent,TrackEvent;SLICE.CoWorkEr_ComponentImplementations.SLICE.SLICE.PlannerOne,TrackEvent,SituationEvent;SLICE.CoWorkEr_ComponentImplementations.SLICE.SLICE.PlannerTwo,SituationEvent,AssessmentEvent;SLICE.CoWorkEr_ComponentImplementations.SLICE.SLICE.ConfigOp,AssessmentEvent,CommandEvent;SLICE.CoWorkEr_ComponentImplementations.SLICE.SLICE.EffectorMain,CommandEvent,CommandEvent";
            Console.WriteLine("pathId = {0}", pathId);
            CUTSPath_Element[] pathSeq = BDCClient.createPathId(pathId);
            try
            {
                int cutsId = bdc_measurements.bind_to_path(pathSeq, 3);
                CUTSBenchmark_Data_Collector_SE_controls
                    bdc_controller = new CUTSBenchmark_Data_Collector_SE_controls();
                int i = 100;
                while (i-- > 0)
                {
                    bdc_controller.collect_performance_data();
                    CUTSEvent_Time_Info eventInfo = bdc_measurements.execution_time(cutsId);
                    CUTSTime_Info time = eventInfo.time;
                    Console.WriteLine("ID {0}: exec time (min/avg/max): ({1} ms/{2} ms/{3} ms)\t number of events (min/max): ({4}/{5})",
                        cutsId,
                        time.min,
                        time.total,
                        time.max,
                        eventInfo.min_events,
                        eventInfo.max_events);
                    Thread.Sleep(20000);
                }
            }
            catch (System.Web.Services.Protocols.SoapException ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }
    }
}
