#include <Benchmark_Data_Collector_Impl.h>

namespace SLICE
{


  using namespace System::Runtime::InteropServices;

  struct MarshalFunctor
  {

    void operator() (char* ptr)
    {

      Marshal::FreeHGlobal (static_cast<System::IntPtr> (ptr));
    }
  };


  std::string CliStrToStdStr (System::String ^clistring)
  {

    char* str = static_cast<char*>
    (static_cast<void*> (Marshal::StringToHGlobalAnsi(clistring)));

    ACE_Utils::Auto_Functor<char,MarshalFunctor> cleanup (str);

    return std::string(str);
  }


  Benchmark_Data_Collector::Benchmark_Data_Collector()
  {

    try
    {

      int argc = 1;

      CORBA::StringSeq argv (argc);

      argv.length(argc);

      argv[argc-1] = "dummy";

      this->orb_ = CORBA::ORB_init (argc, argv.get_buffer(), "");

      if (CORBA::is_nil (this->orb_))
      {

        throw std::exception("Unable to initialize ORB: ORB_init failed");
      }


      CORBA::Object_var obj = this->orb_->resolve_initial_references ("NameService");

      if (CORBA::is_nil(obj))
      {

        throw std::exception ("Unable to obtain reference to NameService");
      }


      CosNaming::NamingContext_var ctx = CosNaming::NamingContext::_narrow (obj);

      if (CORBA::is_nil(ctx))
      {

        throw std::exception ("Unable to narrow reference to initial Naming Context");
      }


      CosNaming::Name name;

      name.length (1);

      name[0].id = CORBA::string_dup ("Benchmark_Data_Collector");

      obj = ctx->resolve (name);

      if (CORBA::is_nil (obj))
      {
        throw std::exception ("Unable to acquire Benchmark_Data_Collector objref");
      }


      this->benchmark_data_collector_ = CUTS::Benchmark_Data_Collector::_narrow (obj.in());

      if (CORBA::is_nil (this->benchmark_data_collector_))
      {
        throw std::exception ("Unable to narrow reference to Benchmark_Data_Collector");
      }

      this->controls_ = this->benchmark_data_collector_->provide_controls();

      if (CORBA::is_nil (this->controls_))
      {
        throw std::exception ("Unable to acquire controls objref");
      }

      this->online_measurements_ = this->benchmark_data_collector_->provide_online_measurements();

      if (CORBA::is_nil (this->online_measurements_))
      {
        throw std::exception ("Unable to acquire online_measurements objref");
      }
    }


    catch (CORBA::Exception& ex)
    {
      ACE_PRINT_EXCEPTION (ex, "CORBA::Exception");

      throw std::exception (ex._info().c_str());
    }
  }


  Benchmark_Data_Collector::~Benchmark_Data_Collector()
  {
    CUTS::BDC_Control_Handle_var controls(this->controls_);

    CUTS::Path_Measurement_var online_measurements(this->online_measurements_);

    CUTS::Benchmark_Data_Collector_var benchmark_data_collector(this->benchmark_data_collector_);

    CORBA::ORB_var orb (this->orb_);
  }

  CUTSEvent_Time_Info^ Benchmark_Data_Collector::execution_time(System::Int32 path_id)
  {
    try
    {
      CUTS::Event_Time_Info _return = this->online_measurements_->execution_time (path_id);
      CUTSEvent_Time_Info^ retval = gcnew CUTSEvent_Time_Info();

      retval->min_events = _return.min_events;

      retval->max_events = _return.max_events;

      retval->time = gcnew CUTSTime_Info();

      retval->time->min = _return.time.min;

      retval->time->max = _return.time.max;

      retval->time->total = _return.time.total;

      return retval;
    }

    catch (CUTS::Operation_Failed& ex)
    {
      ACE_PRINT_EXCEPTION (ex, "execution_time");

      throw std::exception (ex._info().c_str());
    }

    catch (CUTS::ID_Not_Found& ex)
    {
      ACE_PRINT_EXCEPTION (ex, "execution_time");

      throw std::exception (ex._info().c_str());
    }

    catch (CORBA::Exception& ex)
    {
      ACE_PRINT_EXCEPTION (ex, "execution_time");

      throw std::exception (ex._info().c_str());
    }
  }


  System::Void Benchmark_Data_Collector::unbind_to_path(System::Int32 path_id)
  {
    try
    {
      this->online_measurements_->unbind_to_path (path_id);
    }

    catch (CUTS::ID_Not_Found& ex)
    {
      ACE_PRINT_EXCEPTION (ex, "unbind_to_path");

      throw std::exception (ex._info().c_str());
    }

    catch (CORBA::Exception& ex)
    {
      ACE_PRINT_EXCEPTION (ex, "unbind_to_path");

      throw std::exception (ex._info().c_str());
    }
  }


  System::Int32 Benchmark_Data_Collector::bind_to_path(cli::array<CUTSPath_Element^>^ path, 
                                                       System::UInt16 flags)
  {
    try
    {
      CUTS::Path_Sequence pathSeq;

      for (int i = 0; i < path->Length; ++i)
      {
        CUTSPath_Element^ element = path[i];

        CUTS::Path_Element pathSeqElement;

        pathSeqElement.dst = CORBA::string_dup (CliStrToStdStr (element->dst).c_str());

        pathSeqElement.src = CORBA::string_dup (CliStrToStdStr (element->src).c_str());

        pathSeqElement.node = CORBA::string_dup (CliStrToStdStr (element->node).c_str());

        CORBA::ULong len = pathSeq.length();

        pathSeq.length(len + 1);

        pathSeq[len] = pathSeqElement;
      }

      System::Int32 retval = this->online_measurements_->bind_to_path (pathSeq, flags);
      return retval;
    }

    catch (CUTS::Binding_Failed& ex)
    {
      ACE_PRINT_EXCEPTION (ex, "bind_to_path");

      throw std::exception (ex._info().c_str());
    }

    catch (CORBA::Exception& ex)
    {
      ACE_PRINT_EXCEPTION (ex, "bind_to_path");

      throw std::exception (ex._info().c_str());
    }
  }


  System::Void Benchmark_Data_Collector::collect_performance_data()
  {
    try
    {
      this->controls_->collect_performance_data ();
    }

    catch (CORBA::Exception& ex)
    {
      ACE_PRINT_EXCEPTION (ex, "collect_performance_data");

      throw std::exception (ex._info().c_str());
    }
  }
}


