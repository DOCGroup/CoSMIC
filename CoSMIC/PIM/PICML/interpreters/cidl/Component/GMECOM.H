#ifndef GMECOM_H
#define GMECOM_H

#include "ComponentLib.h"

// TODO: remove it or replace it with SmartMultiPtr from CommonMgaTrukk.h
template <class TTT>
class COMArray {
public:
	CComPtr<TTT> *array;
	COMArray(long len)  { array = new CComPtr<TTT>[len]; };
	~COMArray() { delete[] array; };
};

#define COM_EQUAL(a, b) (static_cast<IUnknown *>(a) == b ? true : a.IsEqualObject(b))

// from CommonMgaTrukk.h

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

// from CommonError.h

#define COMTHROW(FUNC) \
do { \
	HRESULT _hr = (FUNC); \
	if( FAILED(_hr) ) { \
		ASSERT(("COMTHROW: Throwing HRESULT exception. Press IGNORE", false)); \
		throw _hr; \
	} \
} while(false)

#define COMTRY try

#define COMCATCH(CLEANUP) \
	catch(HRESULT hr) \
	{ \
		ASSERT( FAILED(hr) ); \
		{ CLEANUP; } \
		return hr; \
	} \
	return S_OK;

#endif // GMECOM_H
