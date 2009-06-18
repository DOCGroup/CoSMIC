//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	Events.cpp
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

#pragma warning( disable : 4786 )

#include "stdafx.h"
#include "Events.h"
#include "BONImpl.h"
#include <algorithm> // needed for vc7 if used with its own stl
namespace BON
{

//###############################################################################################################################################
//
// 	C L A S S : BON::Event
//
//###############################################################################################################################################

	Event::Event( MON::ObjectEventType eType, const Object& context )
		: m_eType( eType ), m_context( context )
	{
	}

	Event::Event( const Event& event )
		: m_eType( event.m_eType ), m_context( event.m_context )
	{
	}

	Event& Event::operator = ( const Event& event )
	{
		if ( this != &event ) {
			m_eType = event.m_eType;
			m_context = event.m_context;
		}
		return *this;
	}

	MON::ObjectEventType Event::getType() const
	{
		return m_eType;
	}

	Object Event::getContext() const
	{
		return m_context;
	}

	std::string Event::getInfoString( Util::InfoOptions usOptions ) const
	{
		return toString( m_eType ) + "\n\n" + m_context->getInfoString( usOptions );
	}

	std::string	Event::getInfoString( std::set<Util::InfoOption> setOptions ) const
	{
		return getInfoString( copy( setOptions ) );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::EventListenerPool
//
//###############################################################################################################################################

	void EventListenerPool::performEvent( const Event& event )
	{
		ListenerMap::iterator it = m_mapListeners.find( event.getType() );
		if ( it != m_mapListeners.end() ) {
			for ( int i = 0 ; i < it->second.size() ; i++ )
				if ( it->second[ i ]->isActive() )
					it->second[ i ]->eventPerformed( event );
		}
	}

	void EventListenerPool::addListener( EventListener* pListener )
	{
		if ( pListener ) {
			for ( MON::ObjectEventType eType = MON::OET_ObjectCreated ; eType != MON::OET_All ; eType++ ) {
				if ( pListener->getAssignments() & eType ) {
					ListenerMap::iterator it = m_mapListeners.find( eType );
					if ( it == m_mapListeners.end() )
						m_mapListeners[ eType ] = ListenerVector( 1, pListener );
					else
						if ( std::find( m_mapListeners[ eType ].begin(), m_mapListeners[ eType ].end(), pListener ) == m_mapListeners[ eType ].end() )
							m_mapListeners[ eType ].push_back( pListener );
				}
			}
		}
	}

	void EventListenerPool::removeListener( EventListener* pListener )
	{
		if ( pListener ) {
			for ( ListenerMap::iterator it = m_mapListeners.begin() ; it != m_mapListeners.end() ; it++ ) {
				ListenerVector::iterator itv = std::find( it->second.begin(), it->second.end(), pListener );
				if ( itv != it->second.end() )
					it->second.erase( itv );
			}
		}
	}

}; // namespace BON