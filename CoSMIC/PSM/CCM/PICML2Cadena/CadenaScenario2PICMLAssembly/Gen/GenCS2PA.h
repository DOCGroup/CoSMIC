#include <UdmBase.h>
#include <cint_string.h>
#include "CrossLinks.h"
#include "PICML.h"
#include "PICMLAssembly2CadenaScenario.h"
#include "PICMLCadena_Xchange_embedded_EIProperties.h"
#include "cadena_scenario.h"

typedef std::list< Udm::Object> Packets_t;

// Forward declarations.
class RootRuleBlock_0;
class Assembly_and_Scenario_Finder_7;
class TearDown_Connections_50;
class TD_DeliverTo_59;
class Optimization_FindComponents_70;
class TD_SrcPublish_85;
class TD_Invokes_9c;
class TD_Emits_b3;
class Associate_Properties_d2;
class Associate_ComponentProperties_db;
class Associate_CadenaProperties_on_PublishConnectors_fe;
class Associate_Components_n_PublishConnectors_12c;
class AssociateComponents_135;
class AssociatePublishConnectors_15a;
class Create_Destroy_UpdateValue_Properties_n_Requirements_19b;
class UpdateValue_1a4;
class EnumeratePublishConnectorProperties_1a9;
class RefreshType_1d8;
class TransferType_1e5;
class TypeIsInteger_1f2;
class TypeIsBoolean_231;
class TypeIsString_270;
class DeleteCurrentType_2bb;
class EnumerateComponentProperties_2f8;
class TransferValue_327;
class Create_and_Set_Emit_Invoke_Properties_34d;
class Set_CEIProperties_DataType_352;
class Find_Invoke_Properties_383;
class DumpEIValue_3bd;
class CopyTo_XProperty_3f5;
class DestroyEverything_441;
class CopyHierarchy_DumpToDisk_ReadFile_Transfer_452;
class Find_Emit_Properties_47a;
class CreateNormalProperties_4c1;
class Ensure_CadenaProperties_Requirement_4ca;
class Test_4d5;
class RequirementExists_4f2;
class RequirementDoesNotExist_521;
class Create_CadenaProperties_Requirement_542;
class PublishConnectorProperty_Find_Unmatched_572;
class Create_PublishConnectorProperty_595;
class ComponentProperties_Create_5b2;
class DestroyProperties_5da;
class DestroyComponentProperties_5e3;
class DestroyCadenaEIProperties_61f;
class DestroyPublishConnectorProperties_650;
class Associate_Ports_6a3;
class Match_Components_6ac;
class Associate_Ports_rule_6c7;
class CreateDestroy_Components_n_PublishConnectors_6f1;
class CreatePublishConnectors_step3_6fa;
class CreatePublishConnectors_step3_rule_6ff;
class DestroyOrphanPropertiesAndDeleteComponent_728;
class DestroyOrphanProperties_732;
class DestroyComponent_76a;
class CreatePublishConnectors_step2_781;
class CreatePublishConnectors_step2_rule_78a;
class CreatePublishConnectors_step1_7a9;
class CreatePublishConnectors_step1_rule_7b2;
class DestroyPublishConnectors_7cc;
class FinalPackage_InstantiateComponent_7e5;
class FindSubPackage_81a;
class MatchAPackage_84f;
class AssociateComponentsNow_880;
class FindFirstPackage_8a0;
class FindComponents2BDeleted_8da;
class CreateComponents_step1_8f1;
class ReCreate_Connections_940;
class Create_Invokes_949;
class Create_Emits_971;
class Create_SrcPublish_9a4;
class Create_DeliverTo_9c7;

// Class declarations.
class RootRuleBlock_0
{
public:
	void operator()( const Packets_t& embedded_Dummy_File_Ins_1, const Packets_t& pICML_File_Ins_3, const Packets_t& cadena_File_Ins_5);

protected:
	void callAssembly_and_Scenario_Finder_9f2( const Packets_t& rootContainers_8, const Packets_t& scenarioss_a, const Packets_t& rootFolders_d);
	void callAssociate_Components_n_PublishConnectors_9f6( const Packets_t& pAssemblys_12d, const Packets_t& cScenarios_12f);
	void callCreateDestroy_Components_n_PublishConnectors_9f9( const Packets_t& pAssemblys_6f2, const Packets_t& cScenarios_6f4);
	void callTearDown_Connections_9fc( const Packets_t& cScenarios_51, const Packets_t& pAssemblys_53);
	void callAssociate_Ports_9ff( const Packets_t& pAssemblys_6a4, const Packets_t& cScenarios_6a6);
	void callReCreate_Connections_a02( const Packets_t& pAssemblys_941, const Packets_t& cScenarios_943);
	void callAssociate_Properties_a05( const Packets_t& cScenarios_d3, const Packets_t& pAssemblys_d5);
	void callCreate_Destroy_UpdateValue_Properties_n_Requirements_a08( const Packets_t& cScenarios_19c, const Packets_t& pAssemblys_19e);
};

class Assembly_and_Scenario_Finder_7
{
public:
	void operator()( const Packets_t& rootContainers_8, const Packets_t& scenarioss_a, const Packets_t& rootFolders_d, Packets_t& scenarios_c, Packets_t& componentAssemblys_f);

protected:
	bool isInputUnique( const Udm::Object& rootContainer_16, const Udm::Object& scenarios_1f, const Udm::Object& rootFolder_28);
	bool isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& Property, const Udm::Object& RootContainer, const Udm::Object& RootFolder, const Udm::Object& Scenario, const Udm::Object& Scenarios);
	void processInputPackets( const Packets_t& rootContainers_8, const Packets_t& scenarioss_a, const Packets_t& rootFolders_d);
	bool patternMatcher( const Udm::Object& rootContainer_14, const Udm::Object& scenarios_1d, const Udm::Object& rootFolder_26);
	void effector();
	void outputAppender( const cadena_scenario::Scenario& scenario_4c, const PICML::ComponentAssembly& componentAssembly_4e);

private:
	Packets_t* _scenario_10;
	Packets_t* _componentAssembly_11;
	Packets_t _rootContainer_12;
	Packets_t _scenarios_1b;
	Packets_t _rootFolder_24;
	class Match
	{
	public:
		cadena_scenario::Property property_3c;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_3d;
		cadena_scenario::Scenarios scenarios_3e;
		cadena_scenario::Scenario scenario_3f;
		PICML::RootFolder rootFolder_40;
		PICML::ComponentImplementations componentImplementations_41;
		PICML::ComponentImplementationContainer componentImplementationContainer_42;
		PICML::ComponentAssembly componentAssembly_43;
	};

	std::list< Match> _matches;
};

class TearDown_Connections_50
{
public:
	void operator()( const Packets_t& cScenarios_51, const Packets_t& pAssemblys_53, Packets_t& cScenarios_55, Packets_t& pAssemblys_56);

protected:
	void callOptimization_FindComponents_c8( const Packets_t& componentAssemblys_71);
	void callTD_Invokes_ca( const Packets_t& components_9d);
	void callTD_Emits_cc( const Packets_t& components_b4);
	void callTD_SrcPublish_ce( const Packets_t& components_86);
	void callTD_DeliverTo_d0( const Packets_t& components_5a);

private:
	Packets_t* _cScenario_57;
	Packets_t* _pAssembly_58;
};

class TD_DeliverTo_59
{
public:
	void operator()( const Packets_t& components_5a);

protected:
	bool isInputUnique( const Udm::Object& component_60);
	void processInputPackets( const Packets_t& components_5a);
	bool patternMatcher( const Udm::Object& component_5e);
	void effector();
	void outputAppender();

private:
	Packets_t _component_5c;
	class Match
	{
	public:
		PICML::deliverTo deliverTo_6c;
		PICML::Component component_6d;
		PICML::InEventPort inEventPort_6e;
		PICML::PublishConnector publishConnector_6f;
	};

	std::list< Match> _matches;
};

class Optimization_FindComponents_70
{
public:
	void operator()( const Packets_t& componentAssemblys_71, Packets_t& components_73);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_79);
	void processInputPackets( const Packets_t& componentAssemblys_71);
	bool patternMatcher( const Udm::Object& componentAssembly_77);
	void effector();
	void outputAppender( const PICML::Component& component_83);

private:
	Packets_t* _component_74;
	Packets_t _componentAssembly_75;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_81;
		PICML::Component component_82;
	};

	std::list< Match> _matches;
};

class TD_SrcPublish_85
{
public:
	void operator()( const Packets_t& components_86);

protected:
	bool isInputUnique( const Udm::Object& component_8c);
	void processInputPackets( const Packets_t& components_86);
	bool patternMatcher( const Udm::Object& component_8a);
	void effector();
	void outputAppender();

private:
	Packets_t _component_88;
	class Match
	{
	public:
		PICML::PublishConnector publishConnector_98;
		PICML::Component component_99;
		PICML::publish publish_9a;
		PICML::OutEventPort outEventPort_9b;
	};

	std::list< Match> _matches;
};

class TD_Invokes_9c
{
public:
	void operator()( const Packets_t& components_9d);

protected:
	bool isInputUnique( const Udm::Object& component_a3);
	void processInputPackets( const Packets_t& components_9d);
	bool patternMatcher( const Udm::Object& component_a1);
	void effector();
	void outputAppender();

private:
	Packets_t _component_9f;
	class Match
	{
	public:
		PICML::invoke invoke_af;
		PICML::Component component_b0;
		PICML::ProvidedRequestPort providedRequestPort_b1;
		PICML::RequiredRequestPort requiredRequestPort_b2;
	};

	std::list< Match> _matches;
};

class TD_Emits_b3
{
public:
	void operator()( const Packets_t& components_b4);

protected:
	bool isInputUnique( const Udm::Object& component_ba);
	void processInputPackets( const Packets_t& components_b4);
	bool patternMatcher( const Udm::Object& component_b8);
	void effector();
	void outputAppender();

private:
	Packets_t _component_b6;
	class Match
	{
	public:
		PICML::InEventPort inEventPort_c4;
		PICML::Component component_c5;
		PICML::OutEventPort outEventPort_c6;
		PICML::emit emit_c7;
	};

	std::list< Match> _matches;
};

class Associate_Properties_d2
{
public:
	void operator()( const Packets_t& cScenarios_d3, const Packets_t& pAssemblys_d5, Packets_t& pAssemblys_d7, Packets_t& cScenarios_d8);

protected:
	void callAssociate_ComponentProperties_128( const Packets_t& scenarios_dc);
	void callAssociate_CadenaProperties_on_PublishConnectors_12a( const Packets_t& scenarios_ff);

private:
	Packets_t* _pAssembly_d9;
	Packets_t* _cScenario_da;
};

class Associate_ComponentProperties_db
{
public:
	void operator()( const Packets_t& scenarios_dc);

protected:
	bool isInputUnique( const Udm::Object& scenario_e2);
	bool isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& CProperty, const Udm::Object& Component, const Udm::Object& ComponentInstance, const Udm::Object& PProperty, const Udm::Object& Scenario);
	void processInputPackets( const Packets_t& scenarios_dc);
	bool patternMatcher( const Udm::Object& scenario_e0);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_de;
	class Match
	{
	public:
		PICML::AssemblyConfigProperty assemblyConfigProperty_f2;
		PICML::Property pProperty_f3;
		PICML::Component component_f4;
		cadena_scenario::Property cProperty_f5;
		cadena_scenario::ComponentInstance componentInstance_f6;
		cadena_scenario::Scenario scenario_f7;
	};

	std::list< Match> _matches;
};

class Associate_CadenaProperties_on_PublishConnectors_fe
{
public:
	void operator()( const Packets_t& scenarios_ff);

protected:
	bool isInputUnique( const Udm::Object& scenario_105);
	bool isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& CProperty, const Udm::Object& ESSConnection, const Udm::Object& PProperty, const Udm::Object& PublishConnector, const Udm::Object& Requirement, const Udm::Object& Scenario);
	void processInputPackets( const Packets_t& scenarios_ff);
	bool patternMatcher( const Udm::Object& scenario_103);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_101;
	class Match
	{
	public:
		PICML::AssemblyDeployRequirement assemblyDeployRequirement_11a;
		PICML::Requirement requirement_11b;
		PICML::PublishConnector publishConnector_11c;
		cadena_scenario::ESSConnection eSSConnection_11d;
		PICML::Property pProperty_11e;
		cadena_scenario::Scenario scenario_11f;
		cadena_scenario::Property cProperty_120;
	};

	std::list< Match> _matches;
};

class Associate_Components_n_PublishConnectors_12c
{
public:
	void operator()( const Packets_t& pAssemblys_12d, const Packets_t& cScenarios_12f, Packets_t& cScenarios_131, Packets_t& pAssemblys_132);

protected:
	void callAssociateComponents_195( const Packets_t& scenarios_136, const Packets_t& componentAssemblys_138);
	void callAssociatePublishConnectors_198( const Packets_t& componentAssemblys_15b, const Packets_t& scenarios_15d);

private:
	Packets_t* _cScenario_133;
	Packets_t* _pAssembly_134;
};

class AssociateComponents_135
{
public:
	void operator()( const Packets_t& scenarios_136, const Packets_t& componentAssemblys_138);

protected:
	bool isInputUnique( const Udm::Object& scenario_13e, const Udm::Object& componentAssembly_147);
	bool isGuardTrue( const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentInstance, const Udm::Object& Scenario);
	void processInputPackets( const Packets_t& scenarios_136, const Packets_t& componentAssemblys_138);
	bool patternMatcher( const Udm::Object& scenario_13c, const Udm::Object& componentAssembly_145);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_13a;
	Packets_t _componentAssembly_143;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_152;
		cadena_scenario::ComponentInstance componentInstance_153;
		PICML::Component component_154;
		PICML::ComponentAssembly componentAssembly_155;
	};

	std::list< Match> _matches;
};

class AssociatePublishConnectors_15a
{
public:
	void operator()( const Packets_t& componentAssemblys_15b, const Packets_t& scenarios_15d);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_163, const Udm::Object& scenario_16c);
	bool isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& ComponentAssembly, const Udm::Object& DataType, const Udm::Object& ESSConnection, const Udm::Object& Property, const Udm::Object& PublishConnector, const Udm::Object& Requirement, const Udm::Object& Scenario, const Udm::Object& String);
	void processInputPackets( const Packets_t& componentAssemblys_15b, const Packets_t& scenarios_15d);
	bool patternMatcher( const Udm::Object& componentAssembly_161, const Udm::Object& scenario_16a);
	void effector();
	void outputAppender();

private:
	Packets_t _componentAssembly_15f;
	Packets_t _scenario_168;
	class Match
	{
	public:
		PICML::DataType dataType_183;
		PICML::String string_184;
		PICML::Property property_185;
		PICML::AssemblyDeployRequirement assemblyDeployRequirement_186;
		PICML::Requirement requirement_187;
		cadena_scenario::ESSConnection eSSConnection_188;
		PICML::PublishConnector publishConnector_189;
		PICML::ComponentAssembly componentAssembly_18a;
		cadena_scenario::Scenario scenario_18b;
	};

	std::list< Match> _matches;
};

class Create_Destroy_UpdateValue_Properties_n_Requirements_19b
{
public:
	void operator()( const Packets_t& cScenarios_19c, const Packets_t& pAssemblys_19e, Packets_t& pAssemblys_1a0, Packets_t& cScenarios_1a1);

protected:
	void callDestroyProperties_697( const Packets_t& pAssemblys_5db, const Packets_t& cScenarios_5dd);
	void callCreateNormalProperties_69a( const Packets_t& pAssemblys_4c2, const Packets_t& cScenarios_4c4);
	void callCreate_and_Set_Emit_Invoke_Properties_69d( const Packets_t& cScenarios_34e, const Packets_t& pAssemblys_350);
	void callUpdateValue_6a0( const Packets_t& pAssemblys_1a5, const Packets_t& cScenarios_1a7);

private:
	Packets_t* _pAssembly_1a2;
	Packets_t* _cScenario_1a3;
};

class UpdateValue_1a4
{
public:
	void operator()( const Packets_t& pAssemblys_1a5, const Packets_t& cScenarios_1a7);

protected:
	void callEnumeratePublishConnectorProperties_340( const Packets_t& componentAssemblys_1ab, const Packets_t& scenarios_1ae);
	void callEnumerateComponentProperties_343( const Packets_t& componentAssemblys_2f9, const Packets_t& scenarios_2fc);
	void callRefreshType_346( const Packets_t& cPropertys_1d9, const Packets_t& pAssemblys_1db, const Packets_t& pPropertys_1dd);
	void callTransferValue_34a( const Packets_t& cPropertys_328, const Packets_t& pPropertys_32a);
};

class EnumeratePublishConnectorProperties_1a9
{
public:
	void operator()( const Packets_t& componentAssemblys_1ab, const Packets_t& scenarios_1ae, Packets_t& propertys_1aa, Packets_t& componentAssemblys_1ad, Packets_t& cPropertys_1b0);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_1b8, const Udm::Object& scenario_1c1);
	void processInputPackets( const Packets_t& componentAssemblys_1ab, const Packets_t& scenarios_1ae);
	bool patternMatcher( const Udm::Object& componentAssembly_1b6, const Udm::Object& scenario_1bf);
	void effector();
	void outputAppender( const PICML::Property& property_1d2, const PICML::ComponentAssembly& componentAssembly_1d4, const cadena_scenario::Property& cProperty_1d6);

private:
	Packets_t* _property_1b1;
	Packets_t* _componentAssembly_1b2;
	Packets_t* _cProperty_1b3;
	Packets_t _componentAssembly_1b4;
	Packets_t _scenario_1bd;
	class Match
	{
	public:
		PICML::Property property_1cd;
		PICML::ComponentAssembly componentAssembly_1ce;
		cadena_scenario::Scenario scenario_1cf;
		cadena_scenario::Property cProperty_1d0;
		cadena_scenario::ESSConnection eSSConnection_1d1;
	};

	std::list< Match> _matches;
};

class RefreshType_1d8
{
public:
	void operator()( const Packets_t& cPropertys_1d9, const Packets_t& pAssemblys_1db, const Packets_t& pPropertys_1dd, Packets_t& pAssemblys_1df, Packets_t& pPropertys_1e0, Packets_t& cPropertys_1e1);

protected:
	void callDeleteCurrentType_2f0( const Packets_t& propertys_2bc, const Packets_t& componentAssemblys_2bf, const Packets_t& cPropertys_2c2);
	void callTransferType_2f4( const Packets_t& cPropertys_1e6, const Packets_t& pPropertys_1e8, const Packets_t& pAssemblys_1ea);

private:
	Packets_t* _pAssembly_1e2;
	Packets_t* _pProperty_1e3;
	Packets_t* _cProperty_1e4;
};

class TransferType_1e5
{
public:
	void operator()( const Packets_t& cPropertys_1e6, const Packets_t& pPropertys_1e8, const Packets_t& pAssemblys_1ea, Packets_t& cPropertys_1ec, Packets_t& pPropertys_1ed, Packets_t& pAssemblys_1ee);

protected:
	void callTypeIsString_2af( const Packets_t& cPropertys_271, const Packets_t& componentAssemblys_273, const Packets_t& pPropertys_275);
	void callTypeIsInteger_2b3( const Packets_t& componentAssemblys_1f3, const Packets_t& cPropertys_1f5, const Packets_t& pPropertys_1f7);
	void callTypeIsBoolean_2b7( const Packets_t& pPropertys_232, const Packets_t& componentAssemblys_234, const Packets_t& cPropertys_236);

private:
	Packets_t* _cProperty_1ef;
	Packets_t* _pProperty_1f0;
	Packets_t* _pAssembly_1f1;
};

class TypeIsInteger_1f2
{
public:
	void operator()( const Packets_t& componentAssemblys_1f3, const Packets_t& cPropertys_1f5, const Packets_t& pPropertys_1f7);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_1fd, const Udm::Object& cProperty_206, const Udm::Object& pProperty_20f);
	bool isGuardTrue( const Udm::Object& CProperty, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& LongInteger, const Udm::Object& PProperty, const Udm::Object& PredefinedTypes, const Udm::Object& RootFolder);
	void processInputPackets( const Packets_t& componentAssemblys_1f3, const Packets_t& cPropertys_1f5, const Packets_t& pPropertys_1f7);
	bool patternMatcher( const Udm::Object& componentAssembly_1fb, const Udm::Object& cProperty_204, const Udm::Object& pProperty_20d);
	void effector();
	void outputAppender();

private:
	Packets_t _componentAssembly_1f9;
	Packets_t _cProperty_202;
	Packets_t _pProperty_20b;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_220;
		PICML::LongInteger longInteger_221;
		PICML::ComponentImplementationContainer componentImplementationContainer_222;
		cadena_scenario::Property cProperty_223;
		PICML::ComponentImplementations componentImplementations_224;
		PICML::RootFolder rootFolder_225;
		PICML::Property pProperty_226;
		PICML::PredefinedTypes predefinedTypes_227;
	};

	std::list< Match> _matches;
};

class TypeIsBoolean_231
{
public:
	void operator()( const Packets_t& pPropertys_232, const Packets_t& componentAssemblys_234, const Packets_t& cPropertys_236);

protected:
	bool isInputUnique( const Udm::Object& pProperty_23c, const Udm::Object& componentAssembly_245, const Udm::Object& cProperty_24e);
	bool isGuardTrue( const Udm::Object& Boolean, const Udm::Object& CProperty, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& PProperty, const Udm::Object& PredefinedTypes, const Udm::Object& RootFolder);
	void processInputPackets( const Packets_t& pPropertys_232, const Packets_t& componentAssemblys_234, const Packets_t& cPropertys_236);
	bool patternMatcher( const Udm::Object& pProperty_23a, const Udm::Object& componentAssembly_243, const Udm::Object& cProperty_24c);
	void effector();
	void outputAppender();

private:
	Packets_t _pProperty_238;
	Packets_t _componentAssembly_241;
	Packets_t _cProperty_24a;
	class Match
	{
	public:
		PICML::Boolean boolean_25f;
		PICML::PredefinedTypes predefinedTypes_260;
		PICML::RootFolder rootFolder_261;
		PICML::ComponentImplementationContainer componentImplementationContainer_262;
		PICML::ComponentImplementations componentImplementations_263;
		PICML::Property pProperty_264;
		PICML::ComponentAssembly componentAssembly_265;
		cadena_scenario::Property cProperty_266;
	};

	std::list< Match> _matches;
};

class TypeIsString_270
{
public:
	void operator()( const Packets_t& cPropertys_271, const Packets_t& componentAssemblys_273, const Packets_t& pPropertys_275);

protected:
	bool isInputUnique( const Udm::Object& cProperty_27b, const Udm::Object& componentAssembly_284, const Udm::Object& pProperty_28d);
	bool isGuardTrue( const Udm::Object& CProperty, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& PProperty, const Udm::Object& PredefinedTypes, const Udm::Object& RootFolder, const Udm::Object& String);
	void processInputPackets( const Packets_t& cPropertys_271, const Packets_t& componentAssemblys_273, const Packets_t& pPropertys_275);
	bool patternMatcher( const Udm::Object& cProperty_279, const Udm::Object& componentAssembly_282, const Udm::Object& pProperty_28b);
	void effector();
	void outputAppender();

private:
	Packets_t _cProperty_277;
	Packets_t _componentAssembly_280;
	Packets_t _pProperty_289;
	class Match
	{
	public:
		PICML::PredefinedTypes predefinedTypes_29e;
		PICML::String string_29f;
		cadena_scenario::Property cProperty_2a0;
		PICML::RootFolder rootFolder_2a1;
		PICML::ComponentImplementationContainer componentImplementationContainer_2a2;
		PICML::ComponentAssembly componentAssembly_2a3;
		PICML::ComponentImplementations componentImplementations_2a4;
		PICML::Property pProperty_2a5;
	};

	std::list< Match> _matches;
};

class DeleteCurrentType_2bb
{
public:
	void operator()( const Packets_t& propertys_2bc, const Packets_t& componentAssemblys_2bf, const Packets_t& cPropertys_2c2, Packets_t& propertys_2be, Packets_t& componentAssemblys_2c1, Packets_t& cPropertys_2c4);

protected:
	bool isInputUnique( const Udm::Object& property_2cc, const Udm::Object& componentAssembly_2d5, const Udm::Object& cProperty_2de);
	void processInputPackets( const Packets_t& propertys_2bc, const Packets_t& componentAssemblys_2bf, const Packets_t& cPropertys_2c2);
	bool patternMatcher( const Udm::Object& property_2ca, const Udm::Object& componentAssembly_2d3, const Udm::Object& cProperty_2dc);
	void effector();
	void outputAppender( const PICML::Property& property_2ea, const PICML::ComponentAssembly& componentAssembly_2ec, const cadena_scenario::Property& cProperty_2ee);
	void forwardInputs();

private:
	Packets_t* _property_2c5;
	Packets_t* _componentAssembly_2c6;
	Packets_t* _cProperty_2c7;
	Packets_t _property_2c8;
	Packets_t _componentAssembly_2d1;
	Packets_t _cProperty_2da;
	class Match
	{
	public:
		PICML::Property property_2e6;
		PICML::DataType dataType_2e7;
		PICML::ComponentAssembly componentAssembly_2e8;
		cadena_scenario::Property cProperty_2e9;
	};

	std::list< Match> _matches;
};

class EnumerateComponentProperties_2f8
{
public:
	void operator()( const Packets_t& componentAssemblys_2f9, const Packets_t& scenarios_2fc, Packets_t& componentAssemblys_2fb, Packets_t& propertys_2fe, Packets_t& cPropertys_2ff);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_307, const Udm::Object& scenario_310);
	void processInputPackets( const Packets_t& componentAssemblys_2f9, const Packets_t& scenarios_2fc);
	bool patternMatcher( const Udm::Object& componentAssembly_305, const Udm::Object& scenario_30e);
	void effector();
	void outputAppender( const PICML::ComponentAssembly& componentAssembly_321, const PICML::Property& property_323, const cadena_scenario::Property& cProperty_325);

private:
	Packets_t* _componentAssembly_300;
	Packets_t* _property_301;
	Packets_t* _cProperty_302;
	Packets_t _componentAssembly_303;
	Packets_t _scenario_30c;
	class Match
	{
	public:
		cadena_scenario::ComponentInstance componentInstance_31c;
		PICML::ComponentAssembly componentAssembly_31d;
		cadena_scenario::Scenario scenario_31e;
		PICML::Property property_31f;
		cadena_scenario::Property cProperty_320;
	};

	std::list< Match> _matches;
};

class TransferValue_327
{
public:
	void operator()( const Packets_t& cPropertys_328, const Packets_t& pPropertys_32a);

protected:
	bool isInputUnique( const Udm::Object& cProperty_330, const Udm::Object& pProperty_339);
	void processInputPackets( const Packets_t& cPropertys_328, const Packets_t& pPropertys_32a);
	bool patternMatcher( const Udm::Object& cProperty_32e, const Udm::Object& pProperty_337);
	void effector();
	void outputAppender();

private:
	Packets_t _cProperty_32c;
	Packets_t _pProperty_335;
	class Match
	{
	public:
		cadena_scenario::Property cProperty_33e;
		PICML::Property pProperty_33f;
	};

	std::list< Match> _matches;
};

class Create_and_Set_Emit_Invoke_Properties_34d
{
public:
	void operator()( const Packets_t& cScenarios_34e, const Packets_t& pAssemblys_350);

protected:
	void callFind_Invoke_Properties_4b4( const Packets_t& scenarios_388);
	void callFind_Emit_Properties_4b6( const Packets_t& scenarios_47e);
	void callDumpEIValue_4b8( const Packets_t& pSlavePorts_3be, const Packets_t& pMasterPorts_3c0, const Packets_t& cPropertys_3c2, const Packets_t& pCEIPropertiess_3c4, const Packets_t& pSlaveComponents_3c6);
	void callSet_CEIProperties_DataType_4be( const Packets_t& ports_353, const Packets_t& pPropertys_355);
};

class Set_CEIProperties_DataType_352
{
public:
	void operator()( const Packets_t& ports_353, const Packets_t& pPropertys_355);

protected:
	bool isInputUnique( const Udm::Object& port_35b, const Udm::Object& pProperty_364);
	void processInputPackets( const Packets_t& ports_353, const Packets_t& pPropertys_355);
	bool patternMatcher( const Udm::Object& port_359, const Udm::Object& pProperty_362);
	void effector();
	void outputAppender();

private:
	Packets_t _port_357;
	Packets_t _pProperty_360;
	class Match
	{
	public:
		PICML::Component component_379;
		PICML::Port port_37a;
		PICML::ComponentImplementationContainer componentImplementationContainer_37b;
		PICML::RootFolder rootFolder_37c;
		PICML::String string_37d;
		PICML::Property pProperty_37e;
		PICML::ComponentAssembly componentAssembly_37f;
		PICML::PredefinedTypes predefinedTypes_380;
		PICML::ComponentImplementations componentImplementations_381;
	};

	std::list< Match> _matches;
};

class Find_Invoke_Properties_383
{
public:
	void operator()( const Packets_t& scenarios_388, Packets_t& providedRequestPorts_384, Packets_t& requiredRequestPorts_385, Packets_t& pSlaveComponents_386, Packets_t& pPropertys_387, Packets_t& cPropertys_38a);

protected:
	bool isInputUnique( const Udm::Object& scenario_394);
	void processInputPackets( const Packets_t& scenarios_388);
	bool patternMatcher( const Udm::Object& scenario_392);
	void effector();
	void outputAppender( const PICML::ProvidedRequestPort& providedRequestPort_3b3, const PICML::RequiredRequestPort& requiredRequestPort_3b5, const PICML::Component& pSlaveComponent_3b7, const PICML::Property& pProperty_3b9, const cadena_scenario::Property& cProperty_3bb);

private:
	Packets_t* _providedRequestPort_38b;
	Packets_t* _requiredRequestPort_38c;
	Packets_t* _pSlaveComponent_38d;
	Packets_t* _pProperty_38e;
	Packets_t* _cProperty_38f;
	Packets_t _scenario_390;
	class Match
	{
	public:
		PICML::ProvidedRequestPort providedRequestPort_3a8;
		PICML::RequiredRequestPort requiredRequestPort_3a9;
		PICML::invoke invoke_3aa;
		cadena_scenario::FRConnection fRConnection_3ab;
		PICML::Component pSlaveComponent_3ac;
		PICML::Component pMasterComponent_3ad;
		cadena_scenario::Scenario scenario_3ae;
		cadena_scenario::Property cProperty_3af;
		PICML::ComponentAssembly componentAssembly_3b0;
	};

	std::list< Match> _matches;
};

class DumpEIValue_3bd
{
public:
	void operator()( const Packets_t& pSlavePorts_3be, const Packets_t& pMasterPorts_3c0, const Packets_t& cPropertys_3c2, const Packets_t& pCEIPropertiess_3c4, const Packets_t& pSlaveComponents_3c6, Packets_t& cPropertys_3c8, Packets_t& pCEIPropertiess_3c9, Packets_t& pMasterPorts_3ca, Packets_t& pSlavePorts_3cb, Packets_t& pSlaveComponents_3cc);

protected:
	void executeOne( const Packets_t& pSlavePorts_3be, const Packets_t& pMasterPorts_3c0, const Packets_t& cPropertys_3c2, const Packets_t& pCEIPropertiess_3c4, const Packets_t& pSlaveComponents_3c6);
	bool isInputUnique( const Udm::Object& pSlavePort_3d4, const Udm::Object& pMasterPort_3db, const Udm::Object& cProperty_3e2, const Udm::Object& pCEIProperties_3e9, const Udm::Object& pSlaveComponent_3f0);
	void callCopyTo_XProperty_46f( const Packets_t& pSlavePorts_3f6, const Packets_t& pMasterPorts_3f8, const Packets_t& pSlaveComponents_3fb, const Packets_t& pPropertys_3fd, const Packets_t& cPropertys_400);
	void callCopyHierarchy_DumpToDisk_ReadFile_Transfer_475( const Packets_t& rootContainers_453, const Packets_t& pPropertys_456);
	void callDestroyEverything_478( const Packets_t& rootContainers_442);

private:
	Packets_t* _cProperty_3cd;
	Packets_t* _pCEIProperties_3ce;
	Packets_t* _pMasterPort_3cf;
	Packets_t* _pSlavePort_3d0;
	Packets_t* _pSlaveComponent_3d1;
	Packets_t _pSlavePort_3d2;
	Packets_t _pMasterPort_3d9;
	Packets_t _cProperty_3e0;
	Packets_t _pCEIProperties_3e7;
	Packets_t _pSlaveComponent_3ee;
};

class CopyTo_XProperty_3f5
{
public:
	void operator()( const Packets_t& pSlavePorts_3f6, const Packets_t& pMasterPorts_3f8, const Packets_t& pSlaveComponents_3fb, const Packets_t& pPropertys_3fd, const Packets_t& cPropertys_400, Packets_t& rootContainers_3fa, Packets_t& pPropertys_3ff);

protected:
	bool isInputUnique( const Udm::Object& pSlavePort_408, const Udm::Object& pMasterPort_411, const Udm::Object& pSlaveComponent_41a, const Udm::Object& pProperty_423, const Udm::Object& cProperty_42c);
	void processInputPackets( const Packets_t& pSlavePorts_3f6, const Packets_t& pMasterPorts_3f8, const Packets_t& pSlaveComponents_3fb, const Packets_t& pPropertys_3fd, const Packets_t& cPropertys_400);
	bool patternMatcher( const Udm::Object& pSlavePort_406, const Udm::Object& pMasterPort_40f, const Udm::Object& pSlaveComponent_418, const Udm::Object& pProperty_421, const Udm::Object& cProperty_42a);
	void effector();
	void outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::RootContainer& rootContainer_43d, const PICML::Property& pProperty_43f);

private:
	Packets_t* _rootContainer_402;
	Packets_t* _pProperty_403;
	Packets_t _pSlavePort_404;
	Packets_t _pMasterPort_40d;
	Packets_t _pSlaveComponent_416;
	Packets_t _pProperty_41f;
	Packets_t _cProperty_428;
	class Match
	{
	public:
		PICML::Port pSlavePort_434;
		PICML::Port pMasterPort_435;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_436;
		PICML::ComponentAssembly componentAssembly_437;
		PICML::Component pSlaveComponent_438;
		PICML::Property pProperty_439;
		cadena_scenario::Property cProperty_43a;
	};

	std::list< Match> _matches;
};

class DestroyEverything_441
{
public:
	void operator()( const Packets_t& rootContainers_442);

protected:
	bool isInputUnique( const Udm::Object& rootContainer_448);
	void processInputPackets( const Packets_t& rootContainers_442);
	bool patternMatcher( const Udm::Object& rootContainer_446);
	void effector();
	void outputAppender();

private:
	Packets_t _rootContainer_444;
	class Match
	{
	public:
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_450;
		PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector connectionSelector_451;
	};

	std::list< Match> _matches;
};

class CopyHierarchy_DumpToDisk_ReadFile_Transfer_452
{
public:
	void operator()( const Packets_t& rootContainers_453, const Packets_t& pPropertys_456, Packets_t& rootContainers_455);

protected:
	bool isInputUnique( const Udm::Object& rootContainer_45d, const Udm::Object& pProperty_466);
	void processInputPackets( const Packets_t& rootContainers_453, const Packets_t& pPropertys_456);
	bool patternMatcher( const Udm::Object& rootContainer_45b, const Udm::Object& pProperty_464);
	void effector();
	void outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::RootContainer& rootContainer_46d);
	void forwardInputs();

private:
	Packets_t* _rootContainer_458;
	Packets_t _rootContainer_459;
	Packets_t _pProperty_462;
	class Match
	{
	public:
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_46b;
		PICML::Property pProperty_46c;
	};

	std::list< Match> _matches;
};

class Find_Emit_Properties_47a
{
public:
	void operator()( const Packets_t& scenarios_47e, Packets_t& pSlaveComponents_47b, Packets_t& inEventPorts_47c, Packets_t& outEventPorts_47d, Packets_t& cPropertys_480, Packets_t& pPropertys_481);

protected:
	bool isInputUnique( const Udm::Object& scenario_48b);
	void processInputPackets( const Packets_t& scenarios_47e);
	bool patternMatcher( const Udm::Object& scenario_489);
	void effector();
	void outputAppender( const PICML::Component& pSlaveComponent_4aa, const PICML::InEventPort& inEventPort_4ac, const PICML::OutEventPort& outEventPort_4ae, const cadena_scenario::Property& cProperty_4b0, const PICML::Property& pProperty_4b2);

private:
	Packets_t* _pSlaveComponent_482;
	Packets_t* _inEventPort_483;
	Packets_t* _outEventPort_484;
	Packets_t* _cProperty_485;
	Packets_t* _pProperty_486;
	Packets_t _scenario_487;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_49f;
		PICML::Component pSlaveComponent_4a0;
		PICML::Component pMasterComponent_4a1;
		PICML::InEventPort inEventPort_4a2;
		PICML::OutEventPort outEventPort_4a3;
		PICML::emit emit_4a4;
		cadena_scenario::Scenario scenario_4a5;
		cadena_scenario::Property cProperty_4a6;
		cadena_scenario::ESSConnection eSSConnection_4a7;
	};

	std::list< Match> _matches;
};

class CreateNormalProperties_4c1
{
public:
	void operator()( const Packets_t& pAssemblys_4c2, const Packets_t& cScenarios_4c4, Packets_t& pAssemblys_4c6, Packets_t& cScenarios_4c7);

protected:
	void callPublishConnectorProperty_Find_Unmatched_5d0( const Packets_t& scenarios_574);
	void callComponentProperties_Create_5d2( const Packets_t& scenarios_5b3);
	void callEnsure_CadenaProperties_Requirement_5d4( const Packets_t& pPublishConnectors_4cb, const Packets_t& cPropertys_4cd);
	void callCreate_PublishConnectorProperty_5d7( const Packets_t& cPropertys_596, const Packets_t& requirements_598);

private:
	Packets_t* _pAssembly_4c8;
	Packets_t* _cScenario_4c9;
};

class Ensure_CadenaProperties_Requirement_4ca
{
public:
	void operator()( const Packets_t& pPublishConnectors_4cb, const Packets_t& cPropertys_4cd, Packets_t& pPublishConnectors_4cf, Packets_t& cPropertys_4d0, Packets_t& pRequirements_4d1);

protected:
	void callTest_56c( const Packets_t& pPublishConnectors_4d6, const Packets_t& cPropertys_4d8);
	void callCreate_CadenaProperties_Requirement_56f( const Packets_t& propertys_543, const Packets_t& publishConnectors_547);

private:
	Packets_t* _pPublishConnector_4d2;
	Packets_t* _cProperty_4d3;
	Packets_t* _pRequirement_4d4;
};

class Test_4d5
{
public:
	void operator()( const Packets_t& pPublishConnectors_4d6, const Packets_t& cPropertys_4d8, Packets_t& pPublishConnectors_4da, Packets_t& cPropertiess_4db, Packets_t& pPublishConnectors_4dc, Packets_t& cPropertys_4dd, Packets_t& pRequirements_4de);

protected:
	void executeOne( const Packets_t& pPublishConnectors_4d6, const Packets_t& cPropertys_4d8);
	bool isInputUnique( const Udm::Object& pPublishConnector_4e6, const Udm::Object& cProperty_4ed);

private:
	Packets_t* _pPublishConnector_4df;
	Packets_t* _cProperties_4e0;
	Packets_t* _pPublishConnector_4e1;
	Packets_t* _cProperty_4e2;
	Packets_t* _pRequirement_4e3;
	Packets_t _pPublishConnector_4e4;
	Packets_t _cProperty_4eb;
};

class RequirementExists_4f2
{
public:
	bool operator()( const Packets_t& propertys_4f3, const Packets_t& publishConnectors_4f6, Packets_t& propertys_4f5, Packets_t& publishConnectors_4f8, Packets_t& requirements_4f9);

protected:
	bool isInputUnique( const Udm::Object& property_501, const Udm::Object& publishConnector_50a);
	bool isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& Property, const Udm::Object& PublishConnector, const Udm::Object& Requirement);
	void processInputPackets( const Packets_t& propertys_4f3, const Packets_t& publishConnectors_4f6);
	bool patternMatcher( const Udm::Object& property_4ff, const Udm::Object& publishConnector_508);
	void outputAppender( const cadena_scenario::Property& property_51b, const PICML::PublishConnector& publishConnector_51d, const PICML::Requirement& requirement_51f);

private:
	Packets_t* _property_4fa;
	Packets_t* _publishConnector_4fb;
	Packets_t* _requirement_4fc;
	Packets_t _property_4fd;
	Packets_t _publishConnector_506;
	class Match
	{
	public:
		cadena_scenario::Property property_513;
		PICML::AssemblyDeployRequirement assemblyDeployRequirement_514;
		PICML::PublishConnector publishConnector_515;
		PICML::Requirement requirement_516;
	};

	std::list< Match> _matches;
};

class RequirementDoesNotExist_521
{
public:
	bool operator()( const Packets_t& publishConnectors_522, const Packets_t& propertys_525, Packets_t& publishConnectors_524, Packets_t& propertys_527);

protected:
	bool isInputUnique( const Udm::Object& publishConnector_52e, const Udm::Object& property_537);
	void processInputPackets( const Packets_t& publishConnectors_522, const Packets_t& propertys_525);
	bool patternMatcher( const Udm::Object& publishConnector_52c, const Udm::Object& property_535);
	void outputAppender( const PICML::PublishConnector& publishConnector_53e, const cadena_scenario::Property& property_540);

private:
	Packets_t* _publishConnector_528;
	Packets_t* _property_529;
	Packets_t _publishConnector_52a;
	Packets_t _property_533;
	class Match
	{
	public:
		PICML::PublishConnector publishConnector_53c;
		cadena_scenario::Property property_53d;
	};

	std::list< Match> _matches;
};

class Create_CadenaProperties_Requirement_542
{
public:
	void operator()( const Packets_t& propertys_543, const Packets_t& publishConnectors_547, Packets_t& propertys_545, Packets_t& requirements_546, Packets_t& publishConnectors_549);

protected:
	bool isInputUnique( const Udm::Object& property_551, const Udm::Object& publishConnector_55a);
	void processInputPackets( const Packets_t& propertys_543, const Packets_t& publishConnectors_547);
	bool patternMatcher( const Udm::Object& property_54f, const Udm::Object& publishConnector_558);
	void effector();
	void outputAppender( const cadena_scenario::Property& property_566, const PICML::Requirement& requirement_568, const PICML::PublishConnector& publishConnector_56a);

private:
	Packets_t* _property_54a;
	Packets_t* _requirement_54b;
	Packets_t* _publishConnector_54c;
	Packets_t _property_54d;
	Packets_t _publishConnector_556;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_561;
		cadena_scenario::Property property_562;
		PICML::PublishConnector publishConnector_563;
	};

	std::list< Match> _matches;
};

class PublishConnectorProperty_Find_Unmatched_572
{
public:
	void operator()( const Packets_t& scenarios_574, Packets_t& cPropertys_573, Packets_t& publishConnectors_576);

protected:
	bool isInputUnique( const Udm::Object& scenario_57d);
	void processInputPackets( const Packets_t& scenarios_574);
	bool patternMatcher( const Udm::Object& scenario_57b);
	void effector();
	void outputAppender( const cadena_scenario::Property& cProperty_591, const PICML::PublishConnector& publishConnector_593);

private:
	Packets_t* _cProperty_577;
	Packets_t* _publishConnector_578;
	Packets_t _scenario_579;
	class Match
	{
	public:
		PICML::Property pProperty_58c;
		cadena_scenario::ESSConnection eSSConnection_58d;
		cadena_scenario::Property cProperty_58e;
		cadena_scenario::Scenario scenario_58f;
		PICML::PublishConnector publishConnector_590;
	};

	std::list< Match> _matches;
};

class Create_PublishConnectorProperty_595
{
public:
	void operator()( const Packets_t& cPropertys_596, const Packets_t& requirements_598);

protected:
	bool isInputUnique( const Udm::Object& cProperty_59e, const Udm::Object& requirement_5a7);
	void processInputPackets( const Packets_t& cPropertys_596, const Packets_t& requirements_598);
	bool patternMatcher( const Udm::Object& cProperty_59c, const Udm::Object& requirement_5a5);
	void effector();
	void outputAppender();

private:
	Packets_t _cProperty_59a;
	Packets_t _requirement_5a3;
	class Match
	{
	public:
		cadena_scenario::Property cProperty_5af;
		PICML::Property pProperty_5b0;
		PICML::Requirement requirement_5b1;
	};

	std::list< Match> _matches;
};

class ComponentProperties_Create_5b2
{
public:
	void operator()( const Packets_t& scenarios_5b3);

protected:
	bool isInputUnique( const Udm::Object& scenario_5b9);
	void processInputPackets( const Packets_t& scenarios_5b3);
	bool patternMatcher( const Udm::Object& scenario_5b7);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_5b5;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_5c8;
		cadena_scenario::Scenario scenario_5c9;
		cadena_scenario::ComponentInstance componentInstance_5ca;
		cadena_scenario::Property cProperty_5cb;
		PICML::Component component_5cc;
		PICML::Property pProperty1_5cd;
	};

	std::list< Match> _matches;
};

class DestroyProperties_5da
{
public:
	void operator()( const Packets_t& pAssemblys_5db, const Packets_t& cScenarios_5dd, Packets_t& pAssemblys_5df, Packets_t& cScenarios_5e0);

protected:
	void callDestroyComponentProperties_691( const Packets_t& componentAssemblys_5e4);
	void callDestroyCadenaEIProperties_693( const Packets_t& componentAssemblys_620);
	void callDestroyPublishConnectorProperties_695( const Packets_t& componentAssemblys_651);

private:
	Packets_t* _pAssembly_5e1;
	Packets_t* _cScenario_5e2;
};

class DestroyComponentProperties_5e3
{
public:
	void operator()( const Packets_t& componentAssemblys_5e4);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_5ea);
	bool isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& CProperty, const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& DataType, const Udm::Object& PProperty, const Udm::Object& PredefinedType);
	void processInputPackets( const Packets_t& componentAssemblys_5e4);
	bool patternMatcher( const Udm::Object& componentAssembly_5e8);
	void effector();
	void outputAppender();

private:
	Packets_t _componentAssembly_5e6;
	class Match
	{
	public:
		PICML::DataType dataType_5fb;
		PICML::PredefinedType predefinedType_5fc;
		PICML::Property pProperty_5fd;
		cadena_scenario::Property cProperty_5fe;
		PICML::Component component_5ff;
		PICML::ComponentAssembly componentAssembly_600;
		PICML::AssemblyConfigProperty assemblyConfigProperty_601;
	};

	std::list< Match> _matches;
};

class DestroyCadenaEIProperties_61f
{
public:
	void operator()( const Packets_t& componentAssemblys_620);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_626);
	bool isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& PProperty);
	void processInputPackets( const Packets_t& componentAssemblys_620);
	bool patternMatcher( const Udm::Object& componentAssembly_624);
	void effector();
	void outputAppender();

private:
	Packets_t _componentAssembly_622;
	class Match
	{
	public:
		PICML::Property pProperty_632;
		PICML::AssemblyConfigProperty assemblyConfigProperty_633;
		PICML::ComponentAssembly componentAssembly_634;
		PICML::Component component_635;
	};

	std::list< Match> _matches;
};

class DestroyPublishConnectorProperties_650
{
public:
	void operator()( const Packets_t& componentAssemblys_651);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_657);
	bool isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& CProperty, const Udm::Object& ComponentAssembly, const Udm::Object& DataType, const Udm::Object& PProperty, const Udm::Object& PredefinedType, const Udm::Object& PublishConnector, const Udm::Object& Requirement);
	void processInputPackets( const Packets_t& componentAssemblys_651);
	bool patternMatcher( const Udm::Object& componentAssembly_655);
	void effector();
	void outputAppender();

private:
	Packets_t _componentAssembly_653;
	class Match
	{
	public:
		PICML::AssemblyDeployRequirement assemblyDeployRequirement_66b;
		PICML::Requirement requirement_66c;
		PICML::PublishConnector publishConnector_66d;
		PICML::PredefinedType predefinedType_66e;
		PICML::DataType dataType_66f;
		PICML::Property pProperty_670;
		PICML::ComponentAssembly componentAssembly_671;
		cadena_scenario::Property cProperty_672;
	};

	std::list< Match> _matches;
};

class Associate_Ports_6a3
{
public:
	void operator()( const Packets_t& pAssemblys_6a4, const Packets_t& cScenarios_6a6, Packets_t& pAssemblys_6a8, Packets_t& cScenarios_6a9);

protected:
	void callMatch_Components_6ec( const Packets_t& scenarios_6af);
	void callAssociate_Ports_rule_6ee( const Packets_t& components_6c8, const Packets_t& componentInstances_6ca);

private:
	Packets_t* _pAssembly_6aa;
	Packets_t* _cScenario_6ab;
};

class Match_Components_6ac
{
public:
	void operator()( const Packets_t& scenarios_6af, Packets_t& componentInstances_6ad, Packets_t& components_6ae);

protected:
	bool isInputUnique( const Udm::Object& scenario_6b7);
	void processInputPackets( const Packets_t& scenarios_6af);
	bool patternMatcher( const Udm::Object& scenario_6b5);
	void effector();
	void outputAppender( const cadena_scenario::ComponentInstance& componentInstance_6c3, const PICML::Component& component_6c5);

private:
	Packets_t* _componentInstance_6b1;
	Packets_t* _component_6b2;
	Packets_t _scenario_6b3;
	class Match
	{
	public:
		cadena_scenario::ComponentInstance componentInstance_6c0;
		PICML::Component component_6c1;
		cadena_scenario::Scenario scenario_6c2;
	};

	std::list< Match> _matches;
};

class Associate_Ports_rule_6c7
{
public:
	void operator()( const Packets_t& components_6c8, const Packets_t& componentInstances_6ca);

protected:
	bool isInputUnique( const Udm::Object& component_6d0, const Udm::Object& componentInstance_6d9);
	bool isGuardTrue( const Udm::Object& Component, const Udm::Object& ComponentInstance, const Udm::Object& ComponentPort, const Udm::Object& Port);
	void processInputPackets( const Packets_t& components_6c8, const Packets_t& componentInstances_6ca);
	bool patternMatcher( const Udm::Object& component_6ce, const Udm::Object& componentInstance_6d7);
	void effector();
	void outputAppender();

private:
	Packets_t _component_6cc;
	Packets_t _componentInstance_6d5;
	class Match
	{
	public:
		PICML::Component component_6e4;
		PICML::Port port_6e5;
		cadena_scenario::ComponentPort componentPort_6e6;
		cadena_scenario::ComponentInstance componentInstance_6e7;
	};

	std::list< Match> _matches;
};

class CreateDestroy_Components_n_PublishConnectors_6f1
{
public:
	void operator()( const Packets_t& pAssemblys_6f2, const Packets_t& cScenarios_6f4, Packets_t& pAssemblys_6f6, Packets_t& cScenarios_6f7);

protected:
	void callCreatePublishConnectors_step1_918( const Packets_t& cScenarios_7aa, const Packets_t& pAssemblys_7ac);
	void callDestroyPublishConnectors_91b( const Packets_t& componentAssemblys_7cd);
	void callFindComponents2BDeleted_91d( const Packets_t& componentAssemblys_8dc);
	void callCreateComponents_step1_91f( const Packets_t& scenarios_8f3, const Packets_t& componentAssemblys_8f5);
	void callCreatePublishConnectors_step2_922( const Packets_t& cScenarios_782, const Packets_t& pAssemblys_784);
	void callDestroyOrphanPropertiesAndDeleteComponent_925( const Packets_t& pComponentToBeDeleteds_729);
	void callFindFirstPackage_927( const Packets_t& componentAssemblys_8a2, const Packets_t& componentInstances_8a5);
	void callCreatePublishConnectors_step3_92a( const Packets_t& pAssemblys_6fb, const Packets_t& cScenarios_6fd);
	void callMatchAPackage_92d( const Packets_t& componentAssemblys_850, const Packets_t& packages_853, const Packets_t& componentInstances_856);
	void callFinalPackage_InstantiateComponent_931( const Packets_t& componentInstances_7e6, const Packets_t& packages_7e9, const Packets_t& componentAssemblys_7eb);
	void callFindSubPackage_935( const Packets_t& componentInstances_81b, const Packets_t& packages_81f, const Packets_t& componentAssemblys_821);
	void callAssociateComponentsNow_939( const Packets_t& componentAssemblys_881, const Packets_t& componentInstances_883);
	void callMatchAPackage_ref_93c( const Packets_t& componentAssemblys_850, const Packets_t& packages_853, const Packets_t& componentInstances_856);

private:
	Packets_t* _pAssembly_6f8;
	Packets_t* _cScenario_6f9;
};

class CreatePublishConnectors_step3_6fa
{
public:
	void operator()( const Packets_t& pAssemblys_6fb, const Packets_t& cScenarios_6fd);

protected:
	void callCreatePublishConnectors_step3_rule_725( const Packets_t& scenarios_700, const Packets_t& componentAssemblys_702);
};

class CreatePublishConnectors_step3_rule_6ff
{
public:
	void operator()( const Packets_t& scenarios_700, const Packets_t& componentAssemblys_702);

protected:
	bool isInputUnique( const Udm::Object& scenario_708, const Udm::Object& componentAssembly_711);
	bool isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ESSConnection, const Udm::Object& PublishConnector, const Udm::Object& Scenario);
	void processInputPackets( const Packets_t& scenarios_700, const Packets_t& componentAssemblys_702);
	bool patternMatcher( const Udm::Object& scenario_706, const Udm::Object& componentAssembly_70f);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_704;
	Packets_t _componentAssembly_70d;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_71c;
		PICML::PublishConnector publishConnector_71d;
		PICML::ComponentAssembly componentAssembly_71e;
		cadena_scenario::ESSConnection eSSConnection_71f;
	};

	std::list< Match> _matches;
};

class DestroyOrphanPropertiesAndDeleteComponent_728
{
public:
	void operator()( const Packets_t& pComponentToBeDeleteds_729);

protected:
	void executeOne( const Packets_t& pComponentToBeDeleteds_729);
	bool isInputUnique( const Udm::Object& pComponentToBeDeleted_72d);
	void callDestroyOrphanProperties_77d( const Packets_t& components_733);
	void callDestroyComponent_77f( const Packets_t& components_76b);

private:
	Packets_t _pComponentToBeDeleted_72b;
};

class DestroyOrphanProperties_732
{
public:
	void operator()( const Packets_t& components_733, Packets_t& components_735);

protected:
	bool isInputUnique( const Udm::Object& component_73b);
	bool isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& Component, const Udm::Object& DataType, const Udm::Object& PredefinedType, const Udm::Object& Property);
	void processInputPackets( const Packets_t& components_733);
	bool patternMatcher( const Udm::Object& component_739);
	void effector();
	void outputAppender( const PICML::Component& component_768);
	void forwardInputs();

private:
	Packets_t* _component_736;
	Packets_t _component_737;
	class Match
	{
	public:
		PICML::DataType dataType_748;
		PICML::PredefinedType predefinedType_749;
		PICML::AssemblyConfigProperty assemblyConfigProperty_74a;
		PICML::Property property_74b;
		PICML::Component component_74c;
	};

	std::list< Match> _matches;
};

class DestroyComponent_76a
{
public:
	void operator()( const Packets_t& components_76b);

protected:
	bool isInputUnique( const Udm::Object& component_771);
	void processInputPackets( const Packets_t& components_76b);
	bool patternMatcher( const Udm::Object& component_76f);
	void effector();
	void outputAppender();

private:
	Packets_t _component_76d;
	class Match
	{
	public:
		PICML::Component component_776;
	};

	std::list< Match> _matches;
};

class CreatePublishConnectors_step2_781
{
public:
	void operator()( const Packets_t& cScenarios_782, const Packets_t& pAssemblys_784, Packets_t& pAssemblys_786, Packets_t& cScenarios_787);

protected:
	void callCreatePublishConnectors_step2_rule_7a7( const Packets_t& scenarios_78b);

private:
	Packets_t* _pAssembly_788;
	Packets_t* _cScenario_789;
};

class CreatePublishConnectors_step2_rule_78a
{
public:
	void operator()( const Packets_t& scenarios_78b);

protected:
	bool isInputUnique( const Udm::Object& scenario_791);
	bool isGuardTrue( const Udm::Object& ESSConnection, const Udm::Object& EventSink, const Udm::Object& EventSource, const Udm::Object& Scenario);
	void processInputPackets( const Packets_t& scenarios_78b);
	bool patternMatcher( const Udm::Object& scenario_78f);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_78d;
	class Match
	{
	public:
		cadena_scenario::EventSource eventSource_79f;
		cadena_scenario::EventSink eventSink_7a0;
		cadena_scenario::Scenario scenario_7a1;
		cadena_scenario::ESSConnection eSSConnection_7a2;
	};

	std::list< Match> _matches;
};

class CreatePublishConnectors_step1_7a9
{
public:
	void operator()( const Packets_t& cScenarios_7aa, const Packets_t& pAssemblys_7ac, Packets_t& cScenarios_7ae, Packets_t& pAssemblys_7af);

protected:
	void callCreatePublishConnectors_step1_rule_7ca( const Packets_t& scenarios_7b3);

private:
	Packets_t* _cScenario_7b0;
	Packets_t* _pAssembly_7b1;
};

class CreatePublishConnectors_step1_rule_7b2
{
public:
	void operator()( const Packets_t& scenarios_7b3);

protected:
	bool isInputUnique( const Udm::Object& scenario_7b9);
	bool isGuardTrue( const Udm::Object& ESSConnection, const Udm::Object& PublishConnector, const Udm::Object& Scenario);
	void processInputPackets( const Packets_t& scenarios_7b3);
	bool patternMatcher( const Udm::Object& scenario_7b7);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_7b5;
	class Match
	{
	public:
		cadena_scenario::ESSConnection eSSConnection_7c4;
		cadena_scenario::Scenario scenario_7c5;
		PICML::PublishConnector publishConnector_7c6;
	};

	std::list< Match> _matches;
};

class DestroyPublishConnectors_7cc
{
public:
	void operator()( const Packets_t& componentAssemblys_7cd);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_7d3);
	void processInputPackets( const Packets_t& componentAssemblys_7cd);
	bool patternMatcher( const Udm::Object& componentAssembly_7d1);
	void effector();
	void outputAppender();

private:
	Packets_t _componentAssembly_7cf;
	class Match
	{
	public:
		cadena_scenario::ESSConnection eSSConnection_7dc;
		PICML::PublishConnector publishConnector_7dd;
		PICML::ComponentAssembly componentAssembly_7de;
	};

	std::list< Match> _matches;
};

class FinalPackage_InstantiateComponent_7e5
{
public:
	void operator()( const Packets_t& componentInstances_7e6, const Packets_t& packages_7e9, const Packets_t& componentAssemblys_7eb, Packets_t& componentInstances_7e8, Packets_t& componentAssemblys_7ed);

protected:
	bool isInputUnique( const Udm::Object& componentInstance_7f4, const Udm::Object& package_7fd, const Udm::Object& componentAssembly_806);
	bool isGuardTrue( const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentInstance, const Udm::Object& Package);
	void processInputPackets( const Packets_t& componentInstances_7e6, const Packets_t& packages_7e9, const Packets_t& componentAssemblys_7eb);
	bool patternMatcher( const Udm::Object& componentInstance_7f2, const Udm::Object& package_7fb, const Udm::Object& componentAssembly_804);
	void effector();
	void outputAppender( const cadena_scenario::ComponentInstance& componentInstance_816, const PICML::ComponentAssembly& componentAssembly_818);
	void forwardInputs();

private:
	Packets_t* _componentInstance_7ee;
	Packets_t* _componentAssembly_7ef;
	Packets_t _componentInstance_7f0;
	Packets_t _package_7f9;
	Packets_t _componentAssembly_802;
	class Match
	{
	public:
		cadena_scenario::ComponentInstance componentInstance_80e;
		PICML::Component component_80f;
		PICML::Package package_810;
		PICML::ComponentAssembly componentAssembly_811;
	};

	std::list< Match> _matches;
};

class FindSubPackage_81a
{
public:
	void operator()( const Packets_t& componentInstances_81b, const Packets_t& packages_81f, const Packets_t& componentAssemblys_821, Packets_t& componentInstances_81d, Packets_t& packages_81e, Packets_t& componentAssemblys_823);

protected:
	bool isInputUnique( const Udm::Object& componentInstance_82b, const Udm::Object& package_834, const Udm::Object& componentAssembly_83d);
	void processInputPackets( const Packets_t& componentInstances_81b, const Packets_t& packages_81f, const Packets_t& componentAssemblys_821);
	bool patternMatcher( const Udm::Object& componentInstance_829, const Udm::Object& package_832, const Udm::Object& componentAssembly_83b);
	void effector();
	void outputAppender( const cadena_scenario::ComponentInstance& componentInstance_849, const PICML::Package& package_84b, const PICML::ComponentAssembly& componentAssembly_84d);

private:
	Packets_t* _componentInstance_824;
	Packets_t* _package_825;
	Packets_t* _componentAssembly_826;
	Packets_t _componentInstance_827;
	Packets_t _package_830;
	Packets_t _componentAssembly_839;
	class Match
	{
	public:
		cadena_scenario::ComponentInstance componentInstance_845;
		PICML::Package package_846;
		PICML::Package package_847;
		PICML::ComponentAssembly componentAssembly_848;
	};

	std::list< Match> _matches;
};

class MatchAPackage_84f
{
public:
	void operator()( const Packets_t& componentAssemblys_850, const Packets_t& packages_853, const Packets_t& componentInstances_856, Packets_t& componentAssemblys_852, Packets_t& packages_855, Packets_t& componentInstances_858);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_860, const Udm::Object& package_869, const Udm::Object& componentInstance_872);
	void processInputPackets( const Packets_t& componentAssemblys_850, const Packets_t& packages_853, const Packets_t& componentInstances_856);
	bool patternMatcher( const Udm::Object& componentAssembly_85e, const Udm::Object& package_867, const Udm::Object& componentInstance_870);
	void effector();
	void outputAppender( const PICML::ComponentAssembly& componentAssembly_87a, const PICML::Package& package_87c, const cadena_scenario::ComponentInstance& componentInstance_87e);
	void forwardInputs();

private:
	Packets_t* _componentAssembly_859;
	Packets_t* _package_85a;
	Packets_t* _componentInstance_85b;
	Packets_t _componentAssembly_85c;
	Packets_t _package_865;
	Packets_t _componentInstance_86e;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_877;
		PICML::Package package_878;
		cadena_scenario::ComponentInstance componentInstance_879;
	};

	std::list< Match> _matches;
};

class AssociateComponentsNow_880
{
public:
	void operator()( const Packets_t& componentAssemblys_881, const Packets_t& componentInstances_883);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_889, const Udm::Object& componentInstance_892);
	bool isGuardTrue( const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentInstance);
	void processInputPackets( const Packets_t& componentAssemblys_881, const Packets_t& componentInstances_883);
	bool patternMatcher( const Udm::Object& componentAssembly_887, const Udm::Object& componentInstance_890);
	void effector();
	void outputAppender();

private:
	Packets_t _componentAssembly_885;
	Packets_t _componentInstance_88e;
	class Match
	{
	public:
		PICML::Component component_89a;
		PICML::ComponentAssembly componentAssembly_89b;
		cadena_scenario::ComponentInstance componentInstance_89c;
	};

	std::list< Match> _matches;
};

class FindFirstPackage_8a0
{
public:
	void operator()( const Packets_t& componentAssemblys_8a2, const Packets_t& componentInstances_8a5, Packets_t& packages_8a1, Packets_t& componentAssemblys_8a4, Packets_t& componentInstances_8a7);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_8af, const Udm::Object& componentInstance_8b8);
	void processInputPackets( const Packets_t& componentAssemblys_8a2, const Packets_t& componentInstances_8a5);
	bool patternMatcher( const Udm::Object& componentAssembly_8ad, const Udm::Object& componentInstance_8b6);
	void effector();
	void outputAppender( const PICML::Package& package_8d4, const PICML::ComponentAssembly& componentAssembly_8d6, const cadena_scenario::ComponentInstance& componentInstance_8d8);

private:
	Packets_t* _package_8a8;
	Packets_t* _componentAssembly_8a9;
	Packets_t* _componentInstance_8aa;
	Packets_t _componentAssembly_8ab;
	Packets_t _componentInstance_8b4;
	class Match
	{
	public:
		PICML::File file_8cc;
		PICML::Package package_8cd;
		PICML::InterfaceDefinitions interfaceDefinitions_8ce;
		PICML::ComponentImplementations componentImplementations_8cf;
		PICML::ComponentImplementationContainer componentImplementationContainer_8d0;
		PICML::RootFolder rootFolder_8d1;
		PICML::ComponentAssembly componentAssembly_8d2;
		cadena_scenario::ComponentInstance componentInstance_8d3;
	};

	std::list< Match> _matches;
};

class FindComponents2BDeleted_8da
{
public:
	void operator()( const Packets_t& componentAssemblys_8dc, Packets_t& components_8db);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_8e3);
	void processInputPackets( const Packets_t& componentAssemblys_8dc);
	bool patternMatcher( const Udm::Object& componentAssembly_8e1);
	void effector();
	void outputAppender( const PICML::Component& component_8ef);

private:
	Packets_t* _component_8de;
	Packets_t _componentAssembly_8df;
	class Match
	{
	public:
		PICML::Component component_8ec;
		cadena_scenario::ComponentInstance componentInstance_8ed;
		PICML::ComponentAssembly componentAssembly_8ee;
	};

	std::list< Match> _matches;
};

class CreateComponents_step1_8f1
{
public:
	void operator()( const Packets_t& scenarios_8f3, const Packets_t& componentAssemblys_8f5, Packets_t& componentInstances_8f2, Packets_t& componentAssemblys_8f7);

protected:
	bool isInputUnique( const Udm::Object& scenario_8fe, const Udm::Object& componentAssembly_907);
	void processInputPackets( const Packets_t& scenarios_8f3, const Packets_t& componentAssemblys_8f5);
	bool patternMatcher( const Udm::Object& scenario_8fc, const Udm::Object& componentAssembly_905);
	void effector();
	void outputAppender( const cadena_scenario::ComponentInstance& componentInstance_914, const PICML::ComponentAssembly& componentAssembly_916);

private:
	Packets_t* _componentInstance_8f8;
	Packets_t* _componentAssembly_8f9;
	Packets_t _scenario_8fa;
	Packets_t _componentAssembly_903;
	class Match
	{
	public:
		cadena_scenario::ComponentInstance componentInstance_910;
		cadena_scenario::Scenario scenario_911;
		PICML::Component component_912;
		PICML::ComponentAssembly componentAssembly_913;
	};

	std::list< Match> _matches;
};

class ReCreate_Connections_940
{
public:
	void operator()( const Packets_t& pAssemblys_941, const Packets_t& cScenarios_943, Packets_t& cScenarios_945, Packets_t& pAssemblys_946);

protected:
	void callCreate_SrcPublish_9ea( const Packets_t& scenarios_9a5);
	void callCreate_DeliverTo_9ec( const Packets_t& scenarios_9c8);
	void callCreate_Invokes_9ee( const Packets_t& scenarios_94a);
	void callCreate_Emits_9f0( const Packets_t& scenarios_972);

private:
	Packets_t* _cScenario_947;
	Packets_t* _pAssembly_948;
};

class Create_Invokes_949
{
public:
	void operator()( const Packets_t& scenarios_94a);

protected:
	bool isInputUnique( const Udm::Object& scenario_950);
	void processInputPackets( const Packets_t& scenarios_94a);
	bool patternMatcher( const Udm::Object& scenario_94e);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_94c;
	class Match
	{
	public:
		cadena_scenario::ComponentInstance componentInstance_967;
		PICML::Component component_968;
		PICML::ComponentAssembly componentAssembly_969;
		cadena_scenario::FRConnection fRConnection_96a;
		cadena_scenario::Facet facet_96b;
		cadena_scenario::Receptacle receptacle_96c;
		PICML::RequiredRequestPort requiredRequestPort_96d;
		PICML::ProvidedRequestPort providedRequestPort_96e;
		cadena_scenario::Scenario scenario_96f;
	};

	std::list< Match> _matches;
};

class Create_Emits_971
{
public:
	void operator()( const Packets_t& scenarios_972);

protected:
	bool isInputUnique( const Udm::Object& scenario_978);
	bool isGuardTrue( const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& ComponentInstance, const Udm::Object& ESSConnection, const Udm::Object& EventSink, const Udm::Object& EventSource, const Udm::Object& InEventPort, const Udm::Object& OutEventPort, const Udm::Object& Scenario);
	void processInputPackets( const Packets_t& scenarios_972);
	bool patternMatcher( const Udm::Object& scenario_976);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_974;
	class Match
	{
	public:
		cadena_scenario::ComponentInstance componentInstance_991;
		PICML::Component component_992;
		PICML::ComponentAssembly componentAssembly_993;
		cadena_scenario::EventSink eventSink_994;
		cadena_scenario::EventSource eventSource_995;
		cadena_scenario::ESSConnection eSSConnection_996;
		cadena_scenario::Scenario scenario_997;
		PICML::InEventPort inEventPort_998;
		PICML::OutEventPort outEventPort_999;
	};

	std::list< Match> _matches;
};

class Create_SrcPublish_9a4
{
public:
	void operator()( const Packets_t& scenarios_9a5);

protected:
	bool isInputUnique( const Udm::Object& scenario_9ab);
	void processInputPackets( const Packets_t& scenarios_9a5);
	bool patternMatcher( const Udm::Object& scenario_9a9);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_9a7;
	class Match
	{
	public:
		cadena_scenario::EventSource eventSource_9bf;
		cadena_scenario::ESSConnection eSSConnection_9c0;
		cadena_scenario::Scenario scenario_9c1;
		PICML::ComponentAssembly componentAssembly_9c2;
		PICML::Component component_9c3;
		PICML::OutEventPort outEventPort_9c4;
		PICML::PublishConnector publishConnector_9c5;
	};

	std::list< Match> _matches;
};

class Create_DeliverTo_9c7
{
public:
	void operator()( const Packets_t& scenarios_9c8);

protected:
	bool isInputUnique( const Udm::Object& scenario_9ce);
	void processInputPackets( const Packets_t& scenarios_9c8);
	bool patternMatcher( const Udm::Object& scenario_9cc);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_9ca;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_9e2;
		PICML::Component component_9e3;
		PICML::PublishConnector publishConnector_9e4;
		PICML::InEventPort inEventPort_9e5;
		cadena_scenario::ESSConnection eSSConnection_9e6;
		cadena_scenario::EventSink eventSink_9e7;
		cadena_scenario::Scenario scenario_9e8;
	};

	std::list< Match> _matches;
};

