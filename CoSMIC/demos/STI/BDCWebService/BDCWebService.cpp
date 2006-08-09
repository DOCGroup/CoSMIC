#include "ace/Get_Opt.h"
#include "cuts/BDC/Benchmark_Data_CollectorC.h"
#include "cuts/CUTSC.h"
#include "SLICECUTS_x002eBenchmark_USCOREData_USCORECollector_x002e_USCORESE_USCOREcontrolsService.h"

const char *bdc_ior = "file://BDC.ior";
int port = 8080;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "k:p:");
  int c;

  while ((c = get_opts ()) != -1)
    {
      switch (c)
        {
          case 'k':
            bdc_ior = get_opts.opt_arg ();
            break;

          case 'p':
            port = atoi (get_opts.opt_arg ());
            break;

          case '?':  // display help for use of the server.
          default:
            ACE_ERROR_RETURN ((LM_ERROR,
                               "usage:  %s\n"
                               "-k <Benchmark Data Collector IOR> (default is file://BDC.ior)\n"
                               "-p <Port to listen for requests (default is 8080)\n"
                               "\n",
                               argv [0]),
                              -1);
        }
    }
  return 0;
}

int
main (int argc, char *argv[])
{
  try
    {
      // Initialize orb
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv, "");

      if (parse_args (argc, argv) != 0)
        {
          return -1;
        }

      CORBA::Object_var obj = orb->string_to_object (bdc_ior);

      CUTS::Benchmark_Data_Collector_var bdc
        = CUTS::Benchmark_Data_Collector::_narrow (obj.in ());

      if (CORBA::is_nil (bdc.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Unable to acquire BenchMark_Data_Collector objref\n"),
                            -1);
        }
      CUTS::Path_Measurement_var online_measurements = bdc->provide_online_measurements();

      if (CORBA::is_nil (online_measurements.in()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Unable to acquire online_measurements objref\n"),
                            -1);
        }

      CUTS::BDC_Control_Handle_var controls = bdc->provide_controls();

      if (CORBA::is_nil (controls.in()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Unable to acquire controls objref\n"),
                            -1);
        }

      CUTS_x002eBenchmark_USCOREData_USCORECollector_x002e_USCORESE_USCOREcontrolsService service (online_measurements.in(), controls.in());
      int m, s; // master and slave sockets

      m = soap_bind(&service, "localhost", 8080, 100);
      if (m < 0)
        soap_print_fault(&service, stderr);
      else
        {
          fprintf(stderr, "Socket connection successful: master socket = %d\n", m);
          for (int i = 1; ; i++)
            {
              s = soap_accept(&service);
              if (s < 0)
                {
                  soap_print_fault(&service, stderr);
                  break;
                }
              fprintf(stderr,
                      "%d: accepted connection from IP=%d.%d.%d.%d socket=%d\n", i,
                      (service.ip >> 24)&0xFF,
                      (service.ip >> 16)&0xFF,
                      (service.ip >> 8)&0xFF,
                      service.ip&0xFF, s);
              if (service.serve() != SOAP_OK) // process RPC request
                soap_print_fault(&service, stderr); // print error
              fprintf(stderr, "request served\n");
              soap_destroy(&service); // clean up class instances
              soap_end(&service); // clean up everything and close socket
            }
        }
    }
  catch (CORBA::Exception& ex)
    {
      ACE_PRINT_EXCEPTION (ex, "Who is the culprit \n");
      ACE_ERROR_RETURN ((LM_ERROR,
                         "Uncaught CORBA exception\n"),
                        1);
    }

  return 0;
}
