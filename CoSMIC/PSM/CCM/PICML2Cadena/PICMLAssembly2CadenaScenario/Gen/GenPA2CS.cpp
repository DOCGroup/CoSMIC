#include "GenPA2CS.h"
#include <UmlExt.h>
#include <UdmUtil.h>

void RootRuleBlock_0::operator()( const Packets_t& pICML_File_Ins_1, const Packets_t& cadena_File_Ins_3)
{
#ifdef PRINT_INFO
	std::cout << "RootRuleBlock_0" << std::endl;
#endif
	if( ( !pICML_File_Ins_1.empty())&& ( !cadena_File_Ins_3.empty()))
		callRootFinder_28f( pICML_File_Ins_1, cadena_File_Ins_3);
}

void RootRuleBlock_0::callRootFinder_28f( const Packets_t& rootFolders_15e, const Packets_t& scenarios_160)
{
	Packets_t scenarios_162;
	Packets_t componentAssemblys_163;
	RootFinder_15d rootFinder_15d;
	rootFinder_15d( rootFolders_15e, scenarios_160, scenarios_162, componentAssemblys_163);
	if( ( !componentAssemblys_163.empty())&& ( !scenarios_162.empty()))
		callComponentCreation_292( componentAssemblys_163, scenarios_162);
}

void RootRuleBlock_0::callComponentCreation_292( const Packets_t& pICML_Assembly_Ins_18b, const Packets_t& cadena_Scenario_Ins_18d)
{
	Packets_t cadena_Scenario_Outs_18f;
	Packets_t pICML_Assembly_Outs_190;
	ComponentCreation_18a componentCreation_18a;
	componentCreation_18a( pICML_Assembly_Ins_18b, cadena_Scenario_Ins_18d, cadena_Scenario_Outs_18f, pICML_Assembly_Outs_190);
	if( ( !pICML_Assembly_Outs_190.empty())&& ( !cadena_Scenario_Outs_18f.empty()))
		callPortConnection_295( pICML_Assembly_Outs_190, cadena_Scenario_Outs_18f);
}

void RootRuleBlock_0::callPortConnection_295( const Packets_t& pICML_Assembly_Ins_6, const Packets_t& cadena_Scenario_Ins_8)
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
		callInputSplitter_145( cadena_Scenario_Ins_8, pICML_Assembly_Ins_6);
}

void PortConnection_5::callInputSplitter_145( const Packets_t& scenarios_65, const Packets_t& componentAssemblys_68)
{
	Packets_t scenarios_67;
	Packets_t componentAssemblys_6a;
	InputSplitter_64 inputSplitter_64;
	inputSplitter_64( scenarios_65, componentAssemblys_68, scenarios_67, componentAssemblys_6a);
	if( ( !scenarios_67.empty())&& ( !componentAssemblys_6a.empty()))
		callCreatingPublishConnectors_148( scenarios_67, componentAssemblys_6a);
	if( ( !scenarios_67.empty())&& ( !componentAssemblys_6a.empty()))
		callPortFinder_14b( scenarios_67, componentAssemblys_6a);
}

void PortConnection_5::callCreatingPublishConnectors_148( const Packets_t& scenarios_d1, const Packets_t& componentAssemblys_d5)
{
	Packets_t eSSConnections_d3;
	Packets_t publishConnectors_d4;
	CreatingPublishConnectors_d0 creatingPublishConnectors_d0;
	creatingPublishConnectors_d0( scenarios_d1, componentAssemblys_d5, eSSConnections_d3, publishConnectors_d4);
	if( ( !publishConnectors_d4.empty())&& ( !eSSConnections_d3.empty()))
		callConnectorsToSinks_14e( publishConnectors_d4, eSSConnections_d3);
	if( ( !publishConnectors_d4.empty())&& ( !eSSConnections_d3.empty()))
		callTransferingCorrelatorStrings_151( publishConnectors_d4, eSSConnections_d3);
	if( ( !eSSConnections_d3.empty())&& ( !publishConnectors_d4.empty()))
		callSourcesToConnectors_154( eSSConnections_d3, publishConnectors_d4);
}

void PortConnection_5::callPortFinder_14b( const Packets_t& scenarios_f7, const Packets_t& componentAssemblys_fb)
{
	Packets_t scenarios_f9;
	Packets_t ports_fa;
	PortFinder_f6 portFinder_f6;
	portFinder_f6( scenarios_f7, componentAssemblys_fb, scenarios_f9, ports_fa);
	if( ( !ports_fa.empty())&& ( !scenarios_f9.empty()))
		callMethodInvocations_157( ports_fa, scenarios_f9);
	if( ( !scenarios_f9.empty())&& ( !ports_fa.empty()))
		callEmits_15a( scenarios_f9, ports_fa);
}

void PortConnection_5::callConnectorsToSinks_14e( const Packets_t& publishConnectors_b, const Packets_t& eSSConnections_d)
{
	ConnectorsToSinks_a connectorsToSinks_a;
	connectorsToSinks_a( publishConnectors_b, eSSConnections_d);
}

void PortConnection_5::callTransferingCorrelatorStrings_151( const Packets_t& publishConnectors_2e, const Packets_t& eSSConnections_30)
{
	TransferingCorrelatorStrings_2d transferingCorrelatorStrings_2d;
	transferingCorrelatorStrings_2d( publishConnectors_2e, eSSConnections_30);
}

void PortConnection_5::callSourcesToConnectors_154( const Packets_t& eSSConnections_ae, const Packets_t& publishConnectors_b0)
{
	SourcesToConnectors_ad sourcesToConnectors_ad;
	sourcesToConnectors_ad( eSSConnections_ae, publishConnectors_b0);
}

void PortConnection_5::callMethodInvocations_157( const Packets_t& requiredRequestPorts_86, const Packets_t& scenarios_88)
{
	MethodInvocations_85 methodInvocations_85;
	methodInvocations_85( requiredRequestPorts_86, scenarios_88);
}

void PortConnection_5::callEmits_15a( const Packets_t& scenarios_120, const Packets_t& outEventPorts_122)
{
	Emits_11f emits_11f;
	emits_11f( scenarios_120, outEventPorts_122);
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
		set< PICML::InEventPortConsume> inEventPortConsumes_21= publishConnector_16.dstInEventPortConsume();
		for( set< PICML::InEventPortConsume>::const_iterator itInEventPortConsumes_22= inEventPortConsumes_21.begin(); itInEventPortConsumes_22!= inEventPortConsumes_21.end(); ++itInEventPortConsumes_22)
		{
			PICML::InEventPortConsume currInEventPortConsume_23= *itInEventPortConsumes_22;
			PICML::InEventPort inEventPort_24= currInEventPortConsume_23.dstInEventPortConsume_end();
			set< cadena_scenario::ComponentPort> eventSinks_25= inEventPort_24.cadenaPort();
			for( set< cadena_scenario::ComponentPort>::const_iterator itEventSinks_26= eventSinks_25.begin(); itEventSinks_26!= eventSinks_25.end(); ++itEventSinks_26)
			{
				if( false== Uml::IsDerivedFrom( (*itEventSinks_26).type(), cadena_scenario::EventSink::meta))
					continue;
				cadena_scenario::EventSink currEventSink_27= cadena_scenario::EventSink::Cast( *itEventSinks_26);
				Match currMatch;
				currMatch.inEventPort_28= inEventPort_24;
				currMatch.eventSink_29= currEventSink_27;
				currMatch.inEventPortConsume_2a= currInEventPortConsume_23;
				currMatch.publishConnector_2b= publishConnector_16;
				currMatch.eSSConnection_2c= eSSConnection_1f;
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
		currMatch.eSSConnection_2c.sinks()+= currMatch.eventSink_29;
		outputAppender( );
	}
}

void ConnectorsToSinks_a::outputAppender()
{
}

void TransferingCorrelatorStrings_2d::operator()( const Packets_t& publishConnectors_2e, const Packets_t& eSSConnections_30)
{
#ifdef PRINT_INFO
	std::cout << "TransferingCorrelatorStrings_2d" << std::endl;
#endif
	processInputPackets( publishConnectors_2e, eSSConnections_30);
}

bool TransferingCorrelatorStrings_2d::isInputUnique( const Udm::Object& publishConnector_36, const Udm::Object& eSSConnection_3f)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPublishConnector_38= _publishConnector_32.begin(), itESSConnection_41= _eSSConnection_3b.begin(); itPublishConnector_38!= _publishConnector_32.end(), itESSConnection_41!= _eSSConnection_3b.end(); ++itPublishConnector_38, ++itESSConnection_41)
	{
		if( ( *itPublishConnector_38== publishConnector_36)&& ( *itESSConnection_41== eSSConnection_3f))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_publishConnector_32.push_back( publishConnector_36);
		_eSSConnection_3b.push_back( eSSConnection_3f);
	}
	return isUnique;
}

bool TransferingCorrelatorStrings_2d::isGuardTrue( const Udm::Object& Any, const Udm::Object& ConnectionRequirements, const Udm::Object& DataType, const Udm::Object& ESSConnection, const Udm::Object& PredefinedType, const Udm::Object& Property, const Udm::Object& PublishConnector, const Udm::Object& Requirement)
{
	bool Gz_guard= false;
	string s; Requirement.GetStrValue("name",s); for (string::iterator i = s.begin(); i != s.end(); i++) *i = tolower(*i); if (s=="correlator") return true; else return false;;
	return Gz_guard;
}

void TransferingCorrelatorStrings_2d::processInputPackets( const Packets_t& publishConnectors_2e, const Packets_t& eSSConnections_30)
{
	for( Packets_t::const_iterator itPublishConnector_33= publishConnectors_2e.begin(), itESSConnection_3c= eSSConnections_30.begin(); itPublishConnector_33!= publishConnectors_2e.end(), itESSConnection_3c!= eSSConnections_30.end(); ++itPublishConnector_33, ++itESSConnection_3c)
	{
		bool isUnique= isInputUnique( *itPublishConnector_33, *itESSConnection_3c);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPublishConnector_33, *itESSConnection_3c);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool TransferingCorrelatorStrings_2d::patternMatcher( const Udm::Object& publishConnector_34, const Udm::Object& eSSConnection_3d)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( publishConnector_34.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_39= PICML::PublishConnector::Cast( publishConnector_34);
		if( false== Uml::IsDerivedFrom( eSSConnection_3d.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_42= cadena_scenario::ESSConnection::Cast( eSSConnection_3d);
		set< PICML::ConnectionRequirements> connectionRequirementss_44= publishConnector_39.dstConnectionRequirements();
		for( set< PICML::ConnectionRequirements>::const_iterator itConnectionRequirementss_45= connectionRequirementss_44.begin(); itConnectionRequirementss_45!= connectionRequirementss_44.end(); ++itConnectionRequirementss_45)
		{
			PICML::ConnectionRequirements currConnectionRequirements_46= *itConnectionRequirementss_45;
			PICML::Requirement requirement_47= currConnectionRequirements_46.dstConnectionRequirements_end();
			set< PICML::Property> propertys_48= requirement_47.Property_kind_children();
			for( set< PICML::Property>::const_iterator itProperty_49= propertys_48.begin(); itProperty_49!= propertys_48.end(); ++itProperty_49)
			{
				PICML::Property currProperty_4a= *itProperty_49;
				set< PICML::Any> anys_4b= currProperty_4a.Any_kind_children();
				for( set< PICML::Any>::const_iterator itAny_4c= anys_4b.begin(); itAny_4c!= anys_4b.end(); ++itAny_4c)
				{
					PICML::Any currAny_4d= *itAny_4c;
					set< PICML::DataType> dataTypes_4e= currAny_4d.DataType_kind_children();
					for( set< PICML::DataType>::const_iterator itDataType_4f= dataTypes_4e.begin(); itDataType_4f!= dataTypes_4e.end(); ++itDataType_4f)
					{
						PICML::DataType currDataType_50= *itDataType_4f;
						set< PICML::PredefinedType> predefinedTypes_51= currDataType_50.PredefinedType_kind_children();
						for( set< PICML::PredefinedType>::const_iterator itPredefinedType_52= predefinedTypes_51.begin(); itPredefinedType_52!= predefinedTypes_51.end(); ++itPredefinedType_52)
						{
							PICML::PredefinedType currPredefinedType_53= *itPredefinedType_52;
							Match currMatch;
							currMatch.dataType_54= currDataType_50;
							currMatch.connectionRequirements_55= currConnectionRequirements_46;
							currMatch.property_56= currProperty_4a;
							currMatch.any_57= currAny_4d;
							currMatch.predefinedType_58= currPredefinedType_53;
							currMatch.requirement_59= requirement_47;
							currMatch.publishConnector_5a= publishConnector_39;
							currMatch.eSSConnection_5b= eSSConnection_42;
							bool Gz_guard= isGuardTrue( currMatch.any_57, currMatch.connectionRequirements_55, currMatch.dataType_54, currMatch.eSSConnection_5b, currMatch.predefinedType_58, currMatch.property_56, currMatch.publishConnector_5a, currMatch.requirement_59);
							if( true== Gz_guard)
								_matches.push_back( currMatch);
						}
					}
				}
			}
		}
	}
	return !_matches.empty();
}

void TransferingCorrelatorStrings_2d::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& Any= currMatch.any_57;
		Udm::Object& ConnectionRequirements= currMatch.connectionRequirements_55;
		Udm::Object& DataType= currMatch.dataType_54;
		Udm::Object& ESSConnection= currMatch.eSSConnection_5b;
		Udm::Object& PredefinedType= currMatch.predefinedType_58;
		Udm::Object& Property= currMatch.property_56;
		Udm::Object& PublishConnector= currMatch.publishConnector_5a;
		Udm::Object& Requirement= currMatch.requirement_59;
		{string s="correlator mapping not yet implemented"; Any.GetStrValue("DataValue",s); ESSConnection.SetStrValue("Correlator",s);};
		outputAppender( );
	}
}

void TransferingCorrelatorStrings_2d::outputAppender()
{
}

void InputSplitter_64::operator()( const Packets_t& scenarios_65, const Packets_t& componentAssemblys_68, Packets_t& scenarios_67, Packets_t& componentAssemblys_6a)
{
#ifdef PRINT_INFO
	std::cout << "InputSplitter_64" << std::endl;
#endif
	_scenario_6b= &scenarios_67;
	_componentAssembly_6c= &componentAssemblys_6a;
	processInputPackets( scenarios_65, componentAssemblys_68);
	forwardInputs( );
}

bool InputSplitter_64::isInputUnique( const Udm::Object& scenario_71, const Udm::Object& componentAssembly_7a)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_73= _scenario_6d.begin(), itComponentAssembly_7c= _componentAssembly_76.begin(); itScenario_73!= _scenario_6d.end(), itComponentAssembly_7c!= _componentAssembly_76.end(); ++itScenario_73, ++itComponentAssembly_7c)
	{
		if( ( *itScenario_73== scenario_71)&& ( *itComponentAssembly_7c== componentAssembly_7a))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_6d.push_back( scenario_71);
		_componentAssembly_76.push_back( componentAssembly_7a);
	}
	return isUnique;
}

void InputSplitter_64::processInputPackets( const Packets_t& scenarios_65, const Packets_t& componentAssemblys_68)
{
	for( Packets_t::const_iterator itScenario_6e= scenarios_65.begin(), itComponentAssembly_77= componentAssemblys_68.begin(); itScenario_6e!= scenarios_65.end(), itComponentAssembly_77!= componentAssemblys_68.end(); ++itScenario_6e, ++itComponentAssembly_77)
	{
		bool isUnique= isInputUnique( *itScenario_6e, *itComponentAssembly_77);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_6e, *itComponentAssembly_77);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool InputSplitter_64::patternMatcher( const Udm::Object& scenario_6f, const Udm::Object& componentAssembly_78)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_6f.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_74= cadena_scenario::Scenario::Cast( scenario_6f);
		if( false== Uml::IsDerivedFrom( componentAssembly_78.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_7d= PICML::ComponentAssembly::Cast( componentAssembly_78);
		Match currMatch;
		currMatch.scenario_7f= scenario_74;
		currMatch.componentAssembly_80= componentAssembly_7d;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void InputSplitter_64::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.scenario_7f, currMatch.componentAssembly_80);
	}
}

void InputSplitter_64::outputAppender( const cadena_scenario::Scenario& scenario_81, const PICML::ComponentAssembly& componentAssembly_83)
{
	_scenario_6b->push_back( scenario_81);
	_componentAssembly_6c->push_back( componentAssembly_83);
}

void InputSplitter_64::forwardInputs()
{
	*_scenario_6b= _scenario_6d;
	*_componentAssembly_6c= _componentAssembly_76;
}

void MethodInvocations_85::operator()( const Packets_t& requiredRequestPorts_86, const Packets_t& scenarios_88)
{
#ifdef PRINT_INFO
	std::cout << "MethodInvocations_85" << std::endl;
#endif
	processInputPackets( requiredRequestPorts_86, scenarios_88);
}

bool MethodInvocations_85::isInputUnique( const Udm::Object& requiredRequestPort_8e, const Udm::Object& scenario_97)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRequiredRequestPort_90= _requiredRequestPort_8a.begin(), itScenario_99= _scenario_93.begin(); itRequiredRequestPort_90!= _requiredRequestPort_8a.end(), itScenario_99!= _scenario_93.end(); ++itRequiredRequestPort_90, ++itScenario_99)
	{
		if( ( *itRequiredRequestPort_90== requiredRequestPort_8e)&& ( *itScenario_99== scenario_97))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_requiredRequestPort_8a.push_back( requiredRequestPort_8e);
		_scenario_93.push_back( scenario_97);
	}
	return isUnique;
}

void MethodInvocations_85::processInputPackets( const Packets_t& requiredRequestPorts_86, const Packets_t& scenarios_88)
{
	for( Packets_t::const_iterator itRequiredRequestPort_8b= requiredRequestPorts_86.begin(), itScenario_94= scenarios_88.begin(); itRequiredRequestPort_8b!= requiredRequestPorts_86.end(), itScenario_94!= scenarios_88.end(); ++itRequiredRequestPort_8b, ++itScenario_94)
	{
		bool isUnique= isInputUnique( *itRequiredRequestPort_8b, *itScenario_94);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRequiredRequestPort_8b, *itScenario_94);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool MethodInvocations_85::patternMatcher( const Udm::Object& requiredRequestPort_8c, const Udm::Object& scenario_95)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( requiredRequestPort_8c.type(), PICML::RequiredRequestPort::meta))
			continue;
		PICML::RequiredRequestPort requiredRequestPort_91= PICML::RequiredRequestPort::Cast( requiredRequestPort_8c);
		if( false== Uml::IsDerivedFrom( scenario_95.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_9a= cadena_scenario::Scenario::Cast( scenario_95);
		set< cadena_scenario::ComponentPort> receptacles_9c= requiredRequestPort_91.cadenaPort();
		for( set< cadena_scenario::ComponentPort>::const_iterator itReceptacles_9d= receptacles_9c.begin(); itReceptacles_9d!= receptacles_9c.end(); ++itReceptacles_9d)
		{
			if( false== Uml::IsDerivedFrom( (*itReceptacles_9d).type(), cadena_scenario::Receptacle::meta))
				continue;
			cadena_scenario::Receptacle currReceptacle_9e= cadena_scenario::Receptacle::Cast( *itReceptacles_9d);
			set< PICML::Invocation> invocations_9f= requiredRequestPort_91.dstInvocation();
			for( set< PICML::Invocation>::const_iterator itInvocations_a0= invocations_9f.begin(); itInvocations_a0!= invocations_9f.end(); ++itInvocations_a0)
			{
				PICML::Invocation currInvocation_a1= *itInvocations_a0;
				PICML::ProvidedRequestPort providedRequestPort_a2= currInvocation_a1.dstInvocation_end();
				set< cadena_scenario::ComponentPort> facets_a3= providedRequestPort_a2.cadenaPort();
				for( set< cadena_scenario::ComponentPort>::const_iterator itFacets_a4= facets_a3.begin(); itFacets_a4!= facets_a3.end(); ++itFacets_a4)
				{
					if( false== Uml::IsDerivedFrom( (*itFacets_a4).type(), cadena_scenario::Facet::meta))
						continue;
					cadena_scenario::Facet currFacet_a5= cadena_scenario::Facet::Cast( *itFacets_a4);
					Match currMatch;
					currMatch.invocation_a6= currInvocation_a1;
					currMatch.facet_a7= currFacet_a5;
					currMatch.receptacle_a8= currReceptacle_9e;
					currMatch.providedRequestPort_a9= providedRequestPort_a2;
					currMatch.requiredRequestPort_aa= requiredRequestPort_91;
					currMatch.scenario_ab= scenario_9a;
					_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void MethodInvocations_85::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::FRConnection newFRConnection_ac= cadena_scenario::FRConnection::Create( currMatch.scenario_ab);
		newFRConnection_ac.receptacles_end()= currMatch.receptacle_a8;
		newFRConnection_ac.facets_end()= currMatch.facet_a7;
		outputAppender( );
	}
}

void MethodInvocations_85::outputAppender()
{
}

void SourcesToConnectors_ad::operator()( const Packets_t& eSSConnections_ae, const Packets_t& publishConnectors_b0)
{
#ifdef PRINT_INFO
	std::cout << "SourcesToConnectors_ad" << std::endl;
#endif
	processInputPackets( eSSConnections_ae, publishConnectors_b0);
}

bool SourcesToConnectors_ad::isInputUnique( const Udm::Object& eSSConnection_b6, const Udm::Object& publishConnector_bf)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itESSConnection_b8= _eSSConnection_b2.begin(), itPublishConnector_c1= _publishConnector_bb.begin(); itESSConnection_b8!= _eSSConnection_b2.end(), itPublishConnector_c1!= _publishConnector_bb.end(); ++itESSConnection_b8, ++itPublishConnector_c1)
	{
		if( ( *itESSConnection_b8== eSSConnection_b6)&& ( *itPublishConnector_c1== publishConnector_bf))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_eSSConnection_b2.push_back( eSSConnection_b6);
		_publishConnector_bb.push_back( publishConnector_bf);
	}
	return isUnique;
}

void SourcesToConnectors_ad::processInputPackets( const Packets_t& eSSConnections_ae, const Packets_t& publishConnectors_b0)
{
	for( Packets_t::const_iterator itESSConnection_b3= eSSConnections_ae.begin(), itPublishConnector_bc= publishConnectors_b0.begin(); itESSConnection_b3!= eSSConnections_ae.end(), itPublishConnector_bc!= publishConnectors_b0.end(); ++itESSConnection_b3, ++itPublishConnector_bc)
	{
		bool isUnique= isInputUnique( *itESSConnection_b3, *itPublishConnector_bc);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itESSConnection_b3, *itPublishConnector_bc);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool SourcesToConnectors_ad::patternMatcher( const Udm::Object& eSSConnection_b4, const Udm::Object& publishConnector_bd)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( eSSConnection_b4.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_b9= cadena_scenario::ESSConnection::Cast( eSSConnection_b4);
		if( false== Uml::IsDerivedFrom( publishConnector_bd.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_c2= PICML::PublishConnector::Cast( publishConnector_bd);
		set< PICML::OutEventPortPublish> outEventPortPublishs_c4= publishConnector_c2.srcOutEventPortPublish();
		for( set< PICML::OutEventPortPublish>::const_iterator itOutEventPortPublishs_c5= outEventPortPublishs_c4.begin(); itOutEventPortPublishs_c5!= outEventPortPublishs_c4.end(); ++itOutEventPortPublishs_c5)
		{
			PICML::OutEventPortPublish currOutEventPortPublish_c6= *itOutEventPortPublishs_c5;
			PICML::OutEventPort outEventPort_c7= currOutEventPortPublish_c6.srcOutEventPortPublish_end();
			set< cadena_scenario::ComponentPort> eventSources_c8= outEventPort_c7.cadenaPort();
			for( set< cadena_scenario::ComponentPort>::const_iterator itEventSources_c9= eventSources_c8.begin(); itEventSources_c9!= eventSources_c8.end(); ++itEventSources_c9)
			{
				if( false== Uml::IsDerivedFrom( (*itEventSources_c9).type(), cadena_scenario::EventSource::meta))
					continue;
				cadena_scenario::EventSource currEventSource_ca= cadena_scenario::EventSource::Cast( *itEventSources_c9);
				Match currMatch;
				currMatch.outEventPort_cb= outEventPort_c7;
				currMatch.eventSource_cc= currEventSource_ca;
				currMatch.outEventPortPublish_cd= currOutEventPortPublish_c6;
				currMatch.eSSConnection_ce= eSSConnection_b9;
				currMatch.publishConnector_cf= publishConnector_c2;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void SourcesToConnectors_ad::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.eventSource_cc.sinksConnections()+= currMatch.eSSConnection_ce;
		outputAppender( );
	}
}

void SourcesToConnectors_ad::outputAppender()
{
}

void CreatingPublishConnectors_d0::operator()( const Packets_t& scenarios_d1, const Packets_t& componentAssemblys_d5, Packets_t& eSSConnections_d3, Packets_t& publishConnectors_d4)
{
#ifdef PRINT_INFO
	std::cout << "CreatingPublishConnectors_d0" << std::endl;
#endif
	_eSSConnection_d7= &eSSConnections_d3;
	_publishConnector_d8= &publishConnectors_d4;
	processInputPackets( scenarios_d1, componentAssemblys_d5);
}

bool CreatingPublishConnectors_d0::isInputUnique( const Udm::Object& scenario_dd, const Udm::Object& componentAssembly_e6)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_df= _scenario_d9.begin(), itComponentAssembly_e8= _componentAssembly_e2.begin(); itScenario_df!= _scenario_d9.end(), itComponentAssembly_e8!= _componentAssembly_e2.end(); ++itScenario_df, ++itComponentAssembly_e8)
	{
		if( ( *itScenario_df== scenario_dd)&& ( *itComponentAssembly_e8== componentAssembly_e6))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_d9.push_back( scenario_dd);
		_componentAssembly_e2.push_back( componentAssembly_e6);
	}
	return isUnique;
}

void CreatingPublishConnectors_d0::processInputPackets( const Packets_t& scenarios_d1, const Packets_t& componentAssemblys_d5)
{
	for( Packets_t::const_iterator itScenario_da= scenarios_d1.begin(), itComponentAssembly_e3= componentAssemblys_d5.begin(); itScenario_da!= scenarios_d1.end(), itComponentAssembly_e3!= componentAssemblys_d5.end(); ++itScenario_da, ++itComponentAssembly_e3)
	{
		bool isUnique= isInputUnique( *itScenario_da, *itComponentAssembly_e3);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_da, *itComponentAssembly_e3);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool CreatingPublishConnectors_d0::patternMatcher( const Udm::Object& scenario_db, const Udm::Object& componentAssembly_e4)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_db.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_e0= cadena_scenario::Scenario::Cast( scenario_db);
		if( false== Uml::IsDerivedFrom( componentAssembly_e4.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_e9= PICML::ComponentAssembly::Cast( componentAssembly_e4);
		set< PICML::PublishConnector> publishConnectors_eb= componentAssembly_e9.PublishConnector_kind_children();
		for( set< PICML::PublishConnector>::const_iterator itPublishConnector_ec= publishConnectors_eb.begin(); itPublishConnector_ec!= publishConnectors_eb.end(); ++itPublishConnector_ec)
		{
			PICML::PublishConnector currPublishConnector_ed= *itPublishConnector_ec;
			Match currMatch;
			currMatch.scenario_ee= scenario_e0;
			currMatch.publishConnector_ef= currPublishConnector_ed;
			currMatch.componentAssembly_f0= componentAssembly_e9;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void CreatingPublishConnectors_d0::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::ESSConnection newESSConnection_f1= cadena_scenario::ESSConnection::Create( currMatch.scenario_ee);
		outputAppender( newESSConnection_f1, currMatch.publishConnector_ef);
	}
}

void CreatingPublishConnectors_d0::outputAppender( const cadena_scenario::ESSConnection& eSSConnection_f2, const PICML::PublishConnector& publishConnector_f4)
{
	_eSSConnection_d7->push_back( eSSConnection_f2);
	_publishConnector_d8->push_back( publishConnector_f4);
}

void PortFinder_f6::operator()( const Packets_t& scenarios_f7, const Packets_t& componentAssemblys_fb, Packets_t& scenarios_f9, Packets_t& ports_fa)
{
#ifdef PRINT_INFO
	std::cout << "PortFinder_f6" << std::endl;
#endif
	_scenario_fd= &scenarios_f9;
	_port_fe= &ports_fa;
	processInputPackets( scenarios_f7, componentAssemblys_fb);
}

bool PortFinder_f6::isInputUnique( const Udm::Object& scenario_103, const Udm::Object& componentAssembly_10c)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_105= _scenario_ff.begin(), itComponentAssembly_10e= _componentAssembly_108.begin(); itScenario_105!= _scenario_ff.end(), itComponentAssembly_10e!= _componentAssembly_108.end(); ++itScenario_105, ++itComponentAssembly_10e)
	{
		if( ( *itScenario_105== scenario_103)&& ( *itComponentAssembly_10e== componentAssembly_10c))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_ff.push_back( scenario_103);
		_componentAssembly_108.push_back( componentAssembly_10c);
	}
	return isUnique;
}

void PortFinder_f6::processInputPackets( const Packets_t& scenarios_f7, const Packets_t& componentAssemblys_fb)
{
	for( Packets_t::const_iterator itScenario_100= scenarios_f7.begin(), itComponentAssembly_109= componentAssemblys_fb.begin(); itScenario_100!= scenarios_f7.end(), itComponentAssembly_109!= componentAssemblys_fb.end(); ++itScenario_100, ++itComponentAssembly_109)
	{
		bool isUnique= isInputUnique( *itScenario_100, *itComponentAssembly_109);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_100, *itComponentAssembly_109);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool PortFinder_f6::patternMatcher( const Udm::Object& scenario_101, const Udm::Object& componentAssembly_10a)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_101.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_106= cadena_scenario::Scenario::Cast( scenario_101);
		if( false== Uml::IsDerivedFrom( componentAssembly_10a.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_10f= PICML::ComponentAssembly::Cast( componentAssembly_10a);
		set< PICML::ComponentDef> componentDefs_111= componentAssembly_10f.ComponentDef_kind_children();
		for( set< PICML::ComponentDef>::const_iterator itComponentDef_112= componentDefs_111.begin(); itComponentDef_112!= componentDefs_111.end(); ++itComponentDef_112)
		{
			PICML::ComponentDef currComponentDef_113= *itComponentDef_112;
			set< PICML::Port> ports_114= currComponentDef_113.Port_kind_children();
			for( set< PICML::Port>::const_iterator itPort_115= ports_114.begin(); itPort_115!= ports_114.end(); ++itPort_115)
			{
				PICML::Port currPort_116= *itPort_115;
				Match currMatch;
				currMatch.scenario_117= scenario_106;
				currMatch.port_118= currPort_116;
				currMatch.componentDef_119= currComponentDef_113;
				currMatch.componentAssembly_11a= componentAssembly_10f;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void PortFinder_f6::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.scenario_117, currMatch.port_118);
	}
}

void PortFinder_f6::outputAppender( const cadena_scenario::Scenario& scenario_11b, const PICML::Port& port_11d)
{
	_scenario_fd->push_back( scenario_11b);
	_port_fe->push_back( port_11d);
}

void Emits_11f::operator()( const Packets_t& scenarios_120, const Packets_t& outEventPorts_122)
{
#ifdef PRINT_INFO
	std::cout << "Emits_11f" << std::endl;
#endif
	processInputPackets( scenarios_120, outEventPorts_122);
}

bool Emits_11f::isInputUnique( const Udm::Object& scenario_128, const Udm::Object& outEventPort_131)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_12a= _scenario_124.begin(), itOutEventPort_133= _outEventPort_12d.begin(); itScenario_12a!= _scenario_124.end(), itOutEventPort_133!= _outEventPort_12d.end(); ++itScenario_12a, ++itOutEventPort_133)
	{
		if( ( *itScenario_12a== scenario_128)&& ( *itOutEventPort_133== outEventPort_131))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_124.push_back( scenario_128);
		_outEventPort_12d.push_back( outEventPort_131);
	}
	return isUnique;
}

void Emits_11f::processInputPackets( const Packets_t& scenarios_120, const Packets_t& outEventPorts_122)
{
	for( Packets_t::const_iterator itScenario_125= scenarios_120.begin(), itOutEventPort_12e= outEventPorts_122.begin(); itScenario_125!= scenarios_120.end(), itOutEventPort_12e!= outEventPorts_122.end(); ++itScenario_125, ++itOutEventPort_12e)
	{
		bool isUnique= isInputUnique( *itScenario_125, *itOutEventPort_12e);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_125, *itOutEventPort_12e);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Emits_11f::patternMatcher( const Udm::Object& scenario_126, const Udm::Object& outEventPort_12f)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_126.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_12b= cadena_scenario::Scenario::Cast( scenario_126);
		if( false== Uml::IsDerivedFrom( outEventPort_12f.type(), PICML::OutEventPort::meta))
			continue;
		PICML::OutEventPort outEventPort_134= PICML::OutEventPort::Cast( outEventPort_12f);
		set< cadena_scenario::ComponentPort> eventSources_136= outEventPort_134.cadenaPort();
		for( set< cadena_scenario::ComponentPort>::const_iterator itEventSources_137= eventSources_136.begin(); itEventSources_137!= eventSources_136.end(); ++itEventSources_137)
		{
			if( false== Uml::IsDerivedFrom( (*itEventSources_137).type(), cadena_scenario::EventSource::meta))
				continue;
			cadena_scenario::EventSource currEventSource_138= cadena_scenario::EventSource::Cast( *itEventSources_137);
			PICML::EmitConnector emitConnector_139= outEventPort_134.dstEmitConnector();
			if( !emitConnector_139)
				continue;
			PICML::InEventPort inEventPort_13a= emitConnector_139.dstEmitConnector_end();
			set< cadena_scenario::ComponentPort> eventSinks_13b= inEventPort_13a.cadenaPort();
			for( set< cadena_scenario::ComponentPort>::const_iterator itEventSinks_13c= eventSinks_13b.begin(); itEventSinks_13c!= eventSinks_13b.end(); ++itEventSinks_13c)
			{
				if( false== Uml::IsDerivedFrom( (*itEventSinks_13c).type(), cadena_scenario::EventSink::meta))
					continue;
				cadena_scenario::EventSink currEventSink_13d= cadena_scenario::EventSink::Cast( *itEventSinks_13c);
				Match currMatch;
				currMatch.eventSink_13e= currEventSink_13d;
				currMatch.emitConnector_13f= emitConnector_139;
				currMatch.eventSource_140= currEventSource_138;
				currMatch.inEventPort_141= inEventPort_13a;
				currMatch.scenario_142= scenario_12b;
				currMatch.outEventPort_143= outEventPort_134;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void Emits_11f::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::ESSConnection newESSConnection_144= cadena_scenario::ESSConnection::Create( currMatch.scenario_142);
		newESSConnection_144.sinks()+= currMatch.eventSink_13e;
		currMatch.eventSource_140.sinksConnections()+= newESSConnection_144;
		outputAppender( );
	}
}

void Emits_11f::outputAppender()
{
}

void RootFinder_15d::operator()( const Packets_t& rootFolders_15e, const Packets_t& scenarios_160, Packets_t& scenarios_162, Packets_t& componentAssemblys_163)
{
#ifdef PRINT_INFO
	std::cout << "RootFinder_15d" << std::endl;
#endif
	_scenario_164= &scenarios_162;
	_componentAssembly_165= &componentAssemblys_163;
	processInputPackets( rootFolders_15e, scenarios_160);
}

bool RootFinder_15d::isInputUnique( const Udm::Object& rootFolder_16a, const Udm::Object& scenario_173)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRootFolder_16c= _rootFolder_166.begin(), itScenario_175= _scenario_16f.begin(); itRootFolder_16c!= _rootFolder_166.end(), itScenario_175!= _scenario_16f.end(); ++itRootFolder_16c, ++itScenario_175)
	{
		if( ( *itRootFolder_16c== rootFolder_16a)&& ( *itScenario_175== scenario_173))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_rootFolder_166.push_back( rootFolder_16a);
		_scenario_16f.push_back( scenario_173);
	}
	return isUnique;
}

void RootFinder_15d::processInputPackets( const Packets_t& rootFolders_15e, const Packets_t& scenarios_160)
{
	for( Packets_t::const_iterator itRootFolder_167= rootFolders_15e.begin(), itScenario_170= scenarios_160.begin(); itRootFolder_167!= rootFolders_15e.end(), itScenario_170!= scenarios_160.end(); ++itRootFolder_167, ++itScenario_170)
	{
		bool isUnique= isInputUnique( *itRootFolder_167, *itScenario_170);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRootFolder_167, *itScenario_170);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool RootFinder_15d::patternMatcher( const Udm::Object& rootFolder_168, const Udm::Object& scenario_171)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( rootFolder_168.type(), PICML::RootFolder::meta))
			continue;
		PICML::RootFolder rootFolder_16d= PICML::RootFolder::Cast( rootFolder_168);
		if( false== Uml::IsDerivedFrom( scenario_171.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_176= cadena_scenario::Scenario::Cast( scenario_171);
		set< PICML::ComponentImplementations> componentImplementationss_178= rootFolder_16d.ComponentImplementations_kind_children();
		for( set< PICML::ComponentImplementations>::const_iterator itComponentImplementations_179= componentImplementationss_178.begin(); itComponentImplementations_179!= componentImplementationss_178.end(); ++itComponentImplementations_179)
		{
			PICML::ComponentImplementations currComponentImplementations_17a= *itComponentImplementations_179;
			set< PICML::ComponentImplementationContainer> componentImplementationContainers_17b= currComponentImplementations_17a.ComponentImplementationContainer_kind_children();
			for( set< PICML::ComponentImplementationContainer>::const_iterator itComponentImplementationContainer_17c= componentImplementationContainers_17b.begin(); itComponentImplementationContainer_17c!= componentImplementationContainers_17b.end(); ++itComponentImplementationContainer_17c)
			{
				PICML::ComponentImplementationContainer currComponentImplementationContainer_17d= *itComponentImplementationContainer_17c;
				set< PICML::ComponentAssembly> componentAssemblys_17e= currComponentImplementationContainer_17d.ComponentAssembly_kind_children();
				for( set< PICML::ComponentAssembly>::const_iterator itComponentAssembly_17f= componentAssemblys_17e.begin(); itComponentAssembly_17f!= componentAssemblys_17e.end(); ++itComponentAssembly_17f)
				{
					PICML::ComponentAssembly currComponentAssembly_180= *itComponentAssembly_17f;
					Match currMatch;
					currMatch.rootFolder_181= rootFolder_16d;
					currMatch.scenario_182= scenario_176;
					currMatch.componentImplementations_183= currComponentImplementations_17a;
					currMatch.componentImplementationContainer_184= currComponentImplementationContainer_17d;
					currMatch.componentAssembly_185= currComponentAssembly_180;
					_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void RootFinder_15d::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.scenario_182, currMatch.componentAssembly_185);
	}
}

void RootFinder_15d::outputAppender( const cadena_scenario::Scenario& scenario_186, const PICML::ComponentAssembly& componentAssembly_188)
{
	_scenario_164->push_back( scenario_186);
	_componentAssembly_165->push_back( componentAssembly_188);
}

void ComponentCreation_18a::operator()( const Packets_t& pICML_Assembly_Ins_18b, const Packets_t& cadena_Scenario_Ins_18d, Packets_t& cadena_Scenario_Outs_18f, Packets_t& pICML_Assembly_Outs_190)
{
#ifdef PRINT_INFO
	std::cout << "ComponentCreation_18a" << std::endl;
#endif
	_cadena_Scenario_Out_191= &cadena_Scenario_Outs_18f;
	_pICML_Assembly_Out_192= &pICML_Assembly_Outs_190;
	_pICML_Assembly_Out_192->insert( _pICML_Assembly_Out_192->end(), pICML_Assembly_Ins_18b.begin(), pICML_Assembly_Ins_18b.end());
	_cadena_Scenario_Out_191->insert( _cadena_Scenario_Out_191->end(), cadena_Scenario_Ins_18d.begin(), cadena_Scenario_Ins_18d.end());
	if( ( !pICML_Assembly_Ins_18b.empty())&& ( !cadena_Scenario_Ins_18d.empty()))
		callComponentCreation_289( pICML_Assembly_Ins_18b, cadena_Scenario_Ins_18d);
}

void ComponentCreation_18a::callComponentCreation_289( const Packets_t& componentAssemblys_194, const Packets_t& scenarios_198)
{
	Packets_t componentDefs_196;
	Packets_t componentInstances_197;
	ComponentCreation_193 componentCreation_193;
	componentCreation_193( componentAssemblys_194, scenarios_198, componentDefs_196, componentInstances_197);
	if( ( !componentDefs_196.empty())&& ( !componentInstances_197.empty()))
		callPortsCreation_28c( componentDefs_196, componentInstances_197);
}

void ComponentCreation_18a::callPortsCreation_28c( const Packets_t& pICML_Components_1ba, const Packets_t& cadena_Components_1bc)
{
	PortsCreation_1b9 portsCreation_1b9;
	portsCreation_1b9( pICML_Components_1ba, cadena_Components_1bc);
}

void ComponentCreation_193::operator()( const Packets_t& componentAssemblys_194, const Packets_t& scenarios_198, Packets_t& componentDefs_196, Packets_t& componentInstances_197)
{
#ifdef PRINT_INFO
	std::cout << "ComponentCreation_193" << std::endl;
#endif
	_componentDef_19a= &componentDefs_196;
	_componentInstance_19b= &componentInstances_197;
	processInputPackets( componentAssemblys_194, scenarios_198);
}

bool ComponentCreation_193::isInputUnique( const Udm::Object& componentAssembly_1a0, const Udm::Object& scenario_1a9)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_1a2= _componentAssembly_19c.begin(), itScenario_1ab= _scenario_1a5.begin(); itComponentAssembly_1a2!= _componentAssembly_19c.end(), itScenario_1ab!= _scenario_1a5.end(); ++itComponentAssembly_1a2, ++itScenario_1ab)
	{
		if( ( *itComponentAssembly_1a2== componentAssembly_1a0)&& ( *itScenario_1ab== scenario_1a9))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentAssembly_19c.push_back( componentAssembly_1a0);
		_scenario_1a5.push_back( scenario_1a9);
	}
	return isUnique;
}

void ComponentCreation_193::processInputPackets( const Packets_t& componentAssemblys_194, const Packets_t& scenarios_198)
{
	for( Packets_t::const_iterator itComponentAssembly_19d= componentAssemblys_194.begin(), itScenario_1a6= scenarios_198.begin(); itComponentAssembly_19d!= componentAssemblys_194.end(), itScenario_1a6!= scenarios_198.end(); ++itComponentAssembly_19d, ++itScenario_1a6)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_19d, *itScenario_1a6);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_19d, *itScenario_1a6);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool ComponentCreation_193::patternMatcher( const Udm::Object& componentAssembly_19e, const Udm::Object& scenario_1a7)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_19e.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_1a3= PICML::ComponentAssembly::Cast( componentAssembly_19e);
		if( false== Uml::IsDerivedFrom( scenario_1a7.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_1ac= cadena_scenario::Scenario::Cast( scenario_1a7);
		set< PICML::ComponentDef> componentDefs_1ae= componentAssembly_1a3.ComponentDef_kind_children();
		for( set< PICML::ComponentDef>::const_iterator itComponentDef_1af= componentDefs_1ae.begin(); itComponentDef_1af!= componentDefs_1ae.end(); ++itComponentDef_1af)
		{
			PICML::ComponentDef currComponentDef_1b0= *itComponentDef_1af;
			Match currMatch;
			currMatch.componentAssembly_1b1= componentAssembly_1a3;
			currMatch.componentDef_1b2= currComponentDef_1b0;
			currMatch.scenario_1b3= scenario_1ac;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void ComponentCreation_193::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::ComponentInstance newComponentInstance_1b4= cadena_scenario::ComponentInstance::Create( currMatch.scenario_1b3);
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_1b1;
		Udm::Object& ComponentDef= currMatch.componentDef_1b2;
		Udm::Object& ComponentInstance= newComponentInstance_1b4;
		Udm::Object& Scenario= currMatch.scenario_1b3;
		{string s; ComponentDef.GetStrValue("name",s); ComponentInstance.SetStrValue("name",s);  ComponentDef.archetype().GetStrValue("name",s); ComponentInstance.SetStrValue("type",s);};
		outputAppender( currMatch.componentDef_1b2, newComponentInstance_1b4);
	}
}

void ComponentCreation_193::outputAppender( const PICML::ComponentDef& componentDef_1b5, const cadena_scenario::ComponentInstance& componentInstance_1b7)
{
	_componentDef_19a->push_back( componentDef_1b5);
	_componentInstance_19b->push_back( componentInstance_1b7);
}

void PortsCreation_1b9::operator()( const Packets_t& pICML_Components_1ba, const Packets_t& cadena_Components_1bc)
{
#ifdef PRINT_INFO
	std::cout << "PortsCreation_1b9" << std::endl;
#endif
	if( ( !cadena_Components_1bc.empty())&& ( !pICML_Components_1ba.empty()))
		callEventSources_27a( cadena_Components_1bc, pICML_Components_1ba);
}

void PortsCreation_1b9::callEventSources_27a( const Packets_t& componentInstances_255, const Packets_t& componentDefs_258)
{
	Packets_t componentInstances_257;
	Packets_t componentDefs_25a;
	EventSources_254 eventSources_254;
	eventSources_254( componentInstances_255, componentDefs_258, componentInstances_257, componentDefs_25a);
	if( ( !componentDefs_25a.empty())&& ( !componentInstances_257.empty()))
		callEventSinks_27d( componentDefs_25a, componentInstances_257);
}

void PortsCreation_1b9::callEventSinks_27d( const Packets_t& componentDefs_22f, const Packets_t& componentInstances_232)
{
	Packets_t componentDefs_231;
	Packets_t componentInstances_234;
	EventSinks_22e eventSinks_22e;
	eventSinks_22e( componentDefs_22f, componentInstances_232, componentDefs_231, componentInstances_234);
	if( ( !componentDefs_231.empty())&& ( !componentInstances_234.empty()))
		callFacets_280( componentDefs_231, componentInstances_234);
}

void PortsCreation_1b9::callFacets_280( const Packets_t& componentDefs_209, const Packets_t& componentInstances_20c)
{
	Packets_t componentDefs_20b;
	Packets_t componentInstances_20e;
	Facets_208 facets_208;
	facets_208( componentDefs_209, componentInstances_20c, componentDefs_20b, componentInstances_20e);
	if( ( !componentDefs_20b.empty())&& ( !componentInstances_20e.empty()))
		callReceptacles_283( componentDefs_20b, componentInstances_20e);
}

void PortsCreation_1b9::callReceptacles_283( const Packets_t& componentDefs_1bf, const Packets_t& componentInstances_1c2)
{
	Packets_t componentDefs_1c1;
	Packets_t componentInstances_1c4;
	Receptacles_1be receptacles_1be;
	receptacles_1be( componentDefs_1bf, componentInstances_1c2, componentDefs_1c1, componentInstances_1c4);
	if( ( !componentInstances_1c4.empty())&& ( !componentDefs_1c1.empty()))
		callAssignNames_286( componentInstances_1c4, componentDefs_1c1);
}

void PortsCreation_1b9::callAssignNames_286( const Packets_t& componentInstances_1e5, const Packets_t& componentDefs_1e7)
{
	AssignNames_1e4 assignNames_1e4;
	assignNames_1e4( componentInstances_1e5, componentDefs_1e7);
}

void Receptacles_1be::operator()( const Packets_t& componentDefs_1bf, const Packets_t& componentInstances_1c2, Packets_t& componentDefs_1c1, Packets_t& componentInstances_1c4)
{
#ifdef PRINT_INFO
	std::cout << "Receptacles_1be" << std::endl;
#endif
	_componentDef_1c5= &componentDefs_1c1;
	_componentInstance_1c6= &componentInstances_1c4;
	processInputPackets( componentDefs_1bf, componentInstances_1c2);
	forwardInputs( );
}

bool Receptacles_1be::isInputUnique( const Udm::Object& componentDef_1cb, const Udm::Object& componentInstance_1d4)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentDef_1cd= _componentDef_1c7.begin(), itComponentInstance_1d6= _componentInstance_1d0.begin(); itComponentDef_1cd!= _componentDef_1c7.end(), itComponentInstance_1d6!= _componentInstance_1d0.end(); ++itComponentDef_1cd, ++itComponentInstance_1d6)
	{
		if( ( *itComponentDef_1cd== componentDef_1cb)&& ( *itComponentInstance_1d6== componentInstance_1d4))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentDef_1c7.push_back( componentDef_1cb);
		_componentInstance_1d0.push_back( componentInstance_1d4);
	}
	return isUnique;
}

void Receptacles_1be::processInputPackets( const Packets_t& componentDefs_1bf, const Packets_t& componentInstances_1c2)
{
	for( Packets_t::const_iterator itComponentDef_1c8= componentDefs_1bf.begin(), itComponentInstance_1d1= componentInstances_1c2.begin(); itComponentDef_1c8!= componentDefs_1bf.end(), itComponentInstance_1d1!= componentInstances_1c2.end(); ++itComponentDef_1c8, ++itComponentInstance_1d1)
	{
		bool isUnique= isInputUnique( *itComponentDef_1c8, *itComponentInstance_1d1);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentDef_1c8, *itComponentInstance_1d1);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Receptacles_1be::patternMatcher( const Udm::Object& componentDef_1c9, const Udm::Object& componentInstance_1d2)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentDef_1c9.type(), PICML::ComponentDef::meta))
			continue;
		PICML::ComponentDef componentDef_1ce= PICML::ComponentDef::Cast( componentDef_1c9);
		if( false== Uml::IsDerivedFrom( componentInstance_1d2.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_1d7= cadena_scenario::ComponentInstance::Cast( componentInstance_1d2);
		set< PICML::RequiredRequestPort> requiredRequestPorts_1d9= componentDef_1ce.RequiredRequestPort_kind_children();
		for( set< PICML::RequiredRequestPort>::const_iterator itRequiredRequestPort_1da= requiredRequestPorts_1d9.begin(); itRequiredRequestPort_1da!= requiredRequestPorts_1d9.end(); ++itRequiredRequestPort_1da)
		{
			PICML::RequiredRequestPort currRequiredRequestPort_1db= *itRequiredRequestPort_1da;
			Match currMatch;
			currMatch.requiredRequestPort_1dc= currRequiredRequestPort_1db;
			currMatch.componentDef_1dd= componentDef_1ce;
			currMatch.componentInstance_1de= componentInstance_1d7;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Receptacles_1be::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::Receptacle newReceptacle_1df= cadena_scenario::Receptacle::Create( currMatch.componentInstance_1de);
		currMatch.requiredRequestPort_1dc.cadenaPort()+= newReceptacle_1df;
		outputAppender( currMatch.componentDef_1dd, currMatch.componentInstance_1de);
	}
}

void Receptacles_1be::outputAppender( const PICML::ComponentDef& componentDef_1e0, const cadena_scenario::ComponentInstance& componentInstance_1e2)
{
	_componentDef_1c5->push_back( componentDef_1e0);
	_componentInstance_1c6->push_back( componentInstance_1e2);
}

void Receptacles_1be::forwardInputs()
{
	*_componentDef_1c5= _componentDef_1c7;
	*_componentInstance_1c6= _componentInstance_1d0;
}

void AssignNames_1e4::operator()( const Packets_t& componentInstances_1e5, const Packets_t& componentDefs_1e7)
{
#ifdef PRINT_INFO
	std::cout << "AssignNames_1e4" << std::endl;
#endif
	processInputPackets( componentInstances_1e5, componentDefs_1e7);
}

bool AssignNames_1e4::isInputUnique( const Udm::Object& componentInstance_1ed, const Udm::Object& componentDef_1f6)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentInstance_1ef= _componentInstance_1e9.begin(), itComponentDef_1f8= _componentDef_1f2.begin(); itComponentInstance_1ef!= _componentInstance_1e9.end(), itComponentDef_1f8!= _componentDef_1f2.end(); ++itComponentInstance_1ef, ++itComponentDef_1f8)
	{
		if( ( *itComponentInstance_1ef== componentInstance_1ed)&& ( *itComponentDef_1f8== componentDef_1f6))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentInstance_1e9.push_back( componentInstance_1ed);
		_componentDef_1f2.push_back( componentDef_1f6);
	}
	return isUnique;
}

void AssignNames_1e4::processInputPackets( const Packets_t& componentInstances_1e5, const Packets_t& componentDefs_1e7)
{
	for( Packets_t::const_iterator itComponentInstance_1ea= componentInstances_1e5.begin(), itComponentDef_1f3= componentDefs_1e7.begin(); itComponentInstance_1ea!= componentInstances_1e5.end(), itComponentDef_1f3!= componentDefs_1e7.end(); ++itComponentInstance_1ea, ++itComponentDef_1f3)
	{
		bool isUnique= isInputUnique( *itComponentInstance_1ea, *itComponentDef_1f3);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentInstance_1ea, *itComponentDef_1f3);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool AssignNames_1e4::patternMatcher( const Udm::Object& componentInstance_1eb, const Udm::Object& componentDef_1f4)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentInstance_1eb.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_1f0= cadena_scenario::ComponentInstance::Cast( componentInstance_1eb);
		if( false== Uml::IsDerivedFrom( componentDef_1f4.type(), PICML::ComponentDef::meta))
			continue;
		PICML::ComponentDef componentDef_1f9= PICML::ComponentDef::Cast( componentDef_1f4);
		set< PICML::Port> ports_1fb= componentDef_1f9.Port_kind_children();
		for( set< PICML::Port>::const_iterator itPort_1fc= ports_1fb.begin(); itPort_1fc!= ports_1fb.end(); ++itPort_1fc)
		{
			PICML::Port currPort_1fd= *itPort_1fc;
			set< cadena_scenario::ComponentPort> componentPorts_1fe= componentInstance_1f0.ComponentPort_kind_children();
			for( set< cadena_scenario::ComponentPort>::const_iterator itComponentPort_1ff= componentPorts_1fe.begin(); itComponentPort_1ff!= componentPorts_1fe.end(); ++itComponentPort_1ff)
			{
				cadena_scenario::ComponentPort currComponentPort_200= *itComponentPort_1ff;
				set< cadena_scenario::ComponentPort> componentPorts_201= currPort_1fd.cadenaPort();
				for( set< cadena_scenario::ComponentPort>::const_iterator itComponentPorts_202= componentPorts_201.begin(); itComponentPorts_202!= componentPorts_201.end(); ++itComponentPorts_202)
				{
					cadena_scenario::ComponentPort currComponentPort_203= *itComponentPorts_202;
					if( currComponentPort_200!= currComponentPort_203)
						continue;
					Match currMatch;
					currMatch.componentPort_204= currComponentPort_200;
					currMatch.port_205= currPort_1fd;
					currMatch.componentInstance_206= componentInstance_1f0;
					currMatch.componentDef_207= componentDef_1f9;
					_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void AssignNames_1e4::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& ComponentDef= currMatch.componentDef_207;
		Udm::Object& ComponentInstance= currMatch.componentInstance_206;
		Udm::Object& ComponentPort= currMatch.componentPort_204;
		Udm::Object& Port= currMatch.port_205;
		{string s; Port.GetStrValue("name",s); ComponentPort.SetStrValue("Name",s);};
		outputAppender( );
	}
}

void AssignNames_1e4::outputAppender()
{
}

void Facets_208::operator()( const Packets_t& componentDefs_209, const Packets_t& componentInstances_20c, Packets_t& componentDefs_20b, Packets_t& componentInstances_20e)
{
#ifdef PRINT_INFO
	std::cout << "Facets_208" << std::endl;
#endif
	_componentDef_20f= &componentDefs_20b;
	_componentInstance_210= &componentInstances_20e;
	processInputPackets( componentDefs_209, componentInstances_20c);
	forwardInputs( );
}

bool Facets_208::isInputUnique( const Udm::Object& componentDef_215, const Udm::Object& componentInstance_21e)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentDef_217= _componentDef_211.begin(), itComponentInstance_220= _componentInstance_21a.begin(); itComponentDef_217!= _componentDef_211.end(), itComponentInstance_220!= _componentInstance_21a.end(); ++itComponentDef_217, ++itComponentInstance_220)
	{
		if( ( *itComponentDef_217== componentDef_215)&& ( *itComponentInstance_220== componentInstance_21e))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentDef_211.push_back( componentDef_215);
		_componentInstance_21a.push_back( componentInstance_21e);
	}
	return isUnique;
}

void Facets_208::processInputPackets( const Packets_t& componentDefs_209, const Packets_t& componentInstances_20c)
{
	for( Packets_t::const_iterator itComponentDef_212= componentDefs_209.begin(), itComponentInstance_21b= componentInstances_20c.begin(); itComponentDef_212!= componentDefs_209.end(), itComponentInstance_21b!= componentInstances_20c.end(); ++itComponentDef_212, ++itComponentInstance_21b)
	{
		bool isUnique= isInputUnique( *itComponentDef_212, *itComponentInstance_21b);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentDef_212, *itComponentInstance_21b);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Facets_208::patternMatcher( const Udm::Object& componentDef_213, const Udm::Object& componentInstance_21c)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentDef_213.type(), PICML::ComponentDef::meta))
			continue;
		PICML::ComponentDef componentDef_218= PICML::ComponentDef::Cast( componentDef_213);
		if( false== Uml::IsDerivedFrom( componentInstance_21c.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_221= cadena_scenario::ComponentInstance::Cast( componentInstance_21c);
		set< PICML::ProvidedRequestPort> providedRequestPorts_223= componentDef_218.ProvidedRequestPort_kind_children();
		for( set< PICML::ProvidedRequestPort>::const_iterator itProvidedRequestPort_224= providedRequestPorts_223.begin(); itProvidedRequestPort_224!= providedRequestPorts_223.end(); ++itProvidedRequestPort_224)
		{
			PICML::ProvidedRequestPort currProvidedRequestPort_225= *itProvidedRequestPort_224;
			Match currMatch;
			currMatch.providedRequestPort_226= currProvidedRequestPort_225;
			currMatch.componentDef_227= componentDef_218;
			currMatch.componentInstance_228= componentInstance_221;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Facets_208::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::Facet newFacet_229= cadena_scenario::Facet::Create( currMatch.componentInstance_228);
		currMatch.providedRequestPort_226.cadenaPort()+= newFacet_229;
		outputAppender( currMatch.componentDef_227, currMatch.componentInstance_228);
	}
}

void Facets_208::outputAppender( const PICML::ComponentDef& componentDef_22a, const cadena_scenario::ComponentInstance& componentInstance_22c)
{
	_componentDef_20f->push_back( componentDef_22a);
	_componentInstance_210->push_back( componentInstance_22c);
}

void Facets_208::forwardInputs()
{
	*_componentDef_20f= _componentDef_211;
	*_componentInstance_210= _componentInstance_21a;
}

void EventSinks_22e::operator()( const Packets_t& componentDefs_22f, const Packets_t& componentInstances_232, Packets_t& componentDefs_231, Packets_t& componentInstances_234)
{
#ifdef PRINT_INFO
	std::cout << "EventSinks_22e" << std::endl;
#endif
	_componentDef_235= &componentDefs_231;
	_componentInstance_236= &componentInstances_234;
	processInputPackets( componentDefs_22f, componentInstances_232);
	forwardInputs( );
}

bool EventSinks_22e::isInputUnique( const Udm::Object& componentDef_23b, const Udm::Object& componentInstance_244)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentDef_23d= _componentDef_237.begin(), itComponentInstance_246= _componentInstance_240.begin(); itComponentDef_23d!= _componentDef_237.end(), itComponentInstance_246!= _componentInstance_240.end(); ++itComponentDef_23d, ++itComponentInstance_246)
	{
		if( ( *itComponentDef_23d== componentDef_23b)&& ( *itComponentInstance_246== componentInstance_244))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentDef_237.push_back( componentDef_23b);
		_componentInstance_240.push_back( componentInstance_244);
	}
	return isUnique;
}

void EventSinks_22e::processInputPackets( const Packets_t& componentDefs_22f, const Packets_t& componentInstances_232)
{
	for( Packets_t::const_iterator itComponentDef_238= componentDefs_22f.begin(), itComponentInstance_241= componentInstances_232.begin(); itComponentDef_238!= componentDefs_22f.end(), itComponentInstance_241!= componentInstances_232.end(); ++itComponentDef_238, ++itComponentInstance_241)
	{
		bool isUnique= isInputUnique( *itComponentDef_238, *itComponentInstance_241);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentDef_238, *itComponentInstance_241);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool EventSinks_22e::patternMatcher( const Udm::Object& componentDef_239, const Udm::Object& componentInstance_242)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentDef_239.type(), PICML::ComponentDef::meta))
			continue;
		PICML::ComponentDef componentDef_23e= PICML::ComponentDef::Cast( componentDef_239);
		if( false== Uml::IsDerivedFrom( componentInstance_242.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_247= cadena_scenario::ComponentInstance::Cast( componentInstance_242);
		set< PICML::InEventPort> inEventPorts_249= componentDef_23e.InEventPort_kind_children();
		for( set< PICML::InEventPort>::const_iterator itInEventPort_24a= inEventPorts_249.begin(); itInEventPort_24a!= inEventPorts_249.end(); ++itInEventPort_24a)
		{
			PICML::InEventPort currInEventPort_24b= *itInEventPort_24a;
			Match currMatch;
			currMatch.inEventPort_24c= currInEventPort_24b;
			currMatch.componentDef_24d= componentDef_23e;
			currMatch.componentInstance_24e= componentInstance_247;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void EventSinks_22e::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::EventSink newEventSink_24f= cadena_scenario::EventSink::Create( currMatch.componentInstance_24e);
		currMatch.inEventPort_24c.cadenaPort()+= newEventSink_24f;
		outputAppender( currMatch.componentDef_24d, currMatch.componentInstance_24e);
	}
}

void EventSinks_22e::outputAppender( const PICML::ComponentDef& componentDef_250, const cadena_scenario::ComponentInstance& componentInstance_252)
{
	_componentDef_235->push_back( componentDef_250);
	_componentInstance_236->push_back( componentInstance_252);
}

void EventSinks_22e::forwardInputs()
{
	*_componentDef_235= _componentDef_237;
	*_componentInstance_236= _componentInstance_240;
}

void EventSources_254::operator()( const Packets_t& componentInstances_255, const Packets_t& componentDefs_258, Packets_t& componentInstances_257, Packets_t& componentDefs_25a)
{
#ifdef PRINT_INFO
	std::cout << "EventSources_254" << std::endl;
#endif
	_componentInstance_25b= &componentInstances_257;
	_componentDef_25c= &componentDefs_25a;
	processInputPackets( componentInstances_255, componentDefs_258);
	forwardInputs( );
}

bool EventSources_254::isInputUnique( const Udm::Object& componentInstance_261, const Udm::Object& componentDef_26a)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentInstance_263= _componentInstance_25d.begin(), itComponentDef_26c= _componentDef_266.begin(); itComponentInstance_263!= _componentInstance_25d.end(), itComponentDef_26c!= _componentDef_266.end(); ++itComponentInstance_263, ++itComponentDef_26c)
	{
		if( ( *itComponentInstance_263== componentInstance_261)&& ( *itComponentDef_26c== componentDef_26a))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentInstance_25d.push_back( componentInstance_261);
		_componentDef_266.push_back( componentDef_26a);
	}
	return isUnique;
}

void EventSources_254::processInputPackets( const Packets_t& componentInstances_255, const Packets_t& componentDefs_258)
{
	for( Packets_t::const_iterator itComponentInstance_25e= componentInstances_255.begin(), itComponentDef_267= componentDefs_258.begin(); itComponentInstance_25e!= componentInstances_255.end(), itComponentDef_267!= componentDefs_258.end(); ++itComponentInstance_25e, ++itComponentDef_267)
	{
		bool isUnique= isInputUnique( *itComponentInstance_25e, *itComponentDef_267);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentInstance_25e, *itComponentDef_267);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool EventSources_254::patternMatcher( const Udm::Object& componentInstance_25f, const Udm::Object& componentDef_268)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentInstance_25f.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_264= cadena_scenario::ComponentInstance::Cast( componentInstance_25f);
		if( false== Uml::IsDerivedFrom( componentDef_268.type(), PICML::ComponentDef::meta))
			continue;
		PICML::ComponentDef componentDef_26d= PICML::ComponentDef::Cast( componentDef_268);
		set< PICML::OutEventPort> outEventPorts_26f= componentDef_26d.OutEventPort_kind_children();
		for( set< PICML::OutEventPort>::const_iterator itOutEventPort_270= outEventPorts_26f.begin(); itOutEventPort_270!= outEventPorts_26f.end(); ++itOutEventPort_270)
		{
			PICML::OutEventPort currOutEventPort_271= *itOutEventPort_270;
			Match currMatch;
			currMatch.componentInstance_272= componentInstance_264;
			currMatch.outEventPort_273= currOutEventPort_271;
			currMatch.componentDef_274= componentDef_26d;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void EventSources_254::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::EventSource newEventSource_275= cadena_scenario::EventSource::Create( currMatch.componentInstance_272);
		currMatch.outEventPort_273.cadenaPort()+= newEventSource_275;
		outputAppender( currMatch.componentInstance_272, currMatch.componentDef_274);
	}
}

void EventSources_254::outputAppender( const cadena_scenario::ComponentInstance& componentInstance_276, const PICML::ComponentDef& componentDef_278)
{
	_componentInstance_25b->push_back( componentInstance_276);
	_componentDef_25c->push_back( componentDef_278);
}

void EventSources_254::forwardInputs()
{
	*_componentInstance_25b= _componentInstance_25d;
	*_componentDef_25c= _componentDef_266;
}

