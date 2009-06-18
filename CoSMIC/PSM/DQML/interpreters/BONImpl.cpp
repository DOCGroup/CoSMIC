//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	BONImpl.cpp
//
//###############################################################################################################################################

/*
	Copyright (c) Vanderbilt University, 2000-2003
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

#define TEST_META_CONFORMANCE_INSIDE_BON // by ZolMol

#include "stdafx.h"
#include "BONImpl.h"
#include "Extensions.h"
#include <ComponentConfig.h>

namespace BON
{

//###############################################################################################################################################
//
// 	H E L P E R   T E M P L A T E S,   F U N C T I O N S,   M A C R O S
//
//###############################################################################################################################################

	inline ProjectImpl* _getProject( IMgaObject* spObject, ProjectImpl* pProject )
	{
		if ( pProject )
			return pProject;
		ProjectPtr spProject;
		COMTHROW( spObject->get_Project( spProject.Addr() ) );
		return (ProjectImpl*) ProjectImpl::attach( spProject ).getCounted();
	}

	inline MON::ObjectPtr _getMetaBase( IMgaObject* spObject )
	{
		MON::ObjectPtr spMeta;
		COMTHROW( spObject->get_MetaBase( spMeta.Addr() ) );
		return spMeta;
	}

	inline std::string _getMetaName( IMgaObject* spObject )
	{
		CComBSTR bstrName;
		COMTHROW( _getMetaBase( spObject )->get_Name( &bstrName ) );
		return Util::Copy( bstrName );
	}

	inline long _getMetaRef( IMgaObject* spObject )
	{
		long lRef;
		COMTHROW( _getMetaBase( spObject )->get_MetaRef( &lRef ) );
		return lRef;
	}

	inline MON::Containment _getMetaRole( IMgaFCO* spFCO )
	{
		MON::ContainmentPtr spMeta;
		COMTHROW( spFCO->get_MetaRole( spMeta.Addr() ) );
		return MON::Containment(spMeta);
	}

	inline void _checkIsCallable( ObjectImpl* pObject )
	{
		#ifdef GME_ADDON
			if ( pObject->getStatus() != OST_Exists )
				ASSERTTHROW( Exception( "Object is already deleted. Operation is illegal!" ) );
		#endif
	}

	inline bool _isAddOn()
	{
		#ifdef GME_ADDON
			return true;
		#else
			return false;
		#endif
	}

	template < class T >
	std::set<T>& filterByAspect( std::set<T>& inSet, const MON::Aspect& meta )
	{
		if ( meta ) {
			std::set<T>::iterator it = inSet.begin();
			while ( it != inSet.end() ) {
				std::set<T>::iterator itSaved = it;
				it++;
				if ( ! (*itSaved)->isVisible( meta, true ) )
					inSet.erase( itSaved );
			}
		}
		return inSet;
	}

	template < class T , class TI>
	void setCopy( const std::set<TI*>& setIn, std::set<T>& setOut )
	{
		for ( std::set<TI*>::const_iterator it = setIn.begin() ; it != setIn.end() ; it++ )
			setOut.insert( *it );
	}

	template < class T , class TI, class TC>
	void setCastCopy( const std::set<TI*>& setIn, std::set<T>& setOut )
	{
		for ( std::set<TI*>::const_iterator it = setIn.begin() ; it != setIn.end() ; it++ )
			setOut.insert( dynamic_cast<TC*>( *it ) );
	}

	#define THROW_METAPROJECT_BELONG( META )					\
		if ( META.project() != getProject()->getProjectMeta() )	\
		{     \
			MON::Exception exc( "? does not belong to ? of ?!");  \
			exc << META.infoString() << getProject()->getProjectMeta().infoString() << getProject()->getInfoString(); \
			ASSERTTHROW( exc); \
		}

	#define THROW_PROJECT_BELONG( OBJECT )					\
		if ( OBJECT->getProject() != getProject() )					\
		{  \
			BON::Exception exc( "? does not belong to ?!");    \
			exc << OBJECT->getInfoString().c_str() << getProject()->getInfoString().c_str(); \
			ASSERTTHROW( exc );   \
		}

	#define THROW_METAPROJECT_DOES_NOT_HAVE( META, CLASS, NAME )	\
		if ( ! META )													\
			{\
				MON::Exception exc( "MON::##CLASS [ ? ] does not exist in ? of ?!");\
				exc << NAME.c_str() << getProject()->getProjectMeta().infoString().c_str() << getProject()->getInfoString().c_str();\
				ASSERTTHROW( exc );\
			}

	#define THROW_CANNOT_BE_NULL( META, CLASS )		\
		if ( ! META )									\
			{\
			ASSERTTHROW( Exception( std::string( CLASS ) + " cannot be null!" ) );\
			}

	#define THROW_CANNOT_BE_EMPTY( WHAT, THESTR )	\
		if ( THESTR.empty() )							\
			ASSERTTHROW( Exception( std::string( WHAT ) + " cannot be empty string!" ) );

	#define PREF_Color "/color"
	#define PREF_NameColor "/nameColor"
	#define PREF_NameEnabled "/isNameEnabled"
	#define PREF_HelpURL "/help"
	#define PREF_Location1 "/PartRegs/"
	#define PREF_Location2 "/Position"
	#define PREF_NamePosition "/namePosition"
	#define PREF_NameWrap "/nameWrap"
	#define PREF_HotSpotEnabled "/isHotspotEnabled"
	#define PREF_TypeNameEnabled "/isTypeShown"
	#define PREF_TypeInfoEnabled "/isTypeInfoShown"
	#define PREF_Decorator "/decorator"
	#define PREF_Icon "/icon"
	#define PREF_PortIcon "/porticon"
	#define PREF_SubTypeIcon "/subTypeIcon"
	#define PREF_InstanceIcon "/instanceIcon"
	#define PREF_BorderColor "/borderColor"
	#define PREF_BackgroundColor "/backgroundColor"
	#define PREF_PortNameColor "/portColor"
	#define PREF_LineType "/lineType"
	#define PREF_SrcLineEndType "/srcStyle"
	#define PREF_DstLineEndType "/dstStyle"
	#define PREF_LabelFormat "/labelFormatStr"
	#define PREF_SrcLabel1 "/srcLabel1"
	#define PREF_SrcLabel2 "/srcLabel2"
	#define PREF_DstLabel1 "/dstLabel1"
	#define PREF_DstLabel2 "/dstLabel2"

	bool Convert( const std::string& strValue, long& lValue, bool bIsHexa )
	{
		return sscanf( strValue.c_str(), ( bIsHexa ) ? "%x" : "%d", &lValue ) == 1;
	}

	bool Convert( const std::string& strValue, COLORREF& crValue )
	{
		long lValue;
		if ( ! Convert( strValue, lValue, true ) ) {
			crValue = 0x0;
			return false;
		}
		unsigned int uiR = ( lValue & 0xFF0000 ) >> 16;
		unsigned int uiG = ( lValue  & 0xFF00 ) >> 8;
		unsigned int uiB = ( lValue & 0xFF );
		crValue = RGB( uiR, uiG, uiB );
		return true;
	}

	std::string Convert( COLORREF crValue )
	{
		char chBuffer[ 100 ];
		sprintf( chBuffer, "%x", crValue );
		return chBuffer;
	}

	bool Convert( const std::string& strValueIn, NamePosition& eValue )
	{
		int iValue = 0;
		if ( sscanf( strValueIn.c_str(), "%d", &iValue ) == 1 ) {
			eValue = (NamePosition) iValue;
			return true;
		}
		CString strValue( strValueIn.c_str() );
		strValue.TrimLeft( _T("\t ") );
		strValue.TrimRight( _T("\t ") );
		if ( strValue == "N") {
			eValue = NP_North;
			return true;
		}
		if ( strValue == "NE") {
			eValue = NP_NorthEast;
			return true;
		}
		if ( strValue == "E") {
			eValue = NP_East;
			return true;
		}
		if ( strValue == "SE") {
			eValue = NP_SouthEast;
			return true;
		}
		if ( strValue == "S") {
			eValue = NP_South;
			return true;
		}
		if ( strValue == "SW") {
			eValue = NP_SouthWest;
			return true;
		}
		if ( strValue == "W") {
			eValue = NP_West;
			return true;
		}
		if ( strValue == "NW") {
			eValue = NP_NorthWest;
			return true;
		}
		if ( strValue =="C") {
			eValue = NP_Center;
			return true;
		}
		return false;
	}

	std::string Convert( NamePosition pos )
	{
		switch ( pos ) {
			case NP_Center : return "C";
			case NP_South : return "S";
			case NP_North : return "N";
			case NP_West : return "W";
			case NP_East : return "E";
			case NP_SouthWest : return "SW";
			case NP_SouthEast : return "SE";
			case NP_NorthWest : return "NW";
			case NP_NorthEast : return "NE";
		}
		return "S";
	}

	bool Convert( const std::string& strValue, LineType& eType )
	{
		if ( strValue == "dash" ) {
			eType = LT_Dash;
			return true;
		}
		if ( strValue == "solid" ) {
			eType = LT_Solid;
			return true;
		}
		return false;
	}

	std::string Convert( LineType eType )
	{
		switch ( eType ) {
			case LT_Solid : return "solid";
			case LT_Dash : return "dash";
		}
		return "solid";
	}

	bool Convert( const std::string& strValue, LineEndType& eType )
	{
		if ( strValue == "butt" ) {
			eType = LET_Butt;
			return true;
		}
		if ( strValue == "arrow" ) {
			eType = LET_Arrow;
			return true;
		}
		if ( strValue == "diamond" ) {
			eType = LET_Diamond;
			return true;
		}
		if ( strValue == "apex" ) {
			eType = LET_Apex;
			return true;
		}
		if ( strValue == "bullet" ) {
			eType = LET_Bullet;
			return true;
		}
		if ( strValue == "empty diamond" ) {
			eType = LET_EmptyDiamond;
			return true;
		}
		if ( strValue == "empty apex" ) {
			eType = LET_EmptyApex;
			return true;
		}
		if ( strValue == "empty bullet" ) {
			eType = LET_EmptyBullet;
			return true;
		}
		return false;
	}

	std::string Convert( LineEndType eType )
	{
		switch ( eType )  {
			case LET_Butt : return "butt";
			case LET_Arrow : return "arrow";
			case LET_Diamond : return "diamond";
			case LET_Apex : return "apex";
			case LET_Bullet : return "bullet";
			case LET_EmptyDiamond : return "empty diamond";
			case LET_EmptyApex : return "empty apex";
			case LET_EmptyBullet : return "empty bullet";
		}
		return "butt";
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ProjectImpl
//
//###############################################################################################################################################

	ProjectImpl::ProjectMap ProjectImpl::mapProjects;

	ProjectImpl::ProjectImpl( IMgaProject* spProject )
		: Util::GenRefCounted( true, NULL ), m_spProject( spProject ), m_bAutoCommit( true ), m_pRootFolder( NULL ), m_bIsDestructionActive( false )
	{
		// Insert into ProjectMap
		mapProjects.insert( ProjectMap::value_type( ProjectPtr( spProject ), this ) );

		// Retrieve Meta
		MON::ProjectPtr spMeta;
		COMTHROW( m_spProject->get_RootMeta( spMeta.Addr() ) );
		m_meta = MON::Project( spMeta );
	}

	ProjectImpl::~ProjectImpl()
	{
		m_bIsDestructionActive = true;

		if ( ! isDeleted() ) {
			for ( ObjectMap::iterator it = m_mapObjects.begin() ; it != m_mapObjects.end() ; it++ )
				delete it->second;
		}

		mapProjects.erase( m_spProject );

		m_mapObjects.clear();
		m_mapObjectsByID.clear();
		m_mapObjectsByKind.clear();
		m_spProject = NULL;
		m_pRootFolder = NULL;
		m_gme = NULL;
		m_meta = MON::Project();
	}

	void ProjectImpl::finalizeObjects()
	{
		ObjectSet objects;
		for ( ObjectMap::iterator it = m_mapObjects.begin() ; it != m_mapObjects.end() ; it++ )
			objects.insert( it->second );
		for ( ObjectSet::iterator it2 = objects.begin() ; it2 != objects.end() ; it2++ )
			(*it2)->finalize();
	}

	Project ProjectImpl::attach( IMgaProject* spProject )
	{
		ProjectMap::iterator it = mapProjects.find( spProject );
		if ( it != mapProjects.end() )
			return it->second;

		return new ProjectImpl( spProject );
	}

	bool ProjectImpl::setDeleted()
	{
		{	using namespace Util; if ( GenRefCounted::setDeleted() ) return true; }

		for ( ObjectMap::iterator it = m_mapObjects.begin() ; it != m_mapObjects.end() ; it++ )
			it->second->setDeleted();
		return false;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ProjectImpl					// Get and Set operations // ---> Interface Methods

	bool ProjectImpl::isAutoCommit() const
	{
		return m_bAutoCommit;
	}

	void ProjectImpl::setAutoCommit( bool bAutoCommit )
	{
		m_bAutoCommit = bAutoCommit;
		if ( ! m_bAutoCommit && bAutoCommit ) {
			commit();
		}
	}

	void ProjectImpl::commit()
	{
		COMTHROW( m_spProject->CommitTransaction() );

		if (!m_spTerritory) {
			COMTHROW( m_spProject->CreateTerritory( NULL, m_spTerritory.Addr() ) );
		}
		COMTHROW( m_spProject->BeginTransaction( m_spTerritory ) );
	}

	void ProjectImpl::abort()
	{
		COMTHROW( m_spProject->AbortTransaction() );

		if (!m_spTerritory) {
			COMTHROW( m_spProject->CreateTerritory( NULL, m_spTerritory.Addr() ) );
		}
		COMTHROW( m_spProject->BeginTransaction( m_spTerritory ) );
	}

	bool ProjectImpl::isDestructionActive() const
	{
		return m_bIsDestructionActive;
	}

	ProjectPtr ProjectImpl::getProjectI() const
	{
		return m_spProject;
	}

	const MON::Project& ProjectImpl::getProjectMeta() const
	{
		return m_meta;
	}

	std::string ProjectImpl::getName() const
	{
		CComBSTR bstrName;
		COMTHROW( m_spProject->get_Name( &bstrName ) );
		return Util::Copy( bstrName );
	}

	std::string ProjectImpl::getAuthor() const
	{
		CComBSTR bstrAuthor;
		COMTHROW( m_spProject->get_Author( &bstrAuthor ) );
		return Util::Copy( bstrAuthor );
	}

	std::string ProjectImpl::getComment() const
	{
		CComBSTR bstrComment;
		COMTHROW( m_spProject->get_Comment( &bstrComment ) );
		return Util::Copy( bstrComment );
	}

	std::string ProjectImpl::getCreationTime() const
	{
		CComBSTR bstrTime;
		COMTHROW( m_spProject->get_CreateTime( &bstrTime ) );
		return Util::Copy( bstrTime );
	}

	std::string ProjectImpl::getChangeTime() const
	{
		CComBSTR bstrTime;
		COMTHROW( m_spProject->get_ChangeTime( &bstrTime ) );
		return Util::Copy( bstrTime );
	}

	std::string ProjectImpl::getGUID() const
	{
		CComVariant v;
		COMTHROW( m_spProject->get_GUID( &v ) );

		if (v.vt != (VT_UI1 | VT_ARRAY) || 
			v.parray == NULL || 
			v.parray->cbElements != 1 ||
			v.parray->cDims != 1 ||
			v.parray->rgsabound[0].cElements != sizeof(GUID)) {

			ASSERTTHROW( BON::Exception( "Invalid GUID format!" ) );

		}

		GUID guid;
		unsigned char *start = (unsigned char*)&guid;
		unsigned char *end = (unsigned char*)(&guid+1);
		const unsigned char *q = NULL;

		COMTHROW( SafeArrayAccessData(v.parray, (void**)&q) );

		if (q == NULL ) {
			ASSERTTHROW( BON::Exception( "Error in GUID conversion!" ) );
		}

		memcpy( start, q, (end - start) * sizeof(unsigned char) );
		COMTHROW( SafeArrayUnaccessData(v.parray) );

		wchar_t *guidstr = NULL;
		COMTHROW(StringFromCLSID(guid,&guidstr));
		std::string strResult = Util::Copy( guidstr );
		CoTaskMemFree(guidstr); 

		return strResult;
	}

	std::string ProjectImpl::getVersion() const
	{
		CComBSTR bstrVersion;
		COMTHROW( m_spProject->get_Version( &bstrVersion ) );
		return Util::Copy( bstrVersion );
	}

	void ProjectImpl::setName( const std::string& strName )
	{
		COMTHROW( m_spProject->put_Name( Util::Copy( strName ) ) );
		if ( isAutoCommit() )
			commit();
	}

	void ProjectImpl::setAuthor( const std::string& strAuthor )
	{
		COMTHROW( m_spProject->put_Author( Util::Copy( strAuthor ) ) );
		if ( isAutoCommit() )
			commit();
	}

	void ProjectImpl::setComment( const std::string& strComment )
	{
		COMTHROW( m_spProject->put_Comment( Util::Copy( strComment ) ) );
		if ( isAutoCommit() )
			commit();
	}

	std::string ProjectImpl::getInfoString( unsigned short usOptions ) const
	{
		bool bAll = ( usOptions & Util::IO_All ) ? true : false;
		bool bIdent = bAll || ( usOptions & Util::IO_Identifiers );
		bool bLine = bAll || ( usOptions & Util::IO_NewLine );
		std::string strDelim = ( bLine ) ? "\n" : ", ";

		std::string strInfo( "BON::Project" );
		strInfo += ( bLine ) ? " :\n" : " [";

		if ( bIdent )
			strInfo += "name: ";
		strInfo += getName();

		if ( ( usOptions & Util::IO_Specific ) || bAll ) {
			strInfo += strDelim;
			if ( bIdent )
				strInfo += "author: ";
			strInfo += getAuthor() + strDelim;
			if ( bIdent )
				strInfo += "comment: ";
			strInfo += getComment() + strDelim;
			if ( bIdent )
				strInfo += "creationTime: ";
			strInfo += getCreationTime() + strDelim;
			if ( bIdent )
				strInfo += "changeTime: ";
			strInfo += getChangeTime();
		}

		if ( ( usOptions & Util::IO_Meta ) || bAll ) {
			strInfo += strDelim;
			if ( bIdent )
				strInfo += "meta: ";
			strInfo += getProjectMeta().infoString( bIdent );
		}

		if ( ! bLine )
			strInfo += "]";

		return strInfo;
	}

	std::string ProjectImpl::getInfoString( const std::set<Util::InfoOption>& setOptions ) const
	{
		return getInfoString( copy( setOptions ) );
	}

	void ProjectImpl::assignTerritory(TerritoryPtr terr) {
		m_spTerritory = terr;
	}

	void ProjectImpl::consoleMsg(const std::string& msg, msgtype_enum type)
	{
		GMEAppPtr pGME = getGME();
		COMTHROW(pGME->ConsoleMessage(Util::Copy( msg ), type));
	}

	std::string ProjectImpl::getConsoleContents()
	{
		GMEAppPtr pGME = getGME();
		CComBSTR ccBstr;
		COMTHROW(pGME->get_ConsoleContents( &ccBstr));
		return Util::Copy( ccBstr );
	}

	void ProjectImpl::putConsoleContents(const std::string& htmlMsg )
	{
		GMEAppPtr pGME = getGME();
		CComBSTR ccBstr(htmlMsg.c_str());
		COMTHROW(pGME->put_ConsoleContents( ccBstr));
	}

	std::string	ProjectImpl::getGMEVersion()
	{
		GMEAppPtr pGME = getGME();
		CComBSTR verBstr;
		COMTHROW(pGME->get_Version(&verBstr));
		return Util::Copy( verBstr );
	}

	int	ProjectImpl::getGMEVersionMajor() {
		GMEAppPtr pGME = getGME();
		short n;
		COMTHROW(pGME->get_VersionMajor(&n));
		return n;
	}

	int	ProjectImpl::getGMEVersionMinor() {
		GMEAppPtr pGME = getGME();
		short n;
		COMTHROW(pGME->get_VersionMinor(&n));
		return n;
	}

	int	ProjectImpl::getGMEVersionPatchLevel() {
		GMEAppPtr pGME = getGME();
		short n;
		COMTHROW(pGME->get_VersionPatchLevel(&n));
		return n;
	}

	void ProjectImpl::saveProject() {
		if (m_spTerritory) {
			COMTHROW( m_spProject->CommitTransaction( ));
		}

		GMEAppPtr pGME = getGME();
		COMTHROW(pGME->SaveProject());

		if (m_spTerritory) {
			COMTHROW( m_spProject->BeginTransaction( m_spTerritory ));
		}

	}
 
	void ProjectImpl::saveProjectAs(const std::string& connstr) {
		if (m_spTerritory) {
			COMTHROW( m_spProject->CommitTransaction( ));
		}

		GMEAppPtr pGME = getGME();
		COMTHROW(pGME->SaveProjectAs(Util::Copy( connstr )));

		if (m_spTerritory) {
			COMTHROW( m_spProject->BeginTransaction( m_spTerritory ));
		}
	}

	void ProjectImpl::exportProject(const std::string& connstr) {
		if (m_spTerritory) {
			COMTHROW( m_spProject->CommitTransaction( ));
		}

		GMEAppPtr pGME = getGME();
		COMTHROW(pGME->ExportProject(Util::Copy( connstr )));

		if (m_spTerritory) {
			COMTHROW( m_spProject->BeginTransaction( m_spTerritory ));
		}
	}

	void ProjectImpl::importProject(const std::string& connstr) {
		if (m_spTerritory) {
			COMTHROW( m_spProject->CommitTransaction( ));
		}

		GMEAppPtr pGME = getGME();
		COMTHROW(pGME->ImportProject(Util::Copy( connstr )));

		if (m_spTerritory) {
			COMTHROW( m_spProject->BeginTransaction( m_spTerritory ));
		}
	}

	void ProjectImpl::checkConstraints() {
		if (m_spTerritory) {
			COMTHROW( m_spProject->CommitTransaction( ));
		}

		GMEAppPtr pGME = getGME();
		COMTHROW(pGME->CheckAllConstraints());

		if (m_spTerritory) {
			COMTHROW( m_spProject->BeginTransaction( m_spTerritory ));
		}
	}

	void ProjectImpl::runComponent(const std::string& progID) {
		if (m_spTerritory) {
			COMTHROW( m_spProject->CommitTransaction( ));
		}

		GMEAppPtr pGME = getGME();
		COMTHROW(pGME->RunComponent(Util::Copy( progID )));

		if (m_spTerritory) {
			COMTHROW( m_spProject->BeginTransaction( m_spTerritory ));
		}
	}

	void ProjectImpl::showFCO(FCO fco) {
		if (m_spTerritory) {
			COMTHROW( m_spProject->CommitTransaction( ));
		}

		GMEAppPtr pGME = getGME();
		COMTHROW(pGME->ShowFCO(fco->getFCOI()));

		if (m_spTerritory) {
			COMTHROW( m_spProject->BeginTransaction( m_spTerritory ));
		}
	}

//===============================================================================================================================================
// 	C L A S S : BON::ProjectImpl					// Relations - Find and Search

	ObjectImpl* ProjectImpl::findByCOMI( IMgaObject* spObject ) const
	{
		ObjectMap::const_iterator it = m_mapObjects.find( ObjectPtr( spObject ) );
		return ( it == m_mapObjects.end() ) ? NULL : it->second;
	}

	ObjectImpl* ProjectImpl::findByIDI( const std::string& strID )
	{
		// Look for in Objects' cache

		ObjectMapByID::iterator it = m_mapObjectsByID.find( strID );
		if ( it != m_mapObjectsByID.end() )
			return it->second;

		// Retrieve and Attach

		ObjectPtr spObject;
		COMTHROW( m_spProject->GetObjectByID( Util::Copy( strID ), spObject.Addr() ) );
		if ( ! spObject )
			return NULL;

		return ObjectImpl::attachI( spObject, this );
	}

	ObjectSet ProjectImpl::findByKindI( const MON::FCO& meta )
	{
		// Look for in Kinds' cache
		ObjectMapByKind::iterator it = m_mapObjectsByKind.find( meta );
		if ( it != m_mapObjectsByKind.end() && it->second.first )
			return it->second.second;

		// Create Filter
		Util::ComPtr<IMgaFilter> spFilter;
		COMTHROW( m_spProject->CreateFilter( spFilter.Addr() ) );
		COMTHROW( spFilter->put_Kind( Util::Copy( meta.name() ) ) );

		// Retrieve Objects
		Util::ComPtr<IMgaFCOs> spFCOs;
		COMTHROW( m_spProject->AllFCOs( spFilter, spFCOs.Addr() ) );

		// Retrieve and Attach
		MGACOLL_ITERATE( IMgaFCO, spFCOs.p ) {
			ObjectImpl::attachI( MGACOLL_ITER, this, meta );
		} MGACOLL_ITERATE_END;

		// Set its fully retrieved and return
		m_mapObjectsByKind[ meta ].first = true;
		return m_mapObjectsByKind[ meta ].second;
	}

	ObjectSet ProjectImpl::findByKindI( const MON::Folder& meta )
	{
		// Look for in Kinds' cache
		ObjectMapByKind::iterator it = m_mapObjectsByKind.find( meta );
		if ( it != m_mapObjectsByKind.end() && it->second.first )
			return it->second.second;

		// Look for in Kinds' cache
		findByKindI( getRootFolder()->getFolderI(), meta );  // CHANGED LINE

		// Set its fully retrieved and return
		m_mapObjectsByKind[ meta ].first = true;
		return m_mapObjectsByKind[ meta ].second;
	}

	void ProjectImpl::findByKindI( FolderPtr spFolder, const MON::Folder& meta )
	{
		// Check if it is this kind of
		if ( _getMetaRef( spFolder ) == meta.ref() )
			ObjectImpl::attachI( spFolder, this, meta );

		// Traverse Children
		Util::ComPtr<IMgaFolders> spFolders;
		COMTHROW( spFolder->get_ChildFolders( spFolders.Addr() ) );
		MGACOLL_ITERATE( IMgaFolder, spFolders.p ) {
			findByKindI( MGACOLL_ITER, meta );
		} MGACOLL_ITERATE_END;
	}

	GMEAppPtr ProjectImpl::getGME()
	{
		if (!m_gme) {
			CComBSTR bstrName("GME.Application");
			CComQIPtr<IMgaClient> pClient;
			COMTHROW(m_spProject->GetClientByName(bstrName, &pClient));
			if (pClient) {
				CComQIPtr<IDispatch> pDispatch;
				COMTHROW(pClient->get_OLEServer(&pDispatch));
				if (pDispatch) {
					COMTHROW(pDispatch.QueryInterface(m_gme.Addr()));
				}
			}
		}
		if (!m_gme) {
			ASSERTTHROW( Exception( "Unable to retrieve GME Application object" ) );
		}
		return m_gme;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ProjectImpl					// Event Handlers

	void ProjectImpl::onObjectRetrieved( ObjectImpl* pObject )
	{
		m_mapObjectsByID[ pObject->getID() ] = pObject;

		ObjectMapByKind::iterator it = m_mapObjectsByKind.find( pObject->getObjectMeta() );
		if ( it == m_mapObjectsByKind.end() )
			m_mapObjectsByKind[ pObject->getObjectMeta() ] = ObjectSetPair( false, ObjectSet() );
		m_mapObjectsByKind[ pObject->getObjectMeta() ].second.insert( pObject );
		m_mapObjects.insert( ObjectMap::value_type( pObject->getObjectI(), pObject ) );
	}

	void ProjectImpl::onObjectReleased( ObjectImpl* pObject, bool bOnlyMemoryFree )
	{
		m_mapObjectsByID.erase( pObject->getID() );
		m_mapObjectsByKind[ pObject->getObjectMeta() ].second.erase( pObject );
		m_mapObjects.erase( pObject->getObjectI() );
		if ( bOnlyMemoryFree )
			m_mapObjectsByKind[ pObject->getObjectMeta() ].first = false;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ProjectImpl					// Relations // ----> Interface Methods

	Folder ProjectImpl::getRootFolder()
	{
		if ( m_pRootFolder )
				return m_pRootFolder;

		FolderPtr spFolder;
		COMTHROW( m_spProject->get_RootFolder( spFolder.Addr() ) );
		return m_pRootFolder = (FolderImpl*) ObjectImpl::attachI( spFolder, this );
	}

	// CHANGED LINE BEGIN

	std::set<Folder> ProjectImpl::getLibraries()
	{
		std::set<Folder> setResult;
		std::set<Object> set = findByKind( "RootFolder" );
		for ( std::set<Object>::iterator it = set.begin() ; it != set.end() ; ++it )
			if ( getRootFolder() != *it )
				setResult.insert( Folder( *it ) );
		return setResult;
	}

	// CHANGED LINE END

	Object	ProjectImpl::findByID( const std::string& strID, bool bExIfNotExist )
	{
		BON::Object object = findByIDI( strID );
		if ( bExIfNotExist && ! object )
		{
			Exception exc( "BON::Object with ID [ ? ] does not exist!");
			exc << strID;
			ASSERTTHROW( exc );
		}
		return object;
	}

	std::set<Object> ProjectImpl::findByKind( const MON::Object& meta )
	{
		if ( ! meta )
			ASSERTTHROW( Exception( "MON::Object cannot be null!" ) );
		if ( meta.project() != getProjectMeta() )
		{
			MON::Exception exc( "? does not belong to ? of ?!");//, "sss", 
			exc << meta.infoString() << getProjectMeta().infoString() << getInfoString().c_str(); 
			ASSERTTHROW( exc);
		}
		if ( meta.type() < MON::OT_Model || meta.type() > MON::OT_Folder )
		{
			Exception exc( "Type of ? can be only MON::Folder or MON::FCO!");//, "s", 
			exc << meta.infoString();
			ASSERTTHROW( exc );
		}

		std::set<Object> setResult;
		setCopy<Object,ObjectImpl>( ( meta.type() == MON::OT_Folder ) ? findByKindI( MON::Folder( meta ) ) : findByKindI( MON::FCO( meta ) ), setResult );
		return setResult;
	}

	std::set<Object> ProjectImpl::findByKind( const std::string& strKind )
	{
		MON::Object meta = getProjectMeta().findByName( strKind );
		if ( ! meta )
		{
			MON::Exception exc( "MON::Folder [ ? ] or MON::FCO [ ? ] does not exist in ? of ?!");// "ssss", 
			exc << strKind.c_str() << strKind.c_str() << getProjectMeta().infoString().c_str() << getInfoString().c_str();
			ASSERTTHROW( exc );
		}
		if ( meta.type() < MON::OT_Model || meta.type() > MON::OT_Folder )
		{
			Exception exc( "? is not MON::Folder or MON::FCO!");// "s", 
			exc << meta.infoString().c_str();
			ASSERTTHROW( exc );
		}

		std::set<Object> setResult;
		setCopy<Object,ObjectImpl>( ( meta.type() == MON::OT_Folder ) ? findByKindI( MON::Folder( meta ) ) : findByKindI( MON::FCO( meta ) ), setResult );
		return setResult;
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ObjectImpl
//
//###############################################################################################################################################

	ObjectImpl::ObjectImpl()
		:  m_bAllParentFolders( false ), m_bIsDestructionActive( false )
	{
		setDisposable( _isAddOn() );
	}

	ObjectImpl* ObjectImpl::getEx( IMgaObject* spObject, ObjectType eType, const MON::Object& meta )
	{
		std::string strKind = ( meta ) ? meta.name() : _getMetaName( spObject );
		std::string strRole;
		if ( eType != OT_Folder ) {
			CComQIPtr<IMgaFCO> spFCO = spObject;
			MON::Containment role = _getMetaRole( spFCO );
			if ( role )
				strRole = role.name();
		}
		return ExtensionManager::createImpl( eType, strKind, strRole );
	}

	void ObjectImpl::doInitialize( IMgaObject* spObject, ProjectImpl* pProject, const MON::Object& meta )
	{
		m_spObject = spObject;
		m_pProject = _getProject( spObject, pProject );
		std::set<Util::GenRefCounted*> setAggrs;
		setAggrs.insert( m_pProject );
		setAggregators( setAggrs );
		m_meta = meta;

		// Retrieve Meta
		if ( ! meta ) {
			MON::ObjectPtr spMetaBase;
			COMTHROW( m_spObject->get_MetaBase( spMetaBase.Addr() ) );
			long lRef;
			COMTHROW( spMetaBase->get_MetaRef( &lRef ) );
			m_meta = m_pProject->getProjectMeta().findByRef( lRef );
		}

		// Member variables
		m_parentFolder.first = MON::Folder();
		m_parentFolder.second = NULL;

		// Events
		m_pProject->onObjectRetrieved( this );
	}

	ObjectImpl* ObjectImpl::find( ProjectImpl* pProject, IMgaObject* spObject )
	{
		return _getProject( spObject, pProject )->findByCOMI( spObject );
	}

	ObjectImpl* ObjectImpl::attachI( IMgaObject* spObject, ProjectImpl* pProject, const MON::Object& meta )
	{
		// Find out the appropriate Implementation
		CComQIPtr<IMgaFolder> spFolder = spObject;
		if ( spFolder )
			return FolderImpl::attachI( spFolder, pProject, meta );
		CComQIPtr<IMgaFCO> spFCO = spObject;
		if ( spFCO )
			return FCOImpl::attachI( spFCO, pProject, meta );
		ASSERTTHROW( Util::Exception( "Unprocessed Object Type!" ) );
	}

	Object ObjectImpl::attach( IMgaObject* spObject )
	{
		return attachI( spObject );
	}

	ObjectImpl::~ObjectImpl()
	{
		m_bIsDestructionActive = true;

		if ( ! m_pProject->isDestructionActive() && ! isDeleted() ) {
			if ( m_parentFolder.second )
				m_parentFolder.second->onReleasedAsObjectParent( this, true );
			m_pProject->onObjectReleased( this, true );
		}

		for ( RegistryMap::iterator it = m_mapNodes.begin() ; it != m_mapNodes.end() ; it++ )
			delete it->second;

		m_mapNodes.clear();
		m_parentFolder.first = MON::Folder();
		m_parentFolder.second = NULL;
		m_meta = MON::Object();
		m_pProject = NULL;
		m_spObject = NULL;
	}

	bool ObjectImpl::setDeleted()
	{
		{	using namespace Util; if ( GenRefCounted::setDeleted() ) return true; 	}
		finalize();

		if ( m_parentFolder.second )
			m_parentFolder.second->onReleasedAsObjectParent( this, false );
		m_pProject->onObjectReleased( this, false );

		for ( RegistryMap::iterator it = m_mapNodes.begin() ; it != m_mapNodes.end() ; it++ )
			it->second->setDeleted();
		return false;
	}

	void ObjectImpl::destroy()
	{
		// CHANGED LINE BEGIN
		if ( isInLibrary() )
		{
			BON::Exception exc( "? belongs to a library, thus it cannot be destroyed!");//, "s", 
			exc << getInfoString().c_str();
			ASSERTTHROW( exc );
		}
		// CHANGED LINE END
		if ( ! _isAddOn() )
			setDeleted();
		COMTHROW( getObjectI()->DestroyObject() );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
	}

//===============================================================================================================================================
// 	C L A S S : BON::ObjectImpl					// Get and Set operations // ---> Interface Methods

	bool ObjectImpl::isDestructionActive() const
	{
		return m_bIsDestructionActive;
	}

	Project ObjectImpl::getProject() const
	{
		return m_pProject;
	}

	ObjectPtr ObjectImpl::getObjectI() const
	{
		return m_spObject;
	}

	const MON::Object& ObjectImpl::getObjectMeta() const
	{
		return m_meta;
	}

	std::string ObjectImpl::getID() const
	{
		CComBSTR bstrID;
		COMTHROW( m_spObject->get_ID( &bstrID ) );
		return Util::Copy( bstrID );
	}

	ObjectStatus ObjectImpl::getStatus() const
	{
		long lStatus;
		COMTHROW( m_spObject->get_Status( &lStatus ) );
		switch ( lStatus ) {
			case OBJECT_EXISTS :
				return OST_Exists;
			case OBJECT_ZOMBIE :
				return OST_Zombie;
			case OBJECT_DELETED :
				return OST_Deleted;
			default :
				ASSERTTHROW( Util::Exception( "Unprocessed Object Status!" ) );
		}
	}

	bool ObjectImpl::isReadOnly() const
	{
		VARIANT_BOOL vbWritable;
		COMTHROW( m_spObject->get_IsWritable( &vbWritable ) );
		return ( vbWritable ) ? false : true;
	}

	bool ObjectImpl::isInLibrary() const
	{
		VARIANT_BOOL vbLibrary;
		COMTHROW( m_spObject->get_IsLibObject( &vbLibrary ) );
		return ( vbLibrary ) ? true : false;
	}

	std::string ObjectImpl::getName() const
	{
		CComBSTR bstrName;
		COMTHROW( m_spObject->get_Name( &bstrName ) );
		return Util::Copy( bstrName );
	}

	void ObjectImpl::setName( const std::string& strName )
	{
		COMTHROW( m_spObject->put_Name( Util::Copy( strName ) ) );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
	}

	std::string ObjectImpl::getPath( const std::string& strDelimiter, bool bReverseOrder, bool bNeedRootFolder ) const
	{
		Object p = ( (ObjectImpl*) this)->getParent();
		if ( ! p ) {
			if ( bNeedRootFolder )
				return ( bReverseOrder ) ? getName() + strDelimiter : strDelimiter + getName();
			return "";
		}

		return ( bReverseOrder ) ? getName() + strDelimiter + p->getPath( strDelimiter, true, bNeedRootFolder ) : p->getPath( strDelimiter, false, bNeedRootFolder ) + strDelimiter + getName();
	}

	std::string ObjectImpl::getInfoString( const std::set<Util::InfoOption>& setOptions ) const
	{
		return getInfoString( copy( setOptions ) );
	}

	std::string ObjectImpl::getInfoStringHelper( unsigned short usOptions, const std::string& strStereo ) const
	{
		bool bAll = ( usOptions & Util::IO_All ) ? true : false;
		bool bIdent = bAll || ( usOptions & Util::IO_Identifiers );
		bool bLine = bAll || ( usOptions & Util::IO_NewLine );
		std::string strDelim = ( bLine ) ? "\n" : ", ";

		std::string strInfo( "BON::" + strStereo );
		strInfo += ( bLine ) ? " :\n" : " [";

		if ( bIdent )
			strInfo += "name: ";
		strInfo += getName();

		if ( ( usOptions & Util::IO_ID ) || bAll ) {
			strInfo += strDelim;
			if ( bIdent )
				strInfo += "id: ";
			strInfo += getID();
		}

		if ( ( usOptions & Util::IO_Path ) || bAll ) {
			strInfo += strDelim;
			if ( bIdent )
				strInfo += "path: ";
			strInfo += getPath();
		}

		if ( ( usOptions & Util::IO_Meta ) || bAll ) {
			strInfo += strDelim;
			if ( bIdent )
				strInfo += "meta: ";
			strInfo += getObjectMeta().infoString( bIdent, ( usOptions & Util::IO_ID ) ? true : false );
		}

		return strInfo;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ObjectImpl					// Relations

	FolderImpl* ObjectImpl::getParentFolderI( const MON::Folder& meta )
	{
		// CHANGED LINE BEGIN
		if ( getObjectMeta().name() == "RootFolder" ) {
			m_bAllParentFolders = true;
			return NULL;
		}
		// CHANGED LINE END

		// Check if Parent was already retrieved
		if ( m_parentFolder.first )
			return ( ! meta || meta == m_parentFolder.first ) ? m_parentFolder.second : NULL;
		if ( m_bAllParentFolders )
			return NULL;

		// Retrieve
		ObjectPtr spObject;
		COMTHROW( getObjectI()->GetParent( spObject.Addr() ) );
		CComQIPtr<IMgaFolder> spFolder = spObject;

		// It is not a Folder
		if ( ! spFolder ) {
			m_bAllParentFolders = true;
			return NULL;
		}

		// It is a Folder
		if ( ! meta || _getMetaRef( spFolder ) == meta.ref() ) {
			m_parentFolder.first = ( meta ) ? meta : MON::Folder( m_pProject->getProjectMeta().findByName( _getMetaName( spFolder ) ) );
			m_parentFolder.second = FolderImpl::attachI( spFolder, m_pProject, m_parentFolder.first );
			m_parentFolder.second->onRetrievedAsObjectParent( this, false );
			if ( ! meta )
				m_bAllParentFolders = true;
		}
		return m_parentFolder.second;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ObjectImpl					// Event Handlers

	bool ObjectImpl::onRetrievedAsFolderChild( FolderImpl* pFolder, bool bCheckAll )
	{
		m_bAllParentFolders = true;
		m_parentFolder.first = pFolder->getFolderMeta();
		m_parentFolder.second = pFolder;
		return true;
	}

	void ObjectImpl::onReleasedAsFolderChild( FolderImpl* pFolder, bool bOnlyFreeMemory )
	{
		m_bAllParentFolders = false;
		m_parentFolder.first = MON::Folder();
		m_parentFolder.second = NULL;
	}

	void ObjectImpl::eventPerformedI( const Event& event )
	{
		switch ( event.getType() ) {
			case MON::OET_ObjectCreated :
				onObjectCreated();
				break;
			case MON::OET_ObjectDestroyed :
				setDeleted();
				break;
			case MON::OET_ObjectMoved :
				onObjectMoved( NULL, NULL );
				break;
			case MON::OET_RegistryChanged :
				onRegistryChanged();
				break;
		}
	}

	void ObjectImpl::onObjectCreated()
	{
		// Temporary Solution ... Eliminate If Event Paremeters Available
		ObjectPtr spObject;
		COMTHROW( m_spObject->GetParent( spObject.Addr() ) );
		Folder folder( ObjectImpl::attachI( spObject, m_pProject ) );
		if ( folder )
			folder->onChildAdded( this );
		// Temporary Solution END
	}

	void ObjectImpl::onObjectMoved( ObjectImpl* pOldParent, ObjectImpl* pNewParent )
	{
		if ( pOldParent && pNewParent ) {
			if ( pOldParent->getStereotype() == OT_Folder )
				dynamic_cast<FolderImpl*>( pOldParent )->onChildRemoved( this );
			if ( pNewParent->getStereotype() == OT_Folder )
				dynamic_cast<FolderImpl*>( pNewParent )->onChildAdded( this );
			return;
		}

		// Temporary Solution ... Eliminate If Event Paremeters Available
		if ( m_parentFolder.second )
			m_parentFolder.second->onChildRemoved( this );
		ObjectPtr spObject;
		COMTHROW( m_spObject->GetParent( spObject.Addr() ) );
		Folder folder( ObjectImpl::attachI( spObject, m_pProject ) );
		if ( folder )
			folder->onChildAdded( this );
		// Temporary Solution END
	}

	void ObjectImpl::onRegistryChanged()
	{
		for ( RegistryMap::iterator it = m_mapNodes.begin() ; it != m_mapNodes.end() ; it++ )
			it->second->setDeleted();
	}

//===============================================================================================================================================
// 	C L A S S : BON::ObjectImpl					// Relations // ---> Interface Methods

	RegistryNode ObjectImpl::getRegistry() const
	{
		return RegistryNodeImpl::attachI( NULL, (ObjectImpl*) this );
	}

	Object ObjectImpl::getParent()
	{
		return getParentFolder();
	}

	Folder ObjectImpl::getParentFolder( const MON::Folder& meta )
	{
		if ( ! meta )
			return getParentFolderI();

		THROW_METAPROJECT_BELONG( meta );
		if ( ! getObjectMeta().isFolderParent( meta ) )
		{
			MON::Exception exc( "? cannot be parent of ?!");
			exc << meta.infoString() << getObjectMeta().infoString();
			ASSERTTHROW( exc );
		}

		return getParentFolderI( meta );
	}

	Folder ObjectImpl::getParentFolder( const std::string& strFolder )
	{
		if ( strFolder.empty() )
			return getParentFolder();

		MON::Folder meta( getProject()->getProjectMeta().findByName( strFolder ) );
		THROW_METAPROJECT_DOES_NOT_HAVE( meta, Folder, strFolder );
		if ( ! getObjectMeta().isFolderParent( meta ) )
		{
			MON::Exception exc( "? cannot be parent of ?!");
			exc << meta.infoString() << getObjectMeta().infoString();
			ASSERTTHROW( exc );
		}

		return getParentFolder( meta );
	}

//===============================================================================================================================================
// 	C L A S S : BON::ObjectImpl					// Extensions

	void ObjectImpl::accept( Visitor* pVisitor )
	{
		if ( getStereotype() == OT_Folder )
			( (FolderImpl*) this)->accept( pVisitor );
		else
			( (FCOImpl*) this)->accept( pVisitor );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::RegistryNodeImpl
//
//###############################################################################################################################################

	RegistryNodeImpl::RegistryNodeImpl( IMgaRegNode* spNode, ObjectImpl* pObject )
		: Util::GenRefCounted( _isAddOn(), pObject ), m_spNode( spNode ), m_pObject( pObject )
	{
		pObject->m_mapNodes.insert( ObjectImpl::RegistryMap::value_type( spNode, this ) );
	}

	RegistryNodeImpl* RegistryNodeImpl::attachI( IMgaRegNode* spNode, ObjectImpl* pObject )
	{
		if ( spNode )
			return new RegistryNodeImpl( spNode, pObject );
		switch ( pObject->getStereotype() ) {
			case OT_Folder : return new RegistryNodeImpl( NULL, pObject );
			case OT_Model : return new ModelRegistryNodeImpl( dynamic_cast<ModelImpl*>( pObject ) );
			case OT_Connection : return new ConnectionRegistryNodeImpl( dynamic_cast<ConnectionImpl*>( pObject ) );
			default : return new FCOExRegistryNodeImpl( (FCOImpl*) pObject );
		}
	}

	RegistryNodeImpl::~RegistryNodeImpl()
	{
		if ( ! m_pObject->isDestructionActive() && ! isDeleted() )
			m_pObject->m_mapNodes.erase( getRegNodeI() );

		m_pObject = NULL;
		m_spNode = NULL;
	}

	bool RegistryNodeImpl::setDeleted()
	{
		{	using namespace Util; if ( GenRefCounted::setDeleted() ) return true;	}

		m_pObject->m_mapNodes.erase( getRegNodeI() );
		return false;
	}

//===============================================================================================================================================
// 	C L A S S : BON::RegistryNodeImpl					// Get and Set operations // ---> Interface Methods

	Project RegistryNodeImpl::getProject() const
	{
		return m_pObject->getProject();
	}

	Object RegistryNodeImpl::getObject() const
	{
		return m_pObject;
	}

	RegNodePtr RegistryNodeImpl::getRegNodeI() const
	{
		return m_spNode;
	}

	bool RegistryNodeImpl::isRootNode() const
	{
		return ( m_spNode ) ? false : true;
	}

	std::string RegistryNodeImpl::getName() const
	{
		if ( m_spNode ) { // modified by ZolMol
			CComBSTR bstrName;
			COMTHROW( m_spNode->get_Name( &bstrName ) );
			return Util::Copy( bstrName );
		}
		return "";
	}

	std::string RegistryNodeImpl::getPath() const
	{
		if ( m_spNode ) {
			CComBSTR bstrName;
			COMTHROW( m_spNode->get_Path( &bstrName ) );
			return "/" + Util::Copy( bstrName );
		}
		return "/";
	}

	RegistryNodeStatus RegistryNodeImpl::getStatus() const
	{
		if ( m_spNode ) {
			long lStatus;
			COMTHROW( m_spNode->get_Status( &lStatus ) );
			return lStatus;
		}
		return RNS_Undefined;
	}

	std::string RegistryNodeImpl::getValue() const
	{
		if ( m_spNode ) {
			CComBSTR bstrValue;
			COMTHROW( m_spNode->get_Value( &bstrValue ) );
			return Util::Copy( bstrValue );
		}
		return "";
	}

	void RegistryNodeImpl::setValue( const std::string& strValue )
	{
		if ( m_spNode ) {
			COMTHROW( m_spNode->put_Value( Util::Copy( strValue ) ) );
			if ( getProject()->isAutoCommit() )
				getProject()->commit();
		}
	}

	long RegistryNodeImpl::getIntegerValue() const
	{
		return (long) Util::Variant( getValue() );
	}

	void RegistryNodeImpl::setIntegerValue( long lValue )
	{
		setValue( (std::string) Util::Variant( lValue ) );
	}

	double	RegistryNodeImpl::getRealValue() const
	{
		return (double) Util::Variant( getValue() );
	}

	void RegistryNodeImpl::setRealValue( double dValue )
	{
		setValue( (std::string) Util::Variant( dValue ) );
	}

	bool RegistryNodeImpl::getBoolValue() const
	{
		return (bool) Util::Variant( getValue() );
	}

	void RegistryNodeImpl::setBoolValue( bool bValue )
	{
		setValue( (std::string) Util::Variant( bValue ) );
	}

	void RegistryNodeImpl::clear()
	{
		if ( m_spNode ) {
			COMTHROW( m_spNode->Clear() );
		}
	}

	std::string	RegistryNodeImpl::getValueByPath( const std::string& strPath ) const
	{
		std::string strPath2 = getPath().substr( 1 ) + strPath;
		if ( ! m_spNode )
			strPath2 = strPath2.substr( 1 );

		CComBSTR bstrValue;
		CComQIPtr<IMgaFCO> spFCO = m_pObject->getObjectI();
		if ( spFCO ) {
			COMTHROW( spFCO->get_RegistryValue( Util::Copy( strPath2 ), &bstrValue ) );
		}
		else {
			CComQIPtr<IMgaFolder> spFolder = m_pObject->getObjectI();
			COMTHROW( spFolder->get_RegistryValue( Util::Copy( strPath2 ), &bstrValue ) );
		}

		return Util::Copy( bstrValue );
	}

	void RegistryNodeImpl::setValueByPath( const std::string& strPath, const std::string& strValue )
	{
		std::string strPath2 = getPath().substr( 1 ) + strPath;
		if ( ! m_spNode )
			strPath2 = strPath2.substr( 1 );

		CComQIPtr<IMgaFCO> spFCO = m_pObject->getObjectI();
		if ( spFCO ) {
			COMTHROW( spFCO->put_RegistryValue( Util::Copy( strPath2 ), Util::Copy( strValue ) ) );
		}
		else {
			CComQIPtr<IMgaFolder> spFolder = m_pObject->getObjectI();
			COMTHROW( spFolder->put_RegistryValue( Util::Copy( strPath2 ), Util::Copy( strValue ) ) );
		}
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
	}

//===============================================================================================================================================
// 	C L A S S : BON::RegistryNodeImpl					// Relations // ---> Interface Methods

	RegistryNode RegistryNodeImpl::getParent() const
	{
		if ( m_spNode ) {
			RegNodePtr spNode;
			COMTHROW( m_spNode->get_ParentNode( spNode.Addr() ) );
			return attachI( spNode, m_pObject );
		}
		return NULL;
	}

	std::set<RegistryNode> RegistryNodeImpl::getChildren( bool bVirtualsAlso ) const
	{
		std::set<RegistryNode> setNodes;
		Util::ComPtr<IMgaRegNodes> spNodes;

		if ( m_spNode ) {
			COMTHROW( m_spNode->get_SubNodes( ( bVirtualsAlso ) ? VARIANT_TRUE : VARIANT_FALSE, spNodes.Addr() ) );
		}
		else {
			CComQIPtr<IMgaFCO> spFCO = m_pObject->getObjectI();
			if ( spFCO ) {
				COMTHROW( spFCO->get_Registry( ( bVirtualsAlso ) ? VARIANT_TRUE : VARIANT_FALSE, spNodes.Addr() ) );
			}
			else {
				CComQIPtr<IMgaFolder> spFolder = m_pObject->getObjectI();
				COMTHROW( spFolder->get_Registry( ( bVirtualsAlso ) ? VARIANT_TRUE : VARIANT_FALSE, spNodes.Addr() ) );
			}
		}

		if ( spNodes ) {
			MGACOLL_ITERATE( IMgaRegNode, spNodes.p ) {
				setNodes.insert( attachI( MGACOLL_ITER, m_pObject ) );
			} MGACOLL_ITERATE_END;
		}
		return setNodes;
	}

	RegistryNode RegistryNodeImpl::getChild( const std::string& strName ) const
	{
		RegNodePtr spNode;
		if ( m_spNode ) {
			COMTHROW( m_spNode->get_SubNodeByName( Util::Copy( strName ), spNode.Addr() ) );
		}
		else {
			CComQIPtr<IMgaFCO> spFCO = m_pObject->getObjectI();
			if ( spFCO ) {
				COMTHROW( spFCO->get_RegistryNode( Util::Copy( strName ), spNode.Addr() ) );
			}
			else {
				CComQIPtr<IMgaFolder> spFolder = m_pObject->getObjectI();
				COMTHROW( spFolder->get_RegistryNode( Util::Copy( strName ), spNode.Addr() ) );
			}
		}
		return ( spNode ) ? attachI( spNode, m_pObject ) : NULL;
	}

	void RegistryNodeImpl::removeTree()
	{
		if ( m_spNode ) {
			COMTHROW( m_spNode->RemoveTree() );
			return;
		}

		Util::ComPtr<IMgaRegNodes> spNodes;
		CComQIPtr<IMgaFCO> spFCO = m_pObject->getObjectI();
		if ( spFCO ) {
			COMTHROW( spFCO->get_Registry( VARIANT_FALSE, spNodes.Addr() ) );
		}
		else {
			CComQIPtr<IMgaFolder> spFolder = m_pObject->getObjectI();
			COMTHROW( spFolder->get_Registry( VARIANT_FALSE, spNodes.Addr() ) );
		}

		if ( spNodes ) {
			MGACOLL_ITERATE( IMgaRegNode, spNodes.p ) {
				COMTHROW( MGACOLL_ITER->RemoveTree() );
			} MGACOLL_ITERATE_END;
		}
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
	}

	RegistryNode RegistryNodeImpl::getDescendantByPath( const std::string& strPath ) const
	{
		std::string strPath2 = strPath;
		if ( m_spNode )
			strPath2 = getPath().substr( 1 ) + strPath;

		RegNodePtr spNode;
		CComQIPtr<IMgaFCO> spFCO = m_pObject->getObjectI();
		if ( spFCO ) {
			COMTHROW( spFCO->get_RegistryNode( Util::Copy( strPath2 ), spNode.Addr() ) );
		}
		else {
			CComQIPtr<IMgaFolder> spFolder = m_pObject->getObjectI();
			COMTHROW( spFolder->get_RegistryNode( Util::Copy( strPath2 ), spNode.Addr() ) );
		}

		return ( spNode ) ? attachI( spNode, m_pObject ) : NULL;
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::FolderImpl
//
//###############################################################################################################################################

	FolderImpl::FolderImpl()
		: ObjectImpl(), m_bAllChildObjects( false )
	{
	}

	FolderImpl* FolderImpl::attachI( IMgaFolder* spFolder, ProjectImpl* pProject, const MON::Object& meta )
	{
		// Warning : Maybe it is an Exception
		if ( ! spFolder )
			return NULL;

		// Find it in Objects' cache
		pProject = _getProject( spFolder, pProject );
		ObjectImpl* pObject = find( pProject, spFolder );
		if ( pObject )
			return (FolderImpl*) pObject;

		// Get Extension
		pObject = getEx( spFolder, OT_Folder, meta );
		if ( ! pObject )
			pObject = new FolderImpl();
		pObject->doInitialize( spFolder, pProject, meta );
		pObject->initialize();
		return (FolderImpl*) pObject;
	}

	FolderImpl::~FolderImpl()
	{
		if ( ! m_pProject->isDestructionActive() && ! isDeleted() ) {
			for ( ManyObjectLink::iterator it1 = m_childObjects.begin() ; it1 != m_childObjects.end() ; it1++ )
				for ( ObjectSet::iterator it2 = it1->second.second.begin() ; it2 != it1->second.second.end() ; it2++ )
						(*it2)->onReleasedAsFolderChild( this, true );
		}
		m_childObjects.clear();
	}

	bool FolderImpl::setDeleted()
	{
		if ( ObjectImpl::setDeleted() )
			return true;
		if ( ! _isAddOn() ) {
			for ( ManyObjectLink::iterator it1 = m_childObjects.begin() ; it1 != m_childObjects.end() ; it1++ )
				for ( ObjectSet::iterator it2 = it1->second.second.begin() ; it2 != it1->second.second.end() ; it2++ )
					(*it2)->setDeleted();
		}
		return false;
	}

	Folder FolderImpl::attach( IMgaFolder* spFolder )
	{
		return attachI( spFolder );
	}

	Folder FolderImpl::create( const Folder& parent, const MON::Folder& meta )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		return parent->createChildObjectI( meta, MON::OT_Folder );
	}

	Folder FolderImpl::create( const Folder& parent, const std::string& strFolder )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		MON::Folder meta;
		if ( ! strFolder.empty() ) {
			meta = parent->getProject()->getProjectMeta().findByName( strFolder );
			if ( ! meta )
			{
				MON::Exception exc( "MON::Folder [ ? ] does not exist in ? of ?!");//, "sss", 
				exc << strFolder.c_str() << parent->getProject()->getProjectMeta().infoString().c_str() << parent->getProject()->getInfoString().c_str(); 
				ASSERTTHROW( exc);
			}
		}
		return create( parent, meta );
	}

//===============================================================================================================================================
// 	C L A S S : BON::FolderImpl					// Get and Set Operations // ---> Interface Methods

	ObjectType FolderImpl::getStereotype() const
	{
		return OT_Folder;
	}

	FolderPtr FolderImpl::getFolderI() const
	{
		CComQIPtr<IMgaFolder> spFolder = getObjectI().p;
		return spFolder.p;
	}

	MON::Folder FolderImpl::getFolderMeta() const
	{
		return getObjectMeta();
	}

	std::string FolderImpl::getInfoString( unsigned short usOptions ) const
	{
		bool bAll = ( usOptions & Util::IO_All ) ? true : false;
		bool bLine = bAll || ( usOptions & Util::IO_NewLine );

		std::string strInfo = getInfoStringHelper( usOptions, "Folder" );
		if ( ! ( usOptions & Util::IO_NewLine ) && ! ( usOptions & Util::IO_All ) )
			strInfo += "]";

		return strInfo;
	}

//===============================================================================================================================================
// 	C L A S S : BON::FolderImpl					// Relations

	bool FolderImpl::isChildObjectsRetrieved( const MON::Object& meta )
	{
		ManyObjectLink::iterator it = m_childObjects.find( meta );
		if ( it != m_childObjects.end() ) {
			if ( it->second.first )
				return true;
			it->second.first = true;
			return false;
		}
		m_childObjects[ meta ] = ObjectSetPair( true, ObjectSet() );
		return false;
	}

	void FolderImpl::getChildFolders( std::set<ObjectPtr>& setSPFolders )
	{
		Util::ComPtr<IMgaFolders> spFolders;
		COMTHROW( getFolderI()->get_ChildFolders( spFolders.Addr() ) );
		MGACOLL_ITERATE( IMgaFolder, spFolders.p ) {
			setSPFolders.insert( MGACOLL_ITER.p );
		} MGACOLL_ITERATE_END;
	}

	void FolderImpl::getRootFCOs( std::set<ObjectPtr>& setSPFCOs )
	{
		Util::ComPtr<IMgaFCOs> spFCOs;
		COMTHROW( getFolderI()->get_ChildFCOs( spFCOs.Addr() ) );
		MGACOLL_ITERATE( IMgaFCO, spFCOs.p ) {
			setSPFCOs.insert( MGACOLL_ITER.p );
		} MGACOLL_ITERATE_END;
	}

	void FolderImpl::getChildObjects( const MON::Object& meta, std::set<ObjectPtr>& setSPObjects, bool bErase )
	{
		std::set<ObjectPtr>::iterator it = setSPObjects.begin();
		while ( it != setSPObjects.end() ) {
			std::set<ObjectPtr>::iterator itSaved = it;
			it++;
			if ( _getMetaRef( *itSaved ) == meta.ref() ) {
				ObjectImpl* pObject = ObjectImpl::attachI( *itSaved, m_pProject, meta );
				if ( m_childObjects[ meta ].second.find( pObject ) == m_childObjects[ meta ].second.end() ) {
					m_childObjects[ meta ].second.insert( pObject );
					pObject->onRetrievedAsFolderChild( this, false );
				}
				if ( bErase )
					setSPObjects.erase( itSaved );
			}
		}
	}

	ObjectSet FolderImpl::getChildObjectsI( const MON::Object& meta )
	{
		if ( meta ) {
			if ( ! isChildObjectsRetrieved( meta ) ) {
				std::set<ObjectPtr> setSPObjects;
				if ( meta.type() == OT_Folder )
					getChildFolders( setSPObjects);
				else
					getRootFCOs( setSPObjects );
				getChildObjects( meta, setSPObjects, false );
			}
			return m_childObjects[ meta ].second;
		}

		if ( ! m_bAllChildObjects ) {
			m_bAllChildObjects = true;
			std::set<ObjectPtr> setSPFolders;
			getChildFolders( setSPFolders );
			std::set<ObjectPtr> setSPFCOs;
			getRootFCOs( setSPFCOs );
			std::set<MON::Object> setMetas = getFolderMeta().childObjects();
			for ( std::set<MON::Object>::iterator it = setMetas.begin() ; it != setMetas.end() ; it++ ) {
				if ( ! isChildObjectsRetrieved( *it ) )
					getChildObjects( *it, ( it->type() == OT_Folder ) ? setSPFolders : setSPFCOs, true );
			}
		}

		ObjectSet setObjects;
		for ( ManyObjectLink::iterator it = m_childObjects.begin() ; it != m_childObjects.end() ; it++ )
			setObjects.insert( it->second.second.begin(), it->second.second.end() );
		return setObjects;
	}

	ObjectImpl* FolderImpl::createChildObjectI( const MON::Object& meta, MON::ObjectType eType )
	{
		MON::Object objectMeta;
		if ( ! meta ) {
			std::set<MON::Object> metas = getFolderMeta().childObjects();
			for ( std::set<MON::Object>::iterator it = metas.begin() ; it != metas.end() ; it++ ) {
				if ( it->type() == eType ) {
					if ( objectMeta )
					{
						MON::Exception exc( "? cannot be null because ? can contain more than one ? as child!");//, "sss", 
						exc << toString( eType ).c_str() << getObjectMeta().infoString().c_str() << toString( eType ).c_str();
						ASSERTTHROW( exc);
					}
					objectMeta = *it;
				}
			}
			if ( ! objectMeta )
			{
				MON::Exception exc( "? does not have ? as child!");//, "ss", 
				exc << getObjectMeta().infoString().c_str() << toString( eType ).c_str();
				ASSERTTHROW( exc);
			}
		}
		else {
			THROW_METAPROJECT_BELONG( meta );
			if ( ! getFolderMeta().isObjectChild( meta ) )
			{
				MON::Exception exc( "? does not have ? as child!");//, "ss", 
				exc << getObjectMeta().infoString().c_str() << meta.infoString().c_str();
				ASSERTTHROW( exc);
			}
			objectMeta = meta;
		}

		if ( eType == MON::OT_Folder ) {
			FolderPtr spFolder;
			COMTHROW( getFolderI()->CreateFolder( MON::Folder( objectMeta ).getFolderI(), spFolder.Addr() ) );
			FolderImpl* pFolder = FolderImpl::attachI( spFolder, (ProjectImpl*) getProject().getCounted(), objectMeta );
			if ( ! _isAddOn() )
				pFolder->eventPerformedI( Event( MON::OET_ObjectCreated, pFolder ) );
			return pFolder;
		}
		FCOPtr spFCO;
		COMTHROW( getFolderI()->CreateRootObject( MON::FCO( objectMeta ).getFCOI(), spFCO.Addr() ) );
		FCOImpl* pFCO = FCOImpl::attachI( spFCO, (ProjectImpl*) getProject().getCounted(), objectMeta );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
		if ( ! _isAddOn() )
			pFCO->eventPerformedI( Event( MON::OET_ObjectCreated, pFCO ) );
		return pFCO;

	}

	FCOImpl* FolderImpl::createChildFCOI( const FCO& fco, bool bAsInstance, MON::ObjectType eType )
	{
		THROW_CANNOT_BE_NULL( fco, "MON::" + toString( eType, false ) );
		THROW_PROJECT_BELONG( fco );
		if ( ! getFolderMeta().isObjectChild( fco->getObjectMeta() ) )
		{
			MON::Exception exc( "? does not have ? as child!");
			exc << getObjectMeta().infoString() << fco->getObjectMeta().infoString();
			ASSERTTHROW( exc);
		}

		FCOPtr spFCO;
		COMTHROW( getFolderI()->DeriveRootObject( fco->getFCOI(), ( bAsInstance ) ? VARIANT_TRUE : VARIANT_FALSE, spFCO.Addr() ) );
		FCOImpl* pFCO = FCOImpl::attachI( spFCO, (ProjectImpl*) getProject().getCounted(), fco->getFCOMeta() );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
		if ( ! _isAddOn() ) {
			pFCO->eventPerformedI( Event( MON::OET_ObjectCreated, pFCO ) );
			fco->eventPerformedI( Event( MON::OET_DescendantCreated, fco ) );
		}
		return pFCO;
	}

//===============================================================================================================================================
// 	C L A S S : BON::FolderImpl					// Event Handlers

	bool FolderImpl::onRetrievedAsObjectParent( ObjectImpl* pObject, bool bCheckAll )
	{
		ManyObjectLink::iterator it = m_childObjects.find( pObject->getObjectMeta() );
		if ( it == m_childObjects.end() ) {
			if ( bCheckAll )
				return false;
			m_childObjects[ pObject->getObjectMeta() ] = ObjectSetPair( false, ObjectSet() );
		}
		if ( ! bCheckAll || bCheckAll && m_childObjects[ pObject->getObjectMeta() ].first ) {
			m_childObjects[ pObject->getObjectMeta() ].second.insert( pObject );
			return true;
		}
		return false;
	}

	void FolderImpl::onReleasedAsObjectParent( ObjectImpl* pObject, bool bOnlyMemoryFree )
	{
		ManyObjectLink::iterator it = m_childObjects.find( pObject->getObjectMeta() );
		if ( it != m_childObjects.end() ) {
			m_childObjects[ pObject->getObjectMeta() ].second.erase( pObject );
			if ( bOnlyMemoryFree && m_childObjects[ pObject->getObjectMeta() ].first ) {
				m_childObjects[ pObject->getObjectMeta() ].first = false;
				m_bAllChildObjects = false;
			}
		}
	}

	void FolderImpl::eventPerformedI( const Event& event )
	{
		ObjectImpl::eventPerformedI( event );
		switch ( event.getType() ) {
			case MON::OET_ChildAdded :
				onChildAdded( NULL );
				break;
			case MON::OET_ChildLost :
				onChildRemoved( NULL );
				break;
		}
	}

	void FolderImpl::onChildAdded( ObjectImpl* pChild )
	{
		if ( pChild ) {
			if ( onRetrievedAsObjectParent( pChild, true ) )
				pChild->onRetrievedAsFolderChild( this, false );
		}
	}

	void FolderImpl::onChildRemoved( ObjectImpl* pChild )
	{
		if ( pChild ) {
			onReleasedAsObjectParent( pChild, false );
			pChild->onReleasedAsFolderChild( this, false );
		}
	}

//===============================================================================================================================================
// 	C L A S S : BON::FolderImpl					// Relations // ---> Interface Methods

	std::set<Object> FolderImpl::getChildObjects( const MON::Object& meta )
	{
		if ( meta ) {
			THROW_METAPROJECT_BELONG( meta );
			if ( meta.type() < MON::OT_Model || meta.type() > MON::OT_Folder )
			{
				Exception exc( "Type of ? can be only MON::Folder or MON::FCO!");
				exc << meta.infoString().c_str();
				ASSERTTHROW( exc);
			}
			if ( ! getFolderMeta().isObjectChild( meta ) )
			{
				MON::Exception exc( "? cannot be child of ?!");//, "ss", 
				exc << meta.infoString().c_str() << getObjectMeta().infoString().c_str();
				ASSERTTHROW( exc);
			}
		}

		std::set<Object> setResult;
		setCopy<Object,ObjectImpl>( getChildObjectsI( meta ), setResult );
		return setResult;
	}

	std::set<Object> FolderImpl::getChildObjects( const std::string& strObject )
	{
		MON::Object meta;
		if ( ! strObject.empty() ) {
			meta = getProject()->getProjectMeta().findByName( strObject );
			if ( ! meta || meta.type() < MON::OT_Model || meta.type() > MON::OT_Folder )
			{
				MON::Exception exc( "MON::Folder or MON::FCO [ ? ] does not exist in ? of ?!");//, "sss", 
				exc << strObject.c_str() << getProject()->getProjectMeta().infoString().c_str() << getProject()->getInfoString().c_str();
				ASSERTTHROW( exc);
			}
		}
		return getChildObjects( meta );
	}

	std::set<Folder> FolderImpl::getChildFolders()
	{
		std::set<Folder> setResult;
		std::set<MON::Folder> set = getFolderMeta().childFolders();
		for ( std::set<MON::Folder>::iterator it = set.begin() ; it != set.end() ; ++it )
			setCastCopy<Folder,ObjectImpl,FolderImpl>( getChildObjectsI( *it ), setResult );
		return setResult;
	}

	std::set<FCO> FolderImpl::getRootFCOs()
	{
		std::set<FCO> setResult;
		std::set<MON::FCO> set = getFolderMeta().childFCOs();
		for ( std::set<MON::FCO>::iterator it = set.begin() ; it != set.end() ; ++it )
			setCastCopy<FCO,ObjectImpl,FCOImpl>( getChildObjectsI( *it ), setResult );
		return setResult;
	}

	std::set<Atom> FolderImpl::getChildAtoms()
	{
		std::set<Atom> setResult;
		std::set<MON::Atom> set = getFolderMeta().childAtoms();
		for ( std::set<MON::Atom>::iterator it = set.begin() ; it != set.end() ; ++it )
			setCastCopy<Atom,ObjectImpl,AtomImpl>( getChildObjectsI( *it ), setResult );
		return setResult;
	}

	std::set<Model> FolderImpl::getChildModels()
	{
		std::set<Model> setResult;
		std::set<MON::Model> set = getFolderMeta().childModels();
		for ( std::set<MON::Model>::iterator it = set.begin() ; it != set.end() ; ++it )
			setCastCopy<Model,ObjectImpl,ModelImpl>( getChildObjectsI( *it ), setResult );
		return setResult;
	}

	Object FolderImpl::findByPath( const std::string& strPath, const std::string& strDelimiter, bool bReverseOrder )
	{
		std::string strPath2;
		std::string strName;
		int iPos = ( bReverseOrder ) ? strPath.rfind( strDelimiter ) : strPath.find( strDelimiter );
		if ( iPos == std::string::npos ) {
			strName = strPath;
			strPath2 = "";
		}
		else {
			if ( bReverseOrder && iPos + strDelimiter.length() == strPath.length() )
				strPath2 = strPath.substr( 0, iPos );
			if ( ! bReverseOrder && iPos == 0 )
				strPath2 = strPath.substr( iPos + strDelimiter.length() );
			iPos = ( bReverseOrder ) ? strPath2.rfind( strDelimiter ) : strPath2.find( strDelimiter );
			if ( iPos == std::string::npos ) {
				strName = strPath2;
				strPath2 = "";
			}
			else {
				strName = ( bReverseOrder ) ? strPath2.substr( iPos ) : strPath2.substr( 0, iPos );
				strPath2 = ( bReverseOrder ) ? strPath2.substr( 0, iPos ) : strPath2.substr( iPos );
			}
		}

		std::set<Object> objects = getChildObjects();
		for ( std::set<Object>::iterator it = objects.begin() ; it != objects.end() ; it++ )
			if ( strName == (*it)->getName() ) {
				if ( strPath2.empty() )
					return *it;
				else {
					if ( (*it)->getStereotype() == OT_Model ) {
						FCO o = Model( *it )->findByPath( strPath2, strDelimiter, bReverseOrder );
						if ( o )
							return o;
					}
					if ( (*it)->getStereotype() == OT_Folder ) {
						Object o = Folder( *it )->findByPath( strPath2, strDelimiter, bReverseOrder );
						if ( o )
							return o;
					}
				}
			}
		return NULL;
	}

//===============================================================================================================================================
// 	C L A S S : BON::FolderImpl					// Extensions

	void FolderImpl::accept( Visitor* pVisitor )
	{
		ObjectSet children = getChildObjectsI();
		for ( ObjectSet::iterator it = children.begin() ; it != children.end() ; it++ )
			(*it)->accept( pVisitor );
		pVisitor->visitFolder( Folder( this ) );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ConnectionEndImpl
//
//###############################################################################################################################################

	ConnectionEndImpl::ConnectionEndImpl()
		: m_bAllConnections( false ), m_pProject( NULL )
	{
	}

	ConnectionEndImpl* ConnectionEndImpl::attachI( IMgaConnPoint* spCP, ProjectImpl* pProject, const MON::Object& meta )
	{
		FCOPtr spTarget;
		COMTHROW( spCP->get_Target( spTarget.Addr() ) );
		FCOImpl* pTarget = FCOImpl::attachI( spTarget, pProject, meta );

		Util::ComPtr<IMgaFCOs> spRefs;
		COMTHROW( spCP->get_References( spRefs.Addr() ) );

		long lCount;
		COMTHROW( spRefs->get_Count( &lCount ) );
		if ( lCount == 0 )
			return pTarget;

		FCOPtr spRefFirst;
		COMTHROW( spRefs->get_Item( 1, spRefFirst.Addr() ) );
		FCOPtr spRefLast;
		COMTHROW( spRefs->get_Item( lCount, spRefLast.Addr() ) );

		CComQIPtr<IMgaReference> spRef = spRefLast;
		FCOPtr spRefTarget;
		COMTHROW( spRef->get_Referred( spRefTarget.Addr() ) );
		if ( spRefTarget == spTarget )
			return FCOImpl::attachI( spRefFirst, pProject );

		return dynamic_cast<ReferenceImpl*>( FCOImpl::attachI( spRefFirst, pProject ) )->getRefPort( pTarget );
	}

	ConnectionEndImpl::~ConnectionEndImpl()
	{
		if ( ! m_pProject->isDestructionActive() && ! isDeleted() ) {
			for ( ManyConnectionLink::iterator it = m_connections.begin() ; it != m_connections.end() ; it++ )
				for ( ConnectionSet::iterator it2 = it->second.second.begin() ; it2 != it->second.second.end() ; it2++ )
					(*it2)->onReleasedAsConnection( this, it->first.first, true );
		}

		m_connections.clear();
		m_pProject = NULL;
	}

	bool ConnectionEndImpl::setDeleted()
	{
		bool bRet = GenRefCounted::setDeleted();

		for ( ManyConnectionLink::iterator it = m_connections.begin() ; it != m_connections.end() ; it++ )
			for ( ConnectionSet::iterator it2 = it->second.second.begin() ; it2 != it->second.second.end() ; it2++ )
				(*it2)->setDeleted();
		m_connections.clear();

		return bRet;
	}

	void ConnectionEndImpl::setProject( ProjectImpl* pProject )
	{
		m_pProject = pProject;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ConnectionEndImpl					// Get and Set Operations // ---> Interface Methods

	Project ConnectionEndImpl::getProject() const
	{
		return m_pProject;
	}

	std::string	ConnectionEndImpl::getInfoString( const std::set<Util::InfoOption>& setOptions ) const
	{
		return getInfoString( copy( setOptions ) );
	}

//===============================================================================================================================================
// 	C L A S S : BON::ConnectionEndImpl					// Relations

	bool ConnectionEndImpl::isConnectionsRetrieved( const MON::ConnectionEnd::Pair& meta )
	{
		ManyConnectionLink::iterator it = m_connections.find( meta );
		if ( it != m_connections.end() ) {
			if ( it->second.first )
				return true;
			it->second.first = true;
			return false;
		}
		m_connections[ meta ] = ConnectionSetPair( true, ConnectionSet() );
		return false;
	}

	void ConnectionEndImpl::getConnections( std::set<ConnPointPtr>& setSPConnPoints )
	{
		Util::ComPtr<IMgaConnPoints> spCPs;
		COMTHROW( getFCOHelper()->getFCOI()->get_PartOfConns( spCPs.Addr() ) );
		MGACOLL_ITERATE( IMgaConnPoint, spCPs.p ) {
			setSPConnPoints.insert( MGACOLL_ITER );
		} MGACOLL_ITERATE_END;
	}

	void ConnectionEndImpl::getConnections( const MON::ConnectionEnd::Pair& meta, std::set<ConnPointPtr>& setSPConnPoints, bool bErase )
	{
		std::set<ConnPointPtr>::iterator it = setSPConnPoints.begin();
		while ( it != setSPConnPoints.end() ) {
			std::set<ConnPointPtr>::iterator itSaved = it;
			it++;
			CComBSTR bstrRole;
			COMTHROW( (*itSaved)->get_ConnRole( &bstrRole ) );
			if ( Util::Copy( bstrRole ) == meta.first ) {
				ConnectionPtr spConnection;
				COMTHROW( (*itSaved)->get_Owner( spConnection.Addr() ) );
				if ( _getMetaRef( spConnection ) == meta.second.ref() ) {
					ConnectionEndImpl* pEnd = ConnectionEndImpl::attachI( *itSaved, m_pProject );
					pEnd->isConnectionsRetrieved( meta );
					ConnectionImpl* pConnection = ConnectionImpl::attachI( spConnection, m_pProject, meta.second );
					if ( pEnd->m_connections[ meta ].second.find( pConnection ) == pEnd->m_connections[ meta ].second.end() ) {
						pEnd->m_connections[ meta ].second.insert( pConnection );
						pConnection->onRetrievedAsConnection( pEnd, meta.first, false );
					}
					if ( bErase )
						setSPConnPoints.erase( itSaved );
				}
			}
		}
	}

	ConnectionSet ConnectionEndImpl::getConnectionsI( const std::string& strRole, const MON::Connection& meta, bool bOnlyCE )
	{
		std::set<ConnectionEndImpl*> CEs;
		if ( ! bOnlyCE ) {
			CEs.insert( this );
			if ( isReferencePort() ) {
				std::set<ReferencePort> ports = ( (ReferencePortImpl*) this )->getDescendantPorts();
				for ( std::set<ReferencePort>::iterator it = ports.begin() ; it != ports.end() ; it++ )
					CEs.insert( dynamic_cast<ConnectionEndImpl*> ( it->getCounted() ) );
			}
			else {
				ReferencePortSet ports = ( (FCOImpl*) this )->getRefPortRefsI();
				CEs.insert( ports.begin(), ports.end() );
			}
		}

		if ( ! strRole.empty() && meta ) {
			MON::ConnectionEnd::Pair metaRole( strRole, meta );
			if ( ! isConnectionsRetrieved( metaRole ) ) {
				std::set<ConnPointPtr> setSPConnPoints;
				getConnections( setSPConnPoints );
				getConnections( metaRole, setSPConnPoints, false );
			}
			if ( bOnlyCE )
				return m_connections[ metaRole ].second;


			ConnectionSet setOut;
			for ( std::set<ConnectionEndImpl*>::iterator it = CEs.begin() ; it != CEs.end() ; it++ )
				setOut.insert( (*it)->m_connections[ metaRole ].second.begin(), (*it)->m_connections[ metaRole ].second.end() );
			return setOut;
		}

		ConnectionSet setOut;
		if ( ! m_bAllConnections ) {
			std::set<MON::ConnectionRole> roles = getFCOHelper()->getFCOMeta().targetOf();
			for ( std::set<MON::ConnectionRole>::iterator it = roles.begin() ; it != roles.end() ; it++ ) {
				if ( ( strRole.empty() || strRole == it->name() ) && ( ! meta || meta == it->specification().connection() ) ) {
					MON::ConnectionEnd::Pair metaRole( it->name(), it->specification().connection() );
					if ( ! isConnectionsRetrieved( metaRole ) ) {
						std::set<ConnPointPtr> setSPConnPoints;
						getConnections( setSPConnPoints );
						getConnections( metaRole, setSPConnPoints, true );
					}
				}
			}

			if ( strRole.empty() && ! meta ) {
				for ( std::set<ConnectionEndImpl*>::iterator it = CEs.begin() ; it != CEs.end() ; it++ )
					(*it)->m_bAllConnections = true;
			}
		}

		std::set<MON::ConnectionRole> roles = getFCOHelper()->getFCOMeta().targetOf();
		for ( std::set<MON::ConnectionRole>::iterator it = roles.begin() ; it != roles.end() ; it++ ) {
			if ( ( strRole.empty() || strRole == it->name() ) && ( ! meta || meta == it->specification().connection() ) ) {
				MON::ConnectionEnd::Pair metaRole( it->name(), it->specification().connection() );
				if ( bOnlyCE )
					setOut.insert( m_connections[ metaRole ].second.begin(), m_connections[ metaRole ].second.end() );
				else {
					for ( std::set<ConnectionEndImpl*>::iterator it2 = CEs.begin() ; it2 != CEs.end() ; it2++ )
						setOut.insert( (*it2)->m_connections[ metaRole ].second.begin(), (*it2)->m_connections[ metaRole ].second.end() );
				}
			}
		}
		return setOut;
	}

	FCOImpl* ConnectionEndImpl::getFCOHelper() const
	{
		return ( isReferencePort() ) ? ( (ReferencePortImpl*) this)->m_pFCO : (FCOImpl*) this;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ConnectionEndImpl					// Event Handlers

	bool ConnectionEndImpl::onRetrievedAsConnectionEnd( ConnectionImpl* pConnection, const std::string& strRole, bool bCheckAll )
	{
		MON::ConnectionEnd::Pair meta( strRole, pConnection->getConnectionMeta() );
		ManyConnectionLink::iterator it = m_connections.find( meta );
		if ( it == m_connections.end() ) {
			if ( bCheckAll )
				return false;
			m_connections[ meta ] = ConnectionSetPair( false, ConnectionSet() );
		}
		if ( ! bCheckAll || bCheckAll && m_connections[ meta ].first ) {
			m_connections[ meta ].second.insert( pConnection );
			return true;
		}
		return false;
	}

	void ConnectionEndImpl::onReleasedAsConnectionEnd( ConnectionImpl* pConnection, const std::string& strRole, bool bOnlyFreeMemory )
	{
		MON::ConnectionEnd::Pair meta( strRole, pConnection->getConnectionMeta() );
		ManyConnectionLink::iterator it = m_connections.find( meta );
		if ( it != m_connections.end() ) {
			m_connections[ meta ].second.erase( pConnection );
			if ( bOnlyFreeMemory && m_connections[ meta ].first ) {
				FCOImpl* pFCO = ( isReferencePort() ) ? ( (ReferencePortImpl*) this)->m_pFCO : (FCOImpl*) this;
				ReferencePortSet ports = pFCO->getRefPortRefsI();
				for ( ReferencePortSet::iterator it = ports.begin() ; it != ports.end() ; it++ ) {
					( (ConnectionEndImpl*) (*it) )->m_connections[ meta ].first = false;
					( (ConnectionEndImpl*) (*it) )->m_bAllConnections = false;
				}
				( (ConnectionEndImpl*) pFCO )->m_connections[ meta ].first = false;
				( (ConnectionEndImpl*) pFCO )->m_bAllConnections = false;
			}
		}
	}

//===============================================================================================================================================
// 	C L A S S : BON::ConnectionEndImpl					// Relations // ---> Interface Methods

	std::set<Connection> ConnectionEndImpl::getConnLinks( const MON::Connection& meta, const std::string& strRole, bool bAsFCO, const MON::Aspect& aspect )
	{
		if ( aspect && aspect.project() != getProject()->getProjectMeta() )
		{
			MON::Exception exc( "? does not belong to ? of ?!");//, "sss", 
			exc << aspect.infoString().c_str() << getProject()->getProjectMeta().infoString().c_str() << getProject()->getInfoString().c_str();
			ASSERTTHROW( exc);
		}

		// meta specified
		if ( meta ) {
			if ( meta.project() != getProject()->getProjectMeta() )
			{
				MON::Exception exc( "? does not belong to ? of ?!");//, "sss", 
				exc << meta.infoString().c_str() << getProject()->getProjectMeta().infoString().c_str() << getProject()->getInfoString().c_str();
				ASSERTTHROW( exc );
			}

			std::string str = meta.name();
			bool bFound = false;
			int iCnt = meta.specificationCount();
			for ( int i = 0 ; i < iCnt ; i++ ) {
				std::set<MON::ConnectionRole> roles = meta.specification( i ).roles();
				for ( std::set<MON::ConnectionRole>::iterator it = roles.begin() ; it != roles.end() ; it++ ) {
					if ( ( strRole.empty() || strRole == it->name() ) &&  it->isTarget( getFCOHelper()->getFCOMeta() ) ) {
						bFound = true;
						break;
					}
				}
				if ( bFound )
					break;
			}

			if ( ! bFound )
				if ( strRole.empty() ) {
					MON::Exception exc( "? cannot be target of ?!");//, "ss", 
					exc << getFCOHelper()->getObjectMeta().infoString().c_str() << meta.infoString().c_str(); 
					ASSERTTHROW( exc);
				}
				else {
					MON::Exception exc( "? cannot be target of ? with role ?!");//, "sss", 
					exc << getFCOHelper()->getObjectMeta().infoString().c_str() << meta.infoString().c_str() << strRole.c_str();
					ASSERTTHROW( exc);
				}

			std::set<Connection> setResult;
			setCopy<Connection,ConnectionImpl>( getConnectionsI( strRole, meta, ! bAsFCO ), setResult );
			return filterByAspect<Connection>( setResult, aspect );
		}

		// meta NOT specified
		// role specified
		if ( ! strRole.empty() ) {
			bool bFound = false;
			std::set<MON::ConnectionRole> roles = getFCOHelper()->getFCOMeta().targetOf();
			for ( std::set<MON::ConnectionRole>::iterator it = roles.begin() ; it != roles.end() ; it++ ) {
				if ( it->name() == strRole ) {
					bFound = true;
					break;
				}
			}
			if ( ! bFound )
			{
				MON::Exception exc( "? cannot be target of any MON::Connection with role ?!");
				exc << getFCOHelper()->getObjectMeta().infoString() << strRole; 
				ASSERTTHROW( exc);
			}

			std::set<Connection> setResult;
			setCopy<Connection,ConnectionImpl>( getConnectionsI( strRole, meta, ! bAsFCO ), setResult );
			return filterByAspect<Connection>( setResult, aspect );
		}

		// role NOT specified

		std::set<Connection> setResult;
		setCopy<Connection,ConnectionImpl>( getConnectionsI( strRole, meta, ! bAsFCO ), setResult );
		return filterByAspect<Connection>( setResult, aspect );
	}

	std::set<Connection> ConnectionEndImpl::getConnLinks( const std::string& strConnection, const std::string& strRole, bool bAsFCO, const MON::Aspect& aspect )
	{
		MON::Connection meta;
		if ( ! strConnection.empty() ) {
			meta = MON::Connection( getProject()->getProjectMeta().findByName( strConnection ) );
#ifdef TEST_META_CONFORMANCE_INSIDE_BON
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, Connection, strConnection );
#else
			if( !meta)
				return std::set<Connection>();
#endif
		}
		return getConnLinks( meta, strRole, bAsFCO, aspect );
	}

	std::set<Connection> ConnectionEndImpl::getInConnLinks( const MON::Connection& meta, bool bAsFCO, const MON::Aspect& aspect )
	{
		return getConnLinks( meta, "dst", bAsFCO, aspect );
	}

	std::set<Connection> ConnectionEndImpl::getInConnLinks( const std::string& strConnection, bool bAsFCO, const MON::Aspect& aspect )
	{
		return getConnLinks( strConnection, "dst", bAsFCO, aspect );
	}

	std::set<Connection> ConnectionEndImpl::getOutConnLinks( const MON::Connection& meta, bool bAsFCO, const MON::Aspect& aspect )
	{
		return getConnLinks( meta, "src", bAsFCO, aspect );
	}

	std::set<Connection> ConnectionEndImpl::getOutConnLinks( const std::string& strConnection, bool bAsFCO, const MON::Aspect& aspect )
	{
		return getConnLinks( strConnection, "src", bAsFCO, aspect );
	}

	typedef std::vector<std::string> RoleVec;
	typedef std::pair<MON::Connection,RoleVec> RoleMeta2;

	std::multiset<ConnectionEnd> ConnectionEndImpl::getConnEndsAs( const MON::Connection& meta, const std::string& strRole, bool bAsFCO, const MON::Aspect& aspect )
	{
		if ( aspect && aspect.project() != getProject()->getProjectMeta() )
		{
			MON::Exception exc( "? does not belong to ? of ?!");
			exc << aspect.infoString() << getProject()->getProjectMeta().infoString() << getProject()->getInfoString();
			ASSERTTHROW( exc);
		}

		std::set<RoleMeta2> metaRoles;
		std::set<MON::ConnectionSpecification> specs;

		// meta specified
		if ( meta ) {
			if ( meta.project() != getProject()->getProjectMeta() )
			{
				MON::Exception exc( "? does not belong to ? of ?!");
				exc << meta.infoString() << getProject()->getProjectMeta().infoString() << getProject()->getInfoString(); 
				ASSERTTHROW( exc);
			}
			if ( ! meta.isSimple() )
			{
				MON::Exception exc( "? is not simple!");
				exc << meta.infoString();
				ASSERTTHROW( exc);
			}

			// role check
			bool bFound = false;
			for ( int i = 0 ; i < meta.specificationCount() ; i++ ) {
				std::set<MON::ConnectionRole> roles = meta.specification( i ).roles();
				for ( std::set<MON::ConnectionRole>::iterator it2 = roles.begin() ; it2 != roles.end() ; it2++ )
					if ( ( strRole.empty() || strRole == it2->name() ) && it2->isTarget( getFCOHelper()->getFCOMeta() ) ) {
						bFound = true;
						break;
					}
			}
			if ( ! bFound )
			{
#ifdef TEST_META_CONFORMANCE_INSIDE_BON
				if ( strRole.empty() ) {
					MON::Exception exc( "? cannot be target of ?!");
					exc << getFCOHelper()->getObjectMeta().infoString() << meta.infoString(); 
					ASSERTTHROW( exc);
				}
				else {
					MON::Exception exc( "? cannot be target of ? with role ?!");
					exc << getFCOHelper()->getObjectMeta().infoString() << meta.infoString() << strRole; 
					ASSERTTHROW( exc);
				}
#else
				return std::multiset<ConnectionEnd>();
#endif
			}

			specs = meta.specifications();
		}
		// meta NOT specified
		else {
			bool bFound = false;
			std::set<MON::ConnectionRole> roles = getFCOHelper()->getFCOMeta().targetOf();
			for ( std::set<MON::ConnectionRole>::iterator it = roles.begin() ; it != roles.end() ; it++ ) {
				if ( it->specification().connection().isSimple() ) {
					specs.insert( it->specification() );
					bFound = true;
				}
			}

			if ( ! bFound )
				return std::multiset<ConnectionEnd>();
			/*if ( ! bFound ) commented out by ZolMol: do not throw if -- meta NOT specified --
				ASSERTTHROW( MON::Exception( "? cannot be target of simple MON::Connection!", "ss", getFCOHelper()->getObjectMeta().infoString().c_str() ) );*/
		}

		bool bFound = false;
		for ( std::set<MON::ConnectionSpecification>::iterator it = specs.begin() ; it != specs.end() ; it++ ) {
			std::set<MON::ConnectionRole> roles = it->roles();
			RoleVec rVec( 2 );
			int iDir = 0;
			for ( std::set<MON::ConnectionRole>::iterator it2 = roles.begin() ; it2 != roles.end() ; it2++ ) {
				if ( it2->isTarget( getFCOHelper()->getFCOMeta()) && ( strRole.empty() || strRole == it2->name() ) ) {
					rVec[ iDir++ ] = it2->name();
					bFound = true;
				}
				else
					rVec[ 1 ] = it2->name();
			}
			if ( iDir > 0 ) {
				metaRoles.insert( RoleMeta2( it->connection(), rVec ) );
				if ( iDir == 2 ) {
					RoleVec rVec2( 2 );
					rVec2[ 0 ] = rVec[ 1 ];
					rVec2[ 1 ] = rVec[ 0 ];
					metaRoles.insert( RoleMeta2( it->connection(), rVec2 ) );
				}
			}
		}

		if ( ! bFound )
			if ( strRole.empty() ) {
				MON::Exception exc( "? cannot be target of MON::Connection!");
				exc << getFCOHelper()->getObjectMeta().infoString();
				ASSERTTHROW( exc);
			}
			else {
				MON::Exception exc( "? cannot be target of MON::Connection with role ?!");
				exc << getFCOHelper()->getObjectMeta().infoString() << strRole; 
				ASSERTTHROW( exc);
			}

		std::multiset<ConnectionEnd> setResult;
		for ( std::set<RoleMeta2>::iterator itr = metaRoles.begin() ; itr != metaRoles.end() ; itr++ ) {
			ConnectionSet conns = getConnectionsI( itr->second[ 0 ], itr->first, ! bAsFCO );
			for ( ConnectionSet::iterator itc = conns.begin() ; itc != conns.end() ; itc++ )
				setResult.insert( (*itc)->getConnectionEndI( itr->second[ 1 ] ) );
		}

		if ( aspect ) {
			std::multiset<ConnectionEnd>::iterator itce = setResult.begin();
			while ( itce != setResult.end() ) {
				std::multiset<ConnectionEnd>::iterator itSaved = itce;
				itce++;
				if ( ! (*itSaved)->getFCOHelper()->isVisible( aspect, true ) ) // changed meta->aspect by ZolMol
					setResult.erase( itSaved );
			}
		}
		return setResult;
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getConnEndsAs( const std::string& strConnection, const std::string& strRole, bool bAsFCO, const MON::Aspect& aspect )
	{
		MON::Connection meta;
		if ( ! strConnection.empty() ) {
			meta = MON::Connection( getProject()->getProjectMeta().findByName( strConnection ) );
#ifdef TEST_META_CONFORMANCE_INSIDE_BON
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, Connection, strConnection );
#else
			if( !meta)
				return std::multiset<ConnectionEnd>();
#endif
		}
		return getConnEndsAs( meta, strRole, bAsFCO, aspect );
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getInConnEnds( const MON::Connection& meta, bool bAsFCO, const MON::Aspect& aspect )
	{
		return getConnEndsAs( meta, "dst", bAsFCO, aspect );
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getInConnEnds( const std::string& strConnection, bool bAsFCO, const MON::Aspect& aspect )
	{
		return getConnEndsAs( strConnection, "dst", bAsFCO, aspect );
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getOutConnEnds( const MON::Connection& meta, bool bAsFCO, const MON::Aspect& aspect )
	{
		return getConnEndsAs( meta, "src", bAsFCO, aspect );
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getOutConnEnds( const std::string& strConnection, bool bAsFCO, const MON::Aspect& aspect )
	{
		return getConnEndsAs( strConnection, "src", bAsFCO, aspect );
	}

	void ConnectionEndImpl::getDirectConnEndsRec( ConnectionEnd& ce, const MON::Connection& meta, const std::string& strRole, bool bAsFCO, std::multiset<ConnectionEnd>& setResult )
	{
		std::multiset<ConnectionEnd> ends = ce->getConnEndsAs( meta, strRole, bAsFCO );
		if ( ends.empty() ) {
			setResult.insert( ce );
			return;
		}
		for ( std::multiset<ConnectionEnd>::iterator it = ends.begin() ; it != ends.end() ; it++ ) {
			ConnectionEnd ce( *it );
			getDirectConnEndsRec( ce, meta, strRole, bAsFCO, setResult );
		}
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getDirectConnEnds( const MON::Connection& meta, const std::string& strRole, bool bAsFCO, const MON::Aspect& aspect )
	{
		THROW_CANNOT_BE_NULL( meta, "MON::Connection" );
		THROW_CANNOT_BE_EMPTY( "The role", strRole );
		std::multiset<ConnectionEnd> setResult;
		ConnectionEnd ce( this );
		getDirectConnEndsRec( ce, meta, strRole, bAsFCO, setResult );

		if ( aspect ) {
			std::multiset<ConnectionEnd>::iterator itce = setResult.begin();
			while ( itce != setResult.end() ) {
				std::multiset<ConnectionEnd>::iterator itSaved = itce;
				itce++;
				if ( ! (*itSaved)->getFCOHelper()->isVisible( aspect, true ) ) // changed meta->aspect by ZolMol
					setResult.erase( itSaved );
			}
		}
		return setResult;
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getDirectConnEnds( const std::string& strConnection, const std::string& strRole, bool bAsFCO, const MON::Aspect& aspect )
	{
		MON::Connection meta = getProject()->getProjectMeta().findByName( strConnection );
		THROW_METAPROJECT_DOES_NOT_HAVE( meta, Connection, strConnection );
		return getDirectConnEnds( meta, strRole, bAsFCO, aspect );
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getDirectInConnEnds( const MON::Connection& meta, bool bAsFCO, const MON::Aspect& aspect )
	{
		return getDirectConnEnds( meta, "dst", bAsFCO, aspect );
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getDirectOutConnEnds( const MON::Connection& meta, bool bAsFCO, const MON::Aspect& aspect )
	{
		return getDirectConnEnds( meta, "src", bAsFCO, aspect );
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getDirectInConnEnds( const std::string& strConnection, bool bAsFCO, const MON::Aspect& aspect )
	{
		MON::Connection meta = getProject()->getProjectMeta().findByName( strConnection );
		THROW_METAPROJECT_DOES_NOT_HAVE( meta, Connection, strConnection );
		return getDirectConnEnds( meta, "dst", bAsFCO, aspect );
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getDirectOutConnEnds( const std::string& strConnection, bool bAsFCO, const MON::Aspect& aspect )
	{
		MON::Connection meta = getProject()->getProjectMeta().findByName( strConnection );
		THROW_METAPROJECT_DOES_NOT_HAVE( meta, Connection, strConnection );
		return getDirectConnEnds( meta, "src", bAsFCO, aspect );
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getConnEnds( const MON::Connection& meta, const std::string& strRole, bool bAsFCO, const MON::Aspect& aspect )
	{
		if ( aspect && aspect.project() != getProject()->getProjectMeta() )
		{
			MON::Exception exc( "? does not belong to ? of ?!");
			exc << aspect.infoString() << getProject()->getProjectMeta().infoString() << getProject()->getInfoString(); 
			ASSERTTHROW( exc);
		}

		std::set<RoleMeta2> metaRoles;
		std::set<MON::ConnectionSpecification> specs;

		// meta specified
		if ( meta ) {
			if ( meta.project() != getProject()->getProjectMeta() )
			{
				MON::Exception exc( "? does not belong to ? of ?!");
				exc << meta.infoString() << getProject()->getProjectMeta().infoString() << getProject()->getInfoString(); 
				ASSERTTHROW( exc);
			}
			if ( ! meta.isSimple() )
			{
				MON::Exception exc( "? is not simple!");
				exc << meta.infoString();
				ASSERTTHROW( exc);
			}

			// connection check
			bool bFound = false;
			for ( int i = 0 ; i < meta.specificationCount() ; i++ ) {
				std::set<MON::ConnectionRole> roles = meta.specification( i ).roles();
				for ( std::set<MON::ConnectionRole>::iterator it2 = roles.begin() ; it2 != roles.end() ; it2++ )
					if ( it2->isTarget( getFCOHelper()->getFCOMeta()) ) {
						bFound = true;
						break;
					}
			}
			if ( ! bFound )
			{
#ifdef TEST_META_CONFORMANCE_INSIDE_BON
				MON::Exception exc( "? cannot be target of ?!");
				exc << getFCOHelper()->getObjectMeta().infoString() << meta.infoString();
				ASSERTTHROW( exc);
#else				
				return std::multiset<ConnectionEnd>();
#endif
			}

			specs = meta.specifications();
		}
		// meta NOT specified
		else {
			bool bFound = false;
			std::set<MON::ConnectionRole> roles = getFCOHelper()->getFCOMeta().targetOf();
			for ( std::set<MON::ConnectionRole>::iterator it = roles.begin() ; it != roles.end() ; it++ ) {
				if ( it->specification().connection().isSimple() ) {
					specs.insert( it->specification() );
					bFound = true;
				}
			}

			if ( ! bFound )
				return std::multiset<ConnectionEnd>();
			/*if ( ! bFound ) commented out by ZolMol: do not throw -- if meta NOT specified --
				ASSERTTHROW( MON::Exception( "? cannot be target of simple MON::Connection!", "ss", getFCOHelper()->getObjectMeta().infoString().c_str() ) );*/
		}

		bool bFound = false;
		for ( std::set<MON::ConnectionSpecification>::iterator it = specs.begin() ; it != specs.end() ; it++ ) {
			std::set<MON::ConnectionRole> roles = it->roles();
			RoleVec rVec( 2 );
			int iDir = 0;
			for ( std::set<MON::ConnectionRole>::iterator it2 = roles.begin() ; it2 != roles.end() ; it2++ ) {
				if ( it2->isTarget( getFCOHelper()->getFCOMeta() ) )
					rVec[ iDir++ ] = it2->name();
				else
					rVec[ 1 ] = it2->name();
			}
			if ( iDir > 0 ) {
				if ( strRole.empty() || strRole == rVec[ 1 ] ) {
					bFound = true;
					metaRoles.insert( RoleMeta2( it->connection(), rVec ) );
				}
				if ( iDir == 2 ) {
					RoleVec rVec2( 2 );
					rVec2[ 0 ] = rVec[ 1 ];
					rVec2[ 1 ] = rVec[ 0 ];
					if ( strRole.empty() || strRole == rVec2[ 1 ] ) {
						bFound = true;
						metaRoles.insert( RoleMeta2( it->connection(), rVec2 ) );
					}
				}
			}
		}

		if ( ! bFound )
			if ( strRole.empty() ) {
				MON::Exception exc( "? cannot be target of ?!");
				exc << getFCOHelper()->getObjectMeta().infoString() << (( meta ) ? meta.infoString() : "MON::Connection"); 
				ASSERTTHROW( exc);
			}
			else
				if ( meta ) {
					MON::Exception exc( "? does not have peer with role ?!");
					exc << getFCOHelper()->getObjectMeta().infoString() << strRole; 
					ASSERTTHROW( exc);
				}
				else {
					MON::Exception exc( "? does not have peer with ? and with role ?!");
					exc << getFCOHelper()->getObjectMeta().infoString() << meta.infoString() << strRole;
					ASSERTTHROW( exc);
				}

		std::multiset<ConnectionEnd> setResult;
		for ( std::set<RoleMeta2>::iterator itr = metaRoles.begin() ; itr != metaRoles.end() ; itr++ ) {
			ConnectionSet conns = getConnectionsI( itr->second[ 0 ], itr->first, ! bAsFCO );
			for ( ConnectionSet::iterator itc = conns.begin() ; itc != conns.end() ; itc++ )
				setResult.insert( (*itc)->getConnectionEndI( itr->second[ 1 ] ) );
		}

		if ( aspect ) {
			std::multiset<ConnectionEnd>::iterator itce = setResult.begin();
			while ( itce != setResult.end() ) {
				std::multiset<ConnectionEnd>::iterator itSaved = itce;
				itce++;
				if ( ! (*itSaved)->getFCOHelper()->isVisible( aspect, true ) ) // change meta->aspect by ZolMol
					setResult.erase( itSaved );
			}
		}
		return setResult;
	}

	std::multiset<ConnectionEnd> ConnectionEndImpl::getConnEnds( const std::string& strConnection, const std::string& strRole, bool bAsFCO, const MON::Aspect& aspect )
	{
		MON::Connection meta;
		if ( ! strConnection.empty() ) {
			meta = MON::Connection( getProject()->getProjectMeta().findByName( strConnection ) );
#ifdef TEST_META_CONFORMANCE_INSIDE_BON
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, Connection, strConnection );
#else
			if( !meta)
				return std::multiset<ConnectionEnd>();
#endif
		}
		return getConnEnds( meta, strRole, bAsFCO, aspect );
	}

//===============================================================================================================================================
// 	C L A S S : BON::ConnectionEndImpl					// Extensions

	void ConnectionEndImpl::accept( Visitor* pVisitor )
	{
		if ( isReferencePort() )
			( (ReferencePortImpl*) this)->accept( pVisitor );
		else
			( (FCOImpl*) this)->accept( pVisitor );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ReferencePortImpl
//
//###############################################################################################################################################

	ReferencePortImpl::ReferencePortImpl( ReferenceImpl* pContainer, FCOImpl* pFCO )
		: m_pContainer( pContainer ), m_pFCO( pFCO )
	{
		setProject( (ProjectImpl*) m_pFCO->getProject().getCounted() );
		setDisposable( _isAddOn() );
		std::set<Util::GenRefCounted*> setAggrs;
		setAggrs.insert( dynamic_cast<Util::GenRefCounted*>( pFCO ) );
		setAggrs.insert( dynamic_cast<Util::GenRefCounted*>( pContainer ) );
		setAggregators( setAggrs );
	}

	ReferencePortImpl::~ReferencePortImpl()
	{
		if ( ! m_pProject->isDestructionActive() && ! isDeleted() ) {
			m_pFCO->onReleasedAsReferencePort( this, true );
			m_pContainer->onReleasedAsPortContainer( m_pFCO, true );
		}

		m_pFCO = NULL;
		m_pContainer = NULL;
	}

	bool ReferencePortImpl::setDeleted()
	{
		if ( ConnectionEndImpl::setDeleted() )
			return true;

		m_pFCO->onReleasedAsReferencePort( this, false );
		m_pContainer->onReleasedAsPortContainer( m_pFCO, false );

		return false;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ReferencePortImpl					// Get And Set Operations // ---> Interface Methods

	bool ReferencePortImpl::isReferencePort() const
	{
		return true;
	}

	ReferencePortContainer ReferencePortImpl::getContainer() const
	{
		return m_pContainer->getRefPortContainer();
	}

	FCO ReferencePortImpl::getFCO() const
	{
		return m_pFCO;
	}

	std::string ReferencePortImpl::getInfoString( unsigned short usOptions ) const
	{
		bool bAll = ( usOptions & Util::IO_All ) ? true : false;
		bool bIdent = bAll || ( usOptions & Util::IO_Identifiers );
		bool bLine = bAll || ( usOptions & Util::IO_NewLine );
		std::string strDelim = ( bLine ) ? "\n" : ", ";

		std::string strInfo( "BON::ReferencePort" );
		strInfo += ( bLine ) ? " :\n" : " [";

		unsigned short usOptions2 = 0;
		if ( bIdent )
			usOptions2 |= Util::IO_Identifiers;
		if ( bAll || ( usOptions & Util::IO_ID ) )
			usOptions2 |= Util::IO_ID;
		if ( bAll || ( usOptions & Util::IO_Meta ) )
			usOptions2 |= Util::IO_Meta;
		if ( bAll || ( usOptions & Util::IO_Path ) )
			usOptions2 |= Util::IO_Path;

		if ( bIdent )
			strInfo += "fco: ";
		strInfo += m_pFCO->getInfoString( usOptions2 ) + strDelim;

		if ( bIdent )
			strInfo += "container: ";
		strInfo += m_pContainer->getInfoString( usOptions2 );

		if ( ! bLine )
			strInfo += "]";

		return strInfo;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ReferencePortImpl					// Relations

	void ReferencePortImpl::getDescendantPortsI( std::set<Reference>& setVisited, std::set<ReferencePort>& setPorts ) const
	{
		if ( setVisited.find( m_pContainer ) == setVisited.end() ) {
			setVisited.insert(  m_pContainer );

			std::set<Reference> refs = m_pContainer->getReferredBy();
			for ( std::set<Reference>::iterator it = refs.begin() ; it != refs.end() ; it++ ) {
				ReferencePort port = (*it)->getRefPortContainer()->getReferencePort( m_pFCO );
				setPorts.insert( port );
				dynamic_cast<ReferencePortImpl*>( port.getCounted() )->getDescendantPortsI( setVisited, setPorts );
			}
		}
	}

//===============================================================================================================================================
// 	C L A S S : BON::ReferencePortImpl					// Extensions

	void ReferencePortImpl::accept( Visitor* pVisitor )
	{
		pVisitor->visitReferencePort( ReferencePort( this ) );
	}

//===============================================================================================================================================
// 	C L A S S : BON::ReferencePortImpl					// Relations // ---> Interface Methods

	ReferencePort ReferencePortImpl::getParentPort() const
	{
		Reference ref( m_pContainer->getReferred() );
		return ( ref ) ? ref->getRefPortContainer()->getReferencePort( m_pFCO ) : NULL;
	}

	std::set<ReferencePort> ReferencePortImpl::getChildPorts() const
	{
		std::set<Reference> refs = m_pContainer->getReferredBy();
		std::set<ReferencePort> ports;
		for ( std::set<Reference>::iterator it = refs.begin() ; it != refs.end() ; it++ )
			 ports.insert( (*it)->getRefPortContainer()->getReferencePort( m_pFCO ) );
		return ports;
	}

	std::set<ReferencePort> ReferencePortImpl::getDescendantPorts() const
	{
		std::set<Reference> setVisited;
		std::set<ReferencePort> setPorts;
		getDescendantPortsI( setVisited, setPorts );
		return setPorts;
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::FCOImpl
//
//###############################################################################################################################################

	FCOImpl::FCOImpl()
		: ObjectImpl(), m_bAllParentModels( false ), m_pType( NULL ), m_bAllTypeFCOs( false ), m_bAllInstanceFCOs( false ), m_bAllSubTypeFCOs( false ), m_bAllSets( false ), m_bAllReferences( false ), m_bAllAttributes( false ), m_bAllRefPorts( false ), m_pTIObject( NULL )
	{
		m_parentModel.first = MON::Model();
		m_parentModel.second = NULL;
	}

	void FCOImpl::doInitialize( ProjectImpl* pProject )
	{
		setProject( pProject );
	}

	FCOImpl* FCOImpl::attachI( IMgaFCO* spFCO, ProjectImpl* pProject, const MON::Object& meta )
	{
		FCOImpl* pFCO = NULL;
		CComQIPtr<IMgaAtom> spAtom = spFCO;
		if ( spAtom )
			pFCO = AtomImpl::attachI( spAtom, pProject, meta );
		else {
			CComQIPtr<IMgaModel> spModel = spFCO;
			if ( spModel )
				pFCO = ModelImpl::attachI( spModel, pProject, meta );
			else {
				CComQIPtr<IMgaSet> spSet = spFCO;
				if ( spSet )
					pFCO = SetImpl::attachI( spSet, pProject, meta );
				else {
					CComQIPtr<IMgaReference> spReference = spFCO;
					if ( spReference )
						pFCO = ReferenceImpl::attachI( spReference, pProject, meta );
					else {
						CComQIPtr<IMgaConnection> spConnection = spFCO;
						if ( spConnection )
							pFCO =  ConnectionImpl::attachI( spConnection, pProject, meta );
						else {
							ASSERTTHROW( Util::Exception( "Unprocessed Object Type!" ) );
						}
					}
				}
			}
		}
		// attachIPost( pFCO); // ZolMol: will be called by the special attachI's like: ModelImpl::attachI
		return pFCO;
	}
	
	// mod by Zolmol:
	// FCOImpl::attachIPost method factored out from FCOImpl::attachI
	// @called: from the attachI method of ModelImpl, AtomImpl, ReferenceImpl, 
	//          ConnectionImpl, SetImpl classes
	// @reason: in case of a model if FCOImpl::attachI is called then ModelImpl::attachI 
	//          is called for sure, but if ModelImpl::attachI is called it does not mean
	//          it has been called from FCOImpl::attachI
	void FCOImpl::attachIPost( FCOImpl* pFCO )
	{
		if ( pFCO && ! pFCO->m_pTIObject && pFCO->getStatus() == OST_Exists ) {
			if ( pFCO->isInstance() )
				pFCO->m_pTIObject = new InstanceImpl( pFCO );
			else
				pFCO->m_pTIObject = new TypeImpl( pFCO );
		}
	}

	FCO FCOImpl::attach( IMgaFCO* spFCO )
	{
		return attachI( spFCO );
	}

	FCOImpl::~FCOImpl()
	{
		if ( ! ObjectImpl::m_pProject->isDestructionActive() && ! isDeleted() ) {
			if ( m_parentModel.second )
				m_parentModel.second->onReleasedAsFCOParent( this, true );

			for ( ManyReferenceLink::iterator itR1 = m_references.begin() ; itR1 != m_references.end() ; itR1++ )
				for ( ReferenceSet::iterator itR2 = itR1->second.second.begin() ; itR2 != itR1->second.second.end() ; itR2++ )
					(*itR2)->onReleasedAsReference( this, true );

			for ( ManySetLink::iterator itS1 = m_sets.begin() ; itS1 != m_sets.end() ; itS1++ )
				for ( SetSet::iterator itS2 = itS1->second.second.begin() ; itS2 != itS1->second.second.end() ; itS2++ )
					(*itS2)->onReleasedAsSet( this, true );
		}

		for ( ManyAttributeLink::iterator it = m_attributes.begin() ; it != m_attributes.end() ; ++it )
			delete it->second;
		if ( m_pTIObject )
			delete m_pTIObject;

		m_parentModel.first = MON::Model();
		m_parentModel.second = NULL;
		m_pTIObject = NULL;
		m_attributes.clear();
		m_references.clear();
		m_sets.clear();
		m_refPorts.clear();
		m_storedRefWrappers.clear();
	}

	bool FCOImpl::setDeleted()
	{
		if ( ObjectImpl::setDeleted() )
			return true;
		ConnectionEndImpl::setDeleted();

		if ( m_parentModel.second )
			m_parentModel.second->onReleasedAsFCOParent( this, false );

		for ( ManyReferenceLink::iterator itR1 = m_references.begin() ; itR1 != m_references.end() ; itR1++ )
			for ( ReferenceSet::iterator itR2 = itR1->second.second.begin() ; itR2 != itR1->second.second.end() ; itR2++ )
				(*itR2)->onReleasedAsReference( this, false );

		for ( ManySetLink::iterator itS1 = m_sets.begin() ; itS1 != m_sets.end() ; itS1++ )
			for ( SetSet::iterator itS2 = itS1->second.second.begin() ; itS2 != itS1->second.second.end() ; itS2++ )
				(*itS2)->onReleasedAsSet( this, false );

		ReferencePortSet ports = m_refPorts;
		for ( ReferencePortSet::iterator it = ports.begin() ; it != ports.end() ; it++ )
			(*it)->setDeleted();
		return false;
	}

//===============================================================================================================================================
// 	C L A S S : BON::FCOImpl					// Get and Set Operations // ---> Interface Methods

	Project FCOImpl::getProject() const
	{
		return ObjectImpl::getProject();
	}

	FCOPtr FCOImpl::getFCOI() const
	{
		CComQIPtr<IMgaFCO> spFCO = getObjectI().p;
		return spFCO.p;
	}

	MON::FCO FCOImpl::getFCOMeta() const
	{
		return getObjectMeta();
	}

	bool FCOImpl::isReferencePort() const
	{
		return false;
	}

	bool FCOImpl::isInstance() const
	{
		VARIANT_BOOL vbInstance;
		COMTHROW( getFCOI()->get_IsInstance( &vbInstance ) );
		return vbInstance == VARIANT_TRUE;
	}
	MON::Containment FCOImpl::getRole()
	{
		getParentModel();
		return _getMetaRole( getFCOI() );
	}

	bool FCOImpl::isPort( const MON::Aspect& meta )
	{
		if ( meta )
			THROW_METAPROJECT_BELONG( meta );

		Model parm = getParentModel();
		if ( m_parentModel.first ) {
			if ( meta ) {
				std::set<MON::Aspect> aspects = m_parentModel.second->getModelMeta().aspects();
				if ( aspects.find( meta ) == aspects.end() )
					return false;
			}
			std::set<MON::ContainmentPart> parts = getRole().parts();
			for ( std::set<MON::ContainmentPart>::iterator it2 = parts.begin() ; it2 != parts.end() ; ++it2 )
				if ( it2->isLinked() && ( ! meta || meta == it2->aspect() ) )
					return true;
		}
		return false;
	}

	bool FCOImpl::isPort( const std::string& strAspect )
	{
		MON::Aspect meta;
		if ( ! strAspect.empty() ) {
			/*commented out by ZolMol, see isVisible()
			meta = MON::Aspect( getProject()->getProjectMeta().findByName( strAspect ) );
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, Aspect, strAspect );*/
			getParentModel();
			if ( m_parentModel.first ) {
				std::set<MON::Aspect> aspects = m_parentModel.second->getModelMeta().aspects();
				for( std::set<MON::Aspect>::const_iterator i = aspects.begin(); i != aspects.end(); ++i)
					if ( i->name() == strAspect)
						meta = *i;
			}
		}
		return isPort( meta );
	}

	bool FCOImpl::isVisible( const MON::Aspect& meta, bool bAsContained )
	{
		THROW_CANNOT_BE_NULL( meta, "MON::Aspect" );
		THROW_METAPROJECT_BELONG( meta );
		getParentModel();
		if ( m_parentModel.first ) {
			if ( meta ) {
				std::set<MON::Aspect> aspects = m_parentModel.second->getModelMeta().aspects();
				if ( aspects.find( meta ) == aspects.end() )
					return false;
			}

			std::set<MON::Containment> containments;
			if ( bAsContained )
				containments.insert( getRole());
				//commented line below. By ZolMol because of wrong conversion by Containment( MetaObject& )
				//containments.insert( m_parentModel.first );
			else
				containments = getFCOMeta().parentContainments();

			for ( std::set<MON::Containment>::iterator it = containments.begin() ; it != containments.end() ; ++it ) 
			{
				std::set<MON::ContainmentPart> parts = it->parts();;
				for ( std::set<MON::ContainmentPart>::iterator it2 = parts.begin() ; it2 != parts.end() ; ++it2 )
					if ( meta == it2->aspect() )
						return true;
			}
		}
		return false;
	}

	bool FCOImpl::isVisible( const std::string& strAspect, bool bAsContained )
	{
		/* Commented out by ZolMol
		MON::Aspect meta = MON::Aspect( getProject()->getProjectMeta().findByName( strAspect ) );
		THROW_METAPROJECT_DOES_NOT_HAVE( meta, Aspect, strAspect );
		return isVisible( meta, bAsContained );*/

		MON::Aspect meta;

		getParentModel();
		if ( m_parentModel.first ) {
			std::set<MON::Aspect> aspects = m_parentModel.second->getModelMeta().aspects();
			for( std::set<MON::Aspect>::const_iterator i = aspects.begin(); i != aspects.end(); ++i)
				if ( i->name() == strAspect)
					meta = *i;
		}

		return (meta)?isVisible( meta, bAsContained):false;
	}

	std::string FCOImpl::getInfoString( const std::set<Util::InfoOption>& setOptions ) const
	{
		return ObjectImpl::getInfoString( setOptions );
	}

//===============================================================================================================================================
// 	C L A S S : BON::FCOImpl					// Relations

	ReferencePortSet FCOImpl::getRefPortRefsI()
	{
		if ( ! m_bAllRefPorts ) {
			m_bAllRefPorts = true;
			ModelImpl* pModel = getParentModelI();
			if ( pModel ) {
				ReferenceSet setRefs = ( (FCOImpl*) pModel )->getReferencesI();
				for ( ReferenceSet::iterator it = setRefs.begin() ; it != setRefs.end() ; ++it )
					(*it)->getRefPort( this );
			}
		}
		return m_refPorts;
	}

	AttributeImpl* FCOImpl::getAttributeI( const MON::Attribute& meta )
	{
		if ( ! m_bAllAttributes ) {
			m_bAllAttributes = true;
			Util::ComPtr<IMgaAttributes> spAttributes;
			COMTHROW( getFCOI()->get_Attributes( spAttributes.Addr() ) );
			MGACOLL_ITERATE( IMgaAttribute, spAttributes.p ) {
				MON::AttributePtr spMeta;
				COMTHROW( MGACOLL_ITER->get_Meta( spMeta.Addr() ) );
				MON::Attribute metaIter( spMeta );
				m_attributes.insert( ManyAttributeLink::value_type( metaIter, AttributeImpl::attachI( MGACOLL_ITER, this, metaIter ) ) );
			} MGACOLL_ITERATE_END;
		}
		return m_attributes[ meta ];
	}

	ModelImpl* FCOImpl::getParentModelI( const MON::Model& meta )
	{
		// Check if Parent was already retrieved
		if ( m_parentModel.first )
			return ( ! meta || meta == m_parentModel.first ) ? m_parentModel.second : NULL;
		if ( m_bAllParentModels )
			return NULL;

		// Retrieve
		ObjectPtr spObject;
		COMTHROW( getObjectI()->GetParent( spObject.Addr() ) );
		CComQIPtr<IMgaModel> spModel = spObject;

		// It is not a Model
		if ( ! spModel ) {
			m_bAllParentModels = true;
			return NULL;
		}

		// It is a Model
		if ( ! meta || meta.ref() == _getMetaRef( spModel ) ) {
			m_parentModel.first = ( meta ) ? meta : MON::Model( getProject()->getProjectMeta().findByName( _getMetaName( spModel ) ) );
			m_parentModel.second = ModelImpl::attachI( spModel, ObjectImpl::m_pProject, m_parentModel.first );
			m_parentModel.second->onRetrievedAsFCOParent( this, false );
			if ( ! meta )
				m_bAllParentModels = true;
		}
		return m_parentModel.second;
	}

	bool FCOImpl::isSetsRetrieved( const MON::Set& meta )
	{
		ManySetLink::iterator it = m_sets.find( meta );
		if ( it != m_sets.end() ) {
			if ( it->second.first )
				return true;
			it->second.first = true;
			return false;
		}
		m_sets[ meta ] = SetSetPair( true, SetSet() );
		return false;
	}

	void FCOImpl::getSets( std::set<SetPtr>& setSPSets )
	{
		Util::ComPtr<IMgaFCOs> spSets;
		COMTHROW( getFCOI()->get_MemberOfSets( spSets.Addr() ) );
		MGACOLL_ITERATE( IMgaFCO, spSets.p ) {
			CComQIPtr<IMgaSet> spSet = MGACOLL_ITER;
			setSPSets.insert( spSet.p );
		} MGACOLL_ITERATE_END;
	}

	void FCOImpl::getSets( const MON::Set& meta, std::set<SetPtr>& setSPSets, bool bErase )
	{
		std::set<SetPtr>::iterator it = setSPSets.begin();
		while ( it != setSPSets.end() ) {
			std::set<SetPtr>::iterator itSaved = it;
			it++;
			if ( _getMetaRef( *itSaved ) == meta.ref() ) {
				SetImpl* pSet = SetImpl::attachI( *itSaved, ObjectImpl::m_pProject, meta );
				if ( m_sets[ meta ].second.find( pSet ) == m_sets[ meta ].second.end() ) {
					m_sets[ meta ].second.insert( pSet );
					pSet->onRetrievedAsSet( this, false );
				}
				if ( bErase )
					setSPSets.erase( itSaved );
			}
		}
	}

	SetSet FCOImpl::getSetsI( const MON::Set& meta )
	{
		// If Containment specified
		if ( meta ) {
			if ( ! isSetsRetrieved( meta ) ) {
				std::set<SetPtr> setSPSets;
				getSets( setSPSets );
				getSets( meta, setSPSets, false );
			}
			return m_sets[ meta ].second;
		}

		// If meta is not specified
		if ( ! m_bAllSets ) {
			m_bAllSets= true;
			std::set<SetPtr> setSPSets;
			getSets( setSPSets );
			std::set<MON::Set> setSets = getFCOMeta().memberOf();
			for ( std::set<MON::Set>::iterator it = setSets.begin() ; it != setSets.end() ; it++ ) {
				if ( ! isSetsRetrieved( *it ) )
					getSets( *it, setSPSets, true );
			}
		}

		// Create the Huge Set
		SetSet setSets;
		for ( ManySetLink::iterator it = m_sets.begin() ; it != m_sets.end() ; it++ )
			setSets.insert( it->second.second.begin(), it->second.second.end() );
		return setSets;
	}

	bool FCOImpl::isReferencesRetrieved( const MON::Reference& meta )
	{
		ManyReferenceLink::iterator it = m_references.find( meta );
		if ( it != m_references.end() ) {
			if ( it->second.first )
				return true;
			it->second.first = true;
			return false;
		}
		m_references[ meta ] = ReferenceSetPair( true, ReferenceSet() );
		return false;
	}

	void FCOImpl::getReferences( std::set<ReferencePtr>& setSPReferences )
	{
		Util::ComPtr<IMgaFCOs> spReferences;
		COMTHROW( getFCOI()->get_ReferencedBy( spReferences.Addr() ) );
		MGACOLL_ITERATE( IMgaFCO, spReferences.p ) {
			CComQIPtr<IMgaReference> spReference = MGACOLL_ITER;
			setSPReferences.insert( spReference.p );
		} MGACOLL_ITERATE_END;
	}

	void FCOImpl::getReferences( const MON::Reference& meta, std::set<ReferencePtr>& setSPReferences, bool bErase )
	{
		std::set<ReferencePtr>::iterator it = setSPReferences.begin();
		while ( it != setSPReferences.end() ) {
			std::set<ReferencePtr>::iterator itSaved = it;
			it++;
			if ( _getMetaRef( *itSaved ) == meta.ref() ) {
				ReferenceImpl* pReference = ReferenceImpl::attachI( *itSaved, ObjectImpl::m_pProject, meta );
				if ( m_references[ meta ].second.find( pReference ) == m_references[ meta ].second.end() ) {
					m_references[ meta ].second.insert( pReference );
					pReference->onRetrievedAsReference( this, false );
				}
				if ( bErase )
					setSPReferences.erase( itSaved );
			}
		}
	}

	ReferenceSet FCOImpl::getReferencesI( const MON::Reference& meta )
	{
		// If Containment specified
		if ( meta ) {
			if ( ! isReferencesRetrieved( meta ) ) {
				std::set<ReferencePtr> setSPReferences;
				getReferences( setSPReferences );
				getReferences( meta, setSPReferences, false );
			}
			return m_references[ meta ].second;
		}

		// If meta is not specified
		if ( ! m_bAllReferences ) {
			m_bAllReferences = true;
			std::set<ReferencePtr> setSPReferences;
			getReferences( setSPReferences );
			std::set<MON::Reference> setRefs = getFCOMeta().referencedBy();
			for ( std::set<MON::Reference>::iterator it = setRefs.begin() ; it != setRefs.end() ; it++ ) {
				if ( ! isReferencesRetrieved( *it ) )
					getReferences( *it, setSPReferences, true );
			}
		}

		// Create the Huge Set
		ReferenceSet setReferences;
		for ( ManyReferenceLink::iterator it = m_references.begin() ; it != m_references.end() ; it++ )
			setReferences.insert( it->second.second.begin(), it->second.second.end() );
		return setReferences;
	}

	FCOImpl* FCOImpl::getType()
	{
		if ( m_bAllTypeFCOs )
			return m_pType;
		m_bAllTypeFCOs = true;
		FCOPtr spFCO;
		COMTHROW( getFCOI()->get_DerivedFrom( spFCO.Addr() ) );
		if ( spFCO ) {
			m_pType = FCOImpl::attachI( spFCO, ObjectImpl::m_pProject, getObjectMeta() );
			m_pType->onRetrievedAsType( this, false );
		}
		return m_pType;
	}

	FCOSet FCOImpl::getDerivedFCOs( bool bInstance )
	{
		if ( bInstance && ! m_bAllInstanceFCOs || ! bInstance && ! m_bAllSubTypeFCOs ) {
			Util::ComPtr<IMgaFCOs> spFCOs;
			COMTHROW( getFCOI()->get_DerivedObjects( spFCOs.Addr() ) );
			MGACOLL_ITERATE( IMgaFCO, spFCOs.p ) {
				VARIANT_BOOL vbInstance;
				COMTHROW( MGACOLL_ITER->get_IsInstance( &vbInstance ) );
				if ( bInstance && vbInstance || ! bInstance && ! vbInstance ) {
					FCOImpl* pFCO = FCOImpl::attachI( MGACOLL_ITER, ObjectImpl::m_pProject, getObjectMeta() );
					if ( bInstance )
						m_setInstances.insert( pFCO );
					else
						m_setSubTypes.insert( pFCO );
					pFCO->onRetrievedAsDerived( this, false );
				}
			} MGACOLL_ITERATE_END;
		}
		if ( bInstance )
			m_bAllInstanceFCOs = true;
		else
			m_bAllSubTypeFCOs = true;
		return ( bInstance ) ? m_setInstances : m_setSubTypes;
	}

//===============================================================================================================================================
// 	C L A S S : BON::FCOImpl					// Event Handlers

	bool FCOImpl::onRetrievedAsType( FCOImpl* pFCO, bool bCheckAll )
	{
		if ( pFCO->isInstance() ) {
			if ( bCheckAll && ! m_bAllInstanceFCOs )
				return false;
			m_setInstances.insert( pFCO );
			return true;
		}
		else {
			if ( bCheckAll && ! m_bAllSubTypeFCOs )
				return false;
			m_setSubTypes.insert( pFCO );
			return true;
		}
	}

	void FCOImpl::onReleasedAsType( FCOImpl* pFCO, bool bOnlyFreeMemory )
	{
		if ( pFCO->isInstance() ) {
			m_setInstances.erase( pFCO );
			if ( bOnlyFreeMemory )
				m_bAllInstanceFCOs = false;
		}
		else {
			m_setSubTypes.erase( pFCO );
			if ( bOnlyFreeMemory )
				m_bAllSubTypeFCOs = false;
		}
	}

	bool FCOImpl::onRetrievedAsDerived( FCOImpl* pFCO, bool bCheckAll )
	{
		m_bAllTypeFCOs = true;
		m_pType = pFCO;
		return true;
	}

	void FCOImpl::onReleasedAsDerived( FCOImpl* pFCO, bool bOnlyFreeMemory )
	{
		m_bAllTypeFCOs = false;
		m_pType = NULL;
	}

	bool FCOImpl::onRetrievedAsModelChild( ModelImpl* pModel, bool bCheckAll )
	{
		m_bAllParentModels = true;
		m_parentModel.first = pModel->getModelMeta();
		m_parentModel.second = pModel;
		return true;
	}

	void FCOImpl::onReleasedAsModelChild( ModelImpl* pFolder, bool bOnlyFreeMemory )
	{
		m_bAllParentModels = false;
		m_parentModel.first = MON::Model();
		m_parentModel.second = NULL;
	}

	bool FCOImpl::onRetrievedAsMember( SetImpl* pSet, bool bCheckAll )
	{
		ManySetLink::iterator it = m_sets.find( pSet->getSetMeta() );
		if ( it == m_sets.end() ) {
			if ( bCheckAll )
				return false;
			m_sets[ pSet->getSetMeta() ] = SetSetPair( false, SetSet() );
		}
		if ( ! bCheckAll || bCheckAll && m_sets[ pSet->getSetMeta() ].first ) {
			m_sets[ pSet->getSetMeta() ].second.insert( pSet );
			return true;
		}
		return false;
	}

	void FCOImpl::onReleasedAsMember( SetImpl* pSet, bool bOnlyFreeMemory )
	{
		ManySetLink::iterator it = m_sets.find( pSet->getSetMeta() );
		if ( it != m_sets.end() ) {
			m_sets[ pSet->getSetMeta() ].second.erase( pSet );
			if ( bOnlyFreeMemory && m_sets[ pSet->getSetMeta() ].first ) {
				m_sets[ pSet->getSetMeta() ].first = false;
				m_bAllSets = false;
			}
		}
	}

	bool FCOImpl::onRetrievedAsReferred( ReferenceImpl* pReference, bool bCheckAll )
	{
		ManyReferenceLink::iterator it = m_references.find( pReference->getReferenceMeta() );
		if ( it == m_references.end() ) {
			if ( bCheckAll )
				return false;
			m_references[ pReference->getReferenceMeta() ] = ReferenceSetPair( false, ReferenceSet() );
		}
		if ( ! bCheckAll || bCheckAll && m_references[ pReference->getReferenceMeta() ].first ) {
			m_references[ pReference->getReferenceMeta() ].second.insert( pReference );
			return true;
		}
		return false;
	}

	void FCOImpl::onReleasedAsReferred( ReferenceImpl* pReference, bool bOnlyFreeMemory )
	{
		ManyReferenceLink::iterator it = m_references.find( pReference->getReferenceMeta() );
		if ( it != m_references.end() ) {
			m_references[ pReference->getReferenceMeta() ].second.erase( pReference );
			if ( bOnlyFreeMemory && m_references[ pReference->getReferenceMeta() ].first ) {
				m_references[ pReference->getReferenceMeta() ].first = false;
				m_bAllReferences = false;
			}
		}
	}

	bool FCOImpl::onRetrievedAsReferencePort( ReferencePortImpl* pPort, bool bCheckAll )
	{
		if ( bCheckAll && ! m_bAllRefPorts )
			return false;
		m_refPorts.insert( pPort );
		return true;
	}

	void FCOImpl::onReleasedAsReferencePort( ReferencePortImpl* pPort, bool bOnlyFreeMemory )
	{
		m_refPorts.erase( pPort );
		if ( bOnlyFreeMemory )
			m_bAllRefPorts = false;
	}

	void FCOImpl::eventPerformedI( const Event& event )
	{
		ObjectImpl::eventPerformedI( event );
		switch ( event.getType() ) {
			case MON::OET_ObjectCreated :
				onObjectCreated();
				break;
			case MON::OET_DescendantCreated :
				onObjectDerived( NULL );
				break;
			case MON::OET_ObjectMoved :
				onObjectMoved( NULL, NULL );
				break;
			case MON::OET_ObjectReferenced :
				onFCOReferenced( NULL );
				break;
			case MON::OET_ObjectReleased :
				onFCOUnreferenced( NULL );
				break;
			case MON::OET_ObjectIncluded :
				onFCOIncluded( NULL );
				break;
			case MON::OET_ObjectExcluded :
				onFCOExcluded( NULL );
				break;
		}
	}

	void FCOImpl::onObjectCreated()
	{
		FCO( this->getType() );
		try {
			std::set<ReferencePort> rps = getReferencePorts();
			for( std::set<ReferencePort>::const_iterator it = rps.begin(); it != rps.end(); ++it)
			{
				Reference ref = (*it)->getContainer()->getReference();
				m_storedRefWrappers.insert( ref);
			}
			rps.clear();
			// exception when releasing the set?
		} catch(...) {
			bool b = true;
			b = !b;
			ASSERT(0);
		}

		// Temporary Solution ... Eliminate If Event Paremeters Available
		ObjectPtr spObject;
		COMTHROW( getObjectI()->GetParent( spObject.Addr() ) );
		Model model( ObjectImpl::attachI( spObject, (ProjectImpl*) getProject().getCounted() ) );
		if ( model )
			model->onChildAdded( this );
		// Temporary Solution END
	}

	void FCOImpl::onObjectDerived( FCOImpl* pFCO )
	{
		if ( ! _isAddOn() ) {
			if ( pFCO ) {
				if ( onRetrievedAsType( pFCO, true ) )
					pFCO->onRetrievedAsDerived( this, false );
			}
			else {
				m_bAllSubTypeFCOs = false;
				m_bAllInstanceFCOs = false;
			}
		}
	}

	void FCOImpl::onObjectMoved( ObjectImpl* pOldParent, ObjectImpl* pNewParent )
	{
		if ( pOldParent && pNewParent ) {
			if ( pOldParent->getStereotype() == OT_Model )
				dynamic_cast<ModelImpl*>( pOldParent )->onChildRemoved( this );
			if ( pNewParent->getStereotype() == OT_Model )
				dynamic_cast<ModelImpl*>( pNewParent )->onChildAdded( this );
			return;
		}
	}

	void FCOImpl::onFCOReferenced( ReferenceImpl* pReference )
	{
		if ( pReference ) {
			if ( onRetrievedAsReferred( pReference, true ) )
				pReference->onRetrievedAsReference( this, false );
			return;
		}
	}

	void FCOImpl::onFCOUnreferenced( ReferenceImpl* pReference )
	{
		if ( pReference ) {
			onReleasedAsReferred( pReference, false );
			pReference->onReleasedAsReference( this, false );
			return;
		}
	}

	void FCOImpl::onFCOIncluded( SetImpl* pSet )
	{
		if ( pSet ) {
			if ( onRetrievedAsMember( pSet, true ) )
				pSet->onRetrievedAsSet( this, false );
			return;
		}
	}

	void FCOImpl::onFCOExcluded( SetImpl* pSet )
	{
		if ( pSet ) {
			onReleasedAsMember( pSet, false );
			pSet->onReleasedAsSet( this, false );
			return;
		}
	}

//===============================================================================================================================================
// 	C L A S S : BON::FCOImpl					// Relations // ---> Interface Methods

	TypeInhObject FCOImpl::getTypeInhObject() const
	{
		return m_pTIObject;
	}

	Object FCOImpl::getParent()
	{
		Object object = ObjectImpl::getParent();
		if ( object )
			return object;
		return getParentModel();
	}

	std::set<ReferencePort> FCOImpl::getReferencePorts( const MON::Aspect& meta )
	{
		if ( meta )
			THROW_METAPROJECT_BELONG( meta );

		std::set<ReferencePort>	setResult;
		Model parent = getParentModel();
		if ( ! parent )
			return setResult;

		if ( meta ) {
			THROW_METAPROJECT_BELONG( meta );
			if ( ! parent->getModelMeta().hasAspect( meta ) || ! getRole().isVisibleIn( meta ) )
				return setResult;
		}

		setCopy<ReferencePort,ReferencePortImpl>( getRefPortRefsI(), setResult );

		if ( meta ) {
			std::set<ReferencePort>::iterator it2 = setResult.begin();
			while ( it2 != setResult.end() ) {
				std::set<ReferencePort>::iterator itSaved = it2;
				it2++;
				MON::Containment role = (*itSaved)->getContainer()->getReference()->getRole();
				if ( role && ! role.isVisibleIn( meta ) )
					setResult.erase( itSaved );
			}
		}

		return setResult;
	}

	Model FCOImpl::getParentModel( const MON::Model& meta )
	{
		if ( meta ) {
			THROW_METAPROJECT_BELONG( meta );
			if ( ! getFCOMeta().isModelParent( meta ) )
			{
				MON::Exception exc( "? cannot be parent of ?!");
				exc << meta.infoString() << getObjectMeta().infoString(); 
				ASSERTTHROW( exc);
			}
		}
		return getParentModelI( meta );
	}

	Model FCOImpl::getParentModel( const std::string& strModel )
	{
		MON::Model meta;
		if ( ! strModel.empty() ) {
			meta = MON::Model( getProject()->getProjectMeta().findByName( strModel ) );
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, Model, strModel );
		}
		return getParentModel( meta );
	}

	Model FCOImpl::getParentModelAs( const std::string& strRole )
	{
		if ( strRole.empty() )
			return getParentModel();

		MON::Containment role;
		std::set<MON::Containment> roles = getFCOMeta().parentContainments();
		for ( std::set<MON::Containment>::iterator it = roles.begin() ; it != roles.end() ; it++ )
			if ( it->name() == strRole ) {
				role = *it;
				break;
			}

		if ( ! role )
		{
			MON::Exception exc( "? cannot be child in MON::Model with containment role of ?!");
			exc << getObjectMeta().infoString() << strRole; 
			ASSERTTHROW( exc);
		}

		ModelImpl* pModel = getParentModelI( role.child() );
		return ( pModel && pModel->getRole() == role ) ? pModel : NULL;
	}

	std::set<Set>	FCOImpl::getMemberOf( const MON::Set& meta, const MON::Aspect& aspect )
	{
		if ( aspect )
			THROW_METAPROJECT_BELONG( aspect );

		if ( meta ) {
			THROW_METAPROJECT_BELONG( meta );
			if ( ! getFCOMeta().isMemberOf( meta ) )
			{
				MON::Exception exc( "? cannot be member of ?!");
				exc << getObjectMeta().infoString() << meta.infoString();
				ASSERTTHROW( exc);
			}
		}
		std::set<Set>	 setResult;
		setCopy<Set,SetImpl>( getSetsI( meta ), setResult );
		return filterByAspect<Set>( setResult, aspect );
	}

	std::set<Set> FCOImpl::getMemberOf( const std::string& strSet, const MON::Aspect& aspect )
	{
		MON::Set meta;
		if ( ! strSet.empty() ) {
			meta = MON::Set( getProject()->getProjectMeta().findByName( strSet ) );
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, Set, strSet );
		}
		return getMemberOf( meta, aspect );
	}

	std::set<Reference> FCOImpl::getReferredBy( const MON::Reference& meta )
	{
		if ( meta ) {
			THROW_METAPROJECT_BELONG( meta );
			if ( ! getFCOMeta().isReferencedBy( meta ) )
			{
				MON::Exception exc( "? cannot be referenced by ?!");
				exc << getObjectMeta().infoString() << meta.infoString();
				ASSERTTHROW( exc);
			}
		}
		std::set<Reference> setResult;
		setCopy<Reference,ReferenceImpl>( getReferencesI( meta ), setResult );
		return setResult;
	}

	std::set<Reference> FCOImpl::getReferredBy( const std::string& strReference )
	{
		MON::Reference meta;
		if ( ! strReference.empty() ) {
			meta = MON::Reference( getProject()->getProjectMeta().findByName( strReference ) );
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, Reference, strReference );
		}
		return getReferredBy( meta );
	}

	std::set<Attribute> FCOImpl::getAttributes()
	{
		std::set<Attribute> attributes;
		std::set<MON::Attribute> metaattributes = getFCOMeta().attributes();
		for ( std::set<MON::Attribute>::iterator it = metaattributes.begin() ; it != metaattributes.end() ; it++ )
			attributes.insert( getAttributeI( *it ) );
		return attributes;
	}

	Attribute FCOImpl::getAttribute( const MON::Attribute& meta )
	{
		THROW_CANNOT_BE_NULL( meta, "MON::Attribute" );
		THROW_METAPROJECT_BELONG( meta );

		std::set<MON::Attribute> attributes = getFCOMeta().attributes();
		if ( attributes.find( meta ) == attributes.end() )
		{
			MON::Exception exc( "? is not associated with ?!");
			exc << meta.infoString() << getObjectMeta().infoString();
			ASSERTTHROW( exc);
		}

		return getAttributeI( meta );
	}

	Attribute FCOImpl::getAttribute( const std::string& strName )
	{
		MON::Attribute meta;
		if ( ! strName.empty() ) {
			std::set<MON::Attribute> attributes = getFCOMeta().attributes();
			for ( std::set<MON::Attribute>::iterator it = attributes.begin() ; it != attributes.end() ; it++ )
				if ( it->name() == strName )
					return getAttributeI( *it );
		}
		return NULL;
	}

	FCO FCOImpl::copy( const Folder& parent )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		THROW_PROJECT_BELONG( parent );

		if ( ! parent->getFolderMeta().isObjectChild( getObjectMeta() ) )
		{
			MON::Exception exc( "? cannot be parent of ?!");
			exc << parent->getObjectMeta().infoString() << getObjectMeta().infoString();
			ASSERTTHROW( exc);
		}

		FCOsPtr spInSet;
		FCOsPtr spOutSet;
		COMTHROW( spInSet.CoCreateInstance( L"Mga.MgaFCOs" ) );		// CHANGED LINE
		COMTHROW( spInSet->Append( getFCOI() ) ); 	
		FCOPtr spFCO;
		COMTHROW( parent->getFolderI()->CopyFCOs( spInSet, spOutSet.Addr() ) );     // CHANGED LINE
		COMTHROW( spOutSet->get_Item( 1, spFCO.Addr() ) );
		FCOImpl* pFCO = FCOImpl::attachI( spFCO, (ProjectImpl*) getProject().getCounted(), getObjectMeta() );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
		if ( ! _isAddOn() ) {
			pFCO->eventPerformedI( Event( MON::OET_ObjectCreated, pFCO ) );
			eventPerformedI( Event( MON::OET_DescendantCreated, pFCO ) );
		}
		return pFCO;
	}

	FCO FCOImpl::move( const Folder& parent )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		THROW_PROJECT_BELONG( parent );

		if ( getParent() == parent )
			return this;

		if ( ! parent->getFolderMeta().isObjectChild( getObjectMeta() ) )
		{
			MON::Exception exc( "? cannot be parent of ?!");
			exc << parent->getObjectMeta().infoString() << getObjectMeta().infoString();
			ASSERTTHROW( exc);
		}

		Model m = getParent();
		Folder f = getParent();
		if ( m )
			m->onChildRemoved( this );
		else if ( f )
			f->onChildRemoved( this );

		FCOsPtr spInSet;
		FCOsPtr spOutSet;
		COMTHROW( spInSet.CoCreateInstance( L"Mga.MgaFCOs" ) );		// CHANGED LINE
		COMTHROW( spInSet->Append( getFCOI() ) ); 	
		
		COMTHROW( parent->getFolderI()->MoveFCOs( spInSet, spOutSet.Addr() ) );
		FCOPtr spFCO;
		COMTHROW( spOutSet->get_Item( 1, spFCO.Addr() ) );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
		return FCOImpl::attachI( spFCO, (ProjectImpl*) getProject().getCounted(), getObjectMeta() );
	}

	FCO FCOImpl::copy( const Model& parent, const std::string strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		THROW_PROJECT_BELONG( parent );

		MON::Containment role;
		std::set<MON::Containment> roles = parent->getModelMeta().childContainments();
		for ( std::set<MON::Containment>::iterator it = roles.begin() ; it != roles.end() ; it++ )
			if ( it->child() == getObjectMeta() && ( strRole.empty() || strRole == it->name() ) ) {
				if ( role )
				{
					MON::Exception exc( "Role must be specified! ? can consist ? with multiple roles!");
					exc << parent->getObjectMeta().infoString() << getObjectMeta().infoString();
					ASSERTTHROW( exc);
				}
				role = *it;
			}
		if ( ! role ) {
			if ( strRole.empty() )
			{
				MON::Exception exc( "? cannot be parent of ?!");
				exc << parent->getObjectMeta().infoString() << getObjectMeta().infoString();
				ASSERTTHROW( exc);
			}
			MON::Exception exc( "? cannot be parent of ? with role [ ? ]!");
			exc << parent->getObjectMeta().infoString() << getObjectMeta().infoString() << strRole;
			ASSERTTHROW( exc);
		}

		FCOsPtr spInSet;
		COMTHROW( spInSet.CoCreateInstance( L"Mga.MgaFCOs" ) );			// CHANGED LINE
		COMTHROW( spInSet->Append( getFCOI() ) );
		Util::ComPtr<IMgaMetaRoles> spRoles;
		COMTHROW( spRoles.CoCreateInstance( L"Mga.MgaMetaRoles" ) );		// CHANGED LINE
		COMTHROW( spRoles->Append( role.getContainmentI() ) );
		FCOsPtr spOutSet;
		COMTHROW( parent->getModelI()->CopyFCOs( spInSet, spRoles, spOutSet.Addr() ) );
		FCOPtr spFCO;
		COMTHROW( spOutSet->get_Item( 1, spFCO.Addr() ) );

		FCOImpl* pFCO = FCOImpl::attachI( spFCO, (ProjectImpl*) getProject().getCounted(), getObjectMeta() );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
		if ( ! _isAddOn() ) {
			pFCO->eventPerformedI( Event( MON::OET_ObjectCreated, pFCO ) );
			eventPerformedI( Event( MON::OET_DescendantCreated, pFCO ) );
		}
		return pFCO;
	}

	FCO FCOImpl::move( const Model& parent, const std::string strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		THROW_PROJECT_BELONG( parent );

		MON::Containment role;
		std::set<MON::Containment> roles = parent->getModelMeta().childContainments();
		for ( std::set<MON::Containment>::iterator it = roles.begin() ; it != roles.end() ; it++ )
			if ( it->child() == getObjectMeta() && ( strRole.empty() || strRole == it->name() ) ) {
				if ( role )
				{
					MON::Exception exc( "Role must be specified! ? can consist ? with multiple roles!");
					exc << parent->getObjectMeta().infoString() << getObjectMeta().infoString();
					ASSERTTHROW( exc);
				}
				role = *it;
			}
		if ( ! role ) {
			if ( strRole.empty() )
			{
				MON::Exception exc( "? cannot be parent of ?!");
				exc << parent->getObjectMeta().infoString() << getObjectMeta().infoString();
				ASSERTTHROW( exc);
			}
			MON::Exception exc( "? cannot be parent of ? with role [ ? ]!");
			exc << parent->getObjectMeta().infoString() << getObjectMeta().infoString() << strRole;
			ASSERTTHROW( exc);
		}

		if ( getParent() == parent && role == getRole() )
			return this;
		Model m = getParent();
		Folder f = getParent();
		if ( m )
			m->onChildRemoved( this );
		else if ( f )
			f->onChildRemoved( this );

		FCOsPtr spInSet;
		COMTHROW( spInSet.CoCreateInstance( L"Mga.MgaFCOs" ) );			// CHANGED LINE
		COMTHROW( spInSet->Append( getFCOI() ) );
		Util::ComPtr<IMgaMetaRoles> spRoles;
		COMTHROW( spRoles.CoCreateInstance( L"Mga.MgaMetaRoles" ) );		// CHANGED LINE
		COMTHROW( spRoles->Append( role.getContainmentI() ) );
		FCOsPtr spOutSet;
		COMTHROW( parent->getModelI()->MoveFCOs( spInSet, spRoles, spOutSet.Addr() ) );
		FCOPtr spFCO;
		COMTHROW( spOutSet->get_Item( 1, spFCO.Addr() ) );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();

		return FCOImpl::attachI( spFCO, (ProjectImpl*) getProject().getCounted(), getObjectMeta() );
	}

//===============================================================================================================================================
// 	C L A S S : BON::FCOImpl					// Extensions

	void FCOImpl::accept( Visitor* pVisitor )
	{
		switch ( getStereotype() ) {
			case OT_Model :
				dynamic_cast<ModelImpl*>( this )->accept( pVisitor );
				break;
			case OT_Atom :
				dynamic_cast<AtomImpl*>( this )->accept( pVisitor );
				break;
			case OT_Set :
				dynamic_cast<SetImpl*>( this )->accept( pVisitor );
				break;
			case OT_Reference :
				dynamic_cast<ReferenceImpl*>( this )->accept( pVisitor );
				break;
			case OT_Connection :
				dynamic_cast<ConnectionImpl*>( this )->accept( pVisitor );
				break;
		}
	}

	FCORegistryNode FCOImpl::getRegistry() const
	{
		return ObjectImpl::getRegistry();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::AttributeImpl
//
//###############################################################################################################################################

	AttributeImpl::AttributeImpl( IMgaAttribute* spAttribute, FCOImpl* pFCO, const MON::Attribute& meta )
		: Util::GenRefCounted( false, pFCO ), m_spAttribute( spAttribute ), m_pFCO( pFCO ), m_meta( meta )
	{
	}

	AttributeImpl* AttributeImpl::attachI( IMgaAttribute* spAttribute, FCOImpl* pFCO, const MON::Attribute& meta )
	{
		return new AttributeImpl( spAttribute, pFCO, meta );
	}

	AttributeImpl::~AttributeImpl()
	{
		m_pFCO = NULL;
		m_spAttribute = NULL;
		m_meta = NULL;
	}

	bool AttributeImpl::setDeleted()
	{
		return isDeleted();
	}

	void AttributeImpl::checkTypes( const Util::Variant& value, bool bExc ) const
	{
		if ( bExc && ! value.isUndefined() ) {
			switch ( getAttributeMeta().valueType() ) {
				case MON::AT_Boolean :
					if ( value.type() != Util::Variant::VT_Boolean )
					{
						Exception exc( "Type mismatch! ? is typed as Boolean!");
						exc << getAttributeMeta().infoString();
						ASSERTTHROW( exc);
					}
				case MON::AT_String :
					if ( value.type() != Util::Variant::VT_String )
					{
						Exception exc( "Type mismatch! ? is typed as String!");
						exc << getAttributeMeta().infoString();
						ASSERTTHROW( exc);
					}
				case MON::AT_Integer :
					if ( value.type() != Util::Variant::VT_Integer )
					{
						Exception exc( "Type mismatch! ? is typed as Integer!");
						exc << getAttributeMeta().infoString();
						ASSERTTHROW( exc);
					}
				case MON::AT_Real :
					if ( value.type() != Util::Variant::VT_Double )
					{
						Exception exc( "Type mismatch! ? is typed as Real!");
						exc << getAttributeMeta().infoString();
						ASSERTTHROW( exc);
					}
				case MON::AT_Enumeration :
					if ( value.type() != Util::Variant::VT_String )
					{
						Exception exc( "Type mismatch! ? is typed as Enumeration!");
						exc << getAttributeMeta().infoString();
						ASSERTTHROW( exc);
					}
					std::vector<MON::Attribute::NameValue> items = getAttributeMeta().enumItems();
					for ( int i = 0 ; i < items.size() ; i++ )
						if ( items[ i ].first == (std::string) value )
							return;
					Exception exc( "Type mismatch! ? which is typed Enumeration has no Item called ?!");
					exc << getAttributeMeta().infoString() << (std::string) value;
					ASSERTTHROW( exc);
			}
		}
	}

	Util::Variant AttributeImpl::checkTypes( Util::Variant::Type eType, const Util::Variant& value, bool bExc ) const
	{
		if ( bExc && ! value.isUndefined() && eType != value.type() ) {
			std::string strType;
			switch ( getAttributeMeta().valueType() ) {
				case MON::AT_Boolean :
					strType = "Boolean"; break;
				case MON::AT_String :
					strType = "String"; break;
				case MON::AT_Integer :
					strType = "Integer"; break;
				case MON::AT_Real :
					strType = "Real"; break;
				case MON::AT_Enumeration :
					strType = "Enumeration"; break;
			}
			Exception exc( "Type mismatch! ? is typed as ?!");
			exc << getAttributeMeta().infoString() << strType;
			ASSERTTHROW( exc);
		}
		return value;
	}

//===============================================================================================================================================
// 	C L A S S : BON::AttributeImpl					// Get and Set Operations // ---> Interface Methods

	Project AttributeImpl::getProject() const
	{
		return m_pFCO->getProject();
	}

	FCO AttributeImpl::getFCO() const
	{
		return m_pFCO;
	}

	AttributePtr AttributeImpl::getAttributeI() const
	{
		return m_spAttribute;
	}

	const MON::Attribute& AttributeImpl::getAttributeMeta() const
	{
		return m_meta;
	}

	AttributeStatus AttributeImpl::getStatus() const
	{
		long lStatus;
		COMTHROW( m_spAttribute->get_Status( &lStatus ) );
		return lStatus;
	}

	Util::Variant AttributeImpl::getValue() const
	{
		CComVariant objValue;
		COMTHROW( m_spAttribute->get_Value( &objValue ) );
		if ( objValue.vt == VT_EMPTY || objValue.vt == VT_ERROR ) // || objValue.vt )
			return Util::Variant();

		switch ( m_meta.valueType() ) {
			case MON::AT_Boolean :
				return objValue.boolVal == VARIANT_TRUE;
			case MON::AT_Integer :
				return objValue.lVal;
			case MON::AT_Real :
				return objValue.dblVal;
			case MON::AT_String :
			case MON::AT_Enumeration :
				return Util::Copy( CComBSTR( objValue.bstrVal ) );
		}
		ASSERTTHROW( Util::Exception( "Invalid control path!" ) );
	}

	void AttributeImpl::setValue( const Util::Variant& value, bool bTypeTolerant )
	{
		checkTypes( value, ! bTypeTolerant );
		if ( value.isUndefined() ) {
			COMTHROW( m_spAttribute->Clear() );
		}
		else {
			switch ( m_meta.valueType() ) {
				case MON::AT_Boolean :
					COMTHROW( m_spAttribute->put_BoolValue( (bool) value ) );
					break;
				case MON::AT_Integer :
					COMTHROW( m_spAttribute->put_IntValue( (long) value ) );
					break;
				case MON::AT_Real :
					COMTHROW( m_spAttribute->put_FloatValue( (double) value ) );
					break;
				case MON::AT_String :
				case MON::AT_Enumeration :
					COMTHROW( m_spAttribute->put_StringValue( Util::Copy( (std::string) value ) ) );
					break;
			}
		}
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
	}

	long AttributeImpl::getIntegerValue( bool bTypeTolerant ) const
	{
		return (long) checkTypes( Util::Variant::VT_Integer, getValue(), ! bTypeTolerant );
	}

	void AttributeImpl::setIntegerValue( long lValue, bool bTypeTolerant )
	{
		checkTypes( Util::Variant( lValue ), ! bTypeTolerant );
		setValue( Util::Variant( lValue ) );
	}

	bool AttributeImpl::getBooleanValue( bool bTypeTolerant ) const
	{
		return (bool) checkTypes( Util::Variant::VT_Boolean, getValue(), ! bTypeTolerant );
	}

	void AttributeImpl::setBooleanValue( bool bValue, bool bTypeTolerant )
	{
		checkTypes( Util::Variant( bValue ), ! bTypeTolerant );
		setValue( Util::Variant( bValue ) );
	}

	double AttributeImpl::getRealValue( bool bTypeTolerant ) const
	{
		return (double) checkTypes( Util::Variant::VT_Double, getValue(), ! bTypeTolerant );
	}

	void AttributeImpl::setRealValue( double dValue, bool bTypeTolerant )
	{
		checkTypes( Util::Variant( dValue ), ! bTypeTolerant );
		setValue( Util::Variant( dValue ) );
	}

	std::string AttributeImpl::getStringValue( bool bTypeTolerant ) const
	{
		return (std::string) checkTypes( Util::Variant::VT_String, getValue(), ! bTypeTolerant );
	}

	void AttributeImpl::setStringValue( const std::string& strValue, bool bTypeTolerant )
	{
		checkTypes( Util::Variant( strValue ), ! bTypeTolerant );
		setValue( Util::Variant( strValue ) );
	}

	bool AttributeImpl::isUndefined() const
	{
		return getValue().isUndefined();
	}

	void AttributeImpl::clear()
	{
		setValue( Util::Variant() );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::AtomImpl
//
//###############################################################################################################################################

	AtomImpl::AtomImpl()
		: FCOImpl()
	{
	}

	AtomImpl* AtomImpl::attachI( IMgaAtom* spAtom, ProjectImpl* pProject, const MON::Object& meta )
	{
		// Warning : Maybe it is an Exception
		if ( ! spAtom )
			return NULL;

		// Find it in Objects' cache
		pProject = _getProject( spAtom, pProject );
		ObjectImpl* pObject = find( pProject, spAtom );
		if ( pObject )
			return dynamic_cast<AtomImpl*>( pObject );

		// Get Extension
		pObject = getEx( spAtom, OT_Atom, meta );
		if ( ! pObject )
			pObject = new AtomImpl();
		pObject->doInitialize( spAtom, pProject, meta );
		dynamic_cast<FCOImpl*>( pObject )->doInitialize( pProject );
		pObject->initialize();

		AtomImpl* ai = dynamic_cast<AtomImpl*>( pObject );
		attachIPost( ai);
		return ai;
	}

	Atom AtomImpl::attach( IMgaAtom* spAtom )
	{
		return attachI( spAtom );
	}

	Atom AtomImpl::create( const Folder& parent, const MON::Atom& meta )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		return parent->createChildObjectI( meta, MON::OT_Atom );
	}

	Atom AtomImpl::create( const Folder& parent, const std::string& strAtom )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		MON::Atom meta;
		if ( ! strAtom.empty() ) {
			meta = parent->getProject()->getProjectMeta().findByName( strAtom );
			if ( ! meta )
			{
				MON::Exception exc( "MON::Atom [ ? ] does not exist in ? of ?!");
				exc << strAtom << parent->getProject()->getProjectMeta().infoString() << parent->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}
		}
		return create( parent, meta );
	}

	Atom AtomImpl::create( const Folder& parent, const Atom& baseType, bool bAsInstance )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		return dynamic_cast<AtomImpl*>( parent->createChildFCOI( baseType, bAsInstance, MON::OT_Atom ) );
	}

	Atom AtomImpl::create( const Model& parent, const MON::Atom& meta, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<AtomImpl*>( parent->createChildFCOI( meta, strRole, MON::OT_Atom ) );
	}

	Atom AtomImpl::create( const Model& parent, const std::string& strAtom, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		MON::Atom meta;
		if ( ! strAtom.empty() ) {
			meta = parent->getProject()->getProjectMeta().findByName( strAtom );
			if ( ! meta )
			{
				MON::Exception exc( "MON::Atom [ ? ] does not exist in ? of ?!");
				exc << strAtom << parent->getProject()->getProjectMeta().infoString() << parent->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}
		}
		return create( parent, meta, strRole );
	}

	Atom AtomImpl::create( const Model& parent, const Atom& baseType, bool bAsInstance, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<AtomImpl*>( parent->createChildFCOI( baseType, bAsInstance, strRole, MON::OT_Atom ) );
	}

	Atom AtomImpl::createAs( const Model& parent, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<AtomImpl*>( parent->createChildFCOI( strRole, MON::OT_Atom ) );
	}

	AtomImpl::~AtomImpl()
	{
	}

//===============================================================================================================================================
// 	C L A S S : BON::AtomImpl					// Get and Set Operations // ---> Interface Methods

	ObjectType AtomImpl::getStereotype() const
	{
		return OT_Atom;
	}

	AtomPtr AtomImpl::getAtomI() const
	{
		CComQIPtr<IMgaAtom> spAtom = getObjectI().p;
		return spAtom.p;
	}

	MON::Atom AtomImpl::getAtomMeta() const
	{
		return getObjectMeta();
	}

	std::string AtomImpl::getInfoString( unsigned short usOptions ) const
	{
		bool bAll = ( usOptions & Util::IO_All ) ? true : false;
		bool bLine = bAll || ( usOptions & Util::IO_NewLine );

		std::string strInfo = getInfoStringHelper( usOptions, "Atom" );
		if ( ! ( usOptions & Util::IO_NewLine ) && ! ( usOptions & Util::IO_All ) )
			strInfo += "]";

		return strInfo;
	}

//===============================================================================================================================================
// 	C L A S S : BON::AtomImpl					// Extensions

	void AtomImpl::accept( Visitor* pVisitor )
	{
		pVisitor->visitAtom( Atom( this ) );
	}

	FCOExRegistryNode AtomImpl::getRegistry() const
	{
		return FCOImpl::getRegistry();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ModelImpl
//
//###############################################################################################################################################

	ModelImpl::ModelImpl()
		: FCOImpl(), m_bAllChildFCOs( false )
	{
	}

	ModelImpl* ModelImpl::attachI( IMgaModel* spModel, ProjectImpl* pProject, const MON::Object& meta )
	{
		// Warning : Maybe it is an Exception
		if ( ! spModel )
			return NULL;

		// Find it in Objects' cache
		pProject = _getProject( spModel, pProject );
		ObjectImpl* pObject = find( pProject, spModel );
		if ( pObject )
			return dynamic_cast<ModelImpl*>( pObject );

		// Get Extension
		pObject = getEx( spModel, OT_Model, meta );
		if ( ! pObject )
			pObject = new ModelImpl();
		pObject->doInitialize( spModel, pProject, meta );
		dynamic_cast<FCOImpl*>( pObject )->doInitialize( pProject );
		pObject->initialize();
		
		ModelImpl* mi = dynamic_cast<ModelImpl*>( pObject );
		attachIPost( mi);
		return mi;
	}

	Model ModelImpl::attach( IMgaModel* spModel )
	{
		return attachI( spModel );
	}

	Model ModelImpl::create( const Folder& parent, const MON::Model& meta )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		return parent->createChildObjectI( meta, MON::OT_Model );
	}

	Model ModelImpl::create( const Folder& parent, const std::string& strModel )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		MON::Model meta;
		if ( ! strModel.empty() ) {
			meta = parent->getProject()->getProjectMeta().findByName( strModel );
			if ( ! meta )
			{
				MON::Exception exc( "MON::Model [ ? ] does not exist in ? of ?!");
				exc << strModel << parent->getProject()->getProjectMeta().infoString() << parent->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}
		}
		return create( parent, meta );
	}

	Model ModelImpl::create( const Folder& parent, const Model& baseType, bool bAsInstance )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		return dynamic_cast<ModelImpl*>( parent->createChildFCOI( baseType, bAsInstance, MON::OT_Model ) );
	}

	Model ModelImpl::create( const Model& parent, const MON::Model& meta, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<ModelImpl*>( parent->createChildFCOI( meta, strRole, MON::OT_Model ) );
	}

	Model ModelImpl::create( const Model& parent, const std::string& strModel, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		MON::Model meta;
		if ( ! strModel.empty() ) {
			meta = parent->getProject()->getProjectMeta().findByName( strModel );
			if ( ! meta )
			{
				MON::Exception exc( "MON::Model [ ? ] does not exist in ? of ?!");
				exc << strModel << parent->getProject()->getProjectMeta().infoString() << parent->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}
		}
		return create( parent, meta, strRole );
	}

	Model ModelImpl::create( const Model& parent, const Model& baseType, bool bAsInstance, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<ModelImpl*>( parent->createChildFCOI( baseType, bAsInstance, strRole, MON::OT_Model ) );
	}

	Model ModelImpl::createAs( const Model& parent, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<ModelImpl*>( parent->createChildFCOI( strRole, MON::OT_Model ) );
	}

	ModelImpl::~ModelImpl()
	{
		if ( ! ObjectImpl::m_pProject->isDestructionActive() && ! isDeleted() ) {
			for ( ManyFCOLink::iterator it1 = m_childFCOs.begin() ; it1 != m_childFCOs.end() ; it1++ )
				for ( FCOSet::iterator it2 = it1->second.second.begin() ; it2 != it1->second.second.end() ; it2++ )
					(*it2)->onReleasedAsModelChild( this, true );
		}
		m_childFCOs.clear();
	}

	bool ModelImpl::setDeleted()
	{
		if ( FCOImpl::setDeleted() )
			return true;
		if ( ! _isAddOn() ) {
			for ( ManyFCOLink::iterator it1 = m_childFCOs.begin() ; it1 != m_childFCOs.end() ; it1++ )
				for ( FCOSet::iterator it2 = it1->second.second.begin() ; it2 != it1->second.second.end() ; it2++ )
					(*it2)->onReleasedAsModelChild( this, true );
		}
		return false;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ModelImpl					// Get and Set Operations // ---> Interface Methods

	ObjectType ModelImpl::getStereotype() const
	{
		return OT_Model;
	}

	ModelPtr ModelImpl::getModelI() const
	{
		CComQIPtr<IMgaModel> spModel = getObjectI().p;
		return spModel.p;
	}

	MON::Model ModelImpl::getModelMeta() const
	{
		return getObjectMeta();
	}

	std::string ModelImpl::getInfoString( unsigned short usOptions ) const
	{
		bool bAll = ( usOptions & Util::IO_All ) ? true : false;
		bool bLine = bAll || ( usOptions & Util::IO_NewLine );

		std::string strInfo = getInfoStringHelper( usOptions, "Model" );
		if ( ! ( usOptions & Util::IO_NewLine ) && ! ( usOptions & Util::IO_All ) )
			strInfo += "]";

		return strInfo;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ModelImpl					// Relations

	bool ModelImpl::isChildFCOsRetrieved( const MON::FCO& meta )
	{
		ManyFCOLink::iterator it = m_childFCOs.find( meta );
		if ( it != m_childFCOs.end() ) {
			if ( it->second.first )
				return true;
			it->second.first = true;
			return false;
		}
		m_childFCOs[ meta ] = FCOSetPair( true, FCOSet() );
		return false;
	}

	void ModelImpl::getChildFCOs( std::set<FCOPtr>& setSPFCOs )
	{
		Util::ComPtr<IMgaFCOs> spFCOs;
		COMTHROW( getModelI()->get_ChildFCOs( spFCOs.Addr() ) );
		MGACOLL_ITERATE( IMgaFCO, spFCOs.p ) {
			setSPFCOs.insert( MGACOLL_ITER );
		} MGACOLL_ITERATE_END;
	}

	void ModelImpl::getChildFCOs( const MON::FCO& meta, std::set<FCOPtr>& setSPFCOs, bool bErase )
	{
		std::set<FCOPtr>::iterator it = setSPFCOs.begin();
		while ( it != setSPFCOs.end() ) {
			std::set<FCOPtr>::iterator itSaved = it;
			it++;
			if ( _getMetaRef( *itSaved ) == meta.ref() ) {
				FCOImpl* pFCO = FCOImpl::attachI( *itSaved, ObjectImpl::m_pProject, meta );
				if ( m_childFCOs[ meta ].second.find( pFCO ) == m_childFCOs[ meta ].second.end() ) {
					m_childFCOs[ meta ].second.insert( pFCO );
					pFCO->onRetrievedAsModelChild( this, false );
				}
				if ( bErase )
					setSPFCOs.erase( itSaved );
			}
		}
	}

	FCOSet ModelImpl::getChildFCOsI( const MON::FCO& meta )
	{
		// If Containment specified
		if ( meta ) {
			if ( ! isChildFCOsRetrieved( meta ) ) {
				std::set<FCOPtr> setSPFCOs;
				getChildFCOs( setSPFCOs );
				getChildFCOs( meta, setSPFCOs, false );
			}
			return m_childFCOs[ meta ].second;
		}

		// If Containment is not specified
		if ( ! m_bAllChildFCOs ) {
			m_bAllChildFCOs = true;
			std::set<FCOPtr> setSPFCOs;
			getChildFCOs( setSPFCOs );
			std::set<MON::FCO> setFCOs = getModelMeta().childFCOs();
			for ( std::set<MON::FCO>::iterator it = setFCOs.begin() ; it != setFCOs.end() ; it++ ) {
				if ( ! isChildFCOsRetrieved( *it ) )
					getChildFCOs( *it, setSPFCOs, true );
			}
		}

		// Create the Huge Set
		FCOSet setFCOs;
		for ( ManyFCOLink::iterator it = m_childFCOs.begin() ; it != m_childFCOs.end() ; it++ )
			setFCOs.insert( it->second.second.begin(), it->second.second.end() );
		return setFCOs;
	}

	FCOImpl* ModelImpl::createChildFCOI( const std::string& strRole, MON::ObjectType eType )
	{
		MON::Containment role;
		std::set<MON::Containment> metas = getModelMeta().childContainments();
		if ( strRole.empty() ) {
			for ( std::set<MON::Containment>::iterator it = metas.begin() ; it != metas.end() ; it++ ) {
				if ( it->child().type() == eType ) {
					if ( role )
					{
						MON::Exception exc( "strRole cannot be an empty string because ? can contain more than one MON::Containment with child ?!");
						exc << getObjectMeta().infoString() << toString( eType );
						ASSERTTHROW( exc);
					}
					role = *it;
				}
			}
			if ( ! role )
			{
				MON::Exception exc( "? does not have ? as child!");
				exc << getObjectMeta().infoString() << toString( eType );
				ASSERTTHROW( exc);
			}
		}
		else {
			for ( std::set<MON::Containment>::iterator it = metas.begin() ; it != metas.end() ; it++ ) {
				if ( it->name() == strRole && it->child().type() == eType ) {
					role = *it;
					break;
				}
			}
			if ( ! role )
			{
				MON::Exception exc( "? does not have ? as child with containment role [ ? ]!");
				exc << getObjectMeta().infoString() << toString( eType ) << strRole;
				ASSERTTHROW( exc);
			}
		}

		FCOPtr spFCO;
		COMTHROW( getModelI()->CreateChildObject( role.getContainmentI(), spFCO.Addr() ) );
		FCOImpl* pFCO = FCOImpl::attachI( spFCO, (ProjectImpl*) getProject().getCounted(), role.child() );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
		if ( ! _isAddOn() )
			pFCO->eventPerformedI( Event( MON::OET_ObjectCreated, pFCO ) );
		return pFCO;
	}

	FCOImpl* ModelImpl::createChildFCOI( const MON::FCO& meta, const std::string& strRole, MON::ObjectType eType )
	{
		if ( ! meta )
			return createChildFCOI( strRole, eType );

		THROW_METAPROJECT_BELONG( meta );
		MON::Containment role;
		std::set<MON::Containment> metas = getModelMeta().childContainments();
		for ( std::set<MON::Containment>::iterator it = metas.begin() ; it != metas.end() ; it++ ) {
			if ( it->child() == meta ) {
				if ( strRole.empty() ) {
					if ( role )
					{
						MON::Exception exc( "strRole cannot be an empty string because ? can contain ? as child with more than one MON::Containment!");
						exc << getObjectMeta().infoString() << meta.infoString();
						ASSERTTHROW( exc);
					}
					role = *it;
				}
				else {
					role = *it;
					break;
				}
			}
		}

		if ( ! role )
		{
			MON::Exception exc( "? does not have ? as child!");
			exc << getObjectMeta().infoString() << meta.infoString();
			ASSERTTHROW( exc);
		}

		FCOPtr spFCO;
		COMTHROW( getModelI()->CreateChildObject( role.getContainmentI(), spFCO.Addr() ) );
		FCOImpl* pFCO = FCOImpl::attachI( spFCO, (ProjectImpl*) getProject().getCounted(), meta );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
		if ( ! _isAddOn() )
			pFCO->eventPerformedI( Event( MON::OET_ObjectCreated, pFCO ) );
		return pFCO;
	}

	FCOImpl* ModelImpl::createChildFCOI( const BON::FCO& fco, bool bAsInstance, const std::string& strRole, MON::ObjectType eType )
	{
		THROW_CANNOT_BE_NULL( fco, "BON::" + toString( eType, false ) );
		THROW_PROJECT_BELONG( fco );

		MON::Containment role;
		std::set<MON::Containment> metas = getModelMeta().childContainments();
		for ( std::set<MON::Containment>::iterator it = metas.begin() ; it != metas.end() ; it++ ) {
			if ( it->child() == fco->getFCOMeta() ) {
				if ( strRole.empty() ) {
					if ( role )
					{
						MON::Exception exc( "strRole cannot be an empty string because ? can contain ? as child with more than one MON::Containment!");
						exc << getObjectMeta().infoString() << fco->getObjectMeta().infoString();
						ASSERTTHROW( exc);
					}
					role = *it;
				}
				else {
					role = *it;
					break;
				}
			}
		}

		if ( ! role )
		{
			MON::Exception exc( "? does not have ? as child!");
			exc << getObjectMeta().infoString() << fco->getObjectMeta().infoString();
			ASSERTTHROW( exc);
		}

		FCOPtr spFCO;
		COMTHROW( getModelI()->DeriveChildObject( fco->getFCOI(), role.getContainmentI(), ( bAsInstance ) ? VARIANT_TRUE : VARIANT_FALSE, spFCO.Addr() ) );
		FCOImpl* pFCO = FCOImpl::attachI( spFCO, (ProjectImpl*) getProject().getCounted(), fco->getFCOMeta() );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
		if ( ! _isAddOn() ) {
			pFCO->eventPerformedI( Event( MON::OET_ObjectCreated, pFCO ) );
			fco->eventPerformedI( Event( MON::OET_DescendantCreated, fco ) );
		}
		return pFCO;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ModelImpl					// Event Handlers

	bool ModelImpl::onRetrievedAsFCOParent( FCOImpl* pFCO, bool bCheckAll )
	{
		ManyFCOLink::iterator it = m_childFCOs.find( pFCO->getFCOMeta() );
		if ( it == m_childFCOs.end() ) {
			if ( bCheckAll )
				return false;
			m_childFCOs[ pFCO->getFCOMeta() ] = FCOSetPair( false, FCOSet() );
		}
		if ( ! bCheckAll || bCheckAll && m_childFCOs[ pFCO->getFCOMeta() ].first ) {
			m_childFCOs[ pFCO->getFCOMeta() ].second.insert( pFCO );
			return true;
		}
		return false;
	}

	void ModelImpl::onReleasedAsFCOParent( FCOImpl* pFCO, bool bOnlyFreeMemory )
	{
		ManyFCOLink::iterator it = m_childFCOs.find( pFCO->getFCOMeta() );
		if ( it != m_childFCOs.end() ) {
			m_childFCOs[ pFCO->getFCOMeta() ].second.erase( pFCO );
			if ( bOnlyFreeMemory && m_childFCOs[ pFCO->getFCOMeta() ].first ) {
				m_childFCOs[ pFCO->getFCOMeta() ].first = false;
				m_bAllChildFCOs = false;
			}
		}
	}

	void ModelImpl::eventPerformedI( const Event& event )
	{
		FCOImpl::eventPerformedI( event );
		switch ( event.getType() ) {
			case MON::OET_ChildAdded :
				onChildAdded( NULL );
				break;
			case MON::OET_ChildLost :
				onChildRemoved( NULL );
				break;
			case MON::OET_DescendantCreated :
				onObjectDerived( NULL );
				break;
		}
	}

	void ModelImpl::onChildAdded( FCOImpl* pChild )
	{
		if ( pChild ) {
			if ( onRetrievedAsFCOParent( pChild, false ) )
				pChild->onRetrievedAsModelChild( this, false );
		}
	}

	void ModelImpl::onChildRemoved( FCOImpl* pChild )
	{
		if ( pChild ) {
			onReleasedAsFCOParent( pChild, false );
			pChild->onReleasedAsModelChild( this, false );
		}
	}

	void ModelImpl::onObjectDerived( FCOImpl* pFCO )
	{
		if ( ! _isAddOn() ) {
			for ( ManyFCOLink::iterator it = m_childFCOs.begin() ; it != m_childFCOs.end() ; it++ )
				for ( FCOSet::iterator it2 = it->second.second.begin() ; it2 != it->second.second.end() ; it2++ )
					(*it2)->eventPerformedI( Event( MON::OET_DescendantCreated, *it2 ) );
		}
	}

//===============================================================================================================================================
// 	C L A S S : BON::ModelImpl					// Relations // ---> Interface Methods

	std::set<FCO> ModelImpl::getChildFCOs( const MON::FCO& meta, const MON::Aspect& aspect )
	{
		if ( aspect )
			THROW_METAPROJECT_BELONG( aspect );

		if ( meta ) {
			THROW_METAPROJECT_BELONG( meta );
			if ( ! getModelMeta().isFCOChild( meta ) )
			{
				MON::Exception exc( "? cannot be child of ?!");
				exc << meta.infoString() << getObjectMeta().infoString();
				ASSERTTHROW( exc);
			}
		}
		std::set<FCO> setResult;
		setCopy<FCO,FCOImpl>( getChildFCOsI( meta ), setResult );
		return filterByAspect<FCO>( setResult, aspect );
	}

	std::set<FCO> ModelImpl::getChildFCOs( const std::string& strFCO, const MON::Aspect& aspect )
	{
		MON::FCO meta;
		if ( ! strFCO.empty() ) {
			meta = MON::FCO( getProject()->getProjectMeta().findByName( strFCO ) );
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, FCO, strFCO );
		}
		return getChildFCOs( meta, aspect );
	}

	std::set<FCO> ModelImpl::getChildFCOsAs( const std::string& strRole, const MON::Aspect& aspect )
	{
		if ( strRole.empty() )
			return getChildFCOs( MON::FCO(), aspect );

		if ( aspect )
			THROW_METAPROJECT_BELONG( aspect );

		MON::Containment role;
		std::set<MON::Containment> roles = getModelMeta().childContainments();
		for ( std::set<MON::Containment>::iterator it = roles.begin() ; it != roles.end() ; it++ )
			if ( strRole == it->name() ) {
				role = *it;
				break;
			}

		if ( ! role )
		{
			MON::Exception exc( "? cannot be has containment role ?!");
			exc << getObjectMeta().infoString() << strRole;
			ASSERTTHROW( exc);
		}

		std::set<FCO> setResult;
		setCopy<FCO,FCOImpl>( getChildFCOsI( role.child() ), setResult );

		std::set<FCO>::iterator it2 = setResult.begin();
		while ( it2 != setResult.end() ) {
			std::set<FCO>::iterator itSaved = it2;
			it2++;
			if ( (*itSaved)->getRole() != role )
				setResult.erase( itSaved );
		}

		return filterByAspect<FCO>( setResult, aspect );
	}

	std::set<Atom> ModelImpl::getChildAtoms( const MON::Aspect& aspect )
	{
		if ( aspect )
			THROW_METAPROJECT_BELONG( aspect );

		std::set<Atom> setResult;
		std::set<MON::Atom> metas = getModelMeta().childAtoms();
		for ( std::set<MON::Atom>::iterator it = metas.begin() ; it != metas.end() ; ++it )
			setCastCopy<Atom,FCOImpl,AtomImpl>( getChildFCOsI( *it ), setResult );
		return filterByAspect<Atom>( setResult, aspect );
	}

	std::set<Model> ModelImpl::getChildModels( const MON::Aspect& aspect )
	{
		if ( aspect )
			THROW_METAPROJECT_BELONG( aspect );

		std::set<Model> setResult;
		std::set<MON::Model> metas = getModelMeta().childModels();
		for ( std::set<MON::Model>::iterator it = metas.begin() ; it != metas.end() ; ++it )
			setCastCopy<Model,FCOImpl,ModelImpl>( getChildFCOsI( *it ), setResult );
		return filterByAspect<Model>( setResult, aspect );
	}

	std::set<Set> ModelImpl::getChildSets( const MON::Aspect& aspect )
	{
		if ( aspect )
			THROW_METAPROJECT_BELONG( aspect );

		std::set<Set> setResult;
		std::set<MON::Set> metas = getModelMeta().childSets();
		for ( std::set<MON::Set>::iterator it = metas.begin() ; it != metas.end() ; ++it )
			setCastCopy<Set,FCOImpl,SetImpl>( getChildFCOsI( *it ), setResult );
		return filterByAspect<Set>( setResult, aspect );
	}

	std::set<Reference> ModelImpl::getChildReferences( const MON::Aspect& aspect )
	{
		if ( aspect )
			THROW_METAPROJECT_BELONG( aspect );

		std::set<Reference> setResult;
		std::set<MON::Reference> metas = getModelMeta().childReferences();
		for ( std::set<MON::Reference>::iterator it = metas.begin() ; it != metas.end() ; ++it )
			setCastCopy<Reference,FCOImpl,ReferenceImpl>( getChildFCOsI( *it ), setResult );
		return filterByAspect<Reference>( setResult, aspect );
	}

	std::set<Connection> ModelImpl::getChildConnections( const MON::Aspect& aspect )
	{
		if ( aspect )
			THROW_METAPROJECT_BELONG( aspect );

		std::set<Connection> setResult;
		std::set<MON::Connection> metas = getModelMeta().childConnections();
		for ( std::set<MON::Connection>::iterator it = metas.begin() ; it != metas.end() ; ++it )
			setCastCopy<Connection,FCOImpl,ConnectionImpl>( getChildFCOsI( *it ), setResult );
		return filterByAspect<Connection>( setResult, aspect );
	}

	FCO ModelImpl::findByPath( const std::string& strPath, const std::string& strDelimiter, bool bReverseOrder )
	{
		std::string strPath2;
		std::string strName;
		int iPos = ( bReverseOrder ) ? strPath.rfind( strDelimiter ) : strPath.find( strDelimiter );
		if ( iPos == std::string::npos ) {
			strName = strPath;
			strPath2 = "";
		}
		else {
			if ( bReverseOrder && iPos + strDelimiter.length() == strPath.length() )
				strPath2 = strPath.substr( 0, iPos );
			if ( ! bReverseOrder && iPos == 0 )
				strPath2 = strPath.substr( iPos + strDelimiter.length() );
			iPos = ( bReverseOrder ) ? strPath2.rfind( strDelimiter ) : strPath2.find( strDelimiter );
			if ( iPos == std::string::npos ) {
				strName = strPath2;
				strPath2 = "";
			}
			else {
				strName = ( bReverseOrder ) ? strPath2.substr( iPos ) : strPath2.substr( 0, iPos );
				strPath2 = ( bReverseOrder ) ? strPath2.substr( 0, iPos ) : strPath2.substr( iPos );
			}
		}

		std::set<FCO> objects = getChildFCOs();
		for ( std::set<FCO>::iterator it = objects.begin() ; it != objects.end() ; it++ )
			if ( strName == (*it)->getName() ) {
				if ( strPath2.empty() )
					return *it;
				else {
					if ( (*it)->getStereotype() == OT_Model ) {
						FCO o = Model( *it )->findByPath( strPath2, strDelimiter, bReverseOrder );
						if ( o )
							return o;
					}
				}
			}
		return NULL;
	}

	std::set<FCO> ModelImpl::findByKind( const MON::Object& meta )
	{
		if ( ! meta )
			ASSERTTHROW( Exception( "MON::Object cannot be null!" ) );
		if ( meta.project() != this->getObjectMeta().project() )
		{
			MON::Exception exc( "? does not belong to ? of ?!");//, "sss", 
			exc << meta.infoString() << this->getObjectMeta().project().infoString() << getInfoString().c_str(); 
			ASSERTTHROW( exc);
		}
		if ( meta.type() < MON::OT_Model || meta.type() > MON::OT_Set )
		{
			Exception exc( "Type of ? can be only MON::FCO!");//, "s", 
			exc << meta.infoString();
			ASSERTTHROW( exc );
		}

		return findByKindHlp( MON::FCO( meta));
	}

	std::set<FCO> ModelImpl::findByKind( const std::string& strKind )
	{
		MON::Object meta = this->getObjectMeta().project().findByName( strKind );
		if ( ! meta )
		{
			MON::Exception exc( "MON::FCO [ ? ] does not exist in ? of ?!");// "ssss", 
			exc << strKind.c_str() << strKind.c_str() << this->getObjectMeta().project().infoString().c_str() << getInfoString().c_str();
			ASSERTTHROW( exc );
		}
		if ( meta.type() < MON::OT_Model || meta.type() > MON::OT_Set )
		{
			Exception exc( "? is not MON::FCO!");// "s", 
			exc << meta.infoString().c_str();
			ASSERTTHROW( exc );
		}

		return findByKindHlp( MON::FCO( meta));
	}

	std::set<FCO> ModelImpl::findByKindHlp( const MON::FCO& meta )
	{
		std::set<FCO> bigResult = getChildFCOs( meta);
		std::set<Model> children = getChildModels();
		for( std::set<Model>::iterator it = children.begin(); it != children.end(); ++it)
		{
			std::set<FCO> res = (*it)->findByKindHlp( meta);
			bigResult.insert( res.begin(), res.end());
		}

		return bigResult;
	}
	
//===============================================================================================================================================
// 	C L A S S : BON::ModelImpl					// Extensions

	void ModelImpl::accept( Visitor* pVisitor )
	{
		FCOSet children = getChildFCOsI();
		for ( FCOSet::iterator it = children.begin() ; it != children.end() ; it++ )
			(*it)->accept( pVisitor );
		pVisitor->visitModel( Model( this ) );
	}

	ModelRegistryNode ModelImpl::getRegistry() const
	{
		return FCOImpl::getRegistry();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::SetImpl
//
//###############################################################################################################################################

	SetImpl::SetImpl()
		: FCOImpl(), m_bAllMemberFCOs( false )
	{
	}

	SetImpl* SetImpl::attachI( IMgaSet* spSet, ProjectImpl* pProject, const MON::Object& meta )
	{
		// Warning : Maybe it is an Exception
		if ( ! spSet )
			return NULL;

		// Find it in Objects' cache
		pProject = _getProject( spSet, pProject );
		ObjectImpl* pObject = find( pProject, spSet );
		if ( pObject )
			return dynamic_cast<SetImpl*>( pObject );

		// Get Extension
		pObject = getEx( spSet, OT_Set, meta );
		if ( ! pObject )
			pObject = new SetImpl();
		pObject->doInitialize( spSet, pProject, meta );
		dynamic_cast<FCOImpl*>( pObject )->doInitialize( pProject );
		pObject->initialize();
		
		SetImpl* si = dynamic_cast<SetImpl*>( pObject );
		attachIPost( si);
		return si;
	}

	Set SetImpl::attach( IMgaSet* spSet )
	{
		return attachI( spSet );
	}

	Set SetImpl::create( const Folder& parent, const MON::Set& meta )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		return parent->createChildObjectI( meta, MON::OT_Set );
	}

	Set SetImpl::create( const Folder& parent, const std::string& strSet )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		MON::Set meta;
		if ( ! strSet.empty() ) {
			meta = parent->getProject()->getProjectMeta().findByName( strSet );
			if ( ! meta )
			{
				MON::Exception exc( "MON::Set [ ? ] does not exist in ? of ?!");
				exc << strSet << parent->getProject()->getProjectMeta().infoString() << parent->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}
		}
		return create( parent, meta );
	}

	Set SetImpl::create( const Folder& parent, const Set& baseType, bool bAsInstance )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		return dynamic_cast<SetImpl*>( parent->createChildFCOI( baseType, bAsInstance, MON::OT_Set ) );
	}

	Set SetImpl::create( const Model& parent, const MON::Set& meta, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<SetImpl*>( parent->createChildFCOI( meta, strRole, MON::OT_Set ) );
	}

	Set SetImpl::create( const Model& parent, const std::string& strSet, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		MON::Set meta;
		if ( ! strSet.empty() ) {
			meta = parent->getProject()->getProjectMeta().findByName( strSet );
			if ( ! meta )
			{
				MON::Exception exc( "MON::Set [ ? ] does not exist in ? of ?!");
				exc << strSet << parent->getProject()->getProjectMeta().infoString() << parent->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}
		}
		return create( parent, meta, strRole );
	}

	Set SetImpl::create( const Model& parent, const Set& baseType, bool bAsInstance, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<SetImpl*>( parent->createChildFCOI( baseType, bAsInstance, strRole, MON::OT_Set ) );
	}

	Set SetImpl::createAs( const Model& parent, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<SetImpl*>( parent->createChildFCOI( strRole, MON::OT_Set ) );
	}

	SetImpl::~SetImpl()
	{
		if ( ! ObjectImpl::m_pProject->isDestructionActive() && ! isDeleted() ) {
			for ( ManyFCOLink::iterator it1 = m_memberFCOs.begin() ; it1 != m_memberFCOs.end() ; it1++ )
				for ( FCOSet::iterator it2 = it1->second.second.begin() ; it2 != it1->second.second.end() ; it2++ )
					(*it2)->onReleasedAsMember( this, true );
		}

		m_memberFCOs.clear();
	}

	bool SetImpl::setDeleted()
	{
		if ( FCOImpl::setDeleted() )
			return true;

		for ( ManyFCOLink::iterator it1 = m_memberFCOs.begin() ; it1 != m_memberFCOs.end() ; it1++ )
			for ( FCOSet::iterator it2 = it1->second.second.begin() ; it2 != it1->second.second.end() ; it2++ )
				(*it2)->onReleasedAsMember( this, false);
		return false;
	}

//===============================================================================================================================================
// 	C L A S S : BON::SetImpl					// Get and Set Operations // ---> Interface Methods

	ObjectType SetImpl::getStereotype() const
	{
		return OT_Set;
	}

	SetPtr SetImpl::getSetI() const
	{
		CComQIPtr<IMgaSet> spSet = getObjectI().p;
		return spSet.p;
	}

	MON::Set SetImpl::getSetMeta() const
	{
		return getObjectMeta();
	}

	std::string SetImpl::getInfoString( unsigned short usOptions ) const
	{
		bool bAll = ( usOptions & Util::IO_All ) ? true : false;
		bool bLine = bAll || ( usOptions & Util::IO_NewLine );

		std::string strInfo = getInfoStringHelper( usOptions, "Set" );
		if ( ! ( usOptions & Util::IO_NewLine ) && ! ( usOptions & Util::IO_All ) )
			strInfo += "]";

		return strInfo;
	}

//===============================================================================================================================================
// 	C L A S S : BON::SetImpl					// Relations

	bool SetImpl::isMemberFCOsRetrieved( const MON::FCO& meta )
	{
		ManyFCOLink::iterator it = m_memberFCOs.find( meta );
		if ( it != m_memberFCOs.end() ) {
			if ( it->second.first )
				return true;
			it->second.first = true;
			return false;
		}
		m_memberFCOs[ meta ] = FCOSetPair( true, FCOSet() );
		return false;
	}

	void SetImpl::getMemberFCOs( std::set<FCOPtr>& setSPFCOs )
	{
		Util::ComPtr<IMgaFCOs> spFCOs;
		COMTHROW( getSetI()->get_Members( spFCOs.Addr() ) );
		MGACOLL_ITERATE( IMgaFCO, spFCOs.p ) {
			setSPFCOs.insert( MGACOLL_ITER );
		} MGACOLL_ITERATE_END;
	}

	void SetImpl::getMemberFCOs( const MON::FCO& meta, std::set<FCOPtr>& setSPFCOs, bool bErase )
	{
		std::set<FCOPtr>::iterator it = setSPFCOs.begin();
		while ( it != setSPFCOs.end() ) {
			std::set<FCOPtr>::iterator itSaved = it;
			it++;
			if ( _getMetaRef( *itSaved ) == meta.ref() ) {
				FCOImpl* pFCO = FCOImpl::attachI( *itSaved, ObjectImpl::m_pProject, meta );
				if ( m_memberFCOs[ meta ].second.find( pFCO ) == m_memberFCOs[ meta ].second.end() ) {
					m_memberFCOs[ meta ].second.insert( pFCO );
					pFCO->onRetrievedAsMember( this, false );
				}
				if ( bErase )
					setSPFCOs.erase( itSaved );
			}
		}
	}

	FCOSet SetImpl::getMemberFCOsI( const MON::FCO& meta )
	{
		// If Containment specified
		if ( meta ) {
			if ( ! isMemberFCOsRetrieved( meta ) ) {
				std::set<FCOPtr> setSPFCOs;
				getMemberFCOs( setSPFCOs );
				getMemberFCOs( meta, setSPFCOs, false );
			}
			return m_memberFCOs[ meta ].second;
		}

		// If Containment is not specified
		if ( ! m_bAllMemberFCOs ) {
			m_bAllMemberFCOs = true;
			std::set<FCOPtr> setSPFCOs;
			getMemberFCOs( setSPFCOs );
			std::set<MON::Containment> setMembers = getSetMeta().memberRoles();
			for ( std::set<MON::Containment>::iterator it = setMembers.begin() ; it != setMembers.end() ; it++ ) {
				if ( ! isMemberFCOsRetrieved( it->child() ) )
					getMemberFCOs( it->child(), setSPFCOs, true );
			}
		}

		// Create the Huge Set
		FCOSet setFCOs;
		for ( ManyFCOLink::iterator it = m_memberFCOs.begin() ; it != m_memberFCOs.end() ; it++ )
			setFCOs.insert( it->second.second.begin(), it->second.second.end() );
		return setFCOs;
	}

	void SetImpl::addMemberI( const BON::FCO& fco )
	{
		FCOImpl* pMember = dynamic_cast<FCOImpl*>( fco.getCounted() );
		COMTHROW( getSetI()->AddMember( pMember->getFCOI() ) );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
		if ( ! _isAddOn() )
			pMember->eventPerformedI( Event( MON::OET_ObjectIncluded, this ) );
	}

	void SetImpl::removeMemberI( const BON::FCO& fco )
	{
		FCOImpl* pMember = dynamic_cast<FCOImpl*>( fco.getCounted() );
		COMTHROW( getSetI()->RemoveMember( pMember->getFCOI() ) );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
		if ( ! _isAddOn() )
			pMember->eventPerformedI( Event( MON::OET_ObjectExcluded, this ) );
	}

//===============================================================================================================================================
// 	C L A S S : BON::SetImpl					// Event Handlers

	bool SetImpl::onRetrievedAsSet( FCOImpl* pFCO, bool bCheckAll )
	{
		ManyFCOLink::iterator it = m_memberFCOs.find( pFCO->getFCOMeta() );
		if ( it == m_memberFCOs.end() ) {
			if ( bCheckAll )
				return false;
			m_memberFCOs[ pFCO->getFCOMeta() ] = FCOSetPair( false, FCOSet() );
		}
		if ( bCheckAll && ! m_memberFCOs[ pFCO->getFCOMeta() ].first )
			return false;
		m_memberFCOs[ pFCO->getFCOMeta() ].second.insert( pFCO );
		return true;
	}

	void SetImpl::onReleasedAsSet( FCOImpl* pFCO, bool bOnlyMemoryFree )
	{
		ManyFCOLink::iterator it = m_memberFCOs.find( pFCO->getFCOMeta() );
		if ( it != m_memberFCOs.end() ) {
			m_memberFCOs[ pFCO->getFCOMeta() ].second.erase( pFCO );
			if ( bOnlyMemoryFree && m_memberFCOs[ pFCO->getFCOMeta() ].first ) {
				m_memberFCOs[ pFCO->getFCOMeta() ].first = false;
				m_bAllMemberFCOs = false;
			}
		}
	}

	void SetImpl::eventPerformedI( const Event& event )
	{
		FCOImpl::eventPerformedI( event );
		switch ( event.getType() ) {
			case MON::OET_RelationChanged :
				onRelationChanged();
				break;
		}
	}

	void SetImpl::onRelationChanged()
	{
		// Temporary Solution ... Eliminate If Event Paremeters Available
		for ( ManyFCOLink::iterator it1 = m_memberFCOs.begin() ; it1 != m_memberFCOs.end() ; it1++ )
			for ( FCOSet::iterator it2 = it1->second.second.begin() ; it2 != it1->second.second.end() ; it2++ )
				(*it2)->onReleasedAsMember( this, false );
		m_memberFCOs.clear();
		m_bAllMemberFCOs = false;
		// Temporary Solution END
	}

//===============================================================================================================================================
// 	C L A S S : BON::SetImpl					// Relations // ---> Interface Methods

	std::set<FCO> SetImpl::getMembers( const MON::FCO& meta, const MON::Aspect& aspect )
	{
		if ( aspect )
			THROW_METAPROJECT_BELONG( aspect );

		if ( meta ) {
			THROW_METAPROJECT_BELONG( meta );
			if ( ! getSetMeta().isMember( meta ) )
			{
				MON::Exception exc( "? cannot be member of ?!");
				exc << meta.infoString() << getObjectMeta().infoString();
				ASSERTTHROW( exc);
			}
		}
		std::set<FCO> setResult;
		setCopy<FCO,FCOImpl>( getMemberFCOsI( meta ), setResult );
		return filterByAspect<FCO>( setResult, aspect );
	}

	std::set<FCO> SetImpl::getMembers( const std::string& strFCO, const MON::Aspect& aspect )
	{
		MON::FCO meta;
		if ( ! strFCO.empty() ) {
			meta = MON::FCO( getProject()->getProjectMeta().findByName( strFCO ) );
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, FCO, strFCO );
		}
		return getMembers( meta, aspect );
	}

	void SetImpl::addMember( const BON::FCO& fco )
	{
		THROW_CANNOT_BE_NULL( fco, "BON::FCO" );
		THROW_PROJECT_BELONG( fco );

		MON::Containment role = fco->getRole();
		if ( role ) {
			if ( ! getSetMeta().isMember( role ) )
			{
				MON::Exception exc( "? with ? cannot be member of ?!");
				exc << fco->getObjectMeta().infoString() << role.infoString() << getObjectMeta().infoString();
				ASSERTTHROW( exc);
			}
			addMemberI( fco );
			return;
		}

		std::set<MON::Containment> roles = getSetMeta().memberRoles();
		for ( std::set<MON::Containment>::iterator it = roles.begin() ; it != roles.end() ; it++ )
			if ( it->child() == fco->getFCOMeta() ) {
				addMemberI( fco );
				return;
			}
		MON::Exception exc( "? cannot be member of ?!");
		exc << fco->getObjectMeta().infoString() << getObjectMeta().infoString();
		ASSERTTHROW( exc);
	}

	void SetImpl::removeMember( const BON::FCO& fco )
	{
		THROW_CANNOT_BE_NULL( fco, "BON::FCO" );
		THROW_PROJECT_BELONG( fco );

		MON::Containment role = fco->getRole();
		if ( role ) {
			if ( ! getSetMeta().isMember( role ) )
			{
				MON::Exception exc( "? with ? cannot be member of ?!");
				exc << fco->getObjectMeta().infoString() << role.infoString() << getObjectMeta().infoString();
				ASSERTTHROW( exc);
			}
			removeMemberI( fco );
			return;
		}

		std::set<MON::Containment> roles = getSetMeta().memberRoles();
		for ( std::set<MON::Containment>::iterator it = roles.begin() ; it != roles.end() ; it++ )
			if ( it->child() == fco->getFCOMeta() ) {
				removeMemberI( fco );
				return;
			}

		MON::Exception exc( "? cannot be member of ?!");
		exc << fco->getObjectMeta().infoString() << getObjectMeta().infoString();
		ASSERTTHROW( exc);
	}

//===============================================================================================================================================
// 	C L A S S : BON::SetImpl					// Extensions

	void SetImpl::accept( Visitor* pVisitor )
	{
		pVisitor->visitSet( Set( this ) );
	}

	FCOExRegistryNode SetImpl::getRegistry() const
	{
		return FCOImpl::getRegistry();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ReferenceImpl
//
//###############################################################################################################################################

	ReferenceImpl::ReferenceImpl()
		: FCOImpl(), m_bAllReferredFCOs( false ), m_bAllChildPorts( false )
	{
		m_referredFCO.first = MON::FCO();
		m_referredFCO.second = NULL;
		m_pContainer = new ReferencePortContainerImpl( this );
	}

	ReferenceImpl* ReferenceImpl::attachI( IMgaReference* spReference, ProjectImpl* pProject, const MON::Object& meta )
	{
		// Warning : Maybe it is an Exception
		if ( ! spReference )
			return NULL;

		// Find it in Objects' cache
		pProject = _getProject( spReference, pProject );
		ObjectImpl* pObject = find( pProject, spReference );
		if ( pObject )
			return dynamic_cast<ReferenceImpl*>( pObject );

		// Get Extension
		pObject = getEx( spReference, OT_Reference, meta );
		if ( ! pObject )
			pObject = new ReferenceImpl();
		pObject->doInitialize( spReference, pProject, meta );
		dynamic_cast<FCOImpl*>( pObject )->doInitialize( pProject );
		pObject->initialize();
		
		ReferenceImpl* ri = dynamic_cast<ReferenceImpl*>( pObject );
		attachIPost( ri);
		return ri;
	}

	Reference ReferenceImpl::attach( IMgaReference* spReference )
	{
		return attachI( spReference );
	}

	Reference ReferenceImpl::create( const Folder& parent, const MON::Reference& meta )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		return parent->createChildObjectI( meta, MON::OT_Reference );
	}

	Reference ReferenceImpl::create( const Folder& parent, const std::string& strReference )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		MON::Reference meta;
		if ( ! strReference.empty() ) {
			meta = parent->getProject()->getProjectMeta().findByName( strReference );
			if ( ! meta )
			{
				MON::Exception exc( "MON::Reference [ ? ] does not exist in ? of ?!");
				exc << strReference << parent->getProject()->getProjectMeta().infoString() << parent->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}
		}
		return create( parent, meta );
	}

	Reference ReferenceImpl::create( const Folder& parent, const Reference& baseType, bool bAsInstance )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Folder" );
		return dynamic_cast<ReferenceImpl*>( parent->createChildFCOI( baseType, bAsInstance, MON::OT_Reference ) );
	}

	Reference ReferenceImpl::create( const Model& parent, const MON::Reference& meta, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<ReferenceImpl*>( parent->createChildFCOI( meta, strRole, MON::OT_Reference ) );
	}

	Reference ReferenceImpl::create( const Model& parent, const std::string& strReference, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		MON::Reference meta;
		if ( ! strReference.empty() ) {
			meta = parent->getProject()->getProjectMeta().findByName( strReference );
			if ( ! meta )
			{
				MON::Exception exc( "MON::Reference [ ? ] does not exist in ? of ?!");
				exc << strReference << parent->getProject()->getProjectMeta().infoString() << parent->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}
		}
		return create( parent, meta, strRole );
	}

	Reference ReferenceImpl::create( const Model& parent, const Reference& baseType, bool bAsInstance, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<ReferenceImpl*>( parent->createChildFCOI( baseType, bAsInstance, strRole, MON::OT_Reference ) );
	}

	Reference ReferenceImpl::createAs( const Model& parent, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		return dynamic_cast<ReferenceImpl*>( parent->createChildFCOI( strRole, MON::OT_Reference ) );
	}

	ReferenceImpl::~ReferenceImpl()
	{
		if ( ! ObjectImpl::m_pProject->isDestructionActive() && ! isDeleted() ) {
			if ( m_referredFCO.second )
					m_referredFCO.second->onReleasedAsReferred( this, true );
		}

		ManyPortLink ports = m_childPorts;
		m_childPorts.clear();
		for ( ManyPortLink::iterator it = ports.begin() ; it != ports.end() ; it++ )
			delete it->second;

		delete m_pContainer;

		m_referredFCO.first = MON::FCO();
		m_referredFCO.second = NULL;
		m_pContainer = NULL;
	}

	bool ReferenceImpl::setDeleted()
	{
		if ( FCOImpl::setDeleted() )
			return true;

		if ( m_referredFCO.second )
			m_referredFCO.second->onReleasedAsReferred( this, false );

		ManyPortLink ports = m_childPorts;
		m_childPorts.clear();
		for ( ManyPortLink::iterator it = ports.begin() ; it != ports.end() ; it++ )
			it->second->setDeleted();

		return false;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ReferenceImpl					// Get and Set Operations // ---> Interface Methods

	ObjectType ReferenceImpl::getStereotype() const
	{
		return OT_Reference;
	}

	ReferencePtr ReferenceImpl::getReferenceI() const
	{
		CComQIPtr<IMgaReference> spReference = getObjectI().p;
		return spReference.p;
	}

	MON::Reference ReferenceImpl::getReferenceMeta() const
	{
		return getObjectMeta();
	}

	std::string ReferenceImpl::getInfoString( unsigned short usOptions ) const
	{
		bool bAll = ( usOptions & Util::IO_All ) ? true : false;
		bool bIdent = bAll || ( usOptions & Util::IO_Identifiers );
		bool bLine = bAll || ( usOptions & Util::IO_NewLine );
		std::string strDelim = ( bLine ) ? "\n" : ", ";

		std::string strInfo = getInfoStringHelper( usOptions, "Reference" );
		if ( bAll || ( usOptions & Util::IO_Specific ) ) {
			strInfo += strDelim;
			if ( bIdent )
				strInfo += "referred: ";
			FCO referred = ( (ReferenceImpl* ) this)->getReferred(); // WARNING
			if ( ! referred )
				strInfo += "null";
			else {
				unsigned short usOptions2 = 0;
				if ( bIdent )
					usOptions2 |= Util::IO_Identifiers;
				if ( bAll || ( usOptions & Util::IO_ID ) )
					usOptions2 |= Util::IO_ID;
				if ( bAll || ( usOptions & Util::IO_Meta ) )
					usOptions2 |= Util::IO_Meta;
				if ( bAll || ( usOptions & Util::IO_Path ) )
					usOptions2 |= Util::IO_Path;
				strInfo += referred->getInfoString( usOptions2 );
			}
		}

		if ( ! bLine )
			strInfo += "]";

		return strInfo;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ReferenceImpl					// Relations

	FCOImpl* ReferenceImpl::getReferredFCOI( const MON::FCO& meta )
	{
		// Check if Parent was already retrieved
		if ( m_referredFCO.first )
			return ( ! meta || meta == m_referredFCO.first ) ? m_referredFCO.second : NULL;
		if ( m_bAllReferredFCOs )
			return NULL;

		// Retrieve
		FCOPtr spFCO;
		COMTHROW( getReferenceI()->get_Referred( spFCO.Addr() ) );

		if ( spFCO.p && ( ! meta || _getMetaRef( spFCO ) == meta.ref() ) ) {
			m_referredFCO.first = ( meta ) ? meta : MON::FCO( getProject()->getProjectMeta().findByName( _getMetaName( spFCO ) ) );
			m_referredFCO.second = FCOImpl::attachI( spFCO, ObjectImpl::m_pProject, m_referredFCO.first );
			m_referredFCO.second->onRetrievedAsReferred( this, false );
		}
		if ( ! meta )
			m_bAllReferredFCOs = true;

		return m_referredFCO.second;
	}

	void ReferenceImpl::setReferredFCOI( const BON::FCO& fco )
	{
		COMTHROW( getReferenceI()->put_Referred( fco->getFCOI() ) );
	}

	bool ReferenceImpl::createRefPort( FCOImpl* pFCO )
	{
		ManyPortLink::iterator it = m_childPorts.find( pFCO );
		if ( it == m_childPorts.end() ) { 
			if ( pFCO->isPort() ) {       
				ReferencePortImpl* pPort = new ReferencePortImpl( this, pFCO );
				m_childPorts[ pFCO ] = pPort; 
				pFCO->onRetrievedAsReferencePort( pPort, false );
				return true;
			}
			return false;
		}
		return true;
	}

	ReferencePortSet ReferenceImpl::getRefPorts()
	{
		if ( ! m_bAllChildPorts ) {
			m_bAllChildPorts = true; //zolmol mod, WAS: m_bAllChildPorts = NULL

			CComQIPtr<IMgaReference> spRef = getReferenceI().p;
			FCOPtr spFCO;
			do {
				FCOPtr spFCO_temp;
				COMTHROW( spRef->get_Referred( spFCO_temp.Addr() ) );
				spFCO = spFCO_temp;
			} while ( spRef = spFCO.p );

			Util::ComPtr<IMgaFCOs> spFCOs;
			COMTHROW( CComQIPtr<IMgaModel>( spFCO.p )->get_ChildFCOs( spFCOs.Addr() ) );
			MGACOLL_ITERATE( IMgaFCO, spFCOs.p ) {
				createRefPort( FCOImpl::attachI( MGACOLL_ITER, ObjectImpl::m_pProject ) );
			} MGACOLL_ITERATE_END;
		}

		ReferencePortSet setResult;
		for ( ManyPortLink::iterator it = m_childPorts.begin() ; it != m_childPorts.end() ; ++it )
			setResult.insert( it->second );
		return setResult;
	}

	ReferencePortImpl* ReferenceImpl::getRefPort( FCOImpl* pFCO )
	{
		getRefPorts();
		ManyPortLink::iterator it = m_childPorts.find( pFCO );
		return ( it == m_childPorts.end() ) ? NULL : m_childPorts[ pFCO ];
	}

//===============================================================================================================================================
// 	C L A S S : BON::ReferenceImpl					// Event Handlers

	bool ReferenceImpl::onRetrievedAsReference( FCOImpl* pFCO, bool bCheckAll )
	{
		m_bAllReferredFCOs = true;
		m_referredFCO.first = pFCO->getFCOMeta();
		m_referredFCO.second = pFCO;
		return true;
	}

	void ReferenceImpl::onReleasedAsReference( FCOImpl* pFCO, bool bOnlyFreeMemory )
	{
		m_referredFCO.first = MON::FCO();
		m_referredFCO.second = NULL;
		m_bAllReferredFCOs = false;
	}

	void ReferenceImpl::onReleasedAsPortContainer( FCOImpl* pFCO, bool bOnlyMemoryFree )
	{
		m_childPorts.erase( pFCO );
		if ( bOnlyMemoryFree )
			m_bAllChildPorts = false;
	}

	void ReferenceImpl::eventPerformedI( const Event& event )
	{
		FCOImpl::eventPerformedI( event );
		switch ( event.getType() ) {
			case MON::OET_RelationChanged :
				onRelationChanged();
				break;
		}
	}

	void ReferenceImpl::onRelationChanged()
	{
		// Temporary Solution ... Eliminate If Event Paremeters Available
		if ( m_referredFCO.second )
			m_referredFCO.second ->onReleasedAsReferred( this, false );
		m_referredFCO.first = MON::FCO();
		m_referredFCO.second = NULL;

		ManyPortLink ports = m_childPorts;
		m_childPorts.clear();
		for ( ManyPortLink::iterator it = ports.begin() ; it != ports.end() ; it++ )
			it->second->setDeleted();
		m_bAllChildPorts = false;
		// Temporary Solution END
	}

//===============================================================================================================================================
// 	C L A S S : BON::ReferenceImpl					// Relations // ---> Interface Methods

	FCO ReferenceImpl::getReferred( const MON::FCO& meta )
	{
		if ( meta ) {
			THROW_METAPROJECT_BELONG( meta );

#ifdef TEST_META_CONFORMANCE_INSIDE_BON
			if ( ! getReferenceMeta().isReferenced( meta ) )
			{
				MON::Exception exc( "? cannot be referenced by ?!");
				exc << meta.infoString() << getObjectMeta().infoString(); 
				ASSERTTHROW( exc);
			}
#endif

		}
		return getReferredFCOI( meta );
	}

	FCO ReferenceImpl::getReferred( const std::string& strFCO )
	{
		MON::FCO meta;
		if ( ! strFCO.empty() ) {
			meta = MON::FCO( getProject()->getProjectMeta().findByName( strFCO ) );
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, FCO, strFCO );
		}
		return getReferred( meta );
	}

	void ReferenceImpl::setReferred( const FCO& fco )
	{
		if ( fco ) {
			THROW_PROJECT_BELONG( fco );

#ifdef TEST_META_CONFORMANCE_INSIDE_BON
			// added by ZolMol
			MON::FCO meta = fco->getFCOMeta();
			if ( ! getReferenceMeta().isReferenced( meta ) )
			{
				MON::Exception exc( "? cannot be referenced by ?!");
				exc << fco->getObjectMeta().infoString() << getObjectMeta().infoString();
				ASSERTTHROW( exc);
			}
			// end added part

			// CHANGED LINES BEGIN
			/* commented out by ZolMol 
			MON::Containment role = fco->getRole(); 
			if ( role ) {
				if ( ! getReferenceMeta().isReferenced( role ) )
					ASSERTTHROW( MON::Exception( "? cannot be referenced by ?!", "ss", fco->getObjectMeta().infoString().c_str(), getObjectMeta().infoString().c_str() ) );
			}
			else {
				bool bFound = false;
				std::set<MON::Containment> roles = getReferenceMeta().targetRoles();
				for ( std::set<MON::Containment>::iterator it = roles.begin() ; it != roles.end() ; it++ )
					if ( it->child() == fco ) {
						bFound = true;
						break;
					}
				if ( ! bFound )
					ASSERTTHROW( MON::Exception( "? cannot be referenced by ?!", "ss", fco->getObjectMeta().infoString().c_str(), getObjectMeta().infoString().c_str() ) );
			} end commended part*/
			// CHANGED LINES END
#endif
		}
		if ( ! _isAddOn() ) {
			if  ( m_referredFCO.second )
				m_referredFCO.second->eventPerformedI( Event( MON::OET_ObjectReleased, m_referredFCO.second ) );
			if ( fco )
				fco->eventPerformedI( Event( MON::OET_ObjectReferenced, fco ) );
		}
		setReferredFCOI( fco );
		if ( getProject()->isAutoCommit() )
			getProject()->commit();
	}

	ReferencePortContainer ReferenceImpl::getRefPortContainer()
	{
		FCO fco = getReferred();
		Reference ref = fco;
		while ( ref ) {
			fco = ref->getReferred();
			ref = fco;
		}
		return ( Model( fco ) ) ? m_pContainer : NULL;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ReferenceImpl					// Extensions

	void ReferenceImpl::accept( Visitor* pVisitor )
	{
		if ( Model( getReferred() ) ) {
			ReferencePortSet ports = getRefPorts();
			for ( ReferencePortSet::iterator it = ports.begin() ; it != ports.end() ; it++ )
				(*it)->accept( pVisitor );
		}
		pVisitor->visitReference( Reference( this ) );
	}

	FCOExRegistryNode ReferenceImpl::getRegistry() const
	{
		return FCOImpl::getRegistry();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ConnectionImpl
//
//###############################################################################################################################################

	ConnectionImpl::ConnectionImpl()
		: FCOImpl(), m_bAllEnds( false )
	{
	}

	ConnectionImpl* ConnectionImpl::attachI( IMgaConnection* spConnection, ProjectImpl* pProject, const MON::Object& meta )
	{
		// Warning : Maybe it is an Exception
		if ( ! spConnection )
			return NULL;

		// Find it in Objects' cache
		pProject = _getProject( spConnection, pProject );
		ObjectImpl* pObject = find( pProject, spConnection );
		if ( pObject )
			return dynamic_cast<ConnectionImpl*>( pObject );

		// Get Extension
		pObject = getEx( spConnection, OT_Connection, meta );
		if ( ! pObject )
			pObject = new ConnectionImpl();
		pObject->doInitialize( spConnection, pProject, meta );
		dynamic_cast<FCOImpl*>( pObject )->doInitialize( pProject );
		pObject->initialize();
		
		ConnectionImpl* ci = dynamic_cast<ConnectionImpl*>( pObject );
		attachIPost( ci);
		return ci;
	}

	Connection ConnectionImpl::attach( IMgaConnection* spConnection )
	{
		return attachI( spConnection );
	}

	Connection ConnectionImpl::create( const Model& parent, const std::set<Connection::Pair>& ends, const MON::Connection& meta, const std::string& strRole )
	{
		if ( ! meta )
			return createAs( parent, ends, strRole );

		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		if ( meta.project() != parent->getProject()->getProjectMeta() )
		{
			MON::Exception exc( "? does not belong to ? of ?!");
			exc << meta.infoString() << parent->getProject()->getProjectMeta().infoString() << parent->getProject()->getInfoString();
			ASSERTTHROW( exc);
		}

		MON::Containment role;
		std::set<MON::Containment> metas = parent->getModelMeta().childContainments();
		for ( std::set<MON::Containment>::iterator it = metas.begin() ; it != metas.end() ; it++ ) {
			if ( it->child() == meta ) {
				if ( strRole.empty() ) {
					if ( role )
					{
						MON::Exception exc( "strRole cannot be an empty string because ? can contain ? as child with more than one MON::Containment!");
						exc << parent->getObjectMeta().infoString() << meta.infoString();
						ASSERTTHROW( exc);
					}
					role = *it;
				}
				else {
					role = *it;
					break;
				}
			}
		}

		if ( ! role )
		{
			MON::Exception exc( "? does not have ? as child!");
			exc << parent->getObjectMeta().infoString() << meta.infoString();
			ASSERTTHROW( exc);
		}

		return createI( parent, role, ends );
	}

	Connection ConnectionImpl::create( const Model& parent, const std::set<Connection::Pair>& ends, const std::string& strConnection, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );
		MON::Connection meta;
		if ( ! strConnection.empty() ) {
			meta = parent->getProject()->getProjectMeta().findByName( strConnection );
			if ( ! meta )
			{
				MON::Exception exc( "MON::Connection [ ? ] does not exist in ? of ?!");
				exc << strConnection << parent->getProject()->getProjectMeta().infoString() << parent->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}
		}
		return create( parent, ends, meta, strRole );
	}

	Connection ConnectionImpl::create( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const MON::Connection& meta, const std::string& strRole  )
	{
		std::set<Connection::Pair> ends;
		ends.insert( Connection::Pair( "src", srcEnd ) );
		ends.insert( Connection::Pair( "dst", dstEnd ) );
		return create( parent, ends, meta, strRole );
	}

	Connection ConnectionImpl::create( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const std::string& strConnection, const std::string& strRole  )
	{
		std::set<Connection::Pair> ends;
		ends.insert( Connection::Pair( "src", srcEnd ) );
		ends.insert( Connection::Pair( "dst", dstEnd ) );
		return create( parent, ends, strConnection, strRole );
	}

	Connection ConnectionImpl::createAs( const Model& parent, const std::set<Connection::Pair>& ends, const std::string& strRole )
	{
		THROW_CANNOT_BE_NULL( parent, "BON::Model" );

		MON::Containment role;
		std::set<MON::Containment> metas = parent->getModelMeta().childContainments();
		if ( strRole.empty() ) {
			for ( std::set<MON::Containment>::iterator it = metas.begin() ; it != metas.end() ; it++ ) {
				if ( it->child().type() == MON::OT_Connection ) {
					if ( role )
					{
						MON::Exception exc( "strRole cannot be an empty string because ? can contain more than one MON::Containment with child MON::Connection!");
						exc << parent->getObjectMeta().infoString();
						ASSERTTHROW( exc);
					}
					role = *it;
				}
			}
			if ( ! role )
			{
				MON::Exception exc( "? does not have MON::Connection as child!");
				exc << parent->getObjectMeta().infoString();
				ASSERTTHROW( exc);
			}
		}
		else {
			for ( std::set<MON::Containment>::iterator it = metas.begin() ; it != metas.end() ; it++ ) {
				if ( it->name() == strRole && it->child().type() == MON::OT_Connection ) {
					role = *it;
					break;
				}
			}
			if ( ! role )
			{
				MON::Exception exc( "? does not have MON::Connection as child with containment role [ ? ]!");
				exc << parent->getObjectMeta().infoString() << strRole;
				ASSERTTHROW( exc);
			}
		}

		return createI( parent, role, ends );
	}

	Connection ConnectionImpl::createAs( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const std::string& strRole )
	{
		std::set<Connection::Pair> ends;
		ends.insert( Connection::Pair( "src", srcEnd ) );
		ends.insert( Connection::Pair( "dst", dstEnd ) );
		return createAs( parent, ends, strRole );
	}

	ConnectionImpl::~ConnectionImpl()
	{
		if ( ! ObjectImpl::m_pProject->isDestructionActive() && ! isDeleted() ) {
			for ( ManyFCOLink::iterator it = m_ends.begin() ; it != m_ends.end() ; it++ )
				it->second->onReleasedAsConnectionEnd( this, it->first.first, false );
		}

		m_ends.clear();
		m_refWrappers.clear();
		m_fcoWrappers.clear();
	}

	bool ConnectionImpl::setDeleted()
	{
		if ( FCOImpl::setDeleted() )
			return true;

		for ( ManyFCOLink::iterator it = m_ends.begin() ; it != m_ends.end() ; it++ )
			it->second->onReleasedAsConnectionEnd( this, it->first.first, false );
		return false;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ConnectionImpl					// Get and Set Operations // ---> Interface Methods

	ObjectType ConnectionImpl::getStereotype() const
	{
		return OT_Connection;
	}

	ConnectionPtr ConnectionImpl::getConnectionI() const
	{
		CComQIPtr<IMgaConnection> spConnection = getObjectI().p;
		return spConnection.p;
	}

	MON::Connection ConnectionImpl::getConnectionMeta() const
	{
		return getObjectMeta();
	}

	std::string ConnectionImpl::getInfoString( unsigned short usOptions ) const
	{
		bool bAll = ( usOptions & Util::IO_All ) ? true : false;
		bool bIdent = bAll || ( usOptions & Util::IO_Identifiers );
		bool bLine = bAll || ( usOptions & Util::IO_NewLine );
		std::string strDelim = ( bLine ) ? "\n" : ", ";

		std::string strInfo = getInfoStringHelper( usOptions, "Connection" );
		if ( bAll || ( usOptions & Util::IO_Specific ) ) {
			( (ConnectionImpl*) this )->getConnEnds(); //WARNING

			unsigned short usOptions2 = 0;
			if ( bIdent )
				usOptions2 |= Util::IO_Identifiers;
			if ( bAll || ( usOptions & Util::IO_ID ) )
				usOptions2 |= Util::IO_ID;
			if ( bAll || ( usOptions & Util::IO_Meta ) )
				usOptions2 |= Util::IO_Meta;
			if ( bAll || ( usOptions & Util::IO_Path ) )
				usOptions2 |= Util::IO_Path;

			for ( ManyFCOLink::const_iterator it =  m_ends.begin() ; it != m_ends.end() ; it++ ) {
				strInfo += strDelim;
				if ( bIdent )
					strInfo += it->first.first + ": ";
				strInfo += it->second->getInfoString( usOptions2 );
			}
		}

		if ( ! bLine )
			strInfo += "]";

		return strInfo;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ConnectionImpl					// Relations

	ConnectionEndImpl* ConnectionImpl::getConnectionEndI( const std::string& strRole, const MON::FCO& meta )
	{
		if ( ! m_bAllEnds ) {
			m_bAllEnds = true;
			Util::ComPtr<IMgaConnPoints> spCPs;
			COMTHROW( getConnectionI()->get_ConnPoints( spCPs.Addr() ) );
			MGACOLL_ITERATE( IMgaConnPoint, spCPs.p ) {
				CComBSTR bstrRole;
				COMTHROW( MGACOLL_ITER->get_ConnRole( &bstrRole ) );
				FCOPtr spTarget;
				COMTHROW( MGACOLL_ITER->get_Target( spTarget.Addr() ) );
				MON::Connection::Pair key( Util::Copy( bstrRole ), MON::FCO( getProject()->getProjectMeta().findByName( _getMetaName( spTarget ) ) ) );
				if ( m_ends.find( key ) == m_ends.end() ) {
					ConnectionEndImpl* pCE = ConnectionEndImpl::attachI( MGACOLL_ITER, ObjectImpl::m_pProject, key.second );
					m_ends[ key ] = pCE;
					if( !pCE) ASSERT(0);
					else pCE->onRetrievedAsConnectionEnd( this, Util::Copy( bstrRole ), false );
				}
			} MGACOLL_ITERATE_END;
		}

		for ( ManyFCOLink::iterator it = m_ends.begin() ; it != m_ends.end() ; ++it )
			if ( ( strRole.empty() || strRole == it->first.first ) && ( ! meta || meta == it->first.second ) )
				return it->second;
		return NULL;
	}

	ConnectionImpl* ConnectionImpl::createI( const Model& parent, const MON::Containment& meta, const std::set<Connection::Pair>& ends )
	{
		if ( ! MON::Connection( meta.child() ).isSimple() )
		{
			MON::Exception exc( "? is not simple. Not binary MON::Connections are supported!");
			exc << meta.child().infoString();
			ASSERTTHROW( exc);
		}

		std::map<std::string, FCOsPtr> mapRefSeqs;
		std::map<std::string,FCO> mapEnds;

		std::set<Connection::Pair>::const_iterator it;
		for ( it = ends.begin() ; it != ends.end() ; it++ ) {
			THROW_CANNOT_BE_NULL( it->second, "BON::ConnectionEnd" );
			if ( parent->getProject() != it->second->getProject() )
			{
				BON::Exception exc( "? does not belong to ?!");
				exc << it->second->getInfoString() << parent->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}

			mapRefSeqs[ it->first ] = FCOsPtr();
			if ( it->second->isReferencePort() ) {
				ReferencePort port( it->second );
				mapEnds[ it->first ] = port->getFCO();
				Reference ref = port->getContainer()->getReference();
				while ( ref ) {
					COMTHROW( ref->getFCOI()->CreateCollection( mapRefSeqs[ it->first ].Addr() ) );
					ref = ref->getReferred();
				}
			}
			else {
				mapEnds[ it->first ] = it->second;
			}
		}

		std::set<MON::ConnectionRole> roles = MON::Connection( meta.child() ).specification( 0 ).roles();
		if ( roles.size() != mapEnds.size() )
		{
			Exception exc( "Number of MON::ConnectionEnds of ? is ?, not ?");
			exc << meta.infoString() << (long) roles.size() << (long) mapEnds.size();
			ASSERTTHROW( exc);
		}

		std::set<MON::ConnectionRole>::iterator itR;
		for ( itR = roles.begin() ; itR != roles.end() ; itR++ )
			if ( mapEnds.find( itR->name() ) == mapEnds.end() )
			{
				Exception exc( "BON::ConnectionEnd of ? at role [ ? ]  is unspecified.");
				exc << meta.infoString() << itR->name();
				ASSERTTHROW( exc);
			}

#ifdef TEST_META_CONFORMANCE_INSIDE_BON

		bool bOK = false;
		for ( int i = 0 ; i < MON::Connection( meta.child() ).specificationCount() && ! bOK ; i++ ) {
			bOK = true;
			roles = MON::Connection( meta.child() ).specification( i ).roles();
			for ( itR = roles.begin() ; itR != roles.end() ; itR++ ) {
				if ( ! itR->isTarget( mapEnds[ itR->name() ]->getRole() ) ) {
					bOK = false;
					break;
				}
			}
		}

		if ( ! bOK ) {
			std::vector<std::string> vecParams;
			std::string strEx;
			for ( it = ends.begin() ; it != ends.end() ; it++ ) {
				if ( ends.begin() != it )
					strEx += ", ";
				strEx += "? with role [ ? ]";
				vecParams.push_back( it->second->getInfoString() );
				vecParams.push_back( it->first );
			}
			strEx += " cannot be connected with ?!";
			ASSERTTHROW( MON::Exception( strEx, vecParams ) );
		}

#endif

		FCOPtr spFCO;
		COMTHROW( parent->getModelI()->CreateSimpleConn( meta.getContainmentI(), mapEnds[ "src" ]->getFCOI(), mapEnds[ "dst" ]->getFCOI(), mapRefSeqs[ "src" ], mapRefSeqs[ "dst" ], spFCO.Addr() ) );
		ConnectionImpl* pConnection = ConnectionImpl::attachI( CComQIPtr<IMgaConnection>( spFCO.p ), (ProjectImpl*) parent->getProject().getCounted(), meta.child() );
		if ( pConnection->getProject()->isAutoCommit() )
			pConnection->getProject()->commit();
		if ( ! _isAddOn() )
			pConnection->eventPerformedI( Event( MON::OET_ObjectCreated, pConnection ) );
		return pConnection;
	}

//===============================================================================================================================================
// 	C L A S S : BON::ConenctionImpl					// Event Handlers

	bool ConnectionImpl::onRetrievedAsConnection( ConnectionEndImpl* pCE, const std::string& strRole, bool bCheckAll )
	{
		if ( ! m_bAllEnds && bCheckAll )
			return false;
		m_ends[ MON::Connection::Pair( strRole, pCE->getFCOHelper()->getFCOMeta() ) ] = pCE;
		return true;
	}

	void ConnectionImpl::onReleasedAsConnection( ConnectionEndImpl* pCE, const std::string& strRole, bool bOnlyFreeMemory )
	{
		for ( ManyFCOLink::iterator it = m_ends.begin() ; it != m_ends.end() ; it++ )
			if ( it->first.first == strRole ) {
				m_ends.erase( it );
				break;
			}
		m_bAllEnds = false;
	}

	void ConnectionImpl::eventPerformedI( const Event& event )
	{
		FCOImpl::eventPerformedI( event );
		switch ( event.getType() ) {
			case MON::OET_ObjectCreated :
				onObjectCreated();
				break;
		}
	}

	void ConnectionImpl::onObjectCreated()
	{
		std::multiset<ConnectionEnd> ss = getConnEnds();
		for( std::multiset<ConnectionEnd>::const_iterator it = ss.begin(); it != ss.end(); ++it)
		{
			ReferencePort rpi( *it);
			if( rpi) // if it's a referenceport
			{
				Reference the_ref = rpi->getContainer()->getReference();
				m_refWrappers.insert( the_ref );
				FCO the_target = rpi->getFCO();
				m_fcoWrappers.insert( the_target);
			}
		}
	}

//===============================================================================================================================================
// 	C L A S S : BON::ConnectionImpl					// Relations // ---> Interface Methods

	std::multiset<ConnectionEnd> ConnectionImpl::getConnEnds( const MON::FCO& meta )
	{
		if ( meta )
			THROW_METAPROJECT_BELONG( meta );

		std::set<std::string> theRoles;

		bool bFound = false;
		for ( int i = 0 ; i < getConnectionMeta().specificationCount() ; i++ ) {
			std::set<MON::ConnectionRole> roles = getConnectionMeta().specification( i ).roles();
			for ( std::set<MON::ConnectionRole>::iterator it = roles.begin() ; it != roles.end() ; it++ ) {
				if ( ! meta || it->isTarget( meta ) ) {
					bFound = true;
					theRoles.insert( it->name() );
				}
			}
		}

		if ( ! bFound )
		{
			MON::Exception exc( "? cannot be target of ?!");
			exc << meta.infoString() << getObjectMeta().infoString();
			ASSERTTHROW( exc);
		}

		std::multiset<ConnectionEnd> setResult;
		for ( std::set<std::string>::iterator it = theRoles.begin() ; it != theRoles.end() ; it++ ) {
			ConnectionEndImpl* pEnd = getConnectionEndI( *it, meta );
			if ( pEnd )
				setResult.insert( pEnd );
		}

		return setResult;
	}

	std::multiset<ConnectionEnd> ConnectionImpl::getConnEnds( const std::string& strFCO )
	{
		MON::FCO meta;
		if ( ! strFCO.empty() ) {
			meta = MON::FCO( getProject()->getProjectMeta().findByName( strFCO ) );
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, FCO, strFCO );
		}
		return getConnEnds( meta );
	}

	ConnectionEnd ConnectionImpl::getConnEnd( const std::string& strRole, const MON::FCO& meta )
	{
		THROW_CANNOT_BE_EMPTY( "Role", strRole );
		if ( meta )
			THROW_METAPROJECT_BELONG( meta );

#ifdef TEST_META_CONFORMANCE_INSIDE_BON

		bool bRoleFound  = false;
		bool bFound = false;
		for ( int i = 0 ; i < getConnectionMeta().specificationCount() ; i++ ) {
			std::set<MON::ConnectionRole> roles = getConnectionMeta().specification( i ).roles();
			for ( std::set<MON::ConnectionRole>::iterator it = roles.begin() ; it != roles.end() ; it++ ) {
				if ( strRole == it->name() ) {
					bRoleFound = true;
					if ( ! meta || it->isTarget( meta ) ) {
						bFound = true;
						break;
					}
				}
			}
			if ( bFound )
				break;
		}

		if ( ! bRoleFound )
		{
			MON::Exception exc( "? cannot be has role ?!");
			exc << getObjectMeta().infoString() << strRole.c_str();
			ASSERTTHROW( exc);
		}
		if ( ! bFound )
		{
			MON::Exception exc( "? cannot be target of ? with role ?!");
			exc << meta.infoString() << getObjectMeta().infoString() << strRole;
			ASSERTTHROW( exc);
		}

#endif

		return getConnectionEndI( strRole, meta );
	}

	ConnectionEnd ConnectionImpl::getConnEnd( const std::string& strRole, const std::string& strFCO )
	{
		MON::FCO meta;
		if ( ! strFCO.empty() ) {
			meta = MON::FCO( getProject()->getProjectMeta().findByName( strFCO ) );
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, FCO, strFCO );
		}
		return getConnEnd( strRole, meta );
	}

	ConnectionEnd ConnectionImpl::getSrc( const MON::FCO& meta )
	{
		if ( ! getConnectionMeta().isSimple() )
		{
			MON::Exception exc( "? is not simple!");
			exc << getObjectMeta().infoString();
			ASSERTTHROW( exc);
		}
		return getConnEnd( "src", meta );
	}

	ConnectionEnd ConnectionImpl::getSrc( const std::string& strFCO )
	{
		if ( ! getConnectionMeta().isSimple() )
		{
			MON::Exception exc( "? is not simple!");
			exc << getObjectMeta().infoString();
			ASSERTTHROW( exc);
		}
		return getConnEnd( "src", strFCO );
	}

	ConnectionEnd ConnectionImpl::getDst( const MON::FCO& meta )
	{
		if ( ! getConnectionMeta().isSimple() )
		{
			MON::Exception exc( "? is not simple!");
			exc << getObjectMeta().infoString();
			ASSERTTHROW( exc);
		}
		return getConnEnd( "dst", meta );
	}

	ConnectionEnd ConnectionImpl::getDst( const std::string& strFCO )
	{
		if ( ! getConnectionMeta().isSimple() )
		{
			MON::Exception exc( "? is not simple!");
			exc << getObjectMeta().infoString();
			ASSERTTHROW( exc);
		}
		return getConnEnd( "dst", strFCO );
	}

//===============================================================================================================================================
// 	C L A S S : BON::ConnectionImpl					// Extensions

	void ConnectionImpl::accept( Visitor* pVisitor )
	{
		pVisitor->visitConnection( Connection( this ) );
	}

	ConnectionRegistryNode ConnectionImpl::getRegistry() const
	{
		return FCOImpl::getRegistry();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ReferencePortContainerImpl
//
//###############################################################################################################################################

	ReferencePortContainerImpl::ReferencePortContainerImpl( ReferenceImpl* pReference )
		: Util::GenRefCounted( false, pReference ), m_pReference( pReference )
	{
	}

	Project ReferencePortContainerImpl::getProject() const
	{
		return m_pReference->getProject();
	}

	Reference ReferencePortContainerImpl::getReference() const
	{
		return m_pReference;
	}

	std::set<ReferencePort> ReferencePortContainerImpl::getReferencePorts()
	{
		std::set<ReferencePort> setResult;
		setCopy<ReferencePort,ReferencePortImpl>( m_pReference->getRefPorts(), setResult );
		return setResult;
	}

	ReferencePort ReferencePortContainerImpl::getReferencePort( const FCO& fco )
	{
		THROW_CANNOT_BE_NULL( fco, "BON::FCO" );
		THROW_PROJECT_BELONG( fco )
		return m_pReference->getRefPort( dynamic_cast<FCOImpl*>( fco.getCounted() ) );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::TypeInhObjectImpl
//
//###############################################################################################################################################

	TypeInhObjectImpl::TypeInhObjectImpl( FCOImpl* pFCO )
		: Util::GenRefCounted( false, pFCO ), m_pFCO( pFCO )
	{
	}

	bool TypeInhObjectImpl::setDeleted()
	{
		return isDeleted();
	}

	Project TypeInhObjectImpl::getProject() const
	{
		return m_pFCO->getProject();
	}

	FCO TypeInhObjectImpl::getFCO() const
	{
		return m_pFCO;
	}

	bool TypeInhObjectImpl::isInstance() const
	{
		return m_pFCO->isInstance();
	}

	Type TypeInhObjectImpl::getType()
	{
		FCOImpl* pFCO = m_pFCO->getType();
		return ( pFCO ) ? pFCO->getTypeInhObject() : Type( NULL );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::InstanceImpl
//
//###############################################################################################################################################

	InstanceImpl::InstanceImpl( FCOImpl* pFCO )
		: TypeInhObjectImpl( pFCO )
	{
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::TypeImpl
//
//###############################################################################################################################################

	TypeImpl::TypeImpl( FCOImpl* pFCO )
		: TypeInhObjectImpl( pFCO )
	{
	}

	std::set<Type> TypeImpl::getSubTypes()
	{
		FCOSet fcos = m_pFCO->getDerivedFCOs( false );
		std::set<Type> setResult;
		for ( FCOSet::iterator it = fcos.begin() ; it != fcos.end() ; it++ )
			setResult.insert( (*it)->getTypeInhObject() );
		return setResult;
	}

	std::set<Instance> TypeImpl::getInstance()
	{
		FCOSet fcos = m_pFCO->getDerivedFCOs( true );
		std::set<Instance> setResult;
		for ( FCOSet::iterator it = fcos.begin() ; it != fcos.end() ; it++ )
			setResult.insert( (*it)->getTypeInhObject() );
		return setResult;
	}

	std::set<TypeInhObject> TypeImpl::getDerivedObjects()
	{
		std::set<TypeInhObject> setResult;
		FCOSet fcos1 = m_pFCO->getDerivedFCOs( false );
		FCOSet fcos2 = m_pFCO->getDerivedFCOs( true );

		FCOSet::iterator it;
		for ( it = fcos1.begin() ; it != fcos1.end() ; it++ )
			setResult.insert( (*it)->getTypeInhObject() );
		for ( it = fcos2.begin() ; it != fcos2.end() ; it++ )
			setResult.insert( (*it)->getTypeInhObject() );
		return setResult;
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::FCORegistryNodeImpl
//
//###############################################################################################################################################

	FCORegistryNodeImpl::FCORegistryNodeImpl( FCOImpl* pObject )
		: RegistryNodeImpl( NULL, pObject )
	{
	}

	COLORREF FCORegistryNodeImpl::getColor() const
	{
		COLORREF color;
		return ( Convert( getObject()->getRegistry()->getValueByPath( PREF_Color ), color ) ) ? color : RGB( 00, 00, 00 );
	}

	void FCORegistryNodeImpl::setColor( COLORREF color )
	{
		getObject()->getRegistry()->setValueByPath( PREF_Color, Convert( color ) );
	}

	COLORREF FCORegistryNodeImpl::getNameColor() const
	{
		COLORREF color;
		return ( Convert( getObject()->getRegistry()->getValueByPath( PREF_NameColor ), color ) ) ? color : RGB( 00, 00, 00 );
	}

	void FCORegistryNodeImpl::setNameColor( COLORREF color )
	{
		getObject()->getRegistry()->setValueByPath( PREF_NameColor, Convert( color ) );
	}

	bool FCORegistryNodeImpl::getNameEnabled() const
	{
		std::string strValue = getObject()->getRegistry()->getValueByPath( PREF_NameEnabled );
		return ( strValue.empty() ) ? true : (bool) Util::Variant( strValue );
	}

	void FCORegistryNodeImpl::setNameEnabled( bool bEnabled )
	{
		getObject()->getRegistry()->setValueByPath( PREF_NameEnabled, (std::string) Util::Variant( bEnabled ) );
	}

	std::string FCORegistryNodeImpl::getHelpURL() const
	{
		return getObject()->getRegistry()->getValueByPath( PREF_HelpURL );
	}

	void FCORegistryNodeImpl::setHelpURL( const std::string& strURL )
	{
		getObject()->getRegistry()->setValueByPath( PREF_HelpURL, strURL );
	}

	std::set<AutoRouterPref> FCORegistryNodeImpl::getInAutoRouterPref() const
	{
		return std::set<AutoRouterPref>();
	}

	void FCORegistryNodeImpl::setInAutoRouterPref( const std::set<AutoRouterPref>& setPrefs )
	{
	}

	std::set<AutoRouterPref> FCORegistryNodeImpl::getOutAutoRouterPref() const
	{
		return std::set<AutoRouterPref>();
	}

	void FCORegistryNodeImpl::setOutAutoRouterPref( const std::set<AutoRouterPref>& setPrefs )
	{
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::FCOExRegistryNodeImpl
//
//###############################################################################################################################################

	FCOExRegistryNodeImpl::FCOExRegistryNodeImpl( FCOImpl* pObject )
		: FCORegistryNodeImpl( pObject )
	{
	}

	Point FCOExRegistryNodeImpl::getLocation( const MON::Aspect& aspect ) const
	{
		if ( aspect ) {
			if ( getObject()->getProject()->getProjectMeta() != aspect.project() )
			{
				MON::Exception exc( "? does not belong to ? of ?!");
				exc << aspect.infoString() << getObject()->getProject()->getProjectMeta().infoString() << getObject()->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}

			Point point;
			std::string strLocation = getObject()->getRegistry()->getValueByPath( PREF_Location1 + aspect.name() + PREF_Location2 );
			return ( sscanf( strLocation.c_str(), "%d,%d", &(point.first), &(point.second) ) == 2 ) ? point : Point( 0, 0 );
		}

		if ( ! FCO( getObject() )->getRole() )
			return Point( 0, 0 );
		std::set<MON::ContainmentPart> parts = FCO( getObject() )->getRole().parts();
		if ( parts.empty() )
			return Point( 0, 0 );

		std::set<MON::ContainmentPart>::iterator it;
		for ( it = parts.begin() ; it != parts.end() ; it++ )
			if ( it->isPrimary() ) {
				Point point;
				std::string strLocation = getObject()->getRegistry()->getValueByPath( PREF_Location1 + it->aspect().name() + PREF_Location2 );
				if ( sscanf( strLocation.c_str(), "%d,%d", &(point.first), &(point.second) ) == 2 )
					return point;
				else
					break;
			}

		it = parts.begin();
		Point point;
		std::string strLocation = getObject()->getRegistry()->getValueByPath( PREF_Location1 + it->aspect().name() + PREF_Location2 );
		return ( sscanf( strLocation.c_str(), "%d,%d", &(point.first), &(point.second) ) == 2 ) ? point : Point( 0, 0 );
	}

	void FCOExRegistryNodeImpl::setLocation( const Point& point, const MON::Aspect& aspect )
	{
		if ( aspect ) {
			if ( getObject()->getProject()->getProjectMeta() != aspect.project() )
			{
				MON::Exception exc( "? does not belong to ? of ?!");
				exc << aspect.infoString() << getObject()->getProject()->getProjectMeta().infoString() << getObject()->getProject()->getInfoString();
				ASSERTTHROW( exc);
			}

			char chBuffer[ 100 ];
			sprintf( chBuffer, "%d,%d", point.first, point.second );
			getObject()->getRegistry()->setValueByPath( PREF_Location1 + aspect.name() + PREF_Location2, std::string( chBuffer ) );
			return;
		}

		if ( FCO( getObject() )->getRole() ) {

			char chBuffer[ 100 ];
			sprintf( chBuffer, "%d,%d", point.first, point.second );

			std::set<MON::ContainmentPart> parts = FCO( getObject() )->getRole().parts();
			for ( std::set<MON::ContainmentPart>::iterator it = parts.begin() ; it != parts.end() ; it++ )
				getObject()->getRegistry()->setValueByPath( PREF_Location1 + it->aspect().name() + PREF_Location2, std::string( chBuffer ) );
		}
	}

	Point FCOExRegistryNodeImpl::getLocation( const std::string& strAspect ) const
	{
		MON::Aspect meta;
		if ( ! strAspect.empty() ) {
			meta = getProject()->getProjectMeta().findByName( strAspect );
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, Aspect, strAspect );
		}
		return getLocation( meta );
	}

	void FCOExRegistryNodeImpl::setLocation( const Point& point, const std::string& strAspect )
	{
		MON::Aspect meta;
		if ( ! strAspect.empty() ) {
			meta = getProject()->getProjectMeta().findByName( strAspect );
			THROW_METAPROJECT_DOES_NOT_HAVE( meta, Aspect, strAspect );
		}
		setLocation( point, meta );
	}

	NamePosition FCOExRegistryNodeImpl::getNamePosition() const
	{
		NamePosition ePos;
		return ( ! Convert( getObject()->getRegistry()->getValueByPath( PREF_NamePosition ), ePos ) ) ? ePos : NP_South;
	}

	void FCOExRegistryNodeImpl::setNamePosition( NamePosition pos )
	{
		getObject()->getRegistry()->setValueByPath( PREF_NamePosition, Convert( pos ) );
	}

	unsigned short FCOExRegistryNodeImpl::getNameWrap() const
	{
		long lWrap = (long) Util::Variant( getObject()->getRegistry()->getValueByPath( PREF_NameWrap ) );
		return ( lWrap < 0 ) ? 0 : (unsigned short) lWrap;
	}

	void FCOExRegistryNodeImpl::setNameWrap( unsigned short usWrap )
	{
		getObject()->getRegistry()->setValueByPath( PREF_NameWrap, (std::string) Util::Variant( (long) usWrap ) );
	}

	bool FCOExRegistryNodeImpl::getHotspotEnabled() const
	{
		std::string strHot = getObject()->getRegistry()->getValueByPath( PREF_HotSpotEnabled );
		return ( strHot.empty() ) ? true : (bool) Util::Variant( strHot );
	}

	void FCOExRegistryNodeImpl::setHotspotEnabled( bool bEnabled )
	{
		getObject()->getRegistry()->setValueByPath( PREF_HotSpotEnabled, (std::string) Util::Variant( bEnabled ) );
	}

	bool FCOExRegistryNodeImpl::getTypeNameEnabled() const
	{
		std::string strEnabled = getObject()->getRegistry()->getValueByPath( PREF_TypeNameEnabled );
		return ( strEnabled.empty() ) ? true : (bool) Util::Variant( strEnabled );
	}

	void FCOExRegistryNodeImpl::setTypeNameEnabled( bool bEnabled )
	{
		getObject()->getRegistry()->setValueByPath( PREF_TypeNameEnabled, (std::string) Util::Variant( bEnabled ) );
	}

	bool FCOExRegistryNodeImpl::getTypeInfoEnabled() const
	{
		std::string strEnabled = getObject()->getRegistry()->getValueByPath( PREF_TypeInfoEnabled );
		return ( strEnabled.empty() ) ? true : (bool) Util::Variant( strEnabled );
	}

	void FCOExRegistryNodeImpl::setTypeInfoEnabled( bool bEnabled )
	{
		getObject()->getRegistry()->setValueByPath( PREF_TypeInfoEnabled, (std::string) Util::Variant( bEnabled ) );
	}

	std::string FCOExRegistryNodeImpl::getDecorator() const
	{
		return getObject()->getRegistry()->getValueByPath( PREF_Decorator );
	}

	void FCOExRegistryNodeImpl::setDecorator( const std::string& strName )
	{
		getObject()->getRegistry()->setValueByPath( PREF_Decorator, strName );
	}

	std::string FCOExRegistryNodeImpl::getIcon() const
	{
		return getObject()->getRegistry()->getValueByPath( PREF_Icon );
	}

	void FCOExRegistryNodeImpl::setIcon( const std::string& strName ) const
	{
		getObject()->getRegistry()->setValueByPath( PREF_Icon, strName );
	}

	std::string FCOExRegistryNodeImpl::getPortIcon() const
	{
		return getObject()->getRegistry()->getValueByPath( PREF_PortIcon );
	}

	void FCOExRegistryNodeImpl::setPortIcon( const std::string& strName ) const
	{
		getObject()->getRegistry()->setValueByPath( PREF_PortIcon, strName );
	}

	std::string FCOExRegistryNodeImpl::getSubTypeIcon() const
	{
		return getObject()->getRegistry()->getValueByPath( PREF_SubTypeIcon );
	}

	void FCOExRegistryNodeImpl::setSubTypeIcon( const std::string& strName ) const
	{
		getObject()->getRegistry()->setValueByPath( PREF_SubTypeIcon, strName );
	}

	std::string FCOExRegistryNodeImpl::getInstanceIcon() const
	{
		return getObject()->getRegistry()->getValueByPath( PREF_InstanceIcon );
	}

	void FCOExRegistryNodeImpl::setInstanceIcon( const std::string& strName ) const
	{
		getObject()->getRegistry()->setValueByPath( PREF_InstanceIcon, strName );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ModelRegistryNodeImpl
//
//###############################################################################################################################################

	ModelRegistryNodeImpl::ModelRegistryNodeImpl( ModelImpl* pModel )
		: FCOExRegistryNodeImpl( pModel )
	{
	}

	COLORREF ModelRegistryNodeImpl::getBorderColor() const
	{
		COLORREF color;
		return ( Convert( getObject()->getRegistry()->getValueByPath( PREF_BorderColor ), color ) ) ? color : RGB( 0, 0, 0 );
	}

	void ModelRegistryNodeImpl::setBorderColor( COLORREF color )
	{
		getObject()->getRegistry()->setValueByPath( PREF_BorderColor, Convert( color ) );
	}

	COLORREF ModelRegistryNodeImpl::getBackgroundColor() const
	{
		COLORREF color;
		return ( Convert( getObject()->getRegistry()->getValueByPath( PREF_BackgroundColor ), color ) ) ? color : RGB( 0, 0, 0 );
	}

	void ModelRegistryNodeImpl::setBackgroundColor( COLORREF color )
	{
		getObject()->getRegistry()->setValueByPath( PREF_BackgroundColor, Convert( color ) );
	}

	COLORREF ModelRegistryNodeImpl::getPortNameColor() const
	{
		COLORREF color;
		return ( Convert( getObject()->getRegistry()->getValueByPath( PREF_PortNameColor ), color ) ) ? color : RGB( 0, 0, 0 );
	}

	void ModelRegistryNodeImpl::setPortNameColor( COLORREF color )
	{
		getObject()->getRegistry()->setValueByPath( PREF_PortNameColor, Convert( color ) );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ConnectionRegistryNodeImpl
//
//###############################################################################################################################################

	ConnectionRegistryNodeImpl::ConnectionRegistryNodeImpl( ConnectionImpl* pConnection )
		: FCORegistryNodeImpl( pConnection )
	{
	}

	LineType ConnectionRegistryNodeImpl::getLineType() const
	{
		LineType eType;
		return ( Convert( getObject()->getRegistry()->getValueByPath( PREF_LineType ), eType ) ) ? eType : LT_Solid;
	}

	void ConnectionRegistryNodeImpl::setLineType( LineType eType )
	{
		getObject()->getRegistry()->setValueByPath( PREF_LineType, Convert( eType ) );
	}

	LineEndType ConnectionRegistryNodeImpl::getSrcLineEndType() const
	{
		LineEndType eType;
		return ( Convert( getObject()->getRegistry()->getValueByPath( PREF_SrcLineEndType ), eType ) ) ? eType : LET_Butt;
	}

	void ConnectionRegistryNodeImpl::setSrcLineEndType( LineEndType eType )
	{
		getObject()->getRegistry()->setValueByPath( PREF_SrcLineEndType, Convert( eType ) );
	}

	LineEndType ConnectionRegistryNodeImpl::getDstLineEndType() const
	{
		LineEndType eType;
		return ( Convert( getObject()->getRegistry()->getValueByPath( PREF_DstLineEndType ), eType ) ) ? eType : LET_Butt;
	}

	void ConnectionRegistryNodeImpl::setDstLineEndType( LineEndType eType )
	{
		getObject()->getRegistry()->setValueByPath( PREF_DstLineEndType, Convert( eType ) );
	}

	std::string ConnectionRegistryNodeImpl::getLabel() const
	{
		return getObject()->getRegistry()->getValueByPath( PREF_LabelFormat );
	}

	void ConnectionRegistryNodeImpl::setLabel( const std::string& strFormat )
	{
		getObject()->getRegistry()->setValueByPath( PREF_LabelFormat, strFormat );
	}

	std::string ConnectionRegistryNodeImpl::getSrcLabel1() const
	{
		return getObject()->getRegistry()->getValueByPath( PREF_SrcLabel1 );
	}

	void ConnectionRegistryNodeImpl::setSrcLabel1( const std::string& strFormat )
	{
		getObject()->getRegistry()->setValueByPath( PREF_SrcLabel1, strFormat );
	}

	std::string ConnectionRegistryNodeImpl::getSrcLabel2() const
	{
		return getObject()->getRegistry()->getValueByPath( PREF_SrcLabel2 );
	}

	void ConnectionRegistryNodeImpl::setSrcLabel2( const std::string& strFormat )
	{
		getObject()->getRegistry()->setValueByPath( PREF_SrcLabel2, strFormat );
	}

	std::string ConnectionRegistryNodeImpl::getDstLabel1() const
	{
		return getObject()->getRegistry()->getValueByPath( PREF_DstLabel1 );
	}

	void ConnectionRegistryNodeImpl::setDstLabel1( const std::string& strFormat )
	{
		getObject()->getRegistry()->setValueByPath( PREF_DstLabel1, strFormat );
	}

	std::string ConnectionRegistryNodeImpl::getDstLabel2() const
	{
		return getObject()->getRegistry()->getValueByPath( PREF_DstLabel2 );
	}

	void ConnectionRegistryNodeImpl::setDstLabel2( const std::string& strFormat )
	{
		getObject()->getRegistry()->setValueByPath( PREF_DstLabel2, strFormat );
	}

}; // namespace BON
