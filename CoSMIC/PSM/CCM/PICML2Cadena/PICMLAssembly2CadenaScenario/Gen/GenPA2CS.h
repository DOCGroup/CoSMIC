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
class TransferingComponentProperties_7;
class Transfering_Properties_c;
class TransferingPublishConnectionProperties_3b;
class Transfering_PublishConnector_Properties_40;
class Transfering_CadenaProperties_45;
class Assembly_and_Scenario_Finder_7c;
class PortConnection_bd;
class ConnectorsToSinks_ce;
class Setting_ConnectorIDs_f0;
class Block_DeleteAll_ConnectorID_Properties_f5;
class Rule_DeleteAll_ConnectorID_Properties_fe;
class Block_Fetch_Default_IfAllEmpty_134;
class Fetch_Default_IfAllEmpty_13d;
class Block_FetchAll_ConnectorID_Property_Value_IfNotEmpty_163;
class Rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c;
class RecreateOne_ConnectorIDProperty_and_DumpValueBack_18f;
class CreateOne_ConnectorIDRequirement_IfNeeded_And_Match_1be;
class Create_ConnectorIDRequirement_IfNeeded_1c7;
class Test_ConnectorIDRequirement_DoesntExist_1d0;
class ConnectorID_Requirement_Exists_1dc;
class ConnectorID_Requirement_ToBeCreated_1f2;
class Create_ConnectorID_Requirement_203;
class Match_ConnectorID_Requirement_219;
class Block_Remove_Multiple_ConnectorID_Requirements_24a;
class Rule_Remove_Multiple_ConnectorID_Requirements_253;
class InputSplitter_28d;
class MethodInvocations_2ae;
class SourcesToConnectors_2dc;
class Creating_ESSConnections_2fe;
class PICMLPort_Finder_324;
class Emits_34d;
class ComponentAndPortCreation_391;
class ComponentCreation_39e;
class PortsCreation_3c4;
class Receptacles_3c9;
class AssignNames_3ef;
class Facets_408;
class EventSinks_42e;
class EventSources_454;
class Transfering_Emit_and_Invoke_Properties_48f;
class ForBlock_492;
class GetPorts_49c;
class MatchCorrectInvokeConnection_4c1;
class TransferEIProperties_4f8;
class DestroyDataNetwork_51a;
class Match_RootContainer_51d;
class KillEverything_531;
class MatchCorrectEmitConnection_546;
class Open_EIConnectionProperties_DataNetwork_57d;
class Match_EIProperties_5ad;

// Class declarations.
class RootRuleBlock_0
{
public:
	void operator()( const Packets_t& cadena_File_Ins_1, const Packets_t& embedded_Dummy_File_Ins_3, const Packets_t& pICML_File_Ins_5);

protected:
	void callAssembly_and_Scenario_Finder_5d0( const Packets_t& rootContainers_7d, const Packets_t& scenarioss_7f, const Packets_t& rootFolders_82);
	void callComponentAndPortCreation_5d4( const Packets_t& assemblys_392, const Packets_t& scenarios_394);
	void callPortConnection_5d7( const Packets_t& assemblys_be, const Packets_t& scenarios_c0);
	void callTransferingComponentProperties_5da( const Packets_t& pComponentDefs_8, const Packets_t& cComponentInstances_a);
	void callTransferingPublishConnectionProperties_5dd( const Packets_t& pPConnectors_3c, const Packets_t& cESSConnections_3e);
	void callTransfering_Emit_and_Invoke_Properties_5e0( const Packets_t& pAssemblys_490);
};

class TransferingComponentProperties_7
{
public:
	void operator()( const Packets_t& pComponentDefs_8, const Packets_t& cComponentInstances_a);

protected:
	void callTransfering_Properties_38( const Packets_t& componentInstances_d, const Packets_t& componentDefs_f);
};

class Transfering_Properties_c
{
public:
	void operator()( const Packets_t& componentInstances_d, const Packets_t& componentDefs_f);

protected:
	bool isInputUnique( const Udm::Object& componentInstance_15, const Udm::Object& componentDef_1e);
	bool isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& ComponentDef, const Udm::Object& ComponentInstance, const Udm::Object& DataType, const Udm::Object& PProperty, const Udm::Object& PredefinedType);
	void processInputPackets( const Packets_t& componentInstances_d, const Packets_t& componentDefs_f);
	bool patternMatcher( const Udm::Object& componentInstance_13, const Udm::Object& componentDef_1c);
	void effector();
	void outputAppender();

private:
	Packets_t _componentInstance_11;
	Packets_t _componentDef_1a;
	class Match
	{
	public:
		cadena_scenario::ComponentInstance componentInstance_2b;
		PICML::Component componentDef_2c;
		PICML::DataType dataType_2d;
		PICML::Property pProperty_2e;
		PICML::PredefinedType predefinedType_2f;
		PICML::AssemblyConfigProperty assemblyConfigProperty_30;
	};

	std::list< Match> _matches;
};

class TransferingPublishConnectionProperties_3b
{
public:
	void operator()( const Packets_t& pPConnectors_3c, const Packets_t& cESSConnections_3e);

protected:
	void callTransfering_PublishConnector_Properties_79( const Packets_t& pPConnectors_41, const Packets_t& cESSConnections_43);
};

class Transfering_PublishConnector_Properties_40
{
public:
	void operator()( const Packets_t& pPConnectors_41, const Packets_t& cESSConnections_43);

protected:
	void callTransfering_CadenaProperties_76( const Packets_t& eSSConnections_46, const Packets_t& publishConnectors_48);
};

class Transfering_CadenaProperties_45
{
public:
	void operator()( const Packets_t& eSSConnections_46, const Packets_t& publishConnectors_48);

protected:
	bool isInputUnique( const Udm::Object& eSSConnection_4e, const Udm::Object& publishConnector_57);
	bool isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& DataType, const Udm::Object& ESSConnection, const Udm::Object& PProperty, const Udm::Object& PredefinedType, const Udm::Object& PublishConnector, const Udm::Object& Requirement);
	void processInputPackets( const Packets_t& eSSConnections_46, const Packets_t& publishConnectors_48);
	bool patternMatcher( const Udm::Object& eSSConnection_4c, const Udm::Object& publishConnector_55);
	void effector();
	void outputAppender();

private:
	Packets_t _eSSConnection_4a;
	Packets_t _publishConnector_53;
	class Match
	{
	public:
		PICML::PredefinedType predefinedType_67;
		PICML::Requirement requirement_68;
		PICML::DataType dataType_69;
		PICML::Property pProperty_6a;
		PICML::AssemblyDeployRequirement assemblyDeployRequirement_6b;
		cadena_scenario::ESSConnection eSSConnection_6c;
		PICML::PublishConnector publishConnector_6d;
	};

	std::list< Match> _matches;
};

class Assembly_and_Scenario_Finder_7c
{
public:
	void operator()( const Packets_t& rootContainers_7d, const Packets_t& scenarioss_7f, const Packets_t& rootFolders_82, Packets_t& scenarios_81, Packets_t& componentAssemblys_84);

protected:
	bool isInputUnique( const Udm::Object& rootContainer_8b, const Udm::Object& scenarios_94, const Udm::Object& rootFolder_9d);
	bool isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& RootContainer, const Udm::Object& RootFolder, const Udm::Object& Scenarios);
	void processInputPackets( const Packets_t& rootContainers_7d, const Packets_t& scenarioss_7f, const Packets_t& rootFolders_82);
	bool patternMatcher( const Udm::Object& rootContainer_89, const Udm::Object& scenarios_92, const Udm::Object& rootFolder_9b);
	void effector();
	void outputAppender( const cadena_scenario::Scenario& scenario_b9, const PICML::ComponentAssembly& componentAssembly_bb);

private:
	Packets_t* _scenario_85;
	Packets_t* _componentAssembly_86;
	Packets_t _rootContainer_87;
	Packets_t _scenarios_90;
	Packets_t _rootFolder_99;
	class Match
	{
	public:
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_ab;
		cadena_scenario::Scenarios scenarios_ac;
		PICML::RootFolder rootFolder_ad;
		PICML::ComponentImplementations componentImplementations_ae;
		PICML::ComponentImplementationContainer componentImplementationContainer_af;
		PICML::ComponentAssembly componentAssembly_b0;
	};

	std::list< Match> _matches;
};

class PortConnection_bd
{
public:
	void operator()( const Packets_t& assemblys_be, const Packets_t& scenarios_c0, Packets_t& pMasterPorts_c2, Packets_t& cEIConnections_c3, Packets_t& cESSConnections_c4, Packets_t& pPConnectors_c5, Packets_t& scenarios_c6, Packets_t& assemblys_c7);

protected:
	void callInputSplitter_379( const Packets_t& scenarios_28e, const Packets_t& componentAssemblys_291);
	void callCreating_ESSConnections_37c( const Packets_t& scenarios_2ff, const Packets_t& componentAssemblys_303);
	void callPICMLPort_Finder_37f( const Packets_t& scenarios_325, const Packets_t& componentAssemblys_329);
	void callSetting_ConnectorIDs_382( const Packets_t& ins_f1, const Packets_t& ins_f3);
	void callConnectorsToSinks_385( const Packets_t& publishConnectors_cf, const Packets_t& eSSConnections_d1);
	void callSourcesToConnectors_388( const Packets_t& eSSConnections_2dd, const Packets_t& publishConnectors_2df);
	void callMethodInvocations_38b( const Packets_t& requiredRequestPorts_2b0, const Packets_t& scenarios_2b3);
	void callEmits_38e( const Packets_t& scenarios_34f, const Packets_t& outEventPorts_351);

private:
	Packets_t* _pMasterPort_c8;
	Packets_t* _cEIConnection_c9;
	Packets_t* _cESSConnection_ca;
	Packets_t* _pPConnector_cb;
	Packets_t* _scenario_cc;
	Packets_t* _assembly_cd;
};

class ConnectorsToSinks_ce
{
public:
	void operator()( const Packets_t& publishConnectors_cf, const Packets_t& eSSConnections_d1);

protected:
	bool isInputUnique( const Udm::Object& publishConnector_d7, const Udm::Object& eSSConnection_e0);
	void processInputPackets( const Packets_t& publishConnectors_cf, const Packets_t& eSSConnections_d1);
	bool patternMatcher( const Udm::Object& publishConnector_d5, const Udm::Object& eSSConnection_de);
	void effector();
	void outputAppender();

private:
	Packets_t _publishConnector_d3;
	Packets_t _eSSConnection_dc;
	class Match
	{
	public:
		PICML::InEventPort inEventPort_eb;
		cadena_scenario::EventSink eventSink_ec;
		PICML::deliverTo deliverTo_ed;
		PICML::PublishConnector publishConnector_ee;
		cadena_scenario::ESSConnection eSSConnection_ef;
	};

	std::list< Match> _matches;
};

class Setting_ConnectorIDs_f0
{
public:
	void operator()( const Packets_t& ins_f1, const Packets_t& ins_f3);

protected:
	void callBlock_Remove_Multiple_ConnectorID_Requirements_27b( const Packets_t& ins_24b, const Packets_t& ins_24d);
	void callCreateOne_ConnectorIDRequirement_IfNeeded_And_Match_27e( const Packets_t& ins_1bf, const Packets_t& ins_1c1);
	void callBlock_FetchAll_ConnectorID_Property_Value_IfNotEmpty_281( const Packets_t& ins_164, const Packets_t& ins_166);
	void callBlock_Fetch_Default_IfAllEmpty_284( const Packets_t& ins_135, const Packets_t& ins_137);
	void callBlock_DeleteAll_ConnectorID_Properties_287( const Packets_t& ins_f6, const Packets_t& ins_f8);
	void callRecreateOne_ConnectorIDProperty_and_DumpValueBack_28a( const Packets_t& requirements_190, const Packets_t& eSSConnections_192);
};

class Block_DeleteAll_ConnectorID_Properties_f5
{
public:
	void operator()( const Packets_t& ins_f6, const Packets_t& ins_f8, Packets_t& outs_fa, Packets_t& outs_fb);

protected:
	void callRule_DeleteAll_ConnectorID_Properties_131( const Packets_t& requirements_ff, const Packets_t& eSSConnections_101);

private:
	Packets_t* _out_fc;
	Packets_t* _out_fd;
};

class Rule_DeleteAll_ConnectorID_Properties_fe
{
public:
	void operator()( const Packets_t& requirements_ff, const Packets_t& eSSConnections_101);

protected:
	bool isInputUnique( const Udm::Object& requirement_107, const Udm::Object& eSSConnection_110);
	void processInputPackets( const Packets_t& requirements_ff, const Packets_t& eSSConnections_101);
	bool patternMatcher( const Udm::Object& requirement_105, const Udm::Object& eSSConnection_10e);
	void effector();
	void outputAppender();

private:
	Packets_t _requirement_103;
	Packets_t _eSSConnection_10c;
	class Match
	{
	public:
		PICML::Property property_118;
		PICML::Requirement requirement_119;
		cadena_scenario::ESSConnection eSSConnection_11a;
	};

	std::list< Match> _matches;
};

class Block_Fetch_Default_IfAllEmpty_134
{
public:
	void operator()( const Packets_t& ins_135, const Packets_t& ins_137, Packets_t& outs_139, Packets_t& outs_13a);

protected:
	void callFetch_Default_IfAllEmpty_160( const Packets_t& requirements_13e, const Packets_t& eSSConnections_140);

private:
	Packets_t* _out_13b;
	Packets_t* _out_13c;
};

class Fetch_Default_IfAllEmpty_13d
{
public:
	void operator()( const Packets_t& requirements_13e, const Packets_t& eSSConnections_140);

protected:
	bool isInputUnique( const Udm::Object& requirement_146, const Udm::Object& eSSConnection_14f);
	bool isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& ESSConnection, const Udm::Object& PublishConnector, const Udm::Object& Requirement);
	void processInputPackets( const Packets_t& requirements_13e, const Packets_t& eSSConnections_140);
	bool patternMatcher( const Udm::Object& requirement_144, const Udm::Object& eSSConnection_14d);
	void effector();
	void outputAppender();

private:
	Packets_t _requirement_142;
	Packets_t _eSSConnection_14b;
	class Match
	{
	public:
		PICML::AssemblyDeployRequirement assemblyDeployRequirement_158;
		PICML::Requirement requirement_159;
		PICML::PublishConnector publishConnector_15a;
		cadena_scenario::ESSConnection eSSConnection_15b;
	};

	std::list< Match> _matches;
};

class Block_FetchAll_ConnectorID_Property_Value_IfNotEmpty_163
{
public:
	void operator()( const Packets_t& ins_164, const Packets_t& ins_166, Packets_t& outs_168, Packets_t& outs_169);

protected:
	void callRule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_18c( const Packets_t& requirements_16d, const Packets_t& eSSConnections_16f);

private:
	Packets_t* _out_16a;
	Packets_t* _out_16b;
};

class Rule_FetchAll_ConnectorID_Property_Value_IfNotEmpty_16c
{
public:
	void operator()( const Packets_t& requirements_16d, const Packets_t& eSSConnections_16f);

protected:
	bool isInputUnique( const Udm::Object& requirement_175, const Udm::Object& eSSConnection_17e);
	bool isGuardTrue( const Udm::Object& ESSConnection, const Udm::Object& Property, const Udm::Object& Requirement);
	void processInputPackets( const Packets_t& requirements_16d, const Packets_t& eSSConnections_16f);
	bool patternMatcher( const Udm::Object& requirement_173, const Udm::Object& eSSConnection_17c);
	void effector();
	void outputAppender();

private:
	Packets_t _requirement_171;
	Packets_t _eSSConnection_17a;
	class Match
	{
	public:
		PICML::Property property_186;
		PICML::Requirement requirement_187;
		cadena_scenario::ESSConnection eSSConnection_188;
	};

	std::list< Match> _matches;
};

class RecreateOne_ConnectorIDProperty_and_DumpValueBack_18f
{
public:
	void operator()( const Packets_t& requirements_190, const Packets_t& eSSConnections_192);

protected:
	bool isInputUnique( const Udm::Object& requirement_198, const Udm::Object& eSSConnection_1a1);
	void processInputPackets( const Packets_t& requirements_190, const Packets_t& eSSConnections_192);
	bool patternMatcher( const Udm::Object& requirement_196, const Udm::Object& eSSConnection_19f);
	void effector();
	void outputAppender();

private:
	Packets_t _requirement_194;
	Packets_t _eSSConnection_19d;
	class Match
	{
	public:
		PICML::PredefinedTypes predefinedTypes_1b4;
		PICML::String string_1b5;
		PICML::RootFolder rootFolder_1b6;
		PICML::ComponentImplementations componentImplementations_1b7;
		PICML::ComponentImplementationContainer componentImplementationContainer_1b8;
		PICML::ComponentAssembly componentAssembly_1b9;
		PICML::Requirement requirement_1ba;
		cadena_scenario::ESSConnection eSSConnection_1bb;
	};

	std::list< Match> _matches;
};

class CreateOne_ConnectorIDRequirement_IfNeeded_And_Match_1be
{
public:
	void operator()( const Packets_t& ins_1bf, const Packets_t& ins_1c1, Packets_t& outs_1c3, Packets_t& outs_1c4);

protected:
	void callCreate_ConnectorIDRequirement_IfNeeded_244( const Packets_t& ins_1c8, const Packets_t& ins_1ca);
	void callMatch_ConnectorID_Requirement_247( const Packets_t& eSSConnections_21a, const Packets_t& publishConnectors_21e);

private:
	Packets_t* _out_1c5;
	Packets_t* _out_1c6;
};

class Create_ConnectorIDRequirement_IfNeeded_1c7
{
public:
	void operator()( const Packets_t& ins_1c8, const Packets_t& ins_1ca, Packets_t& outs_1cc, Packets_t& outs_1cd);

protected:
	void callTest_ConnectorIDRequirement_DoesntExist_215( const Packets_t& ins_1d2);
	void callCreate_ConnectorID_Requirement_217( const Packets_t& publishConnectors_204);

private:
	Packets_t* _out_1ce;
	Packets_t* _out_1cf;
};

class Test_ConnectorIDRequirement_DoesntExist_1d0
{
public:
	void operator()( const Packets_t& ins_1d2, Packets_t& outs_1d1);

protected:
	void executeOne( const Packets_t& ins_1d2);
	bool isInputUnique( const Udm::Object& in_1d7);

private:
	Packets_t* _out_1d4;
	Packets_t _in_1d5;
};

class ConnectorID_Requirement_Exists_1dc
{
public:
	bool operator()( const Packets_t& publishConnectors_1dd);

protected:
	bool isInputUnique( const Udm::Object& publishConnector_1e3);
	bool isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& PublishConnector, const Udm::Object& Requirement);
	void processInputPackets( const Packets_t& publishConnectors_1dd);
	bool patternMatcher( const Udm::Object& publishConnector_1e1);
	void outputAppender();

private:
	Packets_t _publishConnector_1df;
	class Match
	{
	public:
		PICML::AssemblyDeployRequirement assemblyDeployRequirement_1ec;
		PICML::Requirement requirement_1ed;
		PICML::PublishConnector publishConnector_1ee;
	};

	std::list< Match> _matches;
};

class ConnectorID_Requirement_ToBeCreated_1f2
{
public:
	bool operator()( const Packets_t& publishConnectors_1f3, Packets_t& publishConnectors_1f5);

protected:
	bool isInputUnique( const Udm::Object& publishConnector_1fb);
	void processInputPackets( const Packets_t& publishConnectors_1f3);
	bool patternMatcher( const Udm::Object& publishConnector_1f9);
	void outputAppender( const PICML::PublishConnector& publishConnector_201);

private:
	Packets_t* _publishConnector_1f6;
	Packets_t _publishConnector_1f7;
	class Match
	{
	public:
		PICML::PublishConnector publishConnector_200;
	};

	std::list< Match> _matches;
};

class Create_ConnectorID_Requirement_203
{
public:
	void operator()( const Packets_t& publishConnectors_204);

protected:
	bool isInputUnique( const Udm::Object& publishConnector_20a);
	void processInputPackets( const Packets_t& publishConnectors_204);
	bool patternMatcher( const Udm::Object& publishConnector_208);
	void effector();
	void outputAppender();

private:
	Packets_t _publishConnector_206;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_211;
		PICML::PublishConnector publishConnector_212;
	};

	std::list< Match> _matches;
};

class Match_ConnectorID_Requirement_219
{
public:
	void operator()( const Packets_t& eSSConnections_21a, const Packets_t& publishConnectors_21e, Packets_t& eSSConnections_21c, Packets_t& requirements_21d);

protected:
	bool isInputUnique( const Udm::Object& eSSConnection_226, const Udm::Object& publishConnector_22f);
	bool isGuardTrue( const Udm::Object& AssemblyDeployRequirement, const Udm::Object& ESSConnection, const Udm::Object& PublishConnector, const Udm::Object& Requirement);
	void processInputPackets( const Packets_t& eSSConnections_21a, const Packets_t& publishConnectors_21e);
	bool patternMatcher( const Udm::Object& eSSConnection_224, const Udm::Object& publishConnector_22d);
	void effector();
	void outputAppender( const cadena_scenario::ESSConnection& eSSConnection_240, const PICML::Requirement& requirement_242);

private:
	Packets_t* _eSSConnection_220;
	Packets_t* _requirement_221;
	Packets_t _eSSConnection_222;
	Packets_t _publishConnector_22b;
	class Match
	{
	public:
		cadena_scenario::ESSConnection eSSConnection_238;
		PICML::Requirement requirement_239;
		PICML::PublishConnector publishConnector_23a;
		PICML::AssemblyDeployRequirement assemblyDeployRequirement_23b;
	};

	std::list< Match> _matches;
};

class Block_Remove_Multiple_ConnectorID_Requirements_24a
{
public:
	void operator()( const Packets_t& ins_24b, const Packets_t& ins_24d, Packets_t& outs_24f, Packets_t& outs_250);

protected:
	void callRule_Remove_Multiple_ConnectorID_Requirements_279( const Packets_t& publishConnectors_254);

private:
	Packets_t* _out_251;
	Packets_t* _out_252;
};

class Rule_Remove_Multiple_ConnectorID_Requirements_253
{
public:
	void operator()( const Packets_t& publishConnectors_254);

protected:
	bool isInputUnique( const Udm::Object& publishConnector_25a);
	bool isGuardTrue( const Udm::Object& AssemblyDeployRequirement1, const Udm::Object& AssemblyDeployRequirement2, const Udm::Object& PublishConnector, const Udm::Object& Requirement1, const Udm::Object& Requirement2);
	void processInputPackets( const Packets_t& publishConnectors_254);
	bool patternMatcher( const Udm::Object& publishConnector_258);
	void effector();
	void outputAppender();

private:
	Packets_t _publishConnector_256;
	class Match
	{
	public:
		PICML::Requirement requirement1_267;
		PICML::Requirement requirement2_268;
		PICML::AssemblyDeployRequirement assemblyDeployRequirement2_269;
		PICML::PublishConnector publishConnector_26a;
		PICML::AssemblyDeployRequirement assemblyDeployRequirement1_26b;
	};

	std::list< Match> _matches;
};

class InputSplitter_28d
{
public:
	void operator()( const Packets_t& scenarios_28e, const Packets_t& componentAssemblys_291, Packets_t& scenarios_290, Packets_t& componentAssemblys_293);

protected:
	bool isInputUnique( const Udm::Object& scenario_29a, const Udm::Object& componentAssembly_2a3);
	void processInputPackets( const Packets_t& scenarios_28e, const Packets_t& componentAssemblys_291);
	bool patternMatcher( const Udm::Object& scenario_298, const Udm::Object& componentAssembly_2a1);
	void effector();
	void outputAppender( const cadena_scenario::Scenario& scenario_2aa, const PICML::ComponentAssembly& componentAssembly_2ac);
	void forwardInputs();

private:
	Packets_t* _scenario_294;
	Packets_t* _componentAssembly_295;
	Packets_t _scenario_296;
	Packets_t _componentAssembly_29f;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_2a8;
		PICML::ComponentAssembly componentAssembly_2a9;
	};

	std::list< Match> _matches;
};

class MethodInvocations_2ae
{
public:
	void operator()( const Packets_t& requiredRequestPorts_2b0, const Packets_t& scenarios_2b3, Packets_t& fRConnections_2af, Packets_t& requiredRequestPorts_2b2);

protected:
	bool isInputUnique( const Udm::Object& requiredRequestPort_2bb, const Udm::Object& scenario_2c4);
	void processInputPackets( const Packets_t& requiredRequestPorts_2b0, const Packets_t& scenarios_2b3);
	bool patternMatcher( const Udm::Object& requiredRequestPort_2b9, const Udm::Object& scenario_2c2);
	void effector();
	void outputAppender( const cadena_scenario::FRConnection& fRConnection_2d8, const PICML::RequiredRequestPort& requiredRequestPort_2da);

private:
	Packets_t* _fRConnection_2b5;
	Packets_t* _requiredRequestPort_2b6;
	Packets_t _requiredRequestPort_2b7;
	Packets_t _scenario_2c0;
	class Match
	{
	public:
		PICML::invoke invoke_2d1;
		cadena_scenario::Facet facet_2d2;
		cadena_scenario::Receptacle receptacle_2d3;
		PICML::ProvidedRequestPort providedRequestPort_2d4;
		PICML::RequiredRequestPort requiredRequestPort_2d5;
		cadena_scenario::Scenario scenario_2d6;
	};

	std::list< Match> _matches;
};

class SourcesToConnectors_2dc
{
public:
	void operator()( const Packets_t& eSSConnections_2dd, const Packets_t& publishConnectors_2df);

protected:
	bool isInputUnique( const Udm::Object& eSSConnection_2e5, const Udm::Object& publishConnector_2ee);
	void processInputPackets( const Packets_t& eSSConnections_2dd, const Packets_t& publishConnectors_2df);
	bool patternMatcher( const Udm::Object& eSSConnection_2e3, const Udm::Object& publishConnector_2ec);
	void effector();
	void outputAppender();

private:
	Packets_t _eSSConnection_2e1;
	Packets_t _publishConnector_2ea;
	class Match
	{
	public:
		PICML::OutEventPort outEventPort_2f9;
		cadena_scenario::EventSource eventSource_2fa;
		PICML::publish publish_2fb;
		cadena_scenario::ESSConnection eSSConnection_2fc;
		PICML::PublishConnector publishConnector_2fd;
	};

	std::list< Match> _matches;
};

class Creating_ESSConnections_2fe
{
public:
	void operator()( const Packets_t& scenarios_2ff, const Packets_t& componentAssemblys_303, Packets_t& eSSConnections_301, Packets_t& publishConnectors_302);

protected:
	bool isInputUnique( const Udm::Object& scenario_30b, const Udm::Object& componentAssembly_314);
	void processInputPackets( const Packets_t& scenarios_2ff, const Packets_t& componentAssemblys_303);
	bool patternMatcher( const Udm::Object& scenario_309, const Udm::Object& componentAssembly_312);
	void effector();
	void outputAppender( const cadena_scenario::ESSConnection& eSSConnection_320, const PICML::PublishConnector& publishConnector_322);

private:
	Packets_t* _eSSConnection_305;
	Packets_t* _publishConnector_306;
	Packets_t _scenario_307;
	Packets_t _componentAssembly_310;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_31c;
		PICML::PublishConnector publishConnector_31d;
		PICML::ComponentAssembly componentAssembly_31e;
	};

	std::list< Match> _matches;
};

class PICMLPort_Finder_324
{
public:
	void operator()( const Packets_t& scenarios_325, const Packets_t& componentAssemblys_329, Packets_t& scenarios_327, Packets_t& ports_328);

protected:
	bool isInputUnique( const Udm::Object& scenario_331, const Udm::Object& componentAssembly_33a);
	void processInputPackets( const Packets_t& scenarios_325, const Packets_t& componentAssemblys_329);
	bool patternMatcher( const Udm::Object& scenario_32f, const Udm::Object& componentAssembly_338);
	void effector();
	void outputAppender( const cadena_scenario::Scenario& scenario_349, const PICML::Port& port_34b);

private:
	Packets_t* _scenario_32b;
	Packets_t* _port_32c;
	Packets_t _scenario_32d;
	Packets_t _componentAssembly_336;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_345;
		PICML::Port port_346;
		PICML::Component component_347;
		PICML::ComponentAssembly componentAssembly_348;
	};

	std::list< Match> _matches;
};

class Emits_34d
{
public:
	void operator()( const Packets_t& scenarios_34f, const Packets_t& outEventPorts_351, Packets_t& eSSConnections_34e, Packets_t& outEventPorts_353);

protected:
	bool isInputUnique( const Udm::Object& scenario_35a, const Udm::Object& outEventPort_363);
	void processInputPackets( const Packets_t& scenarios_34f, const Packets_t& outEventPorts_351);
	bool patternMatcher( const Udm::Object& scenario_358, const Udm::Object& outEventPort_361);
	void effector();
	void outputAppender( const cadena_scenario::ESSConnection& eSSConnection_375, const PICML::OutEventPort& outEventPort_377);

private:
	Packets_t* _eSSConnection_354;
	Packets_t* _outEventPort_355;
	Packets_t _scenario_356;
	Packets_t _outEventPort_35f;
	class Match
	{
	public:
		cadena_scenario::EventSink eventSink_36e;
		PICML::emit emit_36f;
		cadena_scenario::EventSource eventSource_370;
		PICML::InEventPort inEventPort_371;
		cadena_scenario::Scenario scenario_372;
		PICML::OutEventPort outEventPort_373;
	};

	std::list< Match> _matches;
};

class ComponentAndPortCreation_391
{
public:
	void operator()( const Packets_t& assemblys_392, const Packets_t& scenarios_394, Packets_t& cComponentInstances_396, Packets_t& pComponentDefs_397, Packets_t& scenarios_398, Packets_t& assemblys_399);

protected:
	void callComponentCreation_489( const Packets_t& componentAssemblys_39f, const Packets_t& scenarios_3a3);
	void callPortsCreation_48c( const Packets_t& pICML_Components_3c5, const Packets_t& cadena_Components_3c7);

private:
	Packets_t* _cComponentInstance_39a;
	Packets_t* _pComponentDef_39b;
	Packets_t* _scenario_39c;
	Packets_t* _assembly_39d;
};

class ComponentCreation_39e
{
public:
	void operator()( const Packets_t& componentAssemblys_39f, const Packets_t& scenarios_3a3, Packets_t& components_3a1, Packets_t& componentInstances_3a2);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_3ab, const Udm::Object& scenario_3b4);
	void processInputPackets( const Packets_t& componentAssemblys_39f, const Packets_t& scenarios_3a3);
	bool patternMatcher( const Udm::Object& componentAssembly_3a9, const Udm::Object& scenario_3b2);
	void effector();
	void outputAppender( const PICML::Component& component_3c0, const cadena_scenario::ComponentInstance& componentInstance_3c2);

private:
	Packets_t* _component_3a5;
	Packets_t* _componentInstance_3a6;
	Packets_t _componentAssembly_3a7;
	Packets_t _scenario_3b0;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_3bc;
		PICML::Component component_3bd;
		cadena_scenario::Scenario scenario_3be;
	};

	std::list< Match> _matches;
};

class PortsCreation_3c4
{
public:
	void operator()( const Packets_t& pICML_Components_3c5, const Packets_t& cadena_Components_3c7);

protected:
	void callFacets_47a( const Packets_t& components_40b, const Packets_t& componentInstances_40d);
	void callReceptacles_47d( const Packets_t& components_3cc, const Packets_t& componentInstances_3ce);
	void callEventSinks_480( const Packets_t& components_431, const Packets_t& componentInstances_433);
	void callEventSources_483( const Packets_t& componentInstances_457, const Packets_t& components_459);
	void callAssignNames_486( const Packets_t& componentPorts_3f0, const Packets_t& ports_3f2);
};

class Receptacles_3c9
{
public:
	void operator()( const Packets_t& components_3cc, const Packets_t& componentInstances_3ce, Packets_t& receptacles_3ca, Packets_t& requiredRequestPorts_3cb);

protected:
	bool isInputUnique( const Udm::Object& component_3d6, const Udm::Object& componentInstance_3df);
	void processInputPackets( const Packets_t& components_3cc, const Packets_t& componentInstances_3ce);
	bool patternMatcher( const Udm::Object& component_3d4, const Udm::Object& componentInstance_3dd);
	void effector();
	void outputAppender( const cadena_scenario::Receptacle& receptacle_3eb, const PICML::RequiredRequestPort& requiredRequestPort_3ed);

private:
	Packets_t* _receptacle_3d0;
	Packets_t* _requiredRequestPort_3d1;
	Packets_t _component_3d2;
	Packets_t _componentInstance_3db;
	class Match
	{
	public:
		PICML::RequiredRequestPort requiredRequestPort_3e7;
		PICML::Component component_3e8;
		cadena_scenario::ComponentInstance componentInstance_3e9;
	};

	std::list< Match> _matches;
};

class AssignNames_3ef
{
public:
	void operator()( const Packets_t& componentPorts_3f0, const Packets_t& ports_3f2);

protected:
	bool isInputUnique( const Udm::Object& componentPort_3f8, const Udm::Object& port_401);
	void processInputPackets( const Packets_t& componentPorts_3f0, const Packets_t& ports_3f2);
	bool patternMatcher( const Udm::Object& componentPort_3f6, const Udm::Object& port_3ff);
	void effector();
	void outputAppender();

private:
	Packets_t _componentPort_3f4;
	Packets_t _port_3fd;
	class Match
	{
	public:
		cadena_scenario::ComponentPort componentPort_406;
		PICML::Port port_407;
	};

	std::list< Match> _matches;
};

class Facets_408
{
public:
	void operator()( const Packets_t& components_40b, const Packets_t& componentInstances_40d, Packets_t& facets_409, Packets_t& providedRequestPorts_40a);

protected:
	bool isInputUnique( const Udm::Object& component_415, const Udm::Object& componentInstance_41e);
	void processInputPackets( const Packets_t& components_40b, const Packets_t& componentInstances_40d);
	bool patternMatcher( const Udm::Object& component_413, const Udm::Object& componentInstance_41c);
	void effector();
	void outputAppender( const cadena_scenario::Facet& facet_42a, const PICML::ProvidedRequestPort& providedRequestPort_42c);

private:
	Packets_t* _facet_40f;
	Packets_t* _providedRequestPort_410;
	Packets_t _component_411;
	Packets_t _componentInstance_41a;
	class Match
	{
	public:
		PICML::ProvidedRequestPort providedRequestPort_426;
		PICML::Component component_427;
		cadena_scenario::ComponentInstance componentInstance_428;
	};

	std::list< Match> _matches;
};

class EventSinks_42e
{
public:
	void operator()( const Packets_t& components_431, const Packets_t& componentInstances_433, Packets_t& eventSinks_42f, Packets_t& inEventPorts_430);

protected:
	bool isInputUnique( const Udm::Object& component_43b, const Udm::Object& componentInstance_444);
	void processInputPackets( const Packets_t& components_431, const Packets_t& componentInstances_433);
	bool patternMatcher( const Udm::Object& component_439, const Udm::Object& componentInstance_442);
	void effector();
	void outputAppender( const cadena_scenario::EventSink& eventSink_450, const PICML::InEventPort& inEventPort_452);

private:
	Packets_t* _eventSink_435;
	Packets_t* _inEventPort_436;
	Packets_t _component_437;
	Packets_t _componentInstance_440;
	class Match
	{
	public:
		PICML::InEventPort inEventPort_44c;
		PICML::Component component_44d;
		cadena_scenario::ComponentInstance componentInstance_44e;
	};

	std::list< Match> _matches;
};

class EventSources_454
{
public:
	void operator()( const Packets_t& componentInstances_457, const Packets_t& components_459, Packets_t& eventSources_455, Packets_t& outEventPorts_456);

protected:
	bool isInputUnique( const Udm::Object& componentInstance_461, const Udm::Object& component_46a);
	void processInputPackets( const Packets_t& componentInstances_457, const Packets_t& components_459);
	bool patternMatcher( const Udm::Object& componentInstance_45f, const Udm::Object& component_468);
	void effector();
	void outputAppender( const cadena_scenario::EventSource& eventSource_476, const PICML::OutEventPort& outEventPort_478);

private:
	Packets_t* _eventSource_45b;
	Packets_t* _outEventPort_45c;
	Packets_t _componentInstance_45d;
	Packets_t _component_466;
	class Match
	{
	public:
		PICML::OutEventPort outEventPort_472;
		cadena_scenario::ComponentInstance componentInstance_473;
		PICML::Component component_474;
	};

	std::list< Match> _matches;
};

class Transfering_Emit_and_Invoke_Properties_48f
{
public:
	void operator()( const Packets_t& pAssemblys_490);

protected:
	void callMatch_EIProperties_5cc( const Packets_t& componentAssemblys_5af);
	void callForBlock_5ce( const Packets_t& pPropertys_493);
};

class ForBlock_492
{
public:
	void operator()( const Packets_t& pPropertys_493);

protected:
	void executeOne( const Packets_t& pPropertys_493);
	bool isInputUnique( const Udm::Object& pProperty_497);
	void callOpen_EIConnectionProperties_DataNetwork_59d( const Packets_t& propertys_57f);
	void callGetPorts_59f( const Packets_t& components_49d, const Packets_t& rootContainers_49f);
	void callMatchCorrectEmitConnection_5a2( const Packets_t& rootContainers_548, const Packets_t& outEventPorts_54a);
	void callMatchCorrectInvokeConnection_5a5( const Packets_t& rootContainers_4c3, const Packets_t& requiredRequestPorts_4c6);
	void callTransferEIProperties_5a8( const Packets_t& portConnections_4f9, const Packets_t& connectionSelectors_4fb);
	void callDestroyDataNetwork_5ab( const Packets_t& eConnectionSelectors_51b);

private:
	Packets_t _pProperty_495;
};

class GetPorts_49c
{
public:
	void operator()( const Packets_t& components_49d, const Packets_t& rootContainers_49f, Packets_t& rootContainers_4a1, Packets_t& ports_4a2);

protected:
	bool isInputUnique( const Udm::Object& component_4a9, const Udm::Object& rootContainer_4b2);
	void processInputPackets( const Packets_t& components_49d, const Packets_t& rootContainers_49f);
	bool patternMatcher( const Udm::Object& component_4a7, const Udm::Object& rootContainer_4b0);
	void effector();
	void outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::RootContainer& rootContainer_4bd, const PICML::Port& port_4bf);

private:
	Packets_t* _rootContainer_4a3;
	Packets_t* _port_4a4;
	Packets_t _component_4a5;
	Packets_t _rootContainer_4ae;
	class Match
	{
	public:
		PICML::Component component_4ba;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_4bb;
		PICML::Port port_4bc;
	};

	std::list< Match> _matches;
};

class MatchCorrectInvokeConnection_4c1
{
public:
	void operator()( const Packets_t& rootContainers_4c3, const Packets_t& requiredRequestPorts_4c6, Packets_t& connectionSelectors_4c2, Packets_t& fRConnections_4c5);

protected:
	bool isInputUnique( const Udm::Object& rootContainer_4ce, const Udm::Object& requiredRequestPort_4d7);
	bool isGuardTrue( const Udm::Object& Component, const Udm::Object& ConnectionSelector, const Udm::Object& FRConnection, const Udm::Object& ProvidedRequestPort, const Udm::Object& RequiredRequestPort, const Udm::Object& RootContainer, const Udm::Object& invoke);
	void processInputPackets( const Packets_t& rootContainers_4c3, const Packets_t& requiredRequestPorts_4c6);
	bool patternMatcher( const Udm::Object& rootContainer_4cc, const Udm::Object& requiredRequestPort_4d5);
	void effector();
	void outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector& connectionSelector_4f4, const cadena_scenario::FRConnection& fRConnection_4f6);

private:
	Packets_t* _connectionSelector_4c8;
	Packets_t* _fRConnection_4c9;
	Packets_t _rootContainer_4ca;
	Packets_t _requiredRequestPort_4d3;
	class Match
	{
	public:
		PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector connectionSelector_4e6;
		PICML::ProvidedRequestPort providedRequestPort_4e7;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_4e8;
		PICML::invoke invoke_4e9;
		PICML::Component component_4ea;
		cadena_scenario::FRConnection fRConnection_4eb;
		PICML::RequiredRequestPort requiredRequestPort_4ec;
	};

	std::list< Match> _matches;
};

class TransferEIProperties_4f8
{
public:
	void operator()( const Packets_t& portConnections_4f9, const Packets_t& connectionSelectors_4fb, Packets_t& connectionSelectors_4fd);

protected:
	bool isInputUnique( const Udm::Object& portConnection_503, const Udm::Object& connectionSelector_50c);
	void processInputPackets( const Packets_t& portConnections_4f9, const Packets_t& connectionSelectors_4fb);
	bool patternMatcher( const Udm::Object& portConnection_501, const Udm::Object& connectionSelector_50a);
	void effector();
	void outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector& connectionSelector_518);
	void forwardInputs();

private:
	Packets_t* _connectionSelector_4fe;
	Packets_t _portConnection_4ff;
	Packets_t _connectionSelector_508;
	class Match
	{
	public:
		PICMLCadena_Xchange_embedded_EIProperties::Property eProperty_514;
		cadena_scenario::PortConnection portConnection_515;
		PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector connectionSelector_516;
	};

	std::list< Match> _matches;
};

class DestroyDataNetwork_51a
{
public:
	void operator()( const Packets_t& eConnectionSelectors_51b);

protected:
	void callMatch_RootContainer_542( const Packets_t& connectionSelectors_51e);
	void callKillEverything_544( const Packets_t& rootContainers_532);
};

class Match_RootContainer_51d
{
public:
	void operator()( const Packets_t& connectionSelectors_51e, Packets_t& rootContainers_520);

protected:
	bool isInputUnique( const Udm::Object& connectionSelector_526);
	void processInputPackets( const Packets_t& connectionSelectors_51e);
	bool patternMatcher( const Udm::Object& connectionSelector_524);
	void effector();
	void outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::RootContainer& rootContainer_52f);

private:
	Packets_t* _rootContainer_521;
	Packets_t _connectionSelector_522;
	class Match
	{
	public:
		PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector connectionSelector_52d;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_52e;
	};

	std::list< Match> _matches;
};

class KillEverything_531
{
public:
	void operator()( const Packets_t& rootContainers_532);

protected:
	bool isInputUnique( const Udm::Object& rootContainer_538);
	void processInputPackets( const Packets_t& rootContainers_532);
	bool patternMatcher( const Udm::Object& rootContainer_536);
	void effector();
	void outputAppender();

private:
	Packets_t _rootContainer_534;
	class Match
	{
	public:
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_540;
		PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector connectionSelector_541;
	};

	std::list< Match> _matches;
};

class MatchCorrectEmitConnection_546
{
public:
	void operator()( const Packets_t& rootContainers_548, const Packets_t& outEventPorts_54a, Packets_t& connectionSelectors_547, Packets_t& eSSConnections_54c);

protected:
	bool isInputUnique( const Udm::Object& rootContainer_553, const Udm::Object& outEventPort_55c);
	bool isGuardTrue( const Udm::Object& Component, const Udm::Object& ConnectionSelector, const Udm::Object& ESSConnection, const Udm::Object& InEventPort, const Udm::Object& OutEventPort, const Udm::Object& RootContainer, const Udm::Object& emit);
	void processInputPackets( const Packets_t& rootContainers_548, const Packets_t& outEventPorts_54a);
	bool patternMatcher( const Udm::Object& rootContainer_551, const Udm::Object& outEventPort_55a);
	void effector();
	void outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector& connectionSelector_579, const cadena_scenario::ESSConnection& eSSConnection_57b);

private:
	Packets_t* _connectionSelector_54d;
	Packets_t* _eSSConnection_54e;
	Packets_t _rootContainer_54f;
	Packets_t _outEventPort_558;
	class Match
	{
	public:
		PICML::Component component_56b;
		PICMLCadena_Xchange_embedded_EIProperties::ConnectionSelector connectionSelector_56c;
		PICML::emit emit_56d;
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_56e;
		PICML::OutEventPort outEventPort_56f;
		cadena_scenario::ESSConnection eSSConnection_570;
		PICML::InEventPort inEventPort_571;
	};

	std::list< Match> _matches;
};

class Open_EIConnectionProperties_DataNetwork_57d
{
public:
	void operator()( const Packets_t& propertys_57f, Packets_t& rootContainers_57e, Packets_t& components_581);

protected:
	bool isInputUnique( const Udm::Object& property_588);
	void processInputPackets( const Packets_t& propertys_57f);
	bool patternMatcher( const Udm::Object& property_586);
	void effector();
	void outputAppender( const PICMLCadena_Xchange_embedded_EIProperties::RootContainer& rootContainer_599, const PICML::Component& component_59b);

private:
	Packets_t* _rootContainer_582;
	Packets_t* _component_583;
	Packets_t _property_584;
	class Match
	{
	public:
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootContainer_594;
		PICML::AssemblyConfigProperty assemblyConfigProperty_595;
		PICML::ComponentAssembly componentAssembly_596;
		PICML::Property property_597;
		PICML::Component component_598;
	};

	std::list< Match> _matches;
};

class Match_EIProperties_5ad
{
public:
	void operator()( const Packets_t& componentAssemblys_5af, Packets_t& propertys_5ae);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_5b6);
	bool isGuardTrue( const Udm::Object& AssemblyConfigProperty, const Udm::Object& Component, const Udm::Object& ComponentAssembly, const Udm::Object& Property);
	void processInputPackets( const Packets_t& componentAssemblys_5af);
	bool patternMatcher( const Udm::Object& componentAssembly_5b4);
	void effector();
	void outputAppender( const PICML::Property& property_5ca);

private:
	Packets_t* _property_5b1;
	Packets_t _componentAssembly_5b2;
	class Match
	{
	public:
		PICML::Property property_5c2;
		PICML::ComponentAssembly componentAssembly_5c3;
		PICML::AssemblyConfigProperty assemblyConfigProperty_5c4;
		PICML::Component component_5c5;
	};

	std::list< Match> _matches;
};

