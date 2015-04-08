#include "stdafx.h"
#include "CMMLBonX.h"


namespace BON
{

IMPLEMENT_ABSTRACT_BONEXTENSION( CMML_BON::AbstractEventHandler );
IMPLEMENT_BONEXTENSION( CMML_BON::EventHandler, "EventHandler" );
IMPLEMENT_BONEXTENSION( CMML_BON::Acceptor_Pattern, "Acceptor_Pattern" );
IMPLEMENT_BONEXTENSION( CMML_BON::Middleware, "Middleware" );
IMPLEMENT_BONEXTENSION( CMML_BON::Reactor_Pattern, "Reactor_Pattern" );
IMPLEMENT_BONEXTENSION( CMML_BON::Active_Object_Map_Size, "Active_Object_Map_Size" );
IMPLEMENT_BONEXTENSION( CMML_BON::Atom, "Atom" );
IMPLEMENT_BONEXTENSION( CMML_BON::Concurrency, "Concurrency" );
IMPLEMENT_BONEXTENSION( CMML_BON::End_Points, "End_Points" );
IMPLEMENT_BONEXTENSION( CMML_BON::Handle, "Handle" );
IMPLEMENT_BONEXTENSION( CMML_BON::Reactor, "Reactor" );
IMPLEMENT_BONEXTENSION( CMML_BON::Reactor_Type, "Reactor_Type" );
IMPLEMENT_BONEXTENSION( CMML_BON::SynchronousEventDemultiplexer, "SynchronousEventDemultiplexer" );
IMPLEMENT_BONEXTENSION( CMML_BON::Thread_Queue, "Thread_Queue" );
IMPLEMENT_BONEXTENSION( CMML_BON::Dispatches, "Dispatches" );
IMPLEMENT_BONEXTENSION( CMML_BON::End_Point_Connection, "End_Point_Connection" );
IMPLEMENT_BONEXTENSION( CMML_BON::Notifies, "Notifies" );
IMPLEMENT_BONEXTENSION( CMML_BON::Reactor_Acceptor_Connection, "Reactor_Acceptor_Connection" );
IMPLEMENT_BONEXTENSION( CMML_BON::Reactor_Concurrency_Connection, "Reactor_Concurrency_Connection" );
IMPLEMENT_BONEXTENSION( CMML_BON::Reactor_Thread_Queue_Connection, "Reactor_Thread_Queue_Connection" );
IMPLEMENT_BONEXTENSION( CMML_BON::Reactor_Type_Connection, "Reactor_Type_Connection" );
IMPLEMENT_BONEXTENSION( CMML_BON::Uses, "Uses" );


}; // end namespace BON

namespace CMML_BON
{
//********************************************************************************
// returns src Reactors
//********************************************************************************
std::multiset<Reactor> AbstractEventHandlerImpl::getDispatchesSrcs()
{
	std::multiset<Reactor> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = getInConnEnds("Dispatches");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Reactor dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<Dispatches> AbstractEventHandlerImpl::getInDispatchesLinks()
{
	std::set<Dispatches> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Dispatches c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
AbstractEventHandlerImpl::EventType_Type AbstractEventHandlerImpl::getEventType()
{
	std::string val = FCOImpl::getAttribute("EventType")->getStringValue();

	if ( val == "Read") return Read_EventType_Type;
	else if ( val == "Write") return Write_EventType_Type;
	else if ( val == "Except") return Except_EventType_Type;
	else if ( val == "Accept") return Accept_EventType_Type;
	else if ( val == "Connect") return Connect_EventType_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
void AbstractEventHandlerImpl::setEventType( AbstractEventHandlerImpl::EventType_Type val)
{
	std::string str_val = "";

	if ( val == Read_EventType_Type) str_val = "Read";
	else if ( val == Write_EventType_Type) str_val = "Write";
	else if ( val == Except_EventType_Type) str_val = "Except";
	else if ( val == Accept_EventType_Type) str_val = "Accept";
	else if ( val == Connect_EventType_Type) str_val = "Connect";
	else throw("None of the possible items");

	FCOImpl::getAttribute("EventType")->setStringValue( str_val);
}


//********************************************************************************
// getter for role "Handle" among "Handle"s
//********************************************************************************
std::set<Handle> AbstractEventHandlerImpl::getHandle()
{
	std::set<Handle> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Handle");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Handle elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// returns src End_Pointss
//********************************************************************************
std::multiset<End_Points> Acceptor_PatternImpl::getEnd_Point_ConnectionSrcs()
{
	std::multiset<End_Points> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = getInConnEnds("End_Point_Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			End_Points dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<End_Point_Connection> Acceptor_PatternImpl::getInEnd_Point_ConnectionLinks()
{
	std::set<End_Point_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		End_Point_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<Reactor_Acceptor_Connection> Acceptor_PatternImpl::getInReactor_Acceptor_ConnectionLinks()
{
	std::set<Reactor_Acceptor_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Reactor_Acceptor_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src Reactor_Patterns
//********************************************************************************
std::multiset<Reactor_Pattern> Acceptor_PatternImpl::getReactor_Acceptor_ConnectionSrcs()
{
	std::multiset<Reactor_Pattern> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = getInConnEnds("Reactor_Acceptor_Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Reactor_Pattern dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "Atom" among "Atom"s
//********************************************************************************
std::set<Atom> Acceptor_PatternImpl::getAtom()
{
	std::set<Atom> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Atom");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Atom elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Acceptor_Pattern" among "Acceptor_Pattern"s
//********************************************************************************
std::set<Acceptor_Pattern> MiddlewareImpl::getAcceptor_Pattern()
{
	std::set<Acceptor_Pattern> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Acceptor_Pattern");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Acceptor_Pattern elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Active_Object_Map_Size" among "Active_Object_Map_Size"s
//********************************************************************************
std::set<Active_Object_Map_Size> MiddlewareImpl::getActive_Object_Map_Size()
{
	std::set<Active_Object_Map_Size> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Active_Object_Map_Size");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Active_Object_Map_Size elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Concurrency" among "Concurrency"s
//********************************************************************************
std::set<Concurrency> MiddlewareImpl::getConcurrency()
{
	std::set<Concurrency> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Concurrency");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Concurrency elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "End_Point_Connection" among "End_Point_Connection"s
//********************************************************************************
std::set<End_Point_Connection> MiddlewareImpl::getEnd_Point_Connection()
{
	std::set<End_Point_Connection> res;
	std::set<BON::FCO> roles = getChildFCOsAs("End_Point_Connection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		End_Point_Connection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "End_Points" among "End_Points"s
//********************************************************************************
std::set<End_Points> MiddlewareImpl::getEnd_Points()
{
	std::set<End_Points> res;
	std::set<BON::FCO> roles = getChildFCOsAs("End_Points");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		End_Points elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Reactor_Acceptor_Connection" among "Reactor_Acceptor_Connection"s
//********************************************************************************
std::set<Reactor_Acceptor_Connection> MiddlewareImpl::getReactor_Acceptor_Connection()
{
	std::set<Reactor_Acceptor_Connection> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Reactor_Acceptor_Connection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Reactor_Acceptor_Connection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Reactor_Concurrency_Connection" among "Reactor_Concurrency_Connection"s
//********************************************************************************
std::set<Reactor_Concurrency_Connection> MiddlewareImpl::getReactor_Concurrency_Connection()
{
	std::set<Reactor_Concurrency_Connection> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Reactor_Concurrency_Connection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Reactor_Concurrency_Connection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Reactor_Pattern" among "Reactor_Pattern"s
//********************************************************************************
std::set<Reactor_Pattern> MiddlewareImpl::getReactor_Pattern()
{
	std::set<Reactor_Pattern> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Reactor_Pattern");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Reactor_Pattern elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Reactor_Thread_Queue_Connection" among "Reactor_Thread_Queue_Connection"s
//********************************************************************************
std::set<Reactor_Thread_Queue_Connection> MiddlewareImpl::getReactor_Thread_Queue_Connection()
{
	std::set<Reactor_Thread_Queue_Connection> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Reactor_Thread_Queue_Connection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Reactor_Thread_Queue_Connection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Reactor_Type" among "Reactor_Type"s
//********************************************************************************
std::set<Reactor_Type> MiddlewareImpl::getReactor_Type()
{
	std::set<Reactor_Type> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Reactor_Type");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Reactor_Type elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Reactor_Type_Connection" among "Reactor_Type_Connection"s
//********************************************************************************
std::set<Reactor_Type_Connection> MiddlewareImpl::getReactor_Type_Connection()
{
	std::set<Reactor_Type_Connection> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Reactor_Type_Connection");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Reactor_Type_Connection elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Thread_Queue" among "Thread_Queue"s
//********************************************************************************
std::set<Thread_Queue> MiddlewareImpl::getThread_Queue()
{
	std::set<Thread_Queue> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Thread_Queue");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Thread_Queue elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<Reactor_Concurrency_Connection> Reactor_PatternImpl::getInReactor_Concurrency_ConnectionLinks()
{
	std::set<Reactor_Concurrency_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Reactor_Concurrency_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<Reactor_Thread_Queue_Connection> Reactor_PatternImpl::getInReactor_Thread_Queue_ConnectionLinks()
{
	std::set<Reactor_Thread_Queue_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Reactor_Thread_Queue_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<Reactor_Type_Connection> Reactor_PatternImpl::getInReactor_Type_ConnectionLinks()
{
	std::set<Reactor_Type_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Reactor_Type_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<Reactor_Acceptor_Connection> Reactor_PatternImpl::getOutReactor_Acceptor_ConnectionLinks()
{
	std::set<Reactor_Acceptor_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Reactor_Acceptor_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst Acceptor_Patterns
//********************************************************************************
std::multiset<Acceptor_Pattern> Reactor_PatternImpl::getReactor_Acceptor_ConnectionDsts()
{
	std::multiset<Acceptor_Pattern> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = getOutConnEnds("Reactor_Acceptor_Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Acceptor_Pattern dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src Concurrencys
//********************************************************************************
std::multiset<Concurrency> Reactor_PatternImpl::getReactor_Concurrency_ConnectionSrcs()
{
	std::multiset<Concurrency> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = getInConnEnds("Reactor_Concurrency_Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Concurrency dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src Thread_Queues
//********************************************************************************
std::multiset<Thread_Queue> Reactor_PatternImpl::getReactor_Thread_Queue_ConnectionSrcs()
{
	std::multiset<Thread_Queue> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = getInConnEnds("Reactor_Thread_Queue_Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Thread_Queue dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src Reactor_Types
//********************************************************************************
std::multiset<Reactor_Type> Reactor_PatternImpl::getReactor_Type_ConnectionSrcs()
{
	std::multiset<Reactor_Type> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = getInConnEnds("Reactor_Type_Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Reactor_Type dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// getter for role "Dispatches" among "Dispatches"s
//********************************************************************************
std::set<Dispatches> Reactor_PatternImpl::getDispatches()
{
	std::set<Dispatches> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Dispatches");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Dispatches elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "EventHandler" among "AbstractEventHandler"s
//********************************************************************************
std::set<EventHandler> Reactor_PatternImpl::getEventHandler()
{
	std::set<EventHandler> res;
	std::set<BON::FCO> roles = getChildFCOsAs("EventHandler");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		EventHandler elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Notifies" among "Notifies"s
//********************************************************************************
std::set<Notifies> Reactor_PatternImpl::getNotifies()
{
	std::set<Notifies> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Notifies");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Notifies elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Reactor" among "Reactor"s
//********************************************************************************
std::set<Reactor> Reactor_PatternImpl::getReactor()
{
	std::set<Reactor> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Reactor");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Reactor elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "SynchronousEventDemultiplexer" among "SynchronousEventDemultiplexer"s
//********************************************************************************
std::set<SynchronousEventDemultiplexer> Reactor_PatternImpl::getSynchronousEventDemultiplexer()
{
	std::set<SynchronousEventDemultiplexer> res;
	std::set<BON::FCO> roles = getChildFCOsAs("SynchronousEventDemultiplexer");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		SynchronousEventDemultiplexer elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Uses" among "Uses"s
//********************************************************************************
std::set<Uses> Reactor_PatternImpl::getUses()
{
	std::set<Uses> res;
	std::set<BON::FCO> roles = getChildFCOsAs("Uses");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		Uses elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
long Active_Object_Map_SizeImpl::getValue()
{
	return FCOImpl::getAttribute("Value")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
void Active_Object_Map_SizeImpl::setValue( const long val)
{
	FCOImpl::getAttribute("Value")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
std::set<Reactor_Concurrency_Connection> ConcurrencyImpl::getOutReactor_Concurrency_ConnectionLinks()
{
	std::set<Reactor_Concurrency_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Reactor_Concurrency_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst Reactor_Patterns
//********************************************************************************
std::multiset<Reactor_Pattern> ConcurrencyImpl::getReactor_Concurrency_ConnectionDsts()
{
	std::multiset<Reactor_Pattern> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = getOutConnEnds("Reactor_Concurrency_Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Reactor_Pattern dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
ConcurrencyImpl::Concurrency_Options_Type ConcurrencyImpl::getConcurrency_Options()
{
	std::string val = FCOImpl::getAttribute("Concurrency_Options")->getStringValue();

	if ( val == "reactive") return reactive_Concurrency_Options_Type;
	else if ( val == "thread_per_connection") return thread_per_connection_Concurrency_Options_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
void ConcurrencyImpl::setConcurrency_Options( ConcurrencyImpl::Concurrency_Options_Type val)
{
	std::string str_val = "";

	if ( val == reactive_Concurrency_Options_Type) str_val = "reactive";
	else if ( val == thread_per_connection_Concurrency_Options_Type) str_val = "thread_per_connection";
	else throw("None of the possible items");

	FCOImpl::getAttribute("Concurrency_Options")->setStringValue( str_val);
}


//********************************************************************************
// returns dst Acceptor_Patterns
//********************************************************************************
std::multiset<Acceptor_Pattern> End_PointsImpl::getEnd_Point_ConnectionDsts()
{
	std::multiset<Acceptor_Pattern> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = getOutConnEnds("End_Point_Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Acceptor_Pattern dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<End_Point_Connection> End_PointsImpl::getOutEnd_Point_ConnectionLinks()
{
	std::set<End_Point_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		End_Point_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
long End_PointsImpl::getPorts()
{
	return FCOImpl::getAttribute("Ports")->getIntegerValue();
}


//********************************************************************************
//
//********************************************************************************
void End_PointsImpl::setPorts( const long val)
{
	FCOImpl::getAttribute("Ports")->setIntegerValue( val);
}


//********************************************************************************
//
//********************************************************************************
std::set<Notifies> HandleImpl::getInNotifiesLinks()
{
	std::set<Notifies> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Notifies c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src SynchronousEventDemultiplexers
//********************************************************************************
std::multiset<SynchronousEventDemultiplexer> HandleImpl::getNotifiesSrcs()
{
	std::multiset<SynchronousEventDemultiplexer> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = getInConnEnds("Notifies");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			SynchronousEventDemultiplexer dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::string HandleImpl::getHandleName()
{
	return FCOImpl::getAttribute("HandleName")->getStringValue();
}


//********************************************************************************
//
//********************************************************************************
bool HandleImpl::isready()
{
	return FCOImpl::getAttribute("ready")->getBooleanValue();
}


//********************************************************************************
//
//********************************************************************************
void HandleImpl::setHandleName( const std::string& val)
{
	FCOImpl::getAttribute("HandleName")->setStringValue( val);
}


//********************************************************************************
//
//********************************************************************************
void HandleImpl::setready( bool val)
{
	FCOImpl::getAttribute("ready")->setBooleanValue( val);
}


//********************************************************************************
// returns dst AbstractEventHandlers
//********************************************************************************
std::multiset<AbstractEventHandler> ReactorImpl::getDispatchesDsts()
{
	std::multiset<AbstractEventHandler> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = getOutConnEnds("Dispatches");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			AbstractEventHandler dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<Dispatches> ReactorImpl::getOutDispatchesLinks()
{
	std::set<Dispatches> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Dispatches c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
//
//********************************************************************************
std::set<Uses> ReactorImpl::getOutUsesLinks()
{
	std::set<Uses> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Uses c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst SynchronousEventDemultiplexers
//********************************************************************************
std::multiset<SynchronousEventDemultiplexer> ReactorImpl::getUsesDsts()
{
	std::multiset<SynchronousEventDemultiplexer> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = getOutConnEnds("Uses");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			SynchronousEventDemultiplexer dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<Reactor_Type_Connection> Reactor_TypeImpl::getOutReactor_Type_ConnectionLinks()
{
	std::set<Reactor_Type_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Reactor_Type_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst Reactor_Patterns
//********************************************************************************
std::multiset<Reactor_Pattern> Reactor_TypeImpl::getReactor_Type_ConnectionDsts()
{
	std::multiset<Reactor_Pattern> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = getOutConnEnds("Reactor_Type_Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Reactor_Pattern dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
Reactor_TypeImpl::Reactor_Type_Options_Type Reactor_TypeImpl::getReactor_Type_Options()
{
	std::string val = FCOImpl::getAttribute("Reactor_Type_Options")->getStringValue();

	if ( val == "select_mt") return select_mt_Reactor_Type_Options_Type;
	else if ( val == "select_st") return select_st_Reactor_Type_Options_Type;
	else if ( val == "wfmo") return wfmo_Reactor_Type_Options_Type;
	else if ( val == "msg_wfmo") return msg_wfmo_Reactor_Type_Options_Type;
	else if ( val == "tp") return tp_Reactor_Type_Options_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
void Reactor_TypeImpl::setReactor_Type_Options( Reactor_TypeImpl::Reactor_Type_Options_Type val)
{
	std::string str_val = "";

	if ( val == select_mt_Reactor_Type_Options_Type) str_val = "select_mt";
	else if ( val == select_st_Reactor_Type_Options_Type) str_val = "select_st";
	else if ( val == wfmo_Reactor_Type_Options_Type) str_val = "wfmo";
	else if ( val == msg_wfmo_Reactor_Type_Options_Type) str_val = "msg_wfmo";
	else if ( val == tp_Reactor_Type_Options_Type) str_val = "tp";
	else throw("None of the possible items");

	FCOImpl::getAttribute("Reactor_Type_Options")->setStringValue( str_val);
}


//********************************************************************************
//
//********************************************************************************
std::set<Uses> SynchronousEventDemultiplexerImpl::getInUsesLinks()
{
	std::set<Uses> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Uses c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst Handles
//********************************************************************************
std::multiset<Handle> SynchronousEventDemultiplexerImpl::getNotifiesDsts()
{
	std::multiset<Handle> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = getOutConnEnds("Notifies");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Handle dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
std::set<Notifies> SynchronousEventDemultiplexerImpl::getOutNotifiesLinks()
{
	std::set<Notifies> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Notifies c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src Reactors
//********************************************************************************
std::multiset<Reactor> SynchronousEventDemultiplexerImpl::getUsesSrcs()
{
	std::multiset<Reactor> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = getInConnEnds("Uses");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			Reactor dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
SynchronousEventDemultiplexerImpl::DemultiplexerType_Type SynchronousEventDemultiplexerImpl::getDemultiplexerType()
{
	std::string val = FCOImpl::getAttribute("DemultiplexerType")->getStringValue();

	if ( val == "select()") return select___DemultiplexerType_Type;
	else if ( val == "WaitForMultipleObjects()") return WaitForMultipleObjects___DemultiplexerType_Type;
	else if ( val == "poll()") return poll___DemultiplexerType_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
void SynchronousEventDemultiplexerImpl::setDemultiplexerType( SynchronousEventDemultiplexerImpl::DemultiplexerType_Type val)
{
	std::string str_val = "";

	if ( val == select___DemultiplexerType_Type) str_val = "select()";
	else if ( val == WaitForMultipleObjects___DemultiplexerType_Type) str_val = "WaitForMultipleObjects()";
	else if ( val == poll___DemultiplexerType_Type) str_val = "poll()";
	else throw("None of the possible items");

	FCOImpl::getAttribute("DemultiplexerType")->setStringValue( str_val);
}


//********************************************************************************
//
//********************************************************************************
std::set<Reactor_Thread_Queue_Connection> Thread_QueueImpl::getOutReactor_Thread_Queue_ConnectionLinks()
{
	std::set<Reactor_Thread_Queue_Connection> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		Reactor_Thread_Queue_Connection c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst Reactor_Patterns
//********************************************************************************
std::multiset<Reactor_Pattern> Thread_QueueImpl::getReactor_Thread_Queue_ConnectionDsts()
{
	std::multiset<Reactor_Pattern> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = getOutConnEnds("Reactor_Thread_Queue_Connection");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			Reactor_Pattern dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
//
//********************************************************************************
Thread_QueueImpl::Thread_Queue_Options_Type Thread_QueueImpl::getThread_Queue_Options()
{
	std::string val = FCOImpl::getAttribute("Thread_Queue_Options")->getStringValue();

	if ( val == "LIFO") return LIFO_Thread_Queue_Options_Type;
	else if ( val == "FIFO") return FIFO_Thread_Queue_Options_Type;
	else throw("None of the possible items");
}


//********************************************************************************
//
//********************************************************************************
void Thread_QueueImpl::setThread_Queue_Options( Thread_QueueImpl::Thread_Queue_Options_Type val)
{
	std::string str_val = "";

	if ( val == LIFO_Thread_Queue_Options_Type) str_val = "LIFO";
	else if ( val == FIFO_Thread_Queue_Options_Type) str_val = "FIFO";
	else throw("None of the possible items");

	FCOImpl::getAttribute("Thread_Queue_Options")->setStringValue( str_val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to AbstractEventHandler
//********************************************************************************
AbstractEventHandler DispatchesImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	AbstractEventHandler sp( ce);
	if ( sp)
		return sp;

	AbstractEventHandler empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Reactor
//********************************************************************************
Reactor DispatchesImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Reactor sp( ce);
	if ( sp)
		return sp;

	Reactor empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Acceptor_Pattern
//********************************************************************************
Acceptor_Pattern End_Point_ConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Acceptor_Pattern sp( ce);
	if ( sp)
		return sp;

	Acceptor_Pattern empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to End_Points
//********************************************************************************
End_Points End_Point_ConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	End_Points sp( ce);
	if ( sp)
		return sp;

	End_Points empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Handle
//********************************************************************************
Handle NotifiesImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Handle sp( ce);
	if ( sp)
		return sp;

	Handle empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to SynchronousEventDemultiplexer
//********************************************************************************
SynchronousEventDemultiplexer NotifiesImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	SynchronousEventDemultiplexer sp( ce);
	if ( sp)
		return sp;

	SynchronousEventDemultiplexer empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Acceptor_Pattern
//********************************************************************************
Acceptor_Pattern Reactor_Acceptor_ConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Acceptor_Pattern sp( ce);
	if ( sp)
		return sp;

	Acceptor_Pattern empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Reactor_Pattern
//********************************************************************************
Reactor_Pattern Reactor_Acceptor_ConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Reactor_Pattern sp( ce);
	if ( sp)
		return sp;

	Reactor_Pattern empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Reactor_Pattern
//********************************************************************************
Reactor_Pattern Reactor_Concurrency_ConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Reactor_Pattern sp( ce);
	if ( sp)
		return sp;

	Reactor_Pattern empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Concurrency
//********************************************************************************
Concurrency Reactor_Concurrency_ConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Concurrency sp( ce);
	if ( sp)
		return sp;

	Concurrency empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Reactor_Pattern
//********************************************************************************
Reactor_Pattern Reactor_Thread_Queue_ConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Reactor_Pattern sp( ce);
	if ( sp)
		return sp;

	Reactor_Pattern empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Thread_Queue
//********************************************************************************
Thread_Queue Reactor_Thread_Queue_ConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Thread_Queue sp( ce);
	if ( sp)
		return sp;

	Thread_Queue empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to Reactor_Pattern
//********************************************************************************
Reactor_Pattern Reactor_Type_ConnectionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	Reactor_Pattern sp( ce);
	if ( sp)
		return sp;

	Reactor_Pattern empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Reactor_Type
//********************************************************************************
Reactor_Type Reactor_Type_ConnectionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Reactor_Type sp( ce);
	if ( sp)
		return sp;

	Reactor_Type empty;
	return empty;
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to SynchronousEventDemultiplexer
//********************************************************************************
SynchronousEventDemultiplexer UsesImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	SynchronousEventDemultiplexer sp( ce);
	if ( sp)
		return sp;

	SynchronousEventDemultiplexer empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to Reactor
//********************************************************************************
Reactor UsesImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	Reactor sp( ce);
	if ( sp)
		return sp;

	Reactor empty;
	return empty;
}



}; // namespace CMML_BON

