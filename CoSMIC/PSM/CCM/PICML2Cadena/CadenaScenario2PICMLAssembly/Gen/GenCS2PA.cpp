#include "GenCS2PA.h"
#include <UmlExt.h>
#include <UdmUtil.h>

void RootRuleBlock_0::operator()( const Packets_t& pICML_File_Ins_1, const Packets_t& cadena_File_Ins_3)
{
#ifdef PRINT_INFO
	std::cout << "RootRuleBlock_0" << std::endl;
#endif
	if( ( !pICML_File_Ins_1.empty())&& ( !cadena_File_Ins_3.empty()))
		callRootFinder_2ce( pICML_File_Ins_1, cadena_File_Ins_3);
}

void RootRuleBlock_0::callRootFinder_2ce( const Packets_t& rootFolders_134, const Packets_t& scenarios_136)
{
	Packets_t scenarios_138;
	Packets_t componentAssemblys_139;
	RootFinder_133 rootFinder_133;
	rootFinder_133( rootFolders_134, scenarios_136, scenarios_138, componentAssemblys_139);
	if( ( !componentAssemblys_139.empty())&& ( !scenarios_138.empty()))
		callComponentCreation_2d1( componentAssemblys_139, scenarios_138);
}

void RootRuleBlock_0::callComponentCreation_2d1( const Packets_t& pICML_Assembly_Ins_158, const Packets_t& cadena_Scenario_Ins_15a)
{
	Packets_t cadena_Scenario_Outs_15c;
	Packets_t pICML_Assembly_Outs_15d;
	ComponentCreation_157 componentCreation_157;
	componentCreation_157( pICML_Assembly_Ins_158, cadena_Scenario_Ins_15a, cadena_Scenario_Outs_15c, pICML_Assembly_Outs_15d);
	if( ( !pICML_Assembly_Outs_15d.empty())&& ( !cadena_Scenario_Outs_15c.empty()))
		callPortConnection_2d4( pICML_Assembly_Outs_15d, cadena_Scenario_Outs_15c);
}

void RootRuleBlock_0::callPortConnection_2d4( const Packets_t& pICML_Assembly_Ins_6, const Packets_t& cadena_Scenario_Ins_8)
{
	PortConnection_5 portConnection_5;
	portConnection_5( pICML_Assembly_Ins_6, cadena_Scenario_Ins_8);
}

void PortConnection_5::operator()( const Packets_t& pICML_Assembly_Ins_6, const Packets_t& cadena_Scenario_Ins_8)
{
#ifdef PRINT_INFO
	std::cout << "PortConnection_5" << std::endl;
#endif
	if( ( !cadena_Scenario_Ins_8.empty())&& ( !pICML_Assembly_Ins_6.empty()))
		callInputSplitter_11e( cadena_Scenario_Ins_8, pICML_Assembly_Ins_6);
}

void PortConnection_5::callInputSplitter_11e( const Packets_t& scenarios_58, const Packets_t& componentAssemblys_5b)
{
	Packets_t scenarios_5a;
	Packets_t componentAssemblys_5d;
	InputSplitter_57 inputSplitter_57;
	inputSplitter_57( scenarios_58, componentAssemblys_5b, scenarios_5a, componentAssemblys_5d);
	if( ( !scenarios_5a.empty())&& ( !componentAssemblys_5d.empty()))
		callCreatingPublishConnectors_121( scenarios_5a, componentAssemblys_5d);
	if( ( !scenarios_5a.empty())&& ( !componentAssemblys_5d.empty()))
		callPortFinder_124( scenarios_5a, componentAssemblys_5d);
}

void PortConnection_5::callCreatingPublishConnectors_121( const Packets_t& scenarios_d0, const Packets_t& componentAssemblys_d4)
{
	Packets_t eSSConnections_d2;
	Packets_t publishConnectors_d3;
	CreatingPublishConnectors_cf creatingPublishConnectors_cf;
	creatingPublishConnectors_cf( scenarios_d0, componentAssemblys_d4, eSSConnections_d2, publishConnectors_d3);
	if( ( !publishConnectors_d3.empty())&& ( !eSSConnections_d2.empty()))
		callConnectorsToSinks_127( publishConnectors_d3, eSSConnections_d2);
	if( ( !publishConnectors_d3.empty())&& ( !eSSConnections_d2.empty()))
		callTransferingCorrelatorStrings_12a( publishConnectors_d3, eSSConnections_d2);
	if( ( !eSSConnections_d2.empty())&& ( !publishConnectors_d3.empty()))
		callSourcesToConnectors_12d( eSSConnections_d2, publishConnectors_d3);
}

void PortConnection_5::callPortFinder_124( const Packets_t& scenarios_f6, const Packets_t& componentAssemblys_fa)
{
	Packets_t scenarios_f8;
	Packets_t ports_f9;
	PortFinder_f5 portFinder_f5;
	portFinder_f5( scenarios_f6, componentAssemblys_fa, scenarios_f8, ports_f9);
	if( ( !ports_f9.empty())&& ( !scenarios_f8.empty()))
		callMethodInvocations_130( ports_f9, scenarios_f8);
}

void PortConnection_5::callConnectorsToSinks_127( const Packets_t& publishConnectors_b, const Packets_t& eSSConnections_d)
{
	ConnectorsToSinks_a connectorsToSinks_a;
	connectorsToSinks_a( publishConnectors_b, eSSConnections_d);
}

void PortConnection_5::callTransferingCorrelatorStrings_12a( const Packets_t& publishConnectors_33, const Packets_t& eSSConnections_35)
{
	TransferingCorrelatorStrings_32 transferingCorrelatorStrings_32;
	transferingCorrelatorStrings_32( publishConnectors_33, eSSConnections_35);
}

void PortConnection_5::callSourcesToConnectors_12d( const Packets_t& eSSConnections_a8, const Packets_t& publishConnectors_aa)
{
	SourcesToConnectors_a7 sourcesToConnectors_a7;
	sourcesToConnectors_a7( eSSConnections_a8, publishConnectors_aa);
}

void PortConnection_5::callMethodInvocations_130( const Packets_t& requiredRequestPorts_79, const Packets_t& scenarios_7b)
{
	MethodInvocations_78 methodInvocations_78;
	methodInvocations_78( requiredRequestPorts_79, scenarios_7b);
}

void ConnectorsToSinks_a::operator()( const Packets_t& publishConnectors_b, const Packets_t& eSSConnections_d)
{
#ifdef PRINT_INFO
	std::cout << "ConnectorsToSinks_a" << std::endl;
#endif
	processInputPackets( publishConnectors_b, eSSConnections_d);
}

bool ConnectorsToSinks_a::isInputUnique( const Udm::Object& publishConnector_13, const Udm::Object& eSSConnection_1c)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPublishConnector_15= _publishConnector_f.begin(), itESSConnection_1e= _eSSConnection_18.begin(); itPublishConnector_15!= _publishConnector_f.end(), itESSConnection_1e!= _eSSConnection_18.end(); ++itPublishConnector_15, ++itESSConnection_1e)
	{
		if( ( *itPublishConnector_15== publishConnector_13)&& ( *itESSConnection_1e== eSSConnection_1c))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_publishConnector_f.push_back( publishConnector_13);
		_eSSConnection_18.push_back( eSSConnection_1c);
	}
	return isUnique;
}

void ConnectorsToSinks_a::processInputPackets( const Packets_t& publishConnectors_b, const Packets_t& eSSConnections_d)
{
	for( Packets_t::const_iterator itPublishConnector_10= publishConnectors_b.begin(), itESSConnection_19= eSSConnections_d.begin(); itPublishConnector_10!= publishConnectors_b.end(), itESSConnection_19!= eSSConnections_d.end(); ++itPublishConnector_10, ++itESSConnection_19)
	{
		bool isUnique= isInputUnique( *itPublishConnector_10, *itESSConnection_19);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPublishConnector_10, *itESSConnection_19);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool ConnectorsToSinks_a::patternMatcher( const Udm::Object& publishConnector_11, const Udm::Object& eSSConnection_1a)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( publishConnector_11.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_16= PICML::PublishConnector::Cast( publishConnector_11);
		if( false== Uml::IsDerivedFrom( eSSConnection_1a.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_1f= cadena_scenario::ESSConnection::Cast( eSSConnection_1a);
		set< cadena_scenario::EventSink> eventSinks_21= eSSConnection_1f.sinks();
		for( set< cadena_scenario::EventSink>::const_iterator itEventSinks_22= eventSinks_21.begin(); itEventSinks_22!= eventSinks_21.end(); ++itEventSinks_22)
		{
			cadena_scenario::EventSink currEventSink_23= *itEventSinks_22;
			set< PICML::Port> inEventPorts_24= currEventSink_23.picmlPort();
			for( set< PICML::Port>::const_iterator itInEventPorts_25= inEventPorts_24.begin(); itInEventPorts_25!= inEventPorts_24.end(); ++itInEventPorts_25)
			{
				if( false== Uml::IsDerivedFrom( (*itInEventPorts_25).type(), PICML::InEventPort::meta))
					continue;
				PICML::InEventPort currInEventPort_26= PICML::InEventPort::Cast( *itInEventPorts_25);
				Udm::Object inEventPortParent_27= currInEventPort_26.container();
				if( false== Uml::IsDerivedFrom( inEventPortParent_27.type(), PICML::ComponentDef::meta))
					continue;
				PICML::ComponentDef componentDefInEventPort_28= PICML::ComponentDef::Cast( inEventPortParent_27);
				Udm::Object componentDefParent_29= componentDefInEventPort_28.container();
				if( false== Uml::IsDerivedFrom( componentDefParent_29.type(), PICML::ComponentAssembly::meta))
					continue;
				PICML::ComponentAssembly componentAssemblyComponentDef_2a= PICML::ComponentAssembly::Cast( componentDefParent_29);
				Match currMatch;
				currMatch.componentAssembly_2b= componentAssemblyComponentDef_2a;
				currMatch.componentDef_2c= componentDefInEventPort_28;
				currMatch.eventSink_2d= currEventSink_23;
				currMatch.inEventPort_2e= currInEventPort_26;
				currMatch.publishConnector_2f= publishConnector_16;
				currMatch.eSSConnection_30= eSSConnection_1f;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void ConnectorsToSinks_a::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::InEventPortConsume newInEventPortConsume_31= PICML::InEventPortConsume::Create( currMatch.componentAssembly_2b);
		newInEventPortConsume_31.srcInEventPortConsume_end()= currMatch.publishConnector_2f;
		newInEventPortConsume_31.dstInEventPortConsume_end()= currMatch.inEventPort_2e;
		outputAppender( );
	}
}

void ConnectorsToSinks_a::outputAppender()
{
}

void TransferingCorrelatorStrings_32::operator()( const Packets_t& publishConnectors_33, const Packets_t& eSSConnections_35)
{
#ifdef PRINT_INFO
	std::cout << "TransferingCorrelatorStrings_32" << std::endl;
#endif
	processInputPackets( publishConnectors_33, eSSConnections_35);
}

bool TransferingCorrelatorStrings_32::isInputUnique( const Udm::Object& publishConnector_3b, const Udm::Object& eSSConnection_44)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPublishConnector_3d= _publishConnector_37.begin(), itESSConnection_46= _eSSConnection_40.begin(); itPublishConnector_3d!= _publishConnector_37.end(), itESSConnection_46!= _eSSConnection_40.end(); ++itPublishConnector_3d, ++itESSConnection_46)
	{
		if( ( *itPublishConnector_3d== publishConnector_3b)&& ( *itESSConnection_46== eSSConnection_44))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_publishConnector_37.push_back( publishConnector_3b);
		_eSSConnection_40.push_back( eSSConnection_44);
	}
	return isUnique;
}

bool TransferingCorrelatorStrings_32::isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ESSConnection, const Udm::Object& PublishConnector)
{
	bool Gz_guard= false;
	string s; ESSConnection.GetStrValue("Correlator", s); return (s != "");;
	return Gz_guard;
}

void TransferingCorrelatorStrings_32::processInputPackets( const Packets_t& publishConnectors_33, const Packets_t& eSSConnections_35)
{
	for( Packets_t::const_iterator itPublishConnector_38= publishConnectors_33.begin(), itESSConnection_41= eSSConnections_35.begin(); itPublishConnector_38!= publishConnectors_33.end(), itESSConnection_41!= eSSConnections_35.end(); ++itPublishConnector_38, ++itESSConnection_41)
	{
		bool isUnique= isInputUnique( *itPublishConnector_38, *itESSConnection_41);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPublishConnector_38, *itESSConnection_41);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool TransferingCorrelatorStrings_32::patternMatcher( const Udm::Object& publishConnector_39, const Udm::Object& eSSConnection_42)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( publishConnector_39.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_3e= PICML::PublishConnector::Cast( publishConnector_39);
		if( false== Uml::IsDerivedFrom( eSSConnection_42.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_47= cadena_scenario::ESSConnection::Cast( eSSConnection_42);
		Udm::Object publishConnectorParent_49= publishConnector_3e.container();
		if( false== Uml::IsDerivedFrom( publishConnectorParent_49.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssemblyPublishConnector_4a= PICML::ComponentAssembly::Cast( publishConnectorParent_49);
		Match currMatch;
		currMatch.componentAssembly_4b= componentAssemblyPublishConnector_4a;
		currMatch.publishConnector_4c= publishConnector_3e;
		currMatch.eSSConnection_4d= eSSConnection_47;
		bool Gz_guard= isGuardTrue( currMatch.componentAssembly_4b, currMatch.eSSConnection_4d, currMatch.publishConnector_4c);
		if( true== Gz_guard)
			_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void TransferingCorrelatorStrings_32::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::Requirement newRequirement_51= PICML::Requirement::Create( currMatch.componentAssembly_4b);
		PICML::ConnectionRequirements newConnectionRequirements_52= PICML::ConnectionRequirements::Create( currMatch.componentAssembly_4b);
		PICML::Property newProperty_53= PICML::Property::Create( newRequirement_51);
		PICML::Any newAny_54= PICML::Any::Create( newProperty_53);
		PICML::DataType newDataType_55= PICML::DataType::Create( newAny_54);
		PICML::PredefinedType newPredefinedType_56= PICML::PredefinedType::Create( newDataType_55);
		Udm::Object& Any= newAny_54;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_4b;
		Udm::Object& ConnectionRequirements= newConnectionRequirements_52;
		Udm::Object& DataType= newDataType_55;
		Udm::Object& ESSConnection= currMatch.eSSConnection_4d;
		Udm::Object& PredefinedType= newPredefinedType_56;
		Udm::Object& Property= newProperty_53;
		Udm::Object& PublishConnector= currMatch.publishConnector_4c;
		Udm::Object& Requirement= newRequirement_51;
		{string s; ESSConnection.GetStrValue("Correlator",s); Any.SetStrValue("DataValue", s);  Requirement.SetStrValue("name", "Correlator"); Property.SetStrValue("name", "Correlator"); Any.SetStrValue("name", "Correlator"); DataType.SetStrValue("name", "Correlator"); PredefinedType.SetStrValue("name", "Correlator");};
		newConnectionRequirements_52.srcConnectionRequirements_end()= currMatch.publishConnector_4c;
		newConnectionRequirements_52.dstConnectionRequirements_end()= newRequirement_51;
		outputAppender( );
	}
}

void TransferingCorrelatorStrings_32::outputAppender()
{
}

void InputSplitter_57::operator()( const Packets_t& scenarios_58, const Packets_t& componentAssemblys_5b, Packets_t& scenarios_5a, Packets_t& componentAssemblys_5d)
{
#ifdef PRINT_INFO
	std::cout << "InputSplitter_57" << std::endl;
#endif
	_scenario_5e= &scenarios_5a;
	_componentAssembly_5f= &componentAssemblys_5d;
	processInputPackets( scenarios_58, componentAssemblys_5b);
	forwardInputs( );
}

bool InputSplitter_57::isInputUnique( const Udm::Object& scenario_64, const Udm::Object& componentAssembly_6d)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_66= _scenario_60.begin(), itComponentAssembly_6f= _componentAssembly_69.begin(); itScenario_66!= _scenario_60.end(), itComponentAssembly_6f!= _componentAssembly_69.end(); ++itScenario_66, ++itComponentAssembly_6f)
	{
		if( ( *itScenario_66== scenario_64)&& ( *itComponentAssembly_6f== componentAssembly_6d))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_60.push_back( scenario_64);
		_componentAssembly_69.push_back( componentAssembly_6d);
	}
	return isUnique;
}

void InputSplitter_57::processInputPackets( const Packets_t& scenarios_58, const Packets_t& componentAssemblys_5b)
{
	for( Packets_t::const_iterator itScenario_61= scenarios_58.begin(), itComponentAssembly_6a= componentAssemblys_5b.begin(); itScenario_61!= scenarios_58.end(), itComponentAssembly_6a!= componentAssemblys_5b.end(); ++itScenario_61, ++itComponentAssembly_6a)
	{
		bool isUnique= isInputUnique( *itScenario_61, *itComponentAssembly_6a);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_61, *itComponentAssembly_6a);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool InputSplitter_57::patternMatcher( const Udm::Object& scenario_62, const Udm::Object& componentAssembly_6b)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_62.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_67= cadena_scenario::Scenario::Cast( scenario_62);
		if( false== Uml::IsDerivedFrom( componentAssembly_6b.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_70= PICML::ComponentAssembly::Cast( componentAssembly_6b);
		Match currMatch;
		currMatch.scenario_72= scenario_67;
		currMatch.componentAssembly_73= componentAssembly_70;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void InputSplitter_57::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.scenario_72, currMatch.componentAssembly_73);
	}
}

void InputSplitter_57::outputAppender( const cadena_scenario::Scenario& scenario_74, const PICML::ComponentAssembly& componentAssembly_76)
{
	_scenario_5e->push_back( scenario_74);
	_componentAssembly_5f->push_back( componentAssembly_76);
}

void InputSplitter_57::forwardInputs()
{
	*_scenario_5e= _scenario_60;
	*_componentAssembly_5f= _componentAssembly_69;
}

void MethodInvocations_78::operator()( const Packets_t& requiredRequestPorts_79, const Packets_t& scenarios_7b)
{
#ifdef PRINT_INFO
	std::cout << "MethodInvocations_78" << std::endl;
#endif
	processInputPackets( requiredRequestPorts_79, scenarios_7b);
}

bool MethodInvocations_78::isInputUnique( const Udm::Object& requiredRequestPort_81, const Udm::Object& scenario_8a)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRequiredRequestPort_83= _requiredRequestPort_7d.begin(), itScenario_8c= _scenario_86.begin(); itRequiredRequestPort_83!= _requiredRequestPort_7d.end(), itScenario_8c!= _scenario_86.end(); ++itRequiredRequestPort_83, ++itScenario_8c)
	{
		if( ( *itRequiredRequestPort_83== requiredRequestPort_81)&& ( *itScenario_8c== scenario_8a))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_requiredRequestPort_7d.push_back( requiredRequestPort_81);
		_scenario_86.push_back( scenario_8a);
	}
	return isUnique;
}

void MethodInvocations_78::processInputPackets( const Packets_t& requiredRequestPorts_79, const Packets_t& scenarios_7b)
{
	for( Packets_t::const_iterator itRequiredRequestPort_7e= requiredRequestPorts_79.begin(), itScenario_87= scenarios_7b.begin(); itRequiredRequestPort_7e!= requiredRequestPorts_79.end(), itScenario_87!= scenarios_7b.end(); ++itRequiredRequestPort_7e, ++itScenario_87)
	{
		bool isUnique= isInputUnique( *itRequiredRequestPort_7e, *itScenario_87);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRequiredRequestPort_7e, *itScenario_87);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool MethodInvocations_78::patternMatcher( const Udm::Object& requiredRequestPort_7f, const Udm::Object& scenario_88)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( requiredRequestPort_7f.type(), PICML::RequiredRequestPort::meta))
			continue;
		PICML::RequiredRequestPort requiredRequestPort_84= PICML::RequiredRequestPort::Cast( requiredRequestPort_7f);
		if( false== Uml::IsDerivedFrom( scenario_88.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_8d= cadena_scenario::Scenario::Cast( scenario_88);
		set< cadena_scenario::FRConnection> fRConnections_8f= scenario_8d.FRConnection_kind_children();
		for( set< cadena_scenario::FRConnection>::const_iterator itFRConnection_90= fRConnections_8f.begin(); itFRConnection_90!= fRConnections_8f.end(); ++itFRConnection_90)
		{
			cadena_scenario::FRConnection currFRConnection_91= *itFRConnection_90;
			set< cadena_scenario::ComponentPort> receptacles_92= requiredRequestPort_84.cadenaPort();
			for( set< cadena_scenario::ComponentPort>::const_iterator itReceptacles_93= receptacles_92.begin(); itReceptacles_93!= receptacles_92.end(); ++itReceptacles_93)
			{
				if( false== Uml::IsDerivedFrom( (*itReceptacles_93).type(), cadena_scenario::Receptacle::meta))
					continue;
				cadena_scenario::Receptacle currReceptacle_94= cadena_scenario::Receptacle::Cast( *itReceptacles_93);
				cadena_scenario::Receptacle receptacle_95= currFRConnection_91.receptacles_end();
				if( currReceptacle_94!= receptacle_95)
					continue;
				cadena_scenario::Facet facet_96= currFRConnection_91.facets_end();
				set< PICML::Port> providedRequestPorts_97= facet_96.picmlPort();
				for( set< PICML::Port>::const_iterator itProvidedRequestPorts_98= providedRequestPorts_97.begin(); itProvidedRequestPorts_98!= providedRequestPorts_97.end(); ++itProvidedRequestPorts_98)
				{
					if( false== Uml::IsDerivedFrom( (*itProvidedRequestPorts_98).type(), PICML::ProvidedRequestPort::meta))
						continue;
					PICML::ProvidedRequestPort currProvidedRequestPort_99= PICML::ProvidedRequestPort::Cast( *itProvidedRequestPorts_98);
					Udm::Object providedRequestPortParent_9a= currProvidedRequestPort_99.container();
					if( false== Uml::IsDerivedFrom( providedRequestPortParent_9a.type(), PICML::ComponentDef::meta))
						continue;
					PICML::ComponentDef componentDefProvidedRequestPort_9b= PICML::ComponentDef::Cast( providedRequestPortParent_9a);
					Udm::Object componentDefParent_9c= componentDefProvidedRequestPort_9b.container();
					if( false== Uml::IsDerivedFrom( componentDefParent_9c.type(), PICML::ComponentAssembly::meta))
						continue;
					PICML::ComponentAssembly componentAssemblyComponentDef_9d= PICML::ComponentAssembly::Cast( componentDefParent_9c);
					Match currMatch;
					currMatch.componentAssembly_9e= componentAssemblyComponentDef_9d;
					currMatch.componentDef_9f= componentDefProvidedRequestPort_9b;
					currMatch.fRConnection_a0= currFRConnection_91;
					currMatch.facet_a1= facet_96;
					currMatch.receptacle_a2= currReceptacle_94;
					currMatch.providedRequestPort_a3= currProvidedRequestPort_99;
					currMatch.requiredRequestPort_a4= requiredRequestPort_84;
					currMatch.scenario_a5= scenario_8d;
					_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void MethodInvocations_78::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::Invocation newInvocation_a6= PICML::Invocation::Create( currMatch.componentAssembly_9e);
		newInvocation_a6.srcInvocation_end()= currMatch.requiredRequestPort_a4;
		newInvocation_a6.dstInvocation_end()= currMatch.providedRequestPort_a3;
		outputAppender( );
	}
}

void MethodInvocations_78::outputAppender()
{
}

void SourcesToConnectors_a7::operator()( const Packets_t& eSSConnections_a8, const Packets_t& publishConnectors_aa)
{
#ifdef PRINT_INFO
	std::cout << "SourcesToConnectors_a7" << std::endl;
#endif
	processInputPackets( eSSConnections_a8, publishConnectors_aa);
}

bool SourcesToConnectors_a7::isInputUnique( const Udm::Object& eSSConnection_b0, const Udm::Object& publishConnector_b9)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itESSConnection_b2= _eSSConnection_ac.begin(), itPublishConnector_bb= _publishConnector_b5.begin(); itESSConnection_b2!= _eSSConnection_ac.end(), itPublishConnector_bb!= _publishConnector_b5.end(); ++itESSConnection_b2, ++itPublishConnector_bb)
	{
		if( ( *itESSConnection_b2== eSSConnection_b0)&& ( *itPublishConnector_bb== publishConnector_b9))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_eSSConnection_ac.push_back( eSSConnection_b0);
		_publishConnector_b5.push_back( publishConnector_b9);
	}
	return isUnique;
}

void SourcesToConnectors_a7::processInputPackets( const Packets_t& eSSConnections_a8, const Packets_t& publishConnectors_aa)
{
	for( Packets_t::const_iterator itESSConnection_ad= eSSConnections_a8.begin(), itPublishConnector_b6= publishConnectors_aa.begin(); itESSConnection_ad!= eSSConnections_a8.end(), itPublishConnector_b6!= publishConnectors_aa.end(); ++itESSConnection_ad, ++itPublishConnector_b6)
	{
		bool isUnique= isInputUnique( *itESSConnection_ad, *itPublishConnector_b6);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itESSConnection_ad, *itPublishConnector_b6);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool SourcesToConnectors_a7::patternMatcher( const Udm::Object& eSSConnection_ae, const Udm::Object& publishConnector_b7)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( eSSConnection_ae.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_b3= cadena_scenario::ESSConnection::Cast( eSSConnection_ae);
		if( false== Uml::IsDerivedFrom( publishConnector_b7.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_bc= PICML::PublishConnector::Cast( publishConnector_b7);
		set< cadena_scenario::EventSource> eventSources_be= eSSConnection_b3.sources();
		for( set< cadena_scenario::EventSource>::const_iterator itEventSources_bf= eventSources_be.begin(); itEventSources_bf!= eventSources_be.end(); ++itEventSources_bf)
		{
			cadena_scenario::EventSource currEventSource_c0= *itEventSources_bf;
			set< PICML::Port> outEventPorts_c1= currEventSource_c0.picmlPort();
			for( set< PICML::Port>::const_iterator itOutEventPorts_c2= outEventPorts_c1.begin(); itOutEventPorts_c2!= outEventPorts_c1.end(); ++itOutEventPorts_c2)
			{
				if( false== Uml::IsDerivedFrom( (*itOutEventPorts_c2).type(), PICML::OutEventPort::meta))
					continue;
				PICML::OutEventPort currOutEventPort_c3= PICML::OutEventPort::Cast( *itOutEventPorts_c2);
				Udm::Object outEventPortParent_c4= currOutEventPort_c3.container();
				if( false== Uml::IsDerivedFrom( outEventPortParent_c4.type(), PICML::ComponentDef::meta))
					continue;
				PICML::ComponentDef componentDefOutEventPort_c5= PICML::ComponentDef::Cast( outEventPortParent_c4);
				Udm::Object componentDefParent_c6= componentDefOutEventPort_c5.container();
				if( false== Uml::IsDerivedFrom( componentDefParent_c6.type(), PICML::ComponentAssembly::meta))
					continue;
				PICML::ComponentAssembly componentAssemblyComponentDef_c7= PICML::ComponentAssembly::Cast( componentDefParent_c6);
				Match currMatch;
				currMatch.componentAssembly_c8= componentAssemblyComponentDef_c7;
				currMatch.componentDef_c9= componentDefOutEventPort_c5;
				currMatch.eventSource_ca= currEventSource_c0;
				currMatch.outEventPort_cb= currOutEventPort_c3;
				currMatch.eSSConnection_cc= eSSConnection_b3;
				currMatch.publishConnector_cd= publishConnector_bc;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void SourcesToConnectors_a7::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::OutEventPortPublish newOutEventPortPublish_ce= PICML::OutEventPortPublish::Create( currMatch.componentAssembly_c8);
		newOutEventPortPublish_ce.srcOutEventPortPublish_end()= currMatch.outEventPort_cb;
		newOutEventPortPublish_ce.dstOutEventPortPublish_end()= currMatch.publishConnector_cd;
		outputAppender( );
	}
}

void SourcesToConnectors_a7::outputAppender()
{
}

void CreatingPublishConnectors_cf::operator()( const Packets_t& scenarios_d0, const Packets_t& componentAssemblys_d4, Packets_t& eSSConnections_d2, Packets_t& publishConnectors_d3)
{
#ifdef PRINT_INFO
	std::cout << "CreatingPublishConnectors_cf" << std::endl;
#endif
	_eSSConnection_d6= &eSSConnections_d2;
	_publishConnector_d7= &publishConnectors_d3;
	processInputPackets( scenarios_d0, componentAssemblys_d4);
}

bool CreatingPublishConnectors_cf::isInputUnique( const Udm::Object& scenario_dc, const Udm::Object& componentAssembly_e5)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_de= _scenario_d8.begin(), itComponentAssembly_e7= _componentAssembly_e1.begin(); itScenario_de!= _scenario_d8.end(), itComponentAssembly_e7!= _componentAssembly_e1.end(); ++itScenario_de, ++itComponentAssembly_e7)
	{
		if( ( *itScenario_de== scenario_dc)&& ( *itComponentAssembly_e7== componentAssembly_e5))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_d8.push_back( scenario_dc);
		_componentAssembly_e1.push_back( componentAssembly_e5);
	}
	return isUnique;
}

void CreatingPublishConnectors_cf::processInputPackets( const Packets_t& scenarios_d0, const Packets_t& componentAssemblys_d4)
{
	for( Packets_t::const_iterator itScenario_d9= scenarios_d0.begin(), itComponentAssembly_e2= componentAssemblys_d4.begin(); itScenario_d9!= scenarios_d0.end(), itComponentAssembly_e2!= componentAssemblys_d4.end(); ++itScenario_d9, ++itComponentAssembly_e2)
	{
		bool isUnique= isInputUnique( *itScenario_d9, *itComponentAssembly_e2);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_d9, *itComponentAssembly_e2);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool CreatingPublishConnectors_cf::patternMatcher( const Udm::Object& scenario_da, const Udm::Object& componentAssembly_e3)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_da.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_df= cadena_scenario::Scenario::Cast( scenario_da);
		if( false== Uml::IsDerivedFrom( componentAssembly_e3.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_e8= PICML::ComponentAssembly::Cast( componentAssembly_e3);
		set< cadena_scenario::ESSConnection> eSSConnections_ea= scenario_df.ESSConnection_kind_children();
		for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnection_eb= eSSConnections_ea.begin(); itESSConnection_eb!= eSSConnections_ea.end(); ++itESSConnection_eb)
		{
			cadena_scenario::ESSConnection currESSConnection_ec= *itESSConnection_eb;
			Match currMatch;
			currMatch.scenario_ed= scenario_df;
			currMatch.eSSConnection_ee= currESSConnection_ec;
			currMatch.componentAssembly_ef= componentAssembly_e8;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void CreatingPublishConnectors_cf::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::PublishConnector newPublishConnector_f0= PICML::PublishConnector::Create( currMatch.componentAssembly_ef);
		outputAppender( currMatch.eSSConnection_ee, newPublishConnector_f0);
	}
}

void CreatingPublishConnectors_cf::outputAppender( const cadena_scenario::ESSConnection& eSSConnection_f1, const PICML::PublishConnector& publishConnector_f3)
{
	_eSSConnection_d6->push_back( eSSConnection_f1);
	_publishConnector_d7->push_back( publishConnector_f3);
}

void PortFinder_f5::operator()( const Packets_t& scenarios_f6, const Packets_t& componentAssemblys_fa, Packets_t& scenarios_f8, Packets_t& ports_f9)
{
#ifdef PRINT_INFO
	std::cout << "PortFinder_f5" << std::endl;
#endif
	_scenario_fc= &scenarios_f8;
	_port_fd= &ports_f9;
	processInputPackets( scenarios_f6, componentAssemblys_fa);
}

bool PortFinder_f5::isInputUnique( const Udm::Object& scenario_102, const Udm::Object& componentAssembly_10b)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_104= _scenario_fe.begin(), itComponentAssembly_10d= _componentAssembly_107.begin(); itScenario_104!= _scenario_fe.end(), itComponentAssembly_10d!= _componentAssembly_107.end(); ++itScenario_104, ++itComponentAssembly_10d)
	{
		if( ( *itScenario_104== scenario_102)&& ( *itComponentAssembly_10d== componentAssembly_10b))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_fe.push_back( scenario_102);
		_componentAssembly_107.push_back( componentAssembly_10b);
	}
	return isUnique;
}

void PortFinder_f5::processInputPackets( const Packets_t& scenarios_f6, const Packets_t& componentAssemblys_fa)
{
	for( Packets_t::const_iterator itScenario_ff= scenarios_f6.begin(), itComponentAssembly_108= componentAssemblys_fa.begin(); itScenario_ff!= scenarios_f6.end(), itComponentAssembly_108!= componentAssemblys_fa.end(); ++itScenario_ff, ++itComponentAssembly_108)
	{
		bool isUnique= isInputUnique( *itScenario_ff, *itComponentAssembly_108);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_ff, *itComponentAssembly_108);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool PortFinder_f5::patternMatcher( const Udm::Object& scenario_100, const Udm::Object& componentAssembly_109)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_100.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_105= cadena_scenario::Scenario::Cast( scenario_100);
		if( false== Uml::IsDerivedFrom( componentAssembly_109.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_10e= PICML::ComponentAssembly::Cast( componentAssembly_109);
		set< PICML::ComponentDef> componentDefs_110= componentAssembly_10e.ComponentDef_kind_children();
		for( set< PICML::ComponentDef>::const_iterator itComponentDef_111= componentDefs_110.begin(); itComponentDef_111!= componentDefs_110.end(); ++itComponentDef_111)
		{
			PICML::ComponentDef currComponentDef_112= *itComponentDef_111;
			set< PICML::Port> ports_113= currComponentDef_112.Port_kind_children();
			for( set< PICML::Port>::const_iterator itPort_114= ports_113.begin(); itPort_114!= ports_113.end(); ++itPort_114)
			{
				PICML::Port currPort_115= *itPort_114;
				Match currMatch;
				currMatch.scenario_116= scenario_105;
				currMatch.port_117= currPort_115;
				currMatch.componentDef_118= currComponentDef_112;
				currMatch.componentAssembly_119= componentAssembly_10e;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void PortFinder_f5::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.scenario_116, currMatch.port_117);
	}
}

void PortFinder_f5::outputAppender( const cadena_scenario::Scenario& scenario_11a, const PICML::Port& port_11c)
{
	_scenario_fc->push_back( scenario_11a);
	_port_fd->push_back( port_11c);
}

void RootFinder_133::operator()( const Packets_t& rootFolders_134, const Packets_t& scenarios_136, Packets_t& scenarios_138, Packets_t& componentAssemblys_139)
{
#ifdef PRINT_INFO
	std::cout << "RootFinder_133" << std::endl;
#endif
	_scenario_13a= &scenarios_138;
	_componentAssembly_13b= &componentAssemblys_139;
	processInputPackets( rootFolders_134, scenarios_136);
}

bool RootFinder_133::isInputUnique( const Udm::Object& rootFolder_140, const Udm::Object& scenario_149)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRootFolder_142= _rootFolder_13c.begin(), itScenario_14b= _scenario_145.begin(); itRootFolder_142!= _rootFolder_13c.end(), itScenario_14b!= _scenario_145.end(); ++itRootFolder_142, ++itScenario_14b)
	{
		if( ( *itRootFolder_142== rootFolder_140)&& ( *itScenario_14b== scenario_149))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_rootFolder_13c.push_back( rootFolder_140);
		_scenario_145.push_back( scenario_149);
	}
	return isUnique;
}

void RootFinder_133::processInputPackets( const Packets_t& rootFolders_134, const Packets_t& scenarios_136)
{
	for( Packets_t::const_iterator itRootFolder_13d= rootFolders_134.begin(), itScenario_146= scenarios_136.begin(); itRootFolder_13d!= rootFolders_134.end(), itScenario_146!= scenarios_136.end(); ++itRootFolder_13d, ++itScenario_146)
	{
		bool isUnique= isInputUnique( *itRootFolder_13d, *itScenario_146);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRootFolder_13d, *itScenario_146);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool RootFinder_133::patternMatcher( const Udm::Object& rootFolder_13e, const Udm::Object& scenario_147)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( rootFolder_13e.type(), PICML::RootFolder::meta))
			continue;
		PICML::RootFolder rootFolder_143= PICML::RootFolder::Cast( rootFolder_13e);
		if( false== Uml::IsDerivedFrom( scenario_147.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_14c= cadena_scenario::Scenario::Cast( scenario_147);
		Match currMatch;
		currMatch.rootFolder_14e= rootFolder_143;
		currMatch.scenario_14f= scenario_14c;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void RootFinder_133::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::ComponentImplementations newComponentImplementations_150= PICML::ComponentImplementations::Create( currMatch.rootFolder_14e);
		PICML::ComponentImplementationContainer newComponentImplementationContainer_151= PICML::ComponentImplementationContainer::Create( newComponentImplementations_150);
		PICML::ComponentAssembly newComponentAssembly_152= PICML::ComponentAssembly::Create( newComponentImplementationContainer_151);
		Udm::Object& ComponentAssembly= newComponentAssembly_152;
		Udm::Object& ComponentImplementationContainer= newComponentImplementationContainer_151;
		Udm::Object& ComponentImplementations= newComponentImplementations_150;
		Udm::Object& RootFolder= currMatch.rootFolder_14e;
		Udm::Object& Scenario= currMatch.scenario_14f;
		{ComponentImplementations.SetStrVal("name", "ImportedComponentImplementations"); ComponentImplementationContainer.SetStrVal("name", "ImportedComponentImplementationContainer"); ComponentAssembly.SetStrVal("name", "ImportedComponentAssembly");};
		outputAppender( currMatch.scenario_14f, newComponentAssembly_152);
	}
}

void RootFinder_133::outputAppender( const cadena_scenario::Scenario& scenario_153, const PICML::ComponentAssembly& componentAssembly_155)
{
	_scenario_13a->push_back( scenario_153);
	_componentAssembly_13b->push_back( componentAssembly_155);
}

void ComponentCreation_157::operator()( const Packets_t& pICML_Assembly_Ins_158, const Packets_t& cadena_Scenario_Ins_15a, Packets_t& cadena_Scenario_Outs_15c, Packets_t& pICML_Assembly_Outs_15d)
{
#ifdef PRINT_INFO
	std::cout << "ComponentCreation_157" << std::endl;
#endif
	_cadena_Scenario_Out_15e= &cadena_Scenario_Outs_15c;
	_pICML_Assembly_Out_15f= &pICML_Assembly_Outs_15d;
	_pICML_Assembly_Out_15f->insert( _pICML_Assembly_Out_15f->end(), pICML_Assembly_Ins_158.begin(), pICML_Assembly_Ins_158.end());
	_cadena_Scenario_Out_15e->insert( _cadena_Scenario_Out_15e->end(), cadena_Scenario_Ins_15a.begin(), cadena_Scenario_Ins_15a.end());
	if( ( !pICML_Assembly_Ins_158.empty())&& ( !cadena_Scenario_Ins_15a.empty()))
		callComponentCreation_2c5( pICML_Assembly_Ins_158, cadena_Scenario_Ins_15a);
}

void ComponentCreation_157::callComponentCreation_2c5( const Packets_t& componentAssemblys_283, const Packets_t& scenarios_286)
{
	Packets_t componentAssemblys_285;
	Packets_t scenarios_288;
	ComponentCreation_282 componentCreation_282;
	componentCreation_282( componentAssemblys_283, scenarios_286, componentAssemblys_285, scenarios_288);
	if( ( !scenarios_288.empty())&& ( !componentAssemblys_285.empty()))
		callComponentAlignment_2c8( scenarios_288, componentAssemblys_285);
}

void ComponentCreation_157::callComponentAlignment_2c8( const Packets_t& scenarios_161, const Packets_t& componentAssemblys_165)
{
	Packets_t componentDefs_163;
	Packets_t componentInstances_164;
	ComponentAlignment_160 componentAlignment_160;
	componentAlignment_160( scenarios_161, componentAssemblys_165, componentDefs_163, componentInstances_164);
	if( ( !componentInstances_164.empty())&& ( !componentDefs_163.empty()))
		callAssociatingPorts_2cb( componentInstances_164, componentDefs_163);
}

void ComponentCreation_157::callAssociatingPorts_2cb( const Packets_t& componentInstances_18e, const Packets_t& componentDefs_190)
{
	AssociatingPorts_18d associatingPorts_18d;
	associatingPorts_18d( componentInstances_18e, componentDefs_190);
}

void ComponentAlignment_160::operator()( const Packets_t& scenarios_161, const Packets_t& componentAssemblys_165, Packets_t& componentDefs_163, Packets_t& componentInstances_164)
{
#ifdef PRINT_INFO
	std::cout << "ComponentAlignment_160" << std::endl;
#endif
	_componentDef_167= &componentDefs_163;
	_componentInstance_168= &componentInstances_164;
	processInputPackets( scenarios_161, componentAssemblys_165);
}

bool ComponentAlignment_160::isInputUnique( const Udm::Object& scenario_16d, const Udm::Object& componentAssembly_176)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_16f= _scenario_169.begin(), itComponentAssembly_178= _componentAssembly_172.begin(); itScenario_16f!= _scenario_169.end(), itComponentAssembly_178!= _componentAssembly_172.end(); ++itScenario_16f, ++itComponentAssembly_178)
	{
		if( ( *itScenario_16f== scenario_16d)&& ( *itComponentAssembly_178== componentAssembly_176))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_169.push_back( scenario_16d);
		_componentAssembly_172.push_back( componentAssembly_176);
	}
	return isUnique;
}

bool ComponentAlignment_160::isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ComponentDef, const Udm::Object& ComponentInstance, const Udm::Object& Scenario)
{
	bool Gz_guard= false;
	string cadname, picmlname; ComponentInstance.GetStrValue("name", cadname); ComponentDef.GetStrValue("name", picmlname); return (cadname==picmlname);;
	return Gz_guard;
}

void ComponentAlignment_160::processInputPackets( const Packets_t& scenarios_161, const Packets_t& componentAssemblys_165)
{
	for( Packets_t::const_iterator itScenario_16a= scenarios_161.begin(), itComponentAssembly_173= componentAssemblys_165.begin(); itScenario_16a!= scenarios_161.end(), itComponentAssembly_173!= componentAssemblys_165.end(); ++itScenario_16a, ++itComponentAssembly_173)
	{
		bool isUnique= isInputUnique( *itScenario_16a, *itComponentAssembly_173);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_16a, *itComponentAssembly_173);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool ComponentAlignment_160::patternMatcher( const Udm::Object& scenario_16b, const Udm::Object& componentAssembly_174)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_16b.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_170= cadena_scenario::Scenario::Cast( scenario_16b);
		if( false== Uml::IsDerivedFrom( componentAssembly_174.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_179= PICML::ComponentAssembly::Cast( componentAssembly_174);
		set< cadena_scenario::ComponentInstance> componentInstances_17b= scenario_170.ComponentInstance_kind_children();
		for( set< cadena_scenario::ComponentInstance>::const_iterator itComponentInstance_17c= componentInstances_17b.begin(); itComponentInstance_17c!= componentInstances_17b.end(); ++itComponentInstance_17c)
		{
			cadena_scenario::ComponentInstance currComponentInstance_17d= *itComponentInstance_17c;
			set< PICML::ComponentDef> componentDefs_17e= componentAssembly_179.ComponentDef_kind_children();
			for( set< PICML::ComponentDef>::const_iterator itComponentDef_17f= componentDefs_17e.begin(); itComponentDef_17f!= componentDefs_17e.end(); ++itComponentDef_17f)
			{
				PICML::ComponentDef currComponentDef_180= *itComponentDef_17f;
				Match currMatch;
				currMatch.scenario_181= scenario_170;
				currMatch.componentDef_182= currComponentDef_180;
				currMatch.componentInstance_183= currComponentInstance_17d;
				currMatch.componentAssembly_184= componentAssembly_179;
				bool Gz_guard= isGuardTrue( currMatch.componentAssembly_184, currMatch.componentDef_182, currMatch.componentInstance_183, currMatch.scenario_181);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void ComponentAlignment_160::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.componentDef_182, currMatch.componentInstance_183);
	}
}

void ComponentAlignment_160::outputAppender( const PICML::ComponentDef& componentDef_189, const cadena_scenario::ComponentInstance& componentInstance_18b)
{
	_componentDef_167->push_back( componentDef_189);
	_componentInstance_168->push_back( componentInstance_18b);
}

void AssociatingPorts_18d::operator()( const Packets_t& componentInstances_18e, const Packets_t& componentDefs_190)
{
#ifdef PRINT_INFO
	std::cout << "AssociatingPorts_18d" << std::endl;
#endif
	processInputPackets( componentInstances_18e, componentDefs_190);
}

bool AssociatingPorts_18d::isInputUnique( const Udm::Object& componentInstance_196, const Udm::Object& componentDef_19f)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentInstance_198= _componentInstance_192.begin(), itComponentDef_1a1= _componentDef_19b.begin(); itComponentInstance_198!= _componentInstance_192.end(), itComponentDef_1a1!= _componentDef_19b.end(); ++itComponentInstance_198, ++itComponentDef_1a1)
	{
		if( ( *itComponentInstance_198== componentInstance_196)&& ( *itComponentDef_1a1== componentDef_19f))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentInstance_192.push_back( componentInstance_196);
		_componentDef_19b.push_back( componentDef_19f);
	}
	return isUnique;
}

bool AssociatingPorts_18d::isGuardTrue( const Udm::Object& ComponentDef, const Udm::Object& ComponentInstance, const Udm::Object& ComponentPort, const Udm::Object& Port)
{
	bool Gz_guard= false;
	string picname, cadname; Port.GetStrValue("name", picname); ComponentPort.GetStrValue("Name", cadname); return (picname==cadname);;
	return Gz_guard;
}

void AssociatingPorts_18d::processInputPackets( const Packets_t& componentInstances_18e, const Packets_t& componentDefs_190)
{
	for( Packets_t::const_iterator itComponentInstance_193= componentInstances_18e.begin(), itComponentDef_19c= componentDefs_190.begin(); itComponentInstance_193!= componentInstances_18e.end(), itComponentDef_19c!= componentDefs_190.end(); ++itComponentInstance_193, ++itComponentDef_19c)
	{
		bool isUnique= isInputUnique( *itComponentInstance_193, *itComponentDef_19c);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentInstance_193, *itComponentDef_19c);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool AssociatingPorts_18d::patternMatcher( const Udm::Object& componentInstance_194, const Udm::Object& componentDef_19d)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentInstance_194.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_199= cadena_scenario::ComponentInstance::Cast( componentInstance_194);
		if( false== Uml::IsDerivedFrom( componentDef_19d.type(), PICML::ComponentDef::meta))
			continue;
		PICML::ComponentDef componentDef_1a2= PICML::ComponentDef::Cast( componentDef_19d);
		set< PICML::Port> ports_1a4= componentDef_1a2.Port_kind_children();
		for( set< PICML::Port>::const_iterator itPort_1a5= ports_1a4.begin(); itPort_1a5!= ports_1a4.end(); ++itPort_1a5)
		{
			PICML::Port currPort_1a6= *itPort_1a5;
			set< cadena_scenario::ComponentPort> componentPorts_1a7= componentInstance_199.ComponentPort_kind_children();
			for( set< cadena_scenario::ComponentPort>::const_iterator itComponentPort_1a8= componentPorts_1a7.begin(); itComponentPort_1a8!= componentPorts_1a7.end(); ++itComponentPort_1a8)
			{
				cadena_scenario::ComponentPort currComponentPort_1a9= *itComponentPort_1a8;
				Match currMatch;
				currMatch.port_1aa= currPort_1a6;
				currMatch.componentPort_1ab= currComponentPort_1a9;
				currMatch.componentInstance_1ac= componentInstance_199;
				currMatch.componentDef_1ad= componentDef_1a2;
				bool Gz_guard= isGuardTrue( currMatch.componentDef_1ad, currMatch.componentInstance_1ac, currMatch.componentPort_1ab, currMatch.port_1aa);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void AssociatingPorts_18d::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.port_1aa.cadenaPort()+= currMatch.componentPort_1ab;
		outputAppender( );
	}
}

void AssociatingPorts_18d::outputAppender()
{
}

void PortsCreation_1b2::operator()( const Packets_t& pICML_Components_1b3, const Packets_t& cadena_Components_1b5)
{
#ifdef PRINT_INFO
	std::cout << "PortsCreation_1b2" << std::endl;
#endif
	if( ( !cadena_Components_1b5.empty())&& ( !pICML_Components_1b3.empty()))
		callEventSources_273( cadena_Components_1b5, pICML_Components_1b3);
}

void PortsCreation_1b2::callEventSources_273( const Packets_t& componentInstances_24e, const Packets_t& componentDefs_251)
{
	Packets_t componentInstances_250;
	Packets_t componentDefs_253;
	EventSources_24d eventSources_24d;
	eventSources_24d( componentInstances_24e, componentDefs_251, componentInstances_250, componentDefs_253);
	if( ( !componentDefs_253.empty())&& ( !componentInstances_250.empty()))
		callEventSinks_276( componentDefs_253, componentInstances_250);
}

void PortsCreation_1b2::callEventSinks_276( const Packets_t& componentDefs_228, const Packets_t& componentInstances_22b)
{
	Packets_t componentDefs_22a;
	Packets_t componentInstances_22d;
	EventSinks_227 eventSinks_227;
	eventSinks_227( componentDefs_228, componentInstances_22b, componentDefs_22a, componentInstances_22d);
	if( ( !componentDefs_22a.empty())&& ( !componentInstances_22d.empty()))
		callFacets_279( componentDefs_22a, componentInstances_22d);
}

void PortsCreation_1b2::callFacets_279( const Packets_t& componentDefs_202, const Packets_t& componentInstances_205)
{
	Packets_t componentDefs_204;
	Packets_t componentInstances_207;
	Facets_201 facets_201;
	facets_201( componentDefs_202, componentInstances_205, componentDefs_204, componentInstances_207);
	if( ( !componentDefs_204.empty())&& ( !componentInstances_207.empty()))
		callReceptacles_27c( componentDefs_204, componentInstances_207);
}

void PortsCreation_1b2::callReceptacles_27c( const Packets_t& componentDefs_1b8, const Packets_t& componentInstances_1bb)
{
	Packets_t componentDefs_1ba;
	Packets_t componentInstances_1bd;
	Receptacles_1b7 receptacles_1b7;
	receptacles_1b7( componentDefs_1b8, componentInstances_1bb, componentDefs_1ba, componentInstances_1bd);
	if( ( !componentInstances_1bd.empty())&& ( !componentDefs_1ba.empty()))
		callAssignNames_27f( componentInstances_1bd, componentDefs_1ba);
}

void PortsCreation_1b2::callAssignNames_27f( const Packets_t& componentInstances_1de, const Packets_t& componentDefs_1e0)
{
	AssignNames_1dd assignNames_1dd;
	assignNames_1dd( componentInstances_1de, componentDefs_1e0);
}

void Receptacles_1b7::operator()( const Packets_t& componentDefs_1b8, const Packets_t& componentInstances_1bb, Packets_t& componentDefs_1ba, Packets_t& componentInstances_1bd)
{
#ifdef PRINT_INFO
	std::cout << "Receptacles_1b7" << std::endl;
#endif
	_componentDef_1be= &componentDefs_1ba;
	_componentInstance_1bf= &componentInstances_1bd;
	processInputPackets( componentDefs_1b8, componentInstances_1bb);
	forwardInputs( );
}

bool Receptacles_1b7::isInputUnique( const Udm::Object& componentDef_1c4, const Udm::Object& componentInstance_1cd)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentDef_1c6= _componentDef_1c0.begin(), itComponentInstance_1cf= _componentInstance_1c9.begin(); itComponentDef_1c6!= _componentDef_1c0.end(), itComponentInstance_1cf!= _componentInstance_1c9.end(); ++itComponentDef_1c6, ++itComponentInstance_1cf)
	{
		if( ( *itComponentDef_1c6== componentDef_1c4)&& ( *itComponentInstance_1cf== componentInstance_1cd))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentDef_1c0.push_back( componentDef_1c4);
		_componentInstance_1c9.push_back( componentInstance_1cd);
	}
	return isUnique;
}

void Receptacles_1b7::processInputPackets( const Packets_t& componentDefs_1b8, const Packets_t& componentInstances_1bb)
{
	for( Packets_t::const_iterator itComponentDef_1c1= componentDefs_1b8.begin(), itComponentInstance_1ca= componentInstances_1bb.begin(); itComponentDef_1c1!= componentDefs_1b8.end(), itComponentInstance_1ca!= componentInstances_1bb.end(); ++itComponentDef_1c1, ++itComponentInstance_1ca)
	{
		bool isUnique= isInputUnique( *itComponentDef_1c1, *itComponentInstance_1ca);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentDef_1c1, *itComponentInstance_1ca);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Receptacles_1b7::patternMatcher( const Udm::Object& componentDef_1c2, const Udm::Object& componentInstance_1cb)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentDef_1c2.type(), PICML::ComponentDef::meta))
			continue;
		PICML::ComponentDef componentDef_1c7= PICML::ComponentDef::Cast( componentDef_1c2);
		if( false== Uml::IsDerivedFrom( componentInstance_1cb.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_1d0= cadena_scenario::ComponentInstance::Cast( componentInstance_1cb);
		set< PICML::RequiredRequestPort> requiredRequestPorts_1d2= componentDef_1c7.RequiredRequestPort_kind_children();
		for( set< PICML::RequiredRequestPort>::const_iterator itRequiredRequestPort_1d3= requiredRequestPorts_1d2.begin(); itRequiredRequestPort_1d3!= requiredRequestPorts_1d2.end(); ++itRequiredRequestPort_1d3)
		{
			PICML::RequiredRequestPort currRequiredRequestPort_1d4= *itRequiredRequestPort_1d3;
			Match currMatch;
			currMatch.requiredRequestPort_1d5= currRequiredRequestPort_1d4;
			currMatch.componentDef_1d6= componentDef_1c7;
			currMatch.componentInstance_1d7= componentInstance_1d0;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Receptacles_1b7::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::Receptacle newReceptacle_1d8= cadena_scenario::Receptacle::Create( currMatch.componentInstance_1d7);
		currMatch.requiredRequestPort_1d5.cadenaPort()+= newReceptacle_1d8;
		outputAppender( currMatch.componentDef_1d6, currMatch.componentInstance_1d7);
	}
}

void Receptacles_1b7::outputAppender( const PICML::ComponentDef& componentDef_1d9, const cadena_scenario::ComponentInstance& componentInstance_1db)
{
	_componentDef_1be->push_back( componentDef_1d9);
	_componentInstance_1bf->push_back( componentInstance_1db);
}

void Receptacles_1b7::forwardInputs()
{
	*_componentDef_1be= _componentDef_1c0;
	*_componentInstance_1bf= _componentInstance_1c9;
}

void AssignNames_1dd::operator()( const Packets_t& componentInstances_1de, const Packets_t& componentDefs_1e0)
{
#ifdef PRINT_INFO
	std::cout << "AssignNames_1dd" << std::endl;
#endif
	processInputPackets( componentInstances_1de, componentDefs_1e0);
}

bool AssignNames_1dd::isInputUnique( const Udm::Object& componentInstance_1e6, const Udm::Object& componentDef_1ef)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentInstance_1e8= _componentInstance_1e2.begin(), itComponentDef_1f1= _componentDef_1eb.begin(); itComponentInstance_1e8!= _componentInstance_1e2.end(), itComponentDef_1f1!= _componentDef_1eb.end(); ++itComponentInstance_1e8, ++itComponentDef_1f1)
	{
		if( ( *itComponentInstance_1e8== componentInstance_1e6)&& ( *itComponentDef_1f1== componentDef_1ef))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentInstance_1e2.push_back( componentInstance_1e6);
		_componentDef_1eb.push_back( componentDef_1ef);
	}
	return isUnique;
}

void AssignNames_1dd::processInputPackets( const Packets_t& componentInstances_1de, const Packets_t& componentDefs_1e0)
{
	for( Packets_t::const_iterator itComponentInstance_1e3= componentInstances_1de.begin(), itComponentDef_1ec= componentDefs_1e0.begin(); itComponentInstance_1e3!= componentInstances_1de.end(), itComponentDef_1ec!= componentDefs_1e0.end(); ++itComponentInstance_1e3, ++itComponentDef_1ec)
	{
		bool isUnique= isInputUnique( *itComponentInstance_1e3, *itComponentDef_1ec);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentInstance_1e3, *itComponentDef_1ec);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool AssignNames_1dd::patternMatcher( const Udm::Object& componentInstance_1e4, const Udm::Object& componentDef_1ed)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentInstance_1e4.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_1e9= cadena_scenario::ComponentInstance::Cast( componentInstance_1e4);
		if( false== Uml::IsDerivedFrom( componentDef_1ed.type(), PICML::ComponentDef::meta))
			continue;
		PICML::ComponentDef componentDef_1f2= PICML::ComponentDef::Cast( componentDef_1ed);
		set< PICML::Port> ports_1f4= componentDef_1f2.Port_kind_children();
		for( set< PICML::Port>::const_iterator itPort_1f5= ports_1f4.begin(); itPort_1f5!= ports_1f4.end(); ++itPort_1f5)
		{
			PICML::Port currPort_1f6= *itPort_1f5;
			set< cadena_scenario::ComponentPort> componentPorts_1f7= componentInstance_1e9.ComponentPort_kind_children();
			for( set< cadena_scenario::ComponentPort>::const_iterator itComponentPort_1f8= componentPorts_1f7.begin(); itComponentPort_1f8!= componentPorts_1f7.end(); ++itComponentPort_1f8)
			{
				cadena_scenario::ComponentPort currComponentPort_1f9= *itComponentPort_1f8;
				set< cadena_scenario::ComponentPort> componentPorts_1fa= currPort_1f6.cadenaPort();
				for( set< cadena_scenario::ComponentPort>::const_iterator itComponentPorts_1fb= componentPorts_1fa.begin(); itComponentPorts_1fb!= componentPorts_1fa.end(); ++itComponentPorts_1fb)
				{
					cadena_scenario::ComponentPort currComponentPort_1fc= *itComponentPorts_1fb;
					if( currComponentPort_1f9!= currComponentPort_1fc)
						continue;
					Match currMatch;
					currMatch.componentPort_1fd= currComponentPort_1f9;
					currMatch.port_1fe= currPort_1f6;
					currMatch.componentInstance_1ff= componentInstance_1e9;
					currMatch.componentDef_200= componentDef_1f2;
					_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void AssignNames_1dd::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& ComponentDef= currMatch.componentDef_200;
		Udm::Object& ComponentInstance= currMatch.componentInstance_1ff;
		Udm::Object& ComponentPort= currMatch.componentPort_1fd;
		Udm::Object& Port= currMatch.port_1fe;
		{string s; Port.GetStrValue("name",s); ComponentPort.SetStrValue("Name",s);};
		outputAppender( );
	}
}

void AssignNames_1dd::outputAppender()
{
}

void Facets_201::operator()( const Packets_t& componentDefs_202, const Packets_t& componentInstances_205, Packets_t& componentDefs_204, Packets_t& componentInstances_207)
{
#ifdef PRINT_INFO
	std::cout << "Facets_201" << std::endl;
#endif
	_componentDef_208= &componentDefs_204;
	_componentInstance_209= &componentInstances_207;
	processInputPackets( componentDefs_202, componentInstances_205);
	forwardInputs( );
}

bool Facets_201::isInputUnique( const Udm::Object& componentDef_20e, const Udm::Object& componentInstance_217)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentDef_210= _componentDef_20a.begin(), itComponentInstance_219= _componentInstance_213.begin(); itComponentDef_210!= _componentDef_20a.end(), itComponentInstance_219!= _componentInstance_213.end(); ++itComponentDef_210, ++itComponentInstance_219)
	{
		if( ( *itComponentDef_210== componentDef_20e)&& ( *itComponentInstance_219== componentInstance_217))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentDef_20a.push_back( componentDef_20e);
		_componentInstance_213.push_back( componentInstance_217);
	}
	return isUnique;
}

void Facets_201::processInputPackets( const Packets_t& componentDefs_202, const Packets_t& componentInstances_205)
{
	for( Packets_t::const_iterator itComponentDef_20b= componentDefs_202.begin(), itComponentInstance_214= componentInstances_205.begin(); itComponentDef_20b!= componentDefs_202.end(), itComponentInstance_214!= componentInstances_205.end(); ++itComponentDef_20b, ++itComponentInstance_214)
	{
		bool isUnique= isInputUnique( *itComponentDef_20b, *itComponentInstance_214);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentDef_20b, *itComponentInstance_214);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Facets_201::patternMatcher( const Udm::Object& componentDef_20c, const Udm::Object& componentInstance_215)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentDef_20c.type(), PICML::ComponentDef::meta))
			continue;
		PICML::ComponentDef componentDef_211= PICML::ComponentDef::Cast( componentDef_20c);
		if( false== Uml::IsDerivedFrom( componentInstance_215.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_21a= cadena_scenario::ComponentInstance::Cast( componentInstance_215);
		set< PICML::ProvidedRequestPort> providedRequestPorts_21c= componentDef_211.ProvidedRequestPort_kind_children();
		for( set< PICML::ProvidedRequestPort>::const_iterator itProvidedRequestPort_21d= providedRequestPorts_21c.begin(); itProvidedRequestPort_21d!= providedRequestPorts_21c.end(); ++itProvidedRequestPort_21d)
		{
			PICML::ProvidedRequestPort currProvidedRequestPort_21e= *itProvidedRequestPort_21d;
			Match currMatch;
			currMatch.providedRequestPort_21f= currProvidedRequestPort_21e;
			currMatch.componentDef_220= componentDef_211;
			currMatch.componentInstance_221= componentInstance_21a;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Facets_201::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::Facet newFacet_222= cadena_scenario::Facet::Create( currMatch.componentInstance_221);
		currMatch.providedRequestPort_21f.cadenaPort()+= newFacet_222;
		outputAppender( currMatch.componentDef_220, currMatch.componentInstance_221);
	}
}

void Facets_201::outputAppender( const PICML::ComponentDef& componentDef_223, const cadena_scenario::ComponentInstance& componentInstance_225)
{
	_componentDef_208->push_back( componentDef_223);
	_componentInstance_209->push_back( componentInstance_225);
}

void Facets_201::forwardInputs()
{
	*_componentDef_208= _componentDef_20a;
	*_componentInstance_209= _componentInstance_213;
}

void EventSinks_227::operator()( const Packets_t& componentDefs_228, const Packets_t& componentInstances_22b, Packets_t& componentDefs_22a, Packets_t& componentInstances_22d)
{
#ifdef PRINT_INFO
	std::cout << "EventSinks_227" << std::endl;
#endif
	_componentDef_22e= &componentDefs_22a;
	_componentInstance_22f= &componentInstances_22d;
	processInputPackets( componentDefs_228, componentInstances_22b);
	forwardInputs( );
}

bool EventSinks_227::isInputUnique( const Udm::Object& componentDef_234, const Udm::Object& componentInstance_23d)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentDef_236= _componentDef_230.begin(), itComponentInstance_23f= _componentInstance_239.begin(); itComponentDef_236!= _componentDef_230.end(), itComponentInstance_23f!= _componentInstance_239.end(); ++itComponentDef_236, ++itComponentInstance_23f)
	{
		if( ( *itComponentDef_236== componentDef_234)&& ( *itComponentInstance_23f== componentInstance_23d))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentDef_230.push_back( componentDef_234);
		_componentInstance_239.push_back( componentInstance_23d);
	}
	return isUnique;
}

void EventSinks_227::processInputPackets( const Packets_t& componentDefs_228, const Packets_t& componentInstances_22b)
{
	for( Packets_t::const_iterator itComponentDef_231= componentDefs_228.begin(), itComponentInstance_23a= componentInstances_22b.begin(); itComponentDef_231!= componentDefs_228.end(), itComponentInstance_23a!= componentInstances_22b.end(); ++itComponentDef_231, ++itComponentInstance_23a)
	{
		bool isUnique= isInputUnique( *itComponentDef_231, *itComponentInstance_23a);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentDef_231, *itComponentInstance_23a);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool EventSinks_227::patternMatcher( const Udm::Object& componentDef_232, const Udm::Object& componentInstance_23b)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentDef_232.type(), PICML::ComponentDef::meta))
			continue;
		PICML::ComponentDef componentDef_237= PICML::ComponentDef::Cast( componentDef_232);
		if( false== Uml::IsDerivedFrom( componentInstance_23b.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_240= cadena_scenario::ComponentInstance::Cast( componentInstance_23b);
		set< PICML::InEventPort> inEventPorts_242= componentDef_237.InEventPort_kind_children();
		for( set< PICML::InEventPort>::const_iterator itInEventPort_243= inEventPorts_242.begin(); itInEventPort_243!= inEventPorts_242.end(); ++itInEventPort_243)
		{
			PICML::InEventPort currInEventPort_244= *itInEventPort_243;
			Match currMatch;
			currMatch.inEventPort_245= currInEventPort_244;
			currMatch.componentDef_246= componentDef_237;
			currMatch.componentInstance_247= componentInstance_240;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void EventSinks_227::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::EventSink newEventSink_248= cadena_scenario::EventSink::Create( currMatch.componentInstance_247);
		currMatch.inEventPort_245.cadenaPort()+= newEventSink_248;
		outputAppender( currMatch.componentDef_246, currMatch.componentInstance_247);
	}
}

void EventSinks_227::outputAppender( const PICML::ComponentDef& componentDef_249, const cadena_scenario::ComponentInstance& componentInstance_24b)
{
	_componentDef_22e->push_back( componentDef_249);
	_componentInstance_22f->push_back( componentInstance_24b);
}

void EventSinks_227::forwardInputs()
{
	*_componentDef_22e= _componentDef_230;
	*_componentInstance_22f= _componentInstance_239;
}

void EventSources_24d::operator()( const Packets_t& componentInstances_24e, const Packets_t& componentDefs_251, Packets_t& componentInstances_250, Packets_t& componentDefs_253)
{
#ifdef PRINT_INFO
	std::cout << "EventSources_24d" << std::endl;
#endif
	_componentInstance_254= &componentInstances_250;
	_componentDef_255= &componentDefs_253;
	processInputPackets( componentInstances_24e, componentDefs_251);
	forwardInputs( );
}

bool EventSources_24d::isInputUnique( const Udm::Object& componentInstance_25a, const Udm::Object& componentDef_263)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentInstance_25c= _componentInstance_256.begin(), itComponentDef_265= _componentDef_25f.begin(); itComponentInstance_25c!= _componentInstance_256.end(), itComponentDef_265!= _componentDef_25f.end(); ++itComponentInstance_25c, ++itComponentDef_265)
	{
		if( ( *itComponentInstance_25c== componentInstance_25a)&& ( *itComponentDef_265== componentDef_263))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentInstance_256.push_back( componentInstance_25a);
		_componentDef_25f.push_back( componentDef_263);
	}
	return isUnique;
}

void EventSources_24d::processInputPackets( const Packets_t& componentInstances_24e, const Packets_t& componentDefs_251)
{
	for( Packets_t::const_iterator itComponentInstance_257= componentInstances_24e.begin(), itComponentDef_260= componentDefs_251.begin(); itComponentInstance_257!= componentInstances_24e.end(), itComponentDef_260!= componentDefs_251.end(); ++itComponentInstance_257, ++itComponentDef_260)
	{
		bool isUnique= isInputUnique( *itComponentInstance_257, *itComponentDef_260);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentInstance_257, *itComponentDef_260);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool EventSources_24d::patternMatcher( const Udm::Object& componentInstance_258, const Udm::Object& componentDef_261)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentInstance_258.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_25d= cadena_scenario::ComponentInstance::Cast( componentInstance_258);
		if( false== Uml::IsDerivedFrom( componentDef_261.type(), PICML::ComponentDef::meta))
			continue;
		PICML::ComponentDef componentDef_266= PICML::ComponentDef::Cast( componentDef_261);
		set< PICML::OutEventPort> outEventPorts_268= componentDef_266.OutEventPort_kind_children();
		for( set< PICML::OutEventPort>::const_iterator itOutEventPort_269= outEventPorts_268.begin(); itOutEventPort_269!= outEventPorts_268.end(); ++itOutEventPort_269)
		{
			PICML::OutEventPort currOutEventPort_26a= *itOutEventPort_269;
			Match currMatch;
			currMatch.componentInstance_26b= componentInstance_25d;
			currMatch.outEventPort_26c= currOutEventPort_26a;
			currMatch.componentDef_26d= componentDef_266;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void EventSources_24d::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::EventSource newEventSource_26e= cadena_scenario::EventSource::Create( currMatch.componentInstance_26b);
		currMatch.outEventPort_26c.cadenaPort()+= newEventSource_26e;
		outputAppender( currMatch.componentInstance_26b, currMatch.componentDef_26d);
	}
}

void EventSources_24d::outputAppender( const cadena_scenario::ComponentInstance& componentInstance_26f, const PICML::ComponentDef& componentDef_271)
{
	_componentInstance_254->push_back( componentInstance_26f);
	_componentDef_255->push_back( componentDef_271);
}

void EventSources_24d::forwardInputs()
{
	*_componentInstance_254= _componentInstance_256;
	*_componentDef_255= _componentDef_25f;
}

void ComponentCreation_282::operator()( const Packets_t& componentAssemblys_283, const Packets_t& scenarios_286, Packets_t& componentAssemblys_285, Packets_t& scenarios_288)
{
#ifdef PRINT_INFO
	std::cout << "ComponentCreation_282" << std::endl;
#endif
	_componentAssembly_289= &componentAssemblys_285;
	_scenario_28a= &scenarios_288;
	processInputPackets( componentAssemblys_283, scenarios_286);
	forwardInputs( );
}

bool ComponentCreation_282::isInputUnique( const Udm::Object& componentAssembly_28f, const Udm::Object& scenario_298)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_291= _componentAssembly_28b.begin(), itScenario_29a= _scenario_294.begin(); itComponentAssembly_291!= _componentAssembly_28b.end(), itScenario_29a!= _scenario_294.end(); ++itComponentAssembly_291, ++itScenario_29a)
	{
		if( ( *itComponentAssembly_291== componentAssembly_28f)&& ( *itScenario_29a== scenario_298))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentAssembly_28b.push_back( componentAssembly_28f);
		_scenario_294.push_back( scenario_298);
	}
	return isUnique;
}

bool ComponentCreation_282::isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ComponentDef, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& ComponentInstance, const Udm::Object& IDLFile, const Udm::Object& IDLFiles, const Udm::Object& RootFolder, const Udm::Object& Scenario)
{
	bool Gz_guard= false;
	string cadtype, picmltype; ComponentInstance.GetStrValue("type", cadtype); ComponentDef.GetStrValue("name", picmltype); return (cadtype==picmltype);;
	return Gz_guard;
}

void ComponentCreation_282::processInputPackets( const Packets_t& componentAssemblys_283, const Packets_t& scenarios_286)
{
	for( Packets_t::const_iterator itComponentAssembly_28c= componentAssemblys_283.begin(), itScenario_295= scenarios_286.begin(); itComponentAssembly_28c!= componentAssemblys_283.end(), itScenario_295!= scenarios_286.end(); ++itComponentAssembly_28c, ++itScenario_295)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_28c, *itScenario_295);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_28c, *itScenario_295);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool ComponentCreation_282::patternMatcher( const Udm::Object& componentAssembly_28d, const Udm::Object& scenario_296)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_28d.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_292= PICML::ComponentAssembly::Cast( componentAssembly_28d);
		if( false== Uml::IsDerivedFrom( scenario_296.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_29b= cadena_scenario::Scenario::Cast( scenario_296);
		set< cadena_scenario::ComponentInstance> componentInstances_29d= scenario_29b.ComponentInstance_kind_children();
		for( set< cadena_scenario::ComponentInstance>::const_iterator itComponentInstance_29e= componentInstances_29d.begin(); itComponentInstance_29e!= componentInstances_29d.end(); ++itComponentInstance_29e)
		{
			cadena_scenario::ComponentInstance currComponentInstance_29f= *itComponentInstance_29e;
			Udm::Object componentAssemblyParent_2a0= componentAssembly_292.container();
			if( false== Uml::IsDerivedFrom( componentAssemblyParent_2a0.type(), PICML::ComponentImplementationContainer::meta))
				continue;
			PICML::ComponentImplementationContainer componentImplementationContainerComponentAssembly_2a1= PICML::ComponentImplementationContainer::Cast( componentAssemblyParent_2a0);
			Udm::Object componentImplementationContainerParent_2a2= componentImplementationContainerComponentAssembly_2a1.container();
			if( false== Uml::IsDerivedFrom( componentImplementationContainerParent_2a2.type(), PICML::ComponentImplementations::meta))
				continue;
			PICML::ComponentImplementations componentImplementationsComponentImplementationContainer_2a3= PICML::ComponentImplementations::Cast( componentImplementationContainerParent_2a2);
			Udm::Object componentImplementationsParent_2a4= componentImplementationsComponentImplementationContainer_2a3.container();
			if( false== Uml::IsDerivedFrom( componentImplementationsParent_2a4.type(), PICML::RootFolder::meta))
				continue;
			PICML::RootFolder rootFolderComponentImplementations_2a5= PICML::RootFolder::Cast( componentImplementationsParent_2a4);
			set< PICML::IDLFiles> iDLFiless_2a6= rootFolderComponentImplementations_2a5.IDLFiles_kind_children();
			for( set< PICML::IDLFiles>::const_iterator itIDLFiles_2a7= iDLFiless_2a6.begin(); itIDLFiles_2a7!= iDLFiless_2a6.end(); ++itIDLFiles_2a7)
			{
				PICML::IDLFiles currIDLFiles_2a8= *itIDLFiles_2a7;
				set< PICML::IDLFile> iDLFiles_2a9= currIDLFiles_2a8.IDLFile_kind_children();
				for( set< PICML::IDLFile>::const_iterator itIDLFile_2aa= iDLFiles_2a9.begin(); itIDLFile_2aa!= iDLFiles_2a9.end(); ++itIDLFile_2aa)
				{
					PICML::IDLFile currIDLFile_2ab= *itIDLFile_2aa;
					set< PICML::ComponentDef> componentDefs_2ac= currIDLFile_2ab.ComponentDef_kind_children();
					for( set< PICML::ComponentDef>::const_iterator itComponentDef_2ad= componentDefs_2ac.begin(); itComponentDef_2ad!= componentDefs_2ac.end(); ++itComponentDef_2ad)
					{
						PICML::ComponentDef currComponentDef_2ae= *itComponentDef_2ad;
						Match currMatch;
						currMatch.componentDef_2af= currComponentDef_2ae;
						currMatch.componentInstance_2b0= currComponentInstance_29f;
						currMatch.iDLFile_2b1= currIDLFile_2ab;
						currMatch.iDLFiles_2b2= currIDLFiles_2a8;
						currMatch.rootFolder_2b3= rootFolderComponentImplementations_2a5;
						currMatch.componentImplementationContainer_2b4= componentImplementationContainerComponentAssembly_2a1;
						currMatch.componentImplementations_2b5= componentImplementationsComponentImplementationContainer_2a3;
						currMatch.componentAssembly_2b6= componentAssembly_292;
						currMatch.scenario_2b7= scenario_29b;
						bool Gz_guard= isGuardTrue( currMatch.componentAssembly_2b6, currMatch.componentDef_2af, currMatch.componentImplementationContainer_2b4, currMatch.componentImplementations_2b5, currMatch.componentInstance_2b0, currMatch.iDLFile_2b1, currMatch.iDLFiles_2b2, currMatch.rootFolder_2b3, currMatch.scenario_2b7);
						if( true== Gz_guard)
							_matches.push_back( currMatch);
					}
				}
			}
		}
	}
	return !_matches.empty();
}

void ComponentCreation_282::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_2b6;
		Udm::Object& ComponentDef= currMatch.componentDef_2af;
		Udm::Object& ComponentImplementationContainer= currMatch.componentImplementationContainer_2b4;
		Udm::Object& ComponentImplementations= currMatch.componentImplementations_2b5;
		Udm::Object& ComponentInstance= currMatch.componentInstance_2b0;
		Udm::Object& IDLFile= currMatch.iDLFile_2b1;
		Udm::Object& IDLFiles= currMatch.iDLFiles_2b2;
		Udm::Object& RootFolder= currMatch.rootFolder_2b3;
		Udm::Object& Scenario= currMatch.scenario_2b7;
		{string cadname; ComponentInstance.GetStrValue("name", cadname);  ComponentAssembly.__impl()->createChild(Udm::NULLCHILDROLE, ComponentDef.type(), ComponentDef.__impl())   ->setStringAttr(Uml::Attribute::meta_name, cadname);};
		outputAppender( currMatch.componentAssembly_2b6, currMatch.scenario_2b7);
	}
}

void ComponentCreation_282::outputAppender( const PICML::ComponentAssembly& componentAssembly_2c1, const cadena_scenario::Scenario& scenario_2c3)
{
	_componentAssembly_289->push_back( componentAssembly_2c1);
	_scenario_28a->push_back( scenario_2c3);
}

void ComponentCreation_282::forwardInputs()
{
	*_componentAssembly_289= _componentAssembly_28b;
	*_scenario_28a= _scenario_294;
}

