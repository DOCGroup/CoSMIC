
#ifndef __COMHELP_H
#define __COMHELP_H

#ifndef __AFXTEMPL_H__
#include <afxtempl.h>
#endif

#ifndef __unknwn_h__
#include <unknwn.h>
#endif

// --------------------------- MACROS

inline void COMVERIFY(HRESULT hr)
{
	VERIFY(SUCCEEDED(hr));
}

inline void COMASSERT(HRESULT hr)
{
	ASSERT(SUCCEEDED(hr));
}

// --------------------------- CBstr

class CBstr
{
public:
	CBstr() : s(NULL) { }
	CBstr(const CString &str) : s(str.AllocSysString()) { }
	~CBstr() { Free(); }

	void operator = (const CString &str) { Free(); s = str.AllocSysString(); }

	void Free() { SysFreeString(s); }

	BSTR Send() { return s; }
	operator BSTR* () { return &s; }
	operator CString () { return s; }

private:
	BSTR s;
};

class CBstrRef
{
public:
	CBstrRef(BSTR str) : s(str) { }

	void operator = (const CString& str) { Free(); s = str.AllocSysString(); }

	void Free() { SysFreeString(s); }

	operator BSTR () { return s; }
	operator CString () { return s; }

private:
	BSTR &s;
};

class CBstrIn
{
public:
	CBstrIn(const CString &str) : s(str.AllocSysString()) { }
	~CBstrIn() { SysFreeString(s); }

	operator BSTR () { return s; }

private:
	BSTR s;
};

// --------------------------- CIUnknownPtrList

class CIUnknownPtrList : public CList<IUnknown*, IUnknown*>
{
public:
	CIUnknownPtrList() { };

	void Load(SAFEARRAY** ppsa);
	void Copy(SAFEARRAY* ppsa);
	SAFEARRAY* Store();

	void AddRefAll();
	void ReleaseAll();
};

// --------------------------- CInterfacePtrList
// ex. CInterfacePtrList<IMgaModel*> icategories(psa);
// ex. CInterfacePtrList<IMgaModel*> icategories(categories);

template<class TYPE>
class CInterfacePtrList : public CIUnknownPtrList
{
public:
	// Construction
	CInterfacePtrList() : CIUnknownPtrList() { };

	template<class SOURCE>
	void AddInterfaces(SOURCE &source)
	{
		POSITION pos = source.GetHeadPosition();
		while(pos)
		{
			TYPE i = source.GetNext(pos)->GetInterface();
			ASSERT(i);
			AddTail(i);
		}
	}

	// peek at head or tail
	TYPE& GetHead()
		{ return (TYPE&)CIUnknownPtrList::GetHead(); }
	TYPE GetHead() const
		{ return (TYPE)CIUnknownPtrList::GetHead(); }
	TYPE& GetTail()
		{ return (TYPE&)CIUnknownPtrList::GetTail(); }
	TYPE GetTail() const
		{ return (TYPE)CIUnknownPtrList::GetTail(); }

	// get head or tail (and remove it) - don't call on empty list!
	TYPE RemoveHead()
		{ return (TYPE)CIUnknownPtrList::RemoveHead(); }
	TYPE RemoveTail()
		{ return (TYPE)CIUnknownPtrList::RemoveTail(); }

	// add before head or after tail
	POSITION AddHead(TYPE newElement)
		{ return CIUnknownPtrList::AddHead(newElement); }
	POSITION AddTail(TYPE newElement)
		{ return CIUnknownPtrList::AddTail(newElement); }

	// add another list of elements before head or after tail
	void AddHead(CInterfacePtrList<TYPE>* pNewList)
		{ CIUnknownPtrList::AddHead(pNewList); }
	void AddTail(CInterfacePtrList<TYPE>* pNewList)
		{ CIUnknownPtrList::AddTail(pNewList); }

	// iteration
	TYPE& GetNext(POSITION& rPosition)
		{ return (TYPE&)CIUnknownPtrList::GetNext(rPosition); }
	TYPE GetNext(POSITION& rPosition) const
		{ return (TYPE)CIUnknownPtrList::GetNext(rPosition); }
	TYPE& GetPrev(POSITION& rPosition)
		{ return (TYPE&)CIUnknownPtrList::GetPrev(rPosition); }
	TYPE GetPrev(POSITION& rPosition) const
		{ return (TYPE)CIUnknownPtrList::GetPrev(rPosition); }

	// getting/modifying an element at a given position
	TYPE& GetAt(POSITION position)
		{ return (TYPE&)CIUnknownPtrList::GetAt(position); }
	TYPE GetAt(POSITION position) const
		{ return (TYPE)CIUnknownPtrList::GetAt(position); }
	void SetAt(POSITION pos, TYPE newElement)
		{ CIUnknownPtrList::SetAt(pos, newElement); }

};

// --------------------------- SafeArray
// ex. CreateSafeArray<IMgaCategory*>(categories);

template<class TYPE, class SOURCE>
SAFEARRAY* CreateInterfaceSafeArray(SOURCE &source)
{
	SAFEARRAY *psa;

	psa = SafeArrayCreateVector(VT_UNKNOWN, 0, source.GetCount());
	ASSERT(psa);

	IUnknown* *p;
	COMVERIFY(SafeArrayAccessData(psa,(void**)&p));

	POSITION pos = source.GetHeadPosition();
	while(pos)
	{
		TYPE i = source.GetNext(pos)->GetInterface();
		ASSERT(i);
		i->AddRef();
		*(p++) = i;
	}

	COMVERIFY(SafeArrayUnaccessData(psa));

	return psa;
}

HRESULT SafeArrayDestroyNoRelease(SAFEARRAY* psa);
void LoadBstrSafeArray(CStringList& dest, SAFEARRAY** ppsa);
SAFEARRAY* StoreBstrSafeArray(CStringList& source);

typedef CList<float, float&> FloatList;
void LoadFloatSafeArray(FloatList& dest, SAFEARRAY** ppsa);
SAFEARRAY* StoreFloatSafeArray(FloatList& source);

// --------------------------- CComPtrList
//
// This is the preferred way to store interface pointers.
// Use the MoveTo functions below to transfer lists of
// interface pointers between CComPtrLists and SAFEARRAYs
//

#include <atlbase.h>

template<class INTERFACE> 
class CComPtrList : public CList< CAdapt< CComPtr<INTERFACE> >, CAdapt< CComPtr<INTERFACE> >& >
{
public:
	typedef CComPtr<INTERFACE> COMPTR;
	typedef CAdapt<COMPTR> CADAPT;
	typedef CList<CADAPT, CADAPT&> BASE;
	typedef CComPtrList<INTERFACE> SELF;

	static CADAPT &CastPtr(INTERFACE *&ptr) { return *(CADAPT*)&ptr; }

	// peek at head or tail
	COMPTR &GetHead() { return BASE::GetHead(); }
	COMPTR GetHead() const { return BASE::GetHead(); }
	COMPTR &GetTail() { return BASE::GetTail(); }
	COMPTR GetTail() const { return BASE::GetTail(); }

	// get head or tail (and remove it) - don't call on empty list!
	COMPTR RemoveHead() { return BASE::RemoveHead(); }
	COMPTR RemoveTail() { return BASE::RemoveTail(); }

	// add before head or after tail
	POSITION AddHead(INTERFACE *newElement) { return BASE::AddHead(CastPtr(newElement)); }
	POSITION AddTail(INTERFACE *newElement) { return BASE::AddTail(CastPtr(newElement)); }

	// iteration
	COMPTR &GetNext(POSITION& rPosition) { return BASE::GetNext(rPosition); }
	COMPTR GetNext(POSITION& rPosition) const { return BASE::GetNext(rPosition); }
	COMPTR &GetPrev(POSITION& rPosition) { return BASE::GetPrev(rPosition); }
	COMPTR GetPrev(POSITION& rPosition) const { return BASE::GetPrev(rPosition); }

	// getting/modifying an element at a given position
	COMPTR &GetAt(POSITION position) { return BASE::GetAt(position); }
	COMPTR GetAt(POSITION position) const { return BASE::GetAt(position); }
	void SetAt(POSITION pos, INTERFACE *newElement) { BASE::SetAt(pos, CastPtr(newElement)); }

	// inserting before or after a given position
	POSITION InsertBefore(POSITION position, INTERFACE *newElement)
		{ return BASE::InsertBefore(position, CastPtr(newElement)); }
	POSITION InsertAfter(POSITION position, INTERFACE *newElement)
		{ return BASE::InsertAfter(position, CastPtr(newElement)); }

	// helper functions (note: O(n) speed)
	POSITION Find(INTERFACE *searchValue, POSITION startAfter = NULL) const
		{ return BASE::Find(CastPtr(searchValue), startAfter); }
		// defaults to starting at the HEAD, return NULL if not found
};

// --------------------------- CComPtrArray

template<class INTERFACE> 
class CComPtrArray : public CArray< CAdapt< CComPtr<INTERFACE> >, CComPtr<INTERFACE>& >
{
public:
	typedef CComPtr<INTERFACE> COMPTR;
	typedef CAdapt<COMPTR> CADAPT;
	typedef CArray<CADAPT, COMPTR&> BASE;
	typedef CComPtrArray<INTERFACE> SELF;

	static COMPTR &CastPtr(INTERFACE *&ptr) { return *(COMPTR*)&ptr; }

	// Accessing elements
	COMPTR GetAt(int nIndex) const { return BASE::GetAt(nIndex); }
	COMPTR& ElementAt(int nIndex) { return BASE::ElementAt(nIndex); }

	// Direct Access to the element data (may return NULL)
	const COMPTR* GetData() const { return BASE::GetData(); }
	COMPTR* GetData() { return BASE::GetData(); }

	// Potentially growing the array
	void SetAtGrow(int nIndex, INTERFACE *newElement)
		{ BASE::SetAtGrow(nIndex, CastPtr(newElement)); }
	int Add(INTERFACE *newElement) { return BASE::Add(CastPtr(newElement)); }

	// overloaded operator helpers
	COMPTR operator[](int nIndex) const { return BASE::operator[](nIndex); }
	COMPTR &operator[](int nIndex) { return BASE::operator[](nIndex); }

	// Operations that move elements around
	void InsertAt(int nIndex, INTERFACE *newElement, int nCount = 1)
		{ BASE::InsertAt(nIndex, CastPtr(newElement), nCount); }
};

// --------------------------- CopyTo & MoveTo

template<class INTERFACE>
void CopyTo(SAFEARRAY* psa, CComPtrList<INTERFACE> &container)
{
	ASSERT(psa);
	container.RemoveAll();

	INTERFACE* *p;
	COMVERIFY(SafeArrayAccessData(psa, (void**)&p));
	ASSERT(p);

	long bound;

	ASSERT( (psa)->fFeatures | FADF_UNKNOWN );
	ASSERT( (psa)->cbElements == sizeof(IUnknown*) );
	ASSERT( SafeArrayGetDim(psa) == 1 );
	COMASSERT(SafeArrayGetLBound(psa, 1, &bound));
	ASSERT( bound == 0 );

	COMVERIFY(SafeArrayGetUBound(psa, 1, &bound));
	ASSERT( bound >= -1 );

	while( bound-- >= 0 )
		container.AddTail(*(p++));

	COMVERIFY(SafeArrayUnaccessData(psa));
}

template<class INTERFACE>
void MoveTo(SAFEARRAY** ppsa, CComPtrList<INTERFACE> &container)
{
	ASSERT(ppsa && *ppsa);

	container.RemoveAll();

	INTERFACE* *p;
	COMVERIFY(SafeArrayAccessData(*ppsa, (void**)&p));
	ASSERT(p);

	long bound;

	ASSERT( (*ppsa)->fFeatures | FADF_UNKNOWN );
	ASSERT( (*ppsa)->cbElements == sizeof(IUnknown*) );
	ASSERT( SafeArrayGetDim(*ppsa) == 1 );
	COMASSERT(SafeArrayGetLBound(*ppsa, 1, &bound));
	ASSERT( bound == 0 );

	COMVERIFY(SafeArrayGetUBound(*ppsa, 1, &bound));
	ASSERT( bound >= -1 );

	while( bound-- >= 0 )
	{
		container.AddTail(NULL);
		container.GetTail().p = *(p++);
	}

	COMVERIFY(SafeArrayUnaccessData(*ppsa));

	COMVERIFY(SafeArrayDestroyNoRelease(*ppsa));
	*ppsa = NULL;
}

template<class INTERFACE>
void CopyTo(CComPtrList<INTERFACE> &container, SAFEARRAY **ppsa)
{
	ASSERT( *ppsa == NULL );

	*ppsa = SafeArrayCreateVector(VT_UNKNOWN, 0, container.GetCount());
	ASSERT(*ppsa);

	IUnknown* *p;
	COMVERIFY(SafeArrayAccessData(*ppsa,(void**)&p));

	POSITION pos = container.GetHeadPosition();
	while(pos)
	{
		INTERFACE *a = container.GetNext(pos).p;
		a->AddRef();
		*(p++) = a;
	}

	COMVERIFY(SafeArrayUnaccessData(*ppsa));
}

template<class INTERFACE>
void MoveTo(CComPtrList<INTERFACE> &container, SAFEARRAY **ppsa)
{
	ASSERT( *ppsa == NULL );

	*ppsa = SafeArrayCreateVector(VT_UNKNOWN, 0, container.GetCount());
	ASSERT(*ppsa);

	IUnknown* *p;
	COMVERIFY(SafeArrayAccessData(*ppsa,(void**)&p));

	POSITION pos = container.GetHeadPosition();
	while(pos)
	{
		CComPtr<INTERFACE> &a = container.GetNext(pos);
		*(p++) = a;
		a.p = NULL;
	}
	
	COMVERIFY(SafeArrayUnaccessData(*ppsa));

	container.RemoveAll();
}

#endif//__COMHELP_H
