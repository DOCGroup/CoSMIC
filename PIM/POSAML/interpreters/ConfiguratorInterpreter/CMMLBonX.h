#ifndef CMMLBONX_H
#define CMMLBONX_H

#include "BON.h"
#include "BONImpl.h"
#include "Extensions.h"

///BUP
// add your include files/class definitions here
///EUP

namespace CMML_BON
{

DECLARE_ABSTRACT_BONEXTENSION( BON::Model, AbstractEventHandlerImpl, AbstractEventHandler );
DECLARE_BONEXTENSION( AbstractEventHandler, EventHandlerImpl, EventHandler );
DECLARE_BONEXTENSION( BON::Model, Acceptor_PatternImpl, Acceptor_Pattern );
DECLARE_BONEXTENSION( BON::Model, MiddlewareImpl, Middleware );
DECLARE_BONEXTENSION( BON::Model, Reactor_PatternImpl, Reactor_Pattern );
DECLARE_BONEXTENSION( BON::Atom, Active_Object_Map_SizeImpl, Active_Object_Map_Size );
DECLARE_BONEXTENSION( BON::Atom, AtomImpl, Atom );
DECLARE_BONEXTENSION( BON::Atom, ConcurrencyImpl, Concurrency );
DECLARE_BONEXTENSION( BON::Atom, End_PointsImpl, End_Points );
DECLARE_BONEXTENSION( BON::Atom, HandleImpl, Handle );
DECLARE_BONEXTENSION( BON::Atom, ReactorImpl, Reactor );
DECLARE_BONEXTENSION( BON::Atom, Reactor_TypeImpl, Reactor_Type );
DECLARE_BONEXTENSION( BON::Atom, SynchronousEventDemultiplexerImpl, SynchronousEventDemultiplexer );
DECLARE_BONEXTENSION( BON::Atom, Thread_QueueImpl, Thread_Queue );
DECLARE_BONEXTENSION( BON::Connection, DispatchesImpl, Dispatches );
DECLARE_BONEXTENSION( BON::Connection, End_Point_ConnectionImpl, End_Point_Connection );
DECLARE_BONEXTENSION( BON::Connection, NotifiesImpl, Notifies );
DECLARE_BONEXTENSION( BON::Connection, Reactor_Acceptor_ConnectionImpl, Reactor_Acceptor_Connection );
DECLARE_BONEXTENSION( BON::Connection, Reactor_Concurrency_ConnectionImpl, Reactor_Concurrency_Connection );
DECLARE_BONEXTENSION( BON::Connection, Reactor_Thread_Queue_ConnectionImpl, Reactor_Thread_Queue_Connection );
DECLARE_BONEXTENSION( BON::Connection, Reactor_Type_ConnectionImpl, Reactor_Type_Connection );
DECLARE_BONEXTENSION( BON::Connection, UsesImpl, Uses );


//*******************************************************************
//   C  L  A  S  S   AbstractEventHandlerImpl
//*******************************************************************
class AbstractEventHandlerImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	typedef enum
	{
		Read_EventType_Type,
		Write_EventType_Type,
		Except_EventType_Type,
		Accept_EventType_Type,
		Connect_EventType_Type
	} EventType_Type;

	//
	// connectionEnd getters
	virtual std::multiset<Reactor>          getDispatchesSrcs();
	virtual std::set<Dispatches>            getInDispatchesLinks();
	//
	// attribute getters and setters
	virtual AbstractEventHandlerImpl::EventType_Type  getEventType();
	virtual void        setEventType( AbstractEventHandlerImpl::EventType_Type val);
	//
	// kind and role getters
	virtual std::set<Handle>                getHandle();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   EventHandlerImpl
//*******************************************************************
class EventHandlerImpl :
	  public AbstractEventHandlerImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Acceptor_PatternImpl
//*******************************************************************
class Acceptor_PatternImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual std::multiset<End_Points>       getEnd_Point_ConnectionSrcs();
	virtual std::set<End_Point_Connection>  getInEnd_Point_ConnectionLinks();
	virtual std::set<Reactor_Acceptor_Connection>     getInReactor_Acceptor_ConnectionLinks();
	virtual std::multiset<Reactor_Pattern>  getReactor_Acceptor_ConnectionSrcs();
	//
	// kind and role getters
	virtual std::set<Atom>                  getAtom();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   MiddlewareImpl
//*******************************************************************
class MiddlewareImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// kind and role getters
	virtual std::set<Acceptor_Pattern>      getAcceptor_Pattern();
	virtual std::set<Active_Object_Map_Size>          getActive_Object_Map_Size();
	virtual std::set<Concurrency>           getConcurrency();
	virtual std::set<End_Point_Connection>  getEnd_Point_Connection();
	virtual std::set<End_Points>            getEnd_Points();
	virtual std::set<Reactor_Acceptor_Connection>     getReactor_Acceptor_Connection();
	virtual std::set<Reactor_Concurrency_Connection>  getReactor_Concurrency_Connection();
	virtual std::set<Reactor_Pattern>       getReactor_Pattern();
	virtual std::set<Reactor_Thread_Queue_Connection> getReactor_Thread_Queue_Connection();
	virtual std::set<Reactor_Type>          getReactor_Type();
	virtual std::set<Reactor_Type_Connection>         getReactor_Type_Connection();
	virtual std::set<Thread_Queue>          getThread_Queue();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Reactor_PatternImpl
//*******************************************************************
class Reactor_PatternImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual std::set<Reactor_Concurrency_Connection>  getInReactor_Concurrency_ConnectionLinks();
	virtual std::set<Reactor_Thread_Queue_Connection> getInReactor_Thread_Queue_ConnectionLinks();
	virtual std::set<Reactor_Type_Connection>         getInReactor_Type_ConnectionLinks();
	virtual std::set<Reactor_Acceptor_Connection>     getOutReactor_Acceptor_ConnectionLinks();
	virtual std::multiset<Acceptor_Pattern> getReactor_Acceptor_ConnectionDsts();
	virtual std::multiset<Concurrency>      getReactor_Concurrency_ConnectionSrcs();
	virtual std::multiset<Thread_Queue>     getReactor_Thread_Queue_ConnectionSrcs();
	virtual std::multiset<Reactor_Type>     getReactor_Type_ConnectionSrcs();
	//
	// kind and role getters
	virtual std::set<Dispatches>            getDispatches();
	virtual std::set<EventHandler>          getEventHandler();
	virtual std::set<Notifies>              getNotifies();
	virtual std::set<Reactor>               getReactor();
	virtual std::set<SynchronousEventDemultiplexer>   getSynchronousEventDemultiplexer();
	virtual std::set<Uses>                  getUses();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Active_Object_Map_SizeImpl
//*******************************************************************
class Active_Object_Map_SizeImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// attribute getters and setters
	virtual long        getValue() ;
	virtual void        setValue( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   AtomImpl
//*******************************************************************
class AtomImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };


	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ConcurrencyImpl
//*******************************************************************
class ConcurrencyImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	typedef enum
	{
		reactive_Concurrency_Options_Type,
		thread_per_connection_Concurrency_Options_Type
	} Concurrency_Options_Type;

	//
	// connectionEnd getters
	virtual std::set<Reactor_Concurrency_Connection>  getOutReactor_Concurrency_ConnectionLinks();
	virtual std::multiset<Reactor_Pattern>  getReactor_Concurrency_ConnectionDsts();
	//
	// attribute getters and setters
	virtual ConcurrencyImpl::Concurrency_Options_Type getConcurrency_Options();
	virtual void        setConcurrency_Options( ConcurrencyImpl::Concurrency_Options_Type val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   End_PointsImpl
//*******************************************************************
class End_PointsImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual std::multiset<Acceptor_Pattern> getEnd_Point_ConnectionDsts();
	virtual std::set<End_Point_Connection>  getOutEnd_Point_ConnectionLinks();
	//
	// attribute getters and setters
	virtual long        getPorts() ;
	virtual void        setPorts( const long val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   HandleImpl
//*******************************************************************
class HandleImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual std::set<Notifies>              getInNotifiesLinks();
	virtual std::multiset<SynchronousEventDemultiplexer> getNotifiesSrcs();
	//
	// attribute getters and setters
	virtual std::string getHandleName() ;
	virtual bool        isready() ;
	virtual void        setHandleName( const std::string& val);
	virtual void        setready( bool val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   ReactorImpl
//*******************************************************************
class ReactorImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual std::multiset<AbstractEventHandler>       getDispatchesDsts();
	virtual std::set<Dispatches>            getOutDispatchesLinks();
	virtual std::set<Uses>                  getOutUsesLinks();
	virtual std::multiset<SynchronousEventDemultiplexer> getUsesDsts();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Reactor_TypeImpl
//*******************************************************************
class Reactor_TypeImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	typedef enum
	{
		select_mt_Reactor_Type_Options_Type,
		select_st_Reactor_Type_Options_Type,
		wfmo_Reactor_Type_Options_Type,
		msg_wfmo_Reactor_Type_Options_Type,
		tp_Reactor_Type_Options_Type
	} Reactor_Type_Options_Type;

	//
	// connectionEnd getters
	virtual std::set<Reactor_Type_Connection>         getOutReactor_Type_ConnectionLinks();
	virtual std::multiset<Reactor_Pattern>  getReactor_Type_ConnectionDsts();
	//
	// attribute getters and setters
	virtual Reactor_TypeImpl::Reactor_Type_Options_Type getReactor_Type_Options();
	virtual void        setReactor_Type_Options( Reactor_TypeImpl::Reactor_Type_Options_Type val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   SynchronousEventDemultiplexerImpl
//*******************************************************************
class SynchronousEventDemultiplexerImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	typedef enum
	{
		select___DemultiplexerType_Type,
		WaitForMultipleObjects___DemultiplexerType_Type,
		poll___DemultiplexerType_Type
	} DemultiplexerType_Type;

	//
	// connectionEnd getters
	virtual std::set<Uses>                  getInUsesLinks();
	virtual std::multiset<Handle>           getNotifiesDsts();
	virtual std::set<Notifies>              getOutNotifiesLinks();
	virtual std::multiset<Reactor>          getUsesSrcs();
	//
	// attribute getters and setters
	virtual SynchronousEventDemultiplexerImpl::DemultiplexerType_Type getDemultiplexerType();
	virtual void        setDemultiplexerType( SynchronousEventDemultiplexerImpl::DemultiplexerType_Type val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Thread_QueueImpl
//*******************************************************************
class Thread_QueueImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	typedef enum
	{
		LIFO_Thread_Queue_Options_Type,
		FIFO_Thread_Queue_Options_Type
	} Thread_Queue_Options_Type;

	//
	// connectionEnd getters
	virtual std::set<Reactor_Thread_Queue_Connection> getOutReactor_Thread_Queue_ConnectionLinks();
	virtual std::multiset<Reactor_Pattern>  getReactor_Thread_Queue_ConnectionDsts();
	//
	// attribute getters and setters
	virtual Thread_QueueImpl::Thread_Queue_Options_Type getThread_Queue_Options();
	virtual void        setThread_Queue_Options( Thread_QueueImpl::Thread_Queue_Options_Type val);

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   DispatchesImpl
//*******************************************************************
class DispatchesImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual AbstractEventHandler            getDst();
	virtual Reactor     getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   End_Point_ConnectionImpl
//*******************************************************************
class End_Point_ConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual Acceptor_Pattern                getDst();
	virtual End_Points  getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   NotifiesImpl
//*******************************************************************
class NotifiesImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual Handle      getDst();
	virtual SynchronousEventDemultiplexer   getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Reactor_Acceptor_ConnectionImpl
//*******************************************************************
class Reactor_Acceptor_ConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual Acceptor_Pattern                getDst();
	virtual Reactor_Pattern                 getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Reactor_Concurrency_ConnectionImpl
//*******************************************************************
class Reactor_Concurrency_ConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual Reactor_Pattern                 getDst();
	virtual Concurrency getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Reactor_Thread_Queue_ConnectionImpl
//*******************************************************************
class Reactor_Thread_Queue_ConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual Reactor_Pattern                 getDst();
	virtual Thread_Queue                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   Reactor_Type_ConnectionImpl
//*******************************************************************
class Reactor_Type_ConnectionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual Reactor_Pattern                 getDst();
	virtual Reactor_Type                    getSrc();

	///BUP
	// add your own members here
	///EUP
};


//*******************************************************************
//   C  L  A  S  S   UsesImpl
//*******************************************************************
class UsesImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual SynchronousEventDemultiplexer   getDst();
	virtual Reactor     getSrc();

	///BUP
	// add your own members here
	///EUP
};



}; // namespace CMML_BON

///BUP
// add your additional class definitions here
///EUP

#endif // CMMLBONX_H
