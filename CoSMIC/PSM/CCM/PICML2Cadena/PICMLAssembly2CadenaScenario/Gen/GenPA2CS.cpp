#include "GenPA2CS.h"
#include <UmlExt.h>
#include <UdmUtil.h>

void RootRuleBlock_0::operator()( const Packets_t& cadena_File_Ins_1, const Packets_t& embedded_Dummy_File_Ins_3, const Packets_t& pICML_File_Ins_5)
{
#ifdef PRINT_INFO
	std::cout << "RootRuleBlock_0" << std::endl;
#endif
	if( ( !embedded_Dummy_File_Ins_3.empty())&& ( !cadena_File_Ins_1.empty())&& ( !pICML_File_Ins_5.empty()))
		callAssembly_and_Scenario_Finder_5d0( embedded_Dummy_File_Ins_3, cadena_File_Ins_1, pICML_File_Ins_5);
}

void RootRuleBlock_0::callAssembly_and_Scenario_Finder_5d0( const Packets_t& rootContainers_7d, const Packets_t& scenarioss_7f, const Packets_t& rootFolders_82)
{
	Packets_t scenarios_81;
	Packets_t componentAssemblys_84;
	Assembly_and_Scenario_Finder_7c assembly_and_Scenario_Finder_7c;
	assembly_and_Scenario_Finder_7c( rootContainers_7d, scenarioss_7f, rootFolders_82, scenarios_81, componentAssemblys_84);
	if( ( !componentAssemblys_84.empty())&& ( !scenarios_81.empty()))
		callComponentAndPortCreation_5d4( componentAssemblys_84, scenarios_81);
}

void RootRuleBlock_0::callComponentAndPortCreation_5d4( const Packets_t& assemblys_392, const Packets_t& scenarios_394)
{
	Packets_t cComponentInstances_396;
	Packets_t pComponentDefs_397;
	Packets_t scenarios_398;
	Packets_t assemblys_399;
	ComponentAndPortCreation_391 componentAndPortCreation_391;
	componentAndPortCreation_391( assemblys_392, scenarios_394, cComponentInstances_396, pComponentDefs_397, scenarios_398, assemblys_399);
	if( ( !assemblys_399.empty())&& ( !scenarios_398.empty()))
		callPortConnection_5d7( assemblys_399, scenarios_398);
	if( ( !pComponentDefs_397.empty())&& ( !cComponentInstances_396.empty()))
		callTransferingComponentProperties_5da( pComponentDefs_397, cComponentInstances_396);
}

void RootRuleBlock_0::callPortConnection_5d7( const Packets_t& assemblys_be, const Packets_t& scenarios_c0)
{
	Packets_t pMasterPorts_c2;
	Packets_t cEIConnections_c3;
	Packets_t cESSConnections_c4;
	Packets_t pPConnectors_c5;
	Packets_t scenarios_c6;
	Packets_t assemblys_c7;
	PortConnection_bd portConnection_bd;
	portConnection_bd( assemblys_be, scenarios_c0, pMasterPorts_c2, cEIConnections_c3, cESSConnections_c4, pPConnectors_c5, scenarios_c6, assemblys_c7);
	if( ( !pPConnectors_c5.empty())&& ( !cESSConnections_c4.empty()))
		callTransferingPublishConnectionProperties_5dd( pPConnectors_c5, cESSConnections_c4);
	if( ( !assemblys_c7.empty()))
		callTransfering_Emit_and_Invoke_Properties_5e0( assemblys_c7);
}

void RootRuleBlock_0::callTransferingComponentProperties_5da( const Packets_t& pComponentDefs_8, const Packets_t& cComponentInstances_a)
{
	TransferingComponentProperties_7 transferingComponentProperties_7;
	transferingComponentProperties_7( pComponentDefs_8, cComponentInstances_a);
}

void RootRuleBlock_0::callTransferingPublishConnectionProperties_5dd( const Packets_t& pPConnectors_3c, const Packets_t& cESSConnections_3e)
{
	TransferingPublishConnectionProperties_3b transferingPublishConnectionProperties_3b;
	transferingPublishConnectionProperties_3b( pPConnectors_3c, cESSConnections_3e);
}

void RootRuleBlock_0::callTransfering_Emit_and_Invoke_Properties_5e0( const Packets_t& pAssemblys_490)
{
	Transfering_Emit_and_Invoke_Properties_48f transfering_Emit_and_Invoke_Properties_48f;
	transfering_Emit_and_Invoke_Properties_48f( pAssemblys_490);
}

void TransferingComponentProperties_7::operator()( const Packets_t& pComponentDefs_8, const Packets_t& cComponentInstances_a)
{
#ifdef PRINT_INFO
	std::cout << "TransferingComponentProperties_7" << std::endl;
#endif
	if( ( !cComponentInstances_a.empty())&& ( !pComponentDefs_8.empty()))
		callTransfering_Properties_38( cComponentInstances_a, pComponentDefs_8);
}

void TransferingComponentProperties_7::callTransfering_Properties_38( const Packets_t& componentInstances_d, const Packets_t& componentDefs_f)
{
	Transfering_Properties_c transfering_Properties_c;
	transfering_Properties_c( componentInstances_d, componentDefs_f);
}

void Transfering_Properties_c::operator()( const Packets_t& componentInstances_d, const Packets_t& componentDefs_f)
{
#ifdef PRINT_INFO
	std::cout << "Transfering_Properties_c" << std::endl;
#endif
	processInputPackets( componentInstances_d, componentDefs_f);
}

bool Transfering_Properties_c::isInputUnique( const Udm::Object& componentInstance_15, const Udm::Object& componentDef_1e)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentInstance_17= _componentInstance_11.begin(), itComponentDef_20= _componentDef_1a.begin(); itComponentInstance_17!= _componentInstance_11.end(), itComponentDef_20!= _componentDef_1a.end(); ++itComponentInstance_17, ++itComponentDef_20)
	{
		if( ( *itComponentInstance_17== componentInstance_15)&& ( *itComponentDef_20== componentDef_1e))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentInstance_11.push_back( componentInstance_15);
		_componentDef_1a.push_back( componentDef_1e);
	}
	return isUnique;
}

bool Transfering_Properties_c::isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& ComponentDef, const Udm::Object& ComponentInstance, const Udm::Object& DataType, const Udm::Object& PProperty, const Udm::Object& PredefinedType)
{
	bool Gz_guard= false;
	string name, type;  PProperty.GetStrValue("name", name); if (name == "CadenaEIProperties") return false;  PredefinedType.type().GetStrValue("name", type);  if (type!="LongInteger" && type!="String" && type!="Boolean") return false; return true;;
	return Gz_guard;
}

void Transfering_Properties_c::processInputPackets( const Packets_t& componentInstances_d, const Packets_t& componentDefs_f)
{
	for( Packets_t::const_iterator itComponentInstance_12= componentInstances_d.begin(), itComponentDef_1b= componentDefs_f.begin(); itComponentInstance_12!= componentInstances_d.end(), itComponentDef_1b!= componentDefs_f.end(); ++itComponentInstance_12, ++itComponentDef_1b)
	{
		bool isUnique= isInputUnique( *itComponentInstance_12, *itComponentDef_1b);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentInstance_12, *itComponentDef_1b);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Transfering_Properties_c::patternMatcher( const Udm::Object& componentInstance_13, const Udm::Object& componentDef_1c)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentInstance_13.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_18= cadena_scenario::ComponentInstance::Cast( componentInstance_13);
		if( false== Uml::IsDerivedFrom( componentDef_1c.type(), PICML::Component::meta))
			continue;
		PICML::Component componentDef_21= PICML::Component::Cast( componentDef_1c);
		set< PICML::AssemblyConfigProperty> assemblyConfigPropertys_23= componentDef_21.dstAssemblyConfigProperty();
		for( set< PICML::AssemblyConfigProperty>::const_iterator itAssemblyConfigPropertys_24= assemblyConfigPropertys_23.begin(); itAssemblyConfigPropertys_24!= assemblyConfigPropertys_23.end(); ++itAssemblyConfigPropertys_24)
		{
			PICML::AssemblyConfigProperty currAssemblyConfigProperty_25= *itAssemblyConfigPropertys_24;
			PICML::Property pProperty_26= currAssemblyConfigProperty_25.dstAssemblyConfigProperty_end();
			set< PICML::DataType> dataTypes_27= pProperty_26.DataType_kind_children();
			for( set< PICML::DataType>::const_iterator itDataType_28= dataTypes_27.begin(); itDataType_28!= dataTypes_27.end(); ++itDataType_28)
			{
				PICML::DataType currDataType_29= *itDataType_28;
				PICML::PredefinedType predefinedType_2a= currDataType_29.ref();
				if( !predefinedType_2a)
					continue;
				Match currMatch;
				currMatch.componentInstance_2b= componentInstance_18;
				currMatch.componentDef_2c= componentDef_21;
				currMatch.dataType_2d= currDataType_29;
				currMatch.pProperty_2e= pProperty_26;
				currMatch.predefinedType_2f= predefinedType_2a;
				currMatch.assemblyConfigProperty_30= currAssemblyConfigProperty_25;
				bool Gz_guard= isGuardTrue( currMatch.assemblyConfigProperty_30, currMatch.componentDef_2c, currMatch.componentInstance_2b, currMatch.dataType_2d, currMatch.pProperty_2e, currMatch.predefinedType_2f);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void Transfering_Properties_c::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::Property newCProperty_37= cadena_scenario::Property::Create( currMatch.componentInstance_2b);
		Udm::Object& AssemblyConfigProperty= currMatch.assemblyConfigProperty_30;
		Udm::Object& CProperty= newCProperty_37;
		Udm::Object& ComponentDef= currMatch.componentDef_2c;
		Udm::Object& ComponentInstance= currMatch.componentInstance_2b;
		Udm::Object& DataType= currMatch.dataType_2d;
		Udm::Object& PProperty= currMatch.pProperty_2e;
		Udm::Object& PredefinedType= currMatch.predefinedType_2f;
		{string str; PProperty.GetStrValue("name", str); CProperty.SetStrValue("name", str); PProperty.GetStrValue("DataValue", str); CProperty.SetStrValue("value", str);  PredefinedType.type().GetStrValue("name", str);  if (str=="LongInteger") str="INT"; else if (str=="Boolean") str="BOOLEAN"; else if (str=="String") str="STRING"; CProperty.SetStrValue("type", str);};
		outputAppender( );
	}
}

void Transfering_Properties_c::outputAppender()
{
}

void TransferingPublishConnectionProperties_3b::operator()( const Packets_t& pPConnectors_3c, const Packets_t& cESSConnections_3e)
{
#ifdef PRINT_INFO
	std::cout << "TransferingPublishConnectionProperties_3b" << std::endl;
#endif
	if( ( !pPConnectors_3c.empty())&& ( !cESSConnections_3e.empty()))
		callTransfering_PublishConnector_Properties_79( pPConnectors_3c, cESSConnections_3e);
}

void TransferingPublishConnectionProperties_3b::callTransfering_PublishConnector_Properties_79( const Packets_t& pPConnectors_41, const Packets_t& cESSConnections_43)
{
	Transfering_PublishConnector_Properties_40 transfering_PublishConnector_Properties_40;
	transfering_PublishConnector_Properties_40( pPConnectors_41, cESSConnections_43);
}

void Transfering_PublishConnector_Properties_40::operator()( const Packets_t& pPConnectors_41, const Packets_t& cESSConnections_43)
{
#ifdef PRINT_INFO
	std::cout << "Transfering_PublishConnector_Properties_40" << std::endl;
#endif
	if( ( !cESSConnections_43.empty())&& ( !pPConnectors_41.empty()))
		callTransfering_CadenaProperties_76( cESSConnections_43, pPConnectors_41);
}

void Transfering_PublishConnector_Properties_40::callTransfering_CadenaProperties_76( const Packets_t& eSSConnections_46, const Packets_t& publishConnectors_48)
{
	Transfering_CadenaProperties_45 transfering_CadenaProperties_45;
	transfering_CadenaProperties_45( eSSConnections_46, publishConnectors_48);
}

void Transfering_CadenaProperties_45::operator()( const Packets_t& eSSConnections_46, const Packets_t& publishConnectors_48)
{
#ifdef PRINT_INFO
	std::cout << "Transfering_CadenaProperties_45" << std::endl;
#endif
	processInputPackets( eSSConnections_46, publishConnectors_48);
}

bool Transfering_CadenaProperties_45::isInputUnique( const Udm::Object& eSSConnection_4e, const Udm::Object& publishConnector_57)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itESSConnection_50= _eSSConnection_4a.begin(), itPublishConnector_59= _publishConnector_53.begin(); itESSConnection_50!= _eSSConnection_4a.end(), itPublishConnector_59!= _publishConnector_53.end(); ++itESSConnection_50, ++itPublishConnector_59)
	{
		if( ( *itESSConnection_50== eSSConnection_4e)&& ( *itPublishConnector_59== publishConnector_57))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_eSSConnection_4a.push_back( eSSConnection_4e);
		_publishConnector_53.push_back( publishConnector_57);
	}
	return isUnique;
}

bool Transfering_CadenaProperties_45::isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& DataType, const Udm::Object& ESSConnection, const Udm::Object& PProperty, const Udm::Object& PredefinedType, const Udm::Object& PublishConnector, const Udm::Object& Requirement)
{
	bool Gz_guard= false;
	string name, type; Requirement.GetStrValue("name", name); if (name !="CadenaProperties") return false;  PredefinedType.type().GetStrValue("name", type);  if (type!="LongInteger" && type!="String" && type!="Boolean") return false; return true;;
	return Gz_guard;
}

void Transfering_CadenaProperties_45::processInputPackets( const Packets_t& eSSConnections_46, const Packets_t& publishConnectors_48)
{
	for( Packets_t::const_iterator itESSConnection_4b= eSSConnections_46.begin(), itPublishConnector_54= publishConnectors_48.begin(); itESSConnection_4b!= eSSConnections_46.end(), itPublishConnector_54!= publishConnectors_48.end(); ++itESSConnection_4b, ++itPublishConnector_54)
	{
		bool isUnique= isInputUnique( *itESSConnection_4b, *itPublishConnector_54);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itESSConnection_4b, *itPublishConnector_54);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Transfering_CadenaProperties_45::patternMatcher( const Udm::Object& eSSConnection_4c, const Udm::Object& publishConnector_55)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( eSSConnection_4c.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_51= cadena_scenario::ESSConnection::Cast( eSSConnection_4c);
		if( false== Uml::IsDerivedFrom( publishConnector_55.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_5a= PICML::PublishConnector::Cast( publishConnector_55);
		set< PICML::AssemblyDeployRequirement> assemblyDeployRequirements_5c= publishConnector_5a.dstAssemblyDeployRequirement();
		for( set< PICML::AssemblyDeployRequirement>::const_iterator itAssemblyDeployRequirements_5d= assemblyDeployRequirements_5c.begin(); itAssemblyDeployRequirements_5d!= assemblyDeployRequirements_5c.end(); ++itAssemblyDeployRequirements_5d)
		{
			PICML::AssemblyDeployRequirement currAssemblyDeployRequirement_5e= *itAssemblyDeployRequirements_5d;
			PICML::Requirement requirement_5f= currAssemblyDeployRequirement_5e.dstAssemblyDeployRequirement_end();
			set< PICML::Property> pPropertys_60= requirement_5f.Property_kind_children();
			for( set< PICML::Property>::const_iterator itPProperty_61= pPropertys_60.begin(); itPProperty_61!= pPropertys_60.end(); ++itPProperty_61)
			{
				PICML::Property currPProperty_62= *itPProperty_61;
				set< PICML::DataType> dataTypes_63= currPProperty_62.DataType_kind_children();
				for( set< PICML::DataType>::const_iterator itDataType_64= dataTypes_63.begin(); itDataType_64!= dataTypes_63.end(); ++itDataType_64)
				{
					PICML::DataType currDataType_65= *itDataType_64;
					PICML::PredefinedType predefinedType_66= currDataType_65.ref();
					if( !predefinedType_66)
						continue;
					Match currMatch;
					currMatch.predefinedType_67= predefinedType_66;
					currMatch.requirement_68= requirement_5f;
					currMatch.dataType_69= currDataType_65;
					currMatch.pProperty_6a= currPProperty_62;
					currMatch.assemblyDeployRequirement_6b= currAssemblyDeployRequirement_5e;
					currMatch.eSSConnection_6c= eSSConnection_51;
					currMatch.publishConnector_6d= publishConnector_5a;
					bool Gz_guard= isGuardTrue( currMatch.assemblyDeployRequirement_6b, currMatch.dataType_69, currMatch.eSSConnection_6c, currMatch.pProperty_6a, currMatch.predefinedType_67, currMatch.publishConnector_6d, currMatch.requirement_68);
					if( true== Gz_guard)
						_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void Transfering_CadenaProperties_45::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::Property newCProperty_75= cadena_scenario::Property::Create( currMatch.eSSConnection_6c);
		Udm::Object& AssemblyDeployRequirement= currMatch.assemblyDeployRequirement_6b;
		Udm::Object& CProperty= newCProperty_75;
		Udm::Object& DataType= currMatch.dataType_69;
		Udm::Object& ESSConnection= currMatch.eSSConnection_6c;
		Udm::Object& PProperty= currMatch.pProperty_6a;
		Udm::Object& PredefinedType= currMatch.predefinedType_67;
		Udm::Object& PublishConnector= currMatch.publishConnector_6d;
		Udm::Object& Requirement= currMatch.requirement_68;
		{string str; PProperty.GetStrValue("name", str); CProperty.SetStrValue("name", str); PProperty.GetStrValue("DataValue", str); CProperty.SetStrValue("value", str);  PredefinedType.type().GetStrValue("name", str);  if (str=="LongInteger") str="INT"; else if (str=="Boolean") str="BOOLEAN"; else if (str=="String") str="STRING"; CProperty.SetStrValue("type", str);};
		outputAppender( );
	}
}

void Transfering_CadenaProperties_45::outputAppender()
{
}

void Assembly_and_Scenario_Finder_7c::operator()( const Packets_t& rootContainers_7d, const Packets_t& scenarioss_7f, const Packets_t& rootFolders_82, Packets_t& scenarios_81, Packets_t& componentAssemblys_84)
{
#ifdef PRINT_INFO
	std::cout << "Assembly_and_Scenario_Finder_7c" << std::endl;
#endif
	_scenario_85= &scenarios_81;
	_componentAssembly_86= &componentAssemblys_84;
	processInputPackets( rootContainers_7d, scenarioss_7f, rootFolders_82);
}

bool Assembly_and_Scenario_Finder_7c::isInputUnique( const Udm::Object& rootContainer_8b, const Udm::Object& scenarios_94, const Udm::Object& rootFolder_9d)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRootContainer_8d= _rootContainer_87.begin(), itScenarios_96= _scenarios_90.begin(), itRootFolder_9f= _rootFolder_99.begin(); itRootContainer_8d!= _rootContainer_87.end(), itScenarios_96!= _scenarios_90.end(), itRootFolder_9f!= _rootFolder_99.end(); ++itRootContainer_8d, ++itScenarios_96, ++itRootFolder_9f)
	{
		if( ( *itRootContainer_8d== rootContainer_8b)&& ( *itScenarios_96== scenarios_94)&& ( *itRootFolder_9f== rootFolder_9d))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_rootContainer_87.push_back( rootContainer_8b);
		_scenarios_90.push_back( scenarios_94);
		_rootFolder_99.push_back( rootFolder_9d);
	}
	return isUnique;
}

bool Assembly_and_Scenario_Finder_7c::isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& RootContainer, const Udm::Object& RootFolder, const Udm::Object& Scenarios)
{
	bool Gz_guard= false;
	string ciname; ComponentImplementations.GetStrValue("name",ciname); return (0 != ciname.find("noexport"));;
	return Gz_guard;
}

void Assembly_and_Scenario_Finder_7c::processInputPackets( const Packets_t& rootContainers_7d, const Packets_t& scenarioss_7f, const Packets_t& rootFolders_82)
{
	for( Packets_t::const_iterator itRootContainer_88= rootContainers_7d.begin(), itScenarios_91= scenarioss_7f.begin(), itRootFolder_9a= rootFolders_82.begin(); itRootContainer_88!= rootContainers_7d.end(), itScenarios_91!= scenarioss_7f.end(), itRootFolder_9a!= rootFolders_82.end(); ++itRootContainer_88, ++itScenarios_91, ++itRootFolder_9a)
	{
		bool isUnique= isInputUnique( *itRootContainer_88, *itScenarios_91, *itRootFolder_9a);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRootContainer_88, *itScenarios_91, *itRootFolder_9a);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Assembly_and_Scenario_Finder_7c::patternMatcher( const Udm::Object& rootContainer_89, const Udm::Object& scenarios_92, const Udm::Object& rootFolder_9b)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( rootContainer_89.type(), PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta))
			continue;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_8e= PICMLCadena_Xchange_embedded_EIProperties::RootContainer::Cast( rootContainer_89);
		if( false== Uml::IsDerivedFrom( scenarios_92.type(), cadena_scenario::Scenarios::meta))
			continue;
		cadena_scenario::Scenarios scenarios_97= cadena_scenario::Scenarios::Cast( scenarios_92);
		if( false== Uml::IsDerivedFrom( rootFolder_9b.type(), PICML::RootFolder::meta))
			continue;
		PICML::RootFolder rootFolder_a0= PICML::RootFolder::Cast( rootFolder_9b);
		set< PICML::ComponentImplementations> componentImplementationss_a2= rootFolder_a0.ComponentImplementations_kind_children();
		for( set< PICML::ComponentImplementations>::const_iterator itComponentImplementations_a3= componentImplementationss_a2.begin(); itComponentImplementations_a3!= componentImplementationss_a2.end(); ++itComponentImplementations_a3)
		{
			PICML::ComponentImplementations currComponentImplementations_a4= *itComponentImplementations_a3;
			set< PICML::ComponentImplementationContainer> componentImplementationContainers_a5= currComponentImplementations_a4.ComponentImplementationContainer_kind_children();
			for( set< PICML::ComponentImplementationContainer>::const_iterator itComponentImplementationContainer_a6= componentImplementationContainers_a5.begin(); itComponentImplementationContainer_a6!= componentImplementationContainers_a5.end(); ++itComponentImplementationContainer_a6)
			{
				PICML::ComponentImplementationContainer currComponentImplementationContainer_a7= *itComponentImplementationContainer_a6;
				set< PICML::ComponentAssembly> componentAssemblys_a8= currComponentImplementationContainer_a7.ComponentAssembly_kind_children();
				for( set< PICML::ComponentAssembly>::const_iterator itComponentAssembly_a9= componentAssemblys_a8.begin(); itComponentAssembly_a9!= componentAssemblys_a8.end(); ++itComponentAssembly_a9)
				{
					PICML::ComponentAssembly currComponentAssembly_aa= *itComponentAssembly_a9;
					Match currMatch;
					currMatch.rootContainer_ab= rootContainer_8e;
					currMatch.scenarios_ac= scenarios_97;
					currMatch.rootFolder_ad= rootFolder_a0;
					currMatch.componentImplementations_ae= currComponentImplementations_a4;
					currMatch.componentImplementationContainer_af= currComponentImplementationContainer_a7;
					currMatch.componentAssembly_b0= currComponentAssembly_aa;
					bool Gz_guard= isGuardTrue( currMatch.componentAssembly_b0, currMatch.componentImplementationContainer_af, currMatch.componentImplementations_ae, currMatch.rootContainer_ab, currMatch.rootFolder_ad, currMatch.scenarios_ac);
					if( true== Gz_guard)
						_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void Assembly_and_Scenario_Finder_7c::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::Scenario newScenario_b7= cadena_scenario::Scenario::Create( currMatch.scenarios_ac);
		cadena_scenario::Property newProperty_b8= cadena_scenario::Property::Create( newScenario_b7);
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_b0;
		Udm::Object& ComponentImplementationContainer= currMatch.componentImplementationContainer_af;
		Udm::Object& ComponentImplementations= currMatch.componentImplementations_ae;
		Udm::Object& Property= newProperty_b8;
		Udm::Object& RootContainer= currMatch.rootContainer_ab;
		Udm::Object& RootFolder= currMatch.rootFolder_ad;
		Udm::Object& Scenario= newScenario_b7;
		Udm::Object& Scenarios= currMatch.scenarios_ac;
		{string ciname, cicname, caname; ComponentImplementations.GetStrValue("name",ciname); ComponentImplementationContainer.GetStrValue("name",cicname); ComponentAssembly.GetStrValue("name",caname);  /*TOTO: support fwd slashes (/) in names by escaping them*/  Property.SetStrValue("name", "PICML_pathname"); Property.SetStrValue("value", '/' + ciname + '/' + cicname + '/' + caname); Property.SetStrValue("type", "STRING");};
		currMatch.componentAssembly_b0.rootContainer()= currMatch.rootContainer_ab;
		outputAppender( newScenario_b7, currMatch.componentAssembly_b0);
	}
}

void Assembly_and_Scenario_Finder_7c::outputAppender( const cadena_scenario::Scenario& scenario_b9, const PICML::ComponentAssembly& componentAssembly_bb)
{
	_scenario_85->push_back( scenario_b9);
	_componentAssembly_86->push_back( componentAssembly_bb);
}

void PortConnection_bd::operator()( const Packets_t& assemblys_be, const Packets_t& scenarios_c0, Packets_t& pMasterPorts_c2, Packets_t& cEIConnections_c3, Packets_t& cESSConnections_c4, Packets_t& pPConnectors_c5, Packets_t& scenarios_c6, Packets_t& assemblys_c7)
{
#ifdef PRINT_INFO
	std::cout << "PortConnection_bd" << std::endl;
#endif
	_pMasterPort_c8= &pMasterPorts_c2;
	_cEIConnection_c9= &cEIConnections_c3;
	_cESSConnection_ca= &cESSConnections_c4;
	_pPConnector_cb= &pPConnectors_c5;
	_scenario_cc= &scenarios_c6;
	_assembly_cd= &assemblys_c7;
	_assembly_cd->insert( _assembly_cd->end(), assemblys_be.begin(), assemblys_be.end());
	_scenario_cc->insert( _scenario_cc->end(), scenarios_c0.begin(), scenarios_c0.end());
	if( ( !scenarios_c0.empty())&& ( !assemblys_be.empty()))
		callInputSplitter_379( scenarios_c0, assemblys_be);
}

void PortConnection_bd::callInputSplitter_379( const Packets_t& scenarios_28e, const Packets_t& componentAssemblys_291)
{
	Packets_t scenarios_290;
	Packets_t componentAssemblys_293;
	InputSplitter_28d inputSplitter_28d;
	inputSplitter_28d( scenarios_28e, componentAssemblys_291, scenarios_290, componentAssemblys_293);
	if( ( !scenarios_290.empty())&& ( !componentAssemblys_293.empty()))
		callCreating_ESSConnections_37c( scenarios_290, componentAssemblys_293);
	if( ( !scenarios_290.empty())&& ( !componentAssemblys_293.empty()))
		callPICMLPort_Finder_37f( scenarios_290, componentAssemblys_293);
}

void PortConnection_bd::callCreating_ESSConnections_37c( const Packets_t& scenarios_2ff, const Packets_t& componentAssemblys_303)
{
	Packets_t eSSConnections_301;
	Packets_t publishConnectors_302;
	Creating_ESSConnections_2fe creating_ESSConnections_2fe;
	creating_ESSConnections_2fe( scenarios_2ff, componentAssemblys_303, eSSConnections_301, publishConnectors_302);
	_cESSConnection_ca->insert( _cESSConnection_ca->end(), eSSConnections_301.begin(), eSSConnections_301.end());
	_pPConnector_cb->insert( _pPConnector_cb->end(), publishConnectors_302.begin(), publishConnectors_302.end());
	if( ( !publishConnectors_302.empty())&& ( !eSSConnections_301.empty()))
		callSetting_ConnectorIDs_382( publishConnectors_302, eSSConnections_301);
	if( ( !publishConnectors_302.empty())&& ( !eSSConnections_301.empty()))
		callConnectorsToSinks_385( publishConnectors_302, eSSConnections_301);
	if( ( !eSSConnections_301.empty())&& ( !publishConnectors_302.empty()))
		callSourcesToConnectors_388( eSSConnections_301, publishConnectors_302);
}

void PortConnection_bd::callPICMLPort_Finder_37f( const Packets_t& scenarios_325, const Packets_t& componentAssemblys_329)
{
	Packets_t scenarios_327;
	Packets_t ports_328;
	PICMLPort_Finder_324 pICMLPort_Finder_324;
	pICMLPort_Finder_324( scenarios_325, componentAssemblys_329, scenarios_327, ports_328);
	if( ( !ports_328.empty())&& ( !scenarios_327.empty()))
		callMethodInvocations_38b( ports_328, scenarios_327);
	if( ( !scenarios_327.empty())&& ( !ports_328.empty()))
		callEmits_38e( scenarios_327, ports_328);
}

void PortConnection_bd::callSetting_ConnectorIDs_382( const Packets_t& ins_f1, const Packets_t& ins_f3)
{
	Setting_ConnectorIDs_f0 setting_ConnectorIDs_f0;
	setting_ConnectorIDs_f0( ins_f1, ins_f3);
}

void PortConnection_bd::callConnectorsToSinks_385( const Packets_t& publishConnectors_cf, const Packets_t& eSSConnections_d1)
{
	ConnectorsToSinks_ce connectorsToSinks_ce;
	connectorsToSinks_ce( publishConnectors_cf, eSSConnections_d1);
}

void PortConnection_bd::callSourcesToConnectors_388( const Packets_t& eSSConnections_2dd, const Packets_t& publishConnectors_2df)
{
	SourcesToConnectors_2dc sourcesToConnectors_2dc;
	sourcesToConnectors_2dc( eSSConnections_2dd, publishConnectors_2df);
}

void PortConnection_bd::callMethodInvocations_38b( const Packets_t& requiredRequestPorts_2b0, const Packets_t& scenarios_2b3)
{
	Packets_t fRConnections_2af;
	Packets_t requiredRequestPorts_2b2;
	MethodInvocations_2ae methodInvocations_2ae;
	methodInvocations_2ae( requiredRequestPorts_2b0, scenarios_2b3, fRConnections_2af, requiredRequestPorts_2b2);
	_cEIConnection_c9->insert( _cEIConnection_c9->end(), fRConnections_2af.begin(), fRConnections_2af.end());
	_pMasterPort_c8->insert( _pMasterPort_c8->end(), requiredRequestPorts_2b2.begin(), requiredRequestPorts_2b2.end());
}

void PortConnection_bd::callEmits_38e( const Packets_t& scenarios_34f, const Packets_t& outEventPorts_351)
{
	Packets_t eSSConnections_34e;
	Packets_t outEventPorts_353;
	Emits_34d emits_34d;
	emits_34d( scenarios_34f, outEventPorts_351, eSSConnections_34e, outEventPorts_353);
	_cEIConnection_c9->insert( _cEIConnection_c9->end(), eSSConnections_34e.begin(), eSSConnections_34e.end());
	_pMasterPort_c8->insert( _pMasterPort_c8->end(), outEventPorts_353.begin(), outEventPorts_353.end());
}

void ConnectorsToSinks_ce::operator()( const Packets_t& publishConnectors_cf, const Packets_t& eSSConnections_d1)
{
#ifdef PRINT_INFO
	std::cout << "ConnectorsToSinks_ce" << std::endl;
#endif
	processInputPackets( publishConnectors_cf, eSSConnections_d1);
}

bool ConnectorsToSinks_ce::isInputUnique( const Udm::Object& publishConnector_d7, const Udm::Object& eSSConnection_e0)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPublishConnector_d9= _publishConnector_d3.begin(), itESSConnection_e2= _eSSConnection_dc.begin(); itPublishConnector_d9!= _publishConnector_d3.end(), itESSConnection_e2!= _eSSConnection_dc.end(); ++itPublishConnector_d9, ++itESSConnection_e2)
	{
		if( ( *itPublishConnector_d9== publishConnector_d7)&& ( *itESSConnection_e2== eSSConnection_e0))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_publishConnector_d3.push_back( publishConnector_d7);
		_eSSConnection_dc.push_back( eSSConnection_e0);
	}
	return isUnique;
}

void ConnectorsToSinks_ce::processInputPackets( const Packets_t& publishConnectors_cf, const Packets_t& eSSConnections_d1)
{
	for( Packets_t::const_iterator itPublishConnector_d4= publishConnectors_cf.begin(), itESSConnection_dd= eSSConnections_d1.begin(); itPublishConnector_d4!= publishConnectors_cf.end(), itESSConnection_dd!= eSSConnections_d1.end(); ++itPublishConnector_d4, ++itESSConnection_dd)
	{
		bool isUnique= isInputUnique( *itPublishConnector_d4, *itESSConnection_dd);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPublishConnector_d4, *itESSConnection_dd);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool ConnectorsToSinks_ce::patternMatcher( const Udm::Object& publishConnector_d5, const Udm::Object& eSSConnection_de)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( publishConnector_d5.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_da= PICML::PublishConnector::Cast( publishConnector_d5);
		if( false== Uml::IsDerivedFrom( eSSConnection_de.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_e3= cadena_scenario::ESSConnection::Cast( eSSConnection_de);
		set< PICML::deliverTo> deliverTos_e5= publishConnector_da.dstdeliverTo();
		for( set< PICML::deliverTo>::const_iterator itdeliverTos_e6= deliverTos_e5.begin(); itdeliverTos_e6!= deliverTos_e5.end(); ++itdeliverTos_e6)
		{
			PICML::deliverTo currdeliverTo_e7= *itdeliverTos_e6;
			PICML::InEventPort inEventPort_e8= currdeliverTo_e7.dstdeliverTo_end();
			cadena_scenario::ComponentPort eventSink_e9= inEventPort_e8.cadenaPort();
			if( false== Uml::IsDerivedFrom( eventSink_e9.type(), cadena_scenario::EventSink::meta))
				continue;
			cadena_scenario::EventSink eventSink_ea= cadena_scenario::EventSink::Cast( eventSink_e9);
			if( !eventSink_ea)
				continue;
			Match currMatch;
			currMatch.inEventPort_eb= inEventPort_e8;
			currMatch.eventSink_ec= eventSink_ea;
			currMatch.deliverTo_ed= currdeliverTo_e7;
			currMatch.publishConnector_ee= publishConnector_da;
			currMatch.eSSConnection_ef= eSSConnection_e3;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void ConnectorsToSinks_ce::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.eSSConnection_ef.sinks()+= currMatch.eventSink_ec;
		outputAppender( );
	}
}

void ConnectorsToSinks_ce::outputAppender()
{
}

void Setting_ConnectorIDs_f0::operator()( const Packets_t& ins_f1, const Packets_t& ins_f3)
{
#ifdef PRINT_INFO
	std::cout << "Setting_ConnectorIDs_f0" << std::endl;
#endif
	if( ( !ins_f3.empty())&& ( !ins_f1.empty()))
		callBlock_Remove_Multiple_ConnectorID_Requirements_27b( ins_f3, ins_f1);
}

void Setting_ConnectorIDs_f0::callBlock_Remove_Multiple_ConnectorID_Requirements_27b( const Packets_t& ins_24b, const Packets_t& ins_24d)
{
	Packets_t outs_24f;
	Packets_t outs_250;
	Block_Remove_Multiple_ConnectorID_Requirements_24a block_Remove_Multiple_ConnectorID_Requirements_24a;
	block_Remove_Multiple_ConnectorID_Requirements_24a( ins_24b, ins_24d, outs_24f, outs_250);
	if( ( !outs_250.empty())&& ( !outs_24f.empty()))
		callCreateOne_ConnectorIDRequirement_IfNeeded_And_Match_27e( outs_250, outs_24f);
}

void Setting_ConnectorIDs_f0::callCreateOne_ConnectorIDRequirement_IfNeeded_And_Match_27e( const Packets_t& ins_1bf, const Packets_t& ins_1c1)
{
	Packets_t outs_1c3;
	Packets_t outs_1c4;
	CreateOne_ConnectorIDRequirement_IfNeeded_And_Match_1be createOne_ConnectorIDRequirement_IfNeeded_And_Match_1be;
	createOne_ConnectorIDRequirement_IfNeeded_And_Match_1be( ins_1bf, ins_1c1, outs_1c3, outs_1c4);
	if( ( !outs_1c4.empty())&& ( !outs_1c3.empty()))
		callBlock_FetchAll_ConnectorID_Property_Value_IfNotEmpty_281( outs_1c4, outs_1c3);
}

void Setting_ConnectorIDs_f0::callBlock_FetchAll_ConnectorID_Property_Value_IfNotEmpty_281( const Packets_t& ins_164, const Packets_t& ins_166)
{
	Packets_t outs_168;
	Packets_t outs_169;
	Block_FetchAll_ConnectorID_Property_Value_IfNotEmpty_163 block_FetchAll_ConnectorID_Property_Value_IfNotEmpty_163;
	block_FetchAll_ConnectorID_Property_Value_IfNotEmpty_163( ins_164, ins_166, outs_168, outs_169);
	if( ( !outs_169.empty())&& ( !outs_168.empty()))
		callBlock_Fetch_Default_IfAllEmpty_284( outs_169, outs_168);
}

void Setting_ConnectorIDs_f0::callBlock_Fetch_Default_IfAllEmpty_284( const Packets_t& ins_135, const Packets_t& ins_137)
{
	Packets_t outs_139;
	Packets_t outs_13a;
	Block_Fetch_Default_IfAllEmpty_134 block_Fetch_Default_IfAllEmpty_134;
	block_Fetch_Default_IfAllEmpty_134( ins_135, ins_137, outs_139, outs_13a);
	if( ( !outs_13a.empty())&& ( !outs_139.empty()))
		callBlock_DeleteAll_ConnectorID_Properties_287( outs_13a, outs_139);
}

void Setting_ConnectorIDs_f0::callBlock_DeleteAll_ConnectorID_Properties_287( const Packets_t& ins_f6, const Packets_t& ins_f8)
{
	Packets_t outs_fa;
	Packets_t outs_fb;
	Block_DeleteAll_ConnectorID_Properties_f5 block_DeleteAll_ConnectorID_Properties_f5;
	block_DeleteAll_ConnectorID_Properties_f5( ins_f6, ins_f8, outs_fa, outs_fb);
	if( ( !outs_fb.empty())&& ( !outs_fa.empty()))
		callRecreateOne_ConnectorIDProperty_and_DumpValueBack_28a( outs_fb, outs_fa);
}

void Setting_ConnectorIDs_f0::callRecreateOne_ConnectorIDProperty_and_DumpValueBack_28a( const Packets_t& requirements_190, const Packets_t& eSSConnections_192)
{
	RecreateOne_ConnectorIDProperty_and_DumpValueBack_18f recreateOne_ConnectorIDProperty_and_DumpValueBack_18f;
	recreateOne_ConnectorIDProperty_and_DumpValueBack_18f( requirements_190, eSSConnections_192);
}

void Block_DeleteAll_ConnectorID_Properties_f5::operator()( const Packets_t& ins_f6, const Packets_t& ins_f8, Packets_t& outs_fa, Packets_t& outs_fb)
{
#ifdef PRINT_INFO
	std::cout << "Block_DeleteAll_ConnectorID_Properties_f5" << std::endl;
#endif
	_out_fc= &outs_fa;
	_out_fd= &outs_fb;
	if( ( !ins_f6.empty())&& ( !ins_f8.empty()))
		callRule_DeleteAll_ConnectorID_Properties_131( ins_f6, ins_f8);
	_out_fd->insert( _out_fd->end(), ins_f6.begin(), ins_f6.end());
	_out_fc->insert( _out_fc->end(), ins_f8.begin(), ins_f8.end());
}

void Block_DeleteAll_ConnectorID_Properties_f5::callRule_DeleteAll_ConnectorID_Properties_131( const Packets_t& requirements_ff, const Packets_t& eSSConnections_101)
{
	Rule_DeleteAll_ConnectorID_Properties_fe rule_DeleteAll_ConnectorID_Properties_fe;
	rule_DeleteAll_ConnectorID_Properties_fe( requirements_ff, eSSConnections_101);
}

void Rule_DeleteAll_ConnectorID_Properties_fe::operator()( const Packets_t& requirements_ff, const Packets_t& eSSConnections_101)
{
#ifdef PRINT_INFO
	std::cout << "Rule_DeleteAll_ConnectorID_Properties_fe" << std::endl;
#endif
	processInputPackets( requirements_ff, eSSConnections_101);
}

bool Rule_DeleteAll_ConnectorID_Properties_fe::isInputUnique( const Udm::Object& requirement_107, const Udm::Object& eSSConnection_110)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRequirement_109= _requirement_103.begin(), itESSConnection_112= _eSSConnection_10c.begin(); itRequirement_109!= _requirement_103.end(), itESSConnection_112!= _eSSConnection_10c.end(); ++itRequirement_109, ++itESSConnection_112)
	{
		if( ( *itRequirement_109== requirement_107)&& ( *itESSConnection_112== eSSConnection_110))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_requirement_103.push_back( requirement_107);
		_eSSConnection_10c.push_back( eSSConnection_110);
	}
	return isUnique;
}

void Rule_DeleteAll_ConnectorID_Properties_fe::processInputPackets( const Packets_t& requirements_ff, const Packets_t& eSSConnections_101)
{
	for( Packets_t::const_iterator itRequirement_104= requirements_ff.begin(), itESSConnection_10d= eSSConnections_101.begin(); itRequirement_104!= requirements_ff.end(), itESSConnection_10d!= eSSConnections_101.end(); ++itRequirement_104, ++itESSConnection_10d)
	{
		bool isUnique= isInputUnique( *itRequirement_104, *itESSConnection_10d);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRequirement_104, *itESSConnection_10d);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Rule_DeleteAll_ConnectorID_Properties_fe::patternMatcher( const Udm::Object& requirement_105, const Udm::Object& eSSConnection_10e)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( requirement_105.type(), PICML::Requirement::meta))
			continue;
		PICML::Requirement requirement_10a= PICML::Requirement::Cast( requirement_105);
		if( false== Uml::IsDerivedFrom( eSSConnection_10e.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_113= cadena_scenario::ESSConnection::Cast( eSSConnection_10e);
		set< PICML::Property> propertys_115= requirement_10a.Property_kind_children();
		for( set< PICML::Property>::const_iterator itProperty_116= propertys_115.begin(); itProperty_116!= propertys_115.end(); ++itProperty_116)
		{
			PICML::Property currProperty_117= *itProperty_116;
			Match currMatch;
			currMatch.property_118= currProperty_117;
			currMatch.requirement_119= requirement_10a;
			currMatch.eSSConnection_11a= eSSConnection_113;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Rule_DeleteAll_ConnectorID_Properties_fe::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		set< PICML::AssemblyConfigProperty> delAssemblyConfigPropertys_11b= currMatch.property_118.srcAssemblyConfigProperty();
		for( set< PICML::AssemblyConfigProperty>::const_iterator itdelAssemblyConfigPropertys_11b= delAssemblyConfigPropertys_11b.begin(); itdelAssemblyConfigPropertys_11b!= delAssemblyConfigPropertys_11b.end(); ++itdelAssemblyConfigPropertys_11b)
		{
			PICML::AssemblyConfigProperty currAssemblyConfigProperty_11c= *itdelAssemblyConfigPropertys_11b;
			if( currAssemblyConfigProperty_11c)
				currAssemblyConfigProperty_11c.DeleteObject();
		}
		set< PICML::InfoProperty> delInfoPropertys_11d= currMatch.property_118.srcInfoProperty();
		for( set< PICML::InfoProperty>::const_iterator itdelInfoPropertys_11d= delInfoPropertys_11d.begin(); itdelInfoPropertys_11d!= delInfoPropertys_11d.end(); ++itdelInfoPropertys_11d)
		{
			PICML::InfoProperty currInfoProperty_11e= *itdelInfoPropertys_11d;
			if( currInfoProperty_11e)
				currInfoProperty_11e.DeleteObject();
		}
		set< PICML::ConfigProperty> delConfigPropertys_11f= currMatch.property_118.srcConfigProperty();
		for( set< PICML::ConfigProperty>::const_iterator itdelConfigPropertys_11f= delConfigPropertys_11f.begin(); itdelConfigPropertys_11f!= delConfigPropertys_11f.end(); ++itdelConfigPropertys_11f)
		{
			PICML::ConfigProperty currConfigProperty_120= *itdelConfigPropertys_11f;
			if( currConfigProperty_120)
				currConfigProperty_120.DeleteObject();
		}
		set< PICML::PackageConfigProperty> delPackageConfigPropertys_121= currMatch.property_118.srcPackageConfigProperty();
		for( set< PICML::PackageConfigProperty>::const_iterator itdelPackageConfigPropertys_121= delPackageConfigPropertys_121.begin(); itdelPackageConfigPropertys_121!= delPackageConfigPropertys_121.end(); ++itdelPackageConfigPropertys_121)
		{
			PICML::PackageConfigProperty currPackageConfigProperty_122= *itdelPackageConfigPropertys_121;
			if( currPackageConfigProperty_122)
				currPackageConfigProperty_122.DeleteObject();
		}
		set< PICML::PackageInfoProperty> delPackageInfoPropertys_123= currMatch.property_118.srcPackageInfoProperty();
		for( set< PICML::PackageInfoProperty>::const_iterator itdelPackageInfoPropertys_123= delPackageInfoPropertys_123.begin(); itdelPackageInfoPropertys_123!= delPackageInfoPropertys_123.end(); ++itdelPackageInfoPropertys_123)
		{
			PICML::PackageInfoProperty currPackageInfoProperty_124= *itdelPackageInfoPropertys_123;
			if( currPackageInfoProperty_124)
				currPackageInfoProperty_124.DeleteObject();
		}
		set< PICML::MonolithExecParameter> delMonolithExecParameters_125= currMatch.property_118.srcMonolithExecParameter();
		for( set< PICML::MonolithExecParameter>::const_iterator itdelMonolithExecParameters_125= delMonolithExecParameters_125.begin(); itdelMonolithExecParameters_125!= delMonolithExecParameters_125.end(); ++itdelMonolithExecParameters_125)
		{
			PICML::MonolithExecParameter currMonolithExecParameter_126= *itdelMonolithExecParameters_125;
			if( currMonolithExecParameter_126)
				currMonolithExecParameter_126.DeleteObject();
		}
		set< PICML::ComponentConfigProperty> delComponentConfigPropertys_127= currMatch.property_118.srcComponentConfigProperty();
		for( set< PICML::ComponentConfigProperty>::const_iterator itdelComponentConfigPropertys_127= delComponentConfigPropertys_127.begin(); itdelComponentConfigPropertys_127!= delComponentConfigPropertys_127.end(); ++itdelComponentConfigPropertys_127)
		{
			PICML::ComponentConfigProperty currComponentConfigProperty_128= *itdelComponentConfigPropertys_127;
			if( currComponentConfigProperty_128)
				currComponentConfigProperty_128.DeleteObject();
		}
		set< PICML::ComponentInfoProperty> delComponentInfoPropertys_129= currMatch.property_118.srcComponentInfoProperty();
		for( set< PICML::ComponentInfoProperty>::const_iterator itdelComponentInfoPropertys_129= delComponentInfoPropertys_129.begin(); itdelComponentInfoPropertys_129!= delComponentInfoPropertys_129.end(); ++itdelComponentInfoPropertys_129)
		{
			PICML::ComponentInfoProperty currComponentInfoProperty_12a= *itdelComponentInfoPropertys_129;
			if( currComponentInfoProperty_12a)
				currComponentInfoProperty_12a.DeleteObject();
		}
		set< PICML::PackageConfConfigProperty> delPackageConfConfigPropertys_12b= currMatch.property_118.srcPackageConfConfigProperty();
		for( set< PICML::PackageConfConfigProperty>::const_iterator itdelPackageConfConfigPropertys_12b= delPackageConfConfigPropertys_12b.begin(); itdelPackageConfConfigPropertys_12b!= delPackageConfConfigPropertys_12b.end(); ++itdelPackageConfConfigPropertys_12b)
		{
			PICML::PackageConfConfigProperty currPackageConfConfigProperty_12c= *itdelPackageConfConfigPropertys_12b;
			if( currPackageConfConfigProperty_12c)
				currPackageConfConfigProperty_12c.DeleteObject();
		}
		set< PICML::ArtifactInfoProperty> delArtifactInfoPropertys_12d= currMatch.property_118.srcArtifactInfoProperty();
		for( set< PICML::ArtifactInfoProperty>::const_iterator itdelArtifactInfoPropertys_12d= delArtifactInfoPropertys_12d.begin(); itdelArtifactInfoPropertys_12d!= delArtifactInfoPropertys_12d.end(); ++itdelArtifactInfoPropertys_12d)
		{
			PICML::ArtifactInfoProperty currArtifactInfoProperty_12e= *itdelArtifactInfoPropertys_12d;
			if( currArtifactInfoProperty_12e)
				currArtifactInfoProperty_12e.DeleteObject();
		}
		set< PICML::ArtifactExecParameter> delArtifactExecParameters_12f= currMatch.property_118.srcArtifactExecParameter();
		for( set< PICML::ArtifactExecParameter>::const_iterator itdelArtifactExecParameters_12f= delArtifactExecParameters_12f.begin(); itdelArtifactExecParameters_12f!= delArtifactExecParameters_12f.end(); ++itdelArtifactExecParameters_12f)
		{
			PICML::ArtifactExecParameter currArtifactExecParameter_130= *itdelArtifactExecParameters_12f;
			if( currArtifactExecParameter_130)
				currArtifactExecParameter_130.DeleteObject();
		}
		if( currMatch.property_118)
			currMatch.property_118.DeleteObject();
		outputAppender( );
	}
}

void Rule_DeleteAll_ConnectorID_Properties_fe::outputAppender()
{
}

void Block_Fetch_Default_IfAllEmpty_134::operator()( const Packets_t& ins_135, const Packets_t& ins_137, Packets_t& outs_139, Packets_t& outs_13a)
{
#ifdef PRINT_INFO
	std::cout << "Block_Fetch_Default_IfAllEmpty_134" << std::endl;
#endif
	_out_13b= &outs_139;
	_out_13c= &outs_13a;
	if( ( !ins_135.empty())&& ( !ins_137.empty()))
		callFetch_Default_IfAllEmpty_160( ins_135, ins_137);
	_out_13c->insert( _out_13c->end(), ins_135.begin(), ins_135.end());
	_out_13b->insert( _out_13b->end(), ins_137.begin(), ins_137.end());
}

void Block_Fetch_Default_IfAllEmpty_134::callFetch_Default_IfAllEmpty_160( const Packets_t& requirements_13e, const Packets_t& eSSConnections_140)
{
	Fetch_Default_IfAllEmpty_13d fetch_Default_IfAllEmpty_13d;
	fetch_Default_IfAllEmpty_13d( requirements_13e, eSSConnections_140);
}

void Fetch_Default_IfAllEmpty_13d::operator()( const Packets_t& requirements_13e, const Packets_t& eSSConnections_140)
{
#ifdef PRINT_INFO
	std::cout << "Fetch_Default_IfAllEmpty_13d" << std::endl;
#endif
	processInputPackets( requirements_13e, eSSConnections_140);
}

bool Fetch_Default_IfAllEmpty_13d::isInputUnique( const Udm::Object& requirement_146, const Udm::Object& eSSConnection_14f)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRequirement_148= _requirement_142.begin(), itESSConnection_151= _eSSConnection_14b.begin(); itRequirement_148!= _requirement_142.end(), itESSConnection_151!= _eSSConnection_14b.end(); ++itRequirement_148, ++itESSConnection_151)
	{
		if( ( *itRequirement_148== requirement_146)&& ( *itESSConnection_151== eSSConnection_14f))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_requirement_142.push_back( requirement_146);
		_eSSConnection_14b.push_back( eSSConnection_14f);
	}
	return isUnique;
}

bool Fetch_Default_IfAllEmpty_13d::isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& ESSConnection, const Udm::Object& PublishConnector, const Udm::Object& Requirement)
{
	bool Gz_guard= false;
	string value; ESSConnection.GetStrValue("ConnectorID", value); return (value==""); ;
	return Gz_guard;
}

void Fetch_Default_IfAllEmpty_13d::processInputPackets( const Packets_t& requirements_13e, const Packets_t& eSSConnections_140)
{
	for( Packets_t::const_iterator itRequirement_143= requirements_13e.begin(), itESSConnection_14c= eSSConnections_140.begin(); itRequirement_143!= requirements_13e.end(), itESSConnection_14c!= eSSConnections_140.end(); ++itRequirement_143, ++itESSConnection_14c)
	{
		bool isUnique= isInputUnique( *itRequirement_143, *itESSConnection_14c);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRequirement_143, *itESSConnection_14c);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Fetch_Default_IfAllEmpty_13d::patternMatcher( const Udm::Object& requirement_144, const Udm::Object& eSSConnection_14d)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( requirement_144.type(), PICML::Requirement::meta))
			continue;
		PICML::Requirement requirement_149= PICML::Requirement::Cast( requirement_144);
		if( false== Uml::IsDerivedFrom( eSSConnection_14d.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_152= cadena_scenario::ESSConnection::Cast( eSSConnection_14d);
		set< PICML::AssemblyDeployRequirement> assemblyDeployRequirements_154= requirement_149.srcAssemblyDeployRequirement();
		for( set< PICML::AssemblyDeployRequirement>::const_iterator itAssemblyDeployRequirements_155= assemblyDeployRequirements_154.begin(); itAssemblyDeployRequirements_155!= assemblyDeployRequirements_154.end(); ++itAssemblyDeployRequirements_155)
		{
			PICML::AssemblyDeployRequirement currAssemblyDeployRequirement_156= *itAssemblyDeployRequirements_155;
			PICML::PublishConnector publishConnector_157= currAssemblyDeployRequirement_156.srcAssemblyDeployRequirement_end();
			Match currMatch;
			currMatch.assemblyDeployRequirement_158= currAssemblyDeployRequirement_156;
			currMatch.requirement_159= requirement_149;
			currMatch.publishConnector_15a= publishConnector_157;
			currMatch.eSSConnection_15b= eSSConnection_152;
			bool Gz_guard= isGuardTrue( currMatch.assemblyDeployRequirement_158, currMatch.eSSConnection_15b, currMatch.publishConnector_15a, currMatch.requirement_159);
			if( true== Gz_guard)
				_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Fetch_Default_IfAllEmpty_13d::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& AssemblyDeployRequirement= currMatch.assemblyDeployRequirement_158;
		Udm::Object& ESSConnection= currMatch.eSSConnection_15b;
		Udm::Object& PublishConnector= currMatch.publishConnector_15a;
		Udm::Object& Requirement= currMatch.requirement_159;
		{string ConnName, position; PublishConnector.GetStrValue("name", ConnName); PublishConnector.GetStrValue("position", position); int iuid = PublishConnector.uniqueId(); char suid[20]; sprintf(suid, "%u", iuid);  ESSConnection.SetStrValue("ConnectorID", ConnName + position + suid);};
		outputAppender( );
	}
}

void Fetch_Default_IfAllEmpty_13d::outputAppender()
{
}

void Block_FetchAll_ConnectorID_Property_Value_IfNotEmpty_163::operator()( const Packets_t& ins_164, const Packets_t& ins_166, Packets_t& outs_168, Packets_t& outs_169)
{
#ifdef PRINT_INFO
	std::cout << "Block_FetchAll_ConnectorID_Property_Value_IfNotEmpty_163" << std::endl;
#endif
	_out_16a= &outs_168;
	_out_16b= &outs_169;
	if( ( !ins_166.empty())&& ( !ins_164.empty()))
		callRule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_18c( ins_166, ins_164);
	_out_16a->insert( _out_16a->end(), ins_164.begin(), ins_164.end());
	_out_16b->insert( _out_16b->end(), ins_166.begin(), ins_166.end());
}

void Block_FetchAll_ConnectorID_Property_Value_IfNotEmpty_163::callRule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_18c( const Packets_t& requirements_16d, const Packets_t& eSSConnections_16f)
{
	Rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c;
	rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c( requirements_16d, eSSConnections_16f);
}

void Rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c::operator()( const Packets_t& requirements_16d, const Packets_t& eSSConnections_16f)
{
#ifdef PRINT_INFO
	std::cout << "Rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c" << std::endl;
#endif
	processInputPackets( requirements_16d, eSSConnections_16f);
}

bool Rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c::isInputUnique( const Udm::Object& requirement_175, const Udm::Object& eSSConnection_17e)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRequirement_177= _requirement_171.begin(), itESSConnection_180= _eSSConnection_17a.begin(); itRequirement_177!= _requirement_171.end(), itESSConnection_180!= _eSSConnection_17a.end(); ++itRequirement_177, ++itESSConnection_180)
	{
		if( ( *itRequirement_177== requirement_175)&& ( *itESSConnection_180== eSSConnection_17e))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_requirement_171.push_back( requirement_175);
		_eSSConnection_17a.push_back( eSSConnection_17e);
	}
	return isUnique;
}

bool Rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c::isGuardTrue( const Udm::Object& ESSConnection, const Udm::Object& Property, const Udm::Object& Requirement)
{
	bool Gz_guard= false;
	string name; Property.GetStrValue("name", name); return (name=="ConnectorID");;
	return Gz_guard;
}

void Rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c::processInputPackets( const Packets_t& requirements_16d, const Packets_t& eSSConnections_16f)
{
	for( Packets_t::const_iterator itRequirement_172= requirements_16d.begin(), itESSConnection_17b= eSSConnections_16f.begin(); itRequirement_172!= requirements_16d.end(), itESSConnection_17b!= eSSConnections_16f.end(); ++itRequirement_172, ++itESSConnection_17b)
	{
		bool isUnique= isInputUnique( *itRequirement_172, *itESSConnection_17b);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRequirement_172, *itESSConnection_17b);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c::patternMatcher( const Udm::Object& requirement_173, const Udm::Object& eSSConnection_17c)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( requirement_173.type(), PICML::Requirement::meta))
			continue;
		PICML::Requirement requirement_178= PICML::Requirement::Cast( requirement_173);
		if( false== Uml::IsDerivedFrom( eSSConnection_17c.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_181= cadena_scenario::ESSConnection::Cast( eSSConnection_17c);
		set< PICML::Property> propertys_183= requirement_178.Property_kind_children();
		for( set< PICML::Property>::const_iterator itProperty_184= propertys_183.begin(); itProperty_184!= propertys_183.end(); ++itProperty_184)
		{
			PICML::Property currProperty_185= *itProperty_184;
			Match currMatch;
			currMatch.property_186= currProperty_185;
			currMatch.requirement_187= requirement_178;
			currMatch.eSSConnection_188= eSSConnection_181;
			bool Gz_guard= isGuardTrue( currMatch.eSSConnection_188, currMatch.property_186, currMatch.requirement_187);
			if( true== Gz_guard)
				_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& ESSConnection= currMatch.eSSConnection_188;
		Udm::Object& Property= currMatch.property_186;
		Udm::Object& Requirement= currMatch.requirement_187;
		{string value; Property.GetStrValue("DataValue", value);  if (value != "") ESSConnection.SetStrValue("ConnectorID", value);};
		outputAppender( );
	}
}

void Rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c::outputAppender()
{
}

void RecreateOne_ConnectorIDProperty_and_DumpValueBack_18f::operator()( const Packets_t& requirements_190, const Packets_t& eSSConnections_192)
{
#ifdef PRINT_INFO
	std::cout << "RecreateOne_ConnectorIDProperty_and_DumpValueBack_18f" << std::endl;
#endif
	processInputPackets( requirements_190, eSSConnections_192);
}

bool RecreateOne_ConnectorIDProperty_and_DumpValueBack_18f::isInputUnique( const Udm::Object& requirement_198, const Udm::Object& eSSConnection_1a1)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRequirement_19a= _requirement_194.begin(), itESSConnection_1a3= _eSSConnection_19d.begin(); itRequirement_19a!= _requirement_194.end(), itESSConnection_1a3!= _eSSConnection_19d.end(); ++itRequirement_19a, ++itESSConnection_1a3)
	{
		if( ( *itRequirement_19a== requirement_198)&& ( *itESSConnection_1a3== eSSConnection_1a1))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_requirement_194.push_back( requirement_198);
		_eSSConnection_19d.push_back( eSSConnection_1a1);
	}
	return isUnique;
}

void RecreateOne_ConnectorIDProperty_and_DumpValueBack_18f::processInputPackets( const Packets_t& requirements_190, const Packets_t& eSSConnections_192)
{
	for( Packets_t::const_iterator itRequirement_195= requirements_190.begin(), itESSConnection_19e= eSSConnections_192.begin(); itRequirement_195!= requirements_190.end(), itESSConnection_19e!= eSSConnections_192.end(); ++itRequirement_195, ++itESSConnection_19e)
	{
		bool isUnique= isInputUnique( *itRequirement_195, *itESSConnection_19e);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRequirement_195, *itESSConnection_19e);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool RecreateOne_ConnectorIDProperty_and_DumpValueBack_18f::patternMatcher( const Udm::Object& requirement_196, const Udm::Object& eSSConnection_19f)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( requirement_196.type(), PICML::Requirement::meta))
			continue;
		PICML::Requirement requirement_19b= PICML::Requirement::Cast( requirement_196);
		if( false== Uml::IsDerivedFrom( eSSConnection_19f.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_1a4= cadena_scenario::ESSConnection::Cast( eSSConnection_19f);
		Udm::Object requirementParent_1a6= requirement_19b.container();
		if( false== Uml::IsDerivedFrom( requirementParent_1a6.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssemblyRequirement_1a7= PICML::ComponentAssembly::Cast( requirementParent_1a6);
		Udm::Object componentAssemblyParent_1a8= componentAssemblyRequirement_1a7.container();
		if( false== Uml::IsDerivedFrom( componentAssemblyParent_1a8.type(), PICML::ComponentImplementationContainer::meta))
			continue;
		PICML::ComponentImplementationContainer componentImplementationContainerComponentAssembly_1a9= PICML::ComponentImplementationContainer::Cast( componentAssemblyParent_1a8);
		Udm::Object componentImplementationContainerParent_1aa= componentImplementationContainerComponentAssembly_1a9.container();
		if( false== Uml::IsDerivedFrom( componentImplementationContainerParent_1aa.type(), PICML::ComponentImplementations::meta))
			continue;
		PICML::ComponentImplementations componentImplementationsComponentImplementationContainer_1ab= PICML::ComponentImplementations::Cast( componentImplementationContainerParent_1aa);
		Udm::Object componentImplementationsParent_1ac= componentImplementationsComponentImplementationContainer_1ab.container();
		if( false== Uml::IsDerivedFrom( componentImplementationsParent_1ac.type(), PICML::RootFolder::meta))
			continue;
		PICML::RootFolder rootFolderComponentImplementations_1ad= PICML::RootFolder::Cast( componentImplementationsParent_1ac);
		set< PICML::PredefinedTypes> predefinedTypess_1ae= rootFolderComponentImplementations_1ad.PredefinedTypes_kind_children();
		for( set< PICML::PredefinedTypes>::const_iterator itPredefinedTypes_1af= predefinedTypess_1ae.begin(); itPredefinedTypes_1af!= predefinedTypess_1ae.end(); ++itPredefinedTypes_1af)
		{
			PICML::PredefinedTypes currPredefinedTypes_1b0= *itPredefinedTypes_1af;
			set< PICML::String> strings_1b1= currPredefinedTypes_1b0.String_kind_children();
			for( set< PICML::String>::const_iterator itString_1b2= strings_1b1.begin(); itString_1b2!= strings_1b1.end(); ++itString_1b2)
			{
				PICML::String currString_1b3= *itString_1b2;
				Match currMatch;
				currMatch.predefinedTypes_1b4= currPredefinedTypes_1b0;
				currMatch.string_1b5= currString_1b3;
				currMatch.rootFolder_1b6= rootFolderComponentImplementations_1ad;
				currMatch.componentImplementations_1b7= componentImplementationsComponentImplementationContainer_1ab;
				currMatch.componentImplementationContainer_1b8= componentImplementationContainerComponentAssembly_1a9;
				currMatch.componentAssembly_1b9= componentAssemblyRequirement_1a7;
				currMatch.requirement_1ba= requirement_19b;
				currMatch.eSSConnection_1bb= eSSConnection_1a4;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void RecreateOne_ConnectorIDProperty_and_DumpValueBack_18f::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::Property newProperty_1bc= PICML::Property::Create( currMatch.requirement_1ba);
		PICML::DataType newDataType_1bd= PICML::DataType::Create( newProperty_1bc);
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_1b9;
		Udm::Object& ComponentImplementationContainer= currMatch.componentImplementationContainer_1b8;
		Udm::Object& ComponentImplementations= currMatch.componentImplementations_1b7;
		Udm::Object& DataType= newDataType_1bd;
		Udm::Object& ESSConnection= currMatch.eSSConnection_1bb;
		Udm::Object& PredefinedTypes= currMatch.predefinedTypes_1b4;
		Udm::Object& Property= newProperty_1bc;
		Udm::Object& Requirement= currMatch.requirement_1ba;
		Udm::Object& RootFolder= currMatch.rootFolder_1b6;
		Udm::Object& String= currMatch.string_1b5;
		{Property.SetStrValue("name","ConnectorID");  string connid; ESSConnection.GetStrValue("ConnectorID", connid); Property.SetStrValue("DataValue", connid);  string stringtypename; String.type().GetStrValue("name", stringtypename); DataType.SetStrValue("name", stringtypename); };
		newDataType_1bd.ref()= currMatch.string_1b5;
		outputAppender( );
	}
}

void RecreateOne_ConnectorIDProperty_and_DumpValueBack_18f::outputAppender()
{
}

void CreateOne_ConnectorIDRequirement_IfNeeded_And_Match_1be::operator()( const Packets_t& ins_1bf, const Packets_t& ins_1c1, Packets_t& outs_1c3, Packets_t& outs_1c4)
{
#ifdef PRINT_INFO
	std::cout << "CreateOne_ConnectorIDRequirement_IfNeeded_And_Match_1be" << std::endl;
#endif
	_out_1c5= &outs_1c3;
	_out_1c6= &outs_1c4;
	if( ( !ins_1bf.empty())&& ( !ins_1c1.empty()))
		callCreate_ConnectorIDRequirement_IfNeeded_244( ins_1bf, ins_1c1);
}

void CreateOne_ConnectorIDRequirement_IfNeeded_And_Match_1be::callCreate_ConnectorIDRequirement_IfNeeded_244( const Packets_t& ins_1c8, const Packets_t& ins_1ca)
{
	Packets_t outs_1cc;
	Packets_t outs_1cd;
	Create_ConnectorIDRequirement_IfNeeded_1c7 create_ConnectorIDRequirement_IfNeeded_1c7;
	create_ConnectorIDRequirement_IfNeeded_1c7( ins_1c8, ins_1ca, outs_1cc, outs_1cd);
	if( ( !outs_1cc.empty())&& ( !outs_1cd.empty()))
		callMatch_ConnectorID_Requirement_247( outs_1cc, outs_1cd);
}

void CreateOne_ConnectorIDRequirement_IfNeeded_And_Match_1be::callMatch_ConnectorID_Requirement_247( const Packets_t& eSSConnections_21a, const Packets_t& publishConnectors_21e)
{
	Packets_t eSSConnections_21c;
	Packets_t requirements_21d;
	Match_ConnectorID_Requirement_219 match_ConnectorID_Requirement_219;
	match_ConnectorID_Requirement_219( eSSConnections_21a, publishConnectors_21e, eSSConnections_21c, requirements_21d);
	_out_1c6->insert( _out_1c6->end(), eSSConnections_21c.begin(), eSSConnections_21c.end());
	_out_1c5->insert( _out_1c5->end(), requirements_21d.begin(), requirements_21d.end());
}

void Create_ConnectorIDRequirement_IfNeeded_1c7::operator()( const Packets_t& ins_1c8, const Packets_t& ins_1ca, Packets_t& outs_1cc, Packets_t& outs_1cd)
{
#ifdef PRINT_INFO
	std::cout << "Create_ConnectorIDRequirement_IfNeeded_1c7" << std::endl;
#endif
	_out_1ce= &outs_1cc;
	_out_1cf= &outs_1cd;
	if( ( !ins_1c8.empty()))
		callTest_ConnectorIDRequirement_DoesntExist_215( ins_1c8);
	_out_1cf->insert( _out_1cf->end(), ins_1c8.begin(), ins_1c8.end());
	_out_1ce->insert( _out_1ce->end(), ins_1ca.begin(), ins_1ca.end());
}

void Create_ConnectorIDRequirement_IfNeeded_1c7::callTest_ConnectorIDRequirement_DoesntExist_215( const Packets_t& ins_1d2)
{
	Packets_t outs_1d1;
	Test_ConnectorIDRequirement_DoesntExist_1d0 test_ConnectorIDRequirement_DoesntExist_1d0;
	test_ConnectorIDRequirement_DoesntExist_1d0( ins_1d2, outs_1d1);
	if( ( !outs_1d1.empty()))
		callCreate_ConnectorID_Requirement_217( outs_1d1);
}

void Create_ConnectorIDRequirement_IfNeeded_1c7::callCreate_ConnectorID_Requirement_217( const Packets_t& publishConnectors_204)
{
	Create_ConnectorID_Requirement_203 create_ConnectorID_Requirement_203;
	create_ConnectorID_Requirement_203( publishConnectors_204);
}

void Test_ConnectorIDRequirement_DoesntExist_1d0::operator()( const Packets_t& ins_1d2, Packets_t& outs_1d1)
{
#ifdef PRINT_INFO
	std::cout << "Test_ConnectorIDRequirement_DoesntExist_1d0" << std::endl;
#endif
	_out_1d4= &outs_1d1;
	for( Packets_t::const_iterator itIn_1d6= ins_1d2.begin(); itIn_1d6!= ins_1d2.end(); ++itIn_1d6)
	{
		bool isUnique= isInputUnique( *itIn_1d6);
		if( !isUnique)
			continue;
		Packets_t oneIn_1da( 1, *itIn_1d6);
		executeOne( oneIn_1da);
	}
}

void Test_ConnectorIDRequirement_DoesntExist_1d0::executeOne( const Packets_t& ins_1d2)
{
	ConnectorID_Requirement_Exists_1dc connectorID_Requirement_Exists_1dc;
	bool isMatchConnectorID_Requirement_Exists_1dc= connectorID_Requirement_Exists_1dc( ins_1d2);
	if( isMatchConnectorID_Requirement_Exists_1dc)
		return;
	Packets_t publishConnectors_1f5;
	ConnectorID_Requirement_ToBeCreated_1f2 connectorID_Requirement_ToBeCreated_1f2;
	bool isMatchConnectorID_Requirement_ToBeCreated_1f2= connectorID_Requirement_ToBeCreated_1f2( ins_1d2, publishConnectors_1f5);
	_out_1d4->insert( _out_1d4->end(), publishConnectors_1f5.begin(), publishConnectors_1f5.end());
}

bool Test_ConnectorIDRequirement_DoesntExist_1d0::isInputUnique( const Udm::Object& in_1d7)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itIn_1d9= _in_1d5.begin(); itIn_1d9!= _in_1d5.end(); ++itIn_1d9)
	{
		if( ( *itIn_1d9== in_1d7))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_in_1d5.push_back( in_1d7);
	return isUnique;
}

bool ConnectorID_Requirement_Exists_1dc::operator()( const Packets_t& publishConnectors_1dd)
{
#ifdef PRINT_INFO
	std::cout << "ConnectorID_Requirement_Exists_1dc" << std::endl;
#endif
	processInputPackets( publishConnectors_1dd);
	if( false== _matches.empty())
		return true;
	return false;
}

bool ConnectorID_Requirement_Exists_1dc::isInputUnique( const Udm::Object& publishConnector_1e3)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPublishConnector_1e5= _publishConnector_1df.begin(); itPublishConnector_1e5!= _publishConnector_1df.end(); ++itPublishConnector_1e5)
	{
		if( ( *itPublishConnector_1e5== publishConnector_1e3))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_publishConnector_1df.push_back( publishConnector_1e3);
	return isUnique;
}

bool ConnectorID_Requirement_Exists_1dc::isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& PublishConnector, const Udm::Object& Requirement)
{
	bool Gz_guard= false;
	string name;  Requirement.GetStrValue("name",name); return (name == "ConnectorID");;
	return Gz_guard;
}

void ConnectorID_Requirement_Exists_1dc::processInputPackets( const Packets_t& publishConnectors_1dd)
{
	for( Packets_t::const_iterator itPublishConnector_1e0= publishConnectors_1dd.begin(); itPublishConnector_1e0!= publishConnectors_1dd.end(); ++itPublishConnector_1e0)
	{
		bool isUnique= isInputUnique( *itPublishConnector_1e0);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPublishConnector_1e0);
	}
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( );
	}
}

bool ConnectorID_Requirement_Exists_1dc::patternMatcher( const Udm::Object& publishConnector_1e1)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( publishConnector_1e1.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_1e6= PICML::PublishConnector::Cast( publishConnector_1e1);
		set< PICML::AssemblyDeployRequirement> assemblyDeployRequirements_1e8= publishConnector_1e6.dstAssemblyDeployRequirement();
		for( set< PICML::AssemblyDeployRequirement>::const_iterator itAssemblyDeployRequirements_1e9= assemblyDeployRequirements_1e8.begin(); itAssemblyDeployRequirements_1e9!= assemblyDeployRequirements_1e8.end(); ++itAssemblyDeployRequirements_1e9)
		{
			PICML::AssemblyDeployRequirement currAssemblyDeployRequirement_1ea= *itAssemblyDeployRequirements_1e9;
			PICML::Requirement requirement_1eb= currAssemblyDeployRequirement_1ea.dstAssemblyDeployRequirement_end();
			Match currMatch;
			currMatch.assemblyDeployRequirement_1ec= currAssemblyDeployRequirement_1ea;
			currMatch.requirement_1ed= requirement_1eb;
			currMatch.publishConnector_1ee= publishConnector_1e6;
			bool Gz_guard= isGuardTrue( currMatch.assemblyDeployRequirement_1ec, currMatch.publishConnector_1ee, currMatch.requirement_1ed);
			if( true== Gz_guard)
				_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void ConnectorID_Requirement_Exists_1dc::outputAppender()
{
}

bool ConnectorID_Requirement_ToBeCreated_1f2::operator()( const Packets_t& publishConnectors_1f3, Packets_t& publishConnectors_1f5)
{
#ifdef PRINT_INFO
	std::cout << "ConnectorID_Requirement_ToBeCreated_1f2" << std::endl;
#endif
	_publishConnector_1f6= &publishConnectors_1f5;
	processInputPackets( publishConnectors_1f3);
	if( false== _matches.empty())
		return true;
	return false;
}

bool ConnectorID_Requirement_ToBeCreated_1f2::isInputUnique( const Udm::Object& publishConnector_1fb)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPublishConnector_1fd= _publishConnector_1f7.begin(); itPublishConnector_1fd!= _publishConnector_1f7.end(); ++itPublishConnector_1fd)
	{
		if( ( *itPublishConnector_1fd== publishConnector_1fb))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_publishConnector_1f7.push_back( publishConnector_1fb);
	return isUnique;
}

void ConnectorID_Requirement_ToBeCreated_1f2::processInputPackets( const Packets_t& publishConnectors_1f3)
{
	for( Packets_t::const_iterator itPublishConnector_1f8= publishConnectors_1f3.begin(); itPublishConnector_1f8!= publishConnectors_1f3.end(); ++itPublishConnector_1f8)
	{
		bool isUnique= isInputUnique( *itPublishConnector_1f8);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPublishConnector_1f8);
	}
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.publishConnector_200);
	}
}

bool ConnectorID_Requirement_ToBeCreated_1f2::patternMatcher( const Udm::Object& publishConnector_1f9)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( publishConnector_1f9.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_1fe= PICML::PublishConnector::Cast( publishConnector_1f9);
		Match currMatch;
		currMatch.publishConnector_200= publishConnector_1fe;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void ConnectorID_Requirement_ToBeCreated_1f2::outputAppender( const PICML::PublishConnector& publishConnector_201)
{
	_publishConnector_1f6->push_back( publishConnector_201);
}

void Create_ConnectorID_Requirement_203::operator()( const Packets_t& publishConnectors_204)
{
#ifdef PRINT_INFO
	std::cout << "Create_ConnectorID_Requirement_203" << std::endl;
#endif
	processInputPackets( publishConnectors_204);
}

bool Create_ConnectorID_Requirement_203::isInputUnique( const Udm::Object& publishConnector_20a)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPublishConnector_20c= _publishConnector_206.begin(); itPublishConnector_20c!= _publishConnector_206.end(); ++itPublishConnector_20c)
	{
		if( ( *itPublishConnector_20c== publishConnector_20a))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_publishConnector_206.push_back( publishConnector_20a);
	return isUnique;
}

void Create_ConnectorID_Requirement_203::processInputPackets( const Packets_t& publishConnectors_204)
{
	for( Packets_t::const_iterator itPublishConnector_207= publishConnectors_204.begin(); itPublishConnector_207!= publishConnectors_204.end(); ++itPublishConnector_207)
	{
		bool isUnique= isInputUnique( *itPublishConnector_207);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPublishConnector_207);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Create_ConnectorID_Requirement_203::patternMatcher( const Udm::Object& publishConnector_208)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( publishConnector_208.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_20d= PICML::PublishConnector::Cast( publishConnector_208);
		Udm::Object publishConnectorParent_20f= publishConnector_20d.container();
		if( false== Uml::IsDerivedFrom( publishConnectorParent_20f.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssemblyPublishConnector_210= PICML::ComponentAssembly::Cast( publishConnectorParent_20f);
		Match currMatch;
		currMatch.componentAssembly_211= componentAssemblyPublishConnector_210;
		currMatch.publishConnector_212= publishConnector_20d;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void Create_ConnectorID_Requirement_203::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		PICML::AssemblyDeployRequirement newAssemblyDeployRequirement_213= PICML::AssemblyDeployRequirement::Create( currMatch.componentAssembly_211);
		PICML::Requirement newRequirement_214= PICML::Requirement::Create( currMatch.componentAssembly_211);
		Udm::Object& AssemblyDeployRequirement= newAssemblyDeployRequirement_213;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_211;
		Udm::Object& PublishConnector= currMatch.publishConnector_212;
		Udm::Object& Requirement= newRequirement_214;
		{Requirement.SetStrValue("name", "ConnectorID");};
		newAssemblyDeployRequirement_213.srcAssemblyDeployRequirement_end()= currMatch.publishConnector_212;
		newAssemblyDeployRequirement_213.dstAssemblyDeployRequirement_end()= newRequirement_214;
		outputAppender( );
	}
}

void Create_ConnectorID_Requirement_203::outputAppender()
{
}

void Match_ConnectorID_Requirement_219::operator()( const Packets_t& eSSConnections_21a, const Packets_t& publishConnectors_21e, Packets_t& eSSConnections_21c, Packets_t& requirements_21d)
{
#ifdef PRINT_INFO
	std::cout << "Match_ConnectorID_Requirement_219" << std::endl;
#endif
	_eSSConnection_220= &eSSConnections_21c;
	_requirement_221= &requirements_21d;
	processInputPackets( eSSConnections_21a, publishConnectors_21e);
}

bool Match_ConnectorID_Requirement_219::isInputUnique( const Udm::Object& eSSConnection_226, const Udm::Object& publishConnector_22f)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itESSConnection_228= _eSSConnection_222.begin(), itPublishConnector_231= _publishConnector_22b.begin(); itESSConnection_228!= _eSSConnection_222.end(), itPublishConnector_231!= _publishConnector_22b.end(); ++itESSConnection_228, ++itPublishConnector_231)
	{
		if( ( *itESSConnection_228== eSSConnection_226)&& ( *itPublishConnector_231== publishConnector_22f))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_eSSConnection_222.push_back( eSSConnection_226);
		_publishConnector_22b.push_back( publishConnector_22f);
	}
	return isUnique;
}

bool Match_ConnectorID_Requirement_219::isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& ESSConnection, const Udm::Object& PublishConnector, const Udm::Object& Requirement)
{
	bool Gz_guard= false;
	string name; Requirement.GetStrValue("name", name); return (name=="ConnectorID");;
	return Gz_guard;
}

void Match_ConnectorID_Requirement_219::processInputPackets( const Packets_t& eSSConnections_21a, const Packets_t& publishConnectors_21e)
{
	for( Packets_t::const_iterator itESSConnection_223= eSSConnections_21a.begin(), itPublishConnector_22c= publishConnectors_21e.begin(); itESSConnection_223!= eSSConnections_21a.end(), itPublishConnector_22c!= publishConnectors_21e.end(); ++itESSConnection_223, ++itPublishConnector_22c)
	{
		bool isUnique= isInputUnique( *itESSConnection_223, *itPublishConnector_22c);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itESSConnection_223, *itPublishConnector_22c);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Match_ConnectorID_Requirement_219::patternMatcher( const Udm::Object& eSSConnection_224, const Udm::Object& publishConnector_22d)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( eSSConnection_224.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_229= cadena_scenario::ESSConnection::Cast( eSSConnection_224);
		if( false== Uml::IsDerivedFrom( publishConnector_22d.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_232= PICML::PublishConnector::Cast( publishConnector_22d);
		set< PICML::AssemblyDeployRequirement> assemblyDeployRequirements_234= publishConnector_232.dstAssemblyDeployRequirement();
		for( set< PICML::AssemblyDeployRequirement>::const_iterator itAssemblyDeployRequirements_235= assemblyDeployRequirements_234.begin(); itAssemblyDeployRequirements_235!= assemblyDeployRequirements_234.end(); ++itAssemblyDeployRequirements_235)
		{
			PICML::AssemblyDeployRequirement currAssemblyDeployRequirement_236= *itAssemblyDeployRequirements_235;
			PICML::Requirement requirement_237= currAssemblyDeployRequirement_236.dstAssemblyDeployRequirement_end();
			Match currMatch;
			currMatch.eSSConnection_238= eSSConnection_229;
			currMatch.requirement_239= requirement_237;
			currMatch.publishConnector_23a= publishConnector_232;
			currMatch.assemblyDeployRequirement_23b= currAssemblyDeployRequirement_236;
			bool Gz_guard= isGuardTrue( currMatch.assemblyDeployRequirement_23b, currMatch.eSSConnection_238, currMatch.publishConnector_23a, currMatch.requirement_239);
			if( true== Gz_guard)
				_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Match_ConnectorID_Requirement_219::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.eSSConnection_238, currMatch.requirement_239);
	}
}

void Match_ConnectorID_Requirement_219::outputAppender( const cadena_scenario::ESSConnection& eSSConnection_240, const PICML::Requirement& requirement_242)
{
	_eSSConnection_220->push_back( eSSConnection_240);
	_requirement_221->push_back( requirement_242);
}

void Block_Remove_Multiple_ConnectorID_Requirements_24a::operator()( const Packets_t& ins_24b, const Packets_t& ins_24d, Packets_t& outs_24f, Packets_t& outs_250)
{
#ifdef PRINT_INFO
	std::cout << "Block_Remove_Multiple_ConnectorID_Requirements_24a" << std::endl;
#endif
	_out_251= &outs_24f;
	_out_252= &outs_250;
	if( ( !ins_24d.empty()))
		callRule_Remove_Multiple_ConnectorID_Requirements_279( ins_24d);
	_out_251->insert( _out_251->end(), ins_24b.begin(), ins_24b.end());
	_out_252->insert( _out_252->end(), ins_24d.begin(), ins_24d.end());
}

void Block_Remove_Multiple_ConnectorID_Requirements_24a::callRule_Remove_Multiple_ConnectorID_Requirements_279( const Packets_t& publishConnectors_254)
{
	Rule_Remove_Multiple_ConnectorID_Requirements_253 rule_Remove_Multiple_ConnectorID_Requirements_253;
	rule_Remove_Multiple_ConnectorID_Requirements_253( publishConnectors_254);
}

void Rule_Remove_Multiple_ConnectorID_Requirements_253::operator()( const Packets_t& publishConnectors_254)
{
#ifdef PRINT_INFO
	std::cout << "Rule_Remove_Multiple_ConnectorID_Requirements_253" << std::endl;
#endif
	processInputPackets( publishConnectors_254);
}

bool Rule_Remove_Multiple_ConnectorID_Requirements_253::isInputUnique( const Udm::Object& publishConnector_25a)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPublishConnector_25c= _publishConnector_256.begin(); itPublishConnector_25c!= _publishConnector_256.end(); ++itPublishConnector_25c)
	{
		if( ( *itPublishConnector_25c== publishConnector_25a))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_publishConnector_256.push_back( publishConnector_25a);
	return isUnique;
}

bool Rule_Remove_Multiple_ConnectorID_Requirements_253::isGuardTrue( const Udm::Object& AssemblyDeployRequirement1, const Udm::Object& AssemblyDeployRequirement2, const Udm::Object& PublishConnector, const Udm::Object& Requirement1, const Udm::Object& Requirement2)
{
	bool Gz_guard= false;
	string name;  Requirement1.GetStrValue("name",name); if (name != "ConnectorID") return false;  Requirement2.GetStrValue("name",name); if (name != "ConnectorID") return true;  if (Requirement1.uniqueId() == Requirement2.uniqueId()) return false;  return true;;
	return Gz_guard;
}

void Rule_Remove_Multiple_ConnectorID_Requirements_253::processInputPackets( const Packets_t& publishConnectors_254)
{
	for( Packets_t::const_iterator itPublishConnector_257= publishConnectors_254.begin(); itPublishConnector_257!= publishConnectors_254.end(); ++itPublishConnector_257)
	{
		bool isUnique= isInputUnique( *itPublishConnector_257);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPublishConnector_257);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Rule_Remove_Multiple_ConnectorID_Requirements_253::patternMatcher( const Udm::Object& publishConnector_258)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( publishConnector_258.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_25d= PICML::PublishConnector::Cast( publishConnector_258);
		set< PICML::AssemblyDeployRequirement> assemblyDeployRequirement2s_25f= publishConnector_25d.dstAssemblyDeployRequirement();
		for( set< PICML::AssemblyDeployRequirement>::const_iterator itAssemblyDeployRequirement2s_260= assemblyDeployRequirement2s_25f.begin(); itAssemblyDeployRequirement2s_260!= assemblyDeployRequirement2s_25f.end(); ++itAssemblyDeployRequirement2s_260)
		{
			PICML::AssemblyDeployRequirement currAssemblyDeployRequirement2_261= *itAssemblyDeployRequirement2s_260;
			PICML::Requirement requirement2_262= currAssemblyDeployRequirement2_261.dstAssemblyDeployRequirement_end();
			set< PICML::AssemblyDeployRequirement> assemblyDeployRequirement1s_263= publishConnector_25d.dstAssemblyDeployRequirement();
			for( set< PICML::AssemblyDeployRequirement>::const_iterator itAssemblyDeployRequirement1s_264= assemblyDeployRequirement1s_263.begin(); itAssemblyDeployRequirement1s_264!= assemblyDeployRequirement1s_263.end(); ++itAssemblyDeployRequirement1s_264)
			{
				PICML::AssemblyDeployRequirement currAssemblyDeployRequirement1_265= *itAssemblyDeployRequirement1s_264;
				// Simple association identity check.
				if( ( currAssemblyDeployRequirement2_261!= currAssemblyDeployRequirement1_265))
				{
					PICML::Requirement requirement1_266= currAssemblyDeployRequirement1_265.dstAssemblyDeployRequirement_end();
					Match currMatch;
					currMatch.requirement1_267= requirement1_266;
					currMatch.requirement2_268= requirement2_262;
					currMatch.assemblyDeployRequirement2_269= currAssemblyDeployRequirement2_261;
					currMatch.publishConnector_26a= publishConnector_25d;
					currMatch.assemblyDeployRequirement1_26b= currAssemblyDeployRequirement1_265;
					bool Gz_guard= isGuardTrue( currMatch.assemblyDeployRequirement1_26b, currMatch.assemblyDeployRequirement2_269, currMatch.publishConnector_26a, currMatch.requirement1_267, currMatch.requirement2_268);
					if( true== Gz_guard)
						_matches.push_back( currMatch);
				}
			}
		}
	}
	return !_matches.empty();
}

void Rule_Remove_Multiple_ConnectorID_Requirements_253::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		set< PICML::AssemblyselectRequirement> delAssemblyselectRequirements_271= currMatch.requirement2_268.srcAssemblyselectRequirement();
		for( set< PICML::AssemblyselectRequirement>::const_iterator itdelAssemblyselectRequirements_271= delAssemblyselectRequirements_271.begin(); itdelAssemblyselectRequirements_271!= delAssemblyselectRequirements_271.end(); ++itdelAssemblyselectRequirements_271)
		{
			PICML::AssemblyselectRequirement currAssemblyselectRequirement_272= *itdelAssemblyselectRequirements_271;
			if( currAssemblyselectRequirement_272)
				currAssemblyselectRequirement_272.DeleteObject();
		}
		set< PICML::AssemblyDeployRequirement> delAssemblyDeployRequirements_273= currMatch.requirement2_268.srcAssemblyDeployRequirement();
		for( set< PICML::AssemblyDeployRequirement>::const_iterator itdelAssemblyDeployRequirements_273= delAssemblyDeployRequirements_273.begin(); itdelAssemblyDeployRequirements_273!= delAssemblyDeployRequirements_273.end(); ++itdelAssemblyDeployRequirements_273)
		{
			PICML::AssemblyDeployRequirement currAssemblyDeployRequirement_274= *itdelAssemblyDeployRequirements_273;
			if( currAssemblyDeployRequirement_274)
				currAssemblyDeployRequirement_274.DeleteObject();
		}
		set< PICML::PackageConfSelectRequirement> delPackageConfSelectRequirements_275= currMatch.requirement2_268.srcPackageConfSelectRequirement();
		for( set< PICML::PackageConfSelectRequirement>::const_iterator itdelPackageConfSelectRequirements_275= delPackageConfSelectRequirements_275.begin(); itdelPackageConfSelectRequirements_275!= delPackageConfSelectRequirements_275.end(); ++itdelPackageConfSelectRequirements_275)
		{
			PICML::PackageConfSelectRequirement currPackageConfSelectRequirement_276= *itdelPackageConfSelectRequirements_275;
			if( currPackageConfSelectRequirement_276)
				currPackageConfSelectRequirement_276.DeleteObject();
		}
		set< PICML::ArtifactDeployRequirement> delArtifactDeployRequirements_277= currMatch.requirement2_268.srcArtifactDeployRequirement();
		for( set< PICML::ArtifactDeployRequirement>::const_iterator itdelArtifactDeployRequirements_277= delArtifactDeployRequirements_277.begin(); itdelArtifactDeployRequirements_277!= delArtifactDeployRequirements_277.end(); ++itdelArtifactDeployRequirements_277)
		{
			PICML::ArtifactDeployRequirement currArtifactDeployRequirement_278= *itdelArtifactDeployRequirements_277;
			if( currArtifactDeployRequirement_278)
				currArtifactDeployRequirement_278.DeleteObject();
		}
		if( currMatch.requirement2_268)
			currMatch.requirement2_268.DeleteObject();
		outputAppender( );
	}
}

void Rule_Remove_Multiple_ConnectorID_Requirements_253::outputAppender()
{
}

void InputSplitter_28d::operator()( const Packets_t& scenarios_28e, const Packets_t& componentAssemblys_291, Packets_t& scenarios_290, Packets_t& componentAssemblys_293)
{
#ifdef PRINT_INFO
	std::cout << "InputSplitter_28d" << std::endl;
#endif
	_scenario_294= &scenarios_290;
	_componentAssembly_295= &componentAssemblys_293;
	processInputPackets( scenarios_28e, componentAssemblys_291);
	forwardInputs( );
}

bool InputSplitter_28d::isInputUnique( const Udm::Object& scenario_29a, const Udm::Object& componentAssembly_2a3)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_29c= _scenario_296.begin(), itComponentAssembly_2a5= _componentAssembly_29f.begin(); itScenario_29c!= _scenario_296.end(), itComponentAssembly_2a5!= _componentAssembly_29f.end(); ++itScenario_29c, ++itComponentAssembly_2a5)
	{
		if( ( *itScenario_29c== scenario_29a)&& ( *itComponentAssembly_2a5== componentAssembly_2a3))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_296.push_back( scenario_29a);
		_componentAssembly_29f.push_back( componentAssembly_2a3);
	}
	return isUnique;
}

void InputSplitter_28d::processInputPackets( const Packets_t& scenarios_28e, const Packets_t& componentAssemblys_291)
{
	for( Packets_t::const_iterator itScenario_297= scenarios_28e.begin(), itComponentAssembly_2a0= componentAssemblys_291.begin(); itScenario_297!= scenarios_28e.end(), itComponentAssembly_2a0!= componentAssemblys_291.end(); ++itScenario_297, ++itComponentAssembly_2a0)
	{
		bool isUnique= isInputUnique( *itScenario_297, *itComponentAssembly_2a0);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_297, *itComponentAssembly_2a0);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool InputSplitter_28d::patternMatcher( const Udm::Object& scenario_298, const Udm::Object& componentAssembly_2a1)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_298.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_29d= cadena_scenario::Scenario::Cast( scenario_298);
		if( false== Uml::IsDerivedFrom( componentAssembly_2a1.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_2a6= PICML::ComponentAssembly::Cast( componentAssembly_2a1);
		Match currMatch;
		currMatch.scenario_2a8= scenario_29d;
		currMatch.componentAssembly_2a9= componentAssembly_2a6;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void InputSplitter_28d::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.scenario_2a8, currMatch.componentAssembly_2a9);
	}
}

void InputSplitter_28d::outputAppender( const cadena_scenario::Scenario& scenario_2aa, const PICML::ComponentAssembly& componentAssembly_2ac)
{
	_scenario_294->push_back( scenario_2aa);
	_componentAssembly_295->push_back( componentAssembly_2ac);
}

void InputSplitter_28d::forwardInputs()
{
	*_scenario_294= _scenario_296;
	*_componentAssembly_295= _componentAssembly_29f;
}

void MethodInvocations_2ae::operator()( const Packets_t& requiredRequestPorts_2b0, const Packets_t& scenarios_2b3, Packets_t& fRConnections_2af, Packets_t& requiredRequestPorts_2b2)
{
#ifdef PRINT_INFO
	std::cout << "MethodInvocations_2ae" << std::endl;
#endif
	_fRConnection_2b5= &fRConnections_2af;
	_requiredRequestPort_2b6= &requiredRequestPorts_2b2;
	processInputPackets( requiredRequestPorts_2b0, scenarios_2b3);
}

bool MethodInvocations_2ae::isInputUnique( const Udm::Object& requiredRequestPort_2bb, const Udm::Object& scenario_2c4)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRequiredRequestPort_2bd= _requiredRequestPort_2b7.begin(), itScenario_2c6= _scenario_2c0.begin(); itRequiredRequestPort_2bd!= _requiredRequestPort_2b7.end(), itScenario_2c6!= _scenario_2c0.end(); ++itRequiredRequestPort_2bd, ++itScenario_2c6)
	{
		if( ( *itRequiredRequestPort_2bd== requiredRequestPort_2bb)&& ( *itScenario_2c6== scenario_2c4))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_requiredRequestPort_2b7.push_back( requiredRequestPort_2bb);
		_scenario_2c0.push_back( scenario_2c4);
	}
	return isUnique;
}

void MethodInvocations_2ae::processInputPackets( const Packets_t& requiredRequestPorts_2b0, const Packets_t& scenarios_2b3)
{
	for( Packets_t::const_iterator itRequiredRequestPort_2b8= requiredRequestPorts_2b0.begin(), itScenario_2c1= scenarios_2b3.begin(); itRequiredRequestPort_2b8!= requiredRequestPorts_2b0.end(), itScenario_2c1!= scenarios_2b3.end(); ++itRequiredRequestPort_2b8, ++itScenario_2c1)
	{
		bool isUnique= isInputUnique( *itRequiredRequestPort_2b8, *itScenario_2c1);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRequiredRequestPort_2b8, *itScenario_2c1);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool MethodInvocations_2ae::patternMatcher( const Udm::Object& requiredRequestPort_2b9, const Udm::Object& scenario_2c2)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( requiredRequestPort_2b9.type(), PICML::RequiredRequestPort::meta))
			continue;
		PICML::RequiredRequestPort requiredRequestPort_2be= PICML::RequiredRequestPort::Cast( requiredRequestPort_2b9);
		if( false== Uml::IsDerivedFrom( scenario_2c2.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_2c7= cadena_scenario::Scenario::Cast( scenario_2c2);
		cadena_scenario::ComponentPort receptacle_2c9= requiredRequestPort_2be.cadenaPort();
		if( false== Uml::IsDerivedFrom( receptacle_2c9.type(), cadena_scenario::Receptacle::meta))
			continue;
		cadena_scenario::Receptacle receptacle_2ca= cadena_scenario::Receptacle::Cast( receptacle_2c9);
		if( !receptacle_2ca)
			continue;
		set< PICML::invoke> invokes_2cb= requiredRequestPort_2be.dstinvoke();
		for( set< PICML::invoke>::const_iterator itinvokes_2cc= invokes_2cb.begin(); itinvokes_2cc!= invokes_2cb.end(); ++itinvokes_2cc)
		{
			PICML::invoke currinvoke_2cd= *itinvokes_2cc;
			PICML::ProvidedRequestPort providedRequestPort_2ce= currinvoke_2cd.dstinvoke_end();
			cadena_scenario::ComponentPort facet_2cf= providedRequestPort_2ce.cadenaPort();
			if( false== Uml::IsDerivedFrom( facet_2cf.type(), cadena_scenario::Facet::meta))
				continue;
			cadena_scenario::Facet facet_2d0= cadena_scenario::Facet::Cast( facet_2cf);
			if( !facet_2d0)
				continue;
			Match currMatch;
			currMatch.invoke_2d1= currinvoke_2cd;
			currMatch.facet_2d2= facet_2d0;
			currMatch.receptacle_2d3= receptacle_2ca;
			currMatch.providedRequestPort_2d4= providedRequestPort_2ce;
			currMatch.requiredRequestPort_2d5= requiredRequestPort_2be;
			currMatch.scenario_2d6= scenario_2c7;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void MethodInvocations_2ae::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::FRConnection newFRConnection_2d7= cadena_scenario::FRConnection::Create( currMatch.scenario_2d6);
		currMatch.invoke_2d1.cadenaInvoke()= newFRConnection_2d7;
		newFRConnection_2d7.receptacles_end()= currMatch.receptacle_2d3;
		newFRConnection_2d7.facets_end()= currMatch.facet_2d2;
		outputAppender( newFRConnection_2d7, currMatch.requiredRequestPort_2d5);
	}
}

void MethodInvocations_2ae::outputAppender( const cadena_scenario::FRConnection& fRConnection_2d8, const PICML::RequiredRequestPort& requiredRequestPort_2da)
{
	_fRConnection_2b5->push_back( fRConnection_2d8);
	_requiredRequestPort_2b6->push_back( requiredRequestPort_2da);
}

void SourcesToConnectors_2dc::operator()( const Packets_t& eSSConnections_2dd, const Packets_t& publishConnectors_2df)
{
#ifdef PRINT_INFO
	std::cout << "SourcesToConnectors_2dc" << std::endl;
#endif
	processInputPackets( eSSConnections_2dd, publishConnectors_2df);
}

bool SourcesToConnectors_2dc::isInputUnique( const Udm::Object& eSSConnection_2e5, const Udm::Object& publishConnector_2ee)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itESSConnection_2e7= _eSSConnection_2e1.begin(), itPublishConnector_2f0= _publishConnector_2ea.begin(); itESSConnection_2e7!= _eSSConnection_2e1.end(), itPublishConnector_2f0!= _publishConnector_2ea.end(); ++itESSConnection_2e7, ++itPublishConnector_2f0)
	{
		if( ( *itESSConnection_2e7== eSSConnection_2e5)&& ( *itPublishConnector_2f0== publishConnector_2ee))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_eSSConnection_2e1.push_back( eSSConnection_2e5);
		_publishConnector_2ea.push_back( publishConnector_2ee);
	}
	return isUnique;
}

void SourcesToConnectors_2dc::processInputPackets( const Packets_t& eSSConnections_2dd, const Packets_t& publishConnectors_2df)
{
	for( Packets_t::const_iterator itESSConnection_2e2= eSSConnections_2dd.begin(), itPublishConnector_2eb= publishConnectors_2df.begin(); itESSConnection_2e2!= eSSConnections_2dd.end(), itPublishConnector_2eb!= publishConnectors_2df.end(); ++itESSConnection_2e2, ++itPublishConnector_2eb)
	{
		bool isUnique= isInputUnique( *itESSConnection_2e2, *itPublishConnector_2eb);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itESSConnection_2e2, *itPublishConnector_2eb);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool SourcesToConnectors_2dc::patternMatcher( const Udm::Object& eSSConnection_2e3, const Udm::Object& publishConnector_2ec)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( eSSConnection_2e3.type(), cadena_scenario::ESSConnection::meta))
			continue;
		cadena_scenario::ESSConnection eSSConnection_2e8= cadena_scenario::ESSConnection::Cast( eSSConnection_2e3);
		if( false== Uml::IsDerivedFrom( publishConnector_2ec.type(), PICML::PublishConnector::meta))
			continue;
		PICML::PublishConnector publishConnector_2f1= PICML::PublishConnector::Cast( publishConnector_2ec);
		set< PICML::publish> publishs_2f3= publishConnector_2f1.srcpublish();
		for( set< PICML::publish>::const_iterator itpublishs_2f4= publishs_2f3.begin(); itpublishs_2f4!= publishs_2f3.end(); ++itpublishs_2f4)
		{
			PICML::publish currpublish_2f5= *itpublishs_2f4;
			PICML::OutEventPort outEventPort_2f6= currpublish_2f5.srcpublish_end();
			cadena_scenario::ComponentPort eventSource_2f7= outEventPort_2f6.cadenaPort();
			if( false== Uml::IsDerivedFrom( eventSource_2f7.type(), cadena_scenario::EventSource::meta))
				continue;
			cadena_scenario::EventSource eventSource_2f8= cadena_scenario::EventSource::Cast( eventSource_2f7);
			if( !eventSource_2f8)
				continue;
			Match currMatch;
			currMatch.outEventPort_2f9= outEventPort_2f6;
			currMatch.eventSource_2fa= eventSource_2f8;
			currMatch.publish_2fb= currpublish_2f5;
			currMatch.eSSConnection_2fc= eSSConnection_2e8;
			currMatch.publishConnector_2fd= publishConnector_2f1;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void SourcesToConnectors_2dc::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		currMatch.eventSource_2fa.sinksConnections()+= currMatch.eSSConnection_2fc;
		outputAppender( );
	}
}

void SourcesToConnectors_2dc::outputAppender()
{
}

void Creating_ESSConnections_2fe::operator()( const Packets_t& scenarios_2ff, const Packets_t& componentAssemblys_303, Packets_t& eSSConnections_301, Packets_t& publishConnectors_302)
{
#ifdef PRINT_INFO
	std::cout << "Creating_ESSConnections_2fe" << std::endl;
#endif
	_eSSConnection_305= &eSSConnections_301;
	_publishConnector_306= &publishConnectors_302;
	processInputPackets( scenarios_2ff, componentAssemblys_303);
}

bool Creating_ESSConnections_2fe::isInputUnique( const Udm::Object& scenario_30b, const Udm::Object& componentAssembly_314)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_30d= _scenario_307.begin(), itComponentAssembly_316= _componentAssembly_310.begin(); itScenario_30d!= _scenario_307.end(), itComponentAssembly_316!= _componentAssembly_310.end(); ++itScenario_30d, ++itComponentAssembly_316)
	{
		if( ( *itScenario_30d== scenario_30b)&& ( *itComponentAssembly_316== componentAssembly_314))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_307.push_back( scenario_30b);
		_componentAssembly_310.push_back( componentAssembly_314);
	}
	return isUnique;
}

void Creating_ESSConnections_2fe::processInputPackets( const Packets_t& scenarios_2ff, const Packets_t& componentAssemblys_303)
{
	for( Packets_t::const_iterator itScenario_308= scenarios_2ff.begin(), itComponentAssembly_311= componentAssemblys_303.begin(); itScenario_308!= scenarios_2ff.end(), itComponentAssembly_311!= componentAssemblys_303.end(); ++itScenario_308, ++itComponentAssembly_311)
	{
		bool isUnique= isInputUnique( *itScenario_308, *itComponentAssembly_311);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_308, *itComponentAssembly_311);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Creating_ESSConnections_2fe::patternMatcher( const Udm::Object& scenario_309, const Udm::Object& componentAssembly_312)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_309.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_30e= cadena_scenario::Scenario::Cast( scenario_309);
		if( false== Uml::IsDerivedFrom( componentAssembly_312.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_317= PICML::ComponentAssembly::Cast( componentAssembly_312);
		set< PICML::PublishConnector> publishConnectors_319= componentAssembly_317.PublishConnector_kind_children();
		for( set< PICML::PublishConnector>::const_iterator itPublishConnector_31a= publishConnectors_319.begin(); itPublishConnector_31a!= publishConnectors_319.end(); ++itPublishConnector_31a)
		{
			PICML::PublishConnector currPublishConnector_31b= *itPublishConnector_31a;
			Match currMatch;
			currMatch.scenario_31c= scenario_30e;
			currMatch.publishConnector_31d= currPublishConnector_31b;
			currMatch.componentAssembly_31e= componentAssembly_317;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Creating_ESSConnections_2fe::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::ESSConnection newESSConnection_31f= cadena_scenario::ESSConnection::Create( currMatch.scenario_31c);
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_31e;
		Udm::Object& ESSConnection= newESSConnection_31f;
		Udm::Object& PublishConnector= currMatch.publishConnector_31d;
		Udm::Object& Scenario= currMatch.scenario_31c;
		{ /*char uid[11]; sprintf(uid, "%u", PublishConnector.uniqueId()); ESSConnection.SetStrValue("ConnectorID", uid);*/   /* set<Uml::Attribute> attrs = PublishConnector.type().attributes(); set<Uml::Attribute> aattrs=Uml::AncestorAttributes(PublishConnector.type()); attrs.insert(aattrs.begin(),aattrs.end());  string str = "    "; for(set<Uml::Attribute>::iterator ai = attrs.begin(); ai != attrs.end(); ai++)  {   str += ai->name();   str += " - ";   str += ai->type();   str += " - ";   string val;    PublishConnector.GetStrValue(ai->name(), val);   str += val;   str += "; "; } ESSConnection.SetStrValue("ConnectorID", str); */};
		currMatch.publishConnector_31d.cadenaESSConnection()= newESSConnection_31f;
		outputAppender( newESSConnection_31f, currMatch.publishConnector_31d);
	}
}

void Creating_ESSConnections_2fe::outputAppender( const cadena_scenario::ESSConnection& eSSConnection_320, const PICML::PublishConnector& publishConnector_322)
{
	_eSSConnection_305->push_back( eSSConnection_320);
	_publishConnector_306->push_back( publishConnector_322);
}

void PICMLPort_Finder_324::operator()( const Packets_t& scenarios_325, const Packets_t& componentAssemblys_329, Packets_t& scenarios_327, Packets_t& ports_328)
{
#ifdef PRINT_INFO
	std::cout << "PICMLPort_Finder_324" << std::endl;
#endif
	_scenario_32b= &scenarios_327;
	_port_32c= &ports_328;
	processInputPackets( scenarios_325, componentAssemblys_329);
}

bool PICMLPort_Finder_324::isInputUnique( const Udm::Object& scenario_331, const Udm::Object& componentAssembly_33a)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_333= _scenario_32d.begin(), itComponentAssembly_33c= _componentAssembly_336.begin(); itScenario_333!= _scenario_32d.end(), itComponentAssembly_33c!= _componentAssembly_336.end(); ++itScenario_333, ++itComponentAssembly_33c)
	{
		if( ( *itScenario_333== scenario_331)&& ( *itComponentAssembly_33c== componentAssembly_33a))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_32d.push_back( scenario_331);
		_componentAssembly_336.push_back( componentAssembly_33a);
	}
	return isUnique;
}

void PICMLPort_Finder_324::processInputPackets( const Packets_t& scenarios_325, const Packets_t& componentAssemblys_329)
{
	for( Packets_t::const_iterator itScenario_32e= scenarios_325.begin(), itComponentAssembly_337= componentAssemblys_329.begin(); itScenario_32e!= scenarios_325.end(), itComponentAssembly_337!= componentAssemblys_329.end(); ++itScenario_32e, ++itComponentAssembly_337)
	{
		bool isUnique= isInputUnique( *itScenario_32e, *itComponentAssembly_337);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_32e, *itComponentAssembly_337);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool PICMLPort_Finder_324::patternMatcher( const Udm::Object& scenario_32f, const Udm::Object& componentAssembly_338)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_32f.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_334= cadena_scenario::Scenario::Cast( scenario_32f);
		if( false== Uml::IsDerivedFrom( componentAssembly_338.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_33d= PICML::ComponentAssembly::Cast( componentAssembly_338);
		set< PICML::Component> components_33f= componentAssembly_33d.Component_kind_children();
		for( set< PICML::Component>::const_iterator itComponent_340= components_33f.begin(); itComponent_340!= components_33f.end(); ++itComponent_340)
		{
			PICML::Component currComponent_341= *itComponent_340;
			set< PICML::Port> ports_342= currComponent_341.Port_kind_children();
			for( set< PICML::Port>::const_iterator itPort_343= ports_342.begin(); itPort_343!= ports_342.end(); ++itPort_343)
			{
				PICML::Port currPort_344= *itPort_343;
				Match currMatch;
				currMatch.scenario_345= scenario_334;
				currMatch.port_346= currPort_344;
				currMatch.component_347= currComponent_341;
				currMatch.componentAssembly_348= componentAssembly_33d;
				_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void PICMLPort_Finder_324::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.scenario_345, currMatch.port_346);
	}
}

void PICMLPort_Finder_324::outputAppender( const cadena_scenario::Scenario& scenario_349, const PICML::Port& port_34b)
{
	_scenario_32b->push_back( scenario_349);
	_port_32c->push_back( port_34b);
}

void Emits_34d::operator()( const Packets_t& scenarios_34f, const Packets_t& outEventPorts_351, Packets_t& eSSConnections_34e, Packets_t& outEventPorts_353)
{
#ifdef PRINT_INFO
	std::cout << "Emits_34d" << std::endl;
#endif
	_eSSConnection_354= &eSSConnections_34e;
	_outEventPort_355= &outEventPorts_353;
	processInputPackets( scenarios_34f, outEventPorts_351);
}

bool Emits_34d::isInputUnique( const Udm::Object& scenario_35a, const Udm::Object& outEventPort_363)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itScenario_35c= _scenario_356.begin(), itOutEventPort_365= _outEventPort_35f.begin(); itScenario_35c!= _scenario_356.end(), itOutEventPort_365!= _outEventPort_35f.end(); ++itScenario_35c, ++itOutEventPort_365)
	{
		if( ( *itScenario_35c== scenario_35a)&& ( *itOutEventPort_365== outEventPort_363))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_scenario_356.push_back( scenario_35a);
		_outEventPort_35f.push_back( outEventPort_363);
	}
	return isUnique;
}

void Emits_34d::processInputPackets( const Packets_t& scenarios_34f, const Packets_t& outEventPorts_351)
{
	for( Packets_t::const_iterator itScenario_357= scenarios_34f.begin(), itOutEventPort_360= outEventPorts_351.begin(); itScenario_357!= scenarios_34f.end(), itOutEventPort_360!= outEventPorts_351.end(); ++itScenario_357, ++itOutEventPort_360)
	{
		bool isUnique= isInputUnique( *itScenario_357, *itOutEventPort_360);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itScenario_357, *itOutEventPort_360);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Emits_34d::patternMatcher( const Udm::Object& scenario_358, const Udm::Object& outEventPort_361)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( scenario_358.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_35d= cadena_scenario::Scenario::Cast( scenario_358);
		if( false== Uml::IsDerivedFrom( outEventPort_361.type(), PICML::OutEventPort::meta))
			continue;
		PICML::OutEventPort outEventPort_366= PICML::OutEventPort::Cast( outEventPort_361);
		cadena_scenario::ComponentPort eventSource_368= outEventPort_366.cadenaPort();
		if( false== Uml::IsDerivedFrom( eventSource_368.type(), cadena_scenario::EventSource::meta))
			continue;
		cadena_scenario::EventSource eventSource_369= cadena_scenario::EventSource::Cast( eventSource_368);
		if( !eventSource_369)
			continue;
		PICML::emit emit_36a= outEventPort_366.dstemit();
		if( !emit_36a)
			continue;
		PICML::InEventPort inEventPort_36b= emit_36a.dstemit_end();
		cadena_scenario::ComponentPort eventSink_36c= inEventPort_36b.cadenaPort();
		if( false== Uml::IsDerivedFrom( eventSink_36c.type(), cadena_scenario::EventSink::meta))
			continue;
		cadena_scenario::EventSink eventSink_36d= cadena_scenario::EventSink::Cast( eventSink_36c);
		if( !eventSink_36d)
			continue;
		Match currMatch;
		currMatch.eventSink_36e= eventSink_36d;
		currMatch.emit_36f= emit_36a;
		currMatch.eventSource_370= eventSource_369;
		currMatch.inEventPort_371= inEventPort_36b;
		currMatch.scenario_372= scenario_35d;
		currMatch.outEventPort_373= outEventPort_366;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void Emits_34d::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::ESSConnection newESSConnection_374= cadena_scenario::ESSConnection::Create( currMatch.scenario_372);
		Udm::Object& ESSConnection= newESSConnection_374;
		Udm::Object& EventSink= currMatch.eventSink_36e;
		Udm::Object& EventSource= currMatch.eventSource_370;
		Udm::Object& InEventPort= currMatch.inEventPort_371;
		Udm::Object& OutEventPort= currMatch.outEventPort_373;
		Udm::Object& Scenario= currMatch.scenario_372;
		Udm::Object& emit= currMatch.emit_36f;
		{ESSConnection.SetStrValue("ConnectorID","emit");};
		currMatch.emit_36f.cadenaEmit()+= newESSConnection_374;
		newESSConnection_374.sinks()+= currMatch.eventSink_36e;
		currMatch.eventSource_370.sinksConnections()+= newESSConnection_374;
		outputAppender( newESSConnection_374, currMatch.outEventPort_373);
	}
}

void Emits_34d::outputAppender( const cadena_scenario::ESSConnection& eSSConnection_375, const PICML::OutEventPort& outEventPort_377)
{
	_eSSConnection_354->push_back( eSSConnection_375);
	_outEventPort_355->push_back( outEventPort_377);
}

void ComponentAndPortCreation_391::operator()( const Packets_t& assemblys_392, const Packets_t& scenarios_394, Packets_t& cComponentInstances_396, Packets_t& pComponentDefs_397, Packets_t& scenarios_398, Packets_t& assemblys_399)
{
#ifdef PRINT_INFO
	std::cout << "ComponentAndPortCreation_391" << std::endl;
#endif
	_cComponentInstance_39a= &cComponentInstances_396;
	_pComponentDef_39b= &pComponentDefs_397;
	_scenario_39c= &scenarios_398;
	_assembly_39d= &assemblys_399;
	_assembly_39d->insert( _assembly_39d->end(), assemblys_392.begin(), assemblys_392.end());
	_scenario_39c->insert( _scenario_39c->end(), scenarios_394.begin(), scenarios_394.end());
	if( ( !assemblys_392.empty())&& ( !scenarios_394.empty()))
		callComponentCreation_489( assemblys_392, scenarios_394);
}

void ComponentAndPortCreation_391::callComponentCreation_489( const Packets_t& componentAssemblys_39f, const Packets_t& scenarios_3a3)
{
	Packets_t components_3a1;
	Packets_t componentInstances_3a2;
	ComponentCreation_39e componentCreation_39e;
	componentCreation_39e( componentAssemblys_39f, scenarios_3a3, components_3a1, componentInstances_3a2);
	_pComponentDef_39b->insert( _pComponentDef_39b->end(), components_3a1.begin(), components_3a1.end());
	_cComponentInstance_39a->insert( _cComponentInstance_39a->end(), componentInstances_3a2.begin(), componentInstances_3a2.end());
	if( ( !components_3a1.empty())&& ( !componentInstances_3a2.empty()))
		callPortsCreation_48c( components_3a1, componentInstances_3a2);
}

void ComponentAndPortCreation_391::callPortsCreation_48c( const Packets_t& pICML_Components_3c5, const Packets_t& cadena_Components_3c7)
{
	PortsCreation_3c4 portsCreation_3c4;
	portsCreation_3c4( pICML_Components_3c5, cadena_Components_3c7);
}

void ComponentCreation_39e::operator()( const Packets_t& componentAssemblys_39f, const Packets_t& scenarios_3a3, Packets_t& components_3a1, Packets_t& componentInstances_3a2)
{
#ifdef PRINT_INFO
	std::cout << "ComponentCreation_39e" << std::endl;
#endif
	_component_3a5= &components_3a1;
	_componentInstance_3a6= &componentInstances_3a2;
	processInputPackets( componentAssemblys_39f, scenarios_3a3);
}

bool ComponentCreation_39e::isInputUnique( const Udm::Object& componentAssembly_3ab, const Udm::Object& scenario_3b4)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_3ad= _componentAssembly_3a7.begin(), itScenario_3b6= _scenario_3b0.begin(); itComponentAssembly_3ad!= _componentAssembly_3a7.end(), itScenario_3b6!= _scenario_3b0.end(); ++itComponentAssembly_3ad, ++itScenario_3b6)
	{
		if( ( *itComponentAssembly_3ad== componentAssembly_3ab)&& ( *itScenario_3b6== scenario_3b4))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentAssembly_3a7.push_back( componentAssembly_3ab);
		_scenario_3b0.push_back( scenario_3b4);
	}
	return isUnique;
}

void ComponentCreation_39e::processInputPackets( const Packets_t& componentAssemblys_39f, const Packets_t& scenarios_3a3)
{
	for( Packets_t::const_iterator itComponentAssembly_3a8= componentAssemblys_39f.begin(), itScenario_3b1= scenarios_3a3.begin(); itComponentAssembly_3a8!= componentAssemblys_39f.end(), itScenario_3b1!= scenarios_3a3.end(); ++itComponentAssembly_3a8, ++itScenario_3b1)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_3a8, *itScenario_3b1);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_3a8, *itScenario_3b1);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool ComponentCreation_39e::patternMatcher( const Udm::Object& componentAssembly_3a9, const Udm::Object& scenario_3b2)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_3a9.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_3ae= PICML::ComponentAssembly::Cast( componentAssembly_3a9);
		if( false== Uml::IsDerivedFrom( scenario_3b2.type(), cadena_scenario::Scenario::meta))
			continue;
		cadena_scenario::Scenario scenario_3b7= cadena_scenario::Scenario::Cast( scenario_3b2);
		set< PICML::Component> components_3b9= componentAssembly_3ae.Component_kind_children();
		for( set< PICML::Component>::const_iterator itComponent_3ba= components_3b9.begin(); itComponent_3ba!= components_3b9.end(); ++itComponent_3ba)
		{
			PICML::Component currComponent_3bb= *itComponent_3ba;
			Match currMatch;
			currMatch.componentAssembly_3bc= componentAssembly_3ae;
			currMatch.component_3bd= currComponent_3bb;
			currMatch.scenario_3be= scenario_3b7;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void ComponentCreation_39e::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::ComponentInstance newComponentInstance_3bf= cadena_scenario::ComponentInstance::Create( currMatch.scenario_3be);
		Udm::Object& Component= currMatch.component_3bd;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_3bc;
		Udm::Object& ComponentInstance= newComponentInstance_3bf;
		Udm::Object& Scenario= currMatch.scenario_3be;
		{string s; Component.GetStrValue("name",s); ComponentInstance.SetStrValue("name",s);  Component.archetype().GetStrValue("name",s); ComponentInstance.SetStrValue("type",s);};
		currMatch.component_3bd.cadenaComponentInstance()= newComponentInstance_3bf;
		outputAppender( currMatch.component_3bd, newComponentInstance_3bf);
	}
}

void ComponentCreation_39e::outputAppender( const PICML::Component& component_3c0, const cadena_scenario::ComponentInstance& componentInstance_3c2)
{
	_component_3a5->push_back( component_3c0);
	_componentInstance_3a6->push_back( componentInstance_3c2);
}

void PortsCreation_3c4::operator()( const Packets_t& pICML_Components_3c5, const Packets_t& cadena_Components_3c7)
{
#ifdef PRINT_INFO
	std::cout << "PortsCreation_3c4" << std::endl;
#endif
	if( ( !pICML_Components_3c5.empty())&& ( !cadena_Components_3c7.empty()))
		callFacets_47a( pICML_Components_3c5, cadena_Components_3c7);
	if( ( !pICML_Components_3c5.empty())&& ( !cadena_Components_3c7.empty()))
		callReceptacles_47d( pICML_Components_3c5, cadena_Components_3c7);
	if( ( !pICML_Components_3c5.empty())&& ( !cadena_Components_3c7.empty()))
		callEventSinks_480( pICML_Components_3c5, cadena_Components_3c7);
	if( ( !cadena_Components_3c7.empty())&& ( !pICML_Components_3c5.empty()))
		callEventSources_483( cadena_Components_3c7, pICML_Components_3c5);
}

void PortsCreation_3c4::callFacets_47a( const Packets_t& components_40b, const Packets_t& componentInstances_40d)
{
	Packets_t facets_409;
	Packets_t providedRequestPorts_40a;
	Facets_408 facets_408;
	facets_408( components_40b, componentInstances_40d, facets_409, providedRequestPorts_40a);
	if( ( !facets_409.empty())&& ( !providedRequestPorts_40a.empty()))
		callAssignNames_486( facets_409, providedRequestPorts_40a);
}

void PortsCreation_3c4::callReceptacles_47d( const Packets_t& components_3cc, const Packets_t& componentInstances_3ce)
{
	Packets_t receptacles_3ca;
	Packets_t requiredRequestPorts_3cb;
	Receptacles_3c9 receptacles_3c9;
	receptacles_3c9( components_3cc, componentInstances_3ce, receptacles_3ca, requiredRequestPorts_3cb);
	if( ( !receptacles_3ca.empty())&& ( !requiredRequestPorts_3cb.empty()))
		callAssignNames_486( receptacles_3ca, requiredRequestPorts_3cb);
}

void PortsCreation_3c4::callEventSinks_480( const Packets_t& components_431, const Packets_t& componentInstances_433)
{
	Packets_t eventSinks_42f;
	Packets_t inEventPorts_430;
	EventSinks_42e eventSinks_42e;
	eventSinks_42e( components_431, componentInstances_433, eventSinks_42f, inEventPorts_430);
	if( ( !eventSinks_42f.empty())&& ( !inEventPorts_430.empty()))
		callAssignNames_486( eventSinks_42f, inEventPorts_430);
}

void PortsCreation_3c4::callEventSources_483( const Packets_t& componentInstances_457, const Packets_t& components_459)
{
	Packets_t eventSources_455;
	Packets_t outEventPorts_456;
	EventSources_454 eventSources_454;
	eventSources_454( componentInstances_457, components_459, eventSources_455, outEventPorts_456);
	if( ( !eventSources_455.empty())&& ( !outEventPorts_456.empty()))
		callAssignNames_486( eventSources_455, outEventPorts_456);
}

void PortsCreation_3c4::callAssignNames_486( const Packets_t& componentPorts_3f0, const Packets_t& ports_3f2)
{
	AssignNames_3ef assignNames_3ef;
	assignNames_3ef( componentPorts_3f0, ports_3f2);
}

void Receptacles_3c9::operator()( const Packets_t& components_3cc, const Packets_t& componentInstances_3ce, Packets_t& receptacles_3ca, Packets_t& requiredRequestPorts_3cb)
{
#ifdef PRINT_INFO
	std::cout << "Receptacles_3c9" << std::endl;
#endif
	_receptacle_3d0= &receptacles_3ca;
	_requiredRequestPort_3d1= &requiredRequestPorts_3cb;
	processInputPackets( components_3cc, componentInstances_3ce);
}

bool Receptacles_3c9::isInputUnique( const Udm::Object& component_3d6, const Udm::Object& componentInstance_3df)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponent_3d8= _component_3d2.begin(), itComponentInstance_3e1= _componentInstance_3db.begin(); itComponent_3d8!= _component_3d2.end(), itComponentInstance_3e1!= _componentInstance_3db.end(); ++itComponent_3d8, ++itComponentInstance_3e1)
	{
		if( ( *itComponent_3d8== component_3d6)&& ( *itComponentInstance_3e1== componentInstance_3df))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_component_3d2.push_back( component_3d6);
		_componentInstance_3db.push_back( componentInstance_3df);
	}
	return isUnique;
}

void Receptacles_3c9::processInputPackets( const Packets_t& components_3cc, const Packets_t& componentInstances_3ce)
{
	for( Packets_t::const_iterator itComponent_3d3= components_3cc.begin(), itComponentInstance_3dc= componentInstances_3ce.begin(); itComponent_3d3!= components_3cc.end(), itComponentInstance_3dc!= componentInstances_3ce.end(); ++itComponent_3d3, ++itComponentInstance_3dc)
	{
		bool isUnique= isInputUnique( *itComponent_3d3, *itComponentInstance_3dc);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponent_3d3, *itComponentInstance_3dc);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Receptacles_3c9::patternMatcher( const Udm::Object& component_3d4, const Udm::Object& componentInstance_3dd)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( component_3d4.type(), PICML::Component::meta))
			continue;
		PICML::Component component_3d9= PICML::Component::Cast( component_3d4);
		if( false== Uml::IsDerivedFrom( componentInstance_3dd.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_3e2= cadena_scenario::ComponentInstance::Cast( componentInstance_3dd);
		set< PICML::RequiredRequestPort> requiredRequestPorts_3e4= component_3d9.RequiredRequestPort_kind_children();
		for( set< PICML::RequiredRequestPort>::const_iterator itRequiredRequestPort_3e5= requiredRequestPorts_3e4.begin(); itRequiredRequestPort_3e5!= requiredRequestPorts_3e4.end(); ++itRequiredRequestPort_3e5)
		{
			PICML::RequiredRequestPort currRequiredRequestPort_3e6= *itRequiredRequestPort_3e5;
			Match currMatch;
			currMatch.requiredRequestPort_3e7= currRequiredRequestPort_3e6;
			currMatch.component_3e8= component_3d9;
			currMatch.componentInstance_3e9= componentInstance_3e2;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Receptacles_3c9::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::Receptacle newReceptacle_3ea= cadena_scenario::Receptacle::Create( currMatch.componentInstance_3e9);
		currMatch.requiredRequestPort_3e7.cadenaPort()= newReceptacle_3ea;
		outputAppender( newReceptacle_3ea, currMatch.requiredRequestPort_3e7);
	}
}

void Receptacles_3c9::outputAppender( const cadena_scenario::Receptacle& receptacle_3eb, const PICML::RequiredRequestPort& requiredRequestPort_3ed)
{
	_receptacle_3d0->push_back( receptacle_3eb);
	_requiredRequestPort_3d1->push_back( requiredRequestPort_3ed);
}

void AssignNames_3ef::operator()( const Packets_t& componentPorts_3f0, const Packets_t& ports_3f2)
{
#ifdef PRINT_INFO
	std::cout << "AssignNames_3ef" << std::endl;
#endif
	processInputPackets( componentPorts_3f0, ports_3f2);
}

bool AssignNames_3ef::isInputUnique( const Udm::Object& componentPort_3f8, const Udm::Object& port_401)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentPort_3fa= _componentPort_3f4.begin(), itPort_403= _port_3fd.begin(); itComponentPort_3fa!= _componentPort_3f4.end(), itPort_403!= _port_3fd.end(); ++itComponentPort_3fa, ++itPort_403)
	{
		if( ( *itComponentPort_3fa== componentPort_3f8)&& ( *itPort_403== port_401))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentPort_3f4.push_back( componentPort_3f8);
		_port_3fd.push_back( port_401);
	}
	return isUnique;
}

void AssignNames_3ef::processInputPackets( const Packets_t& componentPorts_3f0, const Packets_t& ports_3f2)
{
	for( Packets_t::const_iterator itComponentPort_3f5= componentPorts_3f0.begin(), itPort_3fe= ports_3f2.begin(); itComponentPort_3f5!= componentPorts_3f0.end(), itPort_3fe!= ports_3f2.end(); ++itComponentPort_3f5, ++itPort_3fe)
	{
		bool isUnique= isInputUnique( *itComponentPort_3f5, *itPort_3fe);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentPort_3f5, *itPort_3fe);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool AssignNames_3ef::patternMatcher( const Udm::Object& componentPort_3f6, const Udm::Object& port_3ff)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentPort_3f6.type(), cadena_scenario::ComponentPort::meta))
			continue;
		cadena_scenario::ComponentPort componentPort_3fb= cadena_scenario::ComponentPort::Cast( componentPort_3f6);
		if( false== Uml::IsDerivedFrom( port_3ff.type(), PICML::Port::meta))
			continue;
		PICML::Port port_404= PICML::Port::Cast( port_3ff);
		Match currMatch;
		currMatch.componentPort_406= componentPort_3fb;
		currMatch.port_407= port_404;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void AssignNames_3ef::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& ComponentPort= currMatch.componentPort_406;
		Udm::Object& Port= currMatch.port_407;
		{string s; Port.GetStrValue("name",s); ComponentPort.SetStrValue("name",s);};
		outputAppender( );
	}
}

void AssignNames_3ef::outputAppender()
{
}

void Facets_408::operator()( const Packets_t& components_40b, const Packets_t& componentInstances_40d, Packets_t& facets_409, Packets_t& providedRequestPorts_40a)
{
#ifdef PRINT_INFO
	std::cout << "Facets_408" << std::endl;
#endif
	_facet_40f= &facets_409;
	_providedRequestPort_410= &providedRequestPorts_40a;
	processInputPackets( components_40b, componentInstances_40d);
}

bool Facets_408::isInputUnique( const Udm::Object& component_415, const Udm::Object& componentInstance_41e)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponent_417= _component_411.begin(), itComponentInstance_420= _componentInstance_41a.begin(); itComponent_417!= _component_411.end(), itComponentInstance_420!= _componentInstance_41a.end(); ++itComponent_417, ++itComponentInstance_420)
	{
		if( ( *itComponent_417== component_415)&& ( *itComponentInstance_420== componentInstance_41e))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_component_411.push_back( component_415);
		_componentInstance_41a.push_back( componentInstance_41e);
	}
	return isUnique;
}

void Facets_408::processInputPackets( const Packets_t& components_40b, const Packets_t& componentInstances_40d)
{
	for( Packets_t::const_iterator itComponent_412= components_40b.begin(), itComponentInstance_41b= componentInstances_40d.begin(); itComponent_412!= components_40b.end(), itComponentInstance_41b!= componentInstances_40d.end(); ++itComponent_412, ++itComponentInstance_41b)
	{
		bool isUnique= isInputUnique( *itComponent_412, *itComponentInstance_41b);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponent_412, *itComponentInstance_41b);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Facets_408::patternMatcher( const Udm::Object& component_413, const Udm::Object& componentInstance_41c)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( component_413.type(), PICML::Component::meta))
			continue;
		PICML::Component component_418= PICML::Component::Cast( component_413);
		if( false== Uml::IsDerivedFrom( componentInstance_41c.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_421= cadena_scenario::ComponentInstance::Cast( componentInstance_41c);
		set< PICML::ProvidedRequestPort> providedRequestPorts_423= component_418.ProvidedRequestPort_kind_children();
		for( set< PICML::ProvidedRequestPort>::const_iterator itProvidedRequestPort_424= providedRequestPorts_423.begin(); itProvidedRequestPort_424!= providedRequestPorts_423.end(); ++itProvidedRequestPort_424)
		{
			PICML::ProvidedRequestPort currProvidedRequestPort_425= *itProvidedRequestPort_424;
			Match currMatch;
			currMatch.providedRequestPort_426= currProvidedRequestPort_425;
			currMatch.component_427= component_418;
			currMatch.componentInstance_428= componentInstance_421;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Facets_408::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::Facet newFacet_429= cadena_scenario::Facet::Create( currMatch.componentInstance_428);
		currMatch.providedRequestPort_426.cadenaPort()= newFacet_429;
		outputAppender( newFacet_429, currMatch.providedRequestPort_426);
	}
}

void Facets_408::outputAppender( const cadena_scenario::Facet& facet_42a, const PICML::ProvidedRequestPort& providedRequestPort_42c)
{
	_facet_40f->push_back( facet_42a);
	_providedRequestPort_410->push_back( providedRequestPort_42c);
}

void EventSinks_42e::operator()( const Packets_t& components_431, const Packets_t& componentInstances_433, Packets_t& eventSinks_42f, Packets_t& inEventPorts_430)
{
#ifdef PRINT_INFO
	std::cout << "EventSinks_42e" << std::endl;
#endif
	_eventSink_435= &eventSinks_42f;
	_inEventPort_436= &inEventPorts_430;
	processInputPackets( components_431, componentInstances_433);
}

bool EventSinks_42e::isInputUnique( const Udm::Object& component_43b, const Udm::Object& componentInstance_444)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponent_43d= _component_437.begin(), itComponentInstance_446= _componentInstance_440.begin(); itComponent_43d!= _component_437.end(), itComponentInstance_446!= _componentInstance_440.end(); ++itComponent_43d, ++itComponentInstance_446)
	{
		if( ( *itComponent_43d== component_43b)&& ( *itComponentInstance_446== componentInstance_444))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_component_437.push_back( component_43b);
		_componentInstance_440.push_back( componentInstance_444);
	}
	return isUnique;
}

void EventSinks_42e::processInputPackets( const Packets_t& components_431, const Packets_t& componentInstances_433)
{
	for( Packets_t::const_iterator itComponent_438= components_431.begin(), itComponentInstance_441= componentInstances_433.begin(); itComponent_438!= components_431.end(), itComponentInstance_441!= componentInstances_433.end(); ++itComponent_438, ++itComponentInstance_441)
	{
		bool isUnique= isInputUnique( *itComponent_438, *itComponentInstance_441);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponent_438, *itComponentInstance_441);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool EventSinks_42e::patternMatcher( const Udm::Object& component_439, const Udm::Object& componentInstance_442)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( component_439.type(), PICML::Component::meta))
			continue;
		PICML::Component component_43e= PICML::Component::Cast( component_439);
		if( false== Uml::IsDerivedFrom( componentInstance_442.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_447= cadena_scenario::ComponentInstance::Cast( componentInstance_442);
		set< PICML::InEventPort> inEventPorts_449= component_43e.InEventPort_kind_children();
		for( set< PICML::InEventPort>::const_iterator itInEventPort_44a= inEventPorts_449.begin(); itInEventPort_44a!= inEventPorts_449.end(); ++itInEventPort_44a)
		{
			PICML::InEventPort currInEventPort_44b= *itInEventPort_44a;
			Match currMatch;
			currMatch.inEventPort_44c= currInEventPort_44b;
			currMatch.component_44d= component_43e;
			currMatch.componentInstance_44e= componentInstance_447;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void EventSinks_42e::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::EventSink newEventSink_44f= cadena_scenario::EventSink::Create( currMatch.componentInstance_44e);
		currMatch.inEventPort_44c.cadenaPort()= newEventSink_44f;
		outputAppender( newEventSink_44f, currMatch.inEventPort_44c);
	}
}

void EventSinks_42e::outputAppender( const cadena_scenario::EventSink& eventSink_450, const PICML::InEventPort& inEventPort_452)
{
	_eventSink_435->push_back( eventSink_450);
	_inEventPort_436->push_back( inEventPort_452);
}

void EventSources_454::operator()( const Packets_t& componentInstances_457, const Packets_t& components_459, Packets_t& eventSources_455, Packets_t& outEventPorts_456)
{
#ifdef PRINT_INFO
	std::cout << "EventSources_454" << std::endl;
#endif
	_eventSource_45b= &eventSources_455;
	_outEventPort_45c= &outEventPorts_456;
	processInputPackets( componentInstances_457, components_459);
}

bool EventSources_454::isInputUnique( const Udm::Object& componentInstance_461, const Udm::Object& component_46a)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentInstance_463= _componentInstance_45d.begin(), itComponent_46c= _component_466.begin(); itComponentInstance_463!= _componentInstance_45d.end(), itComponent_46c!= _component_466.end(); ++itComponentInstance_463, ++itComponent_46c)
	{
		if( ( *itComponentInstance_463== componentInstance_461)&& ( *itComponent_46c== component_46a))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_componentInstance_45d.push_back( componentInstance_461);
		_component_466.push_back( component_46a);
	}
	return isUnique;
}

void EventSources_454::processInputPackets( const Packets_t& componentInstances_457, const Packets_t& components_459)
{
	for( Packets_t::const_iterator itComponentInstance_45e= componentInstances_457.begin(), itComponent_467= components_459.begin(); itComponentInstance_45e!= componentInstances_457.end(), itComponent_467!= components_459.end(); ++itComponentInstance_45e, ++itComponent_467)
	{
		bool isUnique= isInputUnique( *itComponentInstance_45e, *itComponent_467);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentInstance_45e, *itComponent_467);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool EventSources_454::patternMatcher( const Udm::Object& componentInstance_45f, const Udm::Object& component_468)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentInstance_45f.type(), cadena_scenario::ComponentInstance::meta))
			continue;
		cadena_scenario::ComponentInstance componentInstance_464= cadena_scenario::ComponentInstance::Cast( componentInstance_45f);
		if( false== Uml::IsDerivedFrom( component_468.type(), PICML::Component::meta))
			continue;
		PICML::Component component_46d= PICML::Component::Cast( component_468);
		set< PICML::OutEventPort> outEventPorts_46f= component_46d.OutEventPort_kind_children();
		for( set< PICML::OutEventPort>::const_iterator itOutEventPort_470= outEventPorts_46f.begin(); itOutEventPort_470!= outEventPorts_46f.end(); ++itOutEventPort_470)
		{
			PICML::OutEventPort currOutEventPort_471= *itOutEventPort_470;
			Match currMatch;
			currMatch.outEventPort_472= currOutEventPort_471;
			currMatch.componentInstance_473= componentInstance_464;
			currMatch.component_474= component_46d;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void EventSources_454::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::EventSource newEventSource_475= cadena_scenario::EventSource::Create( currMatch.componentInstance_473);
		currMatch.outEventPort_472.cadenaPort()= newEventSource_475;
		outputAppender( newEventSource_475, currMatch.outEventPort_472);
	}
}

void EventSources_454::outputAppender( const cadena_scenario::EventSource& eventSource_476, const PICML::OutEventPort& outEventPort_478)
{
	_eventSource_45b->push_back( eventSource_476);
	_outEventPort_45c->push_back( outEventPort_478);
}

void Transfering_Emit_and_Invoke_Properties_48f::operator()( const Packets_t& pAssemblys_490)
{
#ifdef PRINT_INFO
	std::cout << "Transfering_Emit_and_Invoke_Properties_48f" << std::endl;
#endif
	if( ( !pAssemblys_490.empty()))
		callMatch_EIProperties_5cc( pAssemblys_490);
}

void Transfering_Emit_and_Invoke_Properties_48f::callMatch_EIProperties_5cc( const Packets_t& componentAssemblys_5af)
{
	Packets_t propertys_5ae;
	Match_EIProperties_5ad match_EIProperties_5ad;
	match_EIProperties_5ad( componentAssemblys_5af, propertys_5ae);
	if( ( !propertys_5ae.empty()))
		callForBlock_5ce( propertys_5ae);
}

void Transfering_Emit_and_Invoke_Properties_48f::callForBlock_5ce( const Packets_t& pPropertys_493)
{
	ForBlock_492 forBlock_492;
	forBlock_492( pPropertys_493);
}

void ForBlock_492::operator()( const Packets_t& pPropertys_493)
{
#ifdef PRINT_INFO
	std::cout << "ForBlock_492" << std::endl;
#endif
	for( Packets_t::const_iterator itPProperty_496= pPropertys_493.begin(); itPProperty_496!= pPropertys_493.end(); ++itPProperty_496)
	{
		bool isUnique= isInputUnique( *itPProperty_496);
		if( !isUnique)
			continue;
		Packets_t onePProperty_49a( 1, *itPProperty_496);
		executeOne( onePProperty_49a);
	}
}

void ForBlock_492::executeOne( const Packets_t& pPropertys_493)
{
	if( ( !pPropertys_493.empty()))
		callOpen_EIConnectionProperties_DataNetwork_59d( pPropertys_493);
}

bool ForBlock_492::isInputUnique( const Udm::Object& pProperty_497)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPProperty_499= _pProperty_495.begin(); itPProperty_499!= _pProperty_495.end(); ++itPProperty_499)
	{
		if( ( *itPProperty_499== pProperty_497))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_pProperty_495.push_back( pProperty_497);
	return isUnique;
}

void ForBlock_492::callOpen_EIConnectionProperties_DataNetwork_59d( const Packets_t& propertys_57f)
{
	Packets_t rootContainers_57e;
	Packets_t components_581;
	Open_EIConnectionProperties_DataNetwork_57d open_EIConnectionProperties_DataNetwork_57d;
	open_EIConnectionProperties_DataNetwork_57d( propertys_57f, rootContainers_57e, components_581);
	if( ( !components_581.empty())&& ( !rootContainers_57e.empty()))
		callGetPorts_59f( components_581, rootContainers_57e);
}

void ForBlock_492::callGetPorts_59f( const Packets_t& components_49d, const Packets_t& rootContainers_49f)
{
	Packets_t rootContainers_4a1;
	Packets_t ports_4a2;
	GetPorts_49c getPorts_49c;
	getPorts_49c( components_49d, rootContainers_49f, rootContainers_4a1, ports_4a2);
	if( ( !rootContainers_4a1.empty())&& ( !ports_4a2.empty()))
		callMatchCorrectEmitConnection_5a2( rootContainers_4a1, ports_4a2);
	if( ( !rootContainers_4a1.empty())&& ( !ports_4a2.empty()))
		callMatchCorrectInvokeConnection_5a5( rootContainers_4a1, ports_4a2);
}

void ForBlock_492::callMatchCorrectEmitConnection_5a2( const Packets_t& rootContainers_548, const Packets_t& outEventPorts_54a)
{
	Packets_t connectionSelectors_547;
	Packets_t eSSConnections_54c;
	MatchCorrectEmitConnection_546 matchCorrectEmitConnection_546;
	matchCorrectEmitConnection_546( rootContainers_548, outEventPorts_54a, connectionSelectors_547, eSSConnections_54c);
	if( ( !eSSConnections_54c.empty())&& ( !connectionSelectors_547.empty()))
		callTransferEIProperties_5a8( eSSConnections_54c, connectionSelectors_547);
}

void ForBlock_492::callMatchCorrectInvokeConnection_5a5( const Packets_t& rootContainers_4c3, const Packets_t& requiredRequestPorts_4c6)
{
	Packets_t connectionSelectors_4c2;
	Packets_t fRConnections_4c5;
	MatchCorrectInvokeConnection_4c1 matchCorrectInvokeConnection_4c1;
	matchCorrectInvokeConnection_4c1( rootContainers_4c3, requiredRequestPorts_4c6, connectionSelectors_4c2, fRConnections_4c5);
	if( ( !fRConnections_4c5.empty())&& ( !connectionSelectors_4c2.empty()))
		callTransferEIProperties_5a8( fRConnections_4c5, connectionSelectors_4c2);
}

void ForBlock_492::callTransferEIProperties_5a8( const Packets_t& portConnections_4f9, const Packets_t& connectionSelectors_4fb)
{
	Packets_t connectionSelectors_4fd;
	TransferEIProperties_4f8 transferEIProperties_4f8;
	transferEIProperties_4f8( portConnections_4f9, connectionSelectors_4fb, connectionSelectors_4fd);
	if( ( !connectionSelectors_4fd.empty()))
		callDestroyDataNetwork_5ab( connectionSelectors_4fd);
}

void ForBlock_492::callDestroyDataNetwork_5ab( const Packets_t& eConnectionSelectors_51b)
{
	DestroyDataNetwork_51a destroyDataNetwork_51a;
	destroyDataNetwork_51a( eConnectionSelectors_51b);
}

void GetPorts_49c::operator()( const Packets_t& components_49d, const Packets_t& rootContainers_49f, Packets_t& rootContainers_4a1, Packets_t& ports_4a2)
{
#ifdef PRINT_INFO
	std::cout << "GetPorts_49c" << std::endl;
#endif
	_rootContainer_4a3= &rootContainers_4a1;
	_port_4a4= &ports_4a2;
	processInputPackets( components_49d, rootContainers_49f);
}

bool GetPorts_49c::isInputUnique( const Udm::Object& component_4a9, const Udm::Object& rootContainer_4b2)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponent_4ab= _component_4a5.begin(), itRootContainer_4b4= _rootContainer_4ae.begin(); itComponent_4ab!= _component_4a5.end(), itRootContainer_4b4!= _rootContainer_4ae.end(); ++itComponent_4ab, ++itRootContainer_4b4)
	{
		if( ( *itComponent_4ab== component_4a9)&& ( *itRootContainer_4b4== rootContainer_4b2))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_component_4a5.push_back( component_4a9);
		_rootContainer_4ae.push_back( rootContainer_4b2);
	}
	return isUnique;
}

void GetPorts_49c::processInputPackets( const Packets_t& components_49d, const Packets_t& rootContainers_49f)
{
	for( Packets_t::const_iterator itComponent_4a6= components_49d.begin(), itRootContainer_4af= rootContainers_49f.begin(); itComponent_4a6!= components_49d.end(), itRootContainer_4af!= rootContainers_49f.end(); ++itComponent_4a6, ++itRootContainer_4af)
	{
		bool isUnique= isInputUnique( *itComponent_4a6, *itRootContainer_4af);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponent_4a6, *itRootContainer_4af);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool GetPorts_49c::patternMatcher( const Udm::Object& component_4a7, const Udm::Object& rootContainer_4b0)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( component_4a7.type(), PICML::Component::meta))
			continue;
		PICML::Component component_4ac= PICML::Component::Cast( component_4a7);
		if( false== Uml::IsDerivedFrom( rootContainer_4b0.type(), PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta))
			continue;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_4b5= PICMLCadena_Xchange_embedded_EIProperties::RootContainer::Cast( rootContainer_4b0);
		set< PICML::Port> ports_4b7= component_4ac.Port_kind_children();
		for( set< PICML::Port>::const_iterator itPort_4b8= ports_4b7.begin(); itPort_4b8!= ports_4b7.end(); ++itPort_4b8)
		{
			PICML::Port currPort_4b9= *itPort_4b8;
			Match currMatch;
			currMatch.component_4ba= component_4ac;
			currMatch.rootContainer_4bb= rootContainer_4b5;
			currMatch.port_4bc= currPort_4b9;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void GetPorts_49c::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.rootContainer_4bb, currMatch.port_4bc);
	}
}

void GetPorts_49c::outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::RootContainer& rootContainer_4bd, const PICML::Port& port_4bf)
{
	_rootContainer_4a3->push_back( rootContainer_4bd);
	_port_4a4->push_back( port_4bf);
}

void MatchCorrectInvokeConnection_4c1::operator()( const Packets_t& rootContainers_4c3, const Packets_t& requiredRequestPorts_4c6, Packets_t& connectionSelectors_4c2, Packets_t& fRConnections_4c5)
{
#ifdef PRINT_INFO
	std::cout << "MatchCorrectInvokeConnection_4c1" << std::endl;
#endif
	_connectionSelector_4c8= &connectionSelectors_4c2;
	_fRConnection_4c9= &fRConnections_4c5;
	processInputPackets( rootContainers_4c3, requiredRequestPorts_4c6);
}

bool MatchCorrectInvokeConnection_4c1::isInputUnique( const Udm::Object& rootContainer_4ce, const Udm::Object& requiredRequestPort_4d7)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRootContainer_4d0= _rootContainer_4ca.begin(), itRequiredRequestPort_4d9= _requiredRequestPort_4d3.begin(); itRootContainer_4d0!= _rootContainer_4ca.end(), itRequiredRequestPort_4d9!= _requiredRequestPort_4d3.end(); ++itRootContainer_4d0, ++itRequiredRequestPort_4d9)
	{
		if( ( *itRootContainer_4d0== rootContainer_4ce)&& ( *itRequiredRequestPort_4d9== requiredRequestPort_4d7))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_rootContainer_4ca.push_back( rootContainer_4ce);
		_requiredRequestPort_4d3.push_back( requiredRequestPort_4d7);
	}
	return isUnique;
}

bool MatchCorrectInvokeConnection_4c1::isGuardTrue( const Udm::Object& Component, const Udm::Object& ConnectionSelector, const Udm::Object& FRConnection, const Udm::Object& ProvidedRequestPort, const Udm::Object& RequiredRequestPort, const Udm::Object& RootContainer, const Udm::Object& invoke)
{
	bool Gz_guard= false;
	string slaveComponentName, requiredSlaveComponentName,           slavePortName, requiredSlavePortName,          masterPortName, requiredMasterPortName;  ConnectionSelector.GetStrValue("masterPortName", requiredMasterPortName); ConnectionSelector.GetStrValue("slaveComponentName", requiredSlaveComponentName); ConnectionSelector.GetStrValue("slavePortName", requiredSlavePortName);  RequiredRequestPort.GetStrValue("name", masterPortName); Component.GetStrValue("name", slaveComponentName); ProvidedRequestPort.GetStrValue("name", slavePortName);  if (slaveComponentName != requiredSlaveComponentName) return false; if (slavePortName != requiredSlavePortName) return false; if (masterPortName != requiredMasterPortName) return false; return true;;
	return Gz_guard;
}

void MatchCorrectInvokeConnection_4c1::processInputPackets( const Packets_t& rootContainers_4c3, const Packets_t& requiredRequestPorts_4c6)
{
	for( Packets_t::const_iterator itRootContainer_4cb= rootContainers_4c3.begin(), itRequiredRequestPort_4d4= requiredRequestPorts_4c6.begin(); itRootContainer_4cb!= rootContainers_4c3.end(), itRequiredRequestPort_4d4!= requiredRequestPorts_4c6.end(); ++itRootContainer_4cb, ++itRequiredRequestPort_4d4)
	{
		bool isUnique= isInputUnique( *itRootContainer_4cb, *itRequiredRequestPort_4d4);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRootContainer_4cb, *itRequiredRequestPort_4d4);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool MatchCorrectInvokeConnection_4c1::patternMatcher( const Udm::Object& rootContainer_4cc, const Udm::Object& requiredRequestPort_4d5)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( rootContainer_4cc.type(), PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta))
			continue;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_4d1= PICMLCadena_Xchange_embedded_EIProperties::RootContainer::Cast( rootContainer_4cc);
		if( false== Uml::IsDerivedFrom( requiredRequestPort_4d5.type(), PICML::RequiredRequestPort::meta))
			continue;
		PICML::RequiredRequestPort requiredRequestPort_4da= PICML::RequiredRequestPort::Cast( requiredRequestPort_4d5);
		set< PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector> connectionSelectors_4dc= rootContainer_4d1.ConnectionSelector_kind_children();
		for( set< PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector>::const_iterator itConnectionSelector_4dd= connectionSelectors_4dc.begin(); itConnectionSelector_4dd!= connectionSelectors_4dc.end(); ++itConnectionSelector_4dd)
		{
			PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector currConnectionSelector_4de= *itConnectionSelector_4dd;
			set< PICML::invoke> invokes_4df= requiredRequestPort_4da.dstinvoke();
			for( set< PICML::invoke>::const_iterator itinvokes_4e0= invokes_4df.begin(); itinvokes_4e0!= invokes_4df.end(); ++itinvokes_4e0)
			{
				PICML::invoke currinvoke_4e1= *itinvokes_4e0;
				cadena_scenario::FRConnection fRConnection_4e2= currinvoke_4e1.cadenaInvoke();
				if( !fRConnection_4e2)
					continue;
				PICML::ProvidedRequestPort providedRequestPort_4e3= currinvoke_4e1.dstinvoke_end();
				Udm::Object providedRequestPortParent_4e4= providedRequestPort_4e3.container();
				if( false== Uml::IsDerivedFrom( providedRequestPortParent_4e4.type(), PICML::Component::meta))
					continue;
				PICML::Component componentProvidedRequestPort_4e5= PICML::Component::Cast( providedRequestPortParent_4e4);
				Match currMatch;
				currMatch.connectionSelector_4e6= currConnectionSelector_4de;
				currMatch.providedRequestPort_4e7= providedRequestPort_4e3;
				currMatch.rootContainer_4e8= rootContainer_4d1;
				currMatch.invoke_4e9= currinvoke_4e1;
				currMatch.component_4ea= componentProvidedRequestPort_4e5;
				currMatch.fRConnection_4eb= fRConnection_4e2;
				currMatch.requiredRequestPort_4ec= requiredRequestPort_4da;
				bool Gz_guard= isGuardTrue( currMatch.component_4ea, currMatch.connectionSelector_4e6, currMatch.fRConnection_4eb, currMatch.providedRequestPort_4e7, currMatch.requiredRequestPort_4ec, currMatch.rootContainer_4e8, currMatch.invoke_4e9);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void MatchCorrectInvokeConnection_4c1::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.connectionSelector_4e6, currMatch.fRConnection_4eb);
	}
}

void MatchCorrectInvokeConnection_4c1::outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector& connectionSelector_4f4, const cadena_scenario::FRConnection& fRConnection_4f6)
{
	_connectionSelector_4c8->push_back( connectionSelector_4f4);
	_fRConnection_4c9->push_back( fRConnection_4f6);
}

void TransferEIProperties_4f8::operator()( const Packets_t& portConnections_4f9, const Packets_t& connectionSelectors_4fb, Packets_t& connectionSelectors_4fd)
{
#ifdef PRINT_INFO
	std::cout << "TransferEIProperties_4f8" << std::endl;
#endif
	_connectionSelector_4fe= &connectionSelectors_4fd;
	processInputPackets( portConnections_4f9, connectionSelectors_4fb);
	forwardInputs( );
}

bool TransferEIProperties_4f8::isInputUnique( const Udm::Object& portConnection_503, const Udm::Object& connectionSelector_50c)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itPortConnection_505= _portConnection_4ff.begin(), itConnectionSelector_50e= _connectionSelector_508.begin(); itPortConnection_505!= _portConnection_4ff.end(), itConnectionSelector_50e!= _connectionSelector_508.end(); ++itPortConnection_505, ++itConnectionSelector_50e)
	{
		if( ( *itPortConnection_505== portConnection_503)&& ( *itConnectionSelector_50e== connectionSelector_50c))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_portConnection_4ff.push_back( portConnection_503);
		_connectionSelector_508.push_back( connectionSelector_50c);
	}
	return isUnique;
}

void TransferEIProperties_4f8::processInputPackets( const Packets_t& portConnections_4f9, const Packets_t& connectionSelectors_4fb)
{
	for( Packets_t::const_iterator itPortConnection_500= portConnections_4f9.begin(), itConnectionSelector_509= connectionSelectors_4fb.begin(); itPortConnection_500!= portConnections_4f9.end(), itConnectionSelector_509!= connectionSelectors_4fb.end(); ++itPortConnection_500, ++itConnectionSelector_509)
	{
		bool isUnique= isInputUnique( *itPortConnection_500, *itConnectionSelector_509);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itPortConnection_500, *itConnectionSelector_509);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool TransferEIProperties_4f8::patternMatcher( const Udm::Object& portConnection_501, const Udm::Object& connectionSelector_50a)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( portConnection_501.type(), cadena_scenario::PortConnection::meta))
			continue;
		cadena_scenario::PortConnection portConnection_506= cadena_scenario::PortConnection::Cast( portConnection_501);
		if( false== Uml::IsDerivedFrom( connectionSelector_50a.type(), PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector::meta))
			continue;
		PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector connectionSelector_50f= PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector::Cast( connectionSelector_50a);
		set< PICMLCadena_Xchange_embedded_EIProperties::Property> ePropertys_511= connectionSelector_50f.Property_kind_children();
		for( set< PICMLCadena_Xchange_embedded_EIProperties::Property>::const_iterator itEProperty_512= ePropertys_511.begin(); itEProperty_512!= ePropertys_511.end(); ++itEProperty_512)
		{
			PICMLCadena_Xchange_embedded_EIProperties::Property currEProperty_513= *itEProperty_512;
			Match currMatch;
			currMatch.eProperty_514= currEProperty_513;
			currMatch.portConnection_515= portConnection_506;
			currMatch.connectionSelector_516= connectionSelector_50f;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void TransferEIProperties_4f8::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		cadena_scenario::Property newCProperty_517= cadena_scenario::Property::Create( currMatch.portConnection_515);
		Udm::Object& CProperty= newCProperty_517;
		Udm::Object& ConnectionSelector= currMatch.connectionSelector_516;
		Udm::Object& EProperty= currMatch.eProperty_514;
		Udm::Object& PortConnection= currMatch.portConnection_515;
		{string str; EProperty.GetStrValue("name", str); CProperty.SetStrValue("name", str); EProperty.GetStrValue("type", str); CProperty.SetStrValue("type", str); EProperty.GetStrValue("value", str); CProperty.SetStrValue("value", str);};
		outputAppender( currMatch.connectionSelector_516);
	}
}

void TransferEIProperties_4f8::outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector& connectionSelector_518)
{
	_connectionSelector_4fe->push_back( connectionSelector_518);
}

void TransferEIProperties_4f8::forwardInputs()
{
	*_connectionSelector_4fe= _connectionSelector_508;
}

void DestroyDataNetwork_51a::operator()( const Packets_t& eConnectionSelectors_51b)
{
#ifdef PRINT_INFO
	std::cout << "DestroyDataNetwork_51a" << std::endl;
#endif
	if( ( !eConnectionSelectors_51b.empty()))
		callMatch_RootContainer_542( eConnectionSelectors_51b);
}

void DestroyDataNetwork_51a::callMatch_RootContainer_542( const Packets_t& connectionSelectors_51e)
{
	Packets_t rootContainers_520;
	Match_RootContainer_51d match_RootContainer_51d;
	match_RootContainer_51d( connectionSelectors_51e, rootContainers_520);
	if( ( !rootContainers_520.empty()))
		callKillEverything_544( rootContainers_520);
}

void DestroyDataNetwork_51a::callKillEverything_544( const Packets_t& rootContainers_532)
{
	KillEverything_531 killEverything_531;
	killEverything_531( rootContainers_532);
}

void Match_RootContainer_51d::operator()( const Packets_t& connectionSelectors_51e, Packets_t& rootContainers_520)
{
#ifdef PRINT_INFO
	std::cout << "Match_RootContainer_51d" << std::endl;
#endif
	_rootContainer_521= &rootContainers_520;
	processInputPackets( connectionSelectors_51e);
}

bool Match_RootContainer_51d::isInputUnique( const Udm::Object& connectionSelector_526)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itConnectionSelector_528= _connectionSelector_522.begin(); itConnectionSelector_528!= _connectionSelector_522.end(); ++itConnectionSelector_528)
	{
		if( ( *itConnectionSelector_528== connectionSelector_526))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_connectionSelector_522.push_back( connectionSelector_526);
	return isUnique;
}

void Match_RootContainer_51d::processInputPackets( const Packets_t& connectionSelectors_51e)
{
	for( Packets_t::const_iterator itConnectionSelector_523= connectionSelectors_51e.begin(); itConnectionSelector_523!= connectionSelectors_51e.end(); ++itConnectionSelector_523)
	{
		bool isUnique= isInputUnique( *itConnectionSelector_523);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itConnectionSelector_523);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Match_RootContainer_51d::patternMatcher( const Udm::Object& connectionSelector_524)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( connectionSelector_524.type(), PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector::meta))
			continue;
		PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector connectionSelector_529= PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector::Cast( connectionSelector_524);
		Udm::Object connectionSelectorParent_52b= connectionSelector_529.container();
		if( false== Uml::IsDerivedFrom( connectionSelectorParent_52b.type(), PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta))
			continue;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainerConnectionSelector_52c= PICMLCadena_Xchange_embedded_EIProperties::RootContainer::Cast( connectionSelectorParent_52b);
		Match currMatch;
		currMatch.connectionSelector_52d= connectionSelector_529;
		currMatch.rootContainer_52e= rootContainerConnectionSelector_52c;
		_matches.push_back( currMatch);
	}
	return !_matches.empty();
}

void Match_RootContainer_51d::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.rootContainer_52e);
	}
}

void Match_RootContainer_51d::outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::RootContainer& rootContainer_52f)
{
	_rootContainer_521->push_back( rootContainer_52f);
}

void KillEverything_531::operator()( const Packets_t& rootContainers_532)
{
#ifdef PRINT_INFO
	std::cout << "KillEverything_531" << std::endl;
#endif
	processInputPackets( rootContainers_532);
}

bool KillEverything_531::isInputUnique( const Udm::Object& rootContainer_538)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRootContainer_53a= _rootContainer_534.begin(); itRootContainer_53a!= _rootContainer_534.end(); ++itRootContainer_53a)
	{
		if( ( *itRootContainer_53a== rootContainer_538))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_rootContainer_534.push_back( rootContainer_538);
	return isUnique;
}

void KillEverything_531::processInputPackets( const Packets_t& rootContainers_532)
{
	for( Packets_t::const_iterator itRootContainer_535= rootContainers_532.begin(); itRootContainer_535!= rootContainers_532.end(); ++itRootContainer_535)
	{
		bool isUnique= isInputUnique( *itRootContainer_535);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRootContainer_535);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool KillEverything_531::patternMatcher( const Udm::Object& rootContainer_536)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( rootContainer_536.type(), PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta))
			continue;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_53b= PICMLCadena_Xchange_embedded_EIProperties::RootContainer::Cast( rootContainer_536);
		set< PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector> connectionSelectors_53d= rootContainer_53b.ConnectionSelector_kind_children();
		for( set< PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector>::const_iterator itConnectionSelector_53e= connectionSelectors_53d.begin(); itConnectionSelector_53e!= connectionSelectors_53d.end(); ++itConnectionSelector_53e)
		{
			PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector currConnectionSelector_53f= *itConnectionSelector_53e;
			Match currMatch;
			currMatch.rootContainer_540= rootContainer_53b;
			currMatch.connectionSelector_541= currConnectionSelector_53f;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void KillEverything_531::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		if( currMatch.connectionSelector_541)
			currMatch.connectionSelector_541.DeleteObject();
		outputAppender( );
	}
}

void KillEverything_531::outputAppender()
{
}

void MatchCorrectEmitConnection_546::operator()( const Packets_t& rootContainers_548, const Packets_t& outEventPorts_54a, Packets_t& connectionSelectors_547, Packets_t& eSSConnections_54c)
{
#ifdef PRINT_INFO
	std::cout << "MatchCorrectEmitConnection_546" << std::endl;
#endif
	_connectionSelector_54d= &connectionSelectors_547;
	_eSSConnection_54e= &eSSConnections_54c;
	processInputPackets( rootContainers_548, outEventPorts_54a);
}

bool MatchCorrectEmitConnection_546::isInputUnique( const Udm::Object& rootContainer_553, const Udm::Object& outEventPort_55c)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itRootContainer_555= _rootContainer_54f.begin(), itOutEventPort_55e= _outEventPort_558.begin(); itRootContainer_555!= _rootContainer_54f.end(), itOutEventPort_55e!= _outEventPort_558.end(); ++itRootContainer_555, ++itOutEventPort_55e)
	{
		if( ( *itRootContainer_555== rootContainer_553)&& ( *itOutEventPort_55e== outEventPort_55c))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
	{
		_rootContainer_54f.push_back( rootContainer_553);
		_outEventPort_558.push_back( outEventPort_55c);
	}
	return isUnique;
}

bool MatchCorrectEmitConnection_546::isGuardTrue( const Udm::Object& Component, const Udm::Object& ConnectionSelector, const Udm::Object& ESSConnection, const Udm::Object& InEventPort, const Udm::Object& OutEventPort, const Udm::Object& RootContainer, const Udm::Object& emit)
{
	bool Gz_guard= false;
	string slaveComponentName, requiredSlaveComponentName,           slavePortName, requiredSlavePortName,          masterPortName, requiredMasterPortName;  ConnectionSelector.GetStrValue("masterPortName", requiredMasterPortName); ConnectionSelector.GetStrValue("slaveComponentName", requiredSlaveComponentName); ConnectionSelector.GetStrValue("slavePortName", requiredSlavePortName);  OutEventPort.GetStrValue("name", masterPortName); Component.GetStrValue("name", slaveComponentName); InEventPort.GetStrValue("name", slavePortName);  if (slaveComponentName != requiredSlaveComponentName) return false; if (slavePortName != requiredSlavePortName) return false; if (masterPortName != requiredMasterPortName) return false; return true;;
	return Gz_guard;
}

void MatchCorrectEmitConnection_546::processInputPackets( const Packets_t& rootContainers_548, const Packets_t& outEventPorts_54a)
{
	for( Packets_t::const_iterator itRootContainer_550= rootContainers_548.begin(), itOutEventPort_559= outEventPorts_54a.begin(); itRootContainer_550!= rootContainers_548.end(), itOutEventPort_559!= outEventPorts_54a.end(); ++itRootContainer_550, ++itOutEventPort_559)
	{
		bool isUnique= isInputUnique( *itRootContainer_550, *itOutEventPort_559);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itRootContainer_550, *itOutEventPort_559);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool MatchCorrectEmitConnection_546::patternMatcher( const Udm::Object& rootContainer_551, const Udm::Object& outEventPort_55a)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( rootContainer_551.type(), PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta))
			continue;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_556= PICMLCadena_Xchange_embedded_EIProperties::RootContainer::Cast( rootContainer_551);
		if( false== Uml::IsDerivedFrom( outEventPort_55a.type(), PICML::OutEventPort::meta))
			continue;
		PICML::OutEventPort outEventPort_55f= PICML::OutEventPort::Cast( outEventPort_55a);
		set< PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector> connectionSelectors_561= rootContainer_556.ConnectionSelector_kind_children();
		for( set< PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector>::const_iterator itConnectionSelector_562= connectionSelectors_561.begin(); itConnectionSelector_562!= connectionSelectors_561.end(); ++itConnectionSelector_562)
		{
			PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector currConnectionSelector_563= *itConnectionSelector_562;
			PICML::emit emit_564= outEventPort_55f.dstemit();
			if( !emit_564)
				continue;
			set< cadena_scenario::ESSConnection> eSSConnections_565= emit_564.cadenaEmit();
			for( set< cadena_scenario::ESSConnection>::const_iterator itESSConnections_566= eSSConnections_565.begin(); itESSConnections_566!= eSSConnections_565.end(); ++itESSConnections_566)
			{
				cadena_scenario::ESSConnection currESSConnection_567= *itESSConnections_566;
				PICML::InEventPort inEventPort_568= emit_564.dstemit_end();
				Udm::Object inEventPortParent_569= inEventPort_568.container();
				if( false== Uml::IsDerivedFrom( inEventPortParent_569.type(), PICML::Component::meta))
					continue;
				PICML::Component componentInEventPort_56a= PICML::Component::Cast( inEventPortParent_569);
				Match currMatch;
				currMatch.component_56b= componentInEventPort_56a;
				currMatch.connectionSelector_56c= currConnectionSelector_563;
				currMatch.emit_56d= emit_564;
				currMatch.rootContainer_56e= rootContainer_556;
				currMatch.outEventPort_56f= outEventPort_55f;
				currMatch.eSSConnection_570= currESSConnection_567;
				currMatch.inEventPort_571= inEventPort_568;
				bool Gz_guard= isGuardTrue( currMatch.component_56b, currMatch.connectionSelector_56c, currMatch.eSSConnection_570, currMatch.inEventPort_571, currMatch.outEventPort_56f, currMatch.rootContainer_56e, currMatch.emit_56d);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void MatchCorrectEmitConnection_546::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.connectionSelector_56c, currMatch.eSSConnection_570);
	}
}

void MatchCorrectEmitConnection_546::outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector& connectionSelector_579, const cadena_scenario::ESSConnection& eSSConnection_57b)
{
	_connectionSelector_54d->push_back( connectionSelector_579);
	_eSSConnection_54e->push_back( eSSConnection_57b);
}

void Open_EIConnectionProperties_DataNetwork_57d::operator()( const Packets_t& propertys_57f, Packets_t& rootContainers_57e, Packets_t& components_581)
{
#ifdef PRINT_INFO
	std::cout << "Open_EIConnectionProperties_DataNetwork_57d" << std::endl;
#endif
	_rootContainer_582= &rootContainers_57e;
	_component_583= &components_581;
	processInputPackets( propertys_57f);
}

bool Open_EIConnectionProperties_DataNetwork_57d::isInputUnique( const Udm::Object& property_588)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itProperty_58a= _property_584.begin(); itProperty_58a!= _property_584.end(); ++itProperty_58a)
	{
		if( ( *itProperty_58a== property_588))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_property_584.push_back( property_588);
	return isUnique;
}

void Open_EIConnectionProperties_DataNetwork_57d::processInputPackets( const Packets_t& propertys_57f)
{
	for( Packets_t::const_iterator itProperty_585= propertys_57f.begin(); itProperty_585!= propertys_57f.end(); ++itProperty_585)
	{
		bool isUnique= isInputUnique( *itProperty_585);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itProperty_585);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Open_EIConnectionProperties_DataNetwork_57d::patternMatcher( const Udm::Object& property_586)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( property_586.type(), PICML::Property::meta))
			continue;
		PICML::Property property_58b= PICML::Property::Cast( property_586);
		set< PICML::AssemblyConfigProperty> assemblyConfigPropertys_58d= property_58b.srcAssemblyConfigProperty();
		for( set< PICML::AssemblyConfigProperty>::const_iterator itAssemblyConfigPropertys_58e= assemblyConfigPropertys_58d.begin(); itAssemblyConfigPropertys_58e!= assemblyConfigPropertys_58d.end(); ++itAssemblyConfigPropertys_58e)
		{
			PICML::AssemblyConfigProperty currAssemblyConfigProperty_58f= *itAssemblyConfigPropertys_58e;
			PICML::Component component_590= currAssemblyConfigProperty_58f.srcAssemblyConfigProperty_end();
			Udm::Object componentParent_591= component_590.container();
			if( false== Uml::IsDerivedFrom( componentParent_591.type(), PICML::ComponentAssembly::meta))
				continue;
			PICML::ComponentAssembly componentAssemblyComponent_592= PICML::ComponentAssembly::Cast( componentParent_591);
			PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_593= componentAssemblyComponent_592.rootContainer();
			if( !rootContainer_593)
				continue;
			Match currMatch;
			currMatch.rootContainer_594= rootContainer_593;
			currMatch.assemblyConfigProperty_595= currAssemblyConfigProperty_58f;
			currMatch.componentAssembly_596= componentAssemblyComponent_592;
			currMatch.property_597= property_58b;
			currMatch.component_598= component_590;
			_matches.push_back( currMatch);
		}
	}
	return !_matches.empty();
}

void Open_EIConnectionProperties_DataNetwork_57d::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		Udm::Object& AssemblyConfigProperty= currMatch.assemblyConfigProperty_595;
		Udm::Object& Component= currMatch.component_598;
		Udm::Object& ComponentAssembly= currMatch.componentAssembly_596;
		Udm::Object& Property= currMatch.property_597;
		Udm::Object& RootContainer= currMatch.rootContainer_594;
		{string str; Property.GetStrValue("DataValue",str);   FILE *f=NULL; string tempfilename=tmpnam(NULL); /*tempfilename+=".xml";*/ if (NULL != (f=fopen(tempfilename.c_str(),"w+b")) ) {   fwrite(str.c_str(),1,str.size(),f);   fclose(f);    /*Debug output which can be removed*/   /*   string prev_filename; SourceChild.GetStrValue("AFileName", prev_filename);    SourceChild.SetStrValue("AFileContent", prev_filename + " ----> "+ tempfilename);   */     /*----------------------- READING OBJECT NETWORK ----------------------------*/   Udm::UdmDiagram mydiagram;    mydiagram.dgr=const_cast<Uml::Diagram *>(&(RootContainer.__impl()->__getdn()->GetRootMeta()));   mydiagram.init=Uml::diagram.init;    UdmDom::DomDataNetwork ddn(mydiagram);   ddn.OpenExisting(tempfilename, "");   UdmUtil::CopyObjectHierarchy(ddn.GetRootObject().__impl(), RootContainer.__impl(), RootContainer.__impl()->__getdn(), UdmUtil::copy_assoc_map());      /*---------------------- END READING OBJECT NETWORK -------------------------*/    /*Closing DataNetwork (also closes file) and THEN deleting temporary file*/    ddn.CloseNoUpdate();   fclose(fopen(tempfilename.c_str(),"w+bDT")); }};
		outputAppender( currMatch.rootContainer_594, currMatch.component_598);
	}
}

void Open_EIConnectionProperties_DataNetwork_57d::outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::RootContainer& rootContainer_599, const PICML::Component& component_59b)
{
	_rootContainer_582->push_back( rootContainer_599);
	_component_583->push_back( component_59b);
}

void Match_EIProperties_5ad::operator()( const Packets_t& componentAssemblys_5af, Packets_t& propertys_5ae)
{
#ifdef PRINT_INFO
	std::cout << "Match_EIProperties_5ad" << std::endl;
#endif
	_property_5b1= &propertys_5ae;
	processInputPackets( componentAssemblys_5af);
}

bool Match_EIProperties_5ad::isInputUnique( const Udm::Object& componentAssembly_5b6)
{
	bool isUnique= true;
	for( Packets_t::const_iterator itComponentAssembly_5b8= _componentAssembly_5b2.begin(); itComponentAssembly_5b8!= _componentAssembly_5b2.end(); ++itComponentAssembly_5b8)
	{
		if( ( *itComponentAssembly_5b8== componentAssembly_5b6))
		{
			isUnique= false;
			break;
		}
	}
	if( isUnique)
		_componentAssembly_5b2.push_back( componentAssembly_5b6);
	return isUnique;
}

bool Match_EIProperties_5ad::isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& Property)
{
	bool Gz_guard= false;
	string name; Property.GetStrValue("name", name); return (name=="CadenaEIProperties");;
	return Gz_guard;
}

void Match_EIProperties_5ad::processInputPackets( const Packets_t& componentAssemblys_5af)
{
	for( Packets_t::const_iterator itComponentAssembly_5b3= componentAssemblys_5af.begin(); itComponentAssembly_5b3!= componentAssemblys_5af.end(); ++itComponentAssembly_5b3)
	{
		bool isUnique= isInputUnique( *itComponentAssembly_5b3);
		if( !isUnique)
			continue;
		bool isMatch= patternMatcher( *itComponentAssembly_5b3);
		if( isMatch)
			effector( );
		_matches.clear();
	}
}

bool Match_EIProperties_5ad::patternMatcher( const Udm::Object& componentAssembly_5b4)
{
	for( int i= 0; i< 1; ++i)
	{
		if( false== Uml::IsDerivedFrom( componentAssembly_5b4.type(), PICML::ComponentAssembly::meta))
			continue;
		PICML::ComponentAssembly componentAssembly_5b9= PICML::ComponentAssembly::Cast( componentAssembly_5b4);
		set< PICML::Component> components_5bb= componentAssembly_5b9.Component_kind_children();
		for( set< PICML::Component>::const_iterator itComponent_5bc= components_5bb.begin(); itComponent_5bc!= components_5bb.end(); ++itComponent_5bc)
		{
			PICML::Component currComponent_5bd= *itComponent_5bc;
			set< PICML::AssemblyConfigProperty> assemblyConfigPropertys_5be= currComponent_5bd.dstAssemblyConfigProperty();
			for( set< PICML::AssemblyConfigProperty>::const_iterator itAssemblyConfigPropertys_5bf= assemblyConfigPropertys_5be.begin(); itAssemblyConfigPropertys_5bf!= assemblyConfigPropertys_5be.end(); ++itAssemblyConfigPropertys_5bf)
			{
				PICML::AssemblyConfigProperty currAssemblyConfigProperty_5c0= *itAssemblyConfigPropertys_5bf;
				PICML::Property property_5c1= currAssemblyConfigProperty_5c0.dstAssemblyConfigProperty_end();
				Match currMatch;
				currMatch.property_5c2= property_5c1;
				currMatch.componentAssembly_5c3= componentAssembly_5b9;
				currMatch.assemblyConfigProperty_5c4= currAssemblyConfigProperty_5c0;
				currMatch.component_5c5= currComponent_5bd;
				bool Gz_guard= isGuardTrue( currMatch.assemblyConfigProperty_5c4, currMatch.component_5c5, currMatch.componentAssembly_5c3, currMatch.property_5c2);
				if( true== Gz_guard)
					_matches.push_back( currMatch);
			}
		}
	}
	return !_matches.empty();
}

void Match_EIProperties_5ad::effector()
{
	for( std::list< Match>::const_iterator itMatch= _matches.begin(); itMatch!= _matches.end(); ++itMatch)
	{
		Match currMatch= *itMatch;
		outputAppender( currMatch.property_5c2);
	}
}

void Match_EIProperties_5ad::outputAppender( const PICML::Property& property_5ca)
{
	_property_5b1->push_back( property_5ca);
}

