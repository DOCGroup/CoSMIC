//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	Utils.h
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

#ifndef Utils_h
#define Utils_h

#pragma warning( disable : 4786 )

#include "StdAfx.h"
#include <string>
#include <vector>
#include <set>
#include "Exceptions.h"

namespace Util
{
	template< class T > class ComPtr;
	class GenRefCounted;
	class GenRefCounter;
	class Variant;

//###############################################################################################################################################
//
// 	F U N C T I O N S
//
//###############################################################################################################################################

	CComBSTR	Copy( const std::string& str );
	std::string	Copy( const CComBSTR& bstr );

//###############################################################################################################################################
//
// 	E N U M E R A T I O N : Util::InfoOption
//
//###############################################################################################################################################

	enum InfoOption
	{
		IO_None = 0x00,
		IO_Identifiers = 0x01,
		IO_ID = 0x02,
		IO_Meta = 0x04,
		IO_Path = 0x08,
		IO_Specific = 0x10,
		IO_NewLine = 0x20,
		IO_All = 0xFF
	};

	typedef unsigned short InfoOptions;

//###############################################################################################################################################
//
// 	C L A S S : Util::ComPtr
//
//###############################################################################################################################################

	template< class T >
	class ComPtr
	{
		// Member Variables
		public :
			T* p;

		// Construction and Destruction
		public :
			ComPtr()
			{
				p = NULL;
			}

			ComPtr( T* q )
			{
				if ( ( p = q ) != NULL )
					q->AddRef();
			}

			ComPtr( const ComPtr<T>& q )
			{
				if ( ( p = q.p ) != NULL )
					p->AddRef();
			}

			ComPtr( const CComPtr<T>& q )
			{
				if ( ( p = q.p ) != NULL )
					p->AddRef();
			}

			~ComPtr()
			{
				Release();
			}

			void Release()
			{
				if ( p ) {
					p->Release();
					p = NULL;
				}
			}

		// Operators
		public :
			operator CComPtr<T> () const
			{
				return CComPtr<T>( p );
			}

			operator T* () const
			{
				return p;
			}

			operator bool () const
			{
				return p != NULL;
			}

			bool operator ! () const
			{
				return p == NULL;
			}

			T& operator * () const
			{
				ASSERT( p != NULL );
				return *p;
			}

			T* operator -> () const
			{
				ASSERT( p != NULL );
				return p;
			}

			T* operator = ( T* q )
			{
				if ( q )
					q->AddRef();
				if ( p )
					p->Release();
				return p = q;
			}

			T* operator = ( const ComPtr<T>& q )
			{
				return operator=( q.p );
			}

			T* operator = ( const CComPtr<T>& q )
			{
				return operator=( q.p );
			}

			bool operator == ( T* q ) const
			{
				return p == q;
			}

			bool operator != ( T* q ) const
			{
				return p != q;
			}

			bool operator < ( T* q ) const
			{
				return p < q;
			}

		// Pointer Managing
		public :
			T** Addr()
			{
//				ASSERT( p != NULL );
				return &p;
			}

			T* Detach()
			{
				T* r = p;
				p = NULL;
				return r;
			}

			void Attach( T* q )
			{
				if ( p )
					p->Release();
				p = q;
			}

		// Interface Methods
		public :
			template<class Q> HRESULT QueryInterface( ComPtr<Q> &q ) const
			{
				ASSERT( p != NULL && q == NULL );
				return p->QueryInterface( __uuidof( Q ), (void**) &q.p );
			}

			HRESULT CoCreateInstance( REFCLSID rclsid, LPUNKNOWN pUnkOuter = NULL, DWORD dwClsContext = CLSCTX_ALL )
			{
				ASSERT( p == NULL );
				return ::CoCreateInstance( rclsid, pUnkOuter, dwClsContext, __uuidof( T ), (void**) &p );
			}

			HRESULT CoCreateInstance( LPCOLESTR szProgID, LPUNKNOWN pUnkOuter = NULL, DWORD dwClsContext = CLSCTX_ALL )
			{
				CLSID clsid;
				HRESULT hr = CLSIDFromProgID( szProgID, &clsid );
				ASSERT( p == NULL );
				if ( SUCCEEDED( hr ) )
					hr = ::CoCreateInstance( clsid, pUnkOuter, dwClsContext, __uuidof( T ), (void**) &p );
				return hr;
			}
	};

// WARNING : Must be Removed

template < class t >
class SmartMultiPtr {
	CComPtr< t > *m_ptr;
public:
	SmartMultiPtr(CComPtr< t > *x) : m_ptr(x) { ; }
	~SmartMultiPtr() { delete[] m_ptr; }
	operator CComPtr< t > *() { return m_ptr; }
	t **operator &() { return &(m_ptr[0]); }
};

#define MGACOLL_ITERATE(iftype, collifptr) \
{ \
	ASSERT( collifptr != NULL ); \
	long iter_count = 0; \
	COMTHROW( collifptr->get_Count(&iter_count) ); \
	ASSERT( iter_count >= 0 ); \
	CComPtr<iftype> *arrptr, *arrend, *array = new CComPtr<iftype>[iter_count]; \
	if(iter_count > 0) \
		COMTHROW( collifptr->GetAll(iter_count, &(*array)) ); \
	arrend = array+iter_count; \
	for(arrptr = array; arrptr != arrend; arrptr++)

#define MGACOLL_ITER (*arrptr)

#define MGACOLL_AT_END (arrptr == arrend)

#define MGACOLL_ITERATE_END \
	delete[] array; \
}

//###############################################################################################################################################
//
// 	C L A S S :  Util::Variant
//
//###############################################################################################################################################

	class Variant
	{
		// Type Definitions
		public :
			typedef enum {
				VT_Boolean = 0,
				VT_Integer,
				VT_Double,
				VT_String
			} Type;

			typedef union {
				bool 			bVal;
				long			lVal;
				double			dVal;
				std::string*	pstrVal;
			} Value;

		// Member Variables
		private :
			bool	m_bUndefined;
			Type	m_eType;
			Value	m_uValue;

		// Construction and Destruction
		public :
			Variant();
			Variant( bool bValue );
			Variant( long lValue );
			Variant( double dValue );
			Variant( const std::string& strValue );
			Variant( const Variant& vValue );
			~Variant();

		// Get and Set operations
		public :
			Type 	type() const;
			bool	isUndefined() const;

		// Operators
		public :
			Variant& operator=( const Variant& vValue );
			operator bool () const;
			operator long () const;
			operator double () const;
			operator std::string () const;
	};

//###############################################################################################################################################
//
// 	C L A S S : Util::GenRefCounted
//
//###############################################################################################################################################

class GenRefCounted
{
	// Member Variables
	private :
		unsigned long 					m_ulRefCount;
		unsigned long					m_ulAggrRefCount;
		std::set<GenRefCounted*> 	m_setAggregators;
		bool							m_bDisposable;
		bool							m_bDeleted;

	// Construction and Destruction
	protected :
		GenRefCounted( bool bDisposable = true, GenRefCounted* pAggregator = NULL )
			: m_ulRefCount( 0 ), m_ulAggrRefCount( 0 ), m_bDisposable( bDisposable ), m_bDeleted( false )
		{
			if ( pAggregator )
				m_setAggregators.insert( pAggregator );
		}

		GenRefCounted( bool bDisposable, GenRefCounted* pAggregator1, GenRefCounted* pAggregator2 )
			: m_ulRefCount( 0 ), m_ulAggrRefCount( 0 ), m_bDisposable( bDisposable ), m_bDeleted( false )
		{
			if ( pAggregator1 )
				m_setAggregators.insert( pAggregator1 );
			if ( pAggregator2 )
				m_setAggregators.insert( pAggregator2 );
		}

	public :
		virtual ~GenRefCounted()
		{
			m_setAggregators.clear();
		}

	// Reference Counter Methods
	private :
		void incRef()
		{
			m_ulRefCount++;
			if ( m_ulRefCount == 1 )
				for ( std::set<GenRefCounted*>::iterator it =  m_setAggregators.begin() ; it != m_setAggregators.end() ; it++ )
					(*it)->incAggrRef();
		}

		bool decRef()
		{
			m_ulRefCount--;
			return doDispose();
		}

		void incAggrRef()
		{
			m_ulAggrRefCount++;
		}

		void decAggrRef()
		{
			m_ulAggrRefCount--;
			if (doDispose()) {
				// VOLGY: Dangerous: what if the project deletes 
				// itself while the last object destruction is still in progress ? 
				// NEEDS REDISGN 
				delete this;
			}
		}

		bool doDispose()
		{
			if ( m_ulRefCount == 0 && m_ulAggrRefCount == 0 ) {
				for ( std::set<GenRefCounted*>::iterator it =  m_setAggregators.begin() ; it != m_setAggregators.end() ; it++ )
					(*it)->decAggrRef();
				return m_bDeleted || m_bDisposable;
			}
			return false;
		}

	// Get And Set Methods
	protected :
		void setDisposable( bool bDisposable )
		{
			m_bDisposable = bDisposable;
		}

		void setAggregators( const std::set<GenRefCounted*>& setAggregators )
		{
			m_setAggregators = setAggregators;
		}

	public :
		bool isDeleted() const
		{
			return m_bDeleted;
		}

		virtual bool setDeleted()
		{
			if ( m_bDeleted )
				return true;
			m_bDeleted = true;
			return false;
		}

		bool isDisposable() const
		{
			return m_bDisposable;
		}

	// Friends
		friend GenRefCounter;
};

//###############################################################################################################################################
//
// 	C L A S S : Util::GenRefCounter
//
//###############################################################################################################################################

class GenRefCounter
{
	// Member Variables
	private :
		GenRefCounted* m_refCounted;

	// Construction and Destruction
	protected :
		GenRefCounter()
			: m_refCounted( NULL )
		{
		}

		GenRefCounter( const GenRefCounter& grc )
			: m_refCounted( grc.m_refCounted )
		{
			incRef();
		}

		GenRefCounter( GenRefCounted* pgrc )
			: m_refCounted( pgrc )
		{
			incRef();
		}

		GenRefCounter& operator = ( const GenRefCounter& grc )
		{
			if ( this != &grc )
				setCounted( grc.m_refCounted );
			return *this;
		}

		GenRefCounter& operator = ( GenRefCounted* pgrc )
		{
			setCounted( pgrc );
			return *this;
		}

	public :
		virtual ~GenRefCounter()
		{
			decRef();
		}

	// Operators
	public :
		operator bool () const
		{
			return m_refCounted != NULL;
		}

		bool operator ! () const
		{
			return m_refCounted == NULL;
		}

		bool operator == ( const GenRefCounter& grc ) const
		{
			return m_refCounted == grc.m_refCounted;
		}

		bool operator != ( const GenRefCounter& grc ) const
		{
			return m_refCounted != grc.m_refCounted;
		}

		bool operator < ( const GenRefCounter& grc ) const
		{
			return m_refCounted < grc.m_refCounted;
		}

	// Accessors
	public :
		GenRefCounted* getCounted( bool bThrow = true ) const
		{
			if ( ! m_refCounted && bThrow )
				ASSERTTHROW( Exception( "Object is null" ) );
			return m_refCounted;
		}

	protected :
		void setCounted( GenRefCounted* pgrc )
		{
			if ( pgrc != m_refCounted ) {
				decRef();
				m_refCounted = pgrc;
				incRef();
			}
		}

	// Counter Operations
	private :
		void incRef()
		{
			if  ( m_refCounted )
				m_refCounted->incRef();
		}

		void decRef()
		{
			if ( m_refCounted ) {
				if ( m_refCounted->decRef() ) {
						delete m_refCounted;
				}
				m_refCounted = NULL;
			}
		}
};

}; // namespace Util

	Util::InfoOption& operator ++( Util::InfoOption& eOption, int );
	Util::InfoOption& operator ++( Util::InfoOption& eOption );
	bool isAll( const std::set<Util::InfoOption>&  setOptions );
	bool isNone( const std::set<Util::InfoOption>&  setOptions );
	Util::InfoOptions copy( const std::set<Util::InfoOption>&  setOptions );
	std::set<Util::InfoOption> copy( Util::InfoOptions usOptions );

#endif // Utils_h