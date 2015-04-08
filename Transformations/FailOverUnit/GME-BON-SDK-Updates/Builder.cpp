#include "stdafx.h"

#include "GMECOM.h"
#include "Builder.h"

#define E_INCONSISTENCY 0x87770100



//////////////////////////////////// CBuilder ////////////////////////////////////
IMPLEMENT_DYNAMIC(CBuilder,CObject)

CBuilder* CBuilder::theInstance = NULL;

#ifdef _EXE
#define STRONG_LOOKUP
#endif

static const CBuilderConnectionList  EmptyList;

CBuilder::CBuilder(IMgaProject* ig, CStringMap *pmap) : parametermap(pmap) {
	ASSERT( ig != NULL );
	ciGme = ig;

	ciTerr = NULL;
	COMVERIFY(ciGme->get_ActiveTerritory(&ciTerr));

	COMVERIFY( ciGme->get_RootFolder(&ciRootFolder));
	ASSERT(ciRootFolder);

	ASSERT( theInstance == NULL );
	theInstance = this;

	objectmap.InitHashTable(733);
	connectionmap.InitHashTable(733);

	CBuilderFactory::CheckKindNames(ciRootFolder);

	ASSERT( folders.IsEmpty() );

	rootfolder = new CBuilderFolder(ciRootFolder, NULL);

	rootfolder->Resolve();
}

CBuilder::~CBuilder()
{
	delete rootfolder;
	ASSERT( !folders.GetHeadPosition() );


#ifdef STRONG_LOOKUP
	pos = objectmap.GetStartPosition();
	while(pos)
	{
		IUnknown* iunknown = NULL;
		CBuilderObject* pobject = NULL;
		objectmap.GetNextAssoc(pos, iunknown, pobject);
		ASSERT(iunknown);
		iunknown->Release();
	}

	pos = connectionmap.GetStartPosition();
	while(pos)
	{
		IUnknown* iunknown = NULL;
		CBuilderConnection* pconnection = NULL;
		connectionmap.GetNextAssoc(pos, iunknown, pconnection);
		ASSERT(iunknown);
		iunknown->Release();
	}
#endif

	ASSERT( theInstance );
	theInstance = NULL;
}

void CBuilder::SetObjectRef(IMgaFCO* i, CBuilderObject* o)
{
	ASSERT(i && o);

#ifdef STRONG_LOOKUP
	CComPtr<IUnknown> iu;
	CComPtr<IMgaFCO> ii = i;
	ii.QueryInterface(&iu);
	ASSERT(iu);

	// We CANNOT Release the IUnknown interface here, since it can be the last
	// ptr and next time the marshalling code will assign a new ptr to this
	// interface

	CBuilderObject* o2;
	if( objectmap.Lookup(iu, o2) )	{
		ASSERT( o == o2 );
	}
	else
		objectmap.SetAt(iu, o);
#else
	objectmap.SetAt(i ,o);
#endif
}


CBuilderObject* CBuilder::FindObject(IMgaFCO* i)
{
	ASSERT(i);

#ifdef STRONG_LOOKUP
	CComPtr<IUnknown> iu;
	CComPtr<IMgaFCO> ii = i;
	ii.QueryInterface(&iu);
	ASSERT(iu);

	CBuilderObject* o = NULL;
//	VERIFY( objectmap.Lookup(iu, o) );
	if( !objectmap.Lookup(iu, o) )
	{
		CBstr idstr;
		COMVERIFY( i->get_ID(idstr) );
		ASSERT(false);
	}
	ASSERT(o);

	return o;
#else
	CBuilderObject* o = NULL;
//	VERIFY( objectmap.Lookup(i, o) );
	if( !objectmap.Lookup(i, o) )
	{
		CBstr idstr;
		COMVERIFY( i->get_ID(idstr) );
		ASSERT(false);
	}
	ASSERT(o);

	return o;
#endif
}

void CBuilder::ForgetObjectRef(IMgaFCO* i)
{
	ASSERT(i);

#ifdef STRONG_LOOKUP
	CComPtr<IUnknown> iu;
	CComPtr<IMgaFCO> ii = i;
	ii.QueryInterface(&iu);
	ASSERT(iu);
	objectmap.RemoveKey(iu);
#else
	objectmap.RemoveKey(i);
#endif
}


CBuilderFolder *CBuilder::GetFolder(CString name) const
{
	POSITION pos = folders.GetHeadPosition();
	while(pos) {
		CBuilderFolder *folder = folders.GetNext(pos);
		if(folder->GetName() == name)
			return folder;
	}
	return 0;
}

CString CBuilder::GetProjectName() const
{
	CBstr bstr;
	COMVERIFY( ciGme->get_Name(bstr) );
	return bstr;
}


CString CBuilder::GetParameter(CString name) {
	CString str;
	if(parametermap) parametermap->Lookup(name, str);
	return str;  // returns null string if not found
}

bool CBuilder::PutParameter(CString name, CString value) {
	if(!parametermap) return false;
	parametermap->SetAt(name,value);
	return true;
}

EditorModes CBuilder::GetEditorMode() const
{
	ASSERT( ciGme != NULL );
	EditorModes mode = (EditorModes)0;
//	COMVERIFY( ciGme->get_editormode(&mode) );
	return mode;
}

void CBuilder::SetEditorMode(EditorModes mode)
{
	ASSERT( ciGme != NULL );
//	COMVERIFY( ciGme->put_editormode(mode) );
}

bool CBuilder::BeginTransaction(transactiontype_enum mode)
{
	ASSERT(ciGme);
	ASSERT(ciTerr);
	return SUCCEEDED(ciGme->BeginTransaction(ciTerr, mode));
}

bool CBuilder::CommitTransaction()
{
	ASSERT(ciGme);
	return SUCCEEDED(ciGme->CommitTransaction());
}

void CBuilder::AbortTransaction()
{
	ASSERT(ciGme);
	COMVERIFY(ciGme->AbortTransaction());
}

//////////////////////////////// CBuilderFolder /////////////////////////////////
IMPLEMENT_DYNAMIC(CBuilderFolder,CObject)

CBuilderFolder::CBuilderFolder(IMgaFolder *ic, CBuilderFolder *parent) : ciFolder(ic), parentfolder(parent)
{
	ASSERT( ciFolder );
	CBuilder::theInstance->folders.AddTail(this);

	CComPtr<IMgaFCOs> psa;
	COMVERIFY( ciFolder->get_ChildFCOs(&psa));
	MGACOLL_ITERATE(IMgaFCO, psa) {
		CComPtr<IMgaModel> mm;
		CComPtr<IMgaAtom> aa;
		CComPtr<IMgaReference> rr;
		CComPtr<IMgaSimpleConnection> cc;
		CComPtr<IMgaSet> ss;
		MGACOLL_ITER.QueryInterface(&mm);
		MGACOLL_ITER.QueryInterface(&aa);
		MGACOLL_ITER.QueryInterface(&rr);
		MGACOLL_ITER.QueryInterface(&cc);
		MGACOLL_ITER.QueryInterface(&ss);
		if(mm) {
			CBuilderModel * bm = CBuilderFactory::Create(mm, NULL);
			rootModels.AddTail( bm);
			rootObjects.AddTail( bm);
		}
		else if( aa)
			rootObjects.AddTail( CBuilderFactory::Create( aa, NULL));
		else if( rr)
			rootObjects.AddTail( CBuilderFactory::Create( rr, NULL));
		else if( cc)
			rootObjects.AddTail( CBuilderFactory::Create( cc, NULL));
		else if( ss)
			rootObjects.AddTail( CBuilderFactory::Create( ss, NULL));
		else // unknown kind
			ASSERT(0);
	} MGACOLL_ITERATE_END;

	{
		CBstr bstr;
		COMVERIFY(ciFolder->get_Name(bstr) );
		name = bstr;
	}

	{
		CBstr bstr;
		COMVERIFY( GetMeta()->get_Name(bstr) );
		kindName = bstr;
		kindTitle = kindName;	// for atoms and models this'll be changed to the real thing in their constructor
	}
	{
		CBstr bstr;
		COMVERIFY( GetMeta()->get_DisplayedName(bstr) );
		kindTitle = bstr;
	}

	CComPtr<IMgaFolders> sfs;
	COMVERIFY( ciFolder->get_ChildFolders(&sfs));
	MGACOLL_ITERATE(IMgaFolder, sfs) {
			subfolders.AddTail(new CBuilderFolder(MGACOLL_ITER, this));
	} MGACOLL_ITERATE_END;
}

CBuilderFolder::~CBuilderFolder() {
	POSITION pos = rootModels.GetHeadPosition();
	while(pos)
	{
		delete rootModels.GetNext(pos);
		ASSERT( rootModels.GetHeadPosition() == pos );
	}

	while(!subfolders.IsEmpty()) delete subfolders.RemoveHead();

	ASSERT( CBuilder::theInstance );
	{
		POSITION pos = CBuilder::theInstance->folders.Find(this);
		ASSERT( pos );
		CBuilder::theInstance->folders.RemoveAt(pos);
	}
}

CComPtr<IMgaMetaFolder> CBuilderFolder::GetMeta() const {
		CComPtr<IMgaMetaFolder> cmeta;
		COMVERIFY( ciFolder->get_MetaFolder(&cmeta) );
		return cmeta;
}


void CBuilderFolder::Resolve()
{
	POSITION pos = rootModels.GetHeadPosition();
	while(pos) {
		rootModels.GetNext(pos)->Resolve();
	}

	pos = subfolders.GetHeadPosition();
	while(pos) 	{
		subfolders.GetNext(pos)->Resolve();
	}
}

CBuilderModel *CBuilderFolder::GetRootModel(CString name) const
{
	POSITION pos = rootModels.GetHeadPosition();
	while(pos) {
		CBuilderModel *root = rootModels.GetNext(pos);
		if(root->GetName() == name)
			return root;
	}
	return 0;
}

void CBuilderFolder::RemoveRootModel(CBuilderModel *model)
{
	ASSERT(model);
	POSITION pos = rootModels.Find(model);
	if(pos)
		rootModels.RemoveAt(pos);
}

CBuilderModel *CBuilderFolder::CreateNewModel(CString kindName, CBuilderModel* baseType, bool instance)
{
	CComPtr<IMgaMetaFolder> fmeta;
	CComPtr<IMgaMetaFCO> cmeta;
	COMVERIFY( ciFolder->get_MetaFolder(&fmeta) );
	COMVERIFY( fmeta->get_LegalRootObjectByName((CBstrIn)kindName, &cmeta) );
	ASSERT( cmeta != NULL );
	CComPtr<IMgaFCO> i;
	if (baseType) {
		COMVERIFY( ciFolder->DeriveRootObject(baseType->GetIModel(), instance ? VARIANT_TRUE : VARIANT_FALSE ,&i) );
	}
	else {
		COMVERIFY( ciFolder->CreateRootObject(cmeta ,&i) );
	}
	ASSERT( i != NULL );

	CBuilderModel* o = CBuilderFactory::Create(CComQIPtr<IMgaModel>(i), NULL);
	rootModels.AddTail(o);
	rootObjects.AddTail(o);

	return o;
}

CBuilderFolder *CBuilderFolder::CreateNewFolder(CString kindName)
{
	CComPtr<IMgaMetaFolder> fmeta;
	CComPtr<IMgaMetaFolder> cmeta;
	COMVERIFY( ciFolder->get_MetaFolder(&fmeta) );
	COMVERIFY( fmeta->get_LegalChildFolderByName((CBstrIn)kindName, &cmeta) );
	ASSERT( cmeta != NULL );
	CComPtr<IMgaFolder> i;
	COMVERIFY( ciFolder->CreateFolder(cmeta ,&i) );
	ASSERT( i != NULL );

	CBuilderFolder* o = new CBuilderFolder(i, this);
	subfolders.AddTail(o);

	return o;
}


CBuilderAtom *CBuilderFolder::CreateNewAtom(CString kindName, CBuilderAtom* baseType, bool instance) {

	CComPtr<IMgaMetaFolder> fmeta;
	CComPtr<IMgaMetaFCO> cmeta;
	COMVERIFY( ciFolder->get_MetaFolder(&fmeta) );
	COMVERIFY( fmeta->get_LegalRootObjectByName((CBstrIn)kindName, &cmeta) );
	ASSERT( cmeta != NULL );
	CComPtr<IMgaFCO> i;
	if (baseType) {
		COMVERIFY( ciFolder->DeriveRootObject(baseType->GetIAtom(), instance ? VARIANT_TRUE : VARIANT_FALSE ,&i) );
	}
	else {
		COMVERIFY( ciFolder->CreateRootObject(cmeta ,&i) );
	}
	ASSERT( i != NULL );

	CBuilderAtom* o = CBuilderFactory::Create(CComQIPtr<IMgaAtom>(i), NULL);
// TODO: Refresh Ports in referencing objects......!!!!

	rootObjects.AddTail(o);
	return o;
}


CBuilderReference *CBuilderFolder::CreateNewReference(CString kindName, CBuilderObject *refTo, CBuilderReference* baseType, bool instance) {
	IMgaFCO *i = NULL;
	CComPtr<IMgaMetaFolder> fmeta;
	CComPtr<IMgaMetaFCO> cmeta;
	COMVERIFY( ciFolder->get_MetaFolder(&fmeta) );
	COMVERIFY( fmeta->get_LegalRootObjectByName((CBstrIn)kindName, &cmeta) );
	ASSERT( cmeta != NULL );
	if (baseType) {
		COMVERIFY( ciFolder->DeriveRootObject(baseType->GetIRef(), instance ? VARIANT_TRUE : VARIANT_FALSE ,&i) );
	}
	else {
		COMVERIFY( ciFolder->CreateRootObject(cmeta ,&i) );
	}
	ASSERT( i != NULL );


	CBuilderReference* oo = CBuilderFactory::Create(CComQIPtr<IMgaReference>(i), NULL);
	rootObjects.AddTail(oo);
	return oo;
}


CBuilderModelReference *CBuilderFolder::CreateNewModelReference(CString kindName, CBuilderObject *refTo)
{
	ASSERT( refTo );
	ASSERT( refTo->IsKindOf(RUNTIME_CLASS(CBuilderModel)) ||
		refTo->IsKindOf(RUNTIME_CLASS(CBuilderModelReference)) );

	CBuilderReference *nobj = CreateNewReference(kindName, refTo);
	ASSERT( nobj->IsKindOf(RUNTIME_CLASS(CBuilderModelReference)) );


	return (CBuilderModelReference *)nobj;

}

CBuilderAtomReference *CBuilderFolder::CreateNewAtomReference(CString kindName, CBuilderObject *refTo)
{
	ASSERT( refTo );
	ASSERT( refTo->IsKindOf(RUNTIME_CLASS(CBuilderAtom)) ||
		refTo->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference)) );

	CBuilderReference *nobj = CreateNewReference(kindName, refTo);
	ASSERT( nobj->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference)) );


	return (CBuilderAtomReference *)nobj;
}


CBuilderConnection *CBuilderFolder::CreateNewConnection(CString kindName, CBuilderObject *source, CBuilderObject *destination)
{
//DONE
	CComPtr<IMgaFCOs> srcrefs, dstrefs;
	CComPtr<IMgaFCO> srcfco, dstfco;
	CBuilderObject const *src = source;
	if(src->IsKindOf(RUNTIME_CLASS(CBuilderReferencePort))) {
		srcfco = src->GetIObject();
		src = ((CBuilderReferencePort*)src)->GetOwner();
		while(src->IsKindOf(RUNTIME_CLASS(CBuilderModelReference))) {
			COMVERIFY(src->GetIObject()->CreateCollection(&srcrefs));
			src=((CBuilderModelReference*)src)->GetReferred();
		}
		if(!src->IsKindOf(RUNTIME_CLASS(CBuilderModel))) COMVERIFY(E_INCONSISTENCY);
		srcfco = source->GetIObject();
		if(src != ((CBuilderReferencePort*)source)->GetPortObject()->GetParent()) COMVERIFY(E_INCONSISTENCY);
	}
	else {
		while(src->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference))) {
			COMVERIFY(src->GetIObject()->CreateCollection(&srcrefs));
			src=((CBuilderAtomReference*)src)->GetReferred();
		}
		// if(!src->IsKindOf(RUNTIME_CLASS(CBuilderAtom))) COMVERIFY(E_INCONSISTENCY);
		srcfco = src->GetIObject();
	}

	CBuilderObject const *dst = destination;
	if(dst->IsKindOf(RUNTIME_CLASS(CBuilderReferencePort))) {
		dstfco = dst->GetIObject();
		dst = ((CBuilderReferencePort*)dst)->GetOwner();
		while(dst->IsKindOf(RUNTIME_CLASS(CBuilderModelReference))) {
			COMVERIFY(dst->GetIObject()->CreateCollection(&dstrefs));
			dst=((CBuilderModelReference*)dst)->GetReferred();
		}
		if(!dst->IsKindOf(RUNTIME_CLASS(CBuilderModel))) COMVERIFY(E_INCONSISTENCY);
		dstfco = destination->GetIObject();
		if(dst != ((CBuilderReferencePort*)destination)->GetPortObject()->GetParent()) COMVERIFY(E_INCONSISTENCY);
	}
	else {
		while(dst->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference))) {
			COMVERIFY(dst->GetIObject()->CreateCollection(&dstrefs));
			dst=((CBuilderAtomReference*)dst)->GetReferred();
		}
		// if(!dst->IsKindOf(RUNTIME_CLASS(CBuilderAtom))) COMVERIFY(E_INCONSISTENCY);
		dstfco = dst->GetIObject();
	}

	CComPtr<IMgaMetaFolder> fmeta;
	CComPtr<IMgaMetaFCO> cmeta;
	COMVERIFY( ciFolder->get_MetaFolder(&fmeta) );
	COMVERIFY( fmeta->get_LegalRootObjectByName((CBstrIn)kindName, &cmeta) );
	ASSERT( cmeta != NULL );
	CComPtr<IMgaFCO> i;
	COMVERIFY( ciFolder->CreateRootObject(cmeta ,&i) );
	ASSERT( i != NULL );

	CBuilderConnection* o = CBuilderFactory::Create(CComQIPtr<IMgaSimpleConnection>(i), NULL);
	rootObjects.AddTail(o);
	o->Resolve();
	return o;
}

CBuilderSet *CBuilderFolder::CreateNewSet(CString kindName, CBuilderSet* baseType, bool instance) {
	CComPtr<IMgaMetaFolder> fmeta;
	CComPtr<IMgaMetaFCO> cmeta;
	COMVERIFY( ciFolder->get_MetaFolder(&fmeta) );
	COMVERIFY( fmeta->get_LegalRootObjectByName((CBstrIn)kindName, &cmeta) );
	ASSERT( cmeta != NULL );
	CComPtr<IMgaFCO> i;
	if (baseType) {
		COMVERIFY( ciFolder->DeriveRootObject(baseType->GetISet(), instance ? VARIANT_TRUE : VARIANT_FALSE ,&i) );
	}
	else {
		COMVERIFY( ciFolder->CreateRootObject(cmeta ,&i) );
	}
	ASSERT( i != NULL );

	CBuilderSet* o = CBuilderFactory::Create(CComQIPtr<IMgaSet>(i), NULL);
// TODO: Refresh Ports in referencing objects......!!!!

	rootObjects.AddTail(o);
	return o;
}

bool CBuilderFolder::GetRegistryValue(CString &path,CString &val) const
{
	CBstr bstr;
	COMVERIFY( ciFolder->get_RegistryValue((CBstrIn)path, bstr) );

	val = bstr;
	return true;
}

bool CBuilderFolder::SetRegistryValue(CString &path,CString &val) const
{
	if( !SUCCEEDED( ciFolder->put_RegistryValue((CBstrIn)path, (CBstrIn)val) ) )
		return false;

	return true;
}

bool CBuilderFolder::SetName(CString newname)
{
	bool ret = SUCCEEDED( ciFolder->put_Name((CBstrIn)newname));
	if( ret )
		name = newname;

	return ret;
}

////////////////////////////////// CBuilderObject //////////////////////////////////
IMPLEMENT_DYNAMIC(CBuilderObject,CObject)


CComPtr<IMgaMetaFCO> CBuilderObject::GetMeta() const {
		CComPtr<IMgaMetaFCO> cmeta;
		COMVERIFY( ciObject->get_Meta(&cmeta) );
		return cmeta;
}


CBuilderObject::CBuilderObject(IMgaFCO* io, CBuilderModel *p, bool globalregister)
{
	ciObject = io;
	parent = p;

	ASSERT(ciObject);

	{
		CBstr bstr;
		COMVERIFY( ciObject->get_Name(bstr) );
		name = bstr;
	}

	{
		CBstr bstr;
		COMVERIFY( GetMeta()->get_Name(bstr) );
		kindName = bstr;
		kindTitle = kindName;	// for atoms and models this'll be changed to the real thing in their constructor
	}

	{
		CBstr bstr;
		CComPtr<IMgaMetaRole> rmeta;
		COMVERIFY( ciObject->get_MetaRole(&rmeta) );
		if(rmeta) {
			COMVERIFY( rmeta->get_Name(bstr) );
			partName = bstr;
		} else partName = "";
	}

	if(globalregister) CBuilder::theInstance->SetObjectRef(io, this);
}

CBuilderObject::~CBuilderObject()
{

	POSITION pos = inConnections.GetStartPosition();
	CString name;
	while(pos) {
		CBuilderConnectionList *list;
		inConnections.GetNextAssoc(pos,name,list);
		POSITION pos2 = list->GetHeadPosition();
		while(pos2)
		{
			delete list->GetNext(pos2);
			ASSERT( pos2 == list->GetHeadPosition() );
		}
		delete list;
	}
	pos = outConnections.GetStartPosition();
	while(pos) {
		CBuilderConnectionList *list;
		outConnections.GetNextAssoc(pos,name,list);
		POSITION pos2 = list->GetHeadPosition();
		while(pos2)
		{
			delete list->GetNext(pos2);
			ASSERT( pos2 == list->GetHeadPosition() );
		}
		delete list;
	}

	ASSERT( CBuilder::theInstance );
	CBuilder::theInstance->ForgetObjectRef(ciObject);
}

void CBuilderObject::Destroy()
{
	ASSERT(ciObject);

	POSITION pos = inConnections.GetStartPosition();
	CString name;
	while(pos) {
		CBuilderConnectionList *list;
		inConnections.GetNextAssoc(pos,name,list);
		POSITION pos2 = list->GetHeadPosition();
		while(pos2)
			list->GetNext(pos2)->Destroy();
	}
	pos = outConnections.GetStartPosition();
	while(pos) {
		CBuilderConnectionList *list;
		outConnections.GetNextAssoc(pos,name,list);
		POSITION pos2 = list->GetHeadPosition();
		while(pos2)
			list->GetNext(pos2)->Destroy();
	}

	CComPtr<IMgaFCO> myself = GetIObject();
	if(parent)
	{
		parent->RemoveMemberFromSets(this);

		delete this;
	}
	else
	{
		ASSERT( this->IsKindOf(RUNTIME_CLASS(CBuilderModel)) );
		delete this;
	}
	COMVERIFY(myself->DestroyObject());
}

CBuilderFolder *CBuilderObject::GetFolder() const
{
	if( parent )
		return parent->GetFolder();

	ASSERT( CBuilder::theInstance );
	ASSERT( this->IsKindOf(RUNTIME_CLASS(CBuilderModel)) );

	const CBuilderFolderList *folders = CBuilder::theInstance->GetFolders();
	ASSERT( folders );

	POSITION pos = folders->GetHeadPosition();
	while(pos)
	{
		CBuilderFolder *folder = folders->GetNext(pos);

		const CBuilderModelList *models = folder->GetRootModels();
		POSITION pos2 = models->GetHeadPosition();
		while(pos2)
			if( models->GetNext(pos2) == this )
				return folder;
	}
	ASSERT(false);
	return NULL;
}

void CBuilderObject::GetNamePath(CString &namePath) const
{
	GetExtendedName(namePath,"__",true);
}

void CBuilderObject::GetExtendedName(CString &extName,CString separator,bool startWithRoot) const
{
	if(!startWithRoot)
		extName += GetName();
	const CBuilderObject *parent = GetParent();
	if(parent) {
		if(!startWithRoot)
			extName += separator;
		parent->GetExtendedName(extName,separator,startWithRoot);
		if(startWithRoot)
			extName += separator;
	}
	if(startWithRoot)
		extName += GetName();
}

bool CBuilderObject::GetLocation(CString &aspectName,CRect &loc)
{
	if(!parent)
		return false;

	CComPtr<IMgaMetaAspect> asp;
	CComQIPtr<IMgaMetaModel>	pmetam = parent->GetMeta();
	COMVERIFY(pmetam->get_AspectByName((CBstrIn)aspectName, &asp));
	CComPtr<IMgaPart> part;
	COMVERIFY(this->GetIObject()->get_Part(asp, &part));

	long x, y;
	COMVERIFY(part->GetGmeAttrs(NULL, &x, &y));
	loc.left = x, loc.top = y, loc.right = x + 100, loc.bottom = y + 100;
	return true;
}

bool CBuilderObject::SetLocation(CString aspectName,CPoint loc)
{
	if(!parent)
		return false;

	CComPtr<IMgaMetaAspect> asp;
	CComQIPtr<IMgaMetaModel>	pmetam = parent->GetMeta();
	COMVERIFY(pmetam->get_AspectByName((CBstrIn)aspectName, &asp));
	CComPtr<IMgaPart> part;
	COMVERIFY(this->GetIObject()->get_Part(asp, &part));

	COMVERIFY(part->SetGmeAttrs(NULL, loc.x, loc.y));
	return true;
}

short CBuilderObject::GetNamePosition()
{
	ASSERT( ciObject );

	short pos = 0;
//  TODO:
//	iObject->get_nameposition(&pos);

	return pos;
}

void CBuilderObject::SetNamePosition(short pos)
{
	ASSERT( ciObject );

//  TODO:
//	iObject->put_nameposition(pos);
}

void CBuilderObject::DisplayMessage(CString &msg,bool error) const
{
	CString namePath;
	GetNamePath(namePath);
	AfxMessageBox(msg + "\n" + namePath,error ? MB_OK | MB_ICONSTOP : MB_OK);
}


bool CBuilderObject::GetRegistryValue(CString &path,CString &val) const
{
	CBstr bstr;
	COMVERIFY( ciObject->get_RegistryValue((CBstrIn)path, bstr) );

	val = bstr;
	return true;
}

bool CBuilderObject::SetRegistryValue(CString &path,CString &val) const
{
	if( !SUCCEEDED( ciObject->put_RegistryValue((CBstrIn)path, (CBstrIn)val) ) )
		return false;

	return true;
}


bool CBuilderObject::GetAttribute(CString &name,CString &val) const
{
	CBstr bstr;
	if ( ! SUCCEEDED( ciObject->get_StrAttrByName((CBstrIn)name, bstr) ) )
		return false;

	val = bstr;
	return true;
}

bool CBuilderObject::GetAttribute(CString &name,int &val) const
{
	long l;
	if(! SUCCEEDED( ciObject->get_IntAttrByName((CBstrIn)name, &l) ) ) return false;
	val = l;
	return true;
}

bool CBuilderObject::GetAttribute(CString &name,bool &val) const
{
	VARIANT_BOOL vb;

	if( !SUCCEEDED( ciObject->get_BoolAttrByName((CBstrIn)name, &vb) ) )
		return false;

	val = (vb != 0);
	return true;
}

bool CBuilderObject::GetAttribute(CString &name,double &val) const
{

	if( !SUCCEEDED( ciObject->get_FloatAttrByName((CBstrIn)name, &val) ) )
		return false;

	return true;
}

bool CBuilderObject::GetAttribute(CString &name,CBuilderObject *&val) const
{

	CComPtr<IMgaFCO> valp;
	if( !SUCCEEDED( ciObject->get_RefAttrByName((CBstrIn)name, &valp) ) )
		return false;

	if(!valp) val = NULL;
	else val = CBuilder::theInstance->FindObject(valp);
	return true;
}


int CBuilderObject::GetAttributeStatus(CString attrName) {
         CComPtr<IMgaMetaAttribute> mattr;
         CComPtr<IMgaAttribute> attr;
         COMVERIFY(GetMeta()->get_AttributeByName(CComBSTR(attrName), &mattr));
         COMVERIFY(ciObject->get_Attribute(mattr, &attr));

         long status;
         COMVERIFY(attr->get_Status(&status));
         return((int) status);
}

bool CBuilderObject::SetAttribute(CString &name, CString &val)
{
	if( !SUCCEEDED( ciObject->put_StrAttrByName((CBstrIn)name, (CBstrIn)val) ) )
		return false;

	return true;
}

bool CBuilderObject::SetAttribute(CString &name, int val)
{
	if( !SUCCEEDED( ciObject->put_IntAttrByName((CBstrIn)name, val) ) )
		return false;

	return true;
}

bool CBuilderObject::SetAttribute(CString &name, bool val)
{
	if( !SUCCEEDED( ciObject->put_BoolAttrByName((CBstrIn)name, val ? -1 : 0) ) )
		return false;

	return true;
}

bool CBuilderObject::SetAttribute(CString &name, double val)
{
	if( !SUCCEEDED( ciObject->put_FloatAttrByName((CBstrIn)name, val) ) )
		return false;

	return true;
}

bool CBuilderObject::SetAttribute(CString &name, CBuilderObject *val)
{
	CComPtr<IMgaFCO> valp;
	if(val) valp = val->GetIObject();
	if( !SUCCEEDED( ciObject->put_RefAttrByName((CBstrIn)name, valp) ) )
		return false;

	return true;
}

void CBuilderObject::GetAttributeNames(CStringList &list, attval_enum type, attval_enum sectype) const
{
	ASSERT( list.IsEmpty() );

	CComPtr<IMgaMetaAttributes> mattrs;
	COMVERIFY(GetMeta()->get_Attributes(&mattrs));
	MGACOLL_ITERATE(IMgaMetaAttribute, mattrs) {
		attval_enum t;
		COMVERIFY(MGACOLL_ITER->get_ValueType(&t) );
		if(t == type || t == sectype) {
			CBstr n;
			COMVERIFY(MGACOLL_ITER->get_Name(n) );
			list.AddTail(n);
		}

	} MGACOLL_ITERATE_END;
}

void CBuilderObject::GetStrAttributeNames(CStringList &list) const
{
	GetAttributeNames(list, ATTVAL_STRING, ATTVAL_ENUM);
}

void CBuilderObject::GetIntAttributeNames(CStringList &list) const
{
	GetAttributeNames(list, ATTVAL_INTEGER);
}

void CBuilderObject::GetBoolAttributeNames(CStringList &list) const
{
	GetAttributeNames(list, ATTVAL_BOOLEAN);
}

void CBuilderObject::GetFloatAttributeNames(CStringList &list) const
{
	GetAttributeNames(list, ATTVAL_DOUBLE);
}

void CBuilderObject::GetRefAttributeNames(CStringList &list) const
{
	GetAttributeNames(list, ATTVAL_REFERENCE);
}

void CBuilderObject::GetReferencedBy(CBuilderObjectList &list) const
{
	ASSERT( list.IsEmpty() );

	CComPtr<IMgaFCOs> reflist;
	COMVERIFY( GetIObject()->get_ReferencedBy(&reflist));
	MGACOLL_ITERATE(IMgaFCO, reflist) {
		CBuilderObject* object = CBuilder::theInstance->FindObject(MGACOLL_ITER);
		ASSERT( object != NULL );

		list.AddTail(object);
	} MGACOLL_ITERATE_END;

}

void CBuilderObject::GetMemberOfSets(CBuilderObjectList &list) const
{
	ASSERT( list.IsEmpty() );

	CComPtr<IMgaFCOs> setlist;
	COMVERIFY( GetIObject()->get_MemberOfSets(&setlist));
	MGACOLL_ITERATE(IMgaFCO, setlist) {
		CBuilderObject* object = CBuilder::theInstance->FindObject(MGACOLL_ITER);
		ASSERT( object != NULL );

		list.AddTail(object);
	} MGACOLL_ITERATE_END;

}


bool CBuilderObject::SetName(CString newname)
{
	bool ret = SUCCEEDED( ciObject->put_Name((CBstrIn)newname));
	if( ret )
		name = newname;

	return ret;
}

bool CBuilderObject::IsInstance()
{
	VARIANT_BOOL ret = 0;
	COMVERIFY( ciObject->get_IsInstance(&ret) );
	return ret != 0;

}


CBuilderObject* CBuilderObject::GetType()
{
	if(!IsInstance()) return 0;
	CComPtr<IMgaFCO> pp;
	COMVERIFY( ciObject->get_Type(&pp) );
	return CBuilder::theInstance->FindObject(pp);

}

CBuilderObject *CBuilderObject::GetDerivedFrom()
{
	if(!IsInstance()) return 0;
	CComPtr<IMgaFCO> pp;
	COMVERIFY( ciObject->get_DerivedFrom(&pp) );
	return CBuilder::theInstance->FindObject(pp);
}

void CBuilderObject::GetDerivedObjects(CBuilderObjectList &l, int mode) {
	CComPtr<IMgaFCOs> pps;
	COMVERIFY( ciObject->get_DerivedObjects(&pps));
	MGACOLL_ITERATE(IMgaFCO, pps) {
		if(mode) {
			VARIANT_BOOL inst;
			COMVERIFY(MGACOLL_ITER->get_IsInstance(&inst));
			if(mode == 1 && inst) continue;
			if(mode == 2 && !inst) continue;
		}
		l.AddTail(CBuilder::theInstance->FindObject(MGACOLL_ITER));
	} MGACOLL_ITERATE_END;
}

bool CBuilderObject::IsMarked()
{
	VARIANT_BOOL ret = 0;
// TODO
//	COMVERIFY( iObject->get_marked(&ret) );
	return ret != 0;
}

void CBuilderObject::Mark(bool marked)
{
// TODO
//	COMVERIFY( iObject->put_marked(marked ? -1 : 0) );
}

const CBuilderConnectionList *CBuilderObject::GetInConnections(const CString &name, bool bPorts ) const	{
	CBuilderConnectionList *list = NULL;
	if ( ! bPorts )
		list =  FindInConnections(name);
	else
		inConnections2.Lookup(name,list);
	if( ! list )
		return &EmptyList;
	return list;
}

const CBuilderConnectionList *CBuilderObject::GetOutConnections(const CString &name, bool bPorts ) const	{
	CBuilderConnectionList *list = NULL;
	if ( ! bPorts )
		list =  FindOutConnections(name);
	else
		outConnections2.Lookup(name,list);
	if( ! list )
		return &EmptyList;
	return list;
}


void CBuilderObject::AddInConnection(CString &name,CBuilderConnection *conn)
{
	CBuilderConnectionList *list = FindInConnections(name);
	if(list == 0) {
		list = new CBuilderConnectionList();
		inConnections[name] = list;
	}
	list->AddTail(conn);
	AddPortInConnection( name, conn );
}

void CBuilderObject::AddOutConnection(CString &name,CBuilderConnection *conn)
{
	CBuilderConnectionList *list = FindOutConnections(name);
	if(list == 0) {
		list = new CBuilderConnectionList();
		outConnections[name] = list;
	}
	list->AddTail(conn);
	AddPortOutConnection( name, conn );
}

void CBuilderObject::AddPortInConnection(CString &name,CBuilderConnection *conn)
{
	CBuilderConnectionList *list = NULL;
	inConnections2.Lookup(name,list);
	if(list == 0) {
		list = new CBuilderConnectionList();
		inConnections2[name] = list;
	}
	list->AddTail(conn);
}

void CBuilderObject::AddPortOutConnection(CString &name,CBuilderConnection *conn)
{
	CBuilderConnectionList *list = NULL;
	outConnections2.Lookup(name,list);
	if(list == 0) {
		list = new CBuilderConnectionList();
		outConnections2[name] = list;
	}
	list->AddTail(conn);
}

CBuilderConnectionList *CBuilderObject::FindInConnections(const CString &name) const
{
	CBuilderConnectionList *list = NULL;
	inConnections.Lookup(name,list);
	return list;
}

CBuilderConnectionList *CBuilderObject::FindOutConnections(const CString &name)	const
{
	CBuilderConnectionList *list = NULL;
	outConnections.Lookup(name,list);
	return list;
}

void CBuilderObject::RemoveInConnection(CBuilderConnection *conn)
{
	ASSERT(conn);
	CBuilderConnectionList *list;
	VERIFY( inConnections.Lookup(conn->GetKindName(),list) );
	ASSERT(list);

	POSITION pos = list->Find(conn);
	if(pos)
		list->RemoveAt(pos);
}

void CBuilderObject::RemoveOutConnection(CBuilderConnection *conn)
{
	ASSERT(conn);
	CBuilderConnectionList *list;
	VERIFY( outConnections.Lookup(conn->GetKindName(),list) );
	ASSERT(list);
	POSITION pos = list->Find(conn);
	if(pos)
		list->RemoveAt(pos);
}

bool CBuilderObject::GetDirectConnections(const CString &name, CBuilderObjectList &list, bool in)
{
	if(list.GetCount() != 0)
	{
		DisplayError("Connection list must be empty in CBuilderObject::GetDirectInConnections");
		return false;
	}

	// if there is no such connection list then we check the parent if it has
	// that connection name
	const CBuilderConnectionList *conns = in ? GetInConnections(name) : GetOutConnections(name);
	if( conns == NULL )
		return parent != NULL && parent->FindConnections(name) != NULL;

	CMap<const CBuilderObject*, const CBuilderObject*, int, int> visited;
	CBuilderObjectList processing;

	visited.SetAt(this,0);
	processing.AddTail(this);

	while( !processing.IsEmpty() )
	{
		CBuilderObject *object = processing.RemoveHead();
		ASSERT( object != NULL );

		conns = in ? object->GetInConnections(name) : object->GetOutConnections(name);

		if( conns == NULL || conns->IsEmpty() )
			list.AddTail(object);
		else
		{
			POSITION pos = conns->GetHeadPosition();
			while( pos != NULL )
			{
				CBuilderObject *next;
				if( in )
				{
					ASSERT( conns->GetAt(pos)->GetDestination() == object );
					next = conns->GetNext(pos)->GetSource();
				}
				else
				{
					ASSERT( conns->GetAt(pos)->GetSource() == object );
					next = conns->GetNext(pos)->GetDestination();
				}

				int k;
				if( !visited.Lookup(next, k) )
				{
					visited.SetAt(next,0);
					processing.AddHead(next);
				}
			}
		}
	}

	return true;
}

bool CBuilderObject::GetInConnectedObjects(const CString &name, CBuilderObjectList &list, bool bPorts )
{
	// if there is no such connection list then we check the parent if it has
	// that connection name
	const CBuilderConnectionList *conns = GetInConnections(name, bPorts );
	if( conns == NULL )
		return parent != NULL && parent->FindConnections(name) != NULL;

	POSITION pos = conns->GetHeadPosition();
	while( pos != NULL )
		list.AddTail( conns->GetNext(pos)->GetSource() );

	return true;
};

bool CBuilderObject::GetOutConnectedObjects(const CString &name, CBuilderObjectList &list, bool bPorts )
{
	// if there is no such connection list then we check the parent if it has
	// that connection name
	const CBuilderConnectionList *conns = GetOutConnections(name, bPorts );
	if( conns == NULL )
		return parent != NULL && parent->FindConnections(name) != NULL;

	POSITION pos = conns->GetHeadPosition();
	while( pos != NULL )
		list.AddTail( conns->GetNext(pos)->GetDestination() );

	return true;
};

long CBuilderObject::GetObjId() const
{
	long ret = -1;
	CBstr rret;
	COMVERIFY( ciObject->get_ID(rret) );
	long mm, ss;
	if(swscanf(*rret, OLESTR("id-%04lx-%08lx"), &mm, &ss) == 2 && mm > 100 && mm < 110) {
		ASSERT(ss < 100000000);
		ret = 100000000 * (mm-100) + ss;
	}
	return ret;
}

CBuilderObject::objtype CBuilderObject::GetObjType() const {
	objtype_enum rret;
	COMVERIFY( ciObject->get_ObjType( &rret) );
	return (objtype)rret;
}

////////////////////////////////// CBuilderModel //////////////////////////////////
IMPLEMENT_DYNAMIC(CBuilderModel,CBuilderObject)

CBuilderModel::CBuilderModel(IMgaModel *iModel, CBuilderModel *aparent) : CBuilderObject(iModel,aparent)
{
	{
		CBstr bstr;
		COMVERIFY( GetMeta()->get_DisplayedName(bstr) );
		kindTitle = bstr;
	}

	CreateModels();
	CreateAtoms();
	CreateReferences();
	CreateConnections();
	CreateSets();
}

CBuilderModel::~CBuilderModel()
{
	POSITION pos2;
	POSITION pos = modelLists.GetStartPosition();
	CString name;
	while(pos) {
		CBuilderModelList *list;
		modelLists.GetNextAssoc(pos,name,list);
		pos2 = list->GetHeadPosition();
		while(pos2)
		{
			delete list->GetNext(pos2);
			ASSERT( pos2 == list->GetHeadPosition() );
		}
		delete list;
	}
	pos = atomLists.GetStartPosition();
	while(pos) {
		CBuilderAtomList *list;
		atomLists.GetNextAssoc(pos,name,list);
		pos2 = list->GetHeadPosition();
		while(pos2)
		{
			delete list->GetNext(pos2);
			ASSERT( pos2 == list->GetHeadPosition() );
		}
		delete list;
	}
	pos = referenceLists.GetStartPosition();
	while(pos) {
		CBuilderReferenceList *list;
		referenceLists.GetNextAssoc(pos,name,list);
		pos2 = list->GetHeadPosition();
		while(pos2)
		{
			delete list->GetNext(pos2);
			ASSERT( pos2 == list->GetHeadPosition() );
		}
		delete list;
	}
	pos = modelReferenceLists.GetStartPosition();
	while(pos) {
		CBuilderModelReferenceList *list;
		modelReferenceLists.GetNextAssoc(pos,name,list);
		pos2 = list->GetHeadPosition();
		while(pos2)
		{
			delete list->GetNext(pos2);
			ASSERT( pos2 == list->GetHeadPosition() );
		}
		delete list;
	}
	pos = atomReferenceLists.GetStartPosition();
	while(pos) {
		CBuilderAtomReferenceList *list;
		atomReferenceLists.GetNextAssoc(pos,name,list);
		pos2 = list->GetHeadPosition();
		while(pos2)
		{
			delete list->GetNext(pos2);
			ASSERT( pos2 == list->GetHeadPosition() );
		}
		delete list;
	}
	pos = setLists.GetStartPosition();
	while(pos) {
		CBuilderSetList *list;
		setLists.GetNextAssoc(pos,name,list);
		pos2 = list->GetHeadPosition();
		while(pos2)
		{
			delete list->GetNext(pos2);
			ASSERT( pos2 == list->GetHeadPosition() );
		}
		delete list;
	}
	pos = connectionLists.GetStartPosition();
	while(pos) {
		CBuilderConnectionList *list;
		connectionLists.GetNextAssoc(pos,name,list);
		ASSERT( list->IsEmpty() );
		delete list;
	}

	if(parent)
		parent->RemoveModel(this);
	else
		GetFolder()->RemoveRootModel(this);
}

void CBuilderModel::Resolve()
{
	{
	POSITION pos = children.GetHeadPosition();
	while(pos)
		children.GetNext(pos)->Resolve();
	}
	{
	POSITION pos = connchildren.GetHeadPosition();
	while(pos)
		connchildren.GetNext(pos)->Resolve();
	}
	{
	POSITION pos = sets.GetHeadPosition();
	while(pos)
		sets.GetNext(pos)->Resolve();
	}
}

void CBuilderModel::CreateModels()
{
	CBuilderModelList *objectlist;

	CComPtr<IMgaMetaRoles> roles;
	COMVERIFY( CComQIPtr<IMgaMetaModel>(GetMeta())->get_Roles(&roles) );

	modelLists.InitHashTable(17);
	MGACOLL_ITERATE(IMgaMetaRole, roles) {
		CComPtr<IMgaMetaFCO> kind;
		COMVERIFY(MGACOLL_ITER->get_Kind(&kind));
		objtype_enum type;
		COMVERIFY(kind->get_ObjType(&type));
		if( type == OBJTYPE_MODEL) {
			CBstr part;
			COMVERIFY(MGACOLL_ITER->get_Name(part) );
			ASSERT( !modelLists.Lookup(CString(part), objectlist) );

			objectlist = new CBuilderModelList;
			ASSERT(objectlist);

			modelLists[CString(part)] = objectlist;
		}
	} MGACOLL_ITERATE_END;

	CComPtr<IMgaFCOs> chds;
	COMVERIFY( GetIModel()->get_ChildFCOs(&chds) );
	MGACOLL_ITERATE(IMgaFCO, chds) {
		objtype_enum ot;
		COMVERIFY(MGACOLL_ITER->get_ObjType(&ot));
		if(ot != OBJTYPE_MODEL) continue;
		CBuilderModel* o = CBuilderFactory::Create(CComQIPtr<IMgaModel>(MGACOLL_ITER), this);

		VERIFY( modelLists.Lookup(o->GetPartName(), objectlist) );
		ASSERT( objectlist );

		objectlist->AddTail(o);
		children.AddTail(o);
		models.AddTail(o);
	} MGACOLL_ITERATE_END;
}

void CBuilderModel::CreateAtoms()
{
	CBuilderAtomList *objectlist;

	CComPtr<IMgaMetaRoles> roles;
	COMVERIFY( CComQIPtr<IMgaMetaModel>(GetMeta())->get_Roles(&roles) );

	atomLists.InitHashTable(17);
	MGACOLL_ITERATE(IMgaMetaRole, roles) {
		CComPtr<IMgaMetaFCO> kind;
		COMVERIFY(MGACOLL_ITER->get_Kind(&kind));
		objtype_enum type;
		COMVERIFY(kind->get_ObjType(&type));
		if( type == OBJTYPE_ATOM) {
			CBstr part;
			COMVERIFY(MGACOLL_ITER->get_Name(part) );
			ASSERT( !atomLists.Lookup(CString(part), objectlist) );

			objectlist = new CBuilderAtomList;
			ASSERT(objectlist);

			atomLists[CString(part)] = objectlist;
		}
	} MGACOLL_ITERATE_END;

	CComPtr<IMgaFCOs> chds;
	COMVERIFY( GetIModel()->get_ChildFCOs(&chds) );
	MGACOLL_ITERATE(IMgaFCO, chds) {
		objtype_enum ot;
		COMVERIFY(MGACOLL_ITER->get_ObjType(&ot));
		if(ot != OBJTYPE_ATOM) continue;

		CBuilderAtom* o = CBuilderFactory::Create(CComQIPtr<IMgaAtom>(MGACOLL_ITER), this);

		VERIFY( atomLists.Lookup(o->GetPartName(), objectlist) );
		ASSERT( objectlist );

		objectlist->AddTail(o);
		children.AddTail(o);
	} MGACOLL_ITERATE_END;
}

void CBuilderModel::CreateReferences()
{
	CBuilderReferenceList *objectlist;

	CComPtr<IMgaMetaRoles> roles;
	COMVERIFY( CComQIPtr<IMgaMetaModel>(GetMeta())->get_Roles(&roles) );

	referenceLists.InitHashTable(17);
	modelReferenceLists.InitHashTable(17);
	atomReferenceLists.InitHashTable(17);
	MGACOLL_ITERATE(IMgaMetaRole, roles) {
		CComPtr<IMgaMetaFCO> kind;
		COMVERIFY(MGACOLL_ITER->get_Kind(&kind));
		objtype_enum type;
		COMVERIFY(kind->get_ObjType(&type));
		if( type == OBJTYPE_REFERENCE) {
			CBstr part;
			COMVERIFY(MGACOLL_ITER->get_Name(part) );
			ASSERT( !referenceLists.Lookup(CString(part), objectlist) );

			referenceLists[CString(part)] = new CBuilderReferenceList;
			modelReferenceLists[CString(part)] = new CBuilderModelReferenceList;
			atomReferenceLists[CString(part)] = new CBuilderAtomReferenceList;
		}
	} MGACOLL_ITERATE_END;

	CComPtr<IMgaFCOs> chds;
	COMVERIFY( GetIModel()->get_ChildFCOs(&chds) );
	MGACOLL_ITERATE(IMgaFCO, chds) {

		objtype_enum ot;
		COMVERIFY(MGACOLL_ITER->get_ObjType(&ot));
		if(ot != OBJTYPE_REFERENCE) continue;
		{ 	// test if modelref, also skips NULL references
			CComPtr<IMgaFCO> r = MGACOLL_ITER;
			while(ot == OBJTYPE_REFERENCE) {
				CComPtr<IMgaFCO> rr;
				COMVERIFY(CComQIPtr<IMgaReference>(r)->get_Referred(&rr));
				r = rr;
				if(!r) {
					ot = OBJTYPE_NULL;
					break;
				}
				COMVERIFY(r->get_ObjType(&ot));
			}
		}
		CBuilderReference* oo = CBuilderFactory::Create(CComQIPtr<IMgaReference>(MGACOLL_ITER), this);
		VERIFY( referenceLists.Lookup(oo->GetPartName(), objectlist) );
		ASSERT( objectlist );
		objectlist->AddTail(oo);
		children.AddTail(oo);

		if(oo->IsKindOf(RUNTIME_CLASS(CBuilderModelReference)) ) {
			CBuilderModelReferenceList *mobjectlist;
			VERIFY( modelReferenceLists.Lookup(oo->GetPartName(), mobjectlist) );
			mobjectlist->AddTail((CBuilderModelReference *)oo);
		}
		else if(oo->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference)) ) {
			CBuilderAtomReferenceList *aobjectlist;
			VERIFY( atomReferenceLists.Lookup(oo->GetPartName(), aobjectlist) );
			aobjectlist->AddTail((CBuilderAtomReference *)oo);
		}

	} MGACOLL_ITERATE_END;
}


void CBuilderModel::CreateSets()
{
	CBuilderSetList *objectlist;

	CComPtr<IMgaMetaRoles> roles;
	COMVERIFY( CComQIPtr<IMgaMetaModel>(GetMeta())->get_Roles(&roles) );

	setLists.InitHashTable(17);
	MGACOLL_ITERATE(IMgaMetaRole, roles) {
		CComPtr<IMgaMetaFCO> kind;
		COMVERIFY(MGACOLL_ITER->get_Kind(&kind));
		objtype_enum type;
		COMVERIFY(kind->get_ObjType(&type));
		if( type == OBJTYPE_SET) {
			CBstr part;
			COMVERIFY(MGACOLL_ITER->get_Name(part) );
			ASSERT( !setLists.Lookup(CString(part), objectlist) );

			objectlist = new CBuilderSetList;
			ASSERT(objectlist);

			setLists[CString(part)] = objectlist;
		}
	} MGACOLL_ITERATE_END;

	CComPtr<IMgaFCOs> chds;
	COMVERIFY( GetIModel()->get_ChildFCOs(&chds) );
	MGACOLL_ITERATE(IMgaFCO, chds) {
		objtype_enum ot;
		COMVERIFY(MGACOLL_ITER->get_ObjType(&ot));
		if(ot != OBJTYPE_SET) continue;
		AddSet(CComQIPtr<IMgaSet>(MGACOLL_ITER));
	} MGACOLL_ITERATE_END;

}

void CBuilderModel::CreateConnections()
{
	CBuilderConnectionList *objectlist;


	CComPtr<IMgaMetaRoles> roles;
	COMVERIFY( CComQIPtr<IMgaMetaModel>(GetMeta())->get_Roles(&roles) );

	connectionLists.InitHashTable(17);
	MGACOLL_ITERATE(IMgaMetaRole, roles) {
		CComPtr<IMgaMetaFCO> kind;
		COMVERIFY(MGACOLL_ITER->get_Kind(&kind));
		objtype_enum type;
		COMVERIFY(kind->get_ObjType(&type));
		if( type == OBJTYPE_CONNECTION) {
			CBstr kname;
			COMVERIFY(kind->get_Name(kname) );  // with connection lists we are working with kinds!!!!
			ASSERT( !connectionLists.Lookup(CString(kname), objectlist) );

			objectlist = new CBuilderConnectionList;
			ASSERT(objectlist);

			connectionLists[CString(kname)] = objectlist;
		}
	} MGACOLL_ITERATE_END;

	CComPtr<IMgaFCOs> chds;
	COMVERIFY( GetIModel()->get_ChildFCOs(&chds) );
	MGACOLL_ITERATE(IMgaFCO, chds) {
		objtype_enum ot;
		COMVERIFY(MGACOLL_ITER->get_ObjType(&ot));
		if(ot != OBJTYPE_CONNECTION) continue;
// TODO: skip if not simple....
		CBuilderConnection* o = AddConnection(CComQIPtr<IMgaSimpleConnection>(MGACOLL_ITER));
	} MGACOLL_ITERATE_END;
}

void CBuilderModel::Destroy()
{
	POSITION pos = children.GetHeadPosition();
	while(pos)
		children.GetNext(pos)->Destroy();

	CBuilderObject::Destroy();
}

void CBuilderModel::RemoveMemberFromSets(CBuilderObject *member)
{
	ASSERT(member && member->GetParent() == this );

	POSITION pos = sets.GetHeadPosition();
	while(pos)
		sets.GetNext(pos)->RemoveMember(member);
}

CBuilderConnection *CBuilderModel::AddConnection(IMgaSimpleConnection *iConnection)
{

	CBuilderConnection *conn = CBuilderFactory::Create(iConnection, this);

	FindConnections(conn->GetKindName())->AddTail(conn);
	connchildren.AddTail(conn);	//	!!! A connection is not a child

	return conn;
}



CBuilderSet *CBuilderModel::AddSet(IMgaSet *iSet)
{
	CBuilderSet* cond = CBuilderFactory::Create(iSet, this);

	FindSets(cond->GetPartName())->AddTail(cond);
	sets.AddTail(cond);
	children.AddTail(cond);

	return cond;
}





const CBuilderModelList *CBuilderModel::GetModels(CString name) const
{
	CBuilderModelList *modelList;
	if(!(modelLists.Lookup(name,modelList)))
		modelList = 0;
	return modelList;
}

const CBuilderAtomList *CBuilderModel::GetAtoms(CString name) const
{
	CBuilderAtomList *atomList;
	if(!(atomLists.Lookup(name,atomList)))
		atomList = 0;
	return atomList;
}

const CBuilderReferenceList *CBuilderModel::GetReferences(CString name) const
{
	CBuilderReferenceList *referenceList;
	if(!(referenceLists.Lookup(name,referenceList)))
		referenceList = 0;
	return referenceList;
}

const CBuilderModelReferenceList *CBuilderModel::GetModelReferences(CString name) const
{
	CBuilderModelReferenceList *modelReferenceList;
	if(!(modelReferenceLists.Lookup(name,modelReferenceList)))
		modelReferenceList = 0;
	return modelReferenceList;
}

const CBuilderAtomReferenceList *CBuilderModel::GetAtomReferences(CString name) const
{
	CBuilderAtomReferenceList *atomReferenceList;
	if(!(atomReferenceLists.Lookup(name,atomReferenceList)))
		atomReferenceList = 0;
	return atomReferenceList;
}

void CBuilderModel::RemoveModel(CBuilderModel *model)
{
	ASSERT(model);
	CBuilderModelList *list;
	VERIFY( modelLists.Lookup(model->GetPartName(),list) );
	ASSERT(list);

	POSITION pos = list->Find(model);
	if(pos)
		list->RemoveAt(pos);
}

void CBuilderModel::RemoveModelReference(CBuilderModelReference *modelref)
{
	ASSERT(modelref);
	CBuilderModelReferenceList *list;
	VERIFY( modelReferenceLists.Lookup(modelref->GetPartName(),list) );
	ASSERT(list);

	POSITION pos = list->Find(modelref);
	if(pos)
		list->RemoveAt(pos);
}

void CBuilderModel::RemoveAtom(CBuilderAtom *atom)
{
	ASSERT(atom);
	CBuilderAtomList *list;
	VERIFY( atomLists.Lookup(atom->GetPartName(),list) );
	ASSERT(list);

	POSITION pos = list->Find(atom);
	if(pos)
		list->RemoveAt(pos);
}

void CBuilderModel::RemoveReference(CBuilderReference *ref)
{
	ASSERT(ref);
	CBuilderReferenceList *list;
	VERIFY( referenceLists.Lookup(ref->GetPartName(),list) );
	ASSERT(list);

	POSITION pos = list->Find(ref);
	if(pos)
		list->RemoveAt(pos);
}

void CBuilderModel::RemoveAtomReference(CBuilderAtomReference *atomref)
{
	ASSERT(atomref);
	CBuilderAtomReferenceList *list;
	VERIFY( atomReferenceLists.Lookup(atomref->GetPartName(),list) );
	ASSERT(list);

	POSITION pos = list->Find(atomref);
	if(pos)
		list->RemoveAt(pos);
}

void CBuilderModel::RemoveConnection(CBuilderConnection *conn)
{
	ASSERT(conn);
	CBuilderConnectionList *list;
	VERIFY( connectionLists.Lookup(conn->GetKindName(),list) );
	ASSERT(list);

	POSITION pos = list->Find(conn);
	ASSERT( pos );
	list->RemoveAt(pos);
}

void CBuilderModel::RemoveSet(CBuilderSet *cond)
{
	ASSERT(cond);
	CBuilderSetList *list;
	VERIFY( setLists.Lookup(cond->GetPartName(),list) );
	ASSERT(list);

	POSITION pos = list->Find(cond);
	ASSERT( pos );
	list->RemoveAt(pos);
}

CBuilderConnectionList *CBuilderModel::FindConnections(CString name) const
{
	CBuilderConnectionList *list = NULL;
	connectionLists.Lookup(name,list);
	return list;
}

CBuilderSetList *CBuilderModel::FindSets(CString name) const
{
	CBuilderSetList *list = NULL;
	setLists.Lookup(name,list);
	return list;
}

void CBuilderModel::TraverseModels(void *pointer)
{
	POSITION pos = models.GetHeadPosition();
	while(pos)
		models.GetNext(pos)->TraverseModels();
}

void CBuilderModel::TraverseChildren(void *pointer)
{
	POSITION pos = children.GetHeadPosition();
	while(pos)
		children.GetNext(pos)->TraverseChildren(pointer);
}

void CBuilderModel::Open()
{
	COMVERIFY( GetIModel()->Open() );
}

bool CBuilderModel::IsOpened()
{
	VARIANT_BOOL b = VARIANT_FALSE;
// TODO:
//	COMVERIFY( GetIModel()->get_opened(&b) );
	return b != 0;
}

bool CBuilderModel::Close(bool withchildren)
{
	HRESULT hr = S_OK;
//	TODO:
//	HRESULT hr = GetIModel()->Close(withchildren ? -1 : 0 );
	COMASSERT( hr );

	return hr == S_OK;
}

void CBuilderModel::GetSelection(CBuilderObjectList &list)
{
	ASSERT( list.IsEmpty() );
// TODO:
/*
	SAFEARRAY *psa = NULL;
	COMVERIFY( GetIModel()->GetSelection(&psa) );

	CInterfacePtrList<IMgaObject*> ilist;
	ilist.Load(&psa);

	POSITION pos = ilist.GetHeadPosition();
	while(pos)
		list.AddTail(CBuilder::theInstance->FindObject(ilist.GetNext(pos)));

	ilist.ReleaseAll();
*/
}

void CBuilderModel::SelectionRemoveAll() const
{
// TODO:
//	COMVERIFY( GetIModel()->UnselectAll() );
}

void CBuilderModel::SelectionAdd(CBuilderObjectList& list) const
{
// TODO:
/*
	CInterfacePtrList<IMgaObject*> ilist;

	POSITION pos = list.GetHeadPosition();
	while(pos)
		ilist.AddTail(list.GetNext(pos)->GetIObject());

	SAFEARRAY *psa = ilist.Store();
	COMVERIFY( GetIModel()->Select(&psa) );
	SafeArrayDestroyNoRelease(psa);
*/
}

void CBuilderModel::SelectionRemove(CBuilderObjectList& list) const
{
// TODO:
/*
	CInterfacePtrList<IMgaObject*> ilist;

	POSITION pos = list.GetHeadPosition();
	while(pos)
		ilist.AddTail(list.GetNext(pos)->GetIObject());

	SAFEARRAY *psa = ilist.Store();
	COMVERIFY( GetIModel()->Unselect(&psa) );
	SafeArrayDestroyNoRelease(psa);
*/
}

void CBuilderModel::SelectionAdd(CBuilderObject* object) const
{
/*
	ASSERT( object );

	CBuilderObjectList list;
	list.AddTail(object);
	SelectionAdd(list);
*/
}

void CBuilderModel::SelectionRemove(CBuilderObject* object)	 const
{
/*
	ASSERT( object );

	CBuilderObjectList list;
	list.AddTail(object);
	SelectionRemove(list);
*/
}

void CBuilderModel::SetCurrentAspect(CString& aspect)
{
/*
	COMVERIFY( GetIModel()->put_currentaspectbyname((CBstrIn)aspect) );
*/
}

CString CBuilderModel::GetCurrentAspect()
{
	CBstr ret;
	CComPtr<IMgaMetaAspects> asps;
	COMVERIFY(CComQIPtr<IMgaMetaModel>(GetMeta())->get_Aspects(&asps));
	CComPtr<IMgaMetaAspect> asp;
	COMVERIFY(asps->get_Item(1, &asp));

	COMVERIFY(asp->get_Name(ret));

	return ret;
}

void CBuilderModel::GetAspectNames(CStringList &list)
{
	ASSERT( list.IsEmpty() );

	CComPtr<IMgaMetaAspects> asps;
	COMVERIFY(CComQIPtr<IMgaMetaModel>(GetMeta())->get_Aspects(&asps));

	MGACOLL_ITERATE(IMgaMetaAspect, asps) {
		CBstr ret;
		COMVERIFY(MGACOLL_ITER->get_Name(ret));
		list.AddTail(ret);
	} MGACOLL_ITERATE_END;
}

CBuilderObject *CBuilderModel::CloneHere( CBuilderObject* orig)
{
	CComPtr<IMgaFCO>   src_obj = orig->GetIObject();
	CComPtr<IMgaModel> par_obj = GetIModel();

	CComPtr<IMgaFCOs>       fco_coll;  // ptr to a collection of IMgaFCO objects
	CComPtr<IMgaMetaRoles>  rol_coll;  // same
	fco_coll.CoCreateInstance( L"Mga.MgaFCOs");        // create an empty 'array' of MgaFCO objects
	rol_coll.CoCreateInstance( L"Mga.MgaMetaRoles");   // same

	// fco collection with 1 element
	fco_coll->Append( src_obj);

	CComPtr<IMgaMetaRole> role;
	src_obj->get_MetaRole(&role);
	
	// role collection with 1 element
	rol_coll->Append( role); // based on the assumption that the parent of src_obj is of same or similar kind to par_obj

	CComPtr<IMgaFCOs> dst_coll;
	par_obj->CopyFCOs( fco_coll, rol_coll, &dst_coll);

	// analyze dst_coll
	long l = 0;
	if( dst_coll) dst_coll->get_Count( &l);

	CBuilderObject *return_value = 0;
	for( int i = 1; i <= l; ++i)
	{
		CComPtr<IMgaFCO> dst;
		dst_coll->get_Item( i, &dst);

		objtype_enum ot;
		if( dst) dst->get_ObjType( &ot);
		if( ot == OBJTYPE_ATOM)
		{
			CBuilderAtom* o = CBuilderFactory::Create(CComQIPtr<IMgaAtom>(dst), this);

			children.AddTail(o);

			CBuilderAtomList *objectlist;
			VERIFY( atomLists.Lookup( o->GetPartName(), objectlist) );
			objectlist->AddTail(o);

			return_value = o;
		}
		else if( ot == OBJTYPE_MODEL)
		{
			CBuilderModel* o = CBuilderFactory::Create( CComQIPtr<IMgaModel>(dst), this);
			o->Resolve();

			children.AddTail(o);
			models.AddTail(o);

			CBuilderModelList *objectlist;
			VERIFY( modelLists.Lookup( o->GetPartName(), objectlist) );
			objectlist->AddTail(o);

			return_value = o;
		}
		else if( ot == OBJTYPE_SET)
		{
			CBuilderSet* o = CBuilderFactory::Create( CComQIPtr<IMgaSet>(dst), this);

			FindSets( o->GetPartName())->AddTail( o);
			sets.AddTail(o);
			children.AddTail(o);

			return_value = o;
		}
		else if( ot == OBJTYPE_REFERENCE)
		{
			CBuilderReference* oo = CBuilderFactory::Create(CComQIPtr<IMgaReference>(dst), this);

			CBuilderReferenceList *objectlist;
			VERIFY( referenceLists.Lookup( oo->GetPartName(), objectlist) );
			objectlist->AddTail(oo);

			children.AddTail(oo);

			if(oo->IsKindOf(RUNTIME_CLASS(CBuilderModelReference)) ) {
					CBuilderModelReferenceList *mobjectlist;
					VERIFY( modelReferenceLists.Lookup(oo->GetPartName(), mobjectlist) );
					mobjectlist->AddTail((CBuilderModelReference *)oo);
			}
			else if(oo->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference)) ) {
					CBuilderAtomReferenceList *aobjectlist;
					VERIFY( atomReferenceLists.Lookup(oo->GetPartName(), aobjectlist) );
					aobjectlist->AddTail((CBuilderAtomReference *)oo);
			}

			return_value = oo;
		}
	}

	return return_value;
}

CBuilderModel *CBuilderModel::CreateNewModel(CString partName, CBuilderModel *baseType, bool instance)
{
	CBuilderModelList *objectlist;
	VERIFY( modelLists.Lookup(partName, objectlist) );

	CBstr rname(partName);
	CComPtr<IMgaMetaRole> role;
	COMVERIFY( CComQIPtr<IMgaMetaModel>(GetMeta())->get_RoleByName((CBstrIn)rname, &role) );
	ASSERT(role);
	CComPtr<IMgaFCO> i = NULL;
	if (baseType) {
		COMVERIFY(GetIModel()->DeriveChildObject(baseType->GetIModel(), role,
			instance ? VARIANT_TRUE : VARIANT_FALSE, &i));
	}
	else {
		COMVERIFY( GetIModel()->CreateChildObject(role, &i) );
	}
	ASSERT( i != NULL );


	CBuilderModel* o = CBuilderFactory::Create(CComQIPtr<IMgaModel>(i), this);
	o->Resolve();
	objectlist->AddTail(o);
	children.AddTail(o);
	models.AddTail(o);

	return o;
}

CBuilderAtom *CBuilderModel::CreateNewAtom(CString partName, CBuilderAtom *baseType, bool instance)
{
	CBuilderAtomList *objectlist;
	VERIFY( atomLists.Lookup(partName, objectlist) );

	CBstr rname(partName);
	CComPtr<IMgaMetaRole> role;
	COMVERIFY( CComQIPtr<IMgaMetaModel>(GetMeta())->get_RoleByName((CBstrIn)rname, &role) );
	ASSERT(role);
	CComPtr<IMgaFCO> i = NULL;
	if (baseType) {
		COMVERIFY(GetIModel()->DeriveChildObject(baseType->GetIAtom(), role,
			instance ? VARIANT_TRUE : VARIANT_FALSE, &i));
	}
	else {
		COMVERIFY( GetIModel()->CreateChildObject(role, &i) );
	}
	ASSERT( i != NULL );


	CBuilderAtom* o = CBuilderFactory::Create(CComQIPtr<IMgaAtom>(i), this);
// TODO: Refresh Ports in referencing objects......!!!!

	objectlist->AddTail(o);
	children.AddTail(o);
	return o;
}


CBuilderReference *CBuilderModel::CreateNewReference(CString refPartName, CBuilderObject *refTo,  CBuilderReference *baseType, bool instance) {
	CBuilderReferenceList *objectlist;
	VERIFY( referenceLists.Lookup(refPartName, objectlist) );

	CBstr rname(refPartName);
	CComPtr<IMgaMetaRole> role;
	COMVERIFY( CComQIPtr<IMgaMetaModel>(GetMeta())->get_RoleByName((CBstrIn)rname, &role) );
	ASSERT(role);
	CComPtr<IMgaFCO> i = NULL;
	if (baseType) {
		ASSERT(refTo == NULL);
		COMVERIFY(GetIModel()->DeriveChildObject(baseType->GetIRef(), role,
			instance ? VARIANT_TRUE : VARIANT_FALSE, &i));
	}
	else {
		COMVERIFY( GetIModel()->CreateReference(role, refTo ? refTo->GetIObject() : NULL, &i) );
	}
	
	ASSERT( i != NULL );
	CBuilderReference* oo = CBuilderFactory::Create(CComQIPtr<IMgaReference>(i), this);
	objectlist->AddTail(oo);
	children.AddTail(oo);

	if(oo->IsKindOf(RUNTIME_CLASS(CBuilderModelReference)) ) {
			CBuilderModelReferenceList *mobjectlist;
			VERIFY( modelReferenceLists.Lookup(refPartName, mobjectlist) );
			mobjectlist->AddTail((CBuilderModelReference *)oo);
	}
	else if(oo->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference)) ) {
			CBuilderAtomReferenceList *aobjectlist;
			VERIFY( atomReferenceLists.Lookup(refPartName, aobjectlist) );
			aobjectlist->AddTail((CBuilderAtomReference *)oo);
	}

	return oo;
}


CBuilderModelReference *CBuilderModel::CreateNewModelReference(CString refPartName, CBuilderObject *refTo)
{
	ASSERT( refTo );
	ASSERT( refTo->IsKindOf(RUNTIME_CLASS(CBuilderModel)) ||
		refTo->IsKindOf(RUNTIME_CLASS(CBuilderModelReference)) );

	CBuilderReference *nobj = CreateNewReference(refPartName, refTo);
	ASSERT( nobj->IsKindOf(RUNTIME_CLASS(CBuilderModelReference)) );


	return (CBuilderModelReference *)nobj;

}

CBuilderAtomReference *CBuilderModel::CreateNewAtomReference(CString refPartName, CBuilderObject *refTo)
{
	ASSERT( refTo );
	ASSERT( refTo->IsKindOf(RUNTIME_CLASS(CBuilderAtom)) ||
		refTo->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference)) );

	CBuilderReference *nobj = CreateNewReference(refPartName, refTo);
	ASSERT( nobj->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference)) );


	return (CBuilderAtomReference *)nobj;
}


CBuilderConnection *CBuilderModel::CreateNewConnection(CString connName, CBuilderObject *source, CBuilderObject *destination)
{
//DONE
	CComPtr<IMgaFCOs> srcrefs, dstrefs;
	CComPtr<IMgaFCO> srcfco, dstfco;
	CBuilderObject const *src = source;
	if(src->IsKindOf(RUNTIME_CLASS(CBuilderReferencePort))) {
		srcfco = src->GetIObject();
		src = ((CBuilderReferencePort*)src)->GetOwner();
		while(src->IsKindOf(RUNTIME_CLASS(CBuilderModelReference))) {
			COMVERIFY(src->GetIObject()->CreateCollection(&srcrefs));
			src=((CBuilderModelReference*)src)->GetReferred();
		}
		if(!src->IsKindOf(RUNTIME_CLASS(CBuilderModel))) COMVERIFY(E_INCONSISTENCY);
		srcfco = source->GetIObject();
		if(src != ((CBuilderReferencePort*)source)->GetPortObject()->GetParent()) COMVERIFY(E_INCONSISTENCY);
	}
	else {
		while(src->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference))) {
			COMVERIFY(src->GetIObject()->CreateCollection(&srcrefs));
			src=((CBuilderAtomReference*)src)->GetReferred();
		}
		// if(!src->IsKindOf(RUNTIME_CLASS(CBuilderAtom))) COMVERIFY(E_INCONSISTENCY);
		srcfco = src->GetIObject();
	}

	CBuilderObject const *dst = destination;
	if(dst->IsKindOf(RUNTIME_CLASS(CBuilderReferencePort))) {
		dstfco = dst->GetIObject();
		dst = ((CBuilderReferencePort*)dst)->GetOwner();
		while(dst->IsKindOf(RUNTIME_CLASS(CBuilderModelReference))) {
			COMVERIFY(dst->GetIObject()->CreateCollection(&dstrefs));
			dst=((CBuilderModelReference*)dst)->GetReferred();
		}
		if(!dst->IsKindOf(RUNTIME_CLASS(CBuilderModel))) COMVERIFY(E_INCONSISTENCY);
		dstfco = destination->GetIObject();
		if(dst != ((CBuilderReferencePort*)destination)->GetPortObject()->GetParent()) COMVERIFY(E_INCONSISTENCY);
	}
	else {
		while(dst->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference))) {
			COMVERIFY(dst->GetIObject()->CreateCollection(&dstrefs));
			dst=((CBuilderAtomReference*)dst)->GetReferred();
		}
		// if(!dst->IsKindOf(RUNTIME_CLASS(CBuilderAtom))) COMVERIFY(E_INCONSISTENCY);
		dstfco = dst->GetIObject();
	}

	CComPtr<IMgaMetaRole> role;
	COMVERIFY(CComQIPtr<IMgaMetaModel>(GetMeta())->get_RoleByName((CBstrIn)connName, &role));
	VERIFY(role);
	CComPtr<IMgaFCO> iconn;
	CComPtr<IMgaSimpleConnection> sconn;
	COMVERIFY( GetIModel()->CreateSimpleConn(role, srcfco, dstfco, srcrefs, dstrefs, &iconn) );
	COMVERIFY(iconn.QueryInterface(&sconn));
	VERIFY( sconn );

	CBuilderConnection *conn = AddConnection(sconn);
	conn->Resolve();

	return conn;
}

CBuilderSet *CBuilderModel::CreateNewSet(CString condPartName, CBuilderSet *baseType, bool instance) {
	CBuilderSetList *objectlist;
	VERIFY( setLists.Lookup(condPartName, objectlist) );

	CBstr rname(condPartName);
	CComPtr<IMgaMetaRole> role;
	COMVERIFY( CComQIPtr<IMgaMetaModel>(GetMeta())->get_RoleByName((CBstrIn)rname, &role) );
// TODO: check if it is a
	ASSERT(role);

	CComPtr<IMgaFCO> i;
	HRESULT hr;
	if (baseType) {
		hr = GetIModel()->DeriveChildObject(baseType->GetISet(), role,
			instance ? VARIANT_TRUE : VARIANT_FALSE, &i);
	}
	else {
		hr = GetIModel()->CreateChildObject(role, &i);
	}

	CComQIPtr<IMgaSet> icond = i;

	if( !SUCCEEDED(hr) )
	{
		ASSERT( icond == NULL );
		return NULL;
	}

	CBuilderSet *cond = AddSet(icond);
	ASSERT(cond);

	return cond;
}

////////////////////////////////// CBuilderAtom //////////////////////////////////
IMPLEMENT_DYNAMIC(CBuilderAtom,CBuilderObject)

CBuilderAtom::CBuilderAtom(IMgaAtom *iAtom,CBuilderModel *aparent) : CBuilderObject(iAtom,aparent)
{
	CBstr bbstr;
	COMVERIFY( iAtom->get_ID(bbstr));
	CString aaa = bbstr;
	CBstr bstr;
	COMVERIFY( GetMeta()->get_DisplayedName(bstr) );
	kindTitle = bstr;
}

CBuilderAtom::~CBuilderAtom()
{
	ASSERT(parent);
	parent->RemoveAtom(this);
}

void CBuilderAtom::Resolve() {
}

////////////////////////////// CBuilderReference //////////////////////////////
IMPLEMENT_DYNAMIC(CBuilderReference,CBuilderObject)

CBuilderReference::CBuilderReference(IMgaReference *iRef,CBuilderModel *aparent) : CBuilderObject(iRef,aparent)
{
	ref = NULL;
}

CBuilderReference::~CBuilderReference()
{
	ASSERT(parent);
	parent->RemoveReference(this);
}

void CBuilderReference::Resolve() {
	CComPtr<IMgaFCO> i;
	COMVERIFY( GetIRef()->get_Referred(&i) );
	if(i) ref = CBuilder::theInstance->FindObject(i);
	else ref = NULL;
}

const CBuilderObject::objtype CBuilderReference::GetReferredType() const {
	if(ref == NULL) return CBuilderObject::OBJNULL;
	return ref->GetObjType();
}

bool CBuilderReference::PutReferred(CBuilderObject *nref)  {
	ref = nref;
	return false;
}

////////////////////////////// CBuilderAtomReference //////////////////////////////
IMPLEMENT_DYNAMIC(CBuilderAtomReference,CBuilderReference)

CBuilderAtomReference::CBuilderAtomReference(IMgaReference *iAtomRef,CBuilderModel *aparent) : CBuilderReference(iAtomRef,aparent)
{
}

CBuilderAtomReference::~CBuilderAtomReference()
{
	ASSERT(parent);
	parent->RemoveAtomReference(this);
}

void CBuilderAtomReference::Resolve()
{
	CBuilderReference::Resolve();
	ASSERT( ref->IsKindOf(RUNTIME_CLASS(CBuilderAtom)) ||
		ref->IsKindOf(RUNTIME_CLASS(CBuilderAtomReference)) );
}

////////////////////////////// CBuilderReferencePort //////////////////////////////
IMPLEMENT_DYNAMIC(CBuilderReferencePort,CBuilderObject)

CBuilderReferencePort::CBuilderReferencePort(IMgaFCO *iPort,CBuilderModelReference *o) :
	CBuilderObject(iPort,o->parent, false), owner(o)
{

	o->SetPortRef(iPort, this);
}

void CBuilderReferencePort::Resolve()
{
// TODO: test if it into to a valid location: parent of target is reacheable by ref chain

	CBuilderObject* o = CBuilder::theInstance->FindObject(GetIObject());

	portobj = o;

}

////////////////////////////// CBuilderModelReference //////////////////////////////
IMPLEMENT_DYNAMIC(CBuilderModelReference,CBuilderReference)

CBuilderModelReference::CBuilderModelReference(IMgaReference *iModelRef,CBuilderModel *aparent) : CBuilderReference(iModelRef,aparent) {
	CreateReferencePorts();
}

CBuilderModelReference::~CBuilderModelReference()
{
	POSITION pos = refPorts.GetHeadPosition();
	while(pos) {
		CBuilderReferencePort *o = refPorts.GetNext(pos);
		ForgetPortRef(o->GetIObject());
		delete o;
	}
	ASSERT(parent);
	parent->RemoveModelReference(this);
}

void CBuilderModelReference::CreateReferencePorts()
{
	CComPtr<IMgaFCOs> children;
	CComPtr<IMgaFCO> r = GetIModelRef();
	while(1) {
		CComPtr<IMgaFCO> rr;
		COMVERIFY(CComQIPtr<IMgaReference>(r)->get_Referred(&rr));
		r = rr;
		if(!r) break;
		objtype_enum o;
		COMVERIFY(r->get_ObjType(&o));
		if(o == OBJTYPE_MODEL) break;
		ASSERT(o == OBJTYPE_REFERENCE);
	}
   if(r) {
	COMVERIFY(CComQIPtr<IMgaModel>(r)->get_ChildFCOs(&children));
	MGACOLL_ITERATE(IMgaFCO, children) {
		objtype_enum o;
		COMVERIFY(MGACOLL_ITER->get_ObjType(&o));
		{
			CComPtr<IMgaFCO> &iportobj=MGACOLL_ITER;
			CComPtr<IMgaMetaRole> role;
			CComPtr<IMgaMetaParts> parts;
			COMVERIFY(MGACOLL_ITER->get_MetaRole(&role));
			COMVERIFY(role->get_Parts(&parts));
			MGACOLL_ITERATE(IMgaMetaPart, parts) {
				VARIANT_BOOL vv;
				COMVERIFY(MGACOLL_ITER->get_IsLinked(&vv));
				if(vv) break;
			}
			if(!MGACOLL_AT_END) {
				CBuilderReferencePort *bport = new CBuilderReferencePort(iportobj,this);
				refPorts.AddTail(bport);
			}
			MGACOLL_ITERATE_END;
		}
	}	MGACOLL_ITERATE_END;
   }
}

void CBuilderModelReference::Destroy() {
	POSITION pos = refPorts.GetHeadPosition();
	while(pos)
		refPorts.GetNext(pos)->Destroy();

	CBuilderObject::Destroy();
}

void CBuilderModelReference::Resolve() {
	CBuilderReference::Resolve();
	ASSERT( ref->IsKindOf(RUNTIME_CLASS(CBuilderModel)) ||
		ref->IsKindOf(RUNTIME_CLASS(CBuilderModelReference)) );

	POSITION pos = refPorts.GetHeadPosition();
	while(pos)
		refPorts.GetNext(pos)->Resolve();

}

IMgaObject *CBuilderModelReference::GetPort(CString aspectName,CBuilderReferencePort *port) const
{
	return port->GetIObject();
}

CBuilderReferencePort *CBuilderModelReference::FindPortRef(IMgaFCO *i) const {
	ASSERT(i);
#ifdef STRONG_LOOKUP
	CComPtr<IUnknown> iu;
	CComPtr<IMgaFCO> ii = i;
	ii.QueryInterface(&iu);
	ASSERT(iu);

	CBuilderReferencePort* o = NULL;
//	VERIFY( objectmap.Lookup(iu, o) );
	if( !objectmap.Lookup(iu, o) )
	{
		CBstr idstr;
		COMVERIFY( i->get_ID(idstr) );
		ASSERT(false);
	}
	ASSERT(o);

	return o;
#else
	CBuilderReferencePort* o = NULL;
//	VERIFY( objectmap.Lookup(i, o) );
	if( !objectmap.Lookup(i, o) )
	{
		CBstr idstr;
		COMVERIFY( i->get_ID(idstr) );
		ASSERT(false);
	}
	ASSERT(o);

	return o;
#endif
}

void CBuilderModelReference::SetPortRef(IMgaFCO *i, CBuilderReferencePort *o) {
	ASSERT(i && o);

#ifdef STRONG_LOOKUP
	CComPtr<IUnknown> iu;
	CComPtr<IMgaFCO> ii = i;
	ii.QueryInterface(&iu);
	ASSERT(iu);

	// We CANNOT Release the IUnknown interface here, since it can be the last
	// ptr and next time the marshalling code will assign a new ptr to this
	// interface

	CBuilderReferencePort* o2;
	if( objectmap.Lookup(iu, o2) )	{
		ASSERT( o == o2 );
	}
	else
		objectmap.SetAt(iu, o);
#else
	objectmap.SetAt(i ,o);
#endif
}

void CBuilderModelReference::ForgetPortRef(IMgaFCO* i) {
	ASSERT(i);

#ifdef STRONG_LOOKUP
	CComPtr<IUnknown> iu;
	CComPtr<IMgaFCO> ii = i;
	ii.QueryInterface(&iu);
	ASSERT(iu);
	objectmap.RemoveKey(iu);
#else
	objectmap.RemoveKey(i);
#endif
}

/////////////////////////////// CBuilderConnection ///////////////////////////////
IMPLEMENT_DYNAMIC(CBuilderConnection,CBuilderObject)

CBuilderConnection::CBuilderConnection(IMgaSimpleConnection *c,CBuilderModel *o) :
	CBuilderObject(c,o), owner(parent)
{
	ASSERT(ciConnection && owner);
}

CBuilderConnection::~CBuilderConnection()
{

	src->RemoveOutConnection(this);
	dst->RemoveInConnection(this);
	owner->RemoveConnection(this);

	ASSERT( CBuilder::theInstance );
	CBuilder::theInstance->ForgetObjectRef(ciConnection);
}

void CBuilderConnection::Destroy()
{
	ASSERT(ciConnection);
	COMVERIFY(ciConnection->DestroyObject());

	ASSERT(owner);
	owner->RemoveMemberFromSets(this);

	delete this;
}

void CBuilderConnection::Resolve() {
	ASSERT(ciConnection);

	CComPtr<IMgaFCO> isrc;
	CComPtr<IMgaFCO> idst;
	CComPtr<IMgaFCOs> isrcrefs;
	CComPtr<IMgaFCOs> idstrefs;

	COMVERIFY(CComQIPtr<IMgaSimpleConnection>(ciConnection)->get_Src(&isrc) );
	COMVERIFY(CComQIPtr<IMgaSimpleConnection>(ciConnection)->get_SrcReferences(&isrcrefs) );

	long isrcrcnt;
	COMVERIFY(isrcrefs->get_Count(&isrcrcnt));
	CBuilderObject *endobj = CBuilder::theInstance->FindObject(isrc);
	if(isrcrcnt) {
		CComPtr<IMgaFCO> frTemp;
		COMVERIFY( isrcrefs->get_Item( 1, &frTemp ) );
		CComPtr<IMgaFCO> lrTemp;
		COMVERIFY( isrcrefs->get_Item( isrcrcnt, &lrTemp ) );
		CBuilderReference* frRef = (CBuilderReference*) CBuilder::theInstance->FindObject( frTemp );
		CBuilderReference* lrRef = (CBuilderReference*) CBuilder::theInstance->FindObject( lrTemp );
		if ( lrRef->GetReferred() == endobj )
			src = frRef;
		else
			src = ( (CBuilderModelReference*) frRef )->FindPortRef( isrc );
	}
	else {
		src = endobj;
	}

	COMVERIFY(CComQIPtr<IMgaSimpleConnection>(ciConnection)->get_Dst(&idst) );
	COMVERIFY(CComQIPtr<IMgaSimpleConnection>(ciConnection)->get_DstReferences(&idstrefs) );

	endobj = CBuilder::theInstance->FindObject(idst);
	long dstrcnt;
	COMVERIFY(idstrefs->get_Count(&dstrcnt));
	if(dstrcnt) {
		CComPtr<IMgaFCO> frTemp;
		COMVERIFY( idstrefs->get_Item( 1, &frTemp ) );
		CComPtr<IMgaFCO> lrTemp;
		COMVERIFY( idstrefs->get_Item( dstrcnt, &lrTemp ) );
		CBuilderReference* frRef = (CBuilderReference*) CBuilder::theInstance->FindObject( frTemp );
		CBuilderReference* lrRef = (CBuilderReference*) CBuilder::theInstance->FindObject( lrTemp );
		if ( lrRef->GetReferred() == endobj )
			dst = frRef;
		else
			dst = ( (CBuilderModelReference*) frRef )->FindPortRef( idst );
	}
	else {
		dst = endobj;
	}

	CBuilderObject* srcParent = NULL;
	CBuilderObject* dstParent = NULL;
	if ( src->IsKindOf( RUNTIME_CLASS( CBuilderReferencePort ) ) )
		srcParent = (CBuilderObject*) ( ( CBuilderReferencePort*) src )->GetOwner();
	else
		srcParent = (CBuilderObject*) src->GetParent();
	if ( dst->IsKindOf( RUNTIME_CLASS( CBuilderReferencePort ) ) )
		dstParent = (CBuilderObject*) ( ( CBuilderReferencePort*) dst )->GetOwner();
	else
		dstParent = (CBuilderObject*) dst->GetParent();

	CBuilderObject* srcParent2 = ( srcParent) ? (CBuilderObject*) srcParent->GetParent() : NULL;
	CBuilderObject* dstParent2 = ( dstParent) ? (CBuilderObject*) dstParent->GetParent() : NULL;
	
	if ( srcParent ) {
		if ( srcParent->IsKindOf( RUNTIME_CLASS( CBuilderModelReference ) ) )
			srcParent->AddPortOutConnection( kindName,this );
		else if ( srcParent2 && ( srcParent2 == dstParent || dstParent2 && srcParent2 == dstParent2 ) )
			srcParent->AddPortOutConnection( kindName,this );
	}
	if ( dstParent ) {
		if ( dstParent->IsKindOf( RUNTIME_CLASS( CBuilderModelReference ) ) )
			dstParent->AddPortInConnection( kindName,this );
		else if ( dstParent2 && ( dstParent2 == srcParent || srcParent2 && dstParent2 == srcParent2 ) )
			dstParent->AddPortInConnection( kindName,this );
	}

	src->AddOutConnection(kindName,this);
	dst->AddInConnection(kindName,this);
}

////////////////////////////// CBuilderSet ///////////////////////////////
IMPLEMENT_DYNAMIC(CBuilderSet,CBuilderObject)

CBuilderSet::CBuilderSet(IMgaSet *iCond,CBuilderModel *own)
	: CBuilderObject(iCond, own) {
	ASSERT(iSet);
}



void CBuilderSet::Resolve() {
/*
	CComBSTR name = GetName();
	if(name.Length() == 0) ASSERT(false);
	wchar_t *cur = wcschr(name, ':');
	if(cur == NULL) cur = name;
	ASSERT(*cur != L'\0');
	CComPtr<IMgaFCOs> objs;
	COMTHROW(owner->GetIModel()->get_ChildFCOs(&objs));
	while(cur) {
		wchar_t *nextseg = wcschr(name, '+');
		if(nextseg != NULL) *nextseg++ = 0;
		bool ok = false;
		MGACOLL_ITERATE(IMgaFCO, objs) {
			objtype_enum ot;
			COMVERIFY(MGACOLL_ITER->get_ObjType(&ot));
			if(ot != OBJTYPE_CONNECTION && ot != OBJTYPE_SET) {
				CComBSTR childname;
				COMVERIFY(MGACOLL_ITER->get_Name(&childname));
				if(childname == cur) {
					InsertControl(CBuilder::theInstance->FindObject(MGACOLL_ITER));
					break;
				}
			}
		}
		if(MGACOLL_AT_END) { ASSERT(false); }
		MGACOLL_ITERATE_END;
		cur = nextseg;
	}
*/

	{
		CComPtr<IMgaFCOs> psa;
		COMVERIFY( CComQIPtr<IMgaSet>(iSet)->get_Members(&psa) );

		MGACOLL_ITERATE(IMgaFCO, psa) {
			    InsertMember(CBuilder::theInstance->FindObject(MGACOLL_ITER));
/*
			objtype_enum ot;
			COMVERIFY(MGACOLL_ITER->get_ObjType(&ot));
			if(ot != OBJTYPE_CONNECTION) {
			    InsertPart(CBuilder::theInstance->FindObject(MGACOLL_ITER));
			}
			else {
			    InsertConnection(CBuilder::theInstance->FindConnection(CComQIPtr<IMgaSimpleConnection>(MGACOLL_ITER)));
			}
*/
		} MGACOLL_ITERATE_END;
	}
}



CBuilderSet::~CBuilderSet()
{
	ASSERT(iSet);

	parent->RemoveSet(this);
}

/*
void CBuilderSet::Destroy()
{
	ASSERT(iSet);

	long objid = GetObjId();
	ASSERT(owner);
	IMgaModel *imodel = owner->GetIModel();

	delete this;

	COMVERIFY( imodel->DeleteSet(objid) );
}
*/

bool CBuilderSet::AddMember(CBuilderObject *member)
{
	ASSERT( member && member->GetParent() == parent  );

	if( members.Find(member) )
		return false;

	COMVERIFY( CComQIPtr<IMgaSet>(iSet)->AddMember(member->GetIObject()) );

	members.AddTail(member);
	return true;
}

bool CBuilderSet::RemoveMember(CBuilderObject *member)
{
	ASSERT( member && member->GetParent() == parent );

	POSITION pos = members.Find(member);
	if( !pos )
		return false;

	COMVERIFY( CComQIPtr<IMgaSet>(iSet)->RemoveMember(member->GetIObject()) );

	members.RemoveAt(pos);
	return true;
}


// -------------------------- BuilderFactory

int MyMessageBox(LPCTSTR lpszText, UINT nType = MB_OK)
{
	return ::MessageBox(NULL, lpszText, "Builder Factory Error", nType);
}

CBuilderFactory::~CBuilderFactory()
{
	if( modelBuildFunctions )
	{
		delete modelBuildFunctions;
		modelBuildFunctions = NULL;
	}
	if( atomBuildFunctions )
	{
		delete atomBuildFunctions;
		atomBuildFunctions = NULL;
	}
	if( modelRefBuildFunctions )
	{
		delete modelRefBuildFunctions;
		modelRefBuildFunctions = NULL;
	}
	if( atomRefBuildFunctions )
	{
		delete atomRefBuildFunctions;
		atomRefBuildFunctions = NULL;
	}
}

CBuilderModelCreateFunctionTable* CBuilderFactory::modelBuildFunctions = NULL;
CBuilderAtomCreateFunctionTable* CBuilderFactory::atomBuildFunctions = NULL;

CBuilderRefCreateFunctionTable* CBuilderFactory::refBuildFunctions = NULL;
CBuilderModelRefCreateFunctionTable* CBuilderFactory::modelRefBuildFunctions = NULL;
CBuilderAtomRefCreateFunctionTable* CBuilderFactory::atomRefBuildFunctions = NULL;

CBuilderConnectionCreateFunctionTable* CBuilderFactory::connectionBuildFunctions = NULL;
CBuilderSetCreateFunctionTable* CBuilderFactory::setBuildFunctions = NULL;

CStringList CBuilderFactory::modelkindnames;
CStringList CBuilderFactory::atomkindnames;
CStringList CBuilderFactory::refkindnames;
CStringList CBuilderFactory::connectionkindnames;
CStringList CBuilderFactory::setkindnames;

CBuilderFactory::CBuilderFactory(CString kindnames, CBuilderModelCreateFunction createFn)
{
	if(modelBuildFunctions == NULL) {
		modelBuildFunctions = new CBuilderModelCreateFunctionTable;
		modelBuildFunctions->InitHashTable(29);
	}
	while( !kindnames.IsEmpty() )
	{
		CString trash = kindnames.SpanIncluding(",;");
		kindnames = kindnames.Mid(trash.GetLength());
		if( kindnames.IsEmpty() )
			break;
		CString kindname = kindnames.SpanExcluding(",;");
		kindnames = kindnames.Mid(kindname.GetLength());
		ASSERT(!kindname.IsEmpty());

		CBuilderModelCreateFunction fn;
		if(modelBuildFunctions->Lookup(kindname,fn)) {
			CString msg = "Create function already exists for object type " + kindname;
			MyMessageBox(msg,MB_OK | MB_ICONSTOP);
			return;
		}
		(*modelBuildFunctions)[kindname] = createFn;
	}
}

CBuilderModel *CBuilderFactory::Create(IMgaModel* iModel, CBuilderModel *aparent)
{
	if( modelBuildFunctions )
	{
		CBstr bstr;
		{
			CComPtr<IMgaMetaFCO> meta;
			COMVERIFY(iModel->get_Meta(&meta));
			COMVERIFY(meta->get_Name(bstr));
		}
		CString kindname(bstr);

		if( modelkindnames.Find(kindname) == NULL )
		{
			CString msg;
			msg.Format("Model kindname \"%s\" was not found in paradigm.", (const char*) kindname);
			MyMessageBox(msg, MB_OK | MB_ICONSTOP);
		}

		CBuilderModelCreateFunction fn;

		if(modelBuildFunctions->Lookup(kindname,fn))
			return fn(iModel,aparent);

		if(modelBuildFunctions->Lookup("*",fn))
			return fn(iModel,aparent);
	}

	CBuilderModel *ret = new CBuilderModel(iModel, aparent);
	ASSERT(ret);
	return ret;
}

CBuilderFactory::CBuilderFactory(CString kindnames, CBuilderAtomCreateFunction createFn)
{
	if(atomBuildFunctions == NULL) {
		atomBuildFunctions = new CBuilderAtomCreateFunctionTable;
		atomBuildFunctions->InitHashTable(29);
	}
	while( !kindnames.IsEmpty() )
	{
		CString trash = kindnames.SpanIncluding(",;");
		kindnames = kindnames.Mid(trash.GetLength());
		if( kindnames.IsEmpty() )
			break;
		CString kindname = kindnames.SpanExcluding(",;");
		kindnames = kindnames.Mid(kindname.GetLength());
		ASSERT(!kindname.IsEmpty());

		CBuilderAtomCreateFunction fn;
		if(atomBuildFunctions->Lookup(kindname,fn)) {
			CString msg = "Create function already exists for object type " + kindname;
			MyMessageBox(msg,MB_OK | MB_ICONSTOP);
			return;
		}
		(*atomBuildFunctions)[kindname] = createFn;
	}
}

CBuilderAtom *CBuilderFactory::Create(IMgaAtom* iAtom, CBuilderModel *aparent)
{
	if( atomBuildFunctions )
	{
		CBstr bstr;
		{
			CComPtr<IMgaMetaFCO> meta;
			COMVERIFY(iAtom->get_Meta(&meta));
			COMVERIFY(meta->get_Name(bstr));
		}
		CString kindname(bstr);

		if( atomkindnames.Find(kindname) == NULL )
		{
			CString msg;
			msg.Format("Atom kindname \"%s\" was not found in paradigm.", (const char*) kindname);
			MyMessageBox(msg, MB_OK | MB_ICONSTOP);
		}

		CBuilderAtomCreateFunction fn;

		if(atomBuildFunctions->Lookup(kindname,fn))
			return fn(iAtom,aparent);

		if(atomBuildFunctions->Lookup("*",fn))
			return fn(iAtom,aparent);
	}

	CBuilderAtom *ret = new CBuilderAtom(iAtom, aparent);
	ASSERT(ret);
	return ret;
}



CBuilderFactory::CBuilderFactory(CString kindnames, CBuilderRefCreateFunction createFn)
{
	if(refBuildFunctions == NULL) {
		refBuildFunctions = new CBuilderRefCreateFunctionTable;
		refBuildFunctions->InitHashTable(29);
	}
	while( !kindnames.IsEmpty() )
	{
		CString trash = kindnames.SpanIncluding(",;");
		kindnames = kindnames.Mid(trash.GetLength());
		if( kindnames.IsEmpty() )
			break;
		CString kindname = kindnames.SpanExcluding(",;");
		kindnames = kindnames.Mid(kindname.GetLength());
		ASSERT(!kindname.IsEmpty());

		CBuilderRefCreateFunction fn;
		CBuilderModelRefCreateFunction fnm;
		CBuilderAtomRefCreateFunction fna;
		if(refBuildFunctions && refBuildFunctions->Lookup(kindname,fn) ||
		   modelRefBuildFunctions && modelRefBuildFunctions->Lookup(kindname,fnm) ||
		   atomRefBuildFunctions && atomRefBuildFunctions->Lookup(kindname,fna)) {
				CString msg = "Create function already exists for object type " + kindname;
				MyMessageBox(msg,MB_OK | MB_ICONSTOP);
				return;

		}
		(*refBuildFunctions)[kindname] = createFn;
	}
}


CBuilderFactory::CBuilderFactory(CString kindnames, CBuilderModelRefCreateFunction createFn) {
	if(modelRefBuildFunctions == NULL) {
		modelRefBuildFunctions = new CBuilderModelRefCreateFunctionTable;
		modelRefBuildFunctions->InitHashTable(29);
	}
	while( !kindnames.IsEmpty() )
	{
		CString trash = kindnames.SpanIncluding(",;");
		kindnames = kindnames.Mid(trash.GetLength());
		if( kindnames.IsEmpty() )
			break;
		CString kindname = kindnames.SpanExcluding(",;");
		kindnames = kindnames.Mid(kindname.GetLength());
		ASSERT(!kindname.IsEmpty());

		CBuilderRefCreateFunction fn;
		CBuilderModelRefCreateFunction fnm;
		if(refBuildFunctions && refBuildFunctions->Lookup(kindname,fn) ||
		   modelRefBuildFunctions && modelRefBuildFunctions->Lookup(kindname,fnm)) {
			CString msg = "Create function already exists for object type " + kindname;
			MyMessageBox(msg,MB_OK | MB_ICONSTOP);
			return;
		}
		(*modelRefBuildFunctions)[kindname] = createFn;
	}
}


CBuilderFactory::CBuilderFactory(CString kindnames, CBuilderAtomRefCreateFunction createFn) {
	if(atomRefBuildFunctions == NULL) {
		atomRefBuildFunctions = new CBuilderAtomRefCreateFunctionTable;
		atomRefBuildFunctions->InitHashTable(29);
	}
	while( !kindnames.IsEmpty() )
	{
		CString trash = kindnames.SpanIncluding(",;");
		kindnames = kindnames.Mid(trash.GetLength());
		if( kindnames.IsEmpty() )
			break;
		CString kindname = kindnames.SpanExcluding(",;");
		kindnames = kindnames.Mid(kindname.GetLength());
		ASSERT(!kindname.IsEmpty());

		CBuilderRefCreateFunction fn;
		CBuilderAtomRefCreateFunction fna;
		if(refBuildFunctions && refBuildFunctions->Lookup(kindname,fn) ||
		   atomRefBuildFunctions && atomRefBuildFunctions->Lookup(kindname,fna)) {
			CString msg = "Create function already exists for object type " + kindname;
			MyMessageBox(msg,MB_OK | MB_ICONSTOP);
			return;
		}
		(*atomRefBuildFunctions)[kindname] = createFn;
	}
}


// The priority of subclassing specification for references
// CBuilderReference is a new addition to the library,
// CBuilderAtomReference and CBuilderModelReference are kept for compatibility
//
// The framework uses the following algorithm to define which class is instantiated
//
// 1. If there is an explicit or '*' DECLARE_CUSTOMREF for the given kind, a custom CBuilderReference is created
// 2. If the reference points to a model or atom
//		2.a if that kind has implicit or '*' DECLARE_CUSTOMMODELREF or DECLARE_CUSTOMATOMREF,
//			a custom CBuilderModelRef or CBuilderAtomRef is created
//      2.b otherwise a standard CBuilderModelReference or CBuilderAtomReference is created
// 3. Otherwise a standard CBuilderReference is created


CBuilderReference *CBuilderFactory::Create(IMgaReference* iRef, CBuilderModel *aparent) {
		CBstr bstr;
		objtype_enum ot;
		{
			CComPtr<IMgaMetaFCO> meta;
			COMVERIFY(iRef->get_Meta(&meta));
			COMVERIFY(meta->get_Name(bstr));

			CComPtr<IMgaFCO> fco;
			COMVERIFY(iRef->get_Referred(&fco));
			if(fco) COMVERIFY(fco->get_ObjType(&ot));
			else ot = OBJTYPE_NULL;
		}
		CString kindname(bstr);

		if( refkindnames.Find(kindname) == NULL )
		{
			CString msg;
			msg.Format("Ref kindname \"%s\" was not found in paradigm.", (const char*) kindname);
			MyMessageBox(msg, MB_OK | MB_ICONSTOP);
		}


		CBuilderRefCreateFunction fn;
		if(refBuildFunctions && (refBuildFunctions->Lookup(kindname,fn) || refBuildFunctions->Lookup("*",fn)))
			return fn(iRef,aparent);

		if(ot == OBJTYPE_MODEL) {
			CBuilderModelRefCreateFunction fn;
			if(modelRefBuildFunctions && (modelRefBuildFunctions->Lookup(kindname,fn) || modelRefBuildFunctions->Lookup("*",fn))) {
				return fn(iRef,aparent);
			}
			return new CBuilderModelReference(iRef, aparent);
		}
		else if (ot == OBJTYPE_ATOM) {
			CBuilderAtomRefCreateFunction fn;
			if(atomRefBuildFunctions && (atomRefBuildFunctions->Lookup(kindname,fn) || atomRefBuildFunctions->Lookup("*",fn))) {
				return fn(iRef,aparent);
			}
			return new CBuilderAtomReference(iRef, aparent);
		}

		return  new CBuilderReference(iRef, aparent);
}


// CONNECTIONS

CBuilderFactory::CBuilderFactory(CString kindnames, CBuilderConnectionCreateFunction createFn)
{
	if(connectionBuildFunctions == NULL) {
		connectionBuildFunctions = new CBuilderConnectionCreateFunctionTable;
		connectionBuildFunctions->InitHashTable(29);
	}
	while( !kindnames.IsEmpty() )
	{
		CString trash = kindnames.SpanIncluding(",;");
		kindnames = kindnames.Mid(trash.GetLength());
		if( kindnames.IsEmpty() )
			break;
		CString kindname = kindnames.SpanExcluding(",;");
		kindnames = kindnames.Mid(kindname.GetLength());
		ASSERT(!kindname.IsEmpty());

		CBuilderConnectionCreateFunction fn;
		if(connectionBuildFunctions->Lookup(kindname,fn)) {
			CString msg = "Create function already exists for object type " + kindname;
			MyMessageBox(msg,MB_OK | MB_ICONSTOP);
			return;
		}
		(*connectionBuildFunctions)[kindname] = createFn;
	}
}

CBuilderConnection *CBuilderFactory::Create(IMgaSimpleConnection* iConnection, CBuilderModel *aparent)
{
	if( connectionBuildFunctions )
	{
		CBstr bstr;
		{
			CComPtr<IMgaMetaFCO> meta;
			COMVERIFY(iConnection->get_Meta(&meta));
			COMVERIFY(meta->get_Name(bstr));
		}
		CString kindname(bstr);

		if( connectionkindnames.Find(kindname) == NULL )
		{
			CString msg;
			msg.Format("Connection kindname \"%s\" was not found in paradigm.", (const char*) kindname);
			MyMessageBox(msg, MB_OK | MB_ICONSTOP);
		}

		CBuilderConnectionCreateFunction fn;

		if(connectionBuildFunctions->Lookup(kindname,fn))
			return fn(iConnection,aparent);

		if(connectionBuildFunctions->Lookup("*",fn))
			return fn(iConnection,aparent);
	}

	CBuilderConnection *ret = new CBuilderConnection(iConnection, aparent);
	ASSERT(ret);
	return ret;
}





CBuilderFactory::CBuilderFactory(CString kindnames, CBuilderSetCreateFunction createFn)
{
	if(setBuildFunctions == NULL) {
		setBuildFunctions = new CBuilderSetCreateFunctionTable;
		setBuildFunctions->InitHashTable(29);
	}
	while( !kindnames.IsEmpty() )
	{
		CString trash = kindnames.SpanIncluding(",;");
		kindnames = kindnames.Mid(trash.GetLength());
		if( kindnames.IsEmpty() )
			break;
		CString kindname = kindnames.SpanExcluding(",;");
		kindnames = kindnames.Mid(kindname.GetLength());
		ASSERT(!kindname.IsEmpty());

		CBuilderSetCreateFunction fn;
		if(setBuildFunctions->Lookup(kindname,fn)) {
			CString msg = "Create function already exists for object type " + kindname;
			MyMessageBox(msg,MB_OK | MB_ICONSTOP);
			return;
		}
		(*setBuildFunctions)[kindname] = createFn;
	}
}

CBuilderSet *CBuilderFactory::Create(IMgaSet* iSet, CBuilderModel *aparent)
{
	if( setBuildFunctions )
	{
		CBstr bstr;
		{
			CComPtr<IMgaMetaFCO> meta;
			COMVERIFY(iSet->get_Meta(&meta));
			COMVERIFY(meta->get_Name(bstr));
		}
		CString kindname(bstr);

		if( setkindnames.Find(kindname) == NULL )
		{
			CString msg;
			msg.Format("Set kindname \"%s\" was not found in paradigm.", (const char*) kindname);
			MyMessageBox(msg, MB_OK | MB_ICONSTOP);
		}

		CBuilderSetCreateFunction fn;

		if(setBuildFunctions->Lookup(kindname,fn))
			return fn(iSet,aparent);

		if(setBuildFunctions->Lookup("*",fn))
			return fn(iSet,aparent);
	}

	CBuilderSet *ret = new CBuilderSet(iSet, aparent);
	ASSERT(ret);
	return ret;
}



void CBuilderFactory::CollectFolderKindNames(IMgaMetaFolder* mf) {

	CComPtr<IMgaMetaFCOs> psa;
	COMVERIFY( mf->get_DefinedFCOs(&psa) );
	CollectFCOKindNames(psa);
	CComPtr<IMgaMetaFolders> folds;
	COMVERIFY( mf->get_DefinedFolders(&folds) );
	MGACOLL_ITERATE(IMgaMetaFolder, folds) {
		CollectFolderKindNames(MGACOLL_ITER);
	} MGACOLL_ITERATE_END;
}

void CBuilderFactory::CollectFCOKindNames(IMgaMetaFCOs * psa) {
	MGACOLL_ITERATE(IMgaMetaFCO, psa) {
			CComBSTR name;
			objtype_enum o;
			COMVERIFY(MGACOLL_ITER->get_Name(&name));
			CString n = name;
			COMVERIFY(MGACOLL_ITER->get_ObjType(&o));
			switch(o) {
			case OBJTYPE_MODEL: 	modelkindnames.AddTail(n);
				{
				CComPtr<IMgaMetaFCOs> psa2;
				CComQIPtr<IMgaMetaModel> mm = MGACOLL_ITER;
				COMVERIFY(mm->get_DefinedFCOs(&psa2) );
				CollectFCOKindNames(psa2);
				}
				break;
			case OBJTYPE_ATOM:		atomkindnames.AddTail(n);  break;
			case OBJTYPE_REFERENCE:	refkindnames.AddTail(n);  break;
			case OBJTYPE_CONNECTION:	connectionkindnames.AddTail(n);  break;
			case OBJTYPE_SET:		setkindnames.AddTail(n);  break;
			}
	} MGACOLL_ITERATE_END;
}

void CBuilderFactory::CheckKindNames(IMgaFolder* rf)
{
	ASSERT(rf);

	modelkindnames.RemoveAll();
	atomkindnames.RemoveAll();
	refkindnames.RemoveAll();
	CComPtr<IMgaMetaFolder> mf;

	COMVERIFY( rf->get_MetaFolder(&mf) );
	CollectFolderKindNames(mf);

	if( modelBuildFunctions )
	{

		POSITION pos = modelBuildFunctions->GetStartPosition();
		while(pos)
		{
			CString kindname;
			CBuilderModelCreateFunction fn;
			modelBuildFunctions->GetNextAssoc(pos, kindname, fn);
			if( modelkindnames.Find(kindname) == NULL && kindname != "*" )
			{
				CString msg;
				msg.Format("Model kindname \"%s\" was not found in paradigm.", (const char*) kindname);
				MyMessageBox(msg, MB_OK | MB_ICONSTOP);
			}
		}
	}

	if( atomBuildFunctions )
	{
		POSITION pos = atomBuildFunctions->GetStartPosition();
		while(pos)
		{
			CString kindname;
			CBuilderAtomCreateFunction fn;
			atomBuildFunctions->GetNextAssoc(pos, kindname, fn);
			if( atomkindnames.Find(kindname) == NULL && kindname != "*" )
			{
				CString msg;
				msg.Format("Atom kindname \"%s\" was not found in paradigm.", (const char*) kindname);
				MyMessageBox(msg, MB_OK | MB_ICONSTOP);
			}
		}
	}

	if( modelRefBuildFunctions || atomRefBuildFunctions )
	{
		if( modelRefBuildFunctions )
		{
			POSITION pos = modelRefBuildFunctions->GetStartPosition();
			while(pos)
			{
				CString kindname;
				CBuilderModelRefCreateFunction fn;
				modelRefBuildFunctions->GetNextAssoc(pos, kindname, fn);
				if( refkindnames.Find(kindname) == NULL && kindname != "*" )
				{
					CString msg;
					msg.Format("ModelRef kindname \"%s\" was not found in paradigm.", (const char*) kindname);
					MyMessageBox(msg, MB_OK | MB_ICONSTOP);
				}
			}
		}

		if( atomRefBuildFunctions )
		{
			POSITION pos = atomRefBuildFunctions->GetStartPosition();
			while(pos)
			{
				CString kindname;
				CBuilderAtomRefCreateFunction fn;
				atomRefBuildFunctions->GetNextAssoc(pos, kindname, fn);
				if( refkindnames.Find(kindname) == NULL && kindname != "*" )
				{
					CString msg;
					msg.Format("AtomRef kindname \"%s\" was not found in paradigm.", (const char*) kindname);
					MyMessageBox(msg, MB_OK | MB_ICONSTOP);
				}
			}
		}

	}
}
