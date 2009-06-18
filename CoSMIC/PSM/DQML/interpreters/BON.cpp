//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	BON.cpp
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

#include "stdafx.h"
#include "BON.h"
#include "BONImpl.h"


#pragma warning(disable:4073) 
#pragma init_seg(lib) 
#pragma warning(default:4073) 

namespace BON
{

//###############################################################################################################################################
//
// 	C L A S S : BON::Project
//
//###############################################################################################################################################

	Project::Project( ProjectImpl* pProject )
		: Util::GenRefCounter( pProject )
	{
	}

	Project::Project( const Project& project )
		: Util::GenRefCounter( project )
	{
	}

	Project& Project::operator = ( const Project& project )
	{
		using namespace Util;
		GenRefCounter::operator=( project );
		return *this;
	}

	Project Project::attach( IMgaProject* spProject )
	{
		return Project( ProjectImpl::attach( spProject ) );
	}

	ProjectImpl* Project::operator -> () const
	{
		return (ProjectImpl*) getCounted();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::Object
//
//###############################################################################################################################################

	Object::Object( ObjectImpl* pObject )
	{
		setCounted( pObject );
	}

	Object::Object( const Object& object )
	{
		setCounted( object.getCounted( false ) );
	}

	Object& Object::operator = ( const Object& object )
	{
		using namespace Util;
		GenRefCounter::operator=( object );
		return *this;
	}

	bool Object::castObjectImpl( ObjectType eType, ObjectType eType2 )
	{
		if ( getCounted( false ) ) {
			ObjectType oType = dynamic_cast<ObjectImpl*>( getCounted() )->getStereotype();
			if ( eType2 == OT_Null && oType != eType || eType2 != OT_Null && ( oType < eType || oType > eType2 ) ) {
				setCounted( NULL );
				return false;
			}
		}
		return true;
	}

	Object Object::attach( IMgaObject* spObject )
	{
		return Object( ObjectImpl::attach( spObject ) );
	}

	ObjectImpl* Object::operator -> () const
	{
		return dynamic_cast<ObjectImpl*>( getCounted() );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::RegistryNode
//
//###############################################################################################################################################

	RegistryNode::RegistryNode( const RegistryNode& node )
		: Util::GenRefCounter( node )
	{
	}

	RegistryNode::RegistryNode( RegistryNodeImpl* pNode )
		: Util::GenRefCounter( pNode )
	{
	}

	RegistryNode& RegistryNode::operator = ( const RegistryNode& object )
	{
		using namespace Util;
		GenRefCounter::operator=( object );
		return *this;
	}

	RegistryNodeImpl* RegistryNode::operator -> () const
	{
		return (RegistryNodeImpl*) getCounted();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::Folder
//
//###############################################################################################################################################

	const ObjectType Folder::type = OT_Folder;
	const std::string Folder::string_type = "BON::Folder";
	std::vector<std::string> Folder::vecDerivedKinds;
	const int Folder::inheritance_level = 1;

	void Folder::addDerivedKinds( const std::vector<std::string>& vecKinds )
	{
		for ( std::vector<std::string>::const_iterator it = vecKinds.begin() ; it != vecKinds.end() ; it++ )
			vecDerivedKinds.push_back( *it );
	}

	Folder::Folder( FolderImpl* pObject )
		: Object( pObject )
	{
	}

	Folder::Folder( const Object& object )
		: Object( object )
	{
		castObjectImpl( OT_Folder );
	}

	Folder& Folder::operator = ( const Object& object )
	{
		Object::operator=( object );
		castObjectImpl( OT_Folder );
		return *this;
	}

	Folder Folder::attach( IMgaObject* spObject )
	{
		CComQIPtr<IMgaFolder> spFolder = spObject;
		return Folder( ( spFolder ) ? FolderImpl::attach( spFolder ) : NULL );
	}

	Folder Folder::create( const Folder& parent, const MON::Folder& meta )
	{
		return FolderImpl::create( parent, meta );
	}

	Folder Folder::create( const Folder& parent, const std::string& strFolder )
	{
		return FolderImpl::create( parent, strFolder );
	}

	FolderImpl* Folder::operator -> () const
	{
		return dynamic_cast<FolderImpl*>( getCounted() );
	}
//###############################################################################################################################################
//
// 	C L A S S : BON::ConnectionEnd
//
//###############################################################################################################################################

	ConnectionEnd::ConnectionEnd( ConnectionEndImpl* pObject )
	{
		setCounted( pObject );
	}

	ConnectionEnd::ConnectionEnd( const ConnectionEnd& object )
	{
		setCounted( object.getCounted( false ) );
	}

	ConnectionEnd& ConnectionEnd::operator = ( const ConnectionEnd& object )
	{
		using namespace Util;
		GenRefCounter::operator=( object );
		return *this;
	}

	ConnectionEndImpl* ConnectionEnd::operator -> () const
	{
		return dynamic_cast<ConnectionEndImpl*>( getCounted() );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ReferencePort
//
//###############################################################################################################################################

	ReferencePort::ReferencePort( ReferencePortImpl* pObject )
		: ConnectionEnd( pObject )
	{
	}

	ReferencePort::ReferencePort( const ConnectionEnd& object )
		: ConnectionEnd( object )
	{
		if ( getCounted( false ) && ! dynamic_cast<ConnectionEndImpl*>( getCounted() )->isReferencePort() )
			setCounted( NULL );
	}

	ReferencePort& ReferencePort::operator = ( const ConnectionEnd& object )
	{
		ConnectionEnd::operator=( object );
		if ( this != &object && getCounted( false ) && ! dynamic_cast<ConnectionEndImpl*>( getCounted() )->isReferencePort()  )
			setCounted( NULL );
		return *this;
	}

	ReferencePortImpl* ReferencePort::operator -> () const
	{
		return dynamic_cast<ReferencePortImpl*>( getCounted() );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::FCO
//
//###############################################################################################################################################

	const ObjectType FCO::type = OT_Null;
	const std::string FCO::string_type = "BON::FCO";
	std::vector<std::string> FCO::vecDerivedKinds;
	const int FCO::inheritance_level = 0;

	void FCO::addDerivedKinds( const std::vector<std::string>& vecKinds )
	{
		for ( std::vector<std::string>::const_iterator it = vecKinds.begin() ; it != vecKinds.end() ; it++ )
			vecDerivedKinds.push_back( *it );
	}

	FCO::FCO( FCOImpl* pObject )
		: Object(), ConnectionEnd()
	{
		setCounted( pObject );
	}

	FCO::FCO( const Object& object )
		: Object(), ConnectionEnd()
	{
		setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Model, OT_Set );
	}

	FCO::FCO( const ConnectionEnd& object )
		: Object(), ConnectionEnd()
	{
		if ( object && ! object->isReferencePort() )
			setCounted( object.getCounted( false ) );
	}

	FCO::FCO( const FCO& object )
		: Object(), ConnectionEnd()
	{
		setCounted( object.getCounted( false ) );
	}

	FCO& FCO::operator = ( const Object& object )
	{
		if ( this != &object ) {
			setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Model, OT_Set );
		}
		return *this;
	}

	FCO& FCO::operator = ( const ConnectionEnd& object )
	{
		if ( this != &object ) {
			if ( object && ! object->isReferencePort() )
				setCounted( object.getCounted( false ) );
		}
		return *this;
	}

	FCO& FCO::operator = ( const FCO& object )
	{
		if ( this != &object )
			setCounted( object.getCounted( false ) );
		return *this;
	}

	FCO FCO::attach( IMgaObject* spObject )
	{
		CComQIPtr<IMgaFCO> spFCO = spObject;
		return FCO( ( spFCO ) ? FCOImpl::attach( spFCO ) : NULL );
	}

	FCO::operator bool () const
	{
		return Object::getCounted( false ) != NULL;
	}

	bool FCO::operator ! () const
	{
		return Object::getCounted( false ) == NULL;
	}

	FCOImpl* FCO::operator -> () const
	{
		return dynamic_cast<FCOImpl*>( getCounted() );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::Attribute
//
//###############################################################################################################################################

	Attribute::Attribute( AttributeImpl* pObject )
		: Util::GenRefCounter( pObject )
	{
	}

	Attribute::Attribute( const Attribute& object )
		: Util::GenRefCounter( object )
	{
	}

	Attribute& Attribute::operator = ( const Attribute& object )
	{
		using namespace Util;
		GenRefCounter::operator=( object );
		return *this;
	}

	AttributeImpl* Attribute::operator -> () const
	{
		return (AttributeImpl*) getCounted();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::Atom
//
//###############################################################################################################################################

	const ObjectType Atom::type = OT_Atom;
	const std::string Atom::string_type = "BON::Atom";
	std::vector<std::string> Atom::vecDerivedKinds;
	const int Atom::inheritance_level = 1;

	void Atom::addDerivedKinds( const std::vector<std::string>& vecKinds )
	{
		for ( std::vector<std::string>::const_iterator it = vecKinds.begin() ; it != vecKinds.end() ; it++ )
			vecDerivedKinds.push_back( *it );
	}

	Atom::Atom( AtomImpl* pObject )
		: FCO( pObject )
	{
	}

	Atom::Atom( const Object& object )
		: FCO()
	{
		setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Atom );
	}

	Atom::Atom( const FCO& object )
		: FCO()
	{
		setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Atom );
	}

	Atom& Atom::operator = ( const Object& object )
	{
		if ( this != &object ) {
			setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Atom );
		}
		return *this;
	}

	Atom& Atom::operator = ( const FCO& object )
	{
		if ( this != &object ) {
			setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Atom );
		}
		return *this;
	}

	Atom::Atom( const ConnectionEnd& object )
		: FCO()
	{
		if ( object && ! object->isReferencePort() )
			setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Atom );
	}

	Atom& Atom::operator = ( const ConnectionEnd& object )
	{
		if ( this != &object ) {
			if ( object && ! object->isReferencePort() )
				setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Atom );
		}
		return *this;
	}

	Atom Atom::attach( IMgaObject* spObject )
	{
		CComQIPtr<IMgaAtom> spAtom = spObject;
		return Atom( ( spAtom ) ? AtomImpl::attach( spAtom ) : NULL );
	}

	Atom Atom::create( const Folder& parent, const MON::Atom& meta )
	{
		return AtomImpl::create( parent, meta );
	}

	Atom Atom::create( const Folder& parent, const std::string& strAtom )
	{
		return AtomImpl::create( parent, strAtom );
	}

	Atom Atom::create( const Folder& parent, const Atom& baseType, bool bAsInstance )
	{
		return AtomImpl::create( parent, baseType, bAsInstance );
	}

	Atom Atom::create( const Model& parent, const MON::Atom& meta, const std::string& strRole )
	{
		return AtomImpl::create( parent, meta, strRole );
	}

	Atom Atom::create( const Model& parent, const std::string& strAtom, const std::string& strRole )
	{
		return AtomImpl::create( parent, strAtom, strRole );
	}

	Atom Atom::create( const Model& parent, const Atom& baseType, bool bAsInstance, const std::string& strRole )
	{
		return AtomImpl::create( parent, baseType, bAsInstance, strRole );
	}

	Atom Atom::createAs( const Model& parent, const std::string& strRole )
	{
		return AtomImpl::createAs( parent, strRole );
	}

	AtomImpl* Atom::operator -> () const
	{
		return dynamic_cast<AtomImpl*>( getCounted() );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::Model
//
//###############################################################################################################################################

	const ObjectType Model::type = OT_Model;
	const std::string Model::string_type = "BON::Model";
	std::vector<std::string> Model::vecDerivedKinds;
	const int Model::inheritance_level = 1;

	void Model::addDerivedKinds( const std::vector<std::string>& vecKinds )
	{
		for ( std::vector<std::string>::const_iterator it = vecKinds.begin() ; it != vecKinds.end() ; it++ )
			vecDerivedKinds.push_back( *it );
	}

	Model::Model( ModelImpl* pObject )
		: FCO( pObject )
	{
	}

	Model::Model( const Object& object )
		: FCO()
	{
		setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Model );
	}

	Model& Model::operator = ( const Object& object )
	{
		if ( this != &object ) {
			setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Model );
		}
		return *this;
	}

	Model::Model( const ConnectionEnd& object )
		: FCO()
	{
		if ( object && ! object->isReferencePort() )
			setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Model );
	}

	Model& Model::operator = ( const ConnectionEnd& object )
	{
		if ( this != &object ) {
			if ( object && ! object->isReferencePort() )
				setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Model );
		}
		return *this;
	}

	Model::Model( const FCO& object )
		: FCO()
	{
		setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Model );
	}

	Model& Model::operator = ( const FCO& object )
	{
		if ( this != &object ) {
			setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Model );
		}
		return *this;
	}

	Model Model::attach( IMgaObject* spObject )
	{
		CComQIPtr<IMgaModel> spModel = spObject;
		return Model( ( spModel ) ? ModelImpl::attach( spModel ) : NULL );
	}

	Model Model::create( const Folder& parent, const MON::Model& meta )
	{
		return ModelImpl::create( parent, meta );
	}

	Model Model::create( const Folder& parent, const std::string& strModel )
	{
		return ModelImpl::create( parent, strModel );
	}

	Model Model::create( const Folder& parent, const Model& baseType, bool bAsInstance )
	{
		return ModelImpl::create( parent, baseType, bAsInstance );
	}

	Model Model::create( const Model& parent, const MON::Model& meta, const std::string& strRole )
	{
		return ModelImpl::create( parent, meta, strRole );
	}

	Model Model::create( const Model& parent, const std::string& strModel, const std::string& strRole )
	{
		return ModelImpl::create( parent, strModel, strRole );
	}

	Model Model::create( const Model& parent, const Model& baseType, bool bAsInstance, const std::string& strRole )
	{
		return ModelImpl::create( parent, baseType, bAsInstance, strRole );
	}

	Model Model::createAs( const Model& parent, const std::string& strRole )
	{
		return ModelImpl::createAs( parent, strRole );
	}

	ModelImpl* Model::operator -> () const
	{
		return dynamic_cast<ModelImpl*>( getCounted() );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::Set
//
//###############################################################################################################################################

	const ObjectType Set::type = OT_Set;
	const std::string Set::string_type = "BON::Set";
	std::vector<std::string> Set::vecDerivedKinds;
	const int Set::inheritance_level = 1;

	void Set::addDerivedKinds( const std::vector<std::string>& vecKinds )
	{
		for ( std::vector<std::string>::const_iterator it = vecKinds.begin() ; it != vecKinds.end() ; it++ )
			vecDerivedKinds.push_back( *it );
	}

	Set::Set( SetImpl* pObject )
		: FCO( pObject )
	{
	}

	Set::Set( const Object& object )
		: FCO()
	{
		setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Set );
	}

	Set::Set( const FCO& object )
		: FCO()
	{
		setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Set );
	}

	Set& Set::operator = ( const Object& object )
	{
		if ( this != &object ) {
			setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Set );
		}
		return *this;
	}

	Set& Set::operator = ( const FCO& object )
	{
		if ( this != &object ) {
			setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Set );
		}
		return *this;
	}

	Set::Set( const ConnectionEnd& object )
		: FCO()
	{
		if ( object && ! object->isReferencePort() )
			setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Set );
	}

	Set& Set::operator = ( const ConnectionEnd& object )
	{
		if ( this != &object ) {
			if ( object && ! object->isReferencePort() )
				setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Set );
		}
		return *this;
	}

	Set Set::attach( IMgaObject* spObject )
	{
		CComQIPtr<IMgaSet> spSet = spObject;
		return Set( ( spSet ) ? SetImpl::attach( spSet ) : NULL );
	}

	Set Set::create( const Folder& parent, const MON::Set& meta )
	{
		return SetImpl::create( parent, meta );
	}

	Set Set::create( const Folder& parent, const std::string& strSet )
	{
		return SetImpl::create( parent, strSet );
	}

	Set Set::create( const Folder& parent, const Set& baseType, bool bAsInstance )
	{
		return SetImpl::create( parent, baseType, bAsInstance );
	}

	Set Set::create( const Model& parent, const MON::Set& meta, const std::string& strRole )
	{
		return SetImpl::create( parent, meta, strRole );
	}

	Set Set::create( const Model& parent, const std::string& strSet, const std::string& strRole )
	{
		return SetImpl::create( parent, strSet, strRole );
	}

	Set Set::create( const Model& parent, const Set& baseType, bool bAsInstance, const std::string& strRole )
	{
		return SetImpl::create( parent, baseType, bAsInstance, strRole );
	}

	Set Set::createAs( const Model& parent, const std::string& strRole )
	{
		return SetImpl::createAs( parent, strRole );
	}

	SetImpl* Set::operator -> () const
	{
		return dynamic_cast<SetImpl*>( getCounted() );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::Reference
//
//###############################################################################################################################################

	const ObjectType Reference::type = OT_Reference;
	const std::string Reference::string_type = "BON::Reference";
	std::vector<std::string> Reference::vecDerivedKinds;
	const int Reference::inheritance_level = 1;

	void Reference::addDerivedKinds( const std::vector<std::string>& vecKinds )
	{
		for ( std::vector<std::string>::const_iterator it = vecKinds.begin() ; it != vecKinds.end() ; it++ )
			vecDerivedKinds.push_back( *it );
	}

	Reference::Reference( ReferenceImpl* pObject )
		: FCO( pObject )
	{
	}

	Reference::Reference( const Object& object )
		: FCO()
	{
		setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Reference );
	}

	Reference::Reference( const FCO& object )
		: FCO()
	{
		setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Reference );
	}

	Reference& Reference::operator = ( const Object& object )
	{
		if ( this != &object ) {
			setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Reference );
		}
		return *this;
	}

	Reference& Reference::operator = ( const FCO& object )
	{
		if ( this != &object ) {
			setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Reference );
		}
		return *this;
	}

	Reference::Reference( const ConnectionEnd& object )
		: FCO()
	{
		if ( object && ! object->isReferencePort() )
			setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Reference );
	}

	Reference& Reference::operator = ( const ConnectionEnd& object )
	{
		if ( this != &object ) {
			if ( object && ! object->isReferencePort() )
				setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Reference );
		}
		return *this;
	}

	Reference Reference::attach( IMgaObject* spObject )
	{
		CComQIPtr<IMgaReference> spReference = spObject;
		return Reference( ( spReference ) ? ReferenceImpl::attach( spReference ) : NULL );
	}

	Reference Reference::create( const Folder& parent, const MON::Reference& meta )
	{
		return ReferenceImpl::create( parent, meta );
	}

	Reference Reference::create( const Folder& parent, const std::string& strReference )
	{
		return ReferenceImpl::create( parent, strReference );
	}

	Reference Reference::create( const Folder& parent, const Reference& baseType, bool bAsInstance )
	{
		return ReferenceImpl::create( parent, baseType, bAsInstance );
	}

	Reference Reference::create( const Model& parent, const MON::Reference& meta, const std::string& strRole )
	{
		return ReferenceImpl::create( parent, meta, strRole );
	}

	Reference Reference::create( const Model& parent, const std::string& strReference, const std::string& strRole )
	{
		return ReferenceImpl::create( parent, strReference, strRole );
	}

	Reference Reference::create( const Model& parent, const Reference& baseType, bool bAsInstance, const std::string& strRole )
	{
		return ReferenceImpl::create( parent, baseType, bAsInstance, strRole );
	}

	Reference Reference::createAs( const Model& parent, const std::string& strRole )
	{
		return ReferenceImpl::createAs( parent, strRole );
	}

	ReferenceImpl* Reference::operator -> () const
	{
		return dynamic_cast<ReferenceImpl*>( getCounted() );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::Connection
//
//###############################################################################################################################################

	const ObjectType Connection::type = OT_Connection;
	const std::string Connection::string_type = "BON::Connection";
	std::vector<std::string> Connection::vecDerivedKinds;
	const int Connection::inheritance_level = 1;

	void Connection::addDerivedKinds( const std::vector<std::string>& vecKinds )
	{
		for ( std::vector<std::string>::const_iterator it = vecKinds.begin() ; it != vecKinds.end() ; it++ )
			vecDerivedKinds.push_back( *it );
	}

	Connection::Connection( ConnectionImpl* pObject )
		: FCO( pObject )
	{
	}

	Connection::Connection( const Object& object )
		: FCO()
	{
		setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Connection );
	}

	Connection& Connection::operator = ( const Object& object )
	{
		if ( this != &object ) {
			setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Connection );
		}
		return *this;
	}

	Connection::Connection( const FCO& object )
		: FCO()
	{
		setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Connection );
	}

	Connection& Connection::operator = ( const FCO& object )
	{
		if ( this != &object ) {
			setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Connection );
		}
		return *this;
	}

	Connection::Connection( const ConnectionEnd& object )
		: FCO()
	{
		if ( object && ! object->isReferencePort() )
			setCounted( object.getCounted( false ) );
		castObjectImpl( OT_Connection );
	}

	Connection& Connection::operator = ( const ConnectionEnd& object )
	{
		if ( this != &object ) {
			if ( object && ! object->isReferencePort() )
				setCounted( object.getCounted( false ) );
			castObjectImpl( OT_Connection );
		}
		return *this;
	}

	Connection Connection::attach( IMgaObject* spObject )
	{
		CComQIPtr<IMgaConnection> spConnection = spObject;
		return Connection( ( spConnection ) ? ConnectionImpl::attach( spConnection ) : NULL );
	}

	Connection Connection::create( const Model& parent, const std::set<Connection::Pair>& ends, const MON::Connection& meta, const std::string& strRole )
	{
		return ConnectionImpl::create( parent, ends, meta, strRole );
	}
	Connection Connection::create( const Model& parent, const std::set<Connection::Pair>& ends, const std::string& strConnection, const std::string& strRole )
	{
		return ConnectionImpl::create( parent, ends, strConnection, strRole );
	}

	Connection Connection::create( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const MON::Connection& meta, const std::string& strRole )
	{
		return ConnectionImpl::create( parent, srcEnd, dstEnd, meta, strRole );
	}

	Connection Connection::create( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const std::string& strConnection, const std::string& strRole )
	{
		return ConnectionImpl::create( parent, srcEnd, dstEnd, strConnection, strRole );
	}

	Connection Connection::createAs( const Model& parent, const std::set<Connection::Pair>& ends, const std::string& strRole )
	{
		return ConnectionImpl::create( parent, ends, strRole );
	}

	Connection Connection::createAs( const Model& parent, const ConnectionEnd& srcEnd, const ConnectionEnd& dstEnd, const std::string& strRole )
	{
		return ConnectionImpl::create( parent, srcEnd, dstEnd, strRole );
	}

	ConnectionImpl* Connection::operator -> () const
	{
		return dynamic_cast<ConnectionImpl*>( getCounted() );
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ReferencePortContainer
//
//###############################################################################################################################################

	ReferencePortContainer::ReferencePortContainer( const ReferencePortContainer& object )
		: Util::GenRefCounter( object )
	{
	}

	ReferencePortContainer::ReferencePortContainer( ReferencePortContainerImpl* pObject )
		: Util::GenRefCounter( pObject )
	{
	}

	ReferencePortContainer& ReferencePortContainer::operator = ( const ReferencePortContainer& object )
	{
		using namespace Util;
		GenRefCounter::operator=( object );
		return *this;
	}

	ReferencePortContainerImpl* ReferencePortContainer::operator -> () const
	{
		return (ReferencePortContainerImpl*) getCounted();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::TypeInhObject
//
//###############################################################################################################################################

	TypeInhObject::TypeInhObject( const TypeInhObject& object )
		: Util::GenRefCounter( object )
	{
	}

	TypeInhObject::TypeInhObject( TypeInhObjectImpl* pObject )
		: Util::GenRefCounter( pObject )
	{
	}

	TypeInhObject& TypeInhObject::operator = ( const TypeInhObject& object )
	{
		using namespace Util;
		GenRefCounter::operator=( object );
		return *this;
	}

	TypeInhObjectImpl* TypeInhObject::operator -> () const
	{
		return (TypeInhObjectImpl*) getCounted();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::Type
//
//###############################################################################################################################################

	Type::Type( const TypeInhObject& object )
		: TypeInhObject( object )
	{
		TypeInhObjectImpl* pImpl = (TypeInhObjectImpl*) getCounted( false );
		if ( pImpl && pImpl->isInstance() )
			setCounted( NULL );
	}

	Type::Type( TypeImpl* pObject )
		: TypeInhObject( pObject )
	{
	}

	Type& Type::operator = ( const TypeInhObject& object )
	{
		TypeInhObject::operator=( object );
		if ( this != &object ) {
			TypeInhObjectImpl* pImpl = (TypeInhObjectImpl*) getCounted( false );
			if ( pImpl && pImpl->isInstance() )
				setCounted( NULL );
		}
		return *this;
	}

	TypeImpl* Type::operator -> () const
	{
		return (TypeImpl*) getCounted();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::Instance
//
//###############################################################################################################################################

	Instance::Instance( const TypeInhObject& object )
		: TypeInhObject( object )
	{
		TypeInhObjectImpl* pImpl = (TypeInhObjectImpl*) getCounted( false );
		if ( pImpl && ! pImpl->isInstance() )
			setCounted( NULL );
	}

	Instance::Instance( InstanceImpl* pObject )
		: TypeInhObject( pObject )
	{
	}

	Instance& Instance::operator = ( const TypeInhObject& object )
	{
		TypeInhObject::operator=( object );
		if ( this != &object ) {
			TypeInhObjectImpl* pImpl = (TypeInhObjectImpl*) getCounted( false );
			if ( pImpl && ! pImpl->isInstance() )
				setCounted( NULL );
		}
		return *this;
	}

	InstanceImpl* Instance::operator -> () const
	{
		return (InstanceImpl*) getCounted();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::FCORegistryNode
//
//###############################################################################################################################################

	FCORegistryNode::FCORegistryNode( const RegistryNode& node )
		: RegistryNode( node )
	{
		RegistryNodeImpl* pNode = (RegistryNodeImpl*) getCounted( false );
		if ( pNode && ( ! pNode->isRootNode() || pNode->getObject()->getStereotype() == OT_Folder ) )
			setCounted( NULL );
	}

	FCORegistryNode::FCORegistryNode( RegistryNodeImpl* pNode )
		: RegistryNode( pNode )
	{
		if ( pNode && ( ! pNode->isRootNode() || pNode->getObject()->getStereotype() == OT_Folder ) )
			setCounted( NULL );
	}

	FCORegistryNode& FCORegistryNode::operator = ( const RegistryNode& object )
	{
		RegistryNode::operator=( object );
		if ( this != &object ) {
			RegistryNodeImpl* pNode = (RegistryNodeImpl*) getCounted( false );
			if ( pNode && ( ! pNode->isRootNode() || pNode->getObject()->getStereotype() == OT_Folder ) )
				setCounted( NULL );
		}
		return *this;
	}

	FCORegistryNodeImpl* FCORegistryNode::operator -> () const
	{
		return (FCORegistryNodeImpl*) getCounted();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::FCOExRegistryNode
//
//###############################################################################################################################################

	FCOExRegistryNode::FCOExRegistryNode( const RegistryNode& node )
		: FCORegistryNode( node )
	{
		RegistryNodeImpl* pNode = (RegistryNodeImpl*) getCounted( false );
		if ( pNode && pNode->getObject()->getStereotype() == OT_Connection )
			setCounted( NULL );
	}

	FCOExRegistryNode::FCOExRegistryNode( RegistryNodeImpl* pNode )
		: FCORegistryNode( pNode )
	{
		pNode = (RegistryNodeImpl*) getCounted( false );
		if ( pNode && pNode->getObject()->getStereotype() == OT_Connection )
			setCounted( NULL );
	}

	FCOExRegistryNode& FCOExRegistryNode::operator = ( const RegistryNode& object )
	{
		FCORegistryNode::operator=( object );
		RegistryNodeImpl* pNode = (RegistryNodeImpl*) getCounted( false );
		if ( pNode && pNode->getObject()->getStereotype() == OT_Connection )
			setCounted( NULL );

		return *this;
	}

	FCOExRegistryNodeImpl* FCOExRegistryNode::operator -> () const
	{
		return (FCOExRegistryNodeImpl*) getCounted();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ModelRegistryNode
//
//###############################################################################################################################################

	ModelRegistryNode::ModelRegistryNode( const RegistryNode& node )
		: FCOExRegistryNode( node )
	{
		RegistryNodeImpl* pNode = (RegistryNodeImpl*) getCounted( false );
		if ( pNode && pNode->getObject()->getStereotype() != OT_Model )
			setCounted( NULL );
	}

	ModelRegistryNode::ModelRegistryNode( RegistryNodeImpl* pNode )
		: FCOExRegistryNode( pNode )
	{
		pNode = (RegistryNodeImpl*) getCounted( false );
		if ( pNode && pNode->getObject()->getStereotype() != OT_Model )
			setCounted( NULL );
	}

	ModelRegistryNode& ModelRegistryNode::operator = ( const RegistryNode& object )
	{
		FCOExRegistryNode::operator=( object );
		RegistryNodeImpl* pNode = (RegistryNodeImpl*) getCounted( false );
		if ( pNode && pNode->getObject()->getStereotype() != OT_Model )
			setCounted( NULL );

		return *this;
	}

	ModelRegistryNodeImpl* ModelRegistryNode::operator -> () const
	{
		return (ModelRegistryNodeImpl*) getCounted();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::ConnectionRegistryNode
//
//###############################################################################################################################################

	ConnectionRegistryNode::ConnectionRegistryNode( const RegistryNode& node )
		: FCORegistryNode( node )
	{
		RegistryNodeImpl* pNode = (RegistryNodeImpl*) getCounted( false );
		if ( pNode && pNode->getObject()->getStereotype() != OT_Connection )
			setCounted( NULL );
	}

	ConnectionRegistryNode::ConnectionRegistryNode( RegistryNodeImpl* pNode )
		: FCORegistryNode( pNode )
	{
		pNode = (RegistryNodeImpl*) getCounted( false );
		if ( pNode && pNode->getObject()->getStereotype() != OT_Connection )
			setCounted( NULL );
	}

	ConnectionRegistryNode& ConnectionRegistryNode::operator = ( const RegistryNode& object )
	{
		FCORegistryNode::operator=( object );
		RegistryNodeImpl* pNode = (RegistryNodeImpl*) getCounted( false );
		if ( pNode && pNode->getObject()->getStereotype() != OT_Connection )
			setCounted( NULL );

		return *this;
	}

	ConnectionRegistryNodeImpl* ConnectionRegistryNode::operator -> () const
	{
		return (ConnectionRegistryNodeImpl*) getCounted();
	}

//###############################################################################################################################################
//
// 	C L A S S : BON::Visitor
//
//###############################################################################################################################################

	void Visitor::visitFolder( const Folder& folder )
	{
		visitObjectImpl( folder );
		visitFolderImpl( folder );
	}

	void Visitor::visitAtom( const Atom& atom )
	{
		visitObjectImpl( atom );
		visitConnectionEndImpl( atom );
		visitFCOImpl( atom );
		visitAtomImpl( atom );
	}

	void Visitor::visitModel( const Model& model )
	{
		visitObjectImpl( model );
		visitConnectionEndImpl( model );
		visitFCOImpl( model );
		visitModelImpl( model );
	}

	void Visitor::visitConnection( const Connection& connection )
	{
		visitObjectImpl( connection );
		visitConnectionEndImpl( connection );
		visitFCOImpl( connection );
		visitConnectionImpl( connection );
	}

	void Visitor::visitSet( const Set& set )
	{
		visitObjectImpl( set );
		visitConnectionEndImpl( set );
		visitFCOImpl( set );
		visitSetImpl( set);
	}

	void Visitor::visitReference( const Reference& reference )
	{
		visitObjectImpl( reference );
		visitConnectionEndImpl( reference );
		visitFCOImpl( reference );
		visitReferenceImpl( reference );
	}

	void Visitor::visitReferencePort( const ReferencePort& port )
	{
		visitConnectionEndImpl( port );
		visitReferencePortImpl( port );
	}

}; // namespace BON