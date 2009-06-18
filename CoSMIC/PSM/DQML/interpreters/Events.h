//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	Events.h
//
//###############################################################################################################################################

/*
	Copyright (c) Vanderbilt University, 2000-2004
	ALL RIGHTS RESERVED

	Vanderbilt University disclaims all warranties with regard to this
	software, including all implied warranties of merchantability
	and fitness.  In no event shall Vanderbilt University be liable for
	any special, indirect or consequential damages or any damages
	whatsoever resulting from loss of use, data or profits, whether
	in an action of contract, negligence or other tortious action,
	arising out of or in connection with the use or performance of
	this software.
*/

#ifndef Events_h
#define Events_h

#include "MON.h"
#include "BON.h"

namespace BON
{

//###############################################################################################################################################
//
// 	C L A S S : BON::Event
//
//###############################################################################################################################################

	class Event
	{
		// Member Variables
		private :
			MON::ObjectEventType	m_eType;
			Object						m_context;

		// Construction and Destruction
		public :
			Event( MON::ObjectEventType eType, const Object& context );
			Event( const Event& event );
			Event& operator = ( const Event& event );
		public :
			virtual ~Event() { }

		// Get Operations
		public :
			MON::ObjectEventType	getType() const;
			Object		 				getContext() const;
			std::string					getInfoString( Util::InfoOptions usOptions = Util::IO_None ) const;
			std::string					getInfoString( std::set<Util::InfoOption> setOptions ) const;
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::EventListener
//
//###############################################################################################################################################

	class EventListener
	{
		// Construction and Destruction
		public :
			EventListener()
			{
			}

			virtual ~EventListener()
			{
			}

		// Interface
		public :
			virtual void eventPerformed( const Event& event )
			{
			}

			virtual MON::ObjectEventTypes getAssignments() const
			{
				return MON::OET_None;
			}

			virtual bool isActive() const
			{
				return true;
			}
	};

//###############################################################################################################################################
//
// 	C L A S S : BON::EventListenerPool
//
//###############################################################################################################################################

	class EventListenerPool
	{
		// Type definitions
		private :
			typedef std::vector<EventListener*> 							ListenerVector;
			typedef std::map<MON::ObjectEventType,ListenerVector>	ListenerMap;

		// Member Variables
		private :
			ListenerMap m_mapListeners;

		// Construction and Destruction
		public :
			EventListenerPool()
			{
			}

			virtual ~EventListenerPool()
			{
			}

		// Interface
		public :
			void performEvent( const Event& event );

			void addListener( EventListener* pListener );
			void removeListener( EventListener* pListener );

	};

}; // namespace BON

#endif Events_h