/////////////////////////////////////////////////
// GME v0.5 Alpha Release                      //
// Copyright (c) 1998, Vanderbilt University   //
// All Rights Reserved						   //
/////////////////////////////////////////////////

#ifndef BUILDER_OBJECT_NETWORK
#error   This file should only be included in the BON configurations
#endif

#define BUILDER_CAST(CLASS,PTR) (DYNAMIC_DOWNCAST(CLASS,PTR))

#ifndef GME_BUILDER_H
#define GME_BUILDER_H

#include "GMECOM.h"
#ifndef __COMHELP_H
#include "ComHelp.h"
#endif

class CBuilder;
class CBuilderFolder;
class CBuilderObject;
class CBuilderModel;
class CBuilderAtom;
class CBuilderReference;
class CBuilderModelReference;
class CBuilderAtomReference;
class CBuilderReferencePort;
class CBuilderConnection;
class CBuilderSet;

typedef CTypedPtrList<CPtrList, CBuilderFolder*> 								CBuilderFolderList;
typedef CTypedPtrList<CPtrList, CBuilderObject*>								CBuilderObjectList;
typedef CTypedPtrList<CPtrList, CBuilderModel*>									CBuilderModelList;
typedef CTypedPtrList<CPtrList, CBuilderAtom*>									CBuilderAtomList;
typedef CTypedPtrList<CPtrList, CBuilderReference*>								CBuilderReferenceList;
typedef CTypedPtrList<CPtrList, CBuilderAtomReference*>							CBuilderAtomReferenceList;
typedef CTypedPtrList<CPtrList, CBuilderModelReference*>						CBuilderModelReferenceList;
typedef CTypedPtrList<CPtrList, CBuilderReferencePort*>							CBuilderReferencePortList;
typedef CTypedPtrList<CPtrList, CBuilderConnection*> 							CBuilderConnectionList;
typedef CTypedPtrList<CPtrList, CBuilderSet*> 									CBuilderSetList;

typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderModelList *>				CBuilderModelListTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderAtomList *>				CBuilderAtomListTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderReferenceList *>			CBuilderReferenceListTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderAtomReferenceList *>		CBuilderAtomReferenceListTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderModelReferenceList *>	CBuilderModelReferenceListTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderConnectionList *>		CBuilderConnectionListTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderSetList *>		CBuilderSetListTable;

typedef CBuilderModel* (*CBuilderModelCreateFunction)(IMgaModel *iModel, CBuilderModel *parent);
typedef CBuilderReference* (*CBuilderRefCreateFunction)(IMgaReference *iRef, CBuilderModel *parent);
typedef CBuilderModelReference* (*CBuilderModelRefCreateFunction)(IMgaReference *iModelRef, CBuilderModel *parent);
typedef CBuilderAtom* (*CBuilderAtomCreateFunction)(IMgaAtom *iAtom, CBuilderModel *parent);
typedef CBuilderAtomReference* (*CBuilderAtomRefCreateFunction)(IMgaReference *iAtomRef, CBuilderModel *parent);
typedef CBuilderConnection* (*CBuilderConnectionCreateFunction)(IMgaSimpleConnection *iConnection, CBuilderModel *parent);
typedef CBuilderSet* (*CBuilderSetCreateFunction)(IMgaSet *iSet, CBuilderModel *parent);

typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderModelCreateFunction> CBuilderModelCreateFunctionTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderAtomCreateFunction> CBuilderAtomCreateFunctionTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderRefCreateFunction> CBuilderRefCreateFunctionTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderModelRefCreateFunction> CBuilderModelRefCreateFunctionTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderAtomRefCreateFunction> CBuilderAtomRefCreateFunctionTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderConnectionCreateFunction> CBuilderConnectionCreateFunctionTable;
typedef CTypedPtrMap<CMapStringToPtr, CString, CBuilderSetCreateFunction> CBuilderSetCreateFunctionTable;

typedef CMap<IUnknown*, IUnknown*, CBuilderObject*, CBuilderObject*> CBuilderObjectLookupTable;
typedef CMap<IUnknown*, IUnknown*, CBuilderConnection*, CBuilderConnection*> CBuilderConnectionLookupTable;
typedef CMap<IUnknown*, IUnknown*, CBuilderReferencePort*, CBuilderReferencePort*> CBuilderReferencePortLookupTable;

typedef CMap<CString, LPCSTR, CString, LPCSTR> CStringMap;

typedef CBuilderObject CBuilderAtomicObject;
typedef CBuilderObjectList CBuilderAtomicObjectList;

enum editormodes { DEFAULT } ;
typedef enum editormodes EditorModes;

class CBuilder : public CObject {
	DECLARE_DYNAMIC(CBuilder)
	friend class CBuilderFolder;
public:
	CBuilder(IMgaProject* iGme, CStringMap *pmp = NULL);
	virtual ~CBuilder();
protected:
	CComPtr<IMgaFolder> ciRootFolder;
	CComPtr<IMgaProject> ciGme;
	CComPtr<IMgaTerritory> ciTerr;
	CBuilderFolderList folders;
	CBuilderFolder *rootfolder;

	CBuilderObjectLookupTable objectmap;
	CBuilderConnectionLookupTable connectionmap;

	CStringMap *parametermap;

public:
	static CBuilder* theInstance;

	IMgaProject* GetProject() const	{ return ciGme; }

	void SetObjectRef(IMgaFCO* i, CBuilderObject* o);
	void SetConnectionRef(IMgaSimpleConnection* i, CBuilderConnection* o);

	CBuilderObject* FindObject(IMgaFCO* i);
	CBuilderConnection* FindConnection(IMgaSimpleConnection* i);

	void ForgetObjectRef(IMgaFCO* i);
	void ForgetConnectionRef(IMgaSimpleConnection* i);

	CString GetParameter(CString name);
	bool PutParameter(CString name, CString value);

	EditorModes GetEditorMode() const;
	void SetEditorMode(EditorModes mode);

	bool BeginTransaction(transactiontype_enum mode = TRANSACTION_GENERAL);
	bool CommitTransaction();
	void AbortTransaction();

public:
	const CBuilderFolderList *GetFolders() const			{ return &folders; }
	CBuilderFolder *GetFolder(CString name) const;
	CBuilderFolder *GetRootFolder() const					{ return rootfolder; }
	CString GetProjectName() const;
};

class CBuilderFolder : public CObject {
	DECLARE_DYNAMIC(CBuilderFolder)
	friend class CBuilder;
	friend class CBuilderModel;
public:
	CBuilderFolder(IMgaFolder *iFolder, CBuilderFolder *parent);
	virtual ~CBuilderFolder();
protected:
	CComPtr<IMgaFolder> ciFolder;
	CBuilderModelList rootModels;
	CBuilderObjectList rootObjects;
	CBuilderFolderList subfolders;
	CBuilderFolder  *parentfolder;
	CString name;
	CString kindName;
	CString kindTitle;

	void Resolve();
	void RemoveRootModel(CBuilderModel *model);

public:
	IMgaFolder* GetIFolder() const						{ return ciFolder; }
	CComPtr<IMgaMetaFolder> GetMeta() const;
public:
	const CString& GetName() const { return name; }
	const CString& GetKindName() const							{ return kindName; }   	// returns folder kind name
	const CString& GetKindTitle() const							{ return kindTitle; }   // returns folder kind title (displayed name)
	const CBuilderModelList *GetRootModels() const				{ return &rootModels; }
	const CBuilderObjectList *GetRootObjects() const				{ return &rootObjects; }
	const CBuilderFolderList *GetSubFolders() const				{ return &subfolders; }
	CBuilderModel *GetRootModel(CString name) const;
	CBuilderModel *CreateNewModel(CString kindName, CBuilderModel* baseType = NULL, bool instance = true);
	CBuilderFolder *CreateNewFolder(CString kindName);
	CBuilderAtom  *CreateNewAtom(CString kindName, CBuilderAtom* baseType = NULL, bool instance = true);
	CBuilderModelReference *CreateNewModelReference(CString kindName, CBuilderObject* refTo);
	CBuilderAtomReference *CreateNewAtomReference(CString kindName, CBuilderObject* refTo);
	CBuilderReference *CreateNewReference(CString kindName, CBuilderObject* refTo, CBuilderReference* baseType = NULL, bool instance = true);
	CBuilderConnection *CreateNewConnection(CString kindName, CBuilderObject *src, CBuilderObject *dst);
	CBuilderSet *CreateNewSet(CString kindName, CBuilderSet* baseType = NULL, bool instance = true);
	bool GetRegistryValue(CString &path,CString &val) const;
	bool SetRegistryValue(CString &path,CString &val) const;

  bool SetName(CString newname);
};

class CBuilderObject : public CObject {
	DECLARE_DYNAMIC(CBuilderObject)
	friend class CBuilderModel;
	friend class CBuilderAtom;
	friend class CBuilderReference;
	friend class CBuilderAtomReference;
	friend class CBuilderReferencePort;
	friend class CBuilderModelReference;
	friend class CBuilderConnection;
	friend class CBuilderSet;
public:
	typedef enum { OBJNULL = OBJTYPE_NULL,
		   MODEL =	 OBJTYPE_MODEL,
		   ATOM =	 OBJTYPE_ATOM,
		   REFERENCE	= OBJTYPE_REFERENCE,
		   CONNECTION	= OBJTYPE_CONNECTION,
		   SET			= OBJTYPE_SET} objtype;

public:
	virtual ~CBuilderObject();
	virtual void Destroy();
protected:
	virtual void Initialize() { }
	CBuilderObject(IMgaFCO *iObject, CBuilderModel *parent, bool globalregister = true);

	CComPtr<IMgaFCO> ciObject;
	CBuilderModel *parent;
	CBuilderConnectionListTable inConnections;
	CBuilderConnectionListTable outConnections;
	CBuilderConnectionListTable inConnections2;
	CBuilderConnectionListTable outConnections2;
	CString name;
	CString kindName;
	CString kindTitle;
	CString partName;

	void DisplayMessage(CString &msg,bool error) const;
	void CreateOutConnections();
	void AddInConnection(CString &name,CBuilderConnection *conn);
	void AddOutConnection(CString &name,CBuilderConnection *conn);
	void AddPortInConnection(CString &name,CBuilderConnection *conn);
	void AddPortOutConnection(CString &name,CBuilderConnection *conn);
	CBuilderConnectionList *FindInConnections(const CString &name) const;
	CBuilderConnectionList *FindOutConnections(const CString &name) const;
	void RemoveInConnection(CBuilderConnection *conn);
	void RemoveOutConnection(CBuilderConnection *conn);

	bool GetDirectConnections(const CString &name, CBuilderObjectList &list, bool in);

	virtual void Resolve() = 0; //										{ ASSERT(false); }
public:
	IMgaFCO* GetIObject() const								{ return ciObject; }
	long GetObjId() const;
	objtype GetObjType() const;

	const CString& GetName() const								{ return name; }
	const CString& GetKindName() const							{ return kindName; }   	// returns model kind name, e.g. "Compound"
	const CString& GetKindTitle() const							{ return kindTitle; }   // returns model kind title, e.g. "Compound"
	const CString& GetPartName() const							{ return partName; }   	// returns model part name, e.g. "CompoundParts"
	void GetNamePath(CString &namePath) const;					// makes "__" separated list of names of all ascendants
	void GetExtendedName(CString &extName,CString separator,bool startWithRoot) const; // makes "separator" separated list of names of all ascendants in specified order
	const CBuilderModel *GetParent() const						{ return parent; }
	bool GetLocation(CString &aspectName,CRect &loc);
	bool SetLocation(CString aspectName,CPoint loc);
	short GetNamePosition();
	void SetNamePosition(short pos);
	CBuilderFolder* GetFolder() const;
	void DisplayError(CString &msg)	 const						{ DisplayMessage(msg,true); }
	void DisplayError(char *msg) const							{ DisplayMessage(CString(msg),true); }
	void DisplayWarning(CString &msg) const						{ DisplayMessage(msg,false); }
	void DisplayWarning(char *msg) const						{ DisplayMessage(CString(msg),false); }

	virtual void TraverseChildren(void *pointer = 0)			{ }

	bool GetRegistryValue(CString &path,CString &val) const;
	bool SetRegistryValue(CString &path,CString &val) const;

	bool GetAttribute(CString &name,CString &val) const;
	bool GetAttribute(char *name,CString &val) const			{ return GetAttribute(CString(name),val); }
	bool GetAttribute(CString &name,int &val) const;
	bool GetAttribute(char *name,int &val) const				{ return GetAttribute(CString(name),val); }
	bool GetAttribute(CString &name,bool &val) const;
	bool GetAttribute(char *name,bool &val) const				{ return GetAttribute(CString(name),val); }
	bool GetAttribute(CString &name,double &val) const;
	bool GetAttribute(char *name,double &val) const				{ return GetAttribute(CString(name),val); }
	bool GetAttribute(CString &name,CBuilderObject *&val) const;
	bool GetAttribute(char *name,CBuilderObject *&val) const	{ return GetAttribute(CString(name),val); }
	int  GetAttributeStatus(CString attrName);					// See Mga.idl for ATTSTATUS enum values

	bool SetAttribute(CString &name, CString &val);
	bool SetAttribute(CString &name, int val);
	bool SetAttribute(CString &name, bool val);
	bool SetAttribute(CString &name, double val);
	bool SetAttribute(CString &name, CBuilderObject *val);

	void GetAttributeNames(CStringList &list, attval_enum type, attval_enum sectype = ATTVAL_NULL) const;
	void GetStrAttributeNames(CStringList &list) const;
	void GetIntAttributeNames(CStringList &list) const;
	void GetBoolAttributeNames(CStringList &list) const;
	void GetFloatAttributeNames(CStringList &list) const;
	void GetRefAttributeNames(CStringList &list) const;


	bool SetName(CString newname);

	bool IsMarked();
	void Mark(bool marked);

	const CBuilderConnectionList *GetInConnections(const CString &name, bool bPorts = true ) const;
	const CBuilderConnectionList *GetInConnections(char *name, bool bPorts = true ) const		{ return GetInConnections(CString(name), bPorts ); }
	const CBuilderConnectionList *GetOutConnections(const CString &name, bool bPorts = true ) const;
	const CBuilderConnectionList *GetOutConnections(char *name, bool bPorts = true ) const		{ return GetOutConnections(CString(name), bPorts ); }
	void GetReferencedBy(CBuilderObjectList &list) const;			// references which point to this object
	void GetMemberOfSets(CBuilderObjectList &list) const;			// sets which contain this object

	bool GetInConnectedObjects(const CString &name, CBuilderObjectList &list, bool bPorts = true );
	bool GetInConnectedObjects(const char *name, CBuilderObjectList &list, bool bPorts = true ) { return GetInConnectedObjects(CString(name), list, bPorts ); }
	bool GetOutConnectedObjects(const CString &name, CBuilderObjectList &list, bool bPorts = true );
	bool GetOutConnectedObjects(const char *name, CBuilderObjectList &list, bool bPorts = true ) { return GetOutConnectedObjects(CString(name), list, bPorts ); }

	bool GetDirectInConnections(const CString &name, CBuilderObjectList &list) { return GetDirectConnections(name, list, true); }
	bool GetDirectInConnections(const char *name, CBuilderObjectList &list) { return GetDirectConnections(CString(name), list, true); }
	bool GetDirectOutConnections(const CString &name, CBuilderObjectList &list) { return GetDirectConnections(name, list, false); }
	bool GetDirectOutConnections(const char *name, CBuilderObjectList &list) { return  GetDirectConnections(CString(name), list, false); }

	const CBuilderConnectionListTable &GetInConnections() const				{ return inConnections; }
	const CBuilderConnectionListTable &GetOutConnections() const			{ return outConnections; }

	CComPtr<IMgaMetaFCO> GetMeta() const;

//	Additions:
	bool IsInstance();
	CBuilderObject *GetType();     //  or NULL, if it is an instance
	CBuilderObject *GetDerivedFrom();     //  or NULL, if it does not have immediate parent

	void GetDerivedObjects(CBuilderObjectList &, int mode = 0);     //  mode is 0 for both, 1 for subtypes only, 2 for instances
};

class CBuilderModel : public CBuilderObject {
	DECLARE_DYNAMIC(CBuilderModel)
	friend class CBuilder;
	friend class CBuilderFolder;
	friend class CBuilderObject;
	friend class CBuilderReference;
	friend class CBuilderModelReference;
	friend class CBuilderFactory;
	friend class CBuilderAtom;
	friend class CBuilderAtomReference;
	friend class CBuilderConnection;
	friend class CBuilderSet;
public:
	virtual ~CBuilderModel();
	virtual void Destroy();
protected:
	CBuilderModel(IMgaModel *iModel, CBuilderModel *parent);

	CBuilderObjectList children;
	CBuilderConnectionList connchildren;
	CBuilderModelList models;
	CBuilderModelListTable modelLists;
	CBuilderAtomListTable atomLists;
	CBuilderReferenceListTable referenceLists;
	CBuilderModelReferenceListTable modelReferenceLists;
	CBuilderAtomReferenceListTable atomReferenceLists;
	CBuilderConnectionListTable connectionLists;
	CBuilderSetList sets;
	CBuilderSetListTable setLists;

	void CreateModels();
	void CreateAtoms();
	void CreateReferences();
	void CreateConnections();
	void CreateSets();
	void MapPortsToAtoms();
	void Resolve();
	CBuilderConnection *AddConnection(IMgaSimpleConnection *iConnection);
	CBuilderSet *AddSet(IMgaSet *iSet);
	CBuilderConnectionList *FindConnections(CString name) const;
	CBuilderSetList *FindSets(CString name) const;
	void RemoveModel(CBuilderModel *model);
	void RemoveAtom(CBuilderAtom *atom);

	void RemoveReference(CBuilderReference *atomref);
	void RemoveModelReference(CBuilderModelReference *modelref);
	void RemoveAtomReference(CBuilderAtomReference *atomref);

	void RemoveConnection(CBuilderConnection *conn);
	void RemoveSet(CBuilderSet *cond);

	void RemoveMemberFromSets(CBuilderObject *part);

public:
	IMgaModel* GetIModel() const { return CComQIPtr<IMgaModel>(ciObject); }

	const CBuilderObjectList *GetChildren() const				{ return &children; }	// return list of all models and parts
	const CBuilderModelList *GetModels() const   				{ return &models; }		// return list of (non-atomic) models only
	const CBuilderModelList *GetModels(CString partName) const;							// you supply partname, returns list of one kind of models, e.g. "CompoundParts"
	const CBuilderAtomList *GetAtoms(CString partName) const;							// you supply partname, returns list of one kind of models, e.g "InputSignals"
	const CBuilderModelReferenceList *GetModelReferences(CString refPartName) const; 	// you supply partname, returns list of one kind of references, e.g. "CompoundRefs"
	const CBuilderAtomReferenceList *GetAtomReferences(CString refPartName) const;	 	// you supply partname, returns list of one kind of references, e.g. "InputSignalReferences"
	const CBuilderReferenceList *GetReferences(CString refPartName) const;	 	    // you supply partname, returns list matching refs no matter what the target is (including null)
	const CBuilderConnectionList *GetConnections(CString name) const	{ return FindConnections(name); } // returns list of one kind of connections, e.g. "Dataflow"
	const CBuilderSetList *GetSets(CString name) const	{ return FindSets(name); } // returns list of one kind of sets, e.g. "StateDep"
	const CBuilderSetList *GetSets() const				{ return &sets; } // returns list of all sets

	virtual void TraverseModels(void *pointer = 0);				 // traverse user defined models
	virtual void TraverseChildren(void *pointer = 0);			 // traverse all models (atoms, references etc.)

	void Open();
	bool IsOpened();
	bool Close(bool withchildren = false);

	void GetSelection(CBuilderObjectList &list);
	void SelectionRemoveAll() const;
	void SelectionRemove(CBuilderObjectList& list) const;
	void SelectionRemove(CBuilderObject* object) const;
	void SelectionAdd(CBuilderObjectList& list) const;
	void SelectionAdd(CBuilderObject* object) const;
	void SelectionSet(CBuilderObjectList& list) const { SelectionRemoveAll(); SelectionAdd(list); }
	void SelectionSet(CBuilderObject* object) const { SelectionRemoveAll(); SelectionAdd(object); }

	void SetCurrentAspect(CString& aspect);
	CString GetCurrentAspect();
	void GetAspectNames(CStringList &list);

	CBuilderObject *CloneHere( CBuilderObject* orig);

	CBuilderModel *CreateNewModel(CString partName, CBuilderModel* baseType = NULL, bool instance = true);
	CBuilderAtom  *CreateNewAtom(CString patrName, CBuilderAtom* baseType = NULL, bool instance = true);
	CBuilderModelReference *CreateNewModelReference(CString refPartName, CBuilderObject* refTo);
	CBuilderAtomReference *CreateNewAtomReference(CString refPartName, CBuilderObject* refTo);
	CBuilderReference *CreateNewReference(CString refPartName, CBuilderObject* refTo, CBuilderReference* baseType = NULL, bool instance = true);
	CBuilderConnection *CreateNewConnection(CString connName, CBuilderObject *src, CBuilderObject *dst);
	CBuilderSet *CreateNewSet(CString condName, CBuilderSet* baseType = NULL, bool instance = true);
};

class CBuilderAtom : public CBuilderObject {
	DECLARE_DYNAMIC(CBuilderAtom)
	friend class CBuilderObject;
	friend class CBuilderModel;
	friend class CBuilderFactory;
public:
	virtual ~CBuilderAtom();
protected:
	CBuilderAtom(IMgaAtom *iAtom, CBuilderModel *parent);

	void Resolve();

public:
	IMgaAtom* GetIAtom() const { return CComQIPtr<IMgaAtom>(ciObject); }
};


class CBuilderReferencePort : public CBuilderObject {
	DECLARE_DYNAMIC(CBuilderReferencePort)
	friend class CBuilderModelReference;
public:
	virtual ~CBuilderReferencePort() {}
protected:
	CBuilderReferencePort(IMgaFCO *iPort, CBuilderModelReference *o);

	CBuilderObject *portobj;
	CBuilderModelReference *owner;
	void Resolve();

public:
	const CBuilderModelReference * GetOwner() const	{ return owner; }
	const CBuilderAtom * GetAtom() const				{  return BUILDER_CAST(CBuilderAtom, portobj); }
	const CBuilderObject * GetPortObject() const				{ return portobj; }
};

class CBuilderReference : public CBuilderObject {
	DECLARE_DYNAMIC(CBuilderReference)
	friend class CBuilderObject;
	friend class CBuilderModel;
	friend class CBuilderConnection;
	friend class CBuilderFactory;
	friend class CBuilderReferencePort;
public:
	CBuilderReference(IMgaReference *iRef, CBuilderModel *parent);
	~CBuilderReference();
protected:
	CBuilderObject *ref;

	void Resolve();

public:
	IMgaReference* GetIRef() const { return CComQIPtr<IMgaReference>(ciObject); }
	const CBuilderObject *GetReferred() const	{ return ref; }
	bool PutReferred(CBuilderObject *nref);
	const CBuilderObject::objtype GetReferredType() const;
};


class CBuilderModelReference : public CBuilderReference {
	DECLARE_DYNAMIC(CBuilderModelReference)
	friend class CBuilderObject;
	friend class CBuilderModel;
	friend class CBuilderConnection;
	friend class CBuilderFactory;
	friend class CBuilderReferencePort;
public:
	virtual ~CBuilderModelReference();
	virtual void Destroy();
protected:
	CBuilderModelReference(IMgaReference *iModelRef, CBuilderModel *parent);
public:

protected:
	CBuilderReferencePortLookupTable objectmap;
	CBuilderReferencePortList refPorts;

	void CreateReferencePorts();
	void Resolve();
	void CreateConnections();
	IMgaObject *GetPort(CString aspectName,CBuilderReferencePort *port) const;
	CBuilderReferencePort *FindPortRef(IMgaFCO *search) const;
	void SetPortRef(IMgaFCO *search, CBuilderReferencePort *tgt);
	void ForgetPortRef(IMgaFCO* i);

public:
	IMgaReference* GetIModelRef() const { return GetIRef(); }

	const CBuilderReferencePortList &GetRefereePorts() const	{ return refPorts; }
};

class CBuilderAtomReference : public CBuilderReference {
	DECLARE_DYNAMIC(CBuilderAtomReference)
	friend class CBuilderObject;
	friend class CBuilderModel;
	friend class CBuilderFactory;
public:
	virtual ~CBuilderAtomReference();
protected:
	CBuilderAtomReference(IMgaReference *iAtomRef, CBuilderModel *parent);

	void Resolve();
public:
	IMgaReference* GetIAtomRef() const { return GetIRef(); }

};



class CBuilderConnection : public CBuilderObject {
	DECLARE_DYNAMIC(CBuilderConnection)
	friend class CBuilderObject;
public:
	CBuilderConnection(IMgaSimpleConnection *iConn,CBuilderModel *o);
	virtual ~CBuilderConnection();
	virtual void Destroy();

protected:
//	CString kindName;
	CBuilderModel *&owner;
	CBuilderObject *src;
	CBuilderObject *dst;
#define ciConnection ciObject
//	CComPtr<IMgaSimpleConnection> ciConnection;

public:
	CBuilderModel *GetOwner()	const			{ return owner; }  	// the model where the connection is visible
	CBuilderObject *GetSource()	const			{ return src; }	   	// where it starts
	CBuilderObject *GetDestination() const		{ return dst; }	   	// where it ends
	const CString &GetKindName() const			{ return kindName; }
	IMgaSimpleConnection *GetIConnection() const		{
		return CComQIPtr<IMgaSimpleConnection>(ciConnection);
	}

	void Resolve();
};


class CBuilderSet : public CBuilderObject {
	DECLARE_DYNAMIC(CBuilderSet)
	friend class CBuilderModel;
public:
	CBuilderSet(IMgaSet *iCond,CBuilderModel *own);
	virtual ~CBuilderSet();
//	virtual void Destroy();

protected:
#define iSet ciObject
	CBuilderObjectList members;

	void InsertMember(CBuilderObject *member)				{ members.AddTail(member); }

public:
//	long GetObjId() const;
	IMgaSet* GetISet() const { return CComQIPtr<IMgaSet>(ciObject); }
	void Resolve();
	const CBuilderModel *GetOwner() const 				{ return GetParent(); }
	const CBuilderObjectList *GetMembers() const			{ return &members; }

	bool AddMember(CBuilderObject *part);
	bool RemoveMember(CBuilderObject *part);
};

// -------------------------- BuilderFactory

class CBuilderFactory
{
public:
	CBuilderFactory(CString modelkinds, CBuilderModelCreateFunction createFn);
	CBuilderFactory(CString atomkinds, CBuilderAtomCreateFunction createFn);

	CBuilderFactory(CString refkinds, CBuilderRefCreateFunction createFn);
	CBuilderFactory(CString modelrefkinds, CBuilderModelRefCreateFunction createFn);
	CBuilderFactory(CString atomrefkinds, CBuilderAtomRefCreateFunction createFn);

	CBuilderFactory(CString connectionkinds, CBuilderConnectionCreateFunction createFn);
	CBuilderFactory(CString setkinds, CBuilderSetCreateFunction createFn);
	~CBuilderFactory();

	static void CheckKindNames(IMgaFolder* iparadigm);
	static void CollectFolderKindNames(IMgaMetaFolder*);
	static void CollectFCOKindNames(IMgaMetaFCOs*);

	static CStringList modelkindnames;
	static CStringList atomkindnames;
	static CStringList refkindnames;
	static CStringList connectionkindnames;
	static CStringList setkindnames;

	static CBuilderModelCreateFunctionTable *modelBuildFunctions;
	static CBuilderAtomCreateFunctionTable *atomBuildFunctions;
	static CBuilderRefCreateFunctionTable *refBuildFunctions;
	static CBuilderModelRefCreateFunctionTable *modelRefBuildFunctions;
	static CBuilderAtomRefCreateFunctionTable *atomRefBuildFunctions;
	static CBuilderConnectionCreateFunctionTable *connectionBuildFunctions;
	static CBuilderSetCreateFunctionTable *setBuildFunctions;

	static CBuilderModel* Create(IMgaModel* iModel, CBuilderModel* parent);
	static CBuilderAtom* Create(IMgaAtom* iAtom, CBuilderModel* parent);
	static CBuilderReference* Create(IMgaReference* iModelRef, CBuilderModel* parent);
	static CBuilderConnection* Create(IMgaSimpleConnection* iConnection, CBuilderModel* parent);
	static CBuilderSet* Create(IMgaSet* iSet, CBuilderModel* parent);
};

// -------------------------- Macros

#define DECLARE_CUSTOMXXX(CLASS, BASECLASS, CBUILDERMODEL, IMGAMODEL) \
	DECLARE_DYNAMIC(CLASS) \
protected: \
	CLASS(IMGAMODEL* iModel, CBuilderModel* parent); \
public: \
	static CBUILDERMODEL* Create(IMGAMODEL* iModel, CBuilderModel* parent); \
	static CBuilderFactory registercreatefunc;

#define IMPLEMENT_CUSTOMXXX(CLASS, BASECLASS, NAMES, CBUILDERMODEL, IMGAMODEL) \
IMPLEMENT_DYNAMIC(CLASS, BASECLASS) \
CLASS::CLASS(IMGAMODEL* iInterface, CBuilderModel* parent) \
	: BASECLASS(iInterface, parent) { } \
CBUILDERMODEL* CLASS::Create(IMGAMODEL* iModel, CBuilderModel* parent) \
{ \
	CLASS* ptr = new CLASS(iModel, parent); \
	ptr->Initialize(); \
	return ptr; \
} \
CBuilderFactory CLASS::registercreatefunc(NAMES, CLASS::Create);

#define DECLARE_CUSTOMXXXBASE(CLASS, BASECLASS, CBUILDERMODEL, IMGAMODEL) \
	DECLARE_DYNAMIC(CLASS) \
protected: \
	CLASS(IMGAMODEL* iInterface, CBuilderModel* parent) : BASECLASS(iInterface, parent) { } \
public:

#define IMPLEMENT_CUSTOMXXXBASE(CLASS, BASECLASS, CBUILDERMODEL, IMGAMODEL) \
IMPLEMENT_DYNAMIC(CLASS, BASECLASS) \


// --- Custom

#define DECLARE_CUSTOMMODEL(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXX(CLASS, BASECLASS, CBuilderModel, IMgaModel)
#define IMPLEMENT_CUSTOMMODEL(CLASS, BASECLASS, NAMES) \
	IMPLEMENT_CUSTOMXXX(CLASS, BASECLASS, NAMES, CBuilderModel, IMgaModel)

#define DECLARE_CUSTOMATOM(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXX(CLASS, BASECLASS, CBuilderAtom, IMgaAtom)
#define IMPLEMENT_CUSTOMATOM(CLASS, BASECLASS, NAMES) \
	IMPLEMENT_CUSTOMXXX(CLASS, BASECLASS, NAMES, CBuilderAtom, IMgaAtom)

#define DECLARE_CUSTOMREF(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXX(CLASS, BASECLASS, CBuilderReference, IMgaReference)
#define IMPLEMENT_CUSTOMREF(CLASS, BASECLASS, NAMES) \
	IMPLEMENT_CUSTOMXXX(CLASS, BASECLASS, NAMES, CBuilderReference, IMgaReference)

#define DECLARE_CUSTOMMODELREF(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXX(CLASS, BASECLASS, CBuilderModelReference, IMgaReference)
#define IMPLEMENT_CUSTOMMODELREF(CLASS, BASECLASS, NAMES) \
	IMPLEMENT_CUSTOMXXX(CLASS, BASECLASS, NAMES, CBuilderModelReference, IMgaReference)

#define DECLARE_CUSTOMATOMREF(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXX(CLASS, BASECLASS, CBuilderAtomReference, IMgaReference)
#define IMPLEMENT_CUSTOMATOMREF(CLASS, BASECLASS, NAMES) \
	IMPLEMENT_CUSTOMXXX(CLASS, BASECLASS, NAMES, CBuilderAtomReference, IMgaReference)

#define DECLARE_CUSTOMCONNECTION(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXX(CLASS, BASECLASS, CBuilderConnection, IMgaSimpleConnection)
#define IMPLEMENT_CUSTOMCONNECTION(CLASS, BASECLASS, NAMES) \
	IMPLEMENT_CUSTOMXXX(CLASS, BASECLASS, NAMES, CBuilderConnection, IMgaSimpleConnection)

#define DECLARE_CUSTOMSET(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXX(CLASS, BASECLASS, CBuilderSet, IMgaSet)
#define IMPLEMENT_CUSTOMSET(CLASS, BASECLASS, NAMES) \
	IMPLEMENT_CUSTOMXXX(CLASS, BASECLASS, NAMES, CBuilderSet, IMgaSet)



// --- Base

#define DECLARE_CUSTOMMODELBASE(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderModel, IMgaModel)
#define IMPLEMENT_CUSTOMMODELBASE(CLASS, BASECLASS) \
	IMPLEMENT_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderModel, IMgaModel)

#define DECLARE_CUSTOMATOMBASE(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderAtom, IMgaAtom)
#define IMPLEMENT_CUSTOMATOMBASE(CLASS, BASECLASS) \
	IMPLEMENT_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderAtom, IMgaAtom)

#define DECLARE_CUSTOMREFBASE(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderReference, IMgaReference)
#define IMPLEMENT_CUSTOMREFBASE(CLASS, BASECLASS) \
	IMPLEMENT_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderReference, IMgaReference)

#define DECLARE_CUSTOMMODELREFBASE(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderModelReference, IMgaReference)
#define IMPLEMENT_CUSTOMMODELREFBASE(CLASS, BASECLASS) \
	IMPLEMENT_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderModelReference, IMgaReference)

#define DECLARE_CUSTOMATOMREFBASE(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderAtomReference, IMgaReference)
#define IMPLEMENT_CUSTOMATOMREFBASE(CLASS, BASECLASS) \
	IMPLEMENT_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderAtomReference, IMgaReference)

#define DECLARE_CUSTOMCONNECTIONBASE(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderConnection, IMgaSimpleConnection)
#define IMPLEMENT_CUSTOMCONNECTIONBASE(CLASS, BASECLASS) \
	IMPLEMENT_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderConnection, IMgaSimpleConnection)

#define DECLARE_CUSTOMSETBASE(CLASS, BASECLASS) \
	DECLARE_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderSet, IMgaSet)
#define IMPLEMENT_CUSTOMSETBASE(CLASS, BASECLASS) \
	IMPLEMENT_CUSTOMXXXBASE(CLASS, BASECLASS, CBuilderSet, IMgaSet)


// --- Cast

#endif // whole file
