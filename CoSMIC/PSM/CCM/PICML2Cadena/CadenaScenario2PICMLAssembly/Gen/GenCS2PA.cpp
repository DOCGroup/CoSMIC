#include "GenCS2PA.h"
#include <UmlExt.h>
#include <UdmUtil.h>

void RootRuleBlock_0::operator()( const Packets_t& embedded_Dummy_File_Ins_1, const Packets_t& pICML_File_Ins_3, const Packets_t& cadena_File_Ins_5)
{
#ifdef PRINT_INFO
	std::cout << "RootRuleBlock_0" << std::endl;
#endif
	if( ( !embedded_Dummy_File_Ins_1.empty())&& ( !cadena_File_Ins_5.empty())&& ( !pICML_File_Ins_3.empty()))
		callAssembly_and_Scenario_Finder_9f2( embedded_Dummy_File_Ins_1, cadena_File_Ins_5, pICML_File_Ins_3);
}

void RootRuleBlock_0::callAssembly_and_Scenario_Finder_9f2( const Packets_t& rootContainers_8, const Packets_t& scenarioss_a, const Packets_t& rootFolders_d)
{
	Packets_t scenarios_c;
	Packets_t componentAssemblys_f;
	Assembly_and_Scenario_Finder_7 assembly_and_Scenario_Finder_7;
	assembly_and_Scenario_Finder_7( rootContainers_8, scenarioss_a, rootFolders_d, scenarios_c, componentAssemblys_f);
	if( ( !componentAssemblys_f.empty())&& ( !scenarios_c.empty()))
		callAssociate_Components_n_PublishConnectors_9f6( componentAssemblys_f, scenarios_c);
}

void RootRuleBlock_0::callAssociate_Components_n_PublishConnectors_9f6( const Packets_t& pAssemblys_12d, const Packets_t& cScenarios_12f)
{
	Packets_t cScenarios_131;
	Packets_t pAssemblys_132;
	Associate_Components_n_PublishConnectors_12c associate_Components_n_PublishConnectors_12c;
	associate_Components_n_PublishConnectors_12c( pAssemblys_12d, cScenarios_12f, cScenarios_131, pAssemblys_132);
	if( ( !pAssemblys_132.empty())&& ( !cScenarios_131.empty()))
		callCreateDestroy_Components_n_PublishConnectors_9f9( pAssemblys_132, cScenarios_131);
}

void RootRuleBlock_0::callCreateDestroy_Components_n_PublishConnectors_9f9( const Packets_t& pAssemblys_6f2, const Packets_t& cScenarios_6f4)
{
	Packets_t pAssemblys_6f6;
	Packets_t cScenarios_6f7;
	CreateDestroy_Components_n_PublishConnectors_6f1 createDestroy_Components_n_PublishConnectors_6f1;
	createDestroy_Components_n_PublishConnectors_6f1( pAssemblys_6f2, cScenarios_6f4, pAssemblys_6f6, cScenarios_6f7);
	if( ( !cScenarios_6f7.empty())&& ( !pAssemblys_6f6.empty()))
		callTearDown_Connections_9fc( cScenarios_6f7, pAssemblys_6f6);
}

void RootRuleBlock_0::callTearDown_Connections_9fc( const Packets_t& cScenarios_51, const Packets_t& pAssemblys_53)
{
	Packets_t cScenarios_55;
	Packets_t pAssemblys_56;
	TearDown_Connections_50 tearDown_Connections_50;
	tearDown_Connections_50( cScenarios_51, pAssemblys_53, cScenarios_55, pAssemblys_56);
	if( ( !pAssemblys_56.empty())&& ( !cScenarios_55.empty()))
		callAssociate_Ports_9ff( pAssemblys_56, cScenarios_55);
}

void RootRuleBlock_0::callAssociate_Ports_9ff( const Packets_t& pAssemblys_6a4, const Packets_t& cScenarios_6a6)
{
	Packets_t pAssemblys_6a8;
	Packets_t cScenarios_6a9;
	Associate_Ports_6a3 associate_Ports_6a3;
	associate_Ports_6a3( pAssemblys_6a4, cScenarios_6a6, pAssemblys_6a8, cScenarios_6a9);
	if( ( !pAssemblys_6a8.empty())&& ( !cScenarios_6a9.empty()))
		callReCreate_Connections_a02( pAssemblys_6a8, cScenarios_6a9);
}

void RootRuleBlock_0::callReCreate_Connections_a02( const Packets_t& pAssemblys_941, const Packets_t& cScenarios_943)
{
	Packets_t cScenarios_945;
	Packets_t pAssemblys_946;
	ReCreate_Connections_940 reCreate_Connections_940;
	reCreate_Connections_940( pAssemblys_941, cScenarios_943, cScenarios_945, pAssemblys_946);
	if( ( !cScenarios_945.empty())&& ( !pAssemblys_946.empty()))
		callAssociate_Properties_a05( cScenarios_945, pAssemblys_946);
}

void RootRuleBlock_0::callAssociate_Properties_a05( const Packets_t& cScenarios_d3, const Packets_t& pAssemblys_d5)
{
	Packets_t pAssemblys_d7;
	Packets_t cScenarios_d8;
	Associate_Properties_d2 associate_Properties_d2;
	associate_Properties_d2( cScenarios_d3, pAssemblys_d5, pAssemblys_d7, cScenarios_d8);
	if( ( !cScenarios_d8.empty())&& ( !pAssemblys_d7.empty()))
		callCreate_Destroy_UpdateValue_Properties_n_Requirements_a08( cScenarios_d8, pAssemblys_d7);
}

void RootRuleBlock_0::callCreate_Destroy_UpdateValue_Properties_n_Requirements_a08( const Packets_t& cScenarios_19c, const Packets_t& pAssemblys_19e)
{
	Packets_t pAssemblys_1a0;
	Packets_t cScenarios_1a1;
	Create_Destroy_UpdateValue_Properties_n_Requirements_19b create_Destroy_UpdateValue_Properties_n_Requirements_19b;
	create_Destroy_UpdateValue_Properties_n_Requirements_19b( cScenarios_19c, pAssemblys_19e, pAssemblys_1a0, cScenarios_1a1);
}

void Assembly_and_Scenario_Finder_7::operator()( const Packets_t& rootContainers_8, const Packets_t& scenarioss_a, const Packets_t& rootFolders_d, Packets_t& scenarios_c, Packets_t& componentAssemblys_f)
{
#ifdef PRINT_INFO
	std::cout << "Assembly_and_Scenario_Finder_7" << std::endl;
#endif
	_scenario_10= &scenarios_c;
	_componentAssembly_11= &componentAssemblys_f;
	processInputPackets( rootContainers_8, scenarioss_a, rootFolders_d);
}

bool Assembly_and_Scenario_Finder_7::isInputUnique( const Udm::Object& rootContainer_16, const Udm::Object& scenarios_1f, const Udm::Object& rootFolder_28)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRootContainer_18= _rootContainer_12.begin(), itScenarios_21= _scenarios_1b.begin(), itRootFolder_2a= _rootFolder_24.begin(); itRootContainer_18!= _rootContainer_12.end(), itScenarios_21!= _scenarios_1b.end(), itRootFolder_2a!= _rootFolder_24.end(); ++itRootContainer_18, ++itScenarios_21, ++itRootFolder_2a)
	{
		if( ( *itRootContainer_18== rootContainer_16)&& ( *itScenarios_21== scenarios_1f)&& ( *itRootFolder_2a== rootFolder_28))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_rootContainer_12.push_back( rootContainer_16);
		_scenarios_1b.push_back( scenarios_1f);
		_rootFolder_24.push_back( rootFolder_28);
	}
	return isUnique;
}

bool Assembly_and_Scenario_Finder_7::isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& Property, const Udm::Object& RootContainer, const Udm::Object& RootFolder, const Udm::Object& Scenario, const Udm::Object& Scenarios)
{
	bool Gz_guard= false;
	string ciname, cicname, caname, CadenaPropertyName, PICML_pathname;  ComponentImplementations.GetStrValue("name",ciname); if (0 == ciname.find("noexport")) return false;  ComponentImplementations.GetStrValue("name",ciname); ComponentImplementationContainer.GetStrValue("name",cicname); ComponentAssembly.GetStrValue("name",caname);  Property.GetStrValue("name", CadenaPropertyName); if (CadenaPropertyName != "PICML_pathname") return false; Property.GetStrValue("value", PICML_pathname); if (PICML_pathname != '/' + ciname + '/' + cicname + '/' + caname) return false;  return true;;
	return Gz_guard;
}

void Assembly_and_Scenario_Finder_7::processInputPackets( const Packets_t& rootContainers_8, const Packets_t& scenarioss_a, const Packets_t& rootFolders_d)
{
	for( Packets_t::const_iterator itRootContainer_13= rootContainers_8.begin(), itScenarios_1c= scenarioss_a.begin(), itRootFolder_25= rootFolders_d.begin(); itRootContainer_13!= rootContainers_8.end(), itScenarios_1c!= scenarioss_a.end(), itRootFolder_25!= rootFolders_d.end(); ++itRootContainer_13, ++itScenarios_1c, ++itRootFolder_25)
	{
		bool isUnique= isInputUnique( *itRootContainer_13, *itScenarios_1c, *itRootFolder_25);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRootContainer_13, *itScenarios_1c, *itRootFolder_25);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Assembly_and_Scenario_Finder_7::patternMatcher( const Udm::Object& rootContainer_14, const Udm::Object& scenarios_1d, const Udm::Object& rootFolder_26)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( rootContainer_14.type(), PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta))
			continue;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_19= PICMLCadena_Xchange_embedded_EIProperties::RootContainer::Cast( rootContainer_14);
		if( false== Uml::IsDerivedFrom( scenarios_1d.type(), cadena_scenario::Scenarios::meta))
			continue;
		cadena_scenario::Scenarios scenarios_22= cadena_scenario::Scenarios::Cast( scenarios_1d);
		if( false== Uml::IsDerivedFrom( rootFolder_26.type(), PICML::RootFolder::meta))
			continue;
		PICML::RootFolder rootFolder_2b= PICML::RootFolder::Cast( rootFolder_26);
		set< cadena_scenario::Scenario> scenarios_2d= scenarios_22.Scenario_kind_children();
		for( set< cadena_scenario::Scenario>::const_iterator itScenario_2e= scenarios_2d.begin(); itScenario_2e!= scenarios_2d.end(); ++itScenario_2e)
		{
			cadena_scenario::Scenario currScenario_2f= *itScenario_2e;
			set< cadena_scenario::Property> propertys_30= currScenario_2f.Property_kind_children();
			for( set< cadena_scenario::Property>::const_iterator itProperty_31= propertys_30.begin(); itProperty_31!= propertys_30.end(); ++itProperty_31)
			{
				cadena_scenario::Property currProperty_32= *itProperty_31;
				set< PICML::ComponentImplementations> componentImplementationss_33= rootFolder_2b.ComponentImplementations_kind_children();
				for( set< PICML::ComponentImplementations>::const_iterator itComponentImplementations_34= componentImplementationss_33.begin(); itComponentImplementations_34!= componentImplementationss_33.end(); ++itComponentImplementations_34)
				{
					PICML::ComponentImplementations currComponentImplementations_35= *itComponentImplementations_34;
					set< PICML::ComponentImplementationContainer> componentImplementationContainers_36= currComponentImplementations_35.ComponentImplementationContainer_kind_children();
					for( set< PICML::ComponentImplementationContainer>::const_iterator itComponentImplementationContainer_37= componentImplementationContainers_36.begin(); itComponentImplementationContainer_37!= componentImplementationContainers_36.end(); ++itComponentImplementationContainer_37)
					{
						PICML::ComponentImplementationContainer currComponentImplementationContainer_38= *itComponentImplementationContainer_37;
						set< PICML::ComponentAssembly> componentAssemblys_39= currComponentImplementationContainer_38.ComponentAssembly_kind_children();
						for( set< PICML::ComponentAssembly>::const_iterator itComponentAssembly_3a= componentAssemblys_39.begin(); itComponentAssembly_3a!= componentAssemblys_39.end(); ++itComponentAssembly_3a)
						{
							PICML::ComponentAssembly currComponentAssembly_3b= *itComponentAssembly_3a;
							Match currMatch;
							currMatch.property_3c= currProperty_32;
							currMatch.rootContainer_3d= rootContainer_19;
							currMatch.scenarios_3e= scenarios_22;
							currMatch.scenario_3f= currScenario_2f;
							currMatch.rootFolder_40= rootFolder_2b;
							currMatch.componentImplementations_41= currComponentImplementations_35;
							currMatch.componentImplementationContainer_42= currComponentImplementationContainer_38;
							currMatch.componentAssembly_43= currComponentAssembly_3b;
							bool Gz_guard= isGuardTrue( currMatch.componentAssembly_43, currMatch.componentImplementationContainer_42, currMatch.componentImplementations_41, currMatch.property_3c, currMatch.rootContainer_3d, currMatch.rootFolder_40, currMatch.scenario_3f, currMatch.scenarios_3e);
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

void Assembly_and_Scenario_Finder_7::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.componentAssembly_43.cadenaScenario()+= currMatch.scenario_3f;
		currMatch.componentAssembly_43.rootContainer()= currMatch.rootContainer_3d;
		outputAppender( currMatch.scenario_3f, currMatch.componentAssembly_43);
	}
}

void Assembly_and_Scenario_Finder_7::outputAppender( const cadena_scenario::Scenario& scenario_4c, const PICML::ComponentAssembly& componentAssembly_4e)
{
	_scenario_10->push_back( scenario_4c);
	_componentAssembly_11->push_back( componentAssembly_4e);
}

void TearDown_Connections_50::operator()( const Packets_t& cScenarios_51, const Packets_t& pAssemblys_53, Packets_t& cScenarios_55, Packets_t& pAssemblys_56)
{
#ifdef PRINT_INFO
	std::cout << "TearDown_Connections_50" << std::endl;
#endif
	_cScenario_57= &cScenarios_55;
	_pAssembly_58= &pAssemblys_56;
	if( ( !pAssemblys_53.empty()))
		callOptimization_FindComponents_c8( pAssemblys_53);
	_cScenario_57->insert( _cScenario_57->end(), cScenarios_51.begin(), cScenarios_51.end());
	_pAssembly_58->insert( _pAssembly_58->end(), pAssemblys_53.begin(), pAssemblys_53.end());
}

void TearDown_Connections_50::callOptimization_FindComponents_c8( const Packets_t& componentAssemblys_71)
{
	Packets_t components_73;
	Optimization_FindComponents_70 optimization_FindComponents_70;
	optimization_FindComponents_70( componentAssemblys_71, components_73);
	if( ( !components_73.empty()))
		callTD_Invokes_ca( components_73);
	if( ( !components_73.empty()))
		callTD_Emits_cc( components_73);
	if( ( !components_73.empty()))
		callTD_SrcPublish_ce( components_73);
	if( ( !components_73.empty()))
		callTD_DeliverTo_d0( components_73);
}

void TearDown_Connections_50::callTD_Invokes_ca( const Packets_t& components_9d)
{
	TD_Invokes_9c tD_Invokes_9c;
	tD_Invokes_9c( components_9d);
}

void TearDown_Connections_50::callTD_Emits_cc( const Packets_t& components_b4)
{
	TD_Emits_b3 tD_Emits_b3;
	tD_Emits_b3( components_b4);
}

void TearDown_Connections_50::callTD_SrcPublish_ce( const Packets_t& components_86)
{
	TD_SrcPublish_85 tD_SrcPublish_85;
	tD_SrcPublish_85( components_86);
}

void TearDown_Connections_50::callTD_DeliverTo_d0( const Packets_t& components_5a)
{
	TD_DeliverTo_59 tD_DeliverTo_59;
	tD_DeliverTo_59( components_5a);
}

void TD_DeliverTo_59::operator()( const Packets_t& components_5a)
{
#ifdef PRINT_INFO
	std::cout << "TD_DeliverTo_59" << std::endl;
#endif
	processInputPackets( components_5a);
}

bool TD_DeliverTo_59::isInputUnique( const Udm::Object& component_60)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponent_62= _component_5c.begin(); itComponent_62!= _component_5c.end(); ++itComponent_62)
	{
		if( ( *itComponent_62== component_60))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_component_5c.push_back( component_60);
	return isUnique;
}

void TD_DeliverTo_59::processInputPackets( const Packets_t& components_5a)
{
	for( Packets_t::const_iterator itComponent_5d= components_5a.begin(); itComponent_5d!= components_5a.end(); ++itComponent_5d)
	{
		bool isUnique= isInputUnique( *itComponent_5d);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponent_5d);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool TD_DeliverTo_59::patternMatcher( const Udm::Object& component_5e)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( component_5e.type(), PICML::Component::meta))
			continue;
		PICML::Component component_63= PICML::Component::Cast( component_5e);
		set< PICML::InEventPort> inEventPorts_65= component_63.InEventPort_kind_children();
		for( set< PICML::InEventPort>::const_iterator itInEventPort_66= inEventPorts_65.begin(); itInEventPort_66!= inEventPorts_65.end(); ++itInEventPort_66)
		{
			PICML::InEventPort currInEventPort_67= *itInEventPort_66;
			set< PICML::deliverTo> deliverTos_68= currInEventPort_67.srcdeliverTo();
			for( set< PICML::deliverTo>::const_iterator itdeliverTos_69= deliverTos_68.begin(); itdeliverTos_69!= deliverTos_68.end(); ++itdeliverTos_69)
			{
				PICML::deliverTo currdeliverTo_6a= *itdeliverTos_69;
				PICML::PublishConnector publishConnector_6b= currdeliverTo_6a.srcdeliverTo_end();
				Match currMatch;
				currMatch.deliverTo_6c= currdeliverTo_6a;
				currMatch.component_6d= component_63;
				currMatch.inEventPort_6e= currInEventPort_67;
				currMatch.publishConnector_6f= publishConnector_6b;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void TD_DeliverTo_59::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		if( currMatch.deliverTo_6c)
			currMatch.deliverTo_6c.DeleteObject();
		outputAppender( );
	}
}

void TD_DeliverTo_59::outputAppender()
{
}

void Optimization_FindComponents_70::operator()( const Packets_t& componentAssemblys_71, Packets_t& components_73)
{
#ifdef PRINT_INFO
	std::cout << "Optimization_FindComponents_70" << std::endl;
#endif
	_component_74= &components_73;
	processInputPackets( componentAssemblys_71);
}

bool Optimization_FindComponents_70::isInputUnique( const Udm::Object& componentAssembly_79)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_7b= _componentAssembly_75.begin(); itComponentAssembly_7b!= _componentAssembly_75.end(); ++itComponentAssembly_7b)
	{
		if( ( *itComponentAssembly_7b== componentAssembly_79))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_componentAssembly_75.push_back( componentAssembly_79);
	return isUnique;
}

void Optimization_FindComponents_70::processInputPackets( const Packets_t& componentAssemblys_71)
{
	for( Packets_t::const_iterator itComponentAssembly_76= componentAssemblys_71.begin(); itComponentAssembly_76!= componentAssemblys_71.end(); ++itComponentAssembly_76)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_76);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_76);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Optimization_FindComponents_70::patternMatcher( const Udm::Object& componentAssembly_77)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_77.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_7c= PICML::ComponentAssembly::Cast( componentAssembly_77);
		set< PICML::Component> components_7e= componentAssembly_7c.Component_kind_children();
		for( set< PICML::Component>::const_iterator itComponent_7f= components_7e.begin(); itComponent_7f!= components_7e.end(); ++itComponent_7f)
		{
			PICML::Component currComponent_80= *itComponent_7f;
			Match currMatch;
			currMatch.componentAssembly_81= componentAssembly_7c;
			currMatch.component_82= currComponent_80;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Optimization_FindComponents_70::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.component_82);
	}
}

void Optimization_FindComponents_70::outputAppender( const PICML::Component& component_83)
{
	_component_74->push_back( component_83);
}

void TD_SrcPublish_85::operator()( const Packets_t& components_86)
{
#ifdef PRINT_INFO
	std::cout << "TD_SrcPublish_85" << std::endl;
#endif
	processInputPackets( components_86);
}

bool TD_SrcPublish_85::isInputUnique( const Udm::Object& component_8c)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponent_8e= _component_88.begin(); itComponent_8e!= _component_88.end(); ++itComponent_8e)
	{
		if( ( *itComponent_8e== component_8c))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_component_88.push_back( component_8c);
	return isUnique;
}

void TD_SrcPublish_85::processInputPackets( const Packets_t& components_86)
{
	for( Packets_t::const_iterator itComponent_89= components_86.begin(); itComponent_89!= components_86.end(); ++itComponent_89)
	{
		bool isUnique= isInputUnique( *itComponent_89);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponent_89);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool TD_SrcPublish_85::patternMatcher( const Udm::Object& component_8a)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( component_8a.type(), PICML::Component::meta))
			continue;
		PICML::Component component_8f= PICML::Component::Cast( component_8a);
		set< PICML::OutEventPort> outEventPorts_91= component_8f.OutEventPort_kind_children();
		for( set< PICML::OutEventPort>::const_iterator itOutEventPort_92= outEventPorts_91.begin(); itOutEventPort_92!= outEventPorts_91.end(); ++itOutEventPort_92)
		{
			PICML::OutEventPort currOutEventPort_93= *itOutEventPort_92;
			set< PICML::publish> publishs_94= currOutEventPort_93.dstpublish();
			for( set< PICML::publish>::const_iterator itpublishs_95= publishs_94.begin(); itpublishs_95!= publishs_94.end(); ++itpublishs_95)
			{
				PICML::publish currpublish_96= *itpublishs_95;
				PICML::PublishConnector publishConnector_97= currpublish_96.dstpublish_end();
				Match currMatch;
				currMatch.publishConnector_98= publishConnector_97;
				currMatch.component_99= component_8f;
				currMatch.publish_9a= currpublish_96;
				currMatch.outEventPort_9b= currOutEventPort_93;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void TD_SrcPublish_85::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		if( currMatch.publish_9a)
			currMatch.publish_9a.DeleteObject();
		outputAppender( );
	}
}

void TD_SrcPublish_85::outputAppender()
{
}

void TD_Invokes_9c::operator()( const Packets_t& components_9d)
{
#ifdef PRINT_INFO
	std::cout << "TD_Invokes_9c" << std::endl;
#endif
	processInputPackets( components_9d);
}

bool TD_Invokes_9c::isInputUnique( const Udm::Object& component_a3)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponent_a5= _component_9f.begin(); itComponent_a5!= _component_9f.end(); ++itComponent_a5)
	{
		if( ( *itComponent_a5== component_a3))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_component_9f.push_back( component_a3);
	return isUnique;
}

void TD_Invokes_9c::processInputPackets( const Packets_t& components_9d)
{
	for( Packets_t::const_iterator itComponent_a0= components_9d.begin(); itComponent_a0!= components_9d.end(); ++itComponent_a0)
	{
		bool isUnique= isInputUnique( *itComponent_a0);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponent_a0);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool TD_Invokes_9c::patternMatcher( const Udm::Object& component_a1)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( component_a1.type(), PICML::Component::meta))
			continue;
		PICML::Component component_a6= PICML::Component::Cast( component_a1);
		set< PICML::RequiredRequestPort> requiredRequestPorts_a8= component_a6.RequiredRequestPort_kind_children();
		for( set< PICML::RequiredRequestPort>::const_iterator itRequiredRequestPort_a9= requiredRequestPorts_a8.begin(); itRequiredRequestPort_a9!= requiredRequestPorts_a8.end(); ++itRequiredRequestPort_a9)
		{
			PICML::RequiredRequestPort currRequiredRequestPort_aa= *itRequiredRequestPort_a9;
			set< PICML::invoke> invokes_ab= currRequiredRequestPort_aa.dstinvoke();
			for( set< PICML::invoke>::const_iterator itinvokes_ac= invokes_ab.begin(); itinvokes_ac!= invokes_ab.end(); ++itinvokes_ac)
			{
				PICML::invoke currinvoke_ad= *itinvokes_ac;
				PICML::ProvidedRequestPort providedRequestPort_ae= currinvoke_ad.dstinvoke_end();
				Match currMatch;
				currMatch.invoke_af= currinvoke_ad;
				currMatch.component_b0= component_a6;
				currMatch.providedRequestPort_b1= providedRequestPort_ae;
				currMatch.requiredRequestPort_b2= currRequiredRequestPort_aa;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void TD_Invokes_9c::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		if( currMatch.invoke_af)
			currMatch.invoke_af.DeleteObject();
		outputAppender( );
	}
}

void TD_Invokes_9c::outputAppender()
{
}

void TD_Emits_b3::operator()( const Packets_t& components_b4)
{
#ifdef PRINT_INFO
	std::cout << "TD_Emits_b3" << std::endl;
#endif
	processInputPackets( components_b4);
}

bool TD_Emits_b3::isInputUnique( const Udm::Object& component_ba)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponent_bc= _component_b6.begin(); itComponent_bc!= _component_b6.end(); ++itComponent_bc)
	{
		if( ( *itComponent_bc== component_ba))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_component_b6.push_back( component_ba);
	return isUnique;
}

void TD_Emits_b3::processInputPackets( const Packets_t& components_b4)
{
	for( Packets_t::const_iterator itComponent_b7= components_b4.begin(); itComponent_b7!= components_b4.end(); ++itComponent_b7)
	{
		bool isUnique= isInputUnique( *itComponent_b7);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponent_b7);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool TD_Emits_b3::patternMatcher( const Udm::Object& component_b8)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( component_b8.type(), PICML::Component::meta))
			continue;
		PICML::Component component_bd= PICML::Component::Cast( component_b8);
		set< PICML::OutEventPort> outEventPorts_bf= component_bd.OutEventPort_kind_children();
		for( set< PICML::OutEventPort>::const_iterator itOutEventPort_c0= outEventPorts_bf.begin(); itOutEventPort_c0!= outEventPorts_bf.end(); ++itOutEventPort_c0)
		{
			PICML::OutEventPort currOutEventPort_c1= *itOutEventPort_c0;
			PICML::emit emit_c2= currOutEventPort_c1.dstemit();
			if( !emit_c2)
				continue;
			PICML::InEventPort inEventPort_c3= emit_c2.dstemit_end();
			Match currMatch;
			currMatch.inEventPort_c4= inEventPort_c3;
			currMatch.component_c5= component_bd;
			currMatch.outEventPort_c6= currOutEventPort_c1;
			currMatch.emit_c7= emit_c2;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void TD_Emits_b3::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		if( currMatch.emit_c7)
			currMatch.emit_c7.DeleteObject();
		outputAppender( );
	}
}

void TD_Emits_b3::outputAppender()
{
}

void Associate_Properties_d2::operator()( const Packets_t& cScenarios_d3, const Packets_t& pAssemblys_d5, Packets_t& pAssemblys_d7, Packets_t& cScenarios_d8)
{
#ifdef PRINT_INFO
	std::cout << "Associate_Properties_d2" << std::endl;
#endif
	_pAssembly_d9= &pAssemblys_d7;
	_cScenario_da= &cScenarios_d8;
	if( ( !cScenarios_d3.empty()))
		callAssociate_ComponentProperties_128( cScenarios_d3);
	if( ( !cScenarios_d3.empty()))
		callAssociate_CadenaProperties_on_PublishConnectors_12a( cScenarios_d3);
	_cScenario_da->insert( _cScenario_da->end(), cScenarios_d3.begin(), cScenarios_d3.end());
	_pAssembly_d9->insert( _pAssembly_d9->end(), pAssemblys_d5.begin(), pAssemblys_d5.end());
}

void Associate_Properties_d2::callAssociate_ComponentProperties_128( const Packets_t& scenarios_dc)
{
	Associate_ComponentProperties_db associate_ComponentProperties_db;
	associate_ComponentProperties_db( scenarios_dc);
}

void Associate_Properties_d2::callAssociate_CadenaProperties_on_PublishConnectors_12a( const Packets_t& scenarios_ff)
{
	Associate_CadenaProperties_on_PublishConnectors_fe associate_CadenaProperties_on_PublishConnectors_fe;
	associate_CadenaProperties_on_PublishConnectors_fe( scenarios_ff);
}

void Associate_ComponentProperties_db::operator()( const Packets_t& scenarios_dc)
{
#ifdef PRINT_INFO
	std::cout << "Associate_ComponentProperties_db" << std::endl;
#endif
	processInputPackets( scenarios_dc);
}

bool Associate_ComponentProperties_db::isInputUnique( const Udm::Object& scenario_e2)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_e4= _scenario_de.begin(); itScenario_e4!= _scenario_de.end(); ++itScenario_e4)
	{
		if( ( *itScenario_e4== scenario_e2))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_de.push_back( scenario_e2);
	return isUnique;
}

bool Associate_ComponentProperties_db::isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& CProperty, const Udm::Object& Component, const Udm::Object& ComponentInstance, const Udm::Object& PProperty, const Udm::Object& Scenario)
{
	bool Gz_guard= false;
	string pName, cName; PProperty.GetStrValue("name", pName); CProperty.GetStrValue("name", cName); return (pName==cName);;
	return Gz_guard;
}

void Associate_ComponentProperties_db::processInputPackets( const Packets_t& scenarios_dc)
{
	for( Packets_t::const_iterator itScenario_df= scenarios_dc.begin(); itScenario_df!= scenarios_dc.end(); ++itScenario_df)
	{
		bool isUnique= isInputUnique( *itScenario_df);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_df);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Associate_ComponentProperties_db::patternMatcher( const Udm::Object& scenario_e0)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_e0.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_e5= cadena_scenario::Scenario::Cast( scenario_e0);
		set< cadena_scenario::ComponentInstance> componentInstances_e7= scenario_e5.ComponentInstance_kind_children();
		for( set< cadena_scenario::ComponentInstance>::const_iterator itComponentInstance_e8= componentInstances_e7.begin(); itComponentInstance_e8!= componentInstances_e7.end(); ++itComponentInstance_e8)
		{
			cadena_scenario::ComponentInstance currComponentInstance_e9= *itComponentInstance_e8;
			set< cadena_scenario::Property> cPropertys_ea= currComponentInstance_e9.Property_kind_children();
			for( set< cadena_scenario::Property>::const_iterator itCProperty_eb= cPropertys_ea.begin(); itCProperty_eb!= cPropertys_ea.end(); ++itCProperty_eb)
			{
				cadena_scenario::Property currCProperty_ec= *itCProperty_eb;
				PICML::Component component_ed= currComponentInstance_e9.picmlComponentDef();
				if( !component_ed)
					continue;
				set< PICML::AssemblyConfigProperty> assemblyConfigPropertys_ee= component_ed.dstAssemblyConfigProperty();
				for( set< PICML::AssemblyConfigProperty>::const_iterator itAssemblyConfigPropertys_ef= assemblyConfigPropertys_ee.begin(); itAssemblyConfigPropertys_ef!= assemblyConfigPropertys_ee.end(); ++itAssemblyConfigPropertys_ef)
				{
					PICML::AssemblyConfigProperty currAssemblyConfigProperty_f0= *itAssemblyConfigPropertys_ef;
					PICML::Property pProperty_f1= currAssemblyConfigProperty_f0.dstAssemblyConfigProperty_end();
					Match currMatch;
					currMatch.assemblyConfigProperty_f2= currAssemblyConfigProperty_f0;
					currMatch.pProperty_f3= pProperty_f1;
					currMatch.component_f4= component_ed;
					currMatch.cProperty_f5= currCProperty_ec;
					currMatch.componentInstance_f6= currComponentInstance_e9;
					currMatch.scenario_f7= scenario_e5;
					bool Gz_guard= isGuardTrue( currMatch.assemblyConfigProperty_f2, currMatch.cProperty_f5, currMatch.component_f4, currMatch.componentInstance_f6, currMatch.pProperty_f3, currMatch.scenario_f7);
					if( true== Gz_guard)
						_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void Associate_ComponentProperties_db::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.pProperty_f3.cadenaProperty()= currMatch.cProperty_f5;
		outputAppender( );
	}
}

void Associate_ComponentProperties_db::outputAppender()
{
}

void Associate_CadenaProperties_on_PublishConnectors_fe::operator()( const Packets_t& scenarios_ff)
{
#ifdef PRINT_INFO
	std::cout << "Associate_CadenaProperties_on_PublishConnectors_fe" << std::endl;
#endif
	processInputPackets( scenarios_ff);
}

bool Associate_CadenaProperties_on_PublishConnectors_fe::isInputUnique( const Udm::Object& scenario_105)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_107= _scenario_101.begin(); itScenario_107!= _scenario_101.end(); ++itScenario_107)
	{
		if( ( *itScenario_107== scenario_105))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_101.push_back( scenario_105);
	return isUnique;
}

bool Associate_CadenaProperties_on_PublishConnectors_fe::isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& CProperty, const Udm::Object& ESSConnection, const Udm::Object& PProperty, const Udm::Object& PublishConnector, const Udm::Object& Requirement, const Udm::Object& Scenario)
{
	bool Gz_guard= false;
	string pReqName, pPropName, cPropName;  Requirement.GetStrValue("name", pReqName); if (pReqName!="CadenaProperties") return false;  PProperty.GetStrValue("name", pPropName); CProperty.GetStrValue("name", cPropName); if (pPropName!=cPropName) return false; else return true;;
	return Gz_guard;
}

void Associate_CadenaProperties_on_PublishConnectors_fe::processInputPackets( const Packets_t& scenarios_ff)
{
	for( Packets_t::const_iterator itScenario_102= scenarios_ff.begin(); itScenario_102!= scenarios_ff.end(); ++itScenario_102)
	{
		bool isUnique= isInputUnique( *itScenario_102);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_102);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Associate_CadenaProperties_on_PublishConnectors_fe::patternMatcher( const Udm::Object& scenario_103)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_103.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_108= cadena_scenario::Scenario::Cast( scenario_103);
		set< cadena_scenario::ESSConnection> eSSConnections_10a= scenario_108.ESSConnection_kind_children();
		for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnection_10b= eSSConnections_10a.begin(); itESSConnection_10b!= eSSConnections_10a.end(); ++itESSConnection_10b)
		{
			cadena_scenario::ESSConnection currESSConnection_10c= *itESSConnection_10b;
			set< cadena_scenario::Property> cPropertys_10d= currESSConnection_10c.Property_kind_children();
			for( set< cadena_scenario::Property>::const_iterator itCProperty_10e= cPropertys_10d.begin(); itCProperty_10e!= cPropertys_10d.end(); ++itCProperty_10e)
			{
				cadena_scenario::Property currCProperty_10f= *itCProperty_10e;
				set< PICML::PublishConnector> publishConnectors_110= currESSConnection_10c.picmlPublishConnector();
				for( set< PICML::PublishConnector>::const_iterator itPublishConnectors_111= publishConnectors_110.begin(); itPublishConnectors_111!= publishConnectors_110.end(); ++itPublishConnectors_111)
				{
					PICML::PublishConnector currPublishConnector_112= *itPublishConnectors_111;
					set< PICML::AssemblyDeployRequirement> assemblyDeployRequirements_113= currPublishConnector_112.dstAssemblyDeployRequirement();
					for( set< PICML::AssemblyDeployRequirement>::const_iterator itAssemblyDeployRequirements_114= assemblyDeployRequirements_113.begin(); itAssemblyDeployRequirements_114!= assemblyDeployRequirements_113.end(); ++itAssemblyDeployRequirements_114)
					{
						PICML::AssemblyDeployRequirement currAssemblyDeployRequirement_115= *itAssemblyDeployRequirements_114;
						PICML::Requirement requirement_116= currAssemblyDeployRequirement_115.dstAssemblyDeployRequirement_end();
						set< PICML::Property> pPropertys_117= requirement_116.Property_kind_children();
						for( set< PICML::Property>::const_iterator itPProperty_118= pPropertys_117.begin(); itPProperty_118!= pPropertys_117.end(); ++itPProperty_118)
						{
							PICML::Property currPProperty_119= *itPProperty_118;
							Match currMatch;
							currMatch.assemblyDeployRequirement_11a= currAssemblyDeployRequirement_115;
							currMatch.requirement_11b= requirement_116;
							currMatch.publishConnector_11c= currPublishConnector_112;
							currMatch.eSSConnection_11d= currESSConnection_10c;
							currMatch.pProperty_11e= currPProperty_119;
							currMatch.scenario_11f= scenario_108;
							currMatch.cProperty_120= currCProperty_10f;
							bool Gz_guard= isGuardTrue( currMatch.assemblyDeployRequirement_11a, currMatch.cProperty_120, currMatch.eSSConnection_11d, currMatch.pProperty_11e, currMatch.publishConnector_11c, currMatch.requirement_11b, currMatch.scenario_11f);
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

void Associate_CadenaProperties_on_PublishConnectors_fe::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.pProperty_11e.cadenaProperty()= currMatch.cProperty_120;
		outputAppender( );
	}
}

void Associate_CadenaProperties_on_PublishConnectors_fe::outputAppender()
{
}

void Associate_Components_n_PublishConnectors_12c::operator()( const Packets_t& pAssemblys_12d, const Packets_t& cScenarios_12f, Packets_t& cScenarios_131, Packets_t& pAssemblys_132)
{
#ifdef PRINT_INFO
	std::cout << "Associate_Components_n_PublishConnectors_12c" << std::endl;
#endif
	_cScenario_133= &cScenarios_131;
	_pAssembly_134= &pAssemblys_132;
	if( ( !cScenarios_12f.empty())&& ( !pAssemblys_12d.empty()))
		callAssociateComponents_195( cScenarios_12f, pAssemblys_12d);
	if( ( !pAssemblys_12d.empty())&& ( !cScenarios_12f.empty()))
		callAssociatePublishConnectors_198( pAssemblys_12d, cScenarios_12f);
	_pAssembly_134->insert( _pAssembly_134->end(), pAssemblys_12d.begin(), pAssemblys_12d.end());
	_cScenario_133->insert( _cScenario_133->end(), cScenarios_12f.begin(), cScenarios_12f.end());
}

void Associate_Components_n_PublishConnectors_12c::callAssociateComponents_195( const Packets_t& scenarios_136, const Packets_t& componentAssemblys_138)
{
	AssociateComponents_135 associateComponents_135;
	associateComponents_135( scenarios_136, componentAssemblys_138);
}

void Associate_Components_n_PublishConnectors_12c::callAssociatePublishConnectors_198( const Packets_t& componentAssemblys_15b, const Packets_t& scenarios_15d)
{
	AssociatePublishConnectors_15a associatePublishConnectors_15a;
	associatePublishConnectors_15a( componentAssemblys_15b, scenarios_15d);
}

void AssociateComponents_135::operator()( const Packets_t& scenarios_136, const Packets_t& componentAssemblys_138)
{
#ifdef PRINT_INFO
	std::cout << "AssociateComponents_135" << std::endl;
#endif
	processInputPackets( scenarios_136, componentAssemblys_138);
}

bool AssociateComponents_135::isInputUnique( const Udm::Object& scenario_13e, const Udm::Object& componentAssembly_147)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_140= _scenario_13a.begin(), itComponentAssembly_149= _componentAssembly_143.begin(); itScenario_140!= _scenario_13a.end(), itComponentAssembly_149!= _componentAssembly_143.end(); ++itScenario_140, ++itComponentAssembly_149)
	{
		if( ( *itScenario_140== scenario_13e)&& ( *itComponentAssembly_149== componentAssembly_147))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_13a.push_back( scenario_13e);
		_componentAssembly_143.push_back( componentAssembly_147);
	}
	return isUnique;
}

bool AssociateComponents_135::isGuardTrue( const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentInstance, const Udm::Object& Scenario)
{
	bool Gz_guard= false;
	string pType, cType, pName, cName;  Component.archetype().GetStrValue("name", pType); Component.GetStrValue("name", pName); ComponentInstance.GetStrValue("type", cType); ComponentInstance.GetStrValue("name", cName);  if (pType==cType && pName==cName) return true; else return false;;
	return Gz_guard;
}

void AssociateComponents_135::processInputPackets( const Packets_t& scenarios_136, const Packets_t& componentAssemblys_138)
{
	for( Packets_t::const_iterator itScenario_13b= scenarios_136.begin(), itComponentAssembly_144= componentAssemblys_138.begin(); itScenario_13b!= scenarios_136.end(), itComponentAssembly_144!= componentAssemblys_138.end(); ++itScenario_13b, ++itComponentAssembly_144)
	{
		bool isUnique= isInputUnique( *itScenario_13b, *itComponentAssembly_144);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_13b, *itComponentAssembly_144);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool AssociateComponents_135::patternMatcher( const Udm::Object& scenario_13c, const Udm::Object& componentAssembly_145)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_13c.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_141= cadena_scenario::Scenario::Cast( scenario_13c);
		if( false== Uml::IsDerivedFrom( componentAssembly_145.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_14a= PICML::ComponentAssembly::Cast( componentAssembly_145);
		set< PICML::Component> components_14c= componentAssembly_14a.Component_kind_children();
		for( set< PICML::Component>::const_iterator itComponent_14d= components_14c.begin(); itComponent_14d!= components_14c.end(); ++itComponent_14d)
		{
			PICML::Component currComponent_14e= *itComponent_14d;
			set< cadena_scenario::ComponentInstance> componentInstances_14f= scenario_141.ComponentInstance_kind_children();
			for( set< cadena_scenario::ComponentInstance>::const_iterator itComponentInstance_150= componentInstances_14f.begin(); itComponentInstance_150!= componentInstances_14f.end(); ++itComponentInstance_150)
			{
				cadena_scenario::ComponentInstance currComponentInstance_151= *itComponentInstance_150;
				Match currMatch;
				currMatch.scenario_152= scenario_141;
				currMatch.componentInstance_153= currComponentInstance_151;
				currMatch.component_154= currComponent_14e;
				currMatch.componentAssembly_155= componentAssembly_14a;
				bool Gz_guard= isGuardTrue( currMatch.component_154, currMatch.componentAssembly_155, currMatch.componentInstance_153, currMatch.scenario_152);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void AssociateComponents_135::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.component_154.cadenaComponentInstance()= currMatch.componentInstance_153;
		outputAppender( );
	}
}

void AssociateComponents_135::outputAppender()
{
}

void AssociatePublishConnectors_15a::operator()( const Packets_t& componentAssemblys_15b, const Packets_t& scenarios_15d)
{
#ifdef PRINT_INFO
	std::cout << "AssociatePublishConnectors_15a" << std::endl;
#endif
	processInputPackets( componentAssemblys_15b, scenarios_15d);
}

bool AssociatePublishConnectors_15a::isInputUnique( const Udm::Object& componentAssembly_163, const Udm::Object& scenario_16c)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_165= _componentAssembly_15f.begin(), itScenario_16e= _scenario_168.begin(); itComponentAssembly_165!= _componentAssembly_15f.end(), itScenario_16e!= _scenario_168.end(); ++itComponentAssembly_165, ++itScenario_16e)
	{
		if( ( *itComponentAssembly_165== componentAssembly_163)&& ( *itScenario_16e== scenario_16c))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentAssembly_15f.push_back( componentAssembly_163);
		_scenario_168.push_back( scenario_16c);
	}
	return isUnique;
}

bool AssociatePublishConnectors_15a::isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& ComponentAssembly, const Udm::Object& DataType, const Udm::Object& ESSConnection, const Udm::Object& Property, const Udm::Object& PublishConnector, const Udm::Object& Requirement, const Udm::Object& Scenario, const Udm::Object& String)
{
	bool Gz_guard= false;
	string s; Requirement.GetStrValue("name", s); if (s!="ConnectorID") return false; Property.GetStrValue("name", s); if (s!="ConnectorID") return false;  string pConnectorID, cConnectorID; Property.GetStrValue("DataValue", pConnectorID); ESSConnection.GetStrValue("ConnectorID", cConnectorID);  return (cConnectorID==pConnectorID && pConnectorID!="");;
	return Gz_guard;
}

void AssociatePublishConnectors_15a::processInputPackets( const Packets_t& componentAssemblys_15b, const Packets_t& scenarios_15d)
{
	for( Packets_t::const_iterator itComponentAssembly_160= componentAssemblys_15b.begin(), itScenario_169= scenarios_15d.begin(); itComponentAssembly_160!= componentAssemblys_15b.end(), itScenario_169!= scenarios_15d.end(); ++itComponentAssembly_160, ++itScenario_169)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_160, *itScenario_169);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_160, *itScenario_169);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool AssociatePublishConnectors_15a::patternMatcher( const Udm::Object& componentAssembly_161, const Udm::Object& scenario_16a)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_161.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_166= PICML::ComponentAssembly::Cast( componentAssembly_161);
		if( false== Uml::IsDerivedFrom( scenario_16a.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_16f= cadena_scenario::Scenario::Cast( scenario_16a);
		set< cadena_scenario::ESSConnection> eSSConnections_171= scenario_16f.ESSConnection_kind_children();
		for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnection_172= eSSConnections_171.begin(); itESSConnection_172!= eSSConnections_171.end(); ++itESSConnection_172)
		{
			cadena_scenario::ESSConnection currESSConnection_173= *itESSConnection_172;
			set< PICML::PublishConnector> publishConnectors_174= componentAssembly_166.PublishConnector_kind_children();
			for( set< PICML::PublishConnector>::const_iterator itPublishConnector_175= publishConnectors_174.begin(); itPublishConnector_175!= publishConnectors_174.end(); ++itPublishConnector_175)
			{
				PICML::PublishConnector currPublishConnector_176= *itPublishConnector_175;
				set< PICML::AssemblyDeployRequirement> assemblyDeployRequirements_177= currPublishConnector_176.dstAssemblyDeployRequirement();
				for( set< PICML::AssemblyDeployRequirement>::const_iterator itAssemblyDeployRequirements_178= assemblyDeployRequirements_177.begin(); itAssemblyDeployRequirements_178!= assemblyDeployRequirements_177.end(); ++itAssemblyDeployRequirements_178)
				{
					PICML::AssemblyDeployRequirement currAssemblyDeployRequirement_179= *itAssemblyDeployRequirements_178;
					PICML::Requirement requirement_17a= currAssemblyDeployRequirement_179.dstAssemblyDeployRequirement_end();
					set< PICML::Property> propertys_17b= requirement_17a.Property_kind_children();
					for( set< PICML::Property>::const_iterator itProperty_17c= propertys_17b.begin(); itProperty_17c!= propertys_17b.end(); ++itProperty_17c)
					{
						PICML::Property currProperty_17d= *itProperty_17c;
						set< PICML::DataType> dataTypes_17e= currProperty_17d.DataType_kind_children();
						for( set< PICML::DataType>::const_iterator itDataType_17f= dataTypes_17e.begin(); itDataType_17f!= dataTypes_17e.end(); ++itDataType_17f)
						{
							PICML::DataType currDataType_180= *itDataType_17f;
							PICML::PredefinedType string_181= currDataType_180.ref();
							if( false== Uml::IsDerivedFrom( string_181.type(), PICML::String::meta))
								continue;
							PICML::String string_182= PICML::String::Cast( string_181);
							if( !string_182)
								continue;
							Match currMatch;
							currMatch.dataType_183= currDataType_180;
							currMatch.string_184= string_182;
							currMatch.property_185= currProperty_17d;
							currMatch.assemblyDeployRequirement_186= currAssemblyDeployRequirement_179;
							currMatch.requirement_187= requirement_17a;
							currMatch.eSSConnection_188= currESSConnection_173;
							currMatch.publishConnector_189= currPublishConnector_176;
							currMatch.componentAssembly_18a= componentAssembly_166;
							currMatch.scenario_18b= scenario_16f;
							bool Gz_guard= isGuardTrue( currMatch.assemblyDeployRequirement_186, currMatch.componentAssembly_18a, currMatch.dataType_183, currMatch.eSSConnection_188, currMatch.property_185, currMatch.publishConnector_189, currMatch.requirement_187, currMatch.scenario_18b, currMatch.string_184);
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

void AssociatePublishConnectors_15a::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.publishConnector_189.cadenaESSConnection()= currMatch.eSSConnection_188;
		outputAppender( );
	}
}

void AssociatePublishConnectors_15a::outputAppender()
{
}

void Create_Destroy_UpdateValue_Properties_n_Requirements_19b::operator()( const Packets_t& cScenarios_19c, const Packets_t& pAssemblys_19e, Packets_t& pAssemblys_1a0, Packets_t& cScenarios_1a1)
{
#ifdef PRINT_INFO
	std::cout << "Create_Destroy_UpdateValue_Properties_n_Requirements_19b" << std::endl;
#endif
	_pAssembly_1a2= &pAssemblys_1a0;
	_cScenario_1a3= &cScenarios_1a1;
	if( ( !pAssemblys_19e.empty())&& ( !cScenarios_19c.empty()))
		callDestroyProperties_697( pAssemblys_19e, cScenarios_19c);
	_cScenario_1a3->insert( _cScenario_1a3->end(), cScenarios_19c.begin(), cScenarios_19c.end());
	_pAssembly_1a2->insert( _pAssembly_1a2->end(), pAssemblys_19e.begin(), pAssemblys_19e.end());
}

void Create_Destroy_UpdateValue_Properties_n_Requirements_19b::callDestroyProperties_697( const Packets_t& pAssemblys_5db, const Packets_t& cScenarios_5dd)
{
	Packets_t pAssemblys_5df;
	Packets_t cScenarios_5e0;
	DestroyProperties_5da destroyProperties_5da;
	destroyProperties_5da( pAssemblys_5db, cScenarios_5dd, pAssemblys_5df, cScenarios_5e0);
	if( ( !pAssemblys_5df.empty())&& ( !cScenarios_5e0.empty()))
		callCreateNormalProperties_69a( pAssemblys_5df, cScenarios_5e0);
	if( ( !cScenarios_5e0.empty())&& ( !pAssemblys_5df.empty()))
		callCreate_and_Set_Emit_Invoke_Properties_69d( cScenarios_5e0, pAssemblys_5df);
}

void Create_Destroy_UpdateValue_Properties_n_Requirements_19b::callCreateNormalProperties_69a( const Packets_t& pAssemblys_4c2, const Packets_t& cScenarios_4c4)
{
	Packets_t pAssemblys_4c6;
	Packets_t cScenarios_4c7;
	CreateNormalProperties_4c1 createNormalProperties_4c1;
	createNormalProperties_4c1( pAssemblys_4c2, cScenarios_4c4, pAssemblys_4c6, cScenarios_4c7);
	if( ( !pAssemblys_4c6.empty())&& ( !cScenarios_4c7.empty()))
		callUpdateValue_6a0( pAssemblys_4c6, cScenarios_4c7);
}

void Create_Destroy_UpdateValue_Properties_n_Requirements_19b::callCreate_and_Set_Emit_Invoke_Properties_69d( const Packets_t& cScenarios_34e, const Packets_t& pAssemblys_350)
{
	Create_and_Set_Emit_Invoke_Properties_34d create_and_Set_Emit_Invoke_Properties_34d;
	create_and_Set_Emit_Invoke_Properties_34d( cScenarios_34e, pAssemblys_350);
}

void Create_Destroy_UpdateValue_Properties_n_Requirements_19b::callUpdateValue_6a0( const Packets_t& pAssemblys_1a5, const Packets_t& cScenarios_1a7)
{
	UpdateValue_1a4 updateValue_1a4;
	updateValue_1a4( pAssemblys_1a5, cScenarios_1a7);
}

void UpdateValue_1a4::operator()( const Packets_t& pAssemblys_1a5, const Packets_t& cScenarios_1a7)
{
#ifdef PRINT_INFO
	std::cout << "UpdateValue_1a4" << std::endl;
#endif
	if( ( !pAssemblys_1a5.empty())&& ( !cScenarios_1a7.empty()))
		callEnumeratePublishConnectorProperties_340( pAssemblys_1a5, cScenarios_1a7);
	if( ( !pAssemblys_1a5.empty())&& ( !cScenarios_1a7.empty()))
		callEnumerateComponentProperties_343( pAssemblys_1a5, cScenarios_1a7);
}

void UpdateValue_1a4::callEnumeratePublishConnectorProperties_340( const Packets_t& componentAssemblys_1ab, const Packets_t& scenarios_1ae)
{
	Packets_t propertys_1aa;
	Packets_t componentAssemblys_1ad;
	Packets_t cPropertys_1b0;
	EnumeratePublishConnectorProperties_1a9 enumeratePublishConnectorProperties_1a9;
	enumeratePublishConnectorProperties_1a9( componentAssemblys_1ab, scenarios_1ae, propertys_1aa, componentAssemblys_1ad, cPropertys_1b0);
	if( ( !cPropertys_1b0.empty())&& ( !componentAssemblys_1ad.empty())&& ( !propertys_1aa.empty()))
		callRefreshType_346( cPropertys_1b0, componentAssemblys_1ad, propertys_1aa);
}

void UpdateValue_1a4::callEnumerateComponentProperties_343( const Packets_t& componentAssemblys_2f9, const Packets_t& scenarios_2fc)
{
	Packets_t componentAssemblys_2fb;
	Packets_t propertys_2fe;
	Packets_t cPropertys_2ff;
	EnumerateComponentProperties_2f8 enumerateComponentProperties_2f8;
	enumerateComponentProperties_2f8( componentAssemblys_2f9, scenarios_2fc, componentAssemblys_2fb, propertys_2fe, cPropertys_2ff);
	if( ( !cPropertys_2ff.empty())&& ( !componentAssemblys_2fb.empty())&& ( !propertys_2fe.empty()))
		callRefreshType_346( cPropertys_2ff, componentAssemblys_2fb, propertys_2fe);
}

void UpdateValue_1a4::callRefreshType_346( const Packets_t& cPropertys_1d9, const Packets_t& pAssemblys_1db, const Packets_t& pPropertys_1dd)
{
	Packets_t pAssemblys_1df;
	Packets_t pPropertys_1e0;
	Packets_t cPropertys_1e1;
	RefreshType_1d8 refreshType_1d8;
	refreshType_1d8( cPropertys_1d9, pAssemblys_1db, pPropertys_1dd, pAssemblys_1df, pPropertys_1e0, cPropertys_1e1);
	if( ( !cPropertys_1e1.empty())&& ( !pPropertys_1e0.empty()))
		callTransferValue_34a( cPropertys_1e1, pPropertys_1e0);
}

void UpdateValue_1a4::callTransferValue_34a( const Packets_t& cPropertys_328, const Packets_t& pPropertys_32a)
{
	TransferValue_327 transferValue_327;
	transferValue_327( cPropertys_328, pPropertys_32a);
}

void EnumeratePublishConnectorProperties_1a9::operator()( const Packets_t& componentAssemblys_1ab, const Packets_t& scenarios_1ae, Packets_t& propertys_1aa, Packets_t& componentAssemblys_1ad, Packets_t& cPropertys_1b0)
{
#ifdef PRINT_INFO
	std::cout << "EnumeratePublishConnectorProperties_1a9" << std::endl;
#endif
	_property_1b1= &propertys_1aa;
	_componentAssembly_1b2= &componentAssemblys_1ad;
	_cProperty_1b3= &cPropertys_1b0;
	processInputPackets( componentAssemblys_1ab, scenarios_1ae);
}

bool EnumeratePublishConnectorProperties_1a9::isInputUnique( const Udm::Object& componentAssembly_1b8, const Udm::Object& scenario_1c1)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_1ba= _componentAssembly_1b4.begin(), itScenario_1c3= _scenario_1bd.begin(); itComponentAssembly_1ba!= _componentAssembly_1b4.end(), itScenario_1c3!= _scenario_1bd.end(); ++itComponentAssembly_1ba, ++itScenario_1c3)
	{
		if( ( *itComponentAssembly_1ba== componentAssembly_1b8)&& ( *itScenario_1c3== scenario_1c1))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentAssembly_1b4.push_back( componentAssembly_1b8);
		_scenario_1bd.push_back( scenario_1c1);
	}
	return isUnique;
}

void EnumeratePublishConnectorProperties_1a9::processInputPackets( const Packets_t& componentAssemblys_1ab, const Packets_t& scenarios_1ae)
{
	for( Packets_t::const_iterator itComponentAssembly_1b5= componentAssemblys_1ab.begin(), itScenario_1be= scenarios_1ae.begin(); itComponentAssembly_1b5!= componentAssemblys_1ab.end(), itScenario_1be!= scenarios_1ae.end(); ++itComponentAssembly_1b5, ++itScenario_1be)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_1b5, *itScenario_1be);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_1b5, *itScenario_1be);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool EnumeratePublishConnectorProperties_1a9::patternMatcher( const Udm::Object& componentAssembly_1b6, const Udm::Object& scenario_1bf)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_1b6.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_1bb= PICML::ComponentAssembly::Cast( componentAssembly_1b6);
		if( false== Uml::IsDerivedFrom( scenario_1bf.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_1c4= cadena_scenario::Scenario::Cast( scenario_1bf);
		set< cadena_scenario::ESSConnection> eSSConnections_1c6= scenario_1c4.ESSConnection_kind_children();
		for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnection_1c7= eSSConnections_1c6.begin(); itESSConnection_1c7!= eSSConnections_1c6.end(); ++itESSConnection_1c7)
		{
			cadena_scenario::ESSConnection currESSConnection_1c8= *itESSConnection_1c7;
			set< cadena_scenario::Property> cPropertys_1c9= currESSConnection_1c8.Property_kind_children();
			for( set< cadena_scenario::Property>::const_iterator itCProperty_1ca= cPropertys_1c9.begin(); itCProperty_1ca!= cPropertys_1c9.end(); ++itCProperty_1ca)
			{
				cadena_scenario::Property currCProperty_1cb= *itCProperty_1ca;
				PICML::Property property_1cc= currCProperty_1cb.picmlProperty();
				if( !property_1cc)
					continue;
				Match currMatch;
				currMatch.property_1cd= property_1cc;
				currMatch.componentAssembly_1ce= componentAssembly_1bb;
				currMatch.scenario_1cf= scenario_1c4;
				currMatch.cProperty_1d0= currCProperty_1cb;
				currMatch.eSSConnection_1d1= currESSConnection_1c8;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void EnumeratePublishConnectorProperties_1a9::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.property_1cd, currMatch.componentAssembly_1ce, currMatch.cProperty_1d0);
	}
}

void EnumeratePublishConnectorProperties_1a9::outputAppender( const PICML::Property& property_1d2, const PICML::ComponentAssembly& componentAssembly_1d4, const cadena_scenario::Property& cProperty_1d6)
{
	_property_1b1->push_back( property_1d2);
	_componentAssembly_1b2->push_back( componentAssembly_1d4);
	_cProperty_1b3->push_back( cProperty_1d6);
}

void RefreshType_1d8::operator()( const Packets_t& cPropertys_1d9, const Packets_t& pAssemblys_1db, const Packets_t& pPropertys_1dd, Packets_t& pAssemblys_1df, Packets_t& pPropertys_1e0, Packets_t& cPropertys_1e1)
{
#ifdef PRINT_INFO
	std::cout << "RefreshType_1d8" << std::endl;
#endif
	_pAssembly_1e2= &pAssemblys_1df;
	_pProperty_1e3= &pPropertys_1e0;
	_cProperty_1e4= &cPropertys_1e1;
	if( ( !pPropertys_1dd.empty())&& ( !pAssemblys_1db.empty())&& ( !cPropertys_1d9.empty()))
		callDeleteCurrentType_2f0( pPropertys_1dd, pAssemblys_1db, cPropertys_1d9);
}

void RefreshType_1d8::callDeleteCurrentType_2f0( const Packets_t& propertys_2bc, const Packets_t& componentAssemblys_2bf, const Packets_t& cPropertys_2c2)
{
	Packets_t propertys_2be;
	Packets_t componentAssemblys_2c1;
	Packets_t cPropertys_2c4;
	DeleteCurrentType_2bb deleteCurrentType_2bb;
	deleteCurrentType_2bb( propertys_2bc, componentAssemblys_2bf, cPropertys_2c2, propertys_2be, componentAssemblys_2c1, cPropertys_2c4);
	if( ( !cPropertys_2c4.empty())&& ( !propertys_2be.empty())&& ( !componentAssemblys_2c1.empty()))
		callTransferType_2f4( cPropertys_2c4, propertys_2be, componentAssemblys_2c1);
}

void RefreshType_1d8::callTransferType_2f4( const Packets_t& cPropertys_1e6, const Packets_t& pPropertys_1e8, const Packets_t& pAssemblys_1ea)
{
	Packets_t cPropertys_1ec;
	Packets_t pPropertys_1ed;
	Packets_t pAssemblys_1ee;
	TransferType_1e5 transferType_1e5;
	transferType_1e5( cPropertys_1e6, pPropertys_1e8, pAssemblys_1ea, cPropertys_1ec, pPropertys_1ed, pAssemblys_1ee);
	_cProperty_1e4->insert( _cProperty_1e4->end(), cPropertys_1ec.begin(), cPropertys_1ec.end());
	_pProperty_1e3->insert( _pProperty_1e3->end(), pPropertys_1ed.begin(), pPropertys_1ed.end());
	_pAssembly_1e2->insert( _pAssembly_1e2->end(), pAssemblys_1ee.begin(), pAssemblys_1ee.end());
}

void TransferType_1e5::operator()( const Packets_t& cPropertys_1e6, const Packets_t& pPropertys_1e8, const Packets_t& pAssemblys_1ea, Packets_t& cPropertys_1ec, Packets_t& pPropertys_1ed, Packets_t& pAssemblys_1ee)
{
#ifdef PRINT_INFO
	std::cout << "TransferType_1e5" << std::endl;
#endif
	_cProperty_1ef= &cPropertys_1ec;
	_pProperty_1f0= &pPropertys_1ed;
	_pAssembly_1f1= &pAssemblys_1ee;
	if( ( !cPropertys_1e6.empty())&& ( !pAssemblys_1ea.empty())&& ( !pPropertys_1e8.empty()))
		callTypeIsString_2af( cPropertys_1e6, pAssemblys_1ea, pPropertys_1e8);
	_cProperty_1ef->insert( _cProperty_1ef->end(), cPropertys_1e6.begin(), cPropertys_1e6.end());
	_pProperty_1f0->insert( _pProperty_1f0->end(), pPropertys_1e8.begin(), pPropertys_1e8.end());
	_pAssembly_1f1->insert( _pAssembly_1f1->end(), pAssemblys_1ea.begin(), pAssemblys_1ea.end());
	if( ( !pAssemblys_1ea.empty())&& ( !cPropertys_1e6.empty())&& ( !pPropertys_1e8.empty()))
		callTypeIsInteger_2b3( pAssemblys_1ea, cPropertys_1e6, pPropertys_1e8);
	if( ( !pPropertys_1e8.empty())&& ( !pAssemblys_1ea.empty())&& ( !cPropertys_1e6.empty()))
		callTypeIsBoolean_2b7( pPropertys_1e8, pAssemblys_1ea, cPropertys_1e6);
}

void TransferType_1e5::callTypeIsString_2af( const Packets_t& cPropertys_271, const Packets_t& componentAssemblys_273, const Packets_t& pPropertys_275)
{
	TypeIsString_270 typeIsString_270;
	typeIsString_270( cPropertys_271, componentAssemblys_273, pPropertys_275);
}

void TransferType_1e5::callTypeIsInteger_2b3( const Packets_t& componentAssemblys_1f3, const Packets_t& cPropertys_1f5, const Packets_t& pPropertys_1f7)
{
	TypeIsInteger_1f2 typeIsInteger_1f2;
	typeIsInteger_1f2( componentAssemblys_1f3, cPropertys_1f5, pPropertys_1f7);
}

void TransferType_1e5::callTypeIsBoolean_2b7( const Packets_t& pPropertys_232, const Packets_t& componentAssemblys_234, const Packets_t& cPropertys_236)
{
	TypeIsBoolean_231 typeIsBoolean_231;
	typeIsBoolean_231( pPropertys_232, componentAssemblys_234, cPropertys_236);
}

void TypeIsInteger_1f2::operator()( const Packets_t& componentAssemblys_1f3, const Packets_t& cPropertys_1f5, const Packets_t& pPropertys_1f7)
{
#ifdef PRINT_INFO
	std::cout << "TypeIsInteger_1f2" << std::endl;
#endif
	processInputPackets( componentAssemblys_1f3, cPropertys_1f5, pPropertys_1f7);
}

bool TypeIsInteger_1f2::isInputUnique( const Udm::Object& componentAssembly_1fd, const Udm::Object& cProperty_206, const Udm::Object& pProperty_20f)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_1ff= _componentAssembly_1f9.begin(), itCProperty_208= _cProperty_202.begin(), itPProperty_211= _pProperty_20b.begin(); itComponentAssembly_1ff!= _componentAssembly_1f9.end(), itCProperty_208!= _cProperty_202.end(), itPProperty_211!= _pProperty_20b.end(); ++itComponentAssembly_1ff, ++itCProperty_208, ++itPProperty_211)
	{
		if( ( *itComponentAssembly_1ff== componentAssembly_1fd)&& ( *itCProperty_208== cProperty_206)&& ( *itPProperty_211== pProperty_20f))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentAssembly_1f9.push_back( componentAssembly_1fd);
		_cProperty_202.push_back( cProperty_206);
		_pProperty_20b.push_back( pProperty_20f);
	}
	return isUnique;
}

bool TypeIsInteger_1f2::isGuardTrue( const Udm::Object& CProperty, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& LongInteger, const Udm::Object& PProperty, const Udm::Object& PredefinedTypes, const Udm::Object& RootFolder)
{
	bool Gz_guard= false;
	string cType; CProperty.GetStrValue("type", cType); return (cType=="INT");;
	return Gz_guard;
}

void TypeIsInteger_1f2::processInputPackets( const Packets_t& componentAssemblys_1f3, const Packets_t& cPropertys_1f5, const Packets_t& pPropertys_1f7)
{
	for( Packets_t::const_iterator itComponentAssembly_1fa= componentAssemblys_1f3.begin(), itCProperty_203= cPropertys_1f5.begin(), itPProperty_20c= pPropertys_1f7.begin(); itComponentAssembly_1fa!= componentAssemblys_1f3.end(), itCProperty_203!= cPropertys_1f5.end(), itPProperty_20c!= pPropertys_1f7.end(); ++itComponentAssembly_1fa, ++itCProperty_203, ++itPProperty_20c)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_1fa, *itCProperty_203, *itPProperty_20c);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_1fa, *itCProperty_203, *itPProperty_20c);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool TypeIsInteger_1f2::patternMatcher( const Udm::Object& componentAssembly_1fb, const Udm::Object& cProperty_204, const Udm::Object& pProperty_20d)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_1fb.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_200= PICML::ComponentAssembly::Cast( componentAssembly_1fb);
		if( false== Uml::IsDerivedFrom( cProperty_204.type(), cadena_scenario::Property::meta))
			continue;
		cadena_scenario::Property cProperty_209= cadena_scenario::Property::Cast( cProperty_204);
		if( false== Uml::IsDerivedFrom( pProperty_20d.type(), PICML::Property::meta))
			continue;
		PICML::Property pProperty_212= PICML::Property::Cast( pProperty_20d);
		Udm::Object componentAssemblyParent_214= componentAssembly_200.container();
		if( false== Uml::IsDerivedFrom( componentAssemblyParent_214.type(), PICML::ComponentImplementationContainer::meta))
			continue;
		PICML::ComponentImplementationContainer componentImplementationContainerComponentAssembly_215= PICML::ComponentImplementationContainer::Cast( componentAssemblyParent_214);
		Udm::Object componentImplementationContainerParent_216= componentImplementationContainerComponentAssembly_215.container();
		if( false== Uml::IsDerivedFrom( componentImplementationContainerParent_216.type(), PICML::ComponentImplementations::meta))
			continue;
		PICML::ComponentImplementations componentImplementationsComponentImplementationContainer_217= PICML::ComponentImplementations::Cast( componentImplementationContainerParent_216);
		Udm::Object componentImplementationsParent_218= componentImplementationsComponentImplementationContainer_217.container();
		if( false== Uml::IsDerivedFrom( componentImplementationsParent_218.type(), PICML::RootFolder::meta))
			continue;
		PICML::RootFolder rootFolderComponentImplementations_219= PICML::RootFolder::Cast( componentImplementationsParent_218);
		set< PICML::PredefinedTypes> predefinedTypess_21a= rootFolderComponentImplementations_219.PredefinedTypes_kind_children();
		for( set< PICML::PredefinedTypes>::const_iterator itPredefinedTypes_21b= predefinedTypess_21a.begin(); itPredefinedTypes_21b!= predefinedTypess_21a.end(); ++itPredefinedTypes_21b)
		{
			PICML::PredefinedTypes currPredefinedTypes_21c= *itPredefinedTypes_21b;
			set< PICML::LongInteger> longIntegers_21d= currPredefinedTypes_21c.LongInteger_kind_children();
			for( set< PICML::LongInteger>::const_iterator itLongInteger_21e= longIntegers_21d.begin(); itLongInteger_21e!= longIntegers_21d.end(); ++itLongInteger_21e)
			{
				PICML::LongInteger currLongInteger_21f= *itLongInteger_21e;
				Match currMatch;
				currMatch.componentAssembly_220= componentAssembly_200;
				currMatch.longInteger_221= currLongInteger_21f;
				currMatch.componentImplementationContainer_222= componentImplementationContainerComponentAssembly_215;
				currMatch.cProperty_223= cProperty_209;
				currMatch.componentImplementations_224= componentImplementationsComponentImplementationContainer_217;
				currMatch.rootFolder_225= rootFolderComponentImplementations_219;
				currMatch.pProperty_226= pProperty_212;
				currMatch.predefinedTypes_227= currPredefinedTypes_21c;
				bool Gz_guard= isGuardTrue( currMatch.cProperty_223, currMatch.componentAssembly_220, currMatch.componentImplementationContainer_222, currMatch.componentImplementations_224, currMatch.longInteger_221, currMatch.pProperty_226, currMatch.predefinedTypes_227, currMatch.rootFolder_225);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void TypeIsInteger_1f2::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::DataType newDataType_230= PICML::DataType::Create( currMatch.pProperty_226);
		Udm::Object& CProperty= currMatch.cProperty_223;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_220;
		Udm::Object& ComponentImplementationContainer= currMatch.componentImplementationContainer_222;
		Udm::Object& ComponentImplementations= currMatch.componentImplementations_224;
		Udm::Object& DataType= newDataType_230;
		Udm::Object& LongInteger= currMatch.longInteger_221;
		Udm::Object& PProperty= currMatch.pProperty_226;
		Udm::Object& PredefinedTypes= currMatch.predefinedTypes_227;
		Udm::Object& RootFolder= currMatch.rootFolder_225;
		{DataType.SetStrValue("name", "LongInteger");};
		newDataType_230.ref()= currMatch.longInteger_221;
		outputAppender( );
	}
}

void TypeIsInteger_1f2::outputAppender()
{
}

void TypeIsBoolean_231::operator()( const Packets_t& pPropertys_232, const Packets_t& componentAssemblys_234, const Packets_t& cPropertys_236)
{
#ifdef PRINT_INFO
	std::cout << "TypeIsBoolean_231" << std::endl;
#endif
	processInputPackets( pPropertys_232, componentAssemblys_234, cPropertys_236);
}

bool TypeIsBoolean_231::isInputUnique( const Udm::Object& pProperty_23c, const Udm::Object& componentAssembly_245, const Udm::Object& cProperty_24e)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPProperty_23e= _pProperty_238.begin(), itComponentAssembly_247= _componentAssembly_241.begin(), itCProperty_250= _cProperty_24a.begin(); itPProperty_23e!= _pProperty_238.end(), itComponentAssembly_247!= _componentAssembly_241.end(), itCProperty_250!= _cProperty_24a.end(); ++itPProperty_23e, ++itComponentAssembly_247, ++itCProperty_250)
	{
		if( ( *itPProperty_23e== pProperty_23c)&& ( *itComponentAssembly_247== componentAssembly_245)&& ( *itCProperty_250== cProperty_24e))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_pProperty_238.push_back( pProperty_23c);
		_componentAssembly_241.push_back( componentAssembly_245);
		_cProperty_24a.push_back( cProperty_24e);
	}
	return isUnique;
}

bool TypeIsBoolean_231::isGuardTrue( const Udm::Object& Boolean, const Udm::Object& CProperty, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& PProperty, const Udm::Object& PredefinedTypes, const Udm::Object& RootFolder)
{
	bool Gz_guard= false;
	string cType; CProperty.GetStrValue("type", cType); return (cType=="BOOLEAN");;
	return Gz_guard;
}

void TypeIsBoolean_231::processInputPackets( const Packets_t& pPropertys_232, const Packets_t& componentAssemblys_234, const Packets_t& cPropertys_236)
{
	for( Packets_t::const_iterator itPProperty_239= pPropertys_232.begin(), itComponentAssembly_242= componentAssemblys_234.begin(), itCProperty_24b= cPropertys_236.begin(); itPProperty_239!= pPropertys_232.end(), itComponentAssembly_242!= componentAssemblys_234.end(), itCProperty_24b!= cPropertys_236.end(); ++itPProperty_239, ++itComponentAssembly_242, ++itCProperty_24b)
	{
		bool isUnique= isInputUnique( *itPProperty_239, *itComponentAssembly_242, *itCProperty_24b);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPProperty_239, *itComponentAssembly_242, *itCProperty_24b);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool TypeIsBoolean_231::patternMatcher( const Udm::Object& pProperty_23a, const Udm::Object& componentAssembly_243, const Udm::Object& cProperty_24c)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( pProperty_23a.type(), PICML::Property::meta))
			continue;
		PICML::Property pProperty_23f= PICML::Property::Cast( pProperty_23a);
		if( false== Uml::IsDerivedFrom( componentAssembly_243.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_248= PICML::ComponentAssembly::Cast( componentAssembly_243);
		if( false== Uml::IsDerivedFrom( cProperty_24c.type(), cadena_scenario::Property::meta))
			continue;
		cadena_scenario::Property cProperty_251= cadena_scenario::Property::Cast( cProperty_24c);
		Udm::Object componentAssemblyParent_253= componentAssembly_248.container();
		if( false== Uml::IsDerivedFrom( componentAssemblyParent_253.type(), PICML::ComponentImplementationContainer::meta))
			continue;
		PICML::ComponentImplementationContainer componentImplementationContainerComponentAssembly_254= PICML::ComponentImplementationContainer::Cast( componentAssemblyParent_253);
		Udm::Object componentImplementationContainerParent_255= componentImplementationContainerComponentAssembly_254.container();
		if( false== Uml::IsDerivedFrom( componentImplementationContainerParent_255.type(), PICML::ComponentImplementations::meta))
			continue;
		PICML::ComponentImplementations componentImplementationsComponentImplementationContainer_256= PICML::ComponentImplementations::Cast( componentImplementationContainerParent_255);
		Udm::Object componentImplementationsParent_257= componentImplementationsComponentImplementationContainer_256.container();
		if( false== Uml::IsDerivedFrom( componentImplementationsParent_257.type(), PICML::RootFolder::meta))
			continue;
		PICML::RootFolder rootFolderComponentImplementations_258= PICML::RootFolder::Cast( componentImplementationsParent_257);
		set< PICML::PredefinedTypes> predefinedTypess_259= rootFolderComponentImplementations_258.PredefinedTypes_kind_children();
		for( set< PICML::PredefinedTypes>::const_iterator itPredefinedTypes_25a= predefinedTypess_259.begin(); itPredefinedTypes_25a!= predefinedTypess_259.end(); ++itPredefinedTypes_25a)
		{
			PICML::PredefinedTypes currPredefinedTypes_25b= *itPredefinedTypes_25a;
			set< PICML::Boolean> booleans_25c= currPredefinedTypes_25b.Boolean_kind_children();
			for( set< PICML::Boolean>::const_iterator itBoolean_25d= booleans_25c.begin(); itBoolean_25d!= booleans_25c.end(); ++itBoolean_25d)
			{
				PICML::Boolean currBoolean_25e= *itBoolean_25d;
				Match currMatch;
				currMatch.boolean_25f= currBoolean_25e;
				currMatch.predefinedTypes_260= currPredefinedTypes_25b;
				currMatch.rootFolder_261= rootFolderComponentImplementations_258;
				currMatch.componentImplementationContainer_262= componentImplementationContainerComponentAssembly_254;
				currMatch.componentImplementations_263= componentImplementationsComponentImplementationContainer_256;
				currMatch.pProperty_264= pProperty_23f;
				currMatch.componentAssembly_265= componentAssembly_248;
				currMatch.cProperty_266= cProperty_251;
				bool Gz_guard= isGuardTrue( currMatch.boolean_25f, currMatch.cProperty_266, currMatch.componentAssembly_265, currMatch.componentImplementationContainer_262, currMatch.componentImplementations_263, currMatch.pProperty_264, currMatch.predefinedTypes_260, currMatch.rootFolder_261);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void TypeIsBoolean_231::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::DataType newDataType_26f= PICML::DataType::Create( currMatch.pProperty_264);
		Udm::Object& Boolean= currMatch.boolean_25f;
		Udm::Object& CProperty= currMatch.cProperty_266;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_265;
		Udm::Object& ComponentImplementationContainer= currMatch.componentImplementationContainer_262;
		Udm::Object& ComponentImplementations= currMatch.componentImplementations_263;
		Udm::Object& DataType= newDataType_26f;
		Udm::Object& PProperty= currMatch.pProperty_264;
		Udm::Object& PredefinedTypes= currMatch.predefinedTypes_260;
		Udm::Object& RootFolder= currMatch.rootFolder_261;
		{DataType.SetStrValue("name", "Boolean");};
		newDataType_26f.ref()= currMatch.boolean_25f;
		outputAppender( );
	}
}

void TypeIsBoolean_231::outputAppender()
{
}

void TypeIsString_270::operator()( const Packets_t& cPropertys_271, const Packets_t& componentAssemblys_273, const Packets_t& pPropertys_275)
{
#ifdef PRINT_INFO
	std::cout << "TypeIsString_270" << std::endl;
#endif
	processInputPackets( cPropertys_271, componentAssemblys_273, pPropertys_275);
}

bool TypeIsString_270::isInputUnique( const Udm::Object& cProperty_27b, const Udm::Object& componentAssembly_284, const Udm::Object& pProperty_28d)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itCProperty_27d= _cProperty_277.begin(), itComponentAssembly_286= _componentAssembly_280.begin(), itPProperty_28f= _pProperty_289.begin(); itCProperty_27d!= _cProperty_277.end(), itComponentAssembly_286!= _componentAssembly_280.end(), itPProperty_28f!= _pProperty_289.end(); ++itCProperty_27d, ++itComponentAssembly_286, ++itPProperty_28f)
	{
		if( ( *itCProperty_27d== cProperty_27b)&& ( *itComponentAssembly_286== componentAssembly_284)&& ( *itPProperty_28f== pProperty_28d))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_cProperty_277.push_back( cProperty_27b);
		_componentAssembly_280.push_back( componentAssembly_284);
		_pProperty_289.push_back( pProperty_28d);
	}
	return isUnique;
}

bool TypeIsString_270::isGuardTrue( const Udm::Object& CProperty, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& PProperty, const Udm::Object& PredefinedTypes, const Udm::Object& RootFolder, const Udm::Object& String)
{
	bool Gz_guard= false;
	string cType; CProperty.GetStrValue("type", cType); return (cType=="STRING");;
	return Gz_guard;
}

void TypeIsString_270::processInputPackets( const Packets_t& cPropertys_271, const Packets_t& componentAssemblys_273, const Packets_t& pPropertys_275)
{
	for( Packets_t::const_iterator itCProperty_278= cPropertys_271.begin(), itComponentAssembly_281= componentAssemblys_273.begin(), itPProperty_28a= pPropertys_275.begin(); itCProperty_278!= cPropertys_271.end(), itComponentAssembly_281!= componentAssemblys_273.end(), itPProperty_28a!= pPropertys_275.end(); ++itCProperty_278, ++itComponentAssembly_281, ++itPProperty_28a)
	{
		bool isUnique= isInputUnique( *itCProperty_278, *itComponentAssembly_281, *itPProperty_28a);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itCProperty_278, *itComponentAssembly_281, *itPProperty_28a);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool TypeIsString_270::patternMatcher( const Udm::Object& cProperty_279, const Udm::Object& componentAssembly_282, const Udm::Object& pProperty_28b)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( cProperty_279.type(), cadena_scenario::Property::meta))
			continue;
		cadena_scenario::Property cProperty_27e= cadena_scenario::Property::Cast( cProperty_279);
		if( false== Uml::IsDerivedFrom( componentAssembly_282.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_287= PICML::ComponentAssembly::Cast( componentAssembly_282);
		if( false== Uml::IsDerivedFrom( pProperty_28b.type(), PICML::Property::meta))
			continue;
		PICML::Property pProperty_290= PICML::Property::Cast( pProperty_28b);
		Udm::Object componentAssemblyParent_292= componentAssembly_287.container();
		if( false== Uml::IsDerivedFrom( componentAssemblyParent_292.type(), PICML::ComponentImplementationContainer::meta))
			continue;
		PICML::ComponentImplementationContainer componentImplementationContainerComponentAssembly_293= PICML::ComponentImplementationContainer::Cast( componentAssemblyParent_292);
		Udm::Object componentImplementationContainerParent_294= componentImplementationContainerComponentAssembly_293.container();
		if( false== Uml::IsDerivedFrom( componentImplementationContainerParent_294.type(), PICML::ComponentImplementations::meta))
			continue;
		PICML::ComponentImplementations componentImplementationsComponentImplementationContainer_295= PICML::ComponentImplementations::Cast( componentImplementationContainerParent_294);
		Udm::Object componentImplementationsParent_296= componentImplementationsComponentImplementationContainer_295.container();
		if( false== Uml::IsDerivedFrom( componentImplementationsParent_296.type(), PICML::RootFolder::meta))
			continue;
		PICML::RootFolder rootFolderComponentImplementations_297= PICML::RootFolder::Cast( componentImplementationsParent_296);
		set< PICML::PredefinedTypes> predefinedTypess_298= rootFolderComponentImplementations_297.PredefinedTypes_kind_children();
		for( set< PICML::PredefinedTypes>::const_iterator itPredefinedTypes_299= predefinedTypess_298.begin(); itPredefinedTypes_299!= predefinedTypess_298.end(); ++itPredefinedTypes_299)
		{
			PICML::PredefinedTypes currPredefinedTypes_29a= *itPredefinedTypes_299;
			set< PICML::String> strings_29b= currPredefinedTypes_29a.String_kind_children();
			for( set< PICML::String>::const_iterator itString_29c= strings_29b.begin(); itString_29c!= strings_29b.end(); ++itString_29c)
			{
				PICML::String currString_29d= *itString_29c;
				Match currMatch;
				currMatch.predefinedTypes_29e= currPredefinedTypes_29a;
				currMatch.string_29f= currString_29d;
				currMatch.cProperty_2a0= cProperty_27e;
				currMatch.rootFolder_2a1= rootFolderComponentImplementations_297;
				currMatch.componentImplementationContainer_2a2= componentImplementationContainerComponentAssembly_293;
				currMatch.componentAssembly_2a3= componentAssembly_287;
				currMatch.componentImplementations_2a4= componentImplementationsComponentImplementationContainer_295;
				currMatch.pProperty_2a5= pProperty_290;
				bool Gz_guard= isGuardTrue( currMatch.cProperty_2a0, currMatch.componentAssembly_2a3, currMatch.componentImplementationContainer_2a2, currMatch.componentImplementations_2a4, currMatch.pProperty_2a5, currMatch.predefinedTypes_29e, currMatch.rootFolder_2a1, currMatch.string_29f);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void TypeIsString_270::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::DataType newDataType_2ae= PICML::DataType::Create( currMatch.pProperty_2a5);
		Udm::Object& CProperty= currMatch.cProperty_2a0;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_2a3;
		Udm::Object& ComponentImplementationContainer= currMatch.componentImplementationContainer_2a2;
		Udm::Object& ComponentImplementations= currMatch.componentImplementations_2a4;
		Udm::Object& DataType= newDataType_2ae;
		Udm::Object& PProperty= currMatch.pProperty_2a5;
		Udm::Object& PredefinedTypes= currMatch.predefinedTypes_29e;
		Udm::Object& RootFolder= currMatch.rootFolder_2a1;
		Udm::Object& String= currMatch.string_29f;
		{DataType.SetStrValue("name", "String");};
		newDataType_2ae.ref()= currMatch.string_29f;
		outputAppender( );
	}
}

void TypeIsString_270::outputAppender()
{
}

void DeleteCurrentType_2bb::operator()( const Packets_t& propertys_2bc, const Packets_t& componentAssemblys_2bf, const Packets_t& cPropertys_2c2, Packets_t& propertys_2be, Packets_t& componentAssemblys_2c1, Packets_t& cPropertys_2c4)
{
#ifdef PRINT_INFO
	std::cout << "DeleteCurrentType_2bb" << std::endl;
#endif
	_property_2c5= &propertys_2be;
	_componentAssembly_2c6= &componentAssemblys_2c1;
	_cProperty_2c7= &cPropertys_2c4;
	processInputPackets( propertys_2bc, componentAssemblys_2bf, cPropertys_2c2);
	forwardInputs( );
}

bool DeleteCurrentType_2bb::isInputUnique( const Udm::Object& property_2cc, const Udm::Object& componentAssembly_2d5, const Udm::Object& cProperty_2de)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itProperty_2ce= _property_2c8.begin(), itComponentAssembly_2d7= _componentAssembly_2d1.begin(), itCProperty_2e0= _cProperty_2da.begin(); itProperty_2ce!= _property_2c8.end(), itComponentAssembly_2d7!= _componentAssembly_2d1.end(), itCProperty_2e0!= _cProperty_2da.end(); ++itProperty_2ce, ++itComponentAssembly_2d7, ++itCProperty_2e0)
	{
		if( ( *itProperty_2ce== property_2cc)&& ( *itComponentAssembly_2d7== componentAssembly_2d5)&& ( *itCProperty_2e0== cProperty_2de))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_property_2c8.push_back( property_2cc);
		_componentAssembly_2d1.push_back( componentAssembly_2d5);
		_cProperty_2da.push_back( cProperty_2de);
	}
	return isUnique;
}

void DeleteCurrentType_2bb::processInputPackets( const Packets_t& propertys_2bc, const Packets_t& componentAssemblys_2bf, const Packets_t& cPropertys_2c2)
{
	for( Packets_t::const_iterator itProperty_2c9= propertys_2bc.begin(), itComponentAssembly_2d2= componentAssemblys_2bf.begin(), itCProperty_2db= cPropertys_2c2.begin(); itProperty_2c9!= propertys_2bc.end(), itComponentAssembly_2d2!= componentAssemblys_2bf.end(), itCProperty_2db!= cPropertys_2c2.end(); ++itProperty_2c9, ++itComponentAssembly_2d2, ++itCProperty_2db)
	{
		bool isUnique= isInputUnique( *itProperty_2c9, *itComponentAssembly_2d2, *itCProperty_2db);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itProperty_2c9, *itComponentAssembly_2d2, *itCProperty_2db);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool DeleteCurrentType_2bb::patternMatcher( const Udm::Object& property_2ca, const Udm::Object& componentAssembly_2d3, const Udm::Object& cProperty_2dc)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( property_2ca.type(), PICML::Property::meta))
			continue;
		PICML::Property property_2cf= PICML::Property::Cast( property_2ca);
		if( false== Uml::IsDerivedFrom( componentAssembly_2d3.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_2d8= PICML::ComponentAssembly::Cast( componentAssembly_2d3);
		if( false== Uml::IsDerivedFrom( cProperty_2dc.type(), cadena_scenario::Property::meta))
			continue;
		cadena_scenario::Property cProperty_2e1= cadena_scenario::Property::Cast( cProperty_2dc);
		set< PICML::DataType> dataTypes_2e3= property_2cf.DataType_kind_children();
		for( set< PICML::DataType>::const_iterator itDataType_2e4= dataTypes_2e3.begin(); itDataType_2e4!= dataTypes_2e3.end(); ++itDataType_2e4)
		{
			PICML::DataType currDataType_2e5= *itDataType_2e4;
			Match currMatch;
			currMatch.property_2e6= property_2cf;
			currMatch.dataType_2e7= currDataType_2e5;
			currMatch.componentAssembly_2e8= componentAssembly_2d8;
			currMatch.cProperty_2e9= cProperty_2e1;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void DeleteCurrentType_2bb::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		if( currMatch.dataType_2e7)
			currMatch.dataType_2e7.DeleteObject();
		outputAppender( currMatch.property_2e6, currMatch.componentAssembly_2e8, currMatch.cProperty_2e9);
	}
}

void DeleteCurrentType_2bb::outputAppender( const PICML::Property& property_2ea, const PICML::ComponentAssembly& componentAssembly_2ec, const cadena_scenario::Property& cProperty_2ee)
{
	_property_2c5->push_back( property_2ea);
	_componentAssembly_2c6->push_back( componentAssembly_2ec);
	_cProperty_2c7->push_back( cProperty_2ee);
}

void DeleteCurrentType_2bb::forwardInputs()
{
	*_property_2c5= _property_2c8;
	*_componentAssembly_2c6= _componentAssembly_2d1;
	*_cProperty_2c7= _cProperty_2da;
}

void EnumerateComponentProperties_2f8::operator()( const Packets_t& componentAssemblys_2f9, const Packets_t& scenarios_2fc, Packets_t& componentAssemblys_2fb, Packets_t& propertys_2fe, Packets_t& cPropertys_2ff)
{
#ifdef PRINT_INFO
	std::cout << "EnumerateComponentProperties_2f8" << std::endl;
#endif
	_componentAssembly_300= &componentAssemblys_2fb;
	_property_301= &propertys_2fe;
	_cProperty_302= &cPropertys_2ff;
	processInputPackets( componentAssemblys_2f9, scenarios_2fc);
}

bool EnumerateComponentProperties_2f8::isInputUnique( const Udm::Object& componentAssembly_307, const Udm::Object& scenario_310)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_309= _componentAssembly_303.begin(), itScenario_312= _scenario_30c.begin(); itComponentAssembly_309!= _componentAssembly_303.end(), itScenario_312!= _scenario_30c.end(); ++itComponentAssembly_309, ++itScenario_312)
	{
		if( ( *itComponentAssembly_309== componentAssembly_307)&& ( *itScenario_312== scenario_310))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentAssembly_303.push_back( componentAssembly_307);
		_scenario_30c.push_back( scenario_310);
	}
	return isUnique;
}

void EnumerateComponentProperties_2f8::processInputPackets( const Packets_t& componentAssemblys_2f9, const Packets_t& scenarios_2fc)
{
	for( Packets_t::const_iterator itComponentAssembly_304= componentAssemblys_2f9.begin(), itScenario_30d= scenarios_2fc.begin(); itComponentAssembly_304!= componentAssemblys_2f9.end(), itScenario_30d!= scenarios_2fc.end(); ++itComponentAssembly_304, ++itScenario_30d)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_304, *itScenario_30d);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_304, *itScenario_30d);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool EnumerateComponentProperties_2f8::patternMatcher( const Udm::Object& componentAssembly_305, const Udm::Object& scenario_30e)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_305.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_30a= PICML::ComponentAssembly::Cast( componentAssembly_305);
		if( false== Uml::IsDerivedFrom( scenario_30e.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_313= cadena_scenario::Scenario::Cast( scenario_30e);
		set< cadena_scenario::ComponentInstance> componentInstances_315= scenario_313.ComponentInstance_kind_children();
		for( set< cadena_scenario::ComponentInstance>::const_iterator itComponentInstance_316= componentInstances_315.begin(); itComponentInstance_316!= componentInstances_315.end(); ++itComponentInstance_316)
		{
			cadena_scenario::ComponentInstance currComponentInstance_317= *itComponentInstance_316;
			set< cadena_scenario::Property> cPropertys_318= currComponentInstance_317.Property_kind_children();
			for( set< cadena_scenario::Property>::const_iterator itCProperty_319= cPropertys_318.begin(); itCProperty_319!= cPropertys_318.end(); ++itCProperty_319)
			{
				cadena_scenario::Property currCProperty_31a= *itCProperty_319;
				PICML::Property property_31b= currCProperty_31a.picmlProperty();
				if( !property_31b)
					continue;
				Match currMatch;
				currMatch.componentInstance_31c= currComponentInstance_317;
				currMatch.componentAssembly_31d= componentAssembly_30a;
				currMatch.scenario_31e= scenario_313;
				currMatch.property_31f= property_31b;
				currMatch.cProperty_320= currCProperty_31a;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void EnumerateComponentProperties_2f8::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.componentAssembly_31d, currMatch.property_31f, currMatch.cProperty_320);
	}
}

void EnumerateComponentProperties_2f8::outputAppender( const PICML::ComponentAssembly& componentAssembly_321, const PICML::Property& property_323, const cadena_scenario::Property& cProperty_325)
{
	_componentAssembly_300->push_back( componentAssembly_321);
	_property_301->push_back( property_323);
	_cProperty_302->push_back( cProperty_325);
}

void TransferValue_327::operator()( const Packets_t& cPropertys_328, const Packets_t& pPropertys_32a)
{
#ifdef PRINT_INFO
	std::cout << "TransferValue_327" << std::endl;
#endif
	processInputPackets( cPropertys_328, pPropertys_32a);
}

bool TransferValue_327::isInputUnique( const Udm::Object& cProperty_330, const Udm::Object& pProperty_339)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itCProperty_332= _cProperty_32c.begin(), itPProperty_33b= _pProperty_335.begin(); itCProperty_332!= _cProperty_32c.end(), itPProperty_33b!= _pProperty_335.end(); ++itCProperty_332, ++itPProperty_33b)
	{
		if( ( *itCProperty_332== cProperty_330)&& ( *itPProperty_33b== pProperty_339))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_cProperty_32c.push_back( cProperty_330);
		_pProperty_335.push_back( pProperty_339);
	}
	return isUnique;
}

void TransferValue_327::processInputPackets( const Packets_t& cPropertys_328, const Packets_t& pPropertys_32a)
{
	for( Packets_t::const_iterator itCProperty_32d= cPropertys_328.begin(), itPProperty_336= pPropertys_32a.begin(); itCProperty_32d!= cPropertys_328.end(), itPProperty_336!= pPropertys_32a.end(); ++itCProperty_32d, ++itPProperty_336)
	{
		bool isUnique= isInputUnique( *itCProperty_32d, *itPProperty_336);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itCProperty_32d, *itPProperty_336);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool TransferValue_327::patternMatcher( const Udm::Object& cProperty_32e, const Udm::Object& pProperty_337)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( cProperty_32e.type(), cadena_scenario::Property::meta))
			continue;
		cadena_scenario::Property cProperty_333= cadena_scenario::Property::Cast( cProperty_32e);
		if( false== Uml::IsDerivedFrom( pProperty_337.type(), PICML::Property::meta))
			continue;
		PICML::Property pProperty_33c= PICML::Property::Cast( pProperty_337);
		Match currMatch;
		currMatch.cProperty_33e= cProperty_333;
		currMatch.pProperty_33f= pProperty_33c;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void TransferValue_327::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& CProperty= currMatch.cProperty_33e;
		Udm::Object& PProperty= currMatch.pProperty_33f;
		{string cValue; CProperty.GetStrValue("value", cValue); PProperty.SetStrValue("DataValue", cValue);};
		outputAppender( );
	}
}

void TransferValue_327::outputAppender()
{
}

void Create_and_Set_Emit_Invoke_Properties_34d::operator()( const Packets_t& cScenarios_34e, const Packets_t& pAssemblys_350)
{
#ifdef PRINT_INFO
	std::cout << "Create_and_Set_Emit_Invoke_Properties_34d" << std::endl;
#endif
	if( ( !cScenarios_34e.empty()))
		callFind_Invoke_Properties_4b4( cScenarios_34e);
	if( ( !cScenarios_34e.empty()))
		callFind_Emit_Properties_4b6( cScenarios_34e);
}

void Create_and_Set_Emit_Invoke_Properties_34d::callFind_Invoke_Properties_4b4( const Packets_t& scenarios_388)
{
	Packets_t providedRequestPorts_384;
	Packets_t requiredRequestPorts_385;
	Packets_t pSlaveComponents_386;
	Packets_t pPropertys_387;
	Packets_t cPropertys_38a;
	Find_Invoke_Properties_383 find_Invoke_Properties_383;
	find_Invoke_Properties_383( scenarios_388, providedRequestPorts_384, requiredRequestPorts_385, pSlaveComponents_386, pPropertys_387, cPropertys_38a);
	if( ( !providedRequestPorts_384.empty())&& ( !requiredRequestPorts_385.empty())&& ( !cPropertys_38a.empty())&& ( !pPropertys_387.empty())&& ( !pSlaveComponents_386.empty()))
		callDumpEIValue_4b8( providedRequestPorts_384, requiredRequestPorts_385, cPropertys_38a, pPropertys_387, pSlaveComponents_386);
}

void Create_and_Set_Emit_Invoke_Properties_34d::callFind_Emit_Properties_4b6( const Packets_t& scenarios_47e)
{
	Packets_t pSlaveComponents_47b;
	Packets_t inEventPorts_47c;
	Packets_t outEventPorts_47d;
	Packets_t cPropertys_480;
	Packets_t pPropertys_481;
	Find_Emit_Properties_47a find_Emit_Properties_47a;
	find_Emit_Properties_47a( scenarios_47e, pSlaveComponents_47b, inEventPorts_47c, outEventPorts_47d, cPropertys_480, pPropertys_481);
	if( ( !inEventPorts_47c.empty())&& ( !outEventPorts_47d.empty())&& ( !cPropertys_480.empty())&& ( !pPropertys_481.empty())&& ( !pSlaveComponents_47b.empty()))
		callDumpEIValue_4b8( inEventPorts_47c, outEventPorts_47d, cPropertys_480, pPropertys_481, pSlaveComponents_47b);
}

void Create_and_Set_Emit_Invoke_Properties_34d::callDumpEIValue_4b8( const Packets_t& pSlavePorts_3be, const Packets_t& pMasterPorts_3c0, const Packets_t& cPropertys_3c2, const Packets_t& pCEIPropertiess_3c4, const Packets_t& pSlaveComponents_3c6)
{
	Packets_t cPropertys_3c8;
	Packets_t pCEIPropertiess_3c9;
	Packets_t pMasterPorts_3ca;
	Packets_t pSlavePorts_3cb;
	Packets_t pSlaveComponents_3cc;
	DumpEIValue_3bd dumpEIValue_3bd;
	dumpEIValue_3bd( pSlavePorts_3be, pMasterPorts_3c0, cPropertys_3c2, pCEIPropertiess_3c4, pSlaveComponents_3c6, cPropertys_3c8, pCEIPropertiess_3c9, pMasterPorts_3ca, pSlavePorts_3cb, pSlaveComponents_3cc);
	if( ( !pMasterPorts_3ca.empty())&& ( !pCEIPropertiess_3c9.empty()))
		callSet_CEIProperties_DataType_4be( pMasterPorts_3ca, pCEIPropertiess_3c9);
}

void Create_and_Set_Emit_Invoke_Properties_34d::callSet_CEIProperties_DataType_4be( const Packets_t& ports_353, const Packets_t& pPropertys_355)
{
	Set_CEIProperties_DataType_352 set_CEIProperties_DataType_352;
	set_CEIProperties_DataType_352( ports_353, pPropertys_355);
}

void Set_CEIProperties_DataType_352::operator()( const Packets_t& ports_353, const Packets_t& pPropertys_355)
{
#ifdef PRINT_INFO
	std::cout << "Set_CEIProperties_DataType_352" << std::endl;
#endif
	processInputPackets( ports_353, pPropertys_355);
}

bool Set_CEIProperties_DataType_352::isInputUnique( const Udm::Object& port_35b, const Udm::Object& pProperty_364)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPort_35d= _port_357.begin(), itPProperty_366= _pProperty_360.begin(); itPort_35d!= _port_357.end(), itPProperty_366!= _pProperty_360.end(); ++itPort_35d, ++itPProperty_366)
	{
		if( ( *itPort_35d== port_35b)&& ( *itPProperty_366== pProperty_364))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_port_357.push_back( port_35b);
		_pProperty_360.push_back( pProperty_364);
	}
	return isUnique;
}

void Set_CEIProperties_DataType_352::processInputPackets( const Packets_t& ports_353, const Packets_t& pPropertys_355)
{
	for( Packets_t::const_iterator itPort_358= ports_353.begin(), itPProperty_361= pPropertys_355.begin(); itPort_358!= ports_353.end(), itPProperty_361!= pPropertys_355.end(); ++itPort_358, ++itPProperty_361)
	{
		bool isUnique= isInputUnique( *itPort_358, *itPProperty_361);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPort_358, *itPProperty_361);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Set_CEIProperties_DataType_352::patternMatcher( const Udm::Object& port_359, const Udm::Object& pProperty_362)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( port_359.type(), PICML::Port::meta))
			continue;
		PICML::Port port_35e= PICML::Port::Cast( port_359);
		if( false== Uml::IsDerivedFrom( pProperty_362.type(), PICML::Property::meta))
			continue;
		PICML::Property pProperty_367= PICML::Property::Cast( pProperty_362);
		Udm::Object portParent_369= port_35e.container();
		if( false== Uml::IsDerivedFrom( portParent_369.type(), PICML::Component::meta))
			continue;
		PICML::Component componentPort_36a= PICML::Component::Cast( portParent_369);
		Udm::Object componentParent_36b= componentPort_36a.container();
		if( false== Uml::IsDerivedFrom( componentParent_36b.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssemblyComponent_36c= PICML::ComponentAssembly::Cast( componentParent_36b);
		Udm::Object componentAssemblyParent_36d= componentAssemblyComponent_36c.container();
		if( false== Uml::IsDerivedFrom( componentAssemblyParent_36d.type(), PICML::ComponentImplementationContainer::meta))
			continue;
		PICML::ComponentImplementationContainer componentImplementationContainerComponentAssembly_36e= PICML::ComponentImplementationContainer::Cast( componentAssemblyParent_36d);
		Udm::Object componentImplementationContainerParent_36f= componentImplementationContainerComponentAssembly_36e.container();
		if( false== Uml::IsDerivedFrom( componentImplementationContainerParent_36f.type(), PICML::ComponentImplementations::meta))
			continue;
		PICML::ComponentImplementations componentImplementationsComponentImplementationContainer_370= PICML::ComponentImplementations::Cast( componentImplementationContainerParent_36f);
		Udm::Object componentImplementationsParent_371= componentImplementationsComponentImplementationContainer_370.container();
		if( false== Uml::IsDerivedFrom( componentImplementationsParent_371.type(), PICML::RootFolder::meta))
			continue;
		PICML::RootFolder rootFolderComponentImplementations_372= PICML::RootFolder::Cast( componentImplementationsParent_371);
		set< PICML::PredefinedTypes> predefinedTypess_373= rootFolderComponentImplementations_372.PredefinedTypes_kind_children();
		for( set< PICML::PredefinedTypes>::const_iterator itPredefinedTypes_374= predefinedTypess_373.begin(); itPredefinedTypes_374!= predefinedTypess_373.end(); ++itPredefinedTypes_374)
		{
			PICML::PredefinedTypes currPredefinedTypes_375= *itPredefinedTypes_374;
			set< PICML::String> strings_376= currPredefinedTypes_375.String_kind_children();
			for( set< PICML::String>::const_iterator itString_377= strings_376.begin(); itString_377!= strings_376.end(); ++itString_377)
			{
				PICML::String currString_378= *itString_377;
				Match currMatch;
				currMatch.component_379= componentPort_36a;
				currMatch.port_37a= port_35e;
				currMatch.componentImplementationContainer_37b= componentImplementationContainerComponentAssembly_36e;
				currMatch.rootFolder_37c= rootFolderComponentImplementations_372;
				currMatch.string_37d= currString_378;
				currMatch.pProperty_37e= pProperty_367;
				currMatch.componentAssembly_37f= componentAssemblyComponent_36c;
				currMatch.predefinedTypes_380= currPredefinedTypes_375;
				currMatch.componentImplementations_381= componentImplementationsComponentImplementationContainer_370;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void Set_CEIProperties_DataType_352::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::DataType newDataType_382= PICML::DataType::Create( currMatch.pProperty_37e);
		Udm::Object& Component= currMatch.component_379;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_37f;
		Udm::Object& ComponentImplementationContainer= currMatch.componentImplementationContainer_37b;
		Udm::Object& ComponentImplementations= currMatch.componentImplementations_381;
		Udm::Object& DataType= newDataType_382;
		Udm::Object& PProperty= currMatch.pProperty_37e;
		Udm::Object& Port= currMatch.port_37a;
		Udm::Object& PredefinedTypes= currMatch.predefinedTypes_380;
		Udm::Object& RootFolder= currMatch.rootFolder_37c;
		Udm::Object& String= currMatch.string_37d;
		{DataType.SetStrValue("name", "String");};
		newDataType_382.ref()= currMatch.string_37d;
		outputAppender( );
	}
}

void Set_CEIProperties_DataType_352::outputAppender()
{
}

void Find_Invoke_Properties_383::operator()( const Packets_t& scenarios_388, Packets_t& providedRequestPorts_384, Packets_t& requiredRequestPorts_385, Packets_t& pSlaveComponents_386, Packets_t& pPropertys_387, Packets_t& cPropertys_38a)
{
#ifdef PRINT_INFO
	std::cout << "Find_Invoke_Properties_383" << std::endl;
#endif
	_providedRequestPort_38b= &providedRequestPorts_384;
	_requiredRequestPort_38c= &requiredRequestPorts_385;
	_pSlaveComponent_38d= &pSlaveComponents_386;
	_pProperty_38e= &pPropertys_387;
	_cProperty_38f= &cPropertys_38a;
	processInputPackets( scenarios_388);
}

bool Find_Invoke_Properties_383::isInputUnique( const Udm::Object& scenario_394)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_396= _scenario_390.begin(); itScenario_396!= _scenario_390.end(); ++itScenario_396)
	{
		if( ( *itScenario_396== scenario_394))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_390.push_back( scenario_394);
	return isUnique;
}

void Find_Invoke_Properties_383::processInputPackets( const Packets_t& scenarios_388)
{
	for( Packets_t::const_iterator itScenario_391= scenarios_388.begin(); itScenario_391!= scenarios_388.end(); ++itScenario_391)
	{
		bool isUnique= isInputUnique( *itScenario_391);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_391);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Find_Invoke_Properties_383::patternMatcher( const Udm::Object& scenario_392)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_392.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_397= cadena_scenario::Scenario::Cast( scenario_392);
		set< cadena_scenario::FRConnection> fRConnections_399= scenario_397.FRConnection_kind_children();
		for( set< cadena_scenario::FRConnection>::const_iterator itFRConnection_39a= fRConnections_399.begin(); itFRConnection_39a!= fRConnections_399.end(); ++itFRConnection_39a)
		{
			cadena_scenario::FRConnection currFRConnection_39b= *itFRConnection_39a;
			set< cadena_scenario::Property> cPropertys_39c= currFRConnection_39b.Property_kind_children();
			for( set< cadena_scenario::Property>::const_iterator itCProperty_39d= cPropertys_39c.begin(); itCProperty_39d!= cPropertys_39c.end(); ++itCProperty_39d)
			{
				cadena_scenario::Property currCProperty_39e= *itCProperty_39d;
				PICML::invoke invoke_39f= currFRConnection_39b.picmlInvoke();
				if( !invoke_39f)
					continue;
				PICML::RequiredRequestPort requiredRequestPort_3a0= invoke_39f.srcinvoke_end();
				Udm::Object requiredRequestPortParent_3a1= requiredRequestPort_3a0.container();
				if( false== Uml::IsDerivedFrom( requiredRequestPortParent_3a1.type(), PICML::Component::meta))
					continue;
				PICML::Component pMasterComponentRequiredRequestPort_3a2= PICML::Component::Cast( requiredRequestPortParent_3a1);
				Udm::Object pMasterComponentParent_3a3= pMasterComponentRequiredRequestPort_3a2.container();
				if( false== Uml::IsDerivedFrom( pMasterComponentParent_3a3.type(), PICML::ComponentAssembly::meta))
					continue;
				PICML::ComponentAssembly componentAssemblyPMasterComponent_3a4= PICML::ComponentAssembly::Cast( pMasterComponentParent_3a3);
				PICML::ProvidedRequestPort providedRequestPort_3a5= invoke_39f.dstinvoke_end();
				Udm::Object providedRequestPortParent_3a6= providedRequestPort_3a5.container();
				if( false== Uml::IsDerivedFrom( providedRequestPortParent_3a6.type(), PICML::Component::meta))
					continue;
				PICML::Component pSlaveComponentProvidedRequestPort_3a7= PICML::Component::Cast( providedRequestPortParent_3a6);
				Match currMatch;
				currMatch.providedRequestPort_3a8= providedRequestPort_3a5;
				currMatch.requiredRequestPort_3a9= requiredRequestPort_3a0;
				currMatch.invoke_3aa= invoke_39f;
				currMatch.fRConnection_3ab= currFRConnection_39b;
				currMatch.pSlaveComponent_3ac= pSlaveComponentProvidedRequestPort_3a7;
				currMatch.pMasterComponent_3ad= pMasterComponentRequiredRequestPort_3a2;
				currMatch.scenario_3ae= scenario_397;
				currMatch.cProperty_3af= currCProperty_39e;
				currMatch.componentAssembly_3b0= componentAssemblyPMasterComponent_3a4;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void Find_Invoke_Properties_383::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::Property newPProperty_3b1= PICML::Property::Create( currMatch.componentAssembly_3b0);
		PICML::AssemblyConfigProperty newAssemblyConfigProperty_3b2= PICML::AssemblyConfigProperty::Create( currMatch.componentAssembly_3b0);
		Udm::Object& AssemblyConfigProperty= newAssemblyConfigProperty_3b2;
		Udm::Object& CProperty= currMatch.cProperty_3af;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_3b0;
		Udm::Object& FRConnection= currMatch.fRConnection_3ab;
		Udm::Object& PMasterComponent= currMatch.pMasterComponent_3ad;
		Udm::Object& PProperty= newPProperty_3b1;
		Udm::Object& PSlaveComponent= currMatch.pSlaveComponent_3ac;
		Udm::Object& ProvidedRequestPort= currMatch.providedRequestPort_3a8;
		Udm::Object& RequiredRequestPort= currMatch.requiredRequestPort_3a9;
		Udm::Object& Scenario= currMatch.scenario_3ae;
		Udm::Object& invoke= currMatch.invoke_3aa;
		{PProperty.SetStrValue("name", "CadenaEIProperties");};
		newPProperty_3b1.cadenaProperty()= currMatch.cProperty_3af;
		newAssemblyConfigProperty_3b2.srcAssemblyConfigProperty_end()= currMatch.pMasterComponent_3ad;
		newAssemblyConfigProperty_3b2.dstAssemblyConfigProperty_end()= newPProperty_3b1;
		outputAppender( currMatch.providedRequestPort_3a8, currMatch.requiredRequestPort_3a9, currMatch.pSlaveComponent_3ac, newPProperty_3b1, currMatch.cProperty_3af);
	}
}

void Find_Invoke_Properties_383::outputAppender( const PICML::ProvidedRequestPort& providedRequestPort_3b3, const PICML::RequiredRequestPort& requiredRequestPort_3b5, const PICML::Component& pSlaveComponent_3b7, const PICML::Property& pProperty_3b9, const cadena_scenario::Property& cProperty_3bb)
{
	_providedRequestPort_38b->push_back( providedRequestPort_3b3);
	_requiredRequestPort_38c->push_back( requiredRequestPort_3b5);
	_pSlaveComponent_38d->push_back( pSlaveComponent_3b7);
	_pProperty_38e->push_back( pProperty_3b9);
	_cProperty_38f->push_back( cProperty_3bb);
}

void DumpEIValue_3bd::operator()( const Packets_t& pSlavePorts_3be, const Packets_t& pMasterPorts_3c0, const Packets_t& cPropertys_3c2, const Packets_t& pCEIPropertiess_3c4, const Packets_t& pSlaveComponents_3c6, Packets_t& cPropertys_3c8, Packets_t& pCEIPropertiess_3c9, Packets_t& pMasterPorts_3ca, Packets_t& pSlavePorts_3cb, Packets_t& pSlaveComponents_3cc)
{
#ifdef PRINT_INFO
	std::cout << "DumpEIValue_3bd" << std::endl;
#endif
	_cProperty_3cd= &cPropertys_3c8;
	_pCEIProperties_3ce= &pCEIPropertiess_3c9;
	_pMasterPort_3cf= &pMasterPorts_3ca;
	_pSlavePort_3d0= &pSlavePorts_3cb;
	_pSlaveComponent_3d1= &pSlaveComponents_3cc;
	for( Packets_t::const_iterator itPSlavePort_3d3= pSlavePorts_3be.begin(), itPMasterPort_3da= pMasterPorts_3c0.begin(), itCProperty_3e1= cPropertys_3c2.begin(), itPCEIProperties_3e8= pCEIPropertiess_3c4.begin(), itPSlaveComponent_3ef= pSlaveComponents_3c6.begin(); itPSlavePort_3d3!= pSlavePorts_3be.end(), itPMasterPort_3da!= pMasterPorts_3c0.end(), itCProperty_3e1!= cPropertys_3c2.end(), itPCEIProperties_3e8!= pCEIPropertiess_3c4.end(), itPSlaveComponent_3ef!= pSlaveComponents_3c6.end(); ++itPSlavePort_3d3, ++itPMasterPort_3da, ++itCProperty_3e1, ++itPCEIProperties_3e8, ++itPSlaveComponent_3ef)
	{
		bool isUnique= isInputUnique( *itPSlavePort_3d3, *itPMasterPort_3da, *itCProperty_3e1, *itPCEIProperties_3e8, *itPSlaveComponent_3ef);
		if( !isUnique)
			continue;
		Packets_t onePSlavePort_3d7( 1, *itPSlavePort_3d3);
		Packets_t onePMasterPort_3de( 1, *itPMasterPort_3da);
		Packets_t oneCProperty_3e5( 1, *itCProperty_3e1);
		Packets_t onePCEIProperties_3ec( 1, *itPCEIProperties_3e8);
		Packets_t onePSlaveComponent_3f3( 1, *itPSlaveComponent_3ef);
		executeOne( onePSlavePort_3d7, onePMasterPort_3de, oneCProperty_3e5, onePCEIProperties_3ec, onePSlaveComponent_3f3);
	}
}

void DumpEIValue_3bd::executeOne( const Packets_t& pSlavePorts_3be, const Packets_t& pMasterPorts_3c0, const Packets_t& cPropertys_3c2, const Packets_t& pCEIPropertiess_3c4, const Packets_t& pSlaveComponents_3c6)
{
	_pSlavePort_3d0->insert( _pSlavePort_3d0->end(), pSlavePorts_3be.begin(), pSlavePorts_3be.end());
	_pMasterPort_3cf->insert( _pMasterPort_3cf->end(), pMasterPorts_3c0.begin(), pMasterPorts_3c0.end());
	_cProperty_3cd->insert( _cProperty_3cd->end(), cPropertys_3c2.begin(), cPropertys_3c2.end());
	_pCEIProperties_3ce->insert( _pCEIProperties_3ce->end(), pCEIPropertiess_3c4.begin(), pCEIPropertiess_3c4.end());
	_pSlaveComponent_3d1->insert( _pSlaveComponent_3d1->end(), pSlaveComponents_3c6.begin(), pSlaveComponents_3c6.end());
	if( ( !pSlavePorts_3be.empty())&& ( !pMasterPorts_3c0.empty())&& ( !pSlaveComponents_3c6.empty())&& ( !pCEIPropertiess_3c4.empty())&& ( !cPropertys_3c2.empty()))
		callCopyTo_XProperty_46f( pSlavePorts_3be, pMasterPorts_3c0, pSlaveComponents_3c6, pCEIPropertiess_3c4, cPropertys_3c2);
}

bool DumpEIValue_3bd::isInputUnique( const Udm::Object& pSlavePort_3d4, const Udm::Object& pMasterPort_3db, const Udm::Object& cProperty_3e2, const Udm::Object& pCEIProperties_3e9, const Udm::Object& pSlaveComponent_3f0)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPSlavePort_3d6= _pSlavePort_3d2.begin(), itPMasterPort_3dd= _pMasterPort_3d9.begin(), itCProperty_3e4= _cProperty_3e0.begin(), itPCEIProperties_3eb= _pCEIProperties_3e7.begin(), itPSlaveComponent_3f2= _pSlaveComponent_3ee.begin(); itPSlavePort_3d6!= _pSlavePort_3d2.end(), itPMasterPort_3dd!= _pMasterPort_3d9.end(), itCProperty_3e4!= _cProperty_3e0.end(), itPCEIProperties_3eb!= _pCEIProperties_3e7.end(), itPSlaveComponent_3f2!= _pSlaveComponent_3ee.end(); ++itPSlavePort_3d6, ++itPMasterPort_3dd, ++itCProperty_3e4, ++itPCEIProperties_3eb, ++itPSlaveComponent_3f2)
	{
		if( ( *itPSlavePort_3d6== pSlavePort_3d4)&& ( *itPMasterPort_3dd== pMasterPort_3db)&& ( *itCProperty_3e4== cProperty_3e2)&& ( *itPCEIProperties_3eb== pCEIProperties_3e9)&& ( *itPSlaveComponent_3f2== pSlaveComponent_3f0))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_pSlavePort_3d2.push_back( pSlavePort_3d4);
		_pMasterPort_3d9.push_back( pMasterPort_3db);
		_cProperty_3e0.push_back( cProperty_3e2);
		_pCEIProperties_3e7.push_back( pCEIProperties_3e9);
		_pSlaveComponent_3ee.push_back( pSlaveComponent_3f0);
	}
	return isUnique;
}

void DumpEIValue_3bd::callCopyTo_XProperty_46f( const Packets_t& pSlavePorts_3f6, const Packets_t& pMasterPorts_3f8, const Packets_t& pSlaveComponents_3fb, const Packets_t& pPropertys_3fd, const Packets_t& cPropertys_400)
{
	Packets_t rootContainers_3fa;
	Packets_t pPropertys_3ff;
	CopyTo_XProperty_3f5 copyTo_XProperty_3f5;
	copyTo_XProperty_3f5( pSlavePorts_3f6, pMasterPorts_3f8, pSlaveComponents_3fb, pPropertys_3fd, cPropertys_400, rootContainers_3fa, pPropertys_3ff);
	if( ( !rootContainers_3fa.empty())&& ( !pPropertys_3ff.empty()))
		callCopyHierarchy_DumpToDisk_ReadFile_Transfer_475( rootContainers_3fa, pPropertys_3ff);
}

void DumpEIValue_3bd::callCopyHierarchy_DumpToDisk_ReadFile_Transfer_475( const Packets_t& rootContainers_453, const Packets_t& pPropertys_456)
{
	Packets_t rootContainers_455;
	CopyHierarchy_DumpToDisk_ReadFile_Transfer_452 copyHierarchy_DumpToDisk_ReadFile_Transfer_452;
	copyHierarchy_DumpToDisk_ReadFile_Transfer_452( rootContainers_453, pPropertys_456, rootContainers_455);
	if( ( !rootContainers_455.empty()))
		callDestroyEverything_478( rootContainers_455);
}

void DumpEIValue_3bd::callDestroyEverything_478( const Packets_t& rootContainers_442)
{
	DestroyEverything_441 destroyEverything_441;
	destroyEverything_441( rootContainers_442);
}

void CopyTo_XProperty_3f5::operator()( const Packets_t& pSlavePorts_3f6, const Packets_t& pMasterPorts_3f8, const Packets_t& pSlaveComponents_3fb, const Packets_t& pPropertys_3fd, const Packets_t& cPropertys_400, Packets_t& rootContainers_3fa, Packets_t& pPropertys_3ff)
{
#ifdef PRINT_INFO
	std::cout << "CopyTo_XProperty_3f5" << std::endl;
#endif
	_rootContainer_402= &rootContainers_3fa;
	_pProperty_403= &pPropertys_3ff;
	processInputPackets( pSlavePorts_3f6, pMasterPorts_3f8, pSlaveComponents_3fb, pPropertys_3fd, cPropertys_400);
}

bool CopyTo_XProperty_3f5::isInputUnique( const Udm::Object& pSlavePort_408, const Udm::Object& pMasterPort_411, const Udm::Object& pSlaveComponent_41a, const Udm::Object& pProperty_423, const Udm::Object& cProperty_42c)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPSlavePort_40a= _pSlavePort_404.begin(), itPMasterPort_413= _pMasterPort_40d.begin(), itPSlaveComponent_41c= _pSlaveComponent_416.begin(), itPProperty_425= _pProperty_41f.begin(), itCProperty_42e= _cProperty_428.begin(); itPSlavePort_40a!= _pSlavePort_404.end(), itPMasterPort_413!= _pMasterPort_40d.end(), itPSlaveComponent_41c!= _pSlaveComponent_416.end(), itPProperty_425!= _pProperty_41f.end(), itCProperty_42e!= _cProperty_428.end(); ++itPSlavePort_40a, ++itPMasterPort_413, ++itPSlaveComponent_41c, ++itPProperty_425, ++itCProperty_42e)
	{
		if( ( *itPSlavePort_40a== pSlavePort_408)&& ( *itPMasterPort_413== pMasterPort_411)&& ( *itPSlaveComponent_41c== pSlaveComponent_41a)&& ( *itPProperty_425== pProperty_423)&& ( *itCProperty_42e== cProperty_42c))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_pSlavePort_404.push_back( pSlavePort_408);
		_pMasterPort_40d.push_back( pMasterPort_411);
		_pSlaveComponent_416.push_back( pSlaveComponent_41a);
		_pProperty_41f.push_back( pProperty_423);
		_cProperty_428.push_back( cProperty_42c);
	}
	return isUnique;
}

void CopyTo_XProperty_3f5::processInputPackets( const Packets_t& pSlavePorts_3f6, const Packets_t& pMasterPorts_3f8, const Packets_t& pSlaveComponents_3fb, const Packets_t& pPropertys_3fd, const Packets_t& cPropertys_400)
{
	for( Packets_t::const_iterator itPSlavePort_405= pSlavePorts_3f6.begin(), itPMasterPort_40e= pMasterPorts_3f8.begin(), itPSlaveComponent_417= pSlaveComponents_3fb.begin(), itPProperty_420= pPropertys_3fd.begin(), itCProperty_429= cPropertys_400.begin(); itPSlavePort_405!= pSlavePorts_3f6.end(), itPMasterPort_40e!= pMasterPorts_3f8.end(), itPSlaveComponent_417!= pSlaveComponents_3fb.end(), itPProperty_420!= pPropertys_3fd.end(), itCProperty_429!= cPropertys_400.end(); ++itPSlavePort_405, ++itPMasterPort_40e, ++itPSlaveComponent_417, ++itPProperty_420, ++itCProperty_429)
	{
		bool isUnique= isInputUnique( *itPSlavePort_405, *itPMasterPort_40e, *itPSlaveComponent_417, *itPProperty_420, *itCProperty_429);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPSlavePort_405, *itPMasterPort_40e, *itPSlaveComponent_417, *itPProperty_420, *itCProperty_429);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool CopyTo_XProperty_3f5::patternMatcher( const Udm::Object& pSlavePort_406, const Udm::Object& pMasterPort_40f, const Udm::Object& pSlaveComponent_418, const Udm::Object& pProperty_421, const Udm::Object& cProperty_42a)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( pSlavePort_406.type(), PICML::Port::meta))
			continue;
		PICML::Port pSlavePort_40b= PICML::Port::Cast( pSlavePort_406);
		if( false== Uml::IsDerivedFrom( pMasterPort_40f.type(), PICML::Port::meta))
			continue;
		PICML::Port pMasterPort_414= PICML::Port::Cast( pMasterPort_40f);
		if( false== Uml::IsDerivedFrom( pSlaveComponent_418.type(), PICML::Component::meta))
			continue;
		PICML::Component pSlaveComponent_41d= PICML::Component::Cast( pSlaveComponent_418);
		if( false== Uml::IsDerivedFrom( pProperty_421.type(), PICML::Property::meta))
			continue;
		PICML::Property pProperty_426= PICML::Property::Cast( pProperty_421);
		if( false== Uml::IsDerivedFrom( cProperty_42a.type(), cadena_scenario::Property::meta))
			continue;
		cadena_scenario::Property cProperty_42f= cadena_scenario::Property::Cast( cProperty_42a);
		Udm::Object pSlaveComponentParent_431= pSlaveComponent_41d.container();
		if( false== Uml::IsDerivedFrom( pSlaveComponentParent_431.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssemblyPSlaveComponent_432= PICML::ComponentAssembly::Cast( pSlaveComponentParent_431);
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_433= componentAssemblyPSlaveComponent_432.rootContainer();
		if( !rootContainer_433)
			continue;
		Match currMatch;
		currMatch.pSlavePort_434= pSlavePort_40b;
		currMatch.pMasterPort_435= pMasterPort_414;
		currMatch.rootContainer_436= rootContainer_433;
		currMatch.componentAssembly_437= componentAssemblyPSlaveComponent_432;
		currMatch.pSlaveComponent_438= pSlaveComponent_41d;
		currMatch.pProperty_439= pProperty_426;
		currMatch.cProperty_43a= cProperty_42f;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void CopyTo_XProperty_3f5::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector newConnectionSelector_43b= PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector::Create( currMatch.rootContainer_436);
		PICMLCadena_Xchange_embedded_EIProperties::Property newXProperty_43c= PICMLCadena_Xchange_embedded_EIProperties::Property::Create( newConnectionSelector_43b);
		Udm::Object& CProperty= currMatch.cProperty_43a;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_437;
		Udm::Object& ConnectionSelector= newConnectionSelector_43b;
		Udm::Object& PMasterPort= currMatch.pMasterPort_435;
		Udm::Object& PProperty= currMatch.pProperty_439;
		Udm::Object& PSlaveComponent= currMatch.pSlaveComponent_438;
		Udm::Object& PSlavePort= currMatch.pSlavePort_434;
		Udm::Object& RootContainer= currMatch.rootContainer_436;
		Udm::Object& XProperty= newXProperty_43c;
		{string s;  PSlaveComponent.GetStrValue("name", s); ConnectionSelector.SetStrValue("slaveComponentName", s); PSlavePort.GetStrValue("name", s); ConnectionSelector.SetStrValue("slavePortName", s); PMasterPort.GetStrValue("name", s); ConnectionSelector.SetStrValue("masterPortName", s);  CProperty.GetStrValue("name", s); XProperty.SetStrValue("name", s); CProperty.GetStrValue("value", s); XProperty.SetStrValue("value", s); CProperty.GetStrValue("type", s); XProperty.SetStrValue("type", s);};
		outputAppender( currMatch.rootContainer_436, currMatch.pProperty_439);
	}
}

void CopyTo_XProperty_3f5::outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::RootContainer& rootContainer_43d, const PICML::Property& pProperty_43f)
{
	_rootContainer_402->push_back( rootContainer_43d);
	_pProperty_403->push_back( pProperty_43f);
}

void DestroyEverything_441::operator()( const Packets_t& rootContainers_442)
{
#ifdef PRINT_INFO
	std::cout << "DestroyEverything_441" << std::endl;
#endif
	processInputPackets( rootContainers_442);
}

bool DestroyEverything_441::isInputUnique( const Udm::Object& rootContainer_448)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRootContainer_44a= _rootContainer_444.begin(); itRootContainer_44a!= _rootContainer_444.end(); ++itRootContainer_44a)
	{
		if( ( *itRootContainer_44a== rootContainer_448))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_rootContainer_444.push_back( rootContainer_448);
	return isUnique;
}

void DestroyEverything_441::processInputPackets( const Packets_t& rootContainers_442)
{
	for( Packets_t::const_iterator itRootContainer_445= rootContainers_442.begin(); itRootContainer_445!= rootContainers_442.end(); ++itRootContainer_445)
	{
		bool isUnique= isInputUnique( *itRootContainer_445);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRootContainer_445);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool DestroyEverything_441::patternMatcher( const Udm::Object& rootContainer_446)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( rootContainer_446.type(), PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta))
			continue;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_44b= PICMLCadena_Xchange_embedded_EIProperties::RootContainer::Cast( rootContainer_446);
		set< PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector> connectionSelectors_44d= rootContainer_44b.ConnectionSelector_kind_children();
		for( set< PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector>::const_iterator itConnectionSelector_44e= connectionSelectors_44d.begin(); itConnectionSelector_44e!= connectionSelectors_44d.end(); ++itConnectionSelector_44e)
		{
			PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector currConnectionSelector_44f= *itConnectionSelector_44e;
			Match currMatch;
			currMatch.rootContainer_450= rootContainer_44b;
			currMatch.connectionSelector_451= currConnectionSelector_44f;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void DestroyEverything_441::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		if( currMatch.connectionSelector_451)
			currMatch.connectionSelector_451.DeleteObject();
		outputAppender( );
	}
}

void DestroyEverything_441::outputAppender()
{
}

void CopyHierarchy_DumpToDisk_ReadFile_Transfer_452::operator()( const Packets_t& rootContainers_453, const Packets_t& pPropertys_456, Packets_t& rootContainers_455)
{
#ifdef PRINT_INFO
	std::cout << "CopyHierarchy_DumpToDisk_ReadFile_Transfer_452" << std::endl;
#endif
	_rootContainer_458= &rootContainers_455;
	processInputPackets( rootContainers_453, pPropertys_456);
	forwardInputs( );
}

bool CopyHierarchy_DumpToDisk_ReadFile_Transfer_452::isInputUnique( const Udm::Object& rootContainer_45d, const Udm::Object& pProperty_466)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRootContainer_45f= _rootContainer_459.begin(), itPProperty_468= _pProperty_462.begin(); itRootContainer_45f!= _rootContainer_459.end(), itPProperty_468!= _pProperty_462.end(); ++itRootContainer_45f, ++itPProperty_468)
	{
		if( ( *itRootContainer_45f== rootContainer_45d)&& ( *itPProperty_468== pProperty_466))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_rootContainer_459.push_back( rootContainer_45d);
		_pProperty_462.push_back( pProperty_466);
	}
	return isUnique;
}

void CopyHierarchy_DumpToDisk_ReadFile_Transfer_452::processInputPackets( const Packets_t& rootContainers_453, const Packets_t& pPropertys_456)
{
	for( Packets_t::const_iterator itRootContainer_45a= rootContainers_453.begin(), itPProperty_463= pPropertys_456.begin(); itRootContainer_45a!= rootContainers_453.end(), itPProperty_463!= pPropertys_456.end(); ++itRootContainer_45a, ++itPProperty_463)
	{
		bool isUnique= isInputUnique( *itRootContainer_45a, *itPProperty_463);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRootContainer_45a, *itPProperty_463);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool CopyHierarchy_DumpToDisk_ReadFile_Transfer_452::patternMatcher( const Udm::Object& rootContainer_45b, const Udm::Object& pProperty_464)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( rootContainer_45b.type(), PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta))
			continue;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_460= PICMLCadena_Xchange_embedded_EIProperties::RootContainer::Cast( rootContainer_45b);
		if( false== Uml::IsDerivedFrom( pProperty_464.type(), PICML::Property::meta))
			continue;
		PICML::Property pProperty_469= PICML::Property::Cast( pProperty_464);
		Match currMatch;
		currMatch.rootContainer_46b= rootContainer_460;
		currMatch.pProperty_46c= pProperty_469;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void CopyHierarchy_DumpToDisk_ReadFile_Transfer_452::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& PProperty= currMatch.pProperty_46c;
		Udm::Object& RootContainer= currMatch.rootContainer_46b;
		{Udm::UdmDiagram mydiagram;  mydiagram.dgr=const_cast<Uml::Diagram *>(&(RootContainer.__impl()->__getdn()->GetRootMeta())); mydiagram.init=Uml::diagram.init; UdmDom::DomDataNetwork ddn(mydiagram);    ddn.CreateNewToString("Udm\\PICMLCadena_Xchange_embedded_EIProperties.xsd", RootContainer.type()); UdmUtil::CopyObjectHierarchy(RootContainer.__impl(), ddn.GetRootObject().__impl(), &ddn, UdmUtil::copy_assoc_map()); ddn.CloseWithUpdate(); PProperty.SetStrValue("DataValue",ddn.Str());};
		outputAppender( currMatch.rootContainer_46b);
	}
}

void CopyHierarchy_DumpToDisk_ReadFile_Transfer_452::outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::RootContainer& rootContainer_46d)
{
	_rootContainer_458->push_back( rootContainer_46d);
}

void CopyHierarchy_DumpToDisk_ReadFile_Transfer_452::forwardInputs()
{
	*_rootContainer_458= _rootContainer_459;
}

void Find_Emit_Properties_47a::operator()( const Packets_t& scenarios_47e, Packets_t& pSlaveComponents_47b, Packets_t& inEventPorts_47c, Packets_t& outEventPorts_47d, Packets_t& cPropertys_480, Packets_t& pPropertys_481)
{
#ifdef PRINT_INFO
	std::cout << "Find_Emit_Properties_47a" << std::endl;
#endif
	_pSlaveComponent_482= &pSlaveComponents_47b;
	_inEventPort_483= &inEventPorts_47c;
	_outEventPort_484= &outEventPorts_47d;
	_cProperty_485= &cPropertys_480;
	_pProperty_486= &pPropertys_481;
	processInputPackets( scenarios_47e);
}

bool Find_Emit_Properties_47a::isInputUnique( const Udm::Object& scenario_48b)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_48d= _scenario_487.begin(); itScenario_48d!= _scenario_487.end(); ++itScenario_48d)
	{
		if( ( *itScenario_48d== scenario_48b))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_487.push_back( scenario_48b);
	return isUnique;
}

void Find_Emit_Properties_47a::processInputPackets( const Packets_t& scenarios_47e)
{
	for( Packets_t::const_iterator itScenario_488= scenarios_47e.begin(); itScenario_488!= scenarios_47e.end(); ++itScenario_488)
	{
		bool isUnique= isInputUnique( *itScenario_488);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_488);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Find_Emit_Properties_47a::patternMatcher( const Udm::Object& scenario_489)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_489.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_48e= cadena_scenario::Scenario::Cast( scenario_489);
		set< cadena_scenario::ESSConnection> eSSConnections_490= scenario_48e.ESSConnection_kind_children();
		for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnection_491= eSSConnections_490.begin(); itESSConnection_491!= eSSConnections_490.end(); ++itESSConnection_491)
		{
			cadena_scenario::ESSConnection currESSConnection_492= *itESSConnection_491;
			set< cadena_scenario::Property> cPropertys_493= currESSConnection_492.Property_kind_children();
			for( set< cadena_scenario::Property>::const_iterator itCProperty_494= cPropertys_493.begin(); itCProperty_494!= cPropertys_493.end(); ++itCProperty_494)
			{
				cadena_scenario::Property currCProperty_495= *itCProperty_494;
				PICML::emit emit_496= currESSConnection_492.picmlEmit();
				if( !emit_496)
					continue;
				PICML::OutEventPort outEventPort_497= emit_496.srcemit_end();
				Udm::Object outEventPortParent_498= outEventPort_497.container();
				if( false== Uml::IsDerivedFrom( outEventPortParent_498.type(), PICML::Component::meta))
					continue;
				PICML::Component pMasterComponentOutEventPort_499= PICML::Component::Cast( outEventPortParent_498);
				Udm::Object pMasterComponentParent_49a= pMasterComponentOutEventPort_499.container();
				if( false== Uml::IsDerivedFrom( pMasterComponentParent_49a.type(), PICML::ComponentAssembly::meta))
					continue;
				PICML::ComponentAssembly componentAssemblyPMasterComponent_49b= PICML::ComponentAssembly::Cast( pMasterComponentParent_49a);
				PICML::InEventPort inEventPort_49c= emit_496.dstemit_end();
				Udm::Object inEventPortParent_49d= inEventPort_49c.container();
				if( false== Uml::IsDerivedFrom( inEventPortParent_49d.type(), PICML::Component::meta))
					continue;
				PICML::Component pSlaveComponentInEventPort_49e= PICML::Component::Cast( inEventPortParent_49d);
				Match currMatch;
				currMatch.componentAssembly_49f= componentAssemblyPMasterComponent_49b;
				currMatch.pSlaveComponent_4a0= pSlaveComponentInEventPort_49e;
				currMatch.pMasterComponent_4a1= pMasterComponentOutEventPort_499;
				currMatch.inEventPort_4a2= inEventPort_49c;
				currMatch.outEventPort_4a3= outEventPort_497;
				currMatch.emit_4a4= emit_496;
				currMatch.scenario_4a5= scenario_48e;
				currMatch.cProperty_4a6= currCProperty_495;
				currMatch.eSSConnection_4a7= currESSConnection_492;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void Find_Emit_Properties_47a::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::Property newPProperty_4a8= PICML::Property::Create( currMatch.componentAssembly_49f);
		PICML::AssemblyConfigProperty newAssemblyConfigProperty_4a9= PICML::AssemblyConfigProperty::Create( currMatch.componentAssembly_49f);
		Udm::Object& AssemblyConfigProperty= newAssemblyConfigProperty_4a9;
		Udm::Object& CProperty= currMatch.cProperty_4a6;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_49f;
		Udm::Object& ESSConnection= currMatch.eSSConnection_4a7;
		Udm::Object& InEventPort= currMatch.inEventPort_4a2;
		Udm::Object& OutEventPort= currMatch.outEventPort_4a3;
		Udm::Object& PMasterComponent= currMatch.pMasterComponent_4a1;
		Udm::Object& PProperty= newPProperty_4a8;
		Udm::Object& PSlaveComponent= currMatch.pSlaveComponent_4a0;
		Udm::Object& Scenario= currMatch.scenario_4a5;
		Udm::Object& emit= currMatch.emit_4a4;
		{PProperty.SetStrValue("name", "CadenaEIProperties");};
		newPProperty_4a8.cadenaProperty()= currMatch.cProperty_4a6;
		newAssemblyConfigProperty_4a9.srcAssemblyConfigProperty_end()= currMatch.pMasterComponent_4a1;
		newAssemblyConfigProperty_4a9.dstAssemblyConfigProperty_end()= newPProperty_4a8;
		outputAppender( currMatch.pSlaveComponent_4a0, currMatch.inEventPort_4a2, currMatch.outEventPort_4a3, currMatch.cProperty_4a6, newPProperty_4a8);
	}
}

void Find_Emit_Properties_47a::outputAppender( const PICML::Component& pSlaveComponent_4aa, const PICML::InEventPort& inEventPort_4ac, const PICML::OutEventPort& outEventPort_4ae, const cadena_scenario::Property& cProperty_4b0, const PICML::Property& pProperty_4b2)
{
	_pSlaveComponent_482->push_back( pSlaveComponent_4aa);
	_inEventPort_483->push_back( inEventPort_4ac);
	_outEventPort_484->push_back( outEventPort_4ae);
	_cProperty_485->push_back( cProperty_4b0);
	_pProperty_486->push_back( pProperty_4b2);
}

void CreateNormalProperties_4c1::operator()( const Packets_t& pAssemblys_4c2, const Packets_t& cScenarios_4c4, Packets_t& pAssemblys_4c6, Packets_t& cScenarios_4c7)
{
#ifdef PRINT_INFO
	std::cout << "CreateNormalProperties_4c1" << std::endl;
#endif
	_pAssembly_4c8= &pAssemblys_4c6;
	_cScenario_4c9= &cScenarios_4c7;
	if( ( !cScenarios_4c4.empty()))
		callPublishConnectorProperty_Find_Unmatched_5d0( cScenarios_4c4);
	if( ( !cScenarios_4c4.empty()))
		callComponentProperties_Create_5d2( cScenarios_4c4);
	_pAssembly_4c8->insert( _pAssembly_4c8->end(), pAssemblys_4c2.begin(), pAssemblys_4c2.end());
	_cScenario_4c9->insert( _cScenario_4c9->end(), cScenarios_4c4.begin(), cScenarios_4c4.end());
}

void CreateNormalProperties_4c1::callPublishConnectorProperty_Find_Unmatched_5d0( const Packets_t& scenarios_574)
{
	Packets_t cPropertys_573;
	Packets_t publishConnectors_576;
	PublishConnectorProperty_Find_Unmatched_572 publishConnectorProperty_Find_Unmatched_572;
	publishConnectorProperty_Find_Unmatched_572( scenarios_574, cPropertys_573, publishConnectors_576);
	if( ( !publishConnectors_576.empty())&& ( !cPropertys_573.empty()))
		callEnsure_CadenaProperties_Requirement_5d4( publishConnectors_576, cPropertys_573);
}

void CreateNormalProperties_4c1::callComponentProperties_Create_5d2( const Packets_t& scenarios_5b3)
{
	ComponentProperties_Create_5b2 componentProperties_Create_5b2;
	componentProperties_Create_5b2( scenarios_5b3);
}

void CreateNormalProperties_4c1::callEnsure_CadenaProperties_Requirement_5d4( const Packets_t& pPublishConnectors_4cb, const Packets_t& cPropertys_4cd)
{
	Packets_t pPublishConnectors_4cf;
	Packets_t cPropertys_4d0;
	Packets_t pRequirements_4d1;
	Ensure_CadenaProperties_Requirement_4ca ensure_CadenaProperties_Requirement_4ca;
	ensure_CadenaProperties_Requirement_4ca( pPublishConnectors_4cb, cPropertys_4cd, pPublishConnectors_4cf, cPropertys_4d0, pRequirements_4d1);
	if( ( !cPropertys_4d0.empty())&& ( !pRequirements_4d1.empty()))
		callCreate_PublishConnectorProperty_5d7( cPropertys_4d0, pRequirements_4d1);
}

void CreateNormalProperties_4c1::callCreate_PublishConnectorProperty_5d7( const Packets_t& cPropertys_596, const Packets_t& requirements_598)
{
	Create_PublishConnectorProperty_595 create_PublishConnectorProperty_595;
	create_PublishConnectorProperty_595( cPropertys_596, requirements_598);
}

void Ensure_CadenaProperties_Requirement_4ca::operator()( const Packets_t& pPublishConnectors_4cb, const Packets_t& cPropertys_4cd, Packets_t& pPublishConnectors_4cf, Packets_t& cPropertys_4d0, Packets_t& pRequirements_4d1)
{
#ifdef PRINT_INFO
	std::cout << "Ensure_CadenaProperties_Requirement_4ca" << std::endl;
#endif
	_pPublishConnector_4d2= &pPublishConnectors_4cf;
	_cProperty_4d3= &cPropertys_4d0;
	_pRequirement_4d4= &pRequirements_4d1;
	if( ( !pPublishConnectors_4cb.empty())&& ( !cPropertys_4cd.empty()))
		callTest_56c( pPublishConnectors_4cb, cPropertys_4cd);
}

void Ensure_CadenaProperties_Requirement_4ca::callTest_56c( const Packets_t& pPublishConnectors_4d6, const Packets_t& cPropertys_4d8)
{
	Packets_t pPublishConnectors_4da;
	Packets_t cPropertiess_4db;
	Packets_t pPublishConnectors_4dc;
	Packets_t cPropertys_4dd;
	Packets_t pRequirements_4de;
	Test_4d5 test_4d5;
	test_4d5( pPublishConnectors_4d6, cPropertys_4d8, pPublishConnectors_4da, cPropertiess_4db, pPublishConnectors_4dc, cPropertys_4dd, pRequirements_4de);
	_pPublishConnector_4d2->insert( _pPublishConnector_4d2->end(), pPublishConnectors_4dc.begin(), pPublishConnectors_4dc.end());
	_cProperty_4d3->insert( _cProperty_4d3->end(), cPropertys_4dd.begin(), cPropertys_4dd.end());
	_pRequirement_4d4->insert( _pRequirement_4d4->end(), pRequirements_4de.begin(), pRequirements_4de.end());
	if( ( !cPropertiess_4db.empty())&& ( !pPublishConnectors_4da.empty()))
		callCreate_CadenaProperties_Requirement_56f( cPropertiess_4db, pPublishConnectors_4da);
}

void Ensure_CadenaProperties_Requirement_4ca::callCreate_CadenaProperties_Requirement_56f( const Packets_t& propertys_543, const Packets_t& publishConnectors_547)
{
	Packets_t propertys_545;
	Packets_t requirements_546;
	Packets_t publishConnectors_549;
	Create_CadenaProperties_Requirement_542 create_CadenaProperties_Requirement_542;
	create_CadenaProperties_Requirement_542( propertys_543, publishConnectors_547, propertys_545, requirements_546, publishConnectors_549);
	_cProperty_4d3->insert( _cProperty_4d3->end(), propertys_545.begin(), propertys_545.end());
	_pRequirement_4d4->insert( _pRequirement_4d4->end(), requirements_546.begin(), requirements_546.end());
	_pPublishConnector_4d2->insert( _pPublishConnector_4d2->end(), publishConnectors_549.begin(), publishConnectors_549.end());
}

void Test_4d5::operator()( const Packets_t& pPublishConnectors_4d6, const Packets_t& cPropertys_4d8, Packets_t& pPublishConnectors_4da, Packets_t& cPropertiess_4db, Packets_t& pPublishConnectors_4dc, Packets_t& cPropertys_4dd, Packets_t& pRequirements_4de)
{
#ifdef PRINT_INFO
	std::cout << "Test_4d5" << std::endl;
#endif
	_pPublishConnector_4df= &pPublishConnectors_4da;
	_cProperties_4e0= &cPropertiess_4db;
	_pPublishConnector_4e1= &pPublishConnectors_4dc;
	_cProperty_4e2= &cPropertys_4dd;
	_pRequirement_4e3= &pRequirements_4de;
	for( Packets_t::const_iterator itPPublishConnector_4e5= pPublishConnectors_4d6.begin(), itCProperty_4ec= cPropertys_4d8.begin(); itPPublishConnector_4e5!= pPublishConnectors_4d6.end(), itCProperty_4ec!= cPropertys_4d8.end(); ++itPPublishConnector_4e5, ++itCProperty_4ec)
	{
		bool isUnique= isInputUnique( *itPPublishConnector_4e5, *itCProperty_4ec);
		if( !isUnique)
			continue;
		Packets_t onePPublishConnector_4e9( 1, *itPPublishConnector_4e5);
		Packets_t oneCProperty_4f0( 1, *itCProperty_4ec);
		executeOne( onePPublishConnector_4e9, oneCProperty_4f0);
	}
}

void Test_4d5::executeOne( const Packets_t& pPublishConnectors_4d6, const Packets_t& cPropertys_4d8)
{
	Packets_t propertys_4f5;
	Packets_t publishConnectors_4f8;
	Packets_t requirements_4f9;
	RequirementExists_4f2 requirementExists_4f2;
	bool isMatchRequirementExists_4f2= requirementExists_4f2( cPropertys_4d8, pPublishConnectors_4d6, propertys_4f5, publishConnectors_4f8, requirements_4f9);
	_cProperty_4e2->insert( _cProperty_4e2->end(), propertys_4f5.begin(), propertys_4f5.end());
	_pPublishConnector_4e1->insert( _pPublishConnector_4e1->end(), publishConnectors_4f8.begin(), publishConnectors_4f8.end());
	_pRequirement_4e3->insert( _pRequirement_4e3->end(), requirements_4f9.begin(), requirements_4f9.end());
	if( isMatchRequirementExists_4f2)
		return;
	Packets_t publishConnectors_524;
	Packets_t propertys_527;
	RequirementDoesNotExist_521 requirementDoesNotExist_521;
	bool isMatchRequirementDoesNotExist_521= requirementDoesNotExist_521( pPublishConnectors_4d6, cPropertys_4d8, publishConnectors_524, propertys_527);
	_pPublishConnector_4df->insert( _pPublishConnector_4df->end(), publishConnectors_524.begin(), publishConnectors_524.end());
	_cProperties_4e0->insert( _cProperties_4e0->end(), propertys_527.begin(), propertys_527.end());
}

bool Test_4d5::isInputUnique( const Udm::Object& pPublishConnector_4e6, const Udm::Object& cProperty_4ed)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPPublishConnector_4e8= _pPublishConnector_4e4.begin(), itCProperty_4ef= _cProperty_4eb.begin(); itPPublishConnector_4e8!= _pPublishConnector_4e4.end(), itCProperty_4ef!= _cProperty_4eb.end(); ++itPPublishConnector_4e8, ++itCProperty_4ef)
	{
		if( ( *itPPublishConnector_4e8== pPublishConnector_4e6)&& ( *itCProperty_4ef== cProperty_4ed))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_pPublishConnector_4e4.push_back( pPublishConnector_4e6);
		_cProperty_4eb.push_back( cProperty_4ed);
	}
	return isUnique;
}

bool RequirementExists_4f2::operator()( const Packets_t& propertys_4f3, const Packets_t& publishConnectors_4f6, Packets_t& propertys_4f5, Packets_t& publishConnectors_4f8, Packets_t& requirements_4f9)
{
#ifdef PRINT_INFO
	std::cout << "RequirementExists_4f2" << std::endl;
#endif
	_property_4fa= &propertys_4f5;
	_publishConnector_4fb= &publishConnectors_4f8;
	_requirement_4fc= &requirements_4f9;
	processInputPackets( propertys_4f3, publishConnectors_4f6);
	if( false== _matches.empty())
		return true;
	return false;
}

bool RequirementExists_4f2::isInputUnique( const Udm::Object& property_501, const Udm::Object& publishConnector_50a)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itProperty_503= _property_4fd.begin(), itPublishConnector_50c= _publishConnector_506.begin(); itProperty_503!= _property_4fd.end(), itPublishConnector_50c!= _publishConnector_506.end(); ++itProperty_503, ++itPublishConnector_50c)
	{
		if( ( *itProperty_503== property_501)&& ( *itPublishConnector_50c== publishConnector_50a))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_property_4fd.push_back( property_501);
		_publishConnector_506.push_back( publishConnector_50a);
	}
	return isUnique;
}

bool RequirementExists_4f2::isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& Property, const Udm::Object& PublishConnector, const Udm::Object& Requirement)
{
	bool Gz_guard= false;
	string pReqName;  Requirement.GetStrValue("name", pReqName); if (pReqName!="CadenaProperties") return false; else return true;;
	return Gz_guard;
}

void RequirementExists_4f2::processInputPackets( const Packets_t& propertys_4f3, const Packets_t& publishConnectors_4f6)
{
	for( Packets_t::const_iterator itProperty_4fe= propertys_4f3.begin(), itPublishConnector_507= publishConnectors_4f6.begin(); itProperty_4fe!= propertys_4f3.end(), itPublishConnector_507!= publishConnectors_4f6.end(); ++itProperty_4fe, ++itPublishConnector_507)
	{
		bool isUnique= isInputUnique( *itProperty_4fe, *itPublishConnector_507);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itProperty_4fe, *itPublishConnector_507);
	}
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.property_513, currMatch.publishConnector_515, currMatch.requirement_516);
	}
}

bool RequirementExists_4f2::patternMatcher( const Udm::Object& property_4ff, const Udm::Object& publishConnector_508)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( property_4ff.type(), cadena_scenario::Property::meta))
			continue;
		cadena_scenario::Property property_504= cadena_scenario::Property::Cast( property_4ff);
		if( false== Uml::IsDerivedFrom( publishConnector_508.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_50d= PICML::PublishConnector::Cast( publishConnector_508);
		set< PICML::AssemblyDeployRequirement> assemblyDeployRequirements_50f= publishConnector_50d.dstAssemblyDeployRequirement();
		for( set< PICML::AssemblyDeployRequirement>::const_iterator itAssemblyDeployRequirements_510= assemblyDeployRequirements_50f.begin(); itAssemblyDeployRequirements_510!= assemblyDeployRequirements_50f.end(); ++itAssemblyDeployRequirements_510)
		{
			PICML::AssemblyDeployRequirement currAssemblyDeployRequirement_511= *itAssemblyDeployRequirements_510;
			PICML::Requirement requirement_512= currAssemblyDeployRequirement_511.dstAssemblyDeployRequirement_end();
			Match currMatch;
			currMatch.property_513= property_504;
			currMatch.assemblyDeployRequirement_514= currAssemblyDeployRequirement_511;
			currMatch.publishConnector_515= publishConnector_50d;
			currMatch.requirement_516= requirement_512;
			bool Gz_guard= isGuardTrue( currMatch.assemblyDeployRequirement_514, currMatch.property_513, currMatch.publishConnector_515, currMatch.requirement_516);
			if( true== Gz_guard)
				_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void RequirementExists_4f2::outputAppender( const cadena_scenario::Property& property_51b, const PICML::PublishConnector& publishConnector_51d, const PICML::Requirement& requirement_51f)
{
	_property_4fa->push_back( property_51b);
	_publishConnector_4fb->push_back( publishConnector_51d);
	_requirement_4fc->push_back( requirement_51f);
}

bool RequirementDoesNotExist_521::operator()( const Packets_t& publishConnectors_522, const Packets_t& propertys_525, Packets_t& publishConnectors_524, Packets_t& propertys_527)
{
#ifdef PRINT_INFO
	std::cout << "RequirementDoesNotExist_521" << std::endl;
#endif
	_publishConnector_528= &publishConnectors_524;
	_property_529= &propertys_527;
	processInputPackets( publishConnectors_522, propertys_525);
	if( false== _matches.empty())
		return true;
	return false;
}

bool RequirementDoesNotExist_521::isInputUnique( const Udm::Object& publishConnector_52e, const Udm::Object& property_537)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPublishConnector_530= _publishConnector_52a.begin(), itProperty_539= _property_533.begin(); itPublishConnector_530!= _publishConnector_52a.end(), itProperty_539!= _property_533.end(); ++itPublishConnector_530, ++itProperty_539)
	{
		if( ( *itPublishConnector_530== publishConnector_52e)&& ( *itProperty_539== property_537))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_publishConnector_52a.push_back( publishConnector_52e);
		_property_533.push_back( property_537);
	}
	return isUnique;
}

void RequirementDoesNotExist_521::processInputPackets( const Packets_t& publishConnectors_522, const Packets_t& propertys_525)
{
	for( Packets_t::const_iterator itPublishConnector_52b= publishConnectors_522.begin(), itProperty_534= propertys_525.begin(); itPublishConnector_52b!= publishConnectors_522.end(), itProperty_534!= propertys_525.end(); ++itPublishConnector_52b, ++itProperty_534)
	{
		bool isUnique= isInputUnique( *itPublishConnector_52b, *itProperty_534);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPublishConnector_52b, *itProperty_534);
	}
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.publishConnector_53c, currMatch.property_53d);
	}
}

bool RequirementDoesNotExist_521::patternMatcher( const Udm::Object& publishConnector_52c, const Udm::Object& property_535)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( publishConnector_52c.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_531= PICML::PublishConnector::Cast( publishConnector_52c);
		if( false== Uml::IsDerivedFrom( property_535.type(), cadena_scenario::Property::meta))
			continue;
		cadena_scenario::Property property_53a= cadena_scenario::Property::Cast( property_535);
		Match currMatch;
		currMatch.publishConnector_53c= publishConnector_531;
		currMatch.property_53d= property_53a;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void RequirementDoesNotExist_521::outputAppender( const PICML::PublishConnector& publishConnector_53e, const cadena_scenario::Property& property_540)
{
	_publishConnector_528->push_back( publishConnector_53e);
	_property_529->push_back( property_540);
}

void Create_CadenaProperties_Requirement_542::operator()( const Packets_t& propertys_543, const Packets_t& publishConnectors_547, Packets_t& propertys_545, Packets_t& requirements_546, Packets_t& publishConnectors_549)
{
#ifdef PRINT_INFO
	std::cout << "Create_CadenaProperties_Requirement_542" << std::endl;
#endif
	_property_54a= &propertys_545;
	_requirement_54b= &requirements_546;
	_publishConnector_54c= &publishConnectors_549;
	processInputPackets( propertys_543, publishConnectors_547);
}

bool Create_CadenaProperties_Requirement_542::isInputUnique( const Udm::Object& property_551, const Udm::Object& publishConnector_55a)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itProperty_553= _property_54d.begin(), itPublishConnector_55c= _publishConnector_556.begin(); itProperty_553!= _property_54d.end(), itPublishConnector_55c!= _publishConnector_556.end(); ++itProperty_553, ++itPublishConnector_55c)
	{
		if( ( *itProperty_553== property_551)&& ( *itPublishConnector_55c== publishConnector_55a))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_property_54d.push_back( property_551);
		_publishConnector_556.push_back( publishConnector_55a);
	}
	return isUnique;
}

void Create_CadenaProperties_Requirement_542::processInputPackets( const Packets_t& propertys_543, const Packets_t& publishConnectors_547)
{
	for( Packets_t::const_iterator itProperty_54e= propertys_543.begin(), itPublishConnector_557= publishConnectors_547.begin(); itProperty_54e!= propertys_543.end(), itPublishConnector_557!= publishConnectors_547.end(); ++itProperty_54e, ++itPublishConnector_557)
	{
		bool isUnique= isInputUnique( *itProperty_54e, *itPublishConnector_557);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itProperty_54e, *itPublishConnector_557);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Create_CadenaProperties_Requirement_542::patternMatcher( const Udm::Object& property_54f, const Udm::Object& publishConnector_558)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( property_54f.type(), cadena_scenario::Property::meta))
			continue;
		cadena_scenario::Property property_554= cadena_scenario::Property::Cast( property_54f);
		if( false== Uml::IsDerivedFrom( publishConnector_558.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_55d= PICML::PublishConnector::Cast( publishConnector_558);
		Udm::Object publishConnectorParent_55f= publishConnector_55d.container();
		if( false== Uml::IsDerivedFrom( publishConnectorParent_55f.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssemblyPublishConnector_560= PICML::ComponentAssembly::Cast( publishConnectorParent_55f);
		Match currMatch;
		currMatch.componentAssembly_561= componentAssemblyPublishConnector_560;
		currMatch.property_562= property_554;
		currMatch.publishConnector_563= publishConnector_55d;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void Create_CadenaProperties_Requirement_542::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::Requirement newRequirement_564= PICML::Requirement::Create( currMatch.componentAssembly_561);
		PICML::AssemblyDeployRequirement newAssemblyDeployRequirement_565= PICML::AssemblyDeployRequirement::Create( currMatch.componentAssembly_561);
		Udm::Object& AssemblyDeployRequirement= newAssemblyDeployRequirement_565;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_561;
		Udm::Object& Property= currMatch.property_562;
		Udm::Object& PublishConnector= currMatch.publishConnector_563;
		Udm::Object& Requirement= newRequirement_564;
		{Requirement.SetStrValue("name", "CadenaProperties"); };
		newAssemblyDeployRequirement_565.srcAssemblyDeployRequirement_end()= currMatch.publishConnector_563;
		newAssemblyDeployRequirement_565.dstAssemblyDeployRequirement_end()= newRequirement_564;
		outputAppender( currMatch.property_562, newRequirement_564, currMatch.publishConnector_563);
	}
}

void Create_CadenaProperties_Requirement_542::outputAppender( const cadena_scenario::Property& property_566, const PICML::Requirement& requirement_568, const PICML::PublishConnector& publishConnector_56a)
{
	_property_54a->push_back( property_566);
	_requirement_54b->push_back( requirement_568);
	_publishConnector_54c->push_back( publishConnector_56a);
}

void PublishConnectorProperty_Find_Unmatched_572::operator()( const Packets_t& scenarios_574, Packets_t& cPropertys_573, Packets_t& publishConnectors_576)
{
#ifdef PRINT_INFO
	std::cout << "PublishConnectorProperty_Find_Unmatched_572" << std::endl;
#endif
	_cProperty_577= &cPropertys_573;
	_publishConnector_578= &publishConnectors_576;
	processInputPackets( scenarios_574);
}

bool PublishConnectorProperty_Find_Unmatched_572::isInputUnique( const Udm::Object& scenario_57d)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_57f= _scenario_579.begin(); itScenario_57f!= _scenario_579.end(); ++itScenario_57f)
	{
		if( ( *itScenario_57f== scenario_57d))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_579.push_back( scenario_57d);
	return isUnique;
}

void PublishConnectorProperty_Find_Unmatched_572::processInputPackets( const Packets_t& scenarios_574)
{
	for( Packets_t::const_iterator itScenario_57a= scenarios_574.begin(); itScenario_57a!= scenarios_574.end(); ++itScenario_57a)
	{
		bool isUnique= isInputUnique( *itScenario_57a);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_57a);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool PublishConnectorProperty_Find_Unmatched_572::patternMatcher( const Udm::Object& scenario_57b)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_57b.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_580= cadena_scenario::Scenario::Cast( scenario_57b);
		set< cadena_scenario::ESSConnection> eSSConnections_582= scenario_580.ESSConnection_kind_children();
		for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnection_583= eSSConnections_582.begin(); itESSConnection_583!= eSSConnections_582.end(); ++itESSConnection_583)
		{
			cadena_scenario::ESSConnection currESSConnection_584= *itESSConnection_583;
			set< cadena_scenario::Property> cPropertys_585= currESSConnection_584.Property_kind_children();
			for( set< cadena_scenario::Property>::const_iterator itCProperty_586= cPropertys_585.begin(); itCProperty_586!= cPropertys_585.end(); ++itCProperty_586)
			{
				cadena_scenario::Property currCProperty_587= *itCProperty_586;
				set< PICML::PublishConnector> publishConnectors_588= currESSConnection_584.picmlPublishConnector();
				for( set< PICML::PublishConnector>::const_iterator itPublishConnectors_589= publishConnectors_588.begin(); itPublishConnectors_589!= publishConnectors_588.end(); ++itPublishConnectors_589)
				{
					PICML::PublishConnector currPublishConnector_58a= *itPublishConnectors_589;
					PICML::Property pProperty_58b= currCProperty_587.picmlProperty();
					if( !pProperty_58b)
						continue;
					Match currMatch;
					currMatch.pProperty_58c= pProperty_58b;
					currMatch.eSSConnection_58d= currESSConnection_584;
					currMatch.cProperty_58e= currCProperty_587;
					currMatch.scenario_58f= scenario_580;
					currMatch.publishConnector_590= currPublishConnector_58a;
					_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void PublishConnectorProperty_Find_Unmatched_572::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.cProperty_58e, currMatch.publishConnector_590);
	}
}

void PublishConnectorProperty_Find_Unmatched_572::outputAppender( const cadena_scenario::Property& cProperty_591, const PICML::PublishConnector& publishConnector_593)
{
	_cProperty_577->push_back( cProperty_591);
	_publishConnector_578->push_back( publishConnector_593);
}

void Create_PublishConnectorProperty_595::operator()( const Packets_t& cPropertys_596, const Packets_t& requirements_598)
{
#ifdef PRINT_INFO
	std::cout << "Create_PublishConnectorProperty_595" << std::endl;
#endif
	processInputPackets( cPropertys_596, requirements_598);
}

bool Create_PublishConnectorProperty_595::isInputUnique( const Udm::Object& cProperty_59e, const Udm::Object& requirement_5a7)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itCProperty_5a0= _cProperty_59a.begin(), itRequirement_5a9= _requirement_5a3.begin(); itCProperty_5a0!= _cProperty_59a.end(), itRequirement_5a9!= _requirement_5a3.end(); ++itCProperty_5a0, ++itRequirement_5a9)
	{
		if( ( *itCProperty_5a0== cProperty_59e)&& ( *itRequirement_5a9== requirement_5a7))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_cProperty_59a.push_back( cProperty_59e);
		_requirement_5a3.push_back( requirement_5a7);
	}
	return isUnique;
}

void Create_PublishConnectorProperty_595::processInputPackets( const Packets_t& cPropertys_596, const Packets_t& requirements_598)
{
	for( Packets_t::const_iterator itCProperty_59b= cPropertys_596.begin(), itRequirement_5a4= requirements_598.begin(); itCProperty_59b!= cPropertys_596.end(), itRequirement_5a4!= requirements_598.end(); ++itCProperty_59b, ++itRequirement_5a4)
	{
		bool isUnique= isInputUnique( *itCProperty_59b, *itRequirement_5a4);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itCProperty_59b, *itRequirement_5a4);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Create_PublishConnectorProperty_595::patternMatcher( const Udm::Object& cProperty_59c, const Udm::Object& requirement_5a5)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( cProperty_59c.type(), cadena_scenario::Property::meta))
			continue;
		cadena_scenario::Property cProperty_5a1= cadena_scenario::Property::Cast( cProperty_59c);
		if( false== Uml::IsDerivedFrom( requirement_5a5.type(), PICML::Requirement::meta))
			continue;
		PICML::Requirement requirement_5aa= PICML::Requirement::Cast( requirement_5a5);
		set< PICML::Property> pPropertys_5ac= requirement_5aa.Property_kind_children();
		for( set< PICML::Property>::const_iterator itPProperty_5ad= pPropertys_5ac.begin(); itPProperty_5ad!= pPropertys_5ac.end(); ++itPProperty_5ad)
		{
			PICML::Property currPProperty_5ae= *itPProperty_5ad;
			Match currMatch;
			currMatch.cProperty_5af= cProperty_5a1;
			currMatch.pProperty_5b0= currPProperty_5ae;
			currMatch.requirement_5b1= requirement_5aa;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Create_PublishConnectorProperty_595::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& CProperty= currMatch.cProperty_5af;
		Udm::Object& PProperty= currMatch.pProperty_5b0;
		Udm::Object& Requirement= currMatch.requirement_5b1;
		{string cPropertyName; CProperty.GetStrValue("name", cPropertyName); PProperty.SetStrValue("name", cPropertyName);};
		currMatch.pProperty_5b0.cadenaProperty()= currMatch.cProperty_5af;
		outputAppender( );
	}
}

void Create_PublishConnectorProperty_595::outputAppender()
{
}

void ComponentProperties_Create_5b2::operator()( const Packets_t& scenarios_5b3)
{
#ifdef PRINT_INFO
	std::cout << "ComponentProperties_Create_5b2" << std::endl;
#endif
	processInputPackets( scenarios_5b3);
}

bool ComponentProperties_Create_5b2::isInputUnique( const Udm::Object& scenario_5b9)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_5bb= _scenario_5b5.begin(); itScenario_5bb!= _scenario_5b5.end(); ++itScenario_5bb)
	{
		if( ( *itScenario_5bb== scenario_5b9))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_5b5.push_back( scenario_5b9);
	return isUnique;
}

void ComponentProperties_Create_5b2::processInputPackets( const Packets_t& scenarios_5b3)
{
	for( Packets_t::const_iterator itScenario_5b6= scenarios_5b3.begin(); itScenario_5b6!= scenarios_5b3.end(); ++itScenario_5b6)
	{
		bool isUnique= isInputUnique( *itScenario_5b6);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_5b6);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool ComponentProperties_Create_5b2::patternMatcher( const Udm::Object& scenario_5b7)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_5b7.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_5bc= cadena_scenario::Scenario::Cast( scenario_5b7);
		set< cadena_scenario::ComponentInstance> componentInstances_5be= scenario_5bc.ComponentInstance_kind_children();
		for( set< cadena_scenario::ComponentInstance>::const_iterator itComponentInstance_5bf= componentInstances_5be.begin(); itComponentInstance_5bf!= componentInstances_5be.end(); ++itComponentInstance_5bf)
		{
			cadena_scenario::ComponentInstance currComponentInstance_5c0= *itComponentInstance_5bf;
			set< cadena_scenario::Property> cPropertys_5c1= currComponentInstance_5c0.Property_kind_children();
			for( set< cadena_scenario::Property>::const_iterator itCProperty_5c2= cPropertys_5c1.begin(); itCProperty_5c2!= cPropertys_5c1.end(); ++itCProperty_5c2)
			{
				cadena_scenario::Property currCProperty_5c3= *itCProperty_5c2;
				PICML::Property pProperty1_5c4= currCProperty_5c3.picmlProperty();
				if( !pProperty1_5c4)
					continue;
				PICML::Component component_5c5= currComponentInstance_5c0.picmlComponentDef();
				if( !component_5c5)
					continue;
				Udm::Object componentParent_5c6= component_5c5.container();
				if( false== Uml::IsDerivedFrom( componentParent_5c6.type(), PICML::ComponentAssembly::meta))
					continue;
				PICML::ComponentAssembly componentAssemblyComponent_5c7= PICML::ComponentAssembly::Cast( componentParent_5c6);
				Match currMatch;
				currMatch.componentAssembly_5c8= componentAssemblyComponent_5c7;
				currMatch.scenario_5c9= scenario_5bc;
				currMatch.componentInstance_5ca= currComponentInstance_5c0;
				currMatch.cProperty_5cb= currCProperty_5c3;
				currMatch.component_5cc= component_5c5;
				currMatch.pProperty1_5cd= pProperty1_5c4;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void ComponentProperties_Create_5b2::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::AssemblyConfigProperty newAssemblyConfigProperty_5ce= PICML::AssemblyConfigProperty::Create( currMatch.componentAssembly_5c8);
		PICML::Property newPProperty2_5cf= PICML::Property::Create( currMatch.componentAssembly_5c8);
		Udm::Object& AssemblyConfigProperty= newAssemblyConfigProperty_5ce;
		Udm::Object& CProperty= currMatch.cProperty_5cb;
		Udm::Object& Component= currMatch.component_5cc;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_5c8;
		Udm::Object& ComponentInstance= currMatch.componentInstance_5ca;
		Udm::Object& PProperty1= currMatch.pProperty1_5cd;
		Udm::Object& PProperty2= newPProperty2_5cf;
		Udm::Object& Scenario= currMatch.scenario_5c9;
		{string cPropertyName; CProperty.GetStrValue("name", cPropertyName); PProperty2.SetStrValue("name", cPropertyName);};
		currMatch.cProperty_5cb.picmlProperty()= newPProperty2_5cf;
		newAssemblyConfigProperty_5ce.srcAssemblyConfigProperty_end()= currMatch.component_5cc;
		newAssemblyConfigProperty_5ce.dstAssemblyConfigProperty_end()= newPProperty2_5cf;
		outputAppender( );
	}
}

void ComponentProperties_Create_5b2::outputAppender()
{
}

void DestroyProperties_5da::operator()( const Packets_t& pAssemblys_5db, const Packets_t& cScenarios_5dd, Packets_t& pAssemblys_5df, Packets_t& cScenarios_5e0)
{
#ifdef PRINT_INFO
	std::cout << "DestroyProperties_5da" << std::endl;
#endif
	_pAssembly_5e1= &pAssemblys_5df;
	_cScenario_5e2= &cScenarios_5e0;
	if( ( !pAssemblys_5db.empty()))
		callDestroyComponentProperties_691( pAssemblys_5db);
	if( ( !pAssemblys_5db.empty()))
		callDestroyCadenaEIProperties_693( pAssemblys_5db);
	if( ( !pAssemblys_5db.empty()))
		callDestroyPublishConnectorProperties_695( pAssemblys_5db);
	_pAssembly_5e1->insert( _pAssembly_5e1->end(), pAssemblys_5db.begin(), pAssemblys_5db.end());
	_cScenario_5e2->insert( _cScenario_5e2->end(), cScenarios_5dd.begin(), cScenarios_5dd.end());
}

void DestroyProperties_5da::callDestroyComponentProperties_691( const Packets_t& componentAssemblys_5e4)
{
	DestroyComponentProperties_5e3 destroyComponentProperties_5e3;
	destroyComponentProperties_5e3( componentAssemblys_5e4);
}

void DestroyProperties_5da::callDestroyCadenaEIProperties_693( const Packets_t& componentAssemblys_620)
{
	DestroyCadenaEIProperties_61f destroyCadenaEIProperties_61f;
	destroyCadenaEIProperties_61f( componentAssemblys_620);
}

void DestroyProperties_5da::callDestroyPublishConnectorProperties_695( const Packets_t& componentAssemblys_651)
{
	DestroyPublishConnectorProperties_650 destroyPublishConnectorProperties_650;
	destroyPublishConnectorProperties_650( componentAssemblys_651);
}

void DestroyComponentProperties_5e3::operator()( const Packets_t& componentAssemblys_5e4)
{
#ifdef PRINT_INFO
	std::cout << "DestroyComponentProperties_5e3" << std::endl;
#endif
	processInputPackets( componentAssemblys_5e4);
}

bool DestroyComponentProperties_5e3::isInputUnique( const Udm::Object& componentAssembly_5ea)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_5ec= _componentAssembly_5e6.begin(); itComponentAssembly_5ec!= _componentAssembly_5e6.end(); ++itComponentAssembly_5ec)
	{
		if( ( *itComponentAssembly_5ec== componentAssembly_5ea))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_componentAssembly_5e6.push_back( componentAssembly_5ea);
	return isUnique;
}

bool DestroyComponentProperties_5e3::isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& CProperty, const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& DataType, const Udm::Object& PProperty, const Udm::Object& PredefinedType)
{
	bool Gz_guard= false;
	string propType; PredefinedType.type().GetStrValue("name", propType); if (propType!="LongInteger" && propType!="String" && propType!="Boolean") return false; else return true;;
	return Gz_guard;
}

void DestroyComponentProperties_5e3::processInputPackets( const Packets_t& componentAssemblys_5e4)
{
	for( Packets_t::const_iterator itComponentAssembly_5e7= componentAssemblys_5e4.begin(); itComponentAssembly_5e7!= componentAssemblys_5e4.end(); ++itComponentAssembly_5e7)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_5e7);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_5e7);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool DestroyComponentProperties_5e3::patternMatcher( const Udm::Object& componentAssembly_5e8)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_5e8.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_5ed= PICML::ComponentAssembly::Cast( componentAssembly_5e8);
		set< PICML::Component> components_5ef= componentAssembly_5ed.Component_kind_children();
		for( set< PICML::Component>::const_iterator itComponent_5f0= components_5ef.begin(); itComponent_5f0!= components_5ef.end(); ++itComponent_5f0)
		{
			PICML::Component currComponent_5f1= *itComponent_5f0;
			set< PICML::AssemblyConfigProperty> assemblyConfigPropertys_5f2= currComponent_5f1.dstAssemblyConfigProperty();
			for( set< PICML::AssemblyConfigProperty>::const_iterator itAssemblyConfigPropertys_5f3= assemblyConfigPropertys_5f2.begin(); itAssemblyConfigPropertys_5f3!= assemblyConfigPropertys_5f2.end(); ++itAssemblyConfigPropertys_5f3)
			{
				PICML::AssemblyConfigProperty currAssemblyConfigProperty_5f4= *itAssemblyConfigPropertys_5f3;
				PICML::Property pProperty_5f5= currAssemblyConfigProperty_5f4.dstAssemblyConfigProperty_end();
				set< PICML::DataType> dataTypes_5f6= pProperty_5f5.DataType_kind_children();
				for( set< PICML::DataType>::const_iterator itDataType_5f7= dataTypes_5f6.begin(); itDataType_5f7!= dataTypes_5f6.end(); ++itDataType_5f7)
				{
					PICML::DataType currDataType_5f8= *itDataType_5f7;
					PICML::PredefinedType predefinedType_5f9= currDataType_5f8.ref();
					if( !predefinedType_5f9)
						continue;
					cadena_scenario::Property cProperty_5fa= pProperty_5f5.cadenaProperty();
					if( !cProperty_5fa)
						continue;
					Match currMatch;
					currMatch.dataType_5fb= currDataType_5f8;
					currMatch.predefinedType_5fc= predefinedType_5f9;
					currMatch.pProperty_5fd= pProperty_5f5;
					currMatch.cProperty_5fe= cProperty_5fa;
					currMatch.component_5ff= currComponent_5f1;
					currMatch.componentAssembly_600= componentAssembly_5ed;
					currMatch.assemblyConfigProperty_601= currAssemblyConfigProperty_5f4;
					bool Gz_guard= isGuardTrue( currMatch.assemblyConfigProperty_601, currMatch.cProperty_5fe, currMatch.component_5ff, currMatch.componentAssembly_600, currMatch.dataType_5fb, currMatch.pProperty_5fd, currMatch.predefinedType_5fc);
					if( true== Gz_guard)
						_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void DestroyComponentProperties_5e3::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& AssemblyConfigProperty= currMatch.assemblyConfigProperty_601;
		Udm::Object& CProperty= currMatch.cProperty_5fe;
		Udm::Object& Component= currMatch.component_5ff;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_600;
		Udm::Object& DataType= currMatch.dataType_5fb;
		Udm::Object& PProperty= currMatch.pProperty_5fd;
		Udm::Object& PredefinedType= currMatch.predefinedType_5fc;
		{/*Workaround: needed because deleting Property from the GReAT model causes an object partially inaccessible exception*/ /*PProperty.DeleteObject();*/};
		currMatch.dataType_5fb.ref()= Udm::null;
		currMatch.pProperty_5fd.cadenaProperty()= Udm::null;
		if( currMatch.dataType_5fb)
			currMatch.dataType_5fb.DeleteObject();
		set< PICML::InfoProperty> delInfoPropertys_609= currMatch.pProperty_5fd.srcInfoProperty();
		for( set< PICML::InfoProperty>::const_iterator itdelInfoPropertys_609= delInfoPropertys_609.begin(); itdelInfoPropertys_609!= delInfoPropertys_609.end(); ++itdelInfoPropertys_609)
		{
			PICML::InfoProperty currInfoProperty_60a= *itdelInfoPropertys_609;
			if( currInfoProperty_60a)
				currInfoProperty_60a.DeleteObject();
		}
		set< PICML::ConfigProperty> delConfigPropertys_60b= currMatch.pProperty_5fd.srcConfigProperty();
		for( set< PICML::ConfigProperty>::const_iterator itdelConfigPropertys_60b= delConfigPropertys_60b.begin(); itdelConfigPropertys_60b!= delConfigPropertys_60b.end(); ++itdelConfigPropertys_60b)
		{
			PICML::ConfigProperty currConfigProperty_60c= *itdelConfigPropertys_60b;
			if( currConfigProperty_60c)
				currConfigProperty_60c.DeleteObject();
		}
		set< PICML::AssemblyConfigProperty> delAssemblyConfigPropertys_60d= currMatch.pProperty_5fd.srcAssemblyConfigProperty();
		for( set< PICML::AssemblyConfigProperty>::const_iterator itdelAssemblyConfigPropertys_60d= delAssemblyConfigPropertys_60d.begin(); itdelAssemblyConfigPropertys_60d!= delAssemblyConfigPropertys_60d.end(); ++itdelAssemblyConfigPropertys_60d)
		{
			PICML::AssemblyConfigProperty currAssemblyConfigProperty_60e= *itdelAssemblyConfigPropertys_60d;
			if( currAssemblyConfigProperty_60e)
				currAssemblyConfigProperty_60e.DeleteObject();
		}
		set< PICML::PackageConfigProperty> delPackageConfigPropertys_60f= currMatch.pProperty_5fd.srcPackageConfigProperty();
		for( set< PICML::PackageConfigProperty>::const_iterator itdelPackageConfigPropertys_60f= delPackageConfigPropertys_60f.begin(); itdelPackageConfigPropertys_60f!= delPackageConfigPropertys_60f.end(); ++itdelPackageConfigPropertys_60f)
		{
			PICML::PackageConfigProperty currPackageConfigProperty_610= *itdelPackageConfigPropertys_60f;
			if( currPackageConfigProperty_610)
				currPackageConfigProperty_610.DeleteObject();
		}
		set< PICML::PackageInfoProperty> delPackageInfoPropertys_611= currMatch.pProperty_5fd.srcPackageInfoProperty();
		for( set< PICML::PackageInfoProperty>::const_iterator itdelPackageInfoPropertys_611= delPackageInfoPropertys_611.begin(); itdelPackageInfoPropertys_611!= delPackageInfoPropertys_611.end(); ++itdelPackageInfoPropertys_611)
		{
			PICML::PackageInfoProperty currPackageInfoProperty_612= *itdelPackageInfoPropertys_611;
			if( currPackageInfoProperty_612)
				currPackageInfoProperty_612.DeleteObject();
		}
		set< PICML::MonolithExecParameter> delMonolithExecParameters_613= currMatch.pProperty_5fd.srcMonolithExecParameter();
		for( set< PICML::MonolithExecParameter>::const_iterator itdelMonolithExecParameters_613= delMonolithExecParameters_613.begin(); itdelMonolithExecParameters_613!= delMonolithExecParameters_613.end(); ++itdelMonolithExecParameters_613)
		{
			PICML::MonolithExecParameter currMonolithExecParameter_614= *itdelMonolithExecParameters_613;
			if( currMonolithExecParameter_614)
				currMonolithExecParameter_614.DeleteObject();
		}
		set< PICML::ComponentConfigProperty> delComponentConfigPropertys_615= currMatch.pProperty_5fd.srcComponentConfigProperty();
		for( set< PICML::ComponentConfigProperty>::const_iterator itdelComponentConfigPropertys_615= delComponentConfigPropertys_615.begin(); itdelComponentConfigPropertys_615!= delComponentConfigPropertys_615.end(); ++itdelComponentConfigPropertys_615)
		{
			PICML::ComponentConfigProperty currComponentConfigProperty_616= *itdelComponentConfigPropertys_615;
			if( currComponentConfigProperty_616)
				currComponentConfigProperty_616.DeleteObject();
		}
		set< PICML::ComponentInfoProperty> delComponentInfoPropertys_617= currMatch.pProperty_5fd.srcComponentInfoProperty();
		for( set< PICML::ComponentInfoProperty>::const_iterator itdelComponentInfoPropertys_617= delComponentInfoPropertys_617.begin(); itdelComponentInfoPropertys_617!= delComponentInfoPropertys_617.end(); ++itdelComponentInfoPropertys_617)
		{
			PICML::ComponentInfoProperty currComponentInfoProperty_618= *itdelComponentInfoPropertys_617;
			if( currComponentInfoProperty_618)
				currComponentInfoProperty_618.DeleteObject();
		}
		set< PICML::PackageConfConfigProperty> delPackageConfConfigPropertys_619= currMatch.pProperty_5fd.srcPackageConfConfigProperty();
		for( set< PICML::PackageConfConfigProperty>::const_iterator itdelPackageConfConfigPropertys_619= delPackageConfConfigPropertys_619.begin(); itdelPackageConfConfigPropertys_619!= delPackageConfConfigPropertys_619.end(); ++itdelPackageConfConfigPropertys_619)
		{
			PICML::PackageConfConfigProperty currPackageConfConfigProperty_61a= *itdelPackageConfConfigPropertys_619;
			if( currPackageConfConfigProperty_61a)
				currPackageConfConfigProperty_61a.DeleteObject();
		}
		set< PICML::ArtifactInfoProperty> delArtifactInfoPropertys_61b= currMatch.pProperty_5fd.srcArtifactInfoProperty();
		for( set< PICML::ArtifactInfoProperty>::const_iterator itdelArtifactInfoPropertys_61b= delArtifactInfoPropertys_61b.begin(); itdelArtifactInfoPropertys_61b!= delArtifactInfoPropertys_61b.end(); ++itdelArtifactInfoPropertys_61b)
		{
			PICML::ArtifactInfoProperty currArtifactInfoProperty_61c= *itdelArtifactInfoPropertys_61b;
			if( currArtifactInfoProperty_61c)
				currArtifactInfoProperty_61c.DeleteObject();
		}
		set< PICML::ArtifactExecParameter> delArtifactExecParameters_61d= currMatch.pProperty_5fd.srcArtifactExecParameter();
		for( set< PICML::ArtifactExecParameter>::const_iterator itdelArtifactExecParameters_61d= delArtifactExecParameters_61d.begin(); itdelArtifactExecParameters_61d!= delArtifactExecParameters_61d.end(); ++itdelArtifactExecParameters_61d)
		{
			PICML::ArtifactExecParameter currArtifactExecParameter_61e= *itdelArtifactExecParameters_61d;
			if( currArtifactExecParameter_61e)
				currArtifactExecParameter_61e.DeleteObject();
		}
		if( currMatch.pProperty_5fd)
			currMatch.pProperty_5fd.DeleteObject();
		outputAppender( );
	}
}

void DestroyComponentProperties_5e3::outputAppender()
{
}

void DestroyCadenaEIProperties_61f::operator()( const Packets_t& componentAssemblys_620)
{
#ifdef PRINT_INFO
	std::cout << "DestroyCadenaEIProperties_61f" << std::endl;
#endif
	processInputPackets( componentAssemblys_620);
}

bool DestroyCadenaEIProperties_61f::isInputUnique( const Udm::Object& componentAssembly_626)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_628= _componentAssembly_622.begin(); itComponentAssembly_628!= _componentAssembly_622.end(); ++itComponentAssembly_628)
	{
		if( ( *itComponentAssembly_628== componentAssembly_626))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_componentAssembly_622.push_back( componentAssembly_626);
	return isUnique;
}

bool DestroyCadenaEIProperties_61f::isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& PProperty)
{
	bool Gz_guard= false;
	string pPropName; PProperty.GetStrValue("name", pPropName); return (pPropName=="CadenaEIProperties");;
	return Gz_guard;
}

void DestroyCadenaEIProperties_61f::processInputPackets( const Packets_t& componentAssemblys_620)
{
	for( Packets_t::const_iterator itComponentAssembly_623= componentAssemblys_620.begin(); itComponentAssembly_623!= componentAssemblys_620.end(); ++itComponentAssembly_623)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_623);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_623);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool DestroyCadenaEIProperties_61f::patternMatcher( const Udm::Object& componentAssembly_624)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_624.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_629= PICML::ComponentAssembly::Cast( componentAssembly_624);
		set< PICML::Component> components_62b= componentAssembly_629.Component_kind_children();
		for( set< PICML::Component>::const_iterator itComponent_62c= components_62b.begin(); itComponent_62c!= components_62b.end(); ++itComponent_62c)
		{
			PICML::Component currComponent_62d= *itComponent_62c;
			set< PICML::AssemblyConfigProperty> assemblyConfigPropertys_62e= currComponent_62d.dstAssemblyConfigProperty();
			for( set< PICML::AssemblyConfigProperty>::const_iterator itAssemblyConfigPropertys_62f= assemblyConfigPropertys_62e.begin(); itAssemblyConfigPropertys_62f!= assemblyConfigPropertys_62e.end(); ++itAssemblyConfigPropertys_62f)
			{
				PICML::AssemblyConfigProperty currAssemblyConfigProperty_630= *itAssemblyConfigPropertys_62f;
				PICML::Property pProperty_631= currAssemblyConfigProperty_630.dstAssemblyConfigProperty_end();
				Match currMatch;
				currMatch.pProperty_632= pProperty_631;
				currMatch.assemblyConfigProperty_633= currAssemblyConfigProperty_630;
				currMatch.componentAssembly_634= componentAssembly_629;
				currMatch.component_635= currComponent_62d;
				bool Gz_guard= isGuardTrue( currMatch.assemblyConfigProperty_633, currMatch.component_635, currMatch.componentAssembly_634, currMatch.pProperty_632);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void DestroyCadenaEIProperties_61f::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		set< PICML::InfoProperty> delInfoPropertys_63a= currMatch.pProperty_632.srcInfoProperty();
		for( set< PICML::InfoProperty>::const_iterator itdelInfoPropertys_63a= delInfoPropertys_63a.begin(); itdelInfoPropertys_63a!= delInfoPropertys_63a.end(); ++itdelInfoPropertys_63a)
		{
			PICML::InfoProperty currInfoProperty_63b= *itdelInfoPropertys_63a;
			if( currInfoProperty_63b)
				currInfoProperty_63b.DeleteObject();
		}
		set< PICML::ConfigProperty> delConfigPropertys_63c= currMatch.pProperty_632.srcConfigProperty();
		for( set< PICML::ConfigProperty>::const_iterator itdelConfigPropertys_63c= delConfigPropertys_63c.begin(); itdelConfigPropertys_63c!= delConfigPropertys_63c.end(); ++itdelConfigPropertys_63c)
		{
			PICML::ConfigProperty currConfigProperty_63d= *itdelConfigPropertys_63c;
			if( currConfigProperty_63d)
				currConfigProperty_63d.DeleteObject();
		}
		set< PICML::AssemblyConfigProperty> delAssemblyConfigPropertys_63e= currMatch.pProperty_632.srcAssemblyConfigProperty();
		for( set< PICML::AssemblyConfigProperty>::const_iterator itdelAssemblyConfigPropertys_63e= delAssemblyConfigPropertys_63e.begin(); itdelAssemblyConfigPropertys_63e!= delAssemblyConfigPropertys_63e.end(); ++itdelAssemblyConfigPropertys_63e)
		{
			PICML::AssemblyConfigProperty currAssemblyConfigProperty_63f= *itdelAssemblyConfigPropertys_63e;
			if( currAssemblyConfigProperty_63f)
				currAssemblyConfigProperty_63f.DeleteObject();
		}
		set< PICML::PackageConfigProperty> delPackageConfigPropertys_640= currMatch.pProperty_632.srcPackageConfigProperty();
		for( set< PICML::PackageConfigProperty>::const_iterator itdelPackageConfigPropertys_640= delPackageConfigPropertys_640.begin(); itdelPackageConfigPropertys_640!= delPackageConfigPropertys_640.end(); ++itdelPackageConfigPropertys_640)
		{
			PICML::PackageConfigProperty currPackageConfigProperty_641= *itdelPackageConfigPropertys_640;
			if( currPackageConfigProperty_641)
				currPackageConfigProperty_641.DeleteObject();
		}
		set< PICML::PackageInfoProperty> delPackageInfoPropertys_642= currMatch.pProperty_632.srcPackageInfoProperty();
		for( set< PICML::PackageInfoProperty>::const_iterator itdelPackageInfoPropertys_642= delPackageInfoPropertys_642.begin(); itdelPackageInfoPropertys_642!= delPackageInfoPropertys_642.end(); ++itdelPackageInfoPropertys_642)
		{
			PICML::PackageInfoProperty currPackageInfoProperty_643= *itdelPackageInfoPropertys_642;
			if( currPackageInfoProperty_643)
				currPackageInfoProperty_643.DeleteObject();
		}
		set< PICML::MonolithExecParameter> delMonolithExecParameters_644= currMatch.pProperty_632.srcMonolithExecParameter();
		for( set< PICML::MonolithExecParameter>::const_iterator itdelMonolithExecParameters_644= delMonolithExecParameters_644.begin(); itdelMonolithExecParameters_644!= delMonolithExecParameters_644.end(); ++itdelMonolithExecParameters_644)
		{
			PICML::MonolithExecParameter currMonolithExecParameter_645= *itdelMonolithExecParameters_644;
			if( currMonolithExecParameter_645)
				currMonolithExecParameter_645.DeleteObject();
		}
		set< PICML::ComponentConfigProperty> delComponentConfigPropertys_646= currMatch.pProperty_632.srcComponentConfigProperty();
		for( set< PICML::ComponentConfigProperty>::const_iterator itdelComponentConfigPropertys_646= delComponentConfigPropertys_646.begin(); itdelComponentConfigPropertys_646!= delComponentConfigPropertys_646.end(); ++itdelComponentConfigPropertys_646)
		{
			PICML::ComponentConfigProperty currComponentConfigProperty_647= *itdelComponentConfigPropertys_646;
			if( currComponentConfigProperty_647)
				currComponentConfigProperty_647.DeleteObject();
		}
		set< PICML::ComponentInfoProperty> delComponentInfoPropertys_648= currMatch.pProperty_632.srcComponentInfoProperty();
		for( set< PICML::ComponentInfoProperty>::const_iterator itdelComponentInfoPropertys_648= delComponentInfoPropertys_648.begin(); itdelComponentInfoPropertys_648!= delComponentInfoPropertys_648.end(); ++itdelComponentInfoPropertys_648)
		{
			PICML::ComponentInfoProperty currComponentInfoProperty_649= *itdelComponentInfoPropertys_648;
			if( currComponentInfoProperty_649)
				currComponentInfoProperty_649.DeleteObject();
		}
		set< PICML::PackageConfConfigProperty> delPackageConfConfigPropertys_64a= currMatch.pProperty_632.srcPackageConfConfigProperty();
		for( set< PICML::PackageConfConfigProperty>::const_iterator itdelPackageConfConfigPropertys_64a= delPackageConfConfigPropertys_64a.begin(); itdelPackageConfConfigPropertys_64a!= delPackageConfConfigPropertys_64a.end(); ++itdelPackageConfConfigPropertys_64a)
		{
			PICML::PackageConfConfigProperty currPackageConfConfigProperty_64b= *itdelPackageConfConfigPropertys_64a;
			if( currPackageConfConfigProperty_64b)
				currPackageConfConfigProperty_64b.DeleteObject();
		}
		set< PICML::ArtifactInfoProperty> delArtifactInfoPropertys_64c= currMatch.pProperty_632.srcArtifactInfoProperty();
		for( set< PICML::ArtifactInfoProperty>::const_iterator itdelArtifactInfoPropertys_64c= delArtifactInfoPropertys_64c.begin(); itdelArtifactInfoPropertys_64c!= delArtifactInfoPropertys_64c.end(); ++itdelArtifactInfoPropertys_64c)
		{
			PICML::ArtifactInfoProperty currArtifactInfoProperty_64d= *itdelArtifactInfoPropertys_64c;
			if( currArtifactInfoProperty_64d)
				currArtifactInfoProperty_64d.DeleteObject();
		}
		set< PICML::ArtifactExecParameter> delArtifactExecParameters_64e= currMatch.pProperty_632.srcArtifactExecParameter();
		for( set< PICML::ArtifactExecParameter>::const_iterator itdelArtifactExecParameters_64e= delArtifactExecParameters_64e.begin(); itdelArtifactExecParameters_64e!= delArtifactExecParameters_64e.end(); ++itdelArtifactExecParameters_64e)
		{
			PICML::ArtifactExecParameter currArtifactExecParameter_64f= *itdelArtifactExecParameters_64e;
			if( currArtifactExecParameter_64f)
				currArtifactExecParameter_64f.DeleteObject();
		}
		if( currMatch.pProperty_632)
			currMatch.pProperty_632.DeleteObject();
		outputAppender( );
	}
}

void DestroyCadenaEIProperties_61f::outputAppender()
{
}

void DestroyPublishConnectorProperties_650::operator()( const Packets_t& componentAssemblys_651)
{
#ifdef PRINT_INFO
	std::cout << "DestroyPublishConnectorProperties_650" << std::endl;
#endif
	processInputPackets( componentAssemblys_651);
}

bool DestroyPublishConnectorProperties_650::isInputUnique( const Udm::Object& componentAssembly_657)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_659= _componentAssembly_653.begin(); itComponentAssembly_659!= _componentAssembly_653.end(); ++itComponentAssembly_659)
	{
		if( ( *itComponentAssembly_659== componentAssembly_657))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_componentAssembly_653.push_back( componentAssembly_657);
	return isUnique;
}

bool DestroyPublishConnectorProperties_650::isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& CProperty, const Udm::Object& ComponentAssembly, const Udm::Object& DataType, const Udm::Object& PProperty, const Udm::Object& PredefinedType, const Udm::Object& PublishConnector, const Udm::Object& Requirement)
{
	bool Gz_guard= false;
	string pRequirementName, pPropType;  Requirement.GetStrValue("name", pRequirementName); if (pRequirementName!="CadenaProperties") return false;  PredefinedType.type().GetStrValue("name", pPropType); if (pPropType=="LongInteger" || pPropType=="String" || pPropType=="Boolean") return true; else return false;;
	return Gz_guard;
}

void DestroyPublishConnectorProperties_650::processInputPackets( const Packets_t& componentAssemblys_651)
{
	for( Packets_t::const_iterator itComponentAssembly_654= componentAssemblys_651.begin(); itComponentAssembly_654!= componentAssemblys_651.end(); ++itComponentAssembly_654)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_654);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_654);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool DestroyPublishConnectorProperties_650::patternMatcher( const Udm::Object& componentAssembly_655)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_655.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_65a= PICML::ComponentAssembly::Cast( componentAssembly_655);
		set< PICML::PublishConnector> publishConnectors_65c= componentAssembly_65a.PublishConnector_kind_children();
		for( set< PICML::PublishConnector>::const_iterator itPublishConnector_65d= publishConnectors_65c.begin(); itPublishConnector_65d!= publishConnectors_65c.end(); ++itPublishConnector_65d)
		{
			PICML::PublishConnector currPublishConnector_65e= *itPublishConnector_65d;
			set< PICML::AssemblyDeployRequirement> assemblyDeployRequirements_65f= currPublishConnector_65e.dstAssemblyDeployRequirement();
			for( set< PICML::AssemblyDeployRequirement>::const_iterator itAssemblyDeployRequirements_660= assemblyDeployRequirements_65f.begin(); itAssemblyDeployRequirements_660!= assemblyDeployRequirements_65f.end(); ++itAssemblyDeployRequirements_660)
			{
				PICML::AssemblyDeployRequirement currAssemblyDeployRequirement_661= *itAssemblyDeployRequirements_660;
				PICML::Requirement requirement_662= currAssemblyDeployRequirement_661.dstAssemblyDeployRequirement_end();
				set< PICML::Property> pPropertys_663= requirement_662.Property_kind_children();
				for( set< PICML::Property>::const_iterator itPProperty_664= pPropertys_663.begin(); itPProperty_664!= pPropertys_663.end(); ++itPProperty_664)
				{
					PICML::Property currPProperty_665= *itPProperty_664;
					set< PICML::DataType> dataTypes_666= currPProperty_665.DataType_kind_children();
					for( set< PICML::DataType>::const_iterator itDataType_667= dataTypes_666.begin(); itDataType_667!= dataTypes_666.end(); ++itDataType_667)
					{
						PICML::DataType currDataType_668= *itDataType_667;
						PICML::PredefinedType predefinedType_669= currDataType_668.ref();
						if( !predefinedType_669)
							continue;
						cadena_scenario::Property cProperty_66a= currPProperty_665.cadenaProperty();
						if( !cProperty_66a)
							continue;
						Match currMatch;
						currMatch.assemblyDeployRequirement_66b= currAssemblyDeployRequirement_661;
						currMatch.requirement_66c= requirement_662;
						currMatch.publishConnector_66d= currPublishConnector_65e;
						currMatch.predefinedType_66e= predefinedType_669;
						currMatch.dataType_66f= currDataType_668;
						currMatch.pProperty_670= currPProperty_665;
						currMatch.componentAssembly_671= componentAssembly_65a;
						currMatch.cProperty_672= cProperty_66a;
						bool Gz_guard= isGuardTrue( currMatch.assemblyDeployRequirement_66b, currMatch.cProperty_672, currMatch.componentAssembly_671, currMatch.dataType_66f, currMatch.pProperty_670, currMatch.predefinedType_66e, currMatch.publishConnector_66d, currMatch.requirement_66c);
						if( true== Gz_guard)
							_matches.push_back( currMatch);
					}
				}
			}
		}
	}
	return !_matches.empty();
}

void DestroyPublishConnectorProperties_650::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& AssemblyDeployRequirement= currMatch.assemblyDeployRequirement_66b;
		Udm::Object& CProperty= currMatch.cProperty_672;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_671;
		Udm::Object& DataType= currMatch.dataType_66f;
		Udm::Object& PProperty= currMatch.pProperty_670;
		Udm::Object& PredefinedType= currMatch.predefinedType_66e;
		Udm::Object& PublishConnector= currMatch.publishConnector_66d;
		Udm::Object& Requirement= currMatch.requirement_66c;
		{/*Workaround: needed because deleting Property from the GReAT model causes an object partially inaccessible exception*/ /*PProperty.DeleteObject();*/};
		currMatch.dataType_66f.ref()= Udm::null;
		currMatch.pProperty_670.cadenaProperty()= Udm::null;
		if( currMatch.dataType_66f)
			currMatch.dataType_66f.DeleteObject();
		set< PICML::InfoProperty> delInfoPropertys_67b= currMatch.pProperty_670.srcInfoProperty();
		for( set< PICML::InfoProperty>::const_iterator itdelInfoPropertys_67b= delInfoPropertys_67b.begin(); itdelInfoPropertys_67b!= delInfoPropertys_67b.end(); ++itdelInfoPropertys_67b)
		{
			PICML::InfoProperty currInfoProperty_67c= *itdelInfoPropertys_67b;
			if( currInfoProperty_67c)
				currInfoProperty_67c.DeleteObject();
		}
		set< PICML::ConfigProperty> delConfigPropertys_67d= currMatch.pProperty_670.srcConfigProperty();
		for( set< PICML::ConfigProperty>::const_iterator itdelConfigPropertys_67d= delConfigPropertys_67d.begin(); itdelConfigPropertys_67d!= delConfigPropertys_67d.end(); ++itdelConfigPropertys_67d)
		{
			PICML::ConfigProperty currConfigProperty_67e= *itdelConfigPropertys_67d;
			if( currConfigProperty_67e)
				currConfigProperty_67e.DeleteObject();
		}
		set< PICML::AssemblyConfigProperty> delAssemblyConfigPropertys_67f= currMatch.pProperty_670.srcAssemblyConfigProperty();
		for( set< PICML::AssemblyConfigProperty>::const_iterator itdelAssemblyConfigPropertys_67f= delAssemblyConfigPropertys_67f.begin(); itdelAssemblyConfigPropertys_67f!= delAssemblyConfigPropertys_67f.end(); ++itdelAssemblyConfigPropertys_67f)
		{
			PICML::AssemblyConfigProperty currAssemblyConfigProperty_680= *itdelAssemblyConfigPropertys_67f;
			if( currAssemblyConfigProperty_680)
				currAssemblyConfigProperty_680.DeleteObject();
		}
		set< PICML::PackageConfigProperty> delPackageConfigPropertys_681= currMatch.pProperty_670.srcPackageConfigProperty();
		for( set< PICML::PackageConfigProperty>::const_iterator itdelPackageConfigPropertys_681= delPackageConfigPropertys_681.begin(); itdelPackageConfigPropertys_681!= delPackageConfigPropertys_681.end(); ++itdelPackageConfigPropertys_681)
		{
			PICML::PackageConfigProperty currPackageConfigProperty_682= *itdelPackageConfigPropertys_681;
			if( currPackageConfigProperty_682)
				currPackageConfigProperty_682.DeleteObject();
		}
		set< PICML::PackageInfoProperty> delPackageInfoPropertys_683= currMatch.pProperty_670.srcPackageInfoProperty();
		for( set< PICML::PackageInfoProperty>::const_iterator itdelPackageInfoPropertys_683= delPackageInfoPropertys_683.begin(); itdelPackageInfoPropertys_683!= delPackageInfoPropertys_683.end(); ++itdelPackageInfoPropertys_683)
		{
			PICML::PackageInfoProperty currPackageInfoProperty_684= *itdelPackageInfoPropertys_683;
			if( currPackageInfoProperty_684)
				currPackageInfoProperty_684.DeleteObject();
		}
		set< PICML::MonolithExecParameter> delMonolithExecParameters_685= currMatch.pProperty_670.srcMonolithExecParameter();
		for( set< PICML::MonolithExecParameter>::const_iterator itdelMonolithExecParameters_685= delMonolithExecParameters_685.begin(); itdelMonolithExecParameters_685!= delMonolithExecParameters_685.end(); ++itdelMonolithExecParameters_685)
		{
			PICML::MonolithExecParameter currMonolithExecParameter_686= *itdelMonolithExecParameters_685;
			if( currMonolithExecParameter_686)
				currMonolithExecParameter_686.DeleteObject();
		}
		set< PICML::ComponentConfigProperty> delComponentConfigPropertys_687= currMatch.pProperty_670.srcComponentConfigProperty();
		for( set< PICML::ComponentConfigProperty>::const_iterator itdelComponentConfigPropertys_687= delComponentConfigPropertys_687.begin(); itdelComponentConfigPropertys_687!= delComponentConfigPropertys_687.end(); ++itdelComponentConfigPropertys_687)
		{
			PICML::ComponentConfigProperty currComponentConfigProperty_688= *itdelComponentConfigPropertys_687;
			if( currComponentConfigProperty_688)
				currComponentConfigProperty_688.DeleteObject();
		}
		set< PICML::ComponentInfoProperty> delComponentInfoPropertys_689= currMatch.pProperty_670.srcComponentInfoProperty();
		for( set< PICML::ComponentInfoProperty>::const_iterator itdelComponentInfoPropertys_689= delComponentInfoPropertys_689.begin(); itdelComponentInfoPropertys_689!= delComponentInfoPropertys_689.end(); ++itdelComponentInfoPropertys_689)
		{
			PICML::ComponentInfoProperty currComponentInfoProperty_68a= *itdelComponentInfoPropertys_689;
			if( currComponentInfoProperty_68a)
				currComponentInfoProperty_68a.DeleteObject();
		}
		set< PICML::PackageConfConfigProperty> delPackageConfConfigPropertys_68b= currMatch.pProperty_670.srcPackageConfConfigProperty();
		for( set< PICML::PackageConfConfigProperty>::const_iterator itdelPackageConfConfigPropertys_68b= delPackageConfConfigPropertys_68b.begin(); itdelPackageConfConfigPropertys_68b!= delPackageConfConfigPropertys_68b.end(); ++itdelPackageConfConfigPropertys_68b)
		{
			PICML::PackageConfConfigProperty currPackageConfConfigProperty_68c= *itdelPackageConfConfigPropertys_68b;
			if( currPackageConfConfigProperty_68c)
				currPackageConfConfigProperty_68c.DeleteObject();
		}
		set< PICML::ArtifactInfoProperty> delArtifactInfoPropertys_68d= currMatch.pProperty_670.srcArtifactInfoProperty();
		for( set< PICML::ArtifactInfoProperty>::const_iterator itdelArtifactInfoPropertys_68d= delArtifactInfoPropertys_68d.begin(); itdelArtifactInfoPropertys_68d!= delArtifactInfoPropertys_68d.end(); ++itdelArtifactInfoPropertys_68d)
		{
			PICML::ArtifactInfoProperty currArtifactInfoProperty_68e= *itdelArtifactInfoPropertys_68d;
			if( currArtifactInfoProperty_68e)
				currArtifactInfoProperty_68e.DeleteObject();
		}
		set< PICML::ArtifactExecParameter> delArtifactExecParameters_68f= currMatch.pProperty_670.srcArtifactExecParameter();
		for( set< PICML::ArtifactExecParameter>::const_iterator itdelArtifactExecParameters_68f= delArtifactExecParameters_68f.begin(); itdelArtifactExecParameters_68f!= delArtifactExecParameters_68f.end(); ++itdelArtifactExecParameters_68f)
		{
			PICML::ArtifactExecParameter currArtifactExecParameter_690= *itdelArtifactExecParameters_68f;
			if( currArtifactExecParameter_690)
				currArtifactExecParameter_690.DeleteObject();
		}
		if( currMatch.pProperty_670)
			currMatch.pProperty_670.DeleteObject();
		outputAppender( );
	}
}

void DestroyPublishConnectorProperties_650::outputAppender()
{
}

void Associate_Ports_6a3::operator()( const Packets_t& pAssemblys_6a4, const Packets_t& cScenarios_6a6, Packets_t& pAssemblys_6a8, Packets_t& cScenarios_6a9)
{
#ifdef PRINT_INFO
	std::cout << "Associate_Ports_6a3" << std::endl;
#endif
	_pAssembly_6aa= &pAssemblys_6a8;
	_cScenario_6ab= &cScenarios_6a9;
	_pAssembly_6aa->insert( _pAssembly_6aa->end(), pAssemblys_6a4.begin(), pAssemblys_6a4.end());
	_cScenario_6ab->insert( _cScenario_6ab->end(), cScenarios_6a6.begin(), cScenarios_6a6.end());
	if( ( !cScenarios_6a6.empty()))
		callMatch_Components_6ec( cScenarios_6a6);
}

void Associate_Ports_6a3::callMatch_Components_6ec( const Packets_t& scenarios_6af)
{
	Packets_t componentInstances_6ad;
	Packets_t components_6ae;
	Match_Components_6ac match_Components_6ac;
	match_Components_6ac( scenarios_6af, componentInstances_6ad, components_6ae);
	if( ( !components_6ae.empty())&& ( !componentInstances_6ad.empty()))
		callAssociate_Ports_rule_6ee( components_6ae, componentInstances_6ad);
}

void Associate_Ports_6a3::callAssociate_Ports_rule_6ee( const Packets_t& components_6c8, const Packets_t& componentInstances_6ca)
{
	Associate_Ports_rule_6c7 associate_Ports_rule_6c7;
	associate_Ports_rule_6c7( components_6c8, componentInstances_6ca);
}

void Match_Components_6ac::operator()( const Packets_t& scenarios_6af, Packets_t& componentInstances_6ad, Packets_t& components_6ae)
{
#ifdef PRINT_INFO
	std::cout << "Match_Components_6ac" << std::endl;
#endif
	_componentInstance_6b1= &componentInstances_6ad;
	_component_6b2= &components_6ae;
	processInputPackets( scenarios_6af);
}

bool Match_Components_6ac::isInputUnique( const Udm::Object& scenario_6b7)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_6b9= _scenario_6b3.begin(); itScenario_6b9!= _scenario_6b3.end(); ++itScenario_6b9)
	{
		if( ( *itScenario_6b9== scenario_6b7))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_6b3.push_back( scenario_6b7);
	return isUnique;
}

void Match_Components_6ac::processInputPackets( const Packets_t& scenarios_6af)
{
	for( Packets_t::const_iterator itScenario_6b4= scenarios_6af.begin(); itScenario_6b4!= scenarios_6af.end(); ++itScenario_6b4)
	{
		bool isUnique= isInputUnique( *itScenario_6b4);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_6b4);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Match_Components_6ac::patternMatcher( const Udm::Object& scenario_6b5)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_6b5.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_6ba= cadena_scenario::Scenario::Cast( scenario_6b5);
		set< cadena_scenario::ComponentInstance> componentInstances_6bc= scenario_6ba.ComponentInstance_kind_children();
		for( set< cadena_scenario::ComponentInstance>::const_iterator itComponentInstance_6bd= componentInstances_6bc.begin(); itComponentInstance_6bd!= componentInstances_6bc.end(); ++itComponentInstance_6bd)
		{
			cadena_scenario::ComponentInstance currComponentInstance_6be= *itComponentInstance_6bd;
			PICML::Component component_6bf= currComponentInstance_6be.picmlComponentDef();
			if( !component_6bf)
				continue;
			Match currMatch;
			currMatch.componentInstance_6c0= currComponentInstance_6be;
			currMatch.component_6c1= component_6bf;
			currMatch.scenario_6c2= scenario_6ba;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Match_Components_6ac::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.componentInstance_6c0, currMatch.component_6c1);
	}
}

void Match_Components_6ac::outputAppender( const cadena_scenario::ComponentInstance& componentInstance_6c3, const PICML::Component& component_6c5)
{
	_componentInstance_6b1->push_back( componentInstance_6c3);
	_component_6b2->push_back( component_6c5);
}

void Associate_Ports_rule_6c7::operator()( const Packets_t& components_6c8, const Packets_t& componentInstances_6ca)
{
#ifdef PRINT_INFO
	std::cout << "Associate_Ports_rule_6c7" << std::endl;
#endif
	processInputPackets( components_6c8, componentInstances_6ca);
}

bool Associate_Ports_rule_6c7::isInputUnique( const Udm::Object& component_6d0, const Udm::Object& componentInstance_6d9)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponent_6d2= _component_6cc.begin(), itComponentInstance_6db= _componentInstance_6d5.begin(); itComponent_6d2!= _component_6cc.end(), itComponentInstance_6db!= _componentInstance_6d5.end(); ++itComponent_6d2, ++itComponentInstance_6db)
	{
		if( ( *itComponent_6d2== component_6d0)&& ( *itComponentInstance_6db== componentInstance_6d9))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_component_6cc.push_back( component_6d0);
		_componentInstance_6d5.push_back( componentInstance_6d9);
	}
	return isUnique;
}

bool Associate_Ports_rule_6c7::isGuardTrue( const Udm::Object& Component, const Udm::Object& ComponentInstance, const Udm::Object& ComponentPort, const Udm::Object& Port)
{
	bool Gz_guard= false;
	string pPortName, cPortName; ComponentPort.GetStrValue("name", cPortName); Port.GetStrValue("name", pPortName); return (pPortName==cPortName);;
	return Gz_guard;
}

void Associate_Ports_rule_6c7::processInputPackets( const Packets_t& components_6c8, const Packets_t& componentInstances_6ca)
{
	for( Packets_t::const_iterator itComponent_6cd= components_6c8.begin(), itComponentInstance_6d6= componentInstances_6ca.begin(); itComponent_6cd!= components_6c8.end(), itComponentInstance_6d6!= componentInstances_6ca.end(); ++itComponent_6cd, ++itComponentInstance_6d6)
	{
		bool isUnique= isInputUnique( *itComponent_6cd, *itComponentInstance_6d6);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponent_6cd, *itComponentInstance_6d6);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Associate_Ports_rule_6c7::patternMatcher( const Udm::Object& component_6ce, const Udm::Object& componentInstance_6d7)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( component_6ce.type(), PICML::Component::meta))
			continue;
		PICML::Component component_6d3= PICML::Component::Cast( component_6ce);
		if( false== Uml::IsDerivedFrom( componentInstance_6d7.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_6dc= cadena_scenario::ComponentInstance::Cast( componentInstance_6d7);
		set< PICML::Port> ports_6de= component_6d3.Port_kind_children();
		for( set< PICML::Port>::const_iterator itPort_6df= ports_6de.begin(); itPort_6df!= ports_6de.end(); ++itPort_6df)
		{
			PICML::Port currPort_6e0= *itPort_6df;
			set< cadena_scenario::ComponentPort> componentPorts_6e1= componentInstance_6dc.ComponentPort_kind_children();
			for( set< cadena_scenario::ComponentPort>::const_iterator itComponentPort_6e2= componentPorts_6e1.begin(); itComponentPort_6e2!= componentPorts_6e1.end(); ++itComponentPort_6e2)
			{
				cadena_scenario::ComponentPort currComponentPort_6e3= *itComponentPort_6e2;
				Match currMatch;
				currMatch.component_6e4= component_6d3;
				currMatch.port_6e5= currPort_6e0;
				currMatch.componentPort_6e6= currComponentPort_6e3;
				currMatch.componentInstance_6e7= componentInstance_6dc;
				bool Gz_guard= isGuardTrue( currMatch.component_6e4, currMatch.componentInstance_6e7, currMatch.componentPort_6e6, currMatch.port_6e5);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void Associate_Ports_rule_6c7::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.port_6e5.cadenaPort()= currMatch.componentPort_6e6;
		outputAppender( );
	}
}

void Associate_Ports_rule_6c7::outputAppender()
{
}

void CreateDestroy_Components_n_PublishConnectors_6f1::operator()( const Packets_t& pAssemblys_6f2, const Packets_t& cScenarios_6f4, Packets_t& pAssemblys_6f6, Packets_t& cScenarios_6f7)
{
#ifdef PRINT_INFO
	std::cout << "CreateDestroy_Components_n_PublishConnectors_6f1" << std::endl;
#endif
	_pAssembly_6f8= &pAssemblys_6f6;
	_cScenario_6f9= &cScenarios_6f7;
	if( ( !cScenarios_6f4.empty())&& ( !pAssemblys_6f2.empty()))
		callCreatePublishConnectors_step1_918( cScenarios_6f4, pAssemblys_6f2);
	if( ( !pAssemblys_6f2.empty()))
		callDestroyPublishConnectors_91b( pAssemblys_6f2);
	if( ( !pAssemblys_6f2.empty()))
		callFindComponents2BDeleted_91d( pAssemblys_6f2);
	if( ( !cScenarios_6f4.empty())&& ( !pAssemblys_6f2.empty()))
		callCreateComponents_step1_91f( cScenarios_6f4, pAssemblys_6f2);
	_pAssembly_6f8->insert( _pAssembly_6f8->end(), pAssemblys_6f2.begin(), pAssemblys_6f2.end());
	_cScenario_6f9->insert( _cScenario_6f9->end(), cScenarios_6f4.begin(), cScenarios_6f4.end());
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callCreatePublishConnectors_step1_918( const Packets_t& cScenarios_7aa, const Packets_t& pAssemblys_7ac)
{
	Packets_t cScenarios_7ae;
	Packets_t pAssemblys_7af;
	CreatePublishConnectors_step1_7a9 createPublishConnectors_step1_7a9;
	createPublishConnectors_step1_7a9( cScenarios_7aa, pAssemblys_7ac, cScenarios_7ae, pAssemblys_7af);
	if( ( !cScenarios_7ae.empty())&& ( !pAssemblys_7af.empty()))
		callCreatePublishConnectors_step2_922( cScenarios_7ae, pAssemblys_7af);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callDestroyPublishConnectors_91b( const Packets_t& componentAssemblys_7cd)
{
	DestroyPublishConnectors_7cc destroyPublishConnectors_7cc;
	destroyPublishConnectors_7cc( componentAssemblys_7cd);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callFindComponents2BDeleted_91d( const Packets_t& componentAssemblys_8dc)
{
	Packets_t components_8db;
	FindComponents2BDeleted_8da findComponents2BDeleted_8da;
	findComponents2BDeleted_8da( componentAssemblys_8dc, components_8db);
	if( ( !components_8db.empty()))
		callDestroyOrphanPropertiesAndDeleteComponent_925( components_8db);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callCreateComponents_step1_91f( const Packets_t& scenarios_8f3, const Packets_t& componentAssemblys_8f5)
{
	Packets_t componentInstances_8f2;
	Packets_t componentAssemblys_8f7;
	CreateComponents_step1_8f1 createComponents_step1_8f1;
	createComponents_step1_8f1( scenarios_8f3, componentAssemblys_8f5, componentInstances_8f2, componentAssemblys_8f7);
	if( ( !componentAssemblys_8f7.empty())&& ( !componentInstances_8f2.empty()))
		callFindFirstPackage_927( componentAssemblys_8f7, componentInstances_8f2);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callCreatePublishConnectors_step2_922( const Packets_t& cScenarios_782, const Packets_t& pAssemblys_784)
{
	Packets_t pAssemblys_786;
	Packets_t cScenarios_787;
	CreatePublishConnectors_step2_781 createPublishConnectors_step2_781;
	createPublishConnectors_step2_781( cScenarios_782, pAssemblys_784, pAssemblys_786, cScenarios_787);
	if( ( !pAssemblys_786.empty())&& ( !cScenarios_787.empty()))
		callCreatePublishConnectors_step3_92a( pAssemblys_786, cScenarios_787);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callDestroyOrphanPropertiesAndDeleteComponent_925( const Packets_t& pComponentToBeDeleteds_729)
{
	DestroyOrphanPropertiesAndDeleteComponent_728 destroyOrphanPropertiesAndDeleteComponent_728;
	destroyOrphanPropertiesAndDeleteComponent_728( pComponentToBeDeleteds_729);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callFindFirstPackage_927( const Packets_t& componentAssemblys_8a2, const Packets_t& componentInstances_8a5)
{
	Packets_t packages_8a1;
	Packets_t componentAssemblys_8a4;
	Packets_t componentInstances_8a7;
	FindFirstPackage_8a0 findFirstPackage_8a0;
	findFirstPackage_8a0( componentAssemblys_8a2, componentInstances_8a5, packages_8a1, componentAssemblys_8a4, componentInstances_8a7);
	if( ( !componentAssemblys_8a4.empty())&& ( !packages_8a1.empty())&& ( !componentInstances_8a7.empty()))
		callMatchAPackage_92d( componentAssemblys_8a4, packages_8a1, componentInstances_8a7);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callCreatePublishConnectors_step3_92a( const Packets_t& pAssemblys_6fb, const Packets_t& cScenarios_6fd)
{
	CreatePublishConnectors_step3_6fa createPublishConnectors_step3_6fa;
	createPublishConnectors_step3_6fa( pAssemblys_6fb, cScenarios_6fd);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callMatchAPackage_92d( const Packets_t& componentAssemblys_850, const Packets_t& packages_853, const Packets_t& componentInstances_856)
{
	Packets_t componentAssemblys_852;
	Packets_t packages_855;
	Packets_t componentInstances_858;
	MatchAPackage_84f matchAPackage_84f;
	matchAPackage_84f( componentAssemblys_850, packages_853, componentInstances_856, componentAssemblys_852, packages_855, componentInstances_858);
	if( ( !componentInstances_858.empty())&& ( !packages_855.empty())&& ( !componentAssemblys_852.empty()))
		callFinalPackage_InstantiateComponent_931( componentInstances_858, packages_855, componentAssemblys_852);
	if( ( !componentInstances_858.empty())&& ( !packages_855.empty())&& ( !componentAssemblys_852.empty()))
		callFindSubPackage_935( componentInstances_858, packages_855, componentAssemblys_852);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callFinalPackage_InstantiateComponent_931( const Packets_t& componentInstances_7e6, const Packets_t& packages_7e9, const Packets_t& componentAssemblys_7eb)
{
	Packets_t componentInstances_7e8;
	Packets_t componentAssemblys_7ed;
	FinalPackage_InstantiateComponent_7e5 finalPackage_InstantiateComponent_7e5;
	finalPackage_InstantiateComponent_7e5( componentInstances_7e6, packages_7e9, componentAssemblys_7eb, componentInstances_7e8, componentAssemblys_7ed);
	if( ( !componentAssemblys_7ed.empty())&& ( !componentInstances_7e8.empty()))
		callAssociateComponentsNow_939( componentAssemblys_7ed, componentInstances_7e8);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callFindSubPackage_935( const Packets_t& componentInstances_81b, const Packets_t& packages_81f, const Packets_t& componentAssemblys_821)
{
	Packets_t componentInstances_81d;
	Packets_t packages_81e;
	Packets_t componentAssemblys_823;
	FindSubPackage_81a findSubPackage_81a;
	findSubPackage_81a( componentInstances_81b, packages_81f, componentAssemblys_821, componentInstances_81d, packages_81e, componentAssemblys_823);
	if( ( !componentAssemblys_823.empty())&& ( !packages_81e.empty())&& ( !componentInstances_81d.empty()))
		callMatchAPackage_ref_93c( componentAssemblys_823, packages_81e, componentInstances_81d);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callAssociateComponentsNow_939( const Packets_t& componentAssemblys_881, const Packets_t& componentInstances_883)
{
	AssociateComponentsNow_880 associateComponentsNow_880;
	associateComponentsNow_880( componentAssemblys_881, componentInstances_883);
}

void CreateDestroy_Components_n_PublishConnectors_6f1::callMatchAPackage_ref_93c( const Packets_t& componentAssemblys_850, const Packets_t& packages_853, const Packets_t& componentInstances_856)
{
	Packets_t componentAssemblys_852;
	Packets_t packages_855;
	Packets_t componentInstances_858;
	MatchAPackage_84f matchAPackage_84f;
	matchAPackage_84f( componentAssemblys_850, packages_853, componentInstances_856, componentAssemblys_852, packages_855, componentInstances_858);
}

void CreatePublishConnectors_step3_6fa::operator()( const Packets_t& pAssemblys_6fb, const Packets_t& cScenarios_6fd)
{
#ifdef PRINT_INFO
	std::cout << "CreatePublishConnectors_step3_6fa" << std::endl;
#endif
	if( ( !cScenarios_6fd.empty())&& ( !pAssemblys_6fb.empty()))
		callCreatePublishConnectors_step3_rule_725( cScenarios_6fd, pAssemblys_6fb);
}

void CreatePublishConnectors_step3_6fa::callCreatePublishConnectors_step3_rule_725( const Packets_t& scenarios_700, const Packets_t& componentAssemblys_702)
{
	CreatePublishConnectors_step3_rule_6ff createPublishConnectors_step3_rule_6ff;
	createPublishConnectors_step3_rule_6ff( scenarios_700, componentAssemblys_702);
}

void CreatePublishConnectors_step3_rule_6ff::operator()( const Packets_t& scenarios_700, const Packets_t& componentAssemblys_702)
{
#ifdef PRINT_INFO
	std::cout << "CreatePublishConnectors_step3_rule_6ff" << std::endl;
#endif
	processInputPackets( scenarios_700, componentAssemblys_702);
}

bool CreatePublishConnectors_step3_rule_6ff::isInputUnique( const Udm::Object& scenario_708, const Udm::Object& componentAssembly_711)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_70a= _scenario_704.begin(), itComponentAssembly_713= _componentAssembly_70d.begin(); itScenario_70a!= _scenario_704.end(), itComponentAssembly_713!= _componentAssembly_70d.end(); ++itScenario_70a, ++itComponentAssembly_713)
	{
		if( ( *itScenario_70a== scenario_708)&& ( *itComponentAssembly_713== componentAssembly_711))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_704.push_back( scenario_708);
		_componentAssembly_70d.push_back( componentAssembly_711);
	}
	return isUnique;
}

bool CreatePublishConnectors_step3_rule_6ff::isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ESSConnection, const Udm::Object& PublishConnector, const Udm::Object& Scenario)
{
	bool Gz_guard= false;
	string cConnectorID; ESSConnection.GetStrValue("ConnectorID", cConnectorID); return (cConnectorID!="emit");;
	return Gz_guard;
}

void CreatePublishConnectors_step3_rule_6ff::processInputPackets( const Packets_t& scenarios_700, const Packets_t& componentAssemblys_702)
{
	for( Packets_t::const_iterator itScenario_705= scenarios_700.begin(), itComponentAssembly_70e= componentAssemblys_702.begin(); itScenario_705!= scenarios_700.end(), itComponentAssembly_70e!= componentAssemblys_702.end(); ++itScenario_705, ++itComponentAssembly_70e)
	{
		bool isUnique= isInputUnique( *itScenario_705, *itComponentAssembly_70e);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_705, *itComponentAssembly_70e);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool CreatePublishConnectors_step3_rule_6ff::patternMatcher( const Udm::Object& scenario_706, const Udm::Object& componentAssembly_70f)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_706.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_70b= cadena_scenario::Scenario::Cast( scenario_706);
		if( false== Uml::IsDerivedFrom( componentAssembly_70f.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_714= PICML::ComponentAssembly::Cast( componentAssembly_70f);
		set< cadena_scenario::ESSConnection> eSSConnections_716= scenario_70b.ESSConnection_kind_children();
		for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnection_717= eSSConnections_716.begin(); itESSConnection_717!= eSSConnections_716.end(); ++itESSConnection_717)
		{
			cadena_scenario::ESSConnection currESSConnection_718= *itESSConnection_717;
			set< PICML::PublishConnector> publishConnectors_719= currESSConnection_718.picmlPublishConnector();
			for( set< PICML::PublishConnector>::const_iterator itPublishConnectors_71a= publishConnectors_719.begin(); itPublishConnectors_71a!= publishConnectors_719.end(); ++itPublishConnectors_71a)
			{
				PICML::PublishConnector currPublishConnector_71b= *itPublishConnectors_71a;
				Match currMatch;
				currMatch.scenario_71c= scenario_70b;
				currMatch.publishConnector_71d= currPublishConnector_71b;
				currMatch.componentAssembly_71e= componentAssembly_714;
				currMatch.eSSConnection_71f= currESSConnection_718;
				bool Gz_guard= isGuardTrue( currMatch.componentAssembly_71e, currMatch.eSSConnection_71f, currMatch.publishConnector_71d, currMatch.scenario_71c);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void CreatePublishConnectors_step3_rule_6ff::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::PublishConnector newPublishConnector_724= PICML::PublishConnector::Create( currMatch.componentAssembly_71e);
		newPublishConnector_724.cadenaESSConnection()= currMatch.eSSConnection_71f;
		outputAppender( );
	}
}

void CreatePublishConnectors_step3_rule_6ff::outputAppender()
{
}

void DestroyOrphanPropertiesAndDeleteComponent_728::operator()( const Packets_t& pComponentToBeDeleteds_729)
{
#ifdef PRINT_INFO
	std::cout << "DestroyOrphanPropertiesAndDeleteComponent_728" << std::endl;
#endif
	for( Packets_t::const_iterator itPComponentToBeDeleted_72c= pComponentToBeDeleteds_729.begin(); itPComponentToBeDeleted_72c!= pComponentToBeDeleteds_729.end(); ++itPComponentToBeDeleted_72c)
	{
		bool isUnique= isInputUnique( *itPComponentToBeDeleted_72c);
		if( !isUnique)
			continue;
		Packets_t onePComponentToBeDeleted_730( 1, *itPComponentToBeDeleted_72c);
		executeOne( onePComponentToBeDeleted_730);
	}
}

void DestroyOrphanPropertiesAndDeleteComponent_728::executeOne( const Packets_t& pComponentToBeDeleteds_729)
{
	if( ( !pComponentToBeDeleteds_729.empty()))
		callDestroyOrphanProperties_77d( pComponentToBeDeleteds_729);
}

bool DestroyOrphanPropertiesAndDeleteComponent_728::isInputUnique( const Udm::Object& pComponentToBeDeleted_72d)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPComponentToBeDeleted_72f= _pComponentToBeDeleted_72b.begin(); itPComponentToBeDeleted_72f!= _pComponentToBeDeleted_72b.end(); ++itPComponentToBeDeleted_72f)
	{
		if( ( *itPComponentToBeDeleted_72f== pComponentToBeDeleted_72d))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_pComponentToBeDeleted_72b.push_back( pComponentToBeDeleted_72d);
	return isUnique;
}

void DestroyOrphanPropertiesAndDeleteComponent_728::callDestroyOrphanProperties_77d( const Packets_t& components_733)
{
	Packets_t components_735;
	DestroyOrphanProperties_732 destroyOrphanProperties_732;
	destroyOrphanProperties_732( components_733, components_735);
	if( ( !components_735.empty()))
		callDestroyComponent_77f( components_735);
}

void DestroyOrphanPropertiesAndDeleteComponent_728::callDestroyComponent_77f( const Packets_t& components_76b)
{
	DestroyComponent_76a destroyComponent_76a;
	destroyComponent_76a( components_76b);
}

void DestroyOrphanProperties_732::operator()( const Packets_t& components_733, Packets_t& components_735)
{
#ifdef PRINT_INFO
	std::cout << "DestroyOrphanProperties_732" << std::endl;
#endif
	_component_736= &components_735;
	processInputPackets( components_733);
	forwardInputs( );
}

bool DestroyOrphanProperties_732::isInputUnique( const Udm::Object& component_73b)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponent_73d= _component_737.begin(); itComponent_73d!= _component_737.end(); ++itComponent_73d)
	{
		if( ( *itComponent_73d== component_73b))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_component_737.push_back( component_73b);
	return isUnique;
}

bool DestroyOrphanProperties_732::isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& Component, const Udm::Object& DataType, const Udm::Object& PredefinedType, const Udm::Object& Property)
{
	bool Gz_guard= false;
	set<Udm::Object> adjacent = Property.GetAdjacentObjects(Component.type()); if (adjacent.size()!=1) return false;  string propType; PredefinedType.type().GetStrValue("name", propType); if (propType!="LongInteger" && propType!="String" && propType!="Boolean") return false; else return true;;
	return Gz_guard;
}

void DestroyOrphanProperties_732::processInputPackets( const Packets_t& components_733)
{
	for( Packets_t::const_iterator itComponent_738= components_733.begin(); itComponent_738!= components_733.end(); ++itComponent_738)
	{
		bool isUnique= isInputUnique( *itComponent_738);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponent_738);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool DestroyOrphanProperties_732::patternMatcher( const Udm::Object& component_739)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( component_739.type(), PICML::Component::meta))
			continue;
		PICML::Component component_73e= PICML::Component::Cast( component_739);
		set< PICML::AssemblyConfigProperty> assemblyConfigPropertys_740= component_73e.dstAssemblyConfigProperty();
		for( set< PICML::AssemblyConfigProperty>::const_iterator itAssemblyConfigPropertys_741= assemblyConfigPropertys_740.begin(); itAssemblyConfigPropertys_741!= assemblyConfigPropertys_740.end(); ++itAssemblyConfigPropertys_741)
		{
			PICML::AssemblyConfigProperty currAssemblyConfigProperty_742= *itAssemblyConfigPropertys_741;
			PICML::Property property_743= currAssemblyConfigProperty_742.dstAssemblyConfigProperty_end();
			set< PICML::DataType> dataTypes_744= property_743.DataType_kind_children();
			for( set< PICML::DataType>::const_iterator itDataType_745= dataTypes_744.begin(); itDataType_745!= dataTypes_744.end(); ++itDataType_745)
			{
				PICML::DataType currDataType_746= *itDataType_745;
				PICML::PredefinedType predefinedType_747= currDataType_746.ref();
				if( !predefinedType_747)
					continue;
				Match currMatch;
				currMatch.dataType_748= currDataType_746;
				currMatch.predefinedType_749= predefinedType_747;
				currMatch.assemblyConfigProperty_74a= currAssemblyConfigProperty_742;
				currMatch.property_74b= property_743;
				currMatch.component_74c= component_73e;
				bool Gz_guard= isGuardTrue( currMatch.assemblyConfigProperty_74a, currMatch.component_74c, currMatch.dataType_748, currMatch.predefinedType_749, currMatch.property_74b);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void DestroyOrphanProperties_732::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.dataType_748.ref()= Udm::null;
		if( currMatch.dataType_748)
			currMatch.dataType_748.DeleteObject();
		set< PICML::InfoProperty> delInfoPropertys_752= currMatch.property_74b.srcInfoProperty();
		for( set< PICML::InfoProperty>::const_iterator itdelInfoPropertys_752= delInfoPropertys_752.begin(); itdelInfoPropertys_752!= delInfoPropertys_752.end(); ++itdelInfoPropertys_752)
		{
			PICML::InfoProperty currInfoProperty_753= *itdelInfoPropertys_752;
			if( currInfoProperty_753)
				currInfoProperty_753.DeleteObject();
		}
		set< PICML::ConfigProperty> delConfigPropertys_754= currMatch.property_74b.srcConfigProperty();
		for( set< PICML::ConfigProperty>::const_iterator itdelConfigPropertys_754= delConfigPropertys_754.begin(); itdelConfigPropertys_754!= delConfigPropertys_754.end(); ++itdelConfigPropertys_754)
		{
			PICML::ConfigProperty currConfigProperty_755= *itdelConfigPropertys_754;
			if( currConfigProperty_755)
				currConfigProperty_755.DeleteObject();
		}
		set< PICML::AssemblyConfigProperty> delAssemblyConfigPropertys_756= currMatch.property_74b.srcAssemblyConfigProperty();
		for( set< PICML::AssemblyConfigProperty>::const_iterator itdelAssemblyConfigPropertys_756= delAssemblyConfigPropertys_756.begin(); itdelAssemblyConfigPropertys_756!= delAssemblyConfigPropertys_756.end(); ++itdelAssemblyConfigPropertys_756)
		{
			PICML::AssemblyConfigProperty currAssemblyConfigProperty_757= *itdelAssemblyConfigPropertys_756;
			if( currAssemblyConfigProperty_757)
				currAssemblyConfigProperty_757.DeleteObject();
		}
		set< PICML::PackageConfigProperty> delPackageConfigPropertys_758= currMatch.property_74b.srcPackageConfigProperty();
		for( set< PICML::PackageConfigProperty>::const_iterator itdelPackageConfigPropertys_758= delPackageConfigPropertys_758.begin(); itdelPackageConfigPropertys_758!= delPackageConfigPropertys_758.end(); ++itdelPackageConfigPropertys_758)
		{
			PICML::PackageConfigProperty currPackageConfigProperty_759= *itdelPackageConfigPropertys_758;
			if( currPackageConfigProperty_759)
				currPackageConfigProperty_759.DeleteObject();
		}
		set< PICML::PackageInfoProperty> delPackageInfoPropertys_75a= currMatch.property_74b.srcPackageInfoProperty();
		for( set< PICML::PackageInfoProperty>::const_iterator itdelPackageInfoPropertys_75a= delPackageInfoPropertys_75a.begin(); itdelPackageInfoPropertys_75a!= delPackageInfoPropertys_75a.end(); ++itdelPackageInfoPropertys_75a)
		{
			PICML::PackageInfoProperty currPackageInfoProperty_75b= *itdelPackageInfoPropertys_75a;
			if( currPackageInfoProperty_75b)
				currPackageInfoProperty_75b.DeleteObject();
		}
		set< PICML::MonolithExecParameter> delMonolithExecParameters_75c= currMatch.property_74b.srcMonolithExecParameter();
		for( set< PICML::MonolithExecParameter>::const_iterator itdelMonolithExecParameters_75c= delMonolithExecParameters_75c.begin(); itdelMonolithExecParameters_75c!= delMonolithExecParameters_75c.end(); ++itdelMonolithExecParameters_75c)
		{
			PICML::MonolithExecParameter currMonolithExecParameter_75d= *itdelMonolithExecParameters_75c;
			if( currMonolithExecParameter_75d)
				currMonolithExecParameter_75d.DeleteObject();
		}
		set< PICML::ComponentConfigProperty> delComponentConfigPropertys_75e= currMatch.property_74b.srcComponentConfigProperty();
		for( set< PICML::ComponentConfigProperty>::const_iterator itdelComponentConfigPropertys_75e= delComponentConfigPropertys_75e.begin(); itdelComponentConfigPropertys_75e!= delComponentConfigPropertys_75e.end(); ++itdelComponentConfigPropertys_75e)
		{
			PICML::ComponentConfigProperty currComponentConfigProperty_75f= *itdelComponentConfigPropertys_75e;
			if( currComponentConfigProperty_75f)
				currComponentConfigProperty_75f.DeleteObject();
		}
		set< PICML::ComponentInfoProperty> delComponentInfoPropertys_760= currMatch.property_74b.srcComponentInfoProperty();
		for( set< PICML::ComponentInfoProperty>::const_iterator itdelComponentInfoPropertys_760= delComponentInfoPropertys_760.begin(); itdelComponentInfoPropertys_760!= delComponentInfoPropertys_760.end(); ++itdelComponentInfoPropertys_760)
		{
			PICML::ComponentInfoProperty currComponentInfoProperty_761= *itdelComponentInfoPropertys_760;
			if( currComponentInfoProperty_761)
				currComponentInfoProperty_761.DeleteObject();
		}
		set< PICML::PackageConfConfigProperty> delPackageConfConfigPropertys_762= currMatch.property_74b.srcPackageConfConfigProperty();
		for( set< PICML::PackageConfConfigProperty>::const_iterator itdelPackageConfConfigPropertys_762= delPackageConfConfigPropertys_762.begin(); itdelPackageConfConfigPropertys_762!= delPackageConfConfigPropertys_762.end(); ++itdelPackageConfConfigPropertys_762)
		{
			PICML::PackageConfConfigProperty currPackageConfConfigProperty_763= *itdelPackageConfConfigPropertys_762;
			if( currPackageConfConfigProperty_763)
				currPackageConfConfigProperty_763.DeleteObject();
		}
		set< PICML::ArtifactInfoProperty> delArtifactInfoPropertys_764= currMatch.property_74b.srcArtifactInfoProperty();
		for( set< PICML::ArtifactInfoProperty>::const_iterator itdelArtifactInfoPropertys_764= delArtifactInfoPropertys_764.begin(); itdelArtifactInfoPropertys_764!= delArtifactInfoPropertys_764.end(); ++itdelArtifactInfoPropertys_764)
		{
			PICML::ArtifactInfoProperty currArtifactInfoProperty_765= *itdelArtifactInfoPropertys_764;
			if( currArtifactInfoProperty_765)
				currArtifactInfoProperty_765.DeleteObject();
		}
		set< PICML::ArtifactExecParameter> delArtifactExecParameters_766= currMatch.property_74b.srcArtifactExecParameter();
		for( set< PICML::ArtifactExecParameter>::const_iterator itdelArtifactExecParameters_766= delArtifactExecParameters_766.begin(); itdelArtifactExecParameters_766!= delArtifactExecParameters_766.end(); ++itdelArtifactExecParameters_766)
		{
			PICML::ArtifactExecParameter currArtifactExecParameter_767= *itdelArtifactExecParameters_766;
			if( currArtifactExecParameter_767)
				currArtifactExecParameter_767.DeleteObject();
		}
		if( currMatch.property_74b)
			currMatch.property_74b.DeleteObject();
		outputAppender( currMatch.component_74c);
	}
}

void DestroyOrphanProperties_732::outputAppender( const PICML::Component& component_768)
{
	_component_736->push_back( component_768);
}

void DestroyOrphanProperties_732::forwardInputs()
{
	*_component_736= _component_737;
}

void DestroyComponent_76a::operator()( const Packets_t& components_76b)
{
#ifdef PRINT_INFO
	std::cout << "DestroyComponent_76a" << std::endl;
#endif
	processInputPackets( components_76b);
}

bool DestroyComponent_76a::isInputUnique( const Udm::Object& component_771)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponent_773= _component_76d.begin(); itComponent_773!= _component_76d.end(); ++itComponent_773)
	{
		if( ( *itComponent_773== component_771))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_component_76d.push_back( component_771);
	return isUnique;
}

void DestroyComponent_76a::processInputPackets( const Packets_t& components_76b)
{
	for( Packets_t::const_iterator itComponent_76e= components_76b.begin(); itComponent_76e!= components_76b.end(); ++itComponent_76e)
	{
		bool isUnique= isInputUnique( *itComponent_76e);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponent_76e);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool DestroyComponent_76a::patternMatcher( const Udm::Object& component_76f)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( component_76f.type(), PICML::Component::meta))
			continue;
		PICML::Component component_774= PICML::Component::Cast( component_76f);
		Match currMatch;
		currMatch.component_776= component_774;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void DestroyComponent_76a::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		set< PICML::ManagesComponent> delManagesComponents_777= currMatch.component_776.srcManagesComponent();
		for( set< PICML::ManagesComponent>::const_iterator itdelManagesComponents_777= delManagesComponents_777.begin(); itdelManagesComponents_777!= delManagesComponents_777.end(); ++itdelManagesComponents_777)
		{
			PICML::ManagesComponent currManagesComponent_778= *itdelManagesComponents_777;
			if( currManagesComponent_778)
				currManagesComponent_778.DeleteObject();
		}
		set< PICML::AssemblyConfigProperty> delAssemblyConfigPropertys_779= currMatch.component_776.dstAssemblyConfigProperty();
		for( set< PICML::AssemblyConfigProperty>::const_iterator itdelAssemblyConfigPropertys_779= delAssemblyConfigPropertys_779.begin(); itdelAssemblyConfigPropertys_779!= delAssemblyConfigPropertys_779.end(); ++itdelAssemblyConfigPropertys_779)
		{
			PICML::AssemblyConfigProperty currAssemblyConfigProperty_77a= *itdelAssemblyConfigPropertys_779;
			if( currAssemblyConfigProperty_77a)
				currAssemblyConfigProperty_77a.DeleteObject();
		}
		set< PICML::AssemblyselectRequirement> delAssemblyselectRequirements_77b= currMatch.component_776.dstAssemblyselectRequirement();
		for( set< PICML::AssemblyselectRequirement>::const_iterator itdelAssemblyselectRequirements_77b= delAssemblyselectRequirements_77b.begin(); itdelAssemblyselectRequirements_77b!= delAssemblyselectRequirements_77b.end(); ++itdelAssemblyselectRequirements_77b)
		{
			PICML::AssemblyselectRequirement currAssemblyselectRequirement_77c= *itdelAssemblyselectRequirements_77b;
			if( currAssemblyselectRequirement_77c)
				currAssemblyselectRequirement_77c.DeleteObject();
		}
		if( currMatch.component_776)
			currMatch.component_776.DeleteObject();
		outputAppender( );
	}
}

void DestroyComponent_76a::outputAppender()
{
}

void CreatePublishConnectors_step2_781::operator()( const Packets_t& cScenarios_782, const Packets_t& pAssemblys_784, Packets_t& pAssemblys_786, Packets_t& cScenarios_787)
{
#ifdef PRINT_INFO
	std::cout << "CreatePublishConnectors_step2_781" << std::endl;
#endif
	_pAssembly_788= &pAssemblys_786;
	_cScenario_789= &cScenarios_787;
	_cScenario_789->insert( _cScenario_789->end(), cScenarios_782.begin(), cScenarios_782.end());
	_pAssembly_788->insert( _pAssembly_788->end(), pAssemblys_784.begin(), pAssemblys_784.end());
	if( ( !cScenarios_782.empty()))
		callCreatePublishConnectors_step2_rule_7a7( cScenarios_782);
}

void CreatePublishConnectors_step2_781::callCreatePublishConnectors_step2_rule_7a7( const Packets_t& scenarios_78b)
{
	CreatePublishConnectors_step2_rule_78a createPublishConnectors_step2_rule_78a;
	createPublishConnectors_step2_rule_78a( scenarios_78b);
}

void CreatePublishConnectors_step2_rule_78a::operator()( const Packets_t& scenarios_78b)
{
#ifdef PRINT_INFO
	std::cout << "CreatePublishConnectors_step2_rule_78a" << std::endl;
#endif
	processInputPackets( scenarios_78b);
}

bool CreatePublishConnectors_step2_rule_78a::isInputUnique( const Udm::Object& scenario_791)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_793= _scenario_78d.begin(); itScenario_793!= _scenario_78d.end(); ++itScenario_793)
	{
		if( ( *itScenario_793== scenario_791))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_78d.push_back( scenario_791);
	return isUnique;
}

bool CreatePublishConnectors_step2_rule_78a::isGuardTrue( const Udm::Object& ESSConnection, const Udm::Object& EventSink, const Udm::Object& EventSource, const Udm::Object& Scenario)
{
	bool Gz_guard= false;
	string cConnID; ESSConnection.GetStrValue("ConnectorID", cConnID); if (cConnID!="emit") return false;  set<Udm::Object> sources = ESSConnection.GetAdjacentObjects(EventSource.type()); set<Udm::Object> sinks = ESSConnection.GetAdjacentObjects(EventSink.type()); if ((sources.size() + sinks.size()) > 2) return true; else return false;;
	return Gz_guard;
}

void CreatePublishConnectors_step2_rule_78a::processInputPackets( const Packets_t& scenarios_78b)
{
	for( Packets_t::const_iterator itScenario_78e= scenarios_78b.begin(); itScenario_78e!= scenarios_78b.end(); ++itScenario_78e)
	{
		bool isUnique= isInputUnique( *itScenario_78e);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_78e);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool CreatePublishConnectors_step2_rule_78a::patternMatcher( const Udm::Object& scenario_78f)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_78f.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_794= cadena_scenario::Scenario::Cast( scenario_78f);
		set< cadena_scenario::ESSConnection> eSSConnections_796= scenario_794.ESSConnection_kind_children();
		for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnection_797= eSSConnections_796.begin(); itESSConnection_797!= eSSConnections_796.end(); ++itESSConnection_797)
		{
			cadena_scenario::ESSConnection currESSConnection_798= *itESSConnection_797;
			set< cadena_scenario::EventSink> eventSinks_799= currESSConnection_798.sinks();
			for( set< cadena_scenario::EventSink>::const_iterator itEventSinks_79a= eventSinks_799.begin(); itEventSinks_79a!= eventSinks_799.end(); ++itEventSinks_79a)
			{
				cadena_scenario::EventSink currEventSink_79b= *itEventSinks_79a;
				set< cadena_scenario::EventSource> eventSources_79c= currESSConnection_798.sources();
				for( set< cadena_scenario::EventSource>::const_iterator itEventSources_79d= eventSources_79c.begin(); itEventSources_79d!= eventSources_79c.end(); ++itEventSources_79d)
				{
					cadena_scenario::EventSource currEventSource_79e= *itEventSources_79d;
					Match currMatch;
					currMatch.eventSource_79f= currEventSource_79e;
					currMatch.eventSink_7a0= currEventSink_79b;
					currMatch.scenario_7a1= scenario_794;
					currMatch.eSSConnection_7a2= currESSConnection_798;
					bool Gz_guard= isGuardTrue( currMatch.eSSConnection_7a2, currMatch.eventSink_7a0, currMatch.eventSource_79f, currMatch.scenario_7a1);
					if( true== Gz_guard)
						_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void CreatePublishConnectors_step2_rule_78a::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& ESSConnection= currMatch.eSSConnection_7a2;
		Udm::Object& EventSink= currMatch.eventSink_7a0;
		Udm::Object& EventSource= currMatch.eventSource_79f;
		Udm::Object& Scenario= currMatch.scenario_7a1;
		{ESSConnection.SetStrValue("ConnectorID", "");};
		outputAppender( );
	}
}

void CreatePublishConnectors_step2_rule_78a::outputAppender()
{
}

void CreatePublishConnectors_step1_7a9::operator()( const Packets_t& cScenarios_7aa, const Packets_t& pAssemblys_7ac, Packets_t& cScenarios_7ae, Packets_t& pAssemblys_7af)
{
#ifdef PRINT_INFO
	std::cout << "CreatePublishConnectors_step1_7a9" << std::endl;
#endif
	_cScenario_7b0= &cScenarios_7ae;
	_pAssembly_7b1= &pAssemblys_7af;
	_cScenario_7b0->insert( _cScenario_7b0->end(), cScenarios_7aa.begin(), cScenarios_7aa.end());
	_pAssembly_7b1->insert( _pAssembly_7b1->end(), pAssemblys_7ac.begin(), pAssemblys_7ac.end());
	if( ( !cScenarios_7aa.empty()))
		callCreatePublishConnectors_step1_rule_7ca( cScenarios_7aa);
}

void CreatePublishConnectors_step1_7a9::callCreatePublishConnectors_step1_rule_7ca( const Packets_t& scenarios_7b3)
{
	CreatePublishConnectors_step1_rule_7b2 createPublishConnectors_step1_rule_7b2;
	createPublishConnectors_step1_rule_7b2( scenarios_7b3);
}

void CreatePublishConnectors_step1_rule_7b2::operator()( const Packets_t& scenarios_7b3)
{
#ifdef PRINT_INFO
	std::cout << "CreatePublishConnectors_step1_rule_7b2" << std::endl;
#endif
	processInputPackets( scenarios_7b3);
}

bool CreatePublishConnectors_step1_rule_7b2::isInputUnique( const Udm::Object& scenario_7b9)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_7bb= _scenario_7b5.begin(); itScenario_7bb!= _scenario_7b5.end(); ++itScenario_7bb)
	{
		if( ( *itScenario_7bb== scenario_7b9))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_7b5.push_back( scenario_7b9);
	return isUnique;
}

bool CreatePublishConnectors_step1_rule_7b2::isGuardTrue( const Udm::Object& ESSConnection, const Udm::Object& PublishConnector, const Udm::Object& Scenario)
{
	bool Gz_guard= false;
	string cConnID; ESSConnection.GetStrValue("ConnectorID", cConnID); return (cConnID=="");;
	return Gz_guard;
}

void CreatePublishConnectors_step1_rule_7b2::processInputPackets( const Packets_t& scenarios_7b3)
{
	for( Packets_t::const_iterator itScenario_7b6= scenarios_7b3.begin(); itScenario_7b6!= scenarios_7b3.end(); ++itScenario_7b6)
	{
		bool isUnique= isInputUnique( *itScenario_7b6);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_7b6);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool CreatePublishConnectors_step1_rule_7b2::patternMatcher( const Udm::Object& scenario_7b7)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_7b7.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_7bc= cadena_scenario::Scenario::Cast( scenario_7b7);
		set< cadena_scenario::ESSConnection> eSSConnections_7be= scenario_7bc.ESSConnection_kind_children();
		for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnection_7bf= eSSConnections_7be.begin(); itESSConnection_7bf!= eSSConnections_7be.end(); ++itESSConnection_7bf)
		{
			cadena_scenario::ESSConnection currESSConnection_7c0= *itESSConnection_7bf;
			set< PICML::PublishConnector> publishConnectors_7c1= currESSConnection_7c0.picmlPublishConnector();
			for( set< PICML::PublishConnector>::const_iterator itPublishConnectors_7c2= publishConnectors_7c1.begin(); itPublishConnectors_7c2!= publishConnectors_7c1.end(); ++itPublishConnectors_7c2)
			{
				PICML::PublishConnector currPublishConnector_7c3= *itPublishConnectors_7c2;
				Match currMatch;
				currMatch.eSSConnection_7c4= currESSConnection_7c0;
				currMatch.scenario_7c5= scenario_7bc;
				currMatch.publishConnector_7c6= currPublishConnector_7c3;
				bool Gz_guard= isGuardTrue( currMatch.eSSConnection_7c4, currMatch.publishConnector_7c6, currMatch.scenario_7c5);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void CreatePublishConnectors_step1_rule_7b2::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& ESSConnection= currMatch.eSSConnection_7c4;
		Udm::Object& PublishConnector= currMatch.publishConnector_7c6;
		Udm::Object& Scenario= currMatch.scenario_7c5;
		{ESSConnection.SetStrValue("ConnectorID", "emit"); };
		outputAppender( );
	}
}

void CreatePublishConnectors_step1_rule_7b2::outputAppender()
{
}

void DestroyPublishConnectors_7cc::operator()( const Packets_t& componentAssemblys_7cd)
{
#ifdef PRINT_INFO
	std::cout << "DestroyPublishConnectors_7cc" << std::endl;
#endif
	processInputPackets( componentAssemblys_7cd);
}

bool DestroyPublishConnectors_7cc::isInputUnique( const Udm::Object& componentAssembly_7d3)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_7d5= _componentAssembly_7cf.begin(); itComponentAssembly_7d5!= _componentAssembly_7cf.end(); ++itComponentAssembly_7d5)
	{
		if( ( *itComponentAssembly_7d5== componentAssembly_7d3))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_componentAssembly_7cf.push_back( componentAssembly_7d3);
	return isUnique;
}

void DestroyPublishConnectors_7cc::processInputPackets( const Packets_t& componentAssemblys_7cd)
{
	for( Packets_t::const_iterator itComponentAssembly_7d0= componentAssemblys_7cd.begin(); itComponentAssembly_7d0!= componentAssemblys_7cd.end(); ++itComponentAssembly_7d0)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_7d0);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_7d0);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool DestroyPublishConnectors_7cc::patternMatcher( const Udm::Object& componentAssembly_7d1)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_7d1.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_7d6= PICML::ComponentAssembly::Cast( componentAssembly_7d1);
		set< PICML::PublishConnector> publishConnectors_7d8= componentAssembly_7d6.PublishConnector_kind_children();
		for( set< PICML::PublishConnector>::const_iterator itPublishConnector_7d9= publishConnectors_7d8.begin(); itPublishConnector_7d9!= publishConnectors_7d8.end(); ++itPublishConnector_7d9)
		{
			PICML::PublishConnector currPublishConnector_7da= *itPublishConnector_7d9;
			cadena_scenario::ESSConnection eSSConnection_7db= currPublishConnector_7da.cadenaESSConnection();
			if( !eSSConnection_7db)
				continue;
			Match currMatch;
			currMatch.eSSConnection_7dc= eSSConnection_7db;
			currMatch.publishConnector_7dd= currPublishConnector_7da;
			currMatch.componentAssembly_7de= componentAssembly_7d6;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void DestroyPublishConnectors_7cc::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.publishConnector_7dd.cadenaESSConnection()= Udm::null;
		set< PICML::deliverTo> deldeliverTos_7df= currMatch.publishConnector_7dd.dstdeliverTo();
		for( set< PICML::deliverTo>::const_iterator itdeldeliverTos_7df= deldeliverTos_7df.begin(); itdeldeliverTos_7df!= deldeliverTos_7df.end(); ++itdeldeliverTos_7df)
		{
			PICML::deliverTo currdeliverTo_7e0= *itdeldeliverTos_7df;
			if( currdeliverTo_7e0)
				currdeliverTo_7e0.DeleteObject();
		}
		set< PICML::publish> delpublishs_7e1= currMatch.publishConnector_7dd.srcpublish();
		for( set< PICML::publish>::const_iterator itdelpublishs_7e1= delpublishs_7e1.begin(); itdelpublishs_7e1!= delpublishs_7e1.end(); ++itdelpublishs_7e1)
		{
			PICML::publish currpublish_7e2= *itdelpublishs_7e1;
			if( currpublish_7e2)
				currpublish_7e2.DeleteObject();
		}
		set< PICML::AssemblyDeployRequirement> delAssemblyDeployRequirements_7e3= currMatch.publishConnector_7dd.dstAssemblyDeployRequirement();
		for( set< PICML::AssemblyDeployRequirement>::const_iterator itdelAssemblyDeployRequirements_7e3= delAssemblyDeployRequirements_7e3.begin(); itdelAssemblyDeployRequirements_7e3!= delAssemblyDeployRequirements_7e3.end(); ++itdelAssemblyDeployRequirements_7e3)
		{
			PICML::AssemblyDeployRequirement currAssemblyDeployRequirement_7e4= *itdelAssemblyDeployRequirements_7e3;
			if( currAssemblyDeployRequirement_7e4)
				currAssemblyDeployRequirement_7e4.DeleteObject();
		}
		if( currMatch.publishConnector_7dd)
			currMatch.publishConnector_7dd.DeleteObject();
		outputAppender( );
	}
}

void DestroyPublishConnectors_7cc::outputAppender()
{
}

void FinalPackage_InstantiateComponent_7e5::operator()( const Packets_t& componentInstances_7e6, const Packets_t& packages_7e9, const Packets_t& componentAssemblys_7eb, Packets_t& componentInstances_7e8, Packets_t& componentAssemblys_7ed)
{
#ifdef PRINT_INFO
	std::cout << "FinalPackage_InstantiateComponent_7e5" << std::endl;
#endif
	_componentInstance_7ee= &componentInstances_7e8;
	_componentAssembly_7ef= &componentAssemblys_7ed;
	processInputPackets( componentInstances_7e6, packages_7e9, componentAssemblys_7eb);
	forwardInputs( );
}

bool FinalPackage_InstantiateComponent_7e5::isInputUnique( const Udm::Object& componentInstance_7f4, const Udm::Object& package_7fd, const Udm::Object& componentAssembly_806)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentInstance_7f6= _componentInstance_7f0.begin(), itPackage_7ff= _package_7f9.begin(), itComponentAssembly_808= _componentAssembly_802.begin(); itComponentInstance_7f6!= _componentInstance_7f0.end(), itPackage_7ff!= _package_7f9.end(), itComponentAssembly_808!= _componentAssembly_802.end(); ++itComponentInstance_7f6, ++itPackage_7ff, ++itComponentAssembly_808)
	{
		if( ( *itComponentInstance_7f6== componentInstance_7f4)&& ( *itPackage_7ff== package_7fd)&& ( *itComponentAssembly_808== componentAssembly_806))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentInstance_7f0.push_back( componentInstance_7f4);
		_package_7f9.push_back( package_7fd);
		_componentAssembly_802.push_back( componentAssembly_806);
	}
	return isUnique;
}

bool FinalPackage_InstantiateComponent_7e5::isGuardTrue( const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentInstance, const Udm::Object& Package)
{
	bool Gz_guard= false;
	string pComponentType, cComponentType; Component.GetStrValue("name", pComponentType); ComponentInstance.GetStrValue("type", cComponentType);  return (pComponentType==cComponentType);;
	return Gz_guard;
}

void FinalPackage_InstantiateComponent_7e5::processInputPackets( const Packets_t& componentInstances_7e6, const Packets_t& packages_7e9, const Packets_t& componentAssemblys_7eb)
{
	for( Packets_t::const_iterator itComponentInstance_7f1= componentInstances_7e6.begin(), itPackage_7fa= packages_7e9.begin(), itComponentAssembly_803= componentAssemblys_7eb.begin(); itComponentInstance_7f1!= componentInstances_7e6.end(), itPackage_7fa!= packages_7e9.end(), itComponentAssembly_803!= componentAssemblys_7eb.end(); ++itComponentInstance_7f1, ++itPackage_7fa, ++itComponentAssembly_803)
	{
		bool isUnique= isInputUnique( *itComponentInstance_7f1, *itPackage_7fa, *itComponentAssembly_803);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentInstance_7f1, *itPackage_7fa, *itComponentAssembly_803);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool FinalPackage_InstantiateComponent_7e5::patternMatcher( const Udm::Object& componentInstance_7f2, const Udm::Object& package_7fb, const Udm::Object& componentAssembly_804)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentInstance_7f2.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_7f7= cadena_scenario::ComponentInstance::Cast( componentInstance_7f2);
		if( false== Uml::IsDerivedFrom( package_7fb.type(), PICML::Package::meta))
			continue;
		PICML::Package package_800= PICML::Package::Cast( package_7fb);
		if( false== Uml::IsDerivedFrom( componentAssembly_804.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_809= PICML::ComponentAssembly::Cast( componentAssembly_804);
		set< PICML::Component> components_80b= package_800.Component_kind_children();
		for( set< PICML::Component>::const_iterator itComponent_80c= components_80b.begin(); itComponent_80c!= components_80b.end(); ++itComponent_80c)
		{
			PICML::Component currComponent_80d= *itComponent_80c;
			Match currMatch;
			currMatch.componentInstance_80e= componentInstance_7f7;
			currMatch.component_80f= currComponent_80d;
			currMatch.package_810= package_800;
			currMatch.componentAssembly_811= componentAssembly_809;
			bool Gz_guard= isGuardTrue( currMatch.component_80f, currMatch.componentAssembly_811, currMatch.componentInstance_80e, currMatch.package_810);
			if( true== Gz_guard)
				_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void FinalPackage_InstantiateComponent_7e5::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& Component= currMatch.component_80f;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_811;
		Udm::Object& ComponentInstance= currMatch.componentInstance_80e;
		Udm::Object& Package= currMatch.package_810;
		{string cadname; ComponentInstance.GetStrValue("name", cadname); Udm::ObjectImpl *newComponent = ComponentAssembly.__impl()->createChild(Udm::NULLCHILDROLE, Component.type(), Component.__impl()); newComponent ->setStringAttr(Uml::Attribute::meta_name, cadname);};
		outputAppender( currMatch.componentInstance_80e, currMatch.componentAssembly_811);
	}
}

void FinalPackage_InstantiateComponent_7e5::outputAppender( const cadena_scenario::ComponentInstance& componentInstance_816, const PICML::ComponentAssembly& componentAssembly_818)
{
	_componentInstance_7ee->push_back( componentInstance_816);
	_componentAssembly_7ef->push_back( componentAssembly_818);
}

void FinalPackage_InstantiateComponent_7e5::forwardInputs()
{
	*_componentInstance_7ee= _componentInstance_7f0;
	*_componentAssembly_7ef= _componentAssembly_802;
}

void FindSubPackage_81a::operator()( const Packets_t& componentInstances_81b, const Packets_t& packages_81f, const Packets_t& componentAssemblys_821, Packets_t& componentInstances_81d, Packets_t& packages_81e, Packets_t& componentAssemblys_823)
{
#ifdef PRINT_INFO
	std::cout << "FindSubPackage_81a" << std::endl;
#endif
	_componentInstance_824= &componentInstances_81d;
	_package_825= &packages_81e;
	_componentAssembly_826= &componentAssemblys_823;
	processInputPackets( componentInstances_81b, packages_81f, componentAssemblys_821);
}

bool FindSubPackage_81a::isInputUnique( const Udm::Object& componentInstance_82b, const Udm::Object& package_834, const Udm::Object& componentAssembly_83d)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentInstance_82d= _componentInstance_827.begin(), itPackage_836= _package_830.begin(), itComponentAssembly_83f= _componentAssembly_839.begin(); itComponentInstance_82d!= _componentInstance_827.end(), itPackage_836!= _package_830.end(), itComponentAssembly_83f!= _componentAssembly_839.end(); ++itComponentInstance_82d, ++itPackage_836, ++itComponentAssembly_83f)
	{
		if( ( *itComponentInstance_82d== componentInstance_82b)&& ( *itPackage_836== package_834)&& ( *itComponentAssembly_83f== componentAssembly_83d))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentInstance_827.push_back( componentInstance_82b);
		_package_830.push_back( package_834);
		_componentAssembly_839.push_back( componentAssembly_83d);
	}
	return isUnique;
}

void FindSubPackage_81a::processInputPackets( const Packets_t& componentInstances_81b, const Packets_t& packages_81f, const Packets_t& componentAssemblys_821)
{
	for( Packets_t::const_iterator itComponentInstance_828= componentInstances_81b.begin(), itPackage_831= packages_81f.begin(), itComponentAssembly_83a= componentAssemblys_821.begin(); itComponentInstance_828!= componentInstances_81b.end(), itPackage_831!= packages_81f.end(), itComponentAssembly_83a!= componentAssemblys_821.end(); ++itComponentInstance_828, ++itPackage_831, ++itComponentAssembly_83a)
	{
		bool isUnique= isInputUnique( *itComponentInstance_828, *itPackage_831, *itComponentAssembly_83a);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentInstance_828, *itPackage_831, *itComponentAssembly_83a);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool FindSubPackage_81a::patternMatcher( const Udm::Object& componentInstance_829, const Udm::Object& package_832, const Udm::Object& componentAssembly_83b)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentInstance_829.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_82e= cadena_scenario::ComponentInstance::Cast( componentInstance_829);
		if( false== Uml::IsDerivedFrom( package_832.type(), PICML::Package::meta))
			continue;
		PICML::Package package_837= PICML::Package::Cast( package_832);
		if( false== Uml::IsDerivedFrom( componentAssembly_83b.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_840= PICML::ComponentAssembly::Cast( componentAssembly_83b);
		set< PICML::Package> packages_842= package_837.Package_kind_children();
		for( set< PICML::Package>::const_iterator itPackage_843= packages_842.begin(); itPackage_843!= packages_842.end(); ++itPackage_843)
		{
			PICML::Package currPackage_844= *itPackage_843;
			Match currMatch;
			currMatch.componentInstance_845= componentInstance_82e;
			currMatch.package_846= currPackage_844;
			currMatch.package_847= package_837;
			currMatch.componentAssembly_848= componentAssembly_840;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void FindSubPackage_81a::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.componentInstance_845, currMatch.package_846, currMatch.componentAssembly_848);
	}
}

void FindSubPackage_81a::outputAppender( const cadena_scenario::ComponentInstance& componentInstance_849, const PICML::Package& package_84b, const PICML::ComponentAssembly& componentAssembly_84d)
{
	_componentInstance_824->push_back( componentInstance_849);
	_package_825->push_back( package_84b);
	_componentAssembly_826->push_back( componentAssembly_84d);
}

void MatchAPackage_84f::operator()( const Packets_t& componentAssemblys_850, const Packets_t& packages_853, const Packets_t& componentInstances_856, Packets_t& componentAssemblys_852, Packets_t& packages_855, Packets_t& componentInstances_858)
{
#ifdef PRINT_INFO
	std::cout << "MatchAPackage_84f" << std::endl;
#endif
	_componentAssembly_859= &componentAssemblys_852;
	_package_85a= &packages_855;
	_componentInstance_85b= &componentInstances_858;
	processInputPackets( componentAssemblys_850, packages_853, componentInstances_856);
	forwardInputs( );
}

bool MatchAPackage_84f::isInputUnique( const Udm::Object& componentAssembly_860, const Udm::Object& package_869, const Udm::Object& componentInstance_872)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_862= _componentAssembly_85c.begin(), itPackage_86b= _package_865.begin(), itComponentInstance_874= _componentInstance_86e.begin(); itComponentAssembly_862!= _componentAssembly_85c.end(), itPackage_86b!= _package_865.end(), itComponentInstance_874!= _componentInstance_86e.end(); ++itComponentAssembly_862, ++itPackage_86b, ++itComponentInstance_874)
	{
		if( ( *itComponentAssembly_862== componentAssembly_860)&& ( *itPackage_86b== package_869)&& ( *itComponentInstance_874== componentInstance_872))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentAssembly_85c.push_back( componentAssembly_860);
		_package_865.push_back( package_869);
		_componentInstance_86e.push_back( componentInstance_872);
	}
	return isUnique;
}

void MatchAPackage_84f::processInputPackets( const Packets_t& componentAssemblys_850, const Packets_t& packages_853, const Packets_t& componentInstances_856)
{
	for( Packets_t::const_iterator itComponentAssembly_85d= componentAssemblys_850.begin(), itPackage_866= packages_853.begin(), itComponentInstance_86f= componentInstances_856.begin(); itComponentAssembly_85d!= componentAssemblys_850.end(), itPackage_866!= packages_853.end(), itComponentInstance_86f!= componentInstances_856.end(); ++itComponentAssembly_85d, ++itPackage_866, ++itComponentInstance_86f)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_85d, *itPackage_866, *itComponentInstance_86f);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_85d, *itPackage_866, *itComponentInstance_86f);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool MatchAPackage_84f::patternMatcher( const Udm::Object& componentAssembly_85e, const Udm::Object& package_867, const Udm::Object& componentInstance_870)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_85e.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_863= PICML::ComponentAssembly::Cast( componentAssembly_85e);
		if( false== Uml::IsDerivedFrom( package_867.type(), PICML::Package::meta))
			continue;
		PICML::Package package_86c= PICML::Package::Cast( package_867);
		if( false== Uml::IsDerivedFrom( componentInstance_870.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_875= cadena_scenario::ComponentInstance::Cast( componentInstance_870);
		Match currMatch;
		currMatch.componentAssembly_877= componentAssembly_863;
		currMatch.package_878= package_86c;
		currMatch.componentInstance_879= componentInstance_875;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void MatchAPackage_84f::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.componentAssembly_877, currMatch.package_878, currMatch.componentInstance_879);
	}
}

void MatchAPackage_84f::outputAppender( const PICML::ComponentAssembly& componentAssembly_87a, const PICML::Package& package_87c, const cadena_scenario::ComponentInstance& componentInstance_87e)
{
	_componentAssembly_859->push_back( componentAssembly_87a);
	_package_85a->push_back( package_87c);
	_componentInstance_85b->push_back( componentInstance_87e);
}

void MatchAPackage_84f::forwardInputs()
{
	*_componentAssembly_859= _componentAssembly_85c;
	*_package_85a= _package_865;
	*_componentInstance_85b= _componentInstance_86e;
}

void AssociateComponentsNow_880::operator()( const Packets_t& componentAssemblys_881, const Packets_t& componentInstances_883)
{
#ifdef PRINT_INFO
	std::cout << "AssociateComponentsNow_880" << std::endl;
#endif
	processInputPackets( componentAssemblys_881, componentInstances_883);
}

bool AssociateComponentsNow_880::isInputUnique( const Udm::Object& componentAssembly_889, const Udm::Object& componentInstance_892)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_88b= _componentAssembly_885.begin(), itComponentInstance_894= _componentInstance_88e.begin(); itComponentAssembly_88b!= _componentAssembly_885.end(), itComponentInstance_894!= _componentInstance_88e.end(); ++itComponentAssembly_88b, ++itComponentInstance_894)
	{
		if( ( *itComponentAssembly_88b== componentAssembly_889)&& ( *itComponentInstance_894== componentInstance_892))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentAssembly_885.push_back( componentAssembly_889);
		_componentInstance_88e.push_back( componentInstance_892);
	}
	return isUnique;
}

bool AssociateComponentsNow_880::isGuardTrue( const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentInstance)
{
	bool Gz_guard= false;
	string pType, cType, pName, cName;  Component.archetype().GetStrValue("name", pType); Component.GetStrValue("name", pName); ComponentInstance.GetStrValue("type", cType); ComponentInstance.GetStrValue("name", cName);  if (pType==cType && pName==cName) return true; else return false;;
	return Gz_guard;
}

void AssociateComponentsNow_880::processInputPackets( const Packets_t& componentAssemblys_881, const Packets_t& componentInstances_883)
{
	for( Packets_t::const_iterator itComponentAssembly_886= componentAssemblys_881.begin(), itComponentInstance_88f= componentInstances_883.begin(); itComponentAssembly_886!= componentAssemblys_881.end(), itComponentInstance_88f!= componentInstances_883.end(); ++itComponentAssembly_886, ++itComponentInstance_88f)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_886, *itComponentInstance_88f);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_886, *itComponentInstance_88f);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool AssociateComponentsNow_880::patternMatcher( const Udm::Object& componentAssembly_887, const Udm::Object& componentInstance_890)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_887.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_88c= PICML::ComponentAssembly::Cast( componentAssembly_887);
		if( false== Uml::IsDerivedFrom( componentInstance_890.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_895= cadena_scenario::ComponentInstance::Cast( componentInstance_890);
		set< PICML::Component> components_897= componentAssembly_88c.Component_kind_children();
		for( set< PICML::Component>::const_iterator itComponent_898= components_897.begin(); itComponent_898!= components_897.end(); ++itComponent_898)
		{
			PICML::Component currComponent_899= *itComponent_898;
			Match currMatch;
			currMatch.component_89a= currComponent_899;
			currMatch.componentAssembly_89b= componentAssembly_88c;
			currMatch.componentInstance_89c= componentInstance_895;
			bool Gz_guard= isGuardTrue( currMatch.component_89a, currMatch.componentAssembly_89b, currMatch.componentInstance_89c);
			if( true== Gz_guard)
				_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void AssociateComponentsNow_880::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.component_89a.cadenaComponentInstance()= currMatch.componentInstance_89c;
		outputAppender( );
	}
}

void AssociateComponentsNow_880::outputAppender()
{
}

void FindFirstPackage_8a0::operator()( const Packets_t& componentAssemblys_8a2, const Packets_t& componentInstances_8a5, Packets_t& packages_8a1, Packets_t& componentAssemblys_8a4, Packets_t& componentInstances_8a7)
{
#ifdef PRINT_INFO
	std::cout << "FindFirstPackage_8a0" << std::endl;
#endif
	_package_8a8= &packages_8a1;
	_componentAssembly_8a9= &componentAssemblys_8a4;
	_componentInstance_8aa= &componentInstances_8a7;
	processInputPackets( componentAssemblys_8a2, componentInstances_8a5);
}

bool FindFirstPackage_8a0::isInputUnique( const Udm::Object& componentAssembly_8af, const Udm::Object& componentInstance_8b8)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_8b1= _componentAssembly_8ab.begin(), itComponentInstance_8ba= _componentInstance_8b4.begin(); itComponentAssembly_8b1!= _componentAssembly_8ab.end(), itComponentInstance_8ba!= _componentInstance_8b4.end(); ++itComponentAssembly_8b1, ++itComponentInstance_8ba)
	{
		if( ( *itComponentAssembly_8b1== componentAssembly_8af)&& ( *itComponentInstance_8ba== componentInstance_8b8))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentAssembly_8ab.push_back( componentAssembly_8af);
		_componentInstance_8b4.push_back( componentInstance_8b8);
	}
	return isUnique;
}

void FindFirstPackage_8a0::processInputPackets( const Packets_t& componentAssemblys_8a2, const Packets_t& componentInstances_8a5)
{
	for( Packets_t::const_iterator itComponentAssembly_8ac= componentAssemblys_8a2.begin(), itComponentInstance_8b5= componentInstances_8a5.begin(); itComponentAssembly_8ac!= componentAssemblys_8a2.end(), itComponentInstance_8b5!= componentInstances_8a5.end(); ++itComponentAssembly_8ac, ++itComponentInstance_8b5)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_8ac, *itComponentInstance_8b5);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_8ac, *itComponentInstance_8b5);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool FindFirstPackage_8a0::patternMatcher( const Udm::Object& componentAssembly_8ad, const Udm::Object& componentInstance_8b6)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_8ad.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_8b2= PICML::ComponentAssembly::Cast( componentAssembly_8ad);
		if( false== Uml::IsDerivedFrom( componentInstance_8b6.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_8bb= cadena_scenario::ComponentInstance::Cast( componentInstance_8b6);
		Udm::Object componentAssemblyParent_8bd= componentAssembly_8b2.container();
		if( false== Uml::IsDerivedFrom( componentAssemblyParent_8bd.type(), PICML::ComponentImplementationContainer::meta))
			continue;
		PICML::ComponentImplementationContainer componentImplementationContainerComponentAssembly_8be= PICML::ComponentImplementationContainer::Cast( componentAssemblyParent_8bd);
		Udm::Object componentImplementationContainerParent_8bf= componentImplementationContainerComponentAssembly_8be.container();
		if( false== Uml::IsDerivedFrom( componentImplementationContainerParent_8bf.type(), PICML::ComponentImplementations::meta))
			continue;
		PICML::ComponentImplementations componentImplementationsComponentImplementationContainer_8c0= PICML::ComponentImplementations::Cast( componentImplementationContainerParent_8bf);
		Udm::Object componentImplementationsParent_8c1= componentImplementationsComponentImplementationContainer_8c0.container();
		if( false== Uml::IsDerivedFrom( componentImplementationsParent_8c1.type(), PICML::RootFolder::meta))
			continue;
		PICML::RootFolder rootFolderComponentImplementations_8c2= PICML::RootFolder::Cast( componentImplementationsParent_8c1);
		set< PICML::InterfaceDefinitions> interfaceDefinitionss_8c3= rootFolderComponentImplementations_8c2.InterfaceDefinitions_kind_children();
		for( set< PICML::InterfaceDefinitions>::const_iterator itInterfaceDefinitions_8c4= interfaceDefinitionss_8c3.begin(); itInterfaceDefinitions_8c4!= interfaceDefinitionss_8c3.end(); ++itInterfaceDefinitions_8c4)
		{
			PICML::InterfaceDefinitions currInterfaceDefinitions_8c5= *itInterfaceDefinitions_8c4;
			set< PICML::File> files_8c6= currInterfaceDefinitions_8c5.File_kind_children();
			for( set< PICML::File>::const_iterator itFile_8c7= files_8c6.begin(); itFile_8c7!= files_8c6.end(); ++itFile_8c7)
			{
				PICML::File currFile_8c8= *itFile_8c7;
				set< PICML::Package> packages_8c9= currFile_8c8.Package_kind_children();
				for( set< PICML::Package>::const_iterator itPackage_8ca= packages_8c9.begin(); itPackage_8ca!= packages_8c9.end(); ++itPackage_8ca)
				{
					PICML::Package currPackage_8cb= *itPackage_8ca;
					Match currMatch;
					currMatch.file_8cc= currFile_8c8;
					currMatch.package_8cd= currPackage_8cb;
					currMatch.interfaceDefinitions_8ce= currInterfaceDefinitions_8c5;
					currMatch.componentImplementations_8cf= componentImplementationsComponentImplementationContainer_8c0;
					currMatch.componentImplementationContainer_8d0= componentImplementationContainerComponentAssembly_8be;
					currMatch.rootFolder_8d1= rootFolderComponentImplementations_8c2;
					currMatch.componentAssembly_8d2= componentAssembly_8b2;
					currMatch.componentInstance_8d3= componentInstance_8bb;
					_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void FindFirstPackage_8a0::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.package_8cd, currMatch.componentAssembly_8d2, currMatch.componentInstance_8d3);
	}
}

void FindFirstPackage_8a0::outputAppender( const PICML::Package& package_8d4, const PICML::ComponentAssembly& componentAssembly_8d6, const cadena_scenario::ComponentInstance& componentInstance_8d8)
{
	_package_8a8->push_back( package_8d4);
	_componentAssembly_8a9->push_back( componentAssembly_8d6);
	_componentInstance_8aa->push_back( componentInstance_8d8);
}

void FindComponents2BDeleted_8da::operator()( const Packets_t& componentAssemblys_8dc, Packets_t& components_8db)
{
#ifdef PRINT_INFO
	std::cout << "FindComponents2BDeleted_8da" << std::endl;
#endif
	_component_8de= &components_8db;
	processInputPackets( componentAssemblys_8dc);
}

bool FindComponents2BDeleted_8da::isInputUnique( const Udm::Object& componentAssembly_8e3)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_8e5= _componentAssembly_8df.begin(); itComponentAssembly_8e5!= _componentAssembly_8df.end(); ++itComponentAssembly_8e5)
	{
		if( ( *itComponentAssembly_8e5== componentAssembly_8e3))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_componentAssembly_8df.push_back( componentAssembly_8e3);
	return isUnique;
}

void FindComponents2BDeleted_8da::processInputPackets( const Packets_t& componentAssemblys_8dc)
{
	for( Packets_t::const_iterator itComponentAssembly_8e0= componentAssemblys_8dc.begin(); itComponentAssembly_8e0!= componentAssemblys_8dc.end(); ++itComponentAssembly_8e0)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_8e0);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_8e0);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool FindComponents2BDeleted_8da::patternMatcher( const Udm::Object& componentAssembly_8e1)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_8e1.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_8e6= PICML::ComponentAssembly::Cast( componentAssembly_8e1);
		set< PICML::Component> components_8e8= componentAssembly_8e6.Component_kind_children();
		for( set< PICML::Component>::const_iterator itComponent_8e9= components_8e8.begin(); itComponent_8e9!= components_8e8.end(); ++itComponent_8e9)
		{
			PICML::Component currComponent_8ea= *itComponent_8e9;
			cadena_scenario::ComponentInstance componentInstance_8eb= currComponent_8ea.cadenaComponentInstance();
			if( !componentInstance_8eb)
				continue;
			Match currMatch;
			currMatch.component_8ec= currComponent_8ea;
			currMatch.componentInstance_8ed= componentInstance_8eb;
			currMatch.componentAssembly_8ee= componentAssembly_8e6;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void FindComponents2BDeleted_8da::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.component_8ec);
	}
}

void FindComponents2BDeleted_8da::outputAppender( const PICML::Component& component_8ef)
{
	_component_8de->push_back( component_8ef);
}

void CreateComponents_step1_8f1::operator()( const Packets_t& scenarios_8f3, const Packets_t& componentAssemblys_8f5, Packets_t& componentInstances_8f2, Packets_t& componentAssemblys_8f7)
{
#ifdef PRINT_INFO
	std::cout << "CreateComponents_step1_8f1" << std::endl;
#endif
	_componentInstance_8f8= &componentInstances_8f2;
	_componentAssembly_8f9= &componentAssemblys_8f7;
	processInputPackets( scenarios_8f3, componentAssemblys_8f5);
}

bool CreateComponents_step1_8f1::isInputUnique( const Udm::Object& scenario_8fe, const Udm::Object& componentAssembly_907)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_900= _scenario_8fa.begin(), itComponentAssembly_909= _componentAssembly_903.begin(); itScenario_900!= _scenario_8fa.end(), itComponentAssembly_909!= _componentAssembly_903.end(); ++itScenario_900, ++itComponentAssembly_909)
	{
		if( ( *itScenario_900== scenario_8fe)&& ( *itComponentAssembly_909== componentAssembly_907))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_8fa.push_back( scenario_8fe);
		_componentAssembly_903.push_back( componentAssembly_907);
	}
	return isUnique;
}

void CreateComponents_step1_8f1::processInputPackets( const Packets_t& scenarios_8f3, const Packets_t& componentAssemblys_8f5)
{
	for( Packets_t::const_iterator itScenario_8fb= scenarios_8f3.begin(), itComponentAssembly_904= componentAssemblys_8f5.begin(); itScenario_8fb!= scenarios_8f3.end(), itComponentAssembly_904!= componentAssemblys_8f5.end(); ++itScenario_8fb, ++itComponentAssembly_904)
	{
		bool isUnique= isInputUnique( *itScenario_8fb, *itComponentAssembly_904);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_8fb, *itComponentAssembly_904);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool CreateComponents_step1_8f1::patternMatcher( const Udm::Object& scenario_8fc, const Udm::Object& componentAssembly_905)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_8fc.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_901= cadena_scenario::Scenario::Cast( scenario_8fc);
		if( false== Uml::IsDerivedFrom( componentAssembly_905.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_90a= PICML::ComponentAssembly::Cast( componentAssembly_905);
		set< cadena_scenario::ComponentInstance> componentInstances_90c= scenario_901.ComponentInstance_kind_children();
		for( set< cadena_scenario::ComponentInstance>::const_iterator itComponentInstance_90d= componentInstances_90c.begin(); itComponentInstance_90d!= componentInstances_90c.end(); ++itComponentInstance_90d)
		{
			cadena_scenario::ComponentInstance currComponentInstance_90e= *itComponentInstance_90d;
			PICML::Component component_90f= currComponentInstance_90e.picmlComponentDef();
			if( !component_90f)
				continue;
			Match currMatch;
			currMatch.componentInstance_910= currComponentInstance_90e;
			currMatch.scenario_911= scenario_901;
			currMatch.component_912= component_90f;
			currMatch.componentAssembly_913= componentAssembly_90a;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void CreateComponents_step1_8f1::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.componentInstance_910, currMatch.componentAssembly_913);
	}
}

void CreateComponents_step1_8f1::outputAppender( const cadena_scenario::ComponentInstance& componentInstance_914, const PICML::ComponentAssembly& componentAssembly_916)
{
	_componentInstance_8f8->push_back( componentInstance_914);
	_componentAssembly_8f9->push_back( componentAssembly_916);
}

void ReCreate_Connections_940::operator()( const Packets_t& pAssemblys_941, const Packets_t& cScenarios_943, Packets_t& cScenarios_945, Packets_t& pAssemblys_946)
{
#ifdef PRINT_INFO
	std::cout << "ReCreate_Connections_940" << std::endl;
#endif
	_cScenario_947= &cScenarios_945;
	_pAssembly_948= &pAssemblys_946;
	if( ( !cScenarios_943.empty()))
		callCreate_SrcPublish_9ea( cScenarios_943);
	if( ( !cScenarios_943.empty()))
		callCreate_DeliverTo_9ec( cScenarios_943);
	if( ( !cScenarios_943.empty()))
		callCreate_Invokes_9ee( cScenarios_943);
	if( ( !cScenarios_943.empty()))
		callCreate_Emits_9f0( cScenarios_943);
	_pAssembly_948->insert( _pAssembly_948->end(), pAssemblys_941.begin(), pAssemblys_941.end());
	_cScenario_947->insert( _cScenario_947->end(), cScenarios_943.begin(), cScenarios_943.end());
}

void ReCreate_Connections_940::callCreate_SrcPublish_9ea( const Packets_t& scenarios_9a5)
{
	Create_SrcPublish_9a4 create_SrcPublish_9a4;
	create_SrcPublish_9a4( scenarios_9a5);
}

void ReCreate_Connections_940::callCreate_DeliverTo_9ec( const Packets_t& scenarios_9c8)
{
	Create_DeliverTo_9c7 create_DeliverTo_9c7;
	create_DeliverTo_9c7( scenarios_9c8);
}

void ReCreate_Connections_940::callCreate_Invokes_9ee( const Packets_t& scenarios_94a)
{
	Create_Invokes_949 create_Invokes_949;
	create_Invokes_949( scenarios_94a);
}

void ReCreate_Connections_940::callCreate_Emits_9f0( const Packets_t& scenarios_972)
{
	Create_Emits_971 create_Emits_971;
	create_Emits_971( scenarios_972);
}

void Create_Invokes_949::operator()( const Packets_t& scenarios_94a)
{
#ifdef PRINT_INFO
	std::cout << "Create_Invokes_949" << std::endl;
#endif
	processInputPackets( scenarios_94a);
}

bool Create_Invokes_949::isInputUnique( const Udm::Object& scenario_950)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_952= _scenario_94c.begin(); itScenario_952!= _scenario_94c.end(); ++itScenario_952)
	{
		if( ( *itScenario_952== scenario_950))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_94c.push_back( scenario_950);
	return isUnique;
}

void Create_Invokes_949::processInputPackets( const Packets_t& scenarios_94a)
{
	for( Packets_t::const_iterator itScenario_94d= scenarios_94a.begin(); itScenario_94d!= scenarios_94a.end(); ++itScenario_94d)
	{
		bool isUnique= isInputUnique( *itScenario_94d);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_94d);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Create_Invokes_949::patternMatcher( const Udm::Object& scenario_94e)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_94e.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_953= cadena_scenario::Scenario::Cast( scenario_94e);
		set< cadena_scenario::ComponentInstance> componentInstances_955= scenario_953.ComponentInstance_kind_children();
		for( set< cadena_scenario::ComponentInstance>::const_iterator itComponentInstance_956= componentInstances_955.begin(); itComponentInstance_956!= componentInstances_955.end(); ++itComponentInstance_956)
		{
			cadena_scenario::ComponentInstance currComponentInstance_957= *itComponentInstance_956;
			set< cadena_scenario::Receptacle> receptacles_958= currComponentInstance_957.Receptacle_kind_children();
			for( set< cadena_scenario::Receptacle>::const_iterator itReceptacle_959= receptacles_958.begin(); itReceptacle_959!= receptacles_958.end(); ++itReceptacle_959)
			{
				cadena_scenario::Receptacle currReceptacle_95a= *itReceptacle_959;
				PICML::Port requiredRequestPort_95b= currReceptacle_95a.picmlPort();
				if( false== Uml::IsDerivedFrom( requiredRequestPort_95b.type(), PICML::RequiredRequestPort::meta))
					continue;
				PICML::RequiredRequestPort requiredRequestPort_95c= PICML::RequiredRequestPort::Cast( requiredRequestPort_95b);
				if( !requiredRequestPort_95c)
					continue;
				Udm::Object requiredRequestPortParent_95d= requiredRequestPort_95c.container();
				if( false== Uml::IsDerivedFrom( requiredRequestPortParent_95d.type(), PICML::Component::meta))
					continue;
				PICML::Component componentRequiredRequestPort_95e= PICML::Component::Cast( requiredRequestPortParent_95d);
				Udm::Object componentParent_95f= componentRequiredRequestPort_95e.container();
				if( false== Uml::IsDerivedFrom( componentParent_95f.type(), PICML::ComponentAssembly::meta))
					continue;
				PICML::ComponentAssembly componentAssemblyComponent_960= PICML::ComponentAssembly::Cast( componentParent_95f);
				set< cadena_scenario::FRConnection> fRConnections_961= currReceptacle_95a.facets();
				for( set< cadena_scenario::FRConnection>::const_iterator itFRConnections_962= fRConnections_961.begin(); itFRConnections_962!= fRConnections_961.end(); ++itFRConnections_962)
				{
					cadena_scenario::FRConnection currFRConnection_963= *itFRConnections_962;
					cadena_scenario::Facet facet_964= currFRConnection_963.facets_end();
					PICML::Port providedRequestPort_965= facet_964.picmlPort();
					if( false== Uml::IsDerivedFrom( providedRequestPort_965.type(), PICML::ProvidedRequestPort::meta))
						continue;
					PICML::ProvidedRequestPort providedRequestPort_966= PICML::ProvidedRequestPort::Cast( providedRequestPort_965);
					if( !providedRequestPort_966)
						continue;
					Match currMatch;
					currMatch.componentInstance_967= currComponentInstance_957;
					currMatch.component_968= componentRequiredRequestPort_95e;
					currMatch.componentAssembly_969= componentAssemblyComponent_960;
					currMatch.fRConnection_96a= currFRConnection_963;
					currMatch.facet_96b= facet_964;
					currMatch.receptacle_96c= currReceptacle_95a;
					currMatch.requiredRequestPort_96d= requiredRequestPort_95c;
					currMatch.providedRequestPort_96e= providedRequestPort_966;
					currMatch.scenario_96f= scenario_953;
					_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void Create_Invokes_949::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::invoke newinvoke_970= PICML::invoke::Create( currMatch.componentAssembly_969);
		newinvoke_970.cadenaInvoke()= currMatch.fRConnection_96a;
		newinvoke_970.srcinvoke_end()= currMatch.requiredRequestPort_96d;
		newinvoke_970.dstinvoke_end()= currMatch.providedRequestPort_96e;
		outputAppender( );
	}
}

void Create_Invokes_949::outputAppender()
{
}

void Create_Emits_971::operator()( const Packets_t& scenarios_972)
{
#ifdef PRINT_INFO
	std::cout << "Create_Emits_971" << std::endl;
#endif
	processInputPackets( scenarios_972);
}

bool Create_Emits_971::isInputUnique( const Udm::Object& scenario_978)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_97a= _scenario_974.begin(); itScenario_97a!= _scenario_974.end(); ++itScenario_97a)
	{
		if( ( *itScenario_97a== scenario_978))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_974.push_back( scenario_978);
	return isUnique;
}

bool Create_Emits_971::isGuardTrue( const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentInstance, const Udm::Object& ESSConnection, const Udm::Object& EventSink, const Udm::Object& EventSource, const Udm::Object& InEventPort, const Udm::Object& OutEventPort, const Udm::Object& Scenario)
{
	bool Gz_guard= false;
	string cConnID; ESSConnection.GetStrValue("ConnectorID", cConnID); return (cConnID=="emit");;
	return Gz_guard;
}

void Create_Emits_971::processInputPackets( const Packets_t& scenarios_972)
{
	for( Packets_t::const_iterator itScenario_975= scenarios_972.begin(); itScenario_975!= scenarios_972.end(); ++itScenario_975)
	{
		bool isUnique= isInputUnique( *itScenario_975);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_975);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Create_Emits_971::patternMatcher( const Udm::Object& scenario_976)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_976.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_97b= cadena_scenario::Scenario::Cast( scenario_976);
		set< cadena_scenario::ComponentInstance> componentInstances_97d= scenario_97b.ComponentInstance_kind_children();
		for( set< cadena_scenario::ComponentInstance>::const_iterator itComponentInstance_97e= componentInstances_97d.begin(); itComponentInstance_97e!= componentInstances_97d.end(); ++itComponentInstance_97e)
		{
			cadena_scenario::ComponentInstance currComponentInstance_97f= *itComponentInstance_97e;
			set< cadena_scenario::EventSource> eventSources_980= currComponentInstance_97f.EventSource_kind_children();
			for( set< cadena_scenario::EventSource>::const_iterator itEventSource_981= eventSources_980.begin(); itEventSource_981!= eventSources_980.end(); ++itEventSource_981)
			{
				cadena_scenario::EventSource currEventSource_982= *itEventSource_981;
				PICML::Port outEventPort_983= currEventSource_982.picmlPort();
				if( false== Uml::IsDerivedFrom( outEventPort_983.type(), PICML::OutEventPort::meta))
					continue;
				PICML::OutEventPort outEventPort_984= PICML::OutEventPort::Cast( outEventPort_983);
				if( !outEventPort_984)
					continue;
				Udm::Object outEventPortParent_985= outEventPort_984.container();
				if( false== Uml::IsDerivedFrom( outEventPortParent_985.type(), PICML::Component::meta))
					continue;
				PICML::Component componentOutEventPort_986= PICML::Component::Cast( outEventPortParent_985);
				Udm::Object componentParent_987= componentOutEventPort_986.container();
				if( false== Uml::IsDerivedFrom( componentParent_987.type(), PICML::ComponentAssembly::meta))
					continue;
				PICML::ComponentAssembly componentAssemblyComponent_988= PICML::ComponentAssembly::Cast( componentParent_987);
				set< cadena_scenario::ESSConnection> eSSConnections_989= currEventSource_982.sinksConnections();
				for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnections_98a= eSSConnections_989.begin(); itESSConnections_98a!= eSSConnections_989.end(); ++itESSConnections_98a)
				{
					cadena_scenario::ESSConnection currESSConnection_98b= *itESSConnections_98a;
					set< cadena_scenario::EventSink> eventSinks_98c= currESSConnection_98b.sinks();
					for( set< cadena_scenario::EventSink>::const_iterator itEventSinks_98d= eventSinks_98c.begin(); itEventSinks_98d!= eventSinks_98c.end(); ++itEventSinks_98d)
					{
						cadena_scenario::EventSink currEventSink_98e= *itEventSinks_98d;
						PICML::Port inEventPort_98f= currEventSink_98e.picmlPort();
						if( false== Uml::IsDerivedFrom( inEventPort_98f.type(), PICML::InEventPort::meta))
							continue;
						PICML::InEventPort inEventPort_990= PICML::InEventPort::Cast( inEventPort_98f);
						if( !inEventPort_990)
							continue;
						Match currMatch;
						currMatch.componentInstance_991= currComponentInstance_97f;
						currMatch.component_992= componentOutEventPort_986;
						currMatch.componentAssembly_993= componentAssemblyComponent_988;
						currMatch.eventSink_994= currEventSink_98e;
						currMatch.eventSource_995= currEventSource_982;
						currMatch.eSSConnection_996= currESSConnection_98b;
						currMatch.scenario_997= scenario_97b;
						currMatch.inEventPort_998= inEventPort_990;
						currMatch.outEventPort_999= outEventPort_984;
						bool Gz_guard= isGuardTrue( currMatch.component_992, currMatch.componentAssembly_993, currMatch.componentInstance_991, currMatch.eSSConnection_996, currMatch.eventSink_994, currMatch.eventSource_995, currMatch.inEventPort_998, currMatch.outEventPort_999, currMatch.scenario_997);
						if( true== Gz_guard)
							_matches.push_back( currMatch);
					}
				}
			}
		}
	}
	return !_matches.empty();
}

void Create_Emits_971::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::emit newemit_9a3= PICML::emit::Create( currMatch.componentAssembly_993);
		newemit_9a3.cadenaEmit()= currMatch.eSSConnection_996;
		newemit_9a3.srcemit_end()= currMatch.outEventPort_999;
		newemit_9a3.dstemit_end()= currMatch.inEventPort_998;
		outputAppender( );
	}
}

void Create_Emits_971::outputAppender()
{
}

void Create_SrcPublish_9a4::operator()( const Packets_t& scenarios_9a5)
{
#ifdef PRINT_INFO
	std::cout << "Create_SrcPublish_9a4" << std::endl;
#endif
	processInputPackets( scenarios_9a5);
}

bool Create_SrcPublish_9a4::isInputUnique( const Udm::Object& scenario_9ab)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_9ad= _scenario_9a7.begin(); itScenario_9ad!= _scenario_9a7.end(); ++itScenario_9ad)
	{
		if( ( *itScenario_9ad== scenario_9ab))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_9a7.push_back( scenario_9ab);
	return isUnique;
}

void Create_SrcPublish_9a4::processInputPackets( const Packets_t& scenarios_9a5)
{
	for( Packets_t::const_iterator itScenario_9a8= scenarios_9a5.begin(); itScenario_9a8!= scenarios_9a5.end(); ++itScenario_9a8)
	{
		bool isUnique= isInputUnique( *itScenario_9a8);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_9a8);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Create_SrcPublish_9a4::patternMatcher( const Udm::Object& scenario_9a9)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_9a9.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_9ae= cadena_scenario::Scenario::Cast( scenario_9a9);
		set< cadena_scenario::ESSConnection> eSSConnections_9b0= scenario_9ae.ESSConnection_kind_children();
		for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnection_9b1= eSSConnections_9b0.begin(); itESSConnection_9b1!= eSSConnections_9b0.end(); ++itESSConnection_9b1)
		{
			cadena_scenario::ESSConnection currESSConnection_9b2= *itESSConnection_9b1;
			set< PICML::PublishConnector> publishConnectors_9b3= currESSConnection_9b2.picmlPublishConnector();
			for( set< PICML::PublishConnector>::const_iterator itPublishConnectors_9b4= publishConnectors_9b3.begin(); itPublishConnectors_9b4!= publishConnectors_9b3.end(); ++itPublishConnectors_9b4)
			{
				PICML::PublishConnector currPublishConnector_9b5= *itPublishConnectors_9b4;
				set< cadena_scenario::EventSource> eventSources_9b6= currESSConnection_9b2.sources();
				for( set< cadena_scenario::EventSource>::const_iterator itEventSources_9b7= eventSources_9b6.begin(); itEventSources_9b7!= eventSources_9b6.end(); ++itEventSources_9b7)
				{
					cadena_scenario::EventSource currEventSource_9b8= *itEventSources_9b7;
					PICML::Port outEventPort_9b9= currEventSource_9b8.picmlPort();
					if( false== Uml::IsDerivedFrom( outEventPort_9b9.type(), PICML::OutEventPort::meta))
						continue;
					PICML::OutEventPort outEventPort_9ba= PICML::OutEventPort::Cast( outEventPort_9b9);
					if( !outEventPort_9ba)
						continue;
					Udm::Object outEventPortParent_9bb= outEventPort_9ba.container();
					if( false== Uml::IsDerivedFrom( outEventPortParent_9bb.type(), PICML::Component::meta))
						continue;
					PICML::Component componentOutEventPort_9bc= PICML::Component::Cast( outEventPortParent_9bb);
					Udm::Object componentParent_9bd= componentOutEventPort_9bc.container();
					if( false== Uml::IsDerivedFrom( componentParent_9bd.type(), PICML::ComponentAssembly::meta))
						continue;
					PICML::ComponentAssembly componentAssemblyComponent_9be= PICML::ComponentAssembly::Cast( componentParent_9bd);
					Match currMatch;
					currMatch.eventSource_9bf= currEventSource_9b8;
					currMatch.eSSConnection_9c0= currESSConnection_9b2;
					currMatch.scenario_9c1= scenario_9ae;
					currMatch.componentAssembly_9c2= componentAssemblyComponent_9be;
					currMatch.component_9c3= componentOutEventPort_9bc;
					currMatch.outEventPort_9c4= outEventPort_9ba;
					currMatch.publishConnector_9c5= currPublishConnector_9b5;
					_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void Create_SrcPublish_9a4::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::publish newpublish_9c6= PICML::publish::Create( currMatch.componentAssembly_9c2);
		newpublish_9c6.srcpublish_end()= currMatch.outEventPort_9c4;
		newpublish_9c6.dstpublish_end()= currMatch.publishConnector_9c5;
		outputAppender( );
	}
}

void Create_SrcPublish_9a4::outputAppender()
{
}

void Create_DeliverTo_9c7::operator()( const Packets_t& scenarios_9c8)
{
#ifdef PRINT_INFO
	std::cout << "Create_DeliverTo_9c7" << std::endl;
#endif
	processInputPackets( scenarios_9c8);
}

bool Create_DeliverTo_9c7::isInputUnique( const Udm::Object& scenario_9ce)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_9d0= _scenario_9ca.begin(); itScenario_9d0!= _scenario_9ca.end(); ++itScenario_9d0)
	{
		if( ( *itScenario_9d0== scenario_9ce))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_scenario_9ca.push_back( scenario_9ce);
	return isUnique;
}

void Create_DeliverTo_9c7::processInputPackets( const Packets_t& scenarios_9c8)
{
	for( Packets_t::const_iterator itScenario_9cb= scenarios_9c8.begin(); itScenario_9cb!= scenarios_9c8.end(); ++itScenario_9cb)
	{
		bool isUnique= isInputUnique( *itScenario_9cb);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_9cb);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Create_DeliverTo_9c7::patternMatcher( const Udm::Object& scenario_9cc)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_9cc.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_9d1= cadena_scenario::Scenario::Cast( scenario_9cc);
		set< cadena_scenario::ESSConnection> eSSConnections_9d3= scenario_9d1.ESSConnection_kind_children();
		for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnection_9d4= eSSConnections_9d3.begin(); itESSConnection_9d4!= eSSConnections_9d3.end(); ++itESSConnection_9d4)
		{
			cadena_scenario::ESSConnection currESSConnection_9d5= *itESSConnection_9d4;
			set< PICML::PublishConnector> publishConnectors_9d6= currESSConnection_9d5.picmlPublishConnector();
			for( set< PICML::PublishConnector>::const_iterator itPublishConnectors_9d7= publishConnectors_9d6.begin(); itPublishConnectors_9d7!= publishConnectors_9d6.end(); ++itPublishConnectors_9d7)
			{
				PICML::PublishConnector currPublishConnector_9d8= *itPublishConnectors_9d7;
				set< cadena_scenario::EventSink> eventSinks_9d9= currESSConnection_9d5.sinks();
				for( set< cadena_scenario::EventSink>::const_iterator itEventSinks_9da= eventSinks_9d9.begin(); itEventSinks_9da!= eventSinks_9d9.end(); ++itEventSinks_9da)
				{
					cadena_scenario::EventSink currEventSink_9db= *itEventSinks_9da;
					PICML::Port inEventPort_9dc= currEventSink_9db.picmlPort();
					if( false== Uml::IsDerivedFrom( inEventPort_9dc.type(), PICML::InEventPort::meta))
						continue;
					PICML::InEventPort inEventPort_9dd= PICML::InEventPort::Cast( inEventPort_9dc);
					if( !inEventPort_9dd)
						continue;
					Udm::Object inEventPortParent_9de= inEventPort_9dd.container();
					if( false== Uml::IsDerivedFrom( inEventPortParent_9de.type(), PICML::Component::meta))
						continue;
					PICML::Component componentInEventPort_9df= PICML::Component::Cast( inEventPortParent_9de);
					Udm::Object componentParent_9e0= componentInEventPort_9df.container();
					if( false== Uml::IsDerivedFrom( componentParent_9e0.type(), PICML::ComponentAssembly::meta))
						continue;
					PICML::ComponentAssembly componentAssemblyComponent_9e1= PICML::ComponentAssembly::Cast( componentParent_9e0);
					Match currMatch;
					currMatch.componentAssembly_9e2= componentAssemblyComponent_9e1;
					currMatch.component_9e3= componentInEventPort_9df;
					currMatch.publishConnector_9e4= currPublishConnector_9d8;
					currMatch.inEventPort_9e5= inEventPort_9dd;
					currMatch.eSSConnection_9e6= currESSConnection_9d5;
					currMatch.eventSink_9e7= currEventSink_9db;
					currMatch.scenario_9e8= scenario_9d1;
					_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void Create_DeliverTo_9c7::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::deliverTo newdeliverTo_9e9= PICML::deliverTo::Create( currMatch.componentAssembly_9e2);
		newdeliverTo_9e9.srcdeliverTo_end()= currMatch.publishConnector_9e4;
		newdeliverTo_9e9.dstdeliverTo_end()= currMatch.inEventPort_9e5;
		outputAppender( );
	}
}

void Create_DeliverTo_9c7::outputAppender()
{
}

