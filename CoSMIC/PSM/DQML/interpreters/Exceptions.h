//###############################################################################################################################################
//
//	Builder and Meta Object Network V2.0 for GME
//	Exceptions.h
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

#ifndef Exceptions_h
#define Exceptions_h

#pragma warning( disable : 4786 )
#pragma warning( disable : 4018 )

#include <StdAfx.h>
#include <string>
#include <vector>

#define ASSERTTHROW( exc )									\
	{																\
		ASSERT( ( exc.getErrorMessage().c_str(), false ) );		\
		throw	exc;												\
	}

#undef COMTHROW
#define COMTHROW( expr )														\
	{																				\
		HRESULT hResult = expr;													\
		if ( FAILED( hResult ) )													\
			ASSERTTHROW( BON::Exception( hResult, "COMException" ) );		\
	}

namespace Util
{
	class Exception;

	typedef std::vector<std::string>	StringVector;

//###############################################################################################################################################
//
// 	C L A S S : Util::Exception
//
//###############################################################################################################################################

	class Exception
		// : public exception
	{
		// Constants
		public :
			static const char PM_CHAR;
			static const char PM_STRING;
			static const char PM_INTEGER;
			static const char PM_LONG;
			static const char PM_FLOAT;
			static const char PM_DOUBLE;

		// Member Variables
		private :
			std::string					m_strMessage;
			StringVector				m_vecParameters;

		// Construction and Destruction
		public :
			Exception();
			//Exception( std::string strMessage);//, std::string strFormat, ... );

			Exception( std::string strMessage, const StringVector& vecParemeters = StringVector() );
			Exception( const Exception& ex );
			virtual ~Exception() { }

		// Get and Set operations
		public :
			Exception& operator << ( char pchar);
			Exception& operator << ( int  pint);
			Exception& operator << ( long plong);
			Exception& operator << ( const std::string& pstr);
			Exception& operator << ( float pfloat);
			Exception& operator << ( double pdoub);
			std::string	getErrorMessage( bool bSubstitute = true ) const;
			std::string	getParameter( int iPos ) const;
			int			getParameterCount() const;
			virtual std::string getKind() const;

		protected :
			void addParameter( const std::string& strParameter );
	};

}; // namespace Util

namespace BON
{
	class Exception;

	typedef std::vector<std::string>	StringVector;

//###############################################################################################################################################
//
//	C L A S S : BON::Exception <<< Util::Exception
//
//###############################################################################################################################################

	class Exception
		: public Util::Exception
	{
		// Member Variables
		private :
			HRESULT	m_hResult;

		// Construction and Destruction
		public :
			Exception( HRESULT hResult );
			//Exception( HRESULT hResult, std::string strMessage, std::string strFormat, ... );
			Exception( HRESULT hResult, std::string strMessage, const StringVector& vecParemeters = StringVector() );
			//Exception( std::string strMessage, std::string strFormat, ... );
			Exception( std::string strMessage, const StringVector& vecParemeters = StringVector() );
			Exception( const Exception& ex );
			virtual ~Exception() { }

		// Get and Set operations
		public :
			HRESULT 	getHResult() const;
			std::string getKind() const;
	};

}; // namespace BON

namespace MON
{
	class Exception;

	typedef std::vector<std::string>	StringVector;

//###############################################################################################################################################
//
//	C L A S S : MON::Exception <<< Util::Exception
//
//###############################################################################################################################################

	class Exception
		: public Util::Exception
	{
		// Member Variables
		private :
			HRESULT	m_hResult;

		// Construction and Destruction
		public :
			Exception( HRESULT hResult );
			//Exception( HRESULT hResult, std::string strMessage, std::string strFormat, ... );
			Exception( HRESULT hResult, std::string strMessage, const StringVector& vecParemeters = StringVector() );
			//Exception( std::string strMessage, std::string strFormat, ... );
			Exception( std::string strMessage, const StringVector& vecParemeters = StringVector() );
			Exception( const Exception& ex );
			virtual ~Exception() { }

		// Get and Set
		public :
			HRESULT 	getHResult() const;
			std::string getKind() const;
	};

}; // namespace MON

#endif // Exceptions_h