#include <UdmBase.h>
#include <cint_string.h>
#include "CrossLinks.h"
#include "PICML.h"
#include "PICMLAssembly2CadenaScenario.h"
#include "cadena_scenario.h"

typedef std::list< Udm::Object> Packets_t;

// Forward declarations.
class RootRuleBlock_0;
class PortConnection_5;
class ConnectorsToSinks_a;
class TransferingCorrelatorStrings_2d;
class InputSplitter_64;
class MethodInvocations_85;
class SourcesToConnectors_ad;
class CreatingPublishConnectors_d0;
class PortFinder_f6;
class Emits_11f;
class RootFinder_15d;
class ComponentCreation_18a;
class ComponentCreation_193;
class PortsCreation_1b9;
class Receptacles_1be;
class AssignNames_1e4;
class Facets_208;
class EventSinks_22e;
class EventSources_254;

// Class declarations.
class RootRuleBlock_0
{
public:
	void operator()( const Packets_t& pICML_File_Ins_1, const Packets_t& cadena_File_Ins_3);

protected:
	void callRootFinder_28f( const Packets_t& rootFolders_15e, const Packets_t& scenarios_160);
	void callComponentCreation_292( const Packets_t& pICML_Assembly_Ins_18b, const Packets_t& cadena_Scenario_Ins_18d);
	void callPortConnection_295( const Packets_t& pICML_Assembly_Ins_6, const Packets_t& cadena_Scenario_Ins_8);
};

class PortConnection_5
{
public:
	void operator()( const Packets_t& pICML_Assembly_Ins_6, const Packets_t& cadena_Scenario_Ins_8);

protected:
	void callInputSplitter_145( const Packets_t& scenarios_65, const Packets_t& componentAssemblys_68);
	void callCreatingPublishConnectors_148( const Packets_t& scenarios_d1, const Packets_t& componentAssemblys_d5);
	void callPortFinder_14b( const Packets_t& scenarios_f7, const Packets_t& componentAssemblys_fb);
	void callConnectorsToSinks_14e( const Packets_t& publishConnectors_b, const Packets_t& eSSConnections_d);
	void callTransferingCorrelatorStrings_151( const Packets_t& publishConnectors_2e, const Packets_t& eSSConnections_30);
	void callSourcesToConnectors_154( const Packets_t& eSSConnections_ae, const Packets_t& publishConnectors_b0);
	void callMethodInvocations_157( const Packets_t& requiredRequestPorts_86, const Packets_t& scenarios_88);
	void callEmits_15a( const Packets_t& scenarios_120, const Packets_t& outEventPorts_122);
};

class ConnectorsToSinks_a
{
public:
	void operator()( const Packets_t& publishConnectors_b, const Packets_t& eSSConnections_d);

protected:
	bool isInputUnique( const Udm::Object& publishConnector_13, const Udm::Object& eSSConnection_1c);
	void processInputPackets( const Packets_t& publishConnectors_b, const Packets_t& eSSConnections_d);
	bool patternMatcher( const Udm::Object& publishConnector_11, const Udm::Object& eSSConnection_1a);
	void effector();
	void outputAppender();

private:
	Packets_t _publishConnector_f;
	Packets_t _eSSConnection_18;
	class Match
	{
	public:
		PICML::InEventPort inEventPort_28;
		cadena_scenario::EventSink eventSink_29;
		PICML::InEventPortConsume inEventPortConsume_2a;
		PICML::PublishConnector publishConnector_2b;
		cadena_scenario::ESSConnection eSSConnection_2c;
	};

	std::list< Match> _matches;
};

class TransferingCorrelatorStrings_2d
{
public:
	void operator()( const Packets_t& publishConnectors_2e, const Packets_t& eSSConnections_30);

protected:
	bool isInputUnique( const Udm::Object& publishConnector_36, const Udm::Object& eSSConnection_3f);
	bool isGuardTrue( const Udm::Object& Any, const Udm::Object& ConnectionRequirements, const Udm::Object& DataType, const Udm::Object& ESSConnection, const Udm::Object& PredefinedType, const Udm::Object& Property, const Udm::Object& PublishConnector, const Udm::Object& Requirement);
	void processInputPackets( const Packets_t& publishConnectors_2e, const Packets_t& eSSConnections_30);
	bool patternMatcher( const Udm::Object& publishConnector_34, const Udm::Object& eSSConnection_3d);
	void effector();
	void outputAppender();

private:
	Packets_t _publishConnector_32;
	Packets_t _eSSConnection_3b;
	class Match
	{
	public:
		PICML::DataType dataType_54;
		PICML::ConnectionRequirements connectionRequirements_55;
		PICML::Property property_56;
		PICML::Any any_57;
		PICML::PredefinedType predefinedType_58;
		PICML::Requirement requirement_59;
		PICML::PublishConnector publishConnector_5a;
		cadena_scenario::ESSConnection eSSConnection_5b;
	};

	std::list< Match> _matches;
};

class InputSplitter_64
{
public:
	void operator()( const Packets_t& scenarios_65, const Packets_t& componentAssemblys_68, Packets_t& scenarios_67, Packets_t& componentAssemblys_6a);

protected:
	bool isInputUnique( const Udm::Object& scenario_71, const Udm::Object& componentAssembly_7a);
	void processInputPackets( const Packets_t& scenarios_65, const Packets_t& componentAssemblys_68);
	bool patternMatcher( const Udm::Object& scenario_6f, const Udm::Object& componentAssembly_78);
	void effector();
	void outputAppender( const cadena_scenario::Scenario& scenario_81, const PICML::ComponentAssembly& componentAssembly_83);
	void forwardInputs();

private:
	Packets_t* _scenario_6b;
	Packets_t* _componentAssembly_6c;
	Packets_t _scenario_6d;
	Packets_t _componentAssembly_76;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_7f;
		PICML::ComponentAssembly componentAssembly_80;
	};

	std::list< Match> _matches;
};

class MethodInvocations_85
{
public:
	void operator()( const Packets_t& requiredRequestPorts_86, const Packets_t& scenarios_88);

protected:
	bool isInputUnique( const Udm::Object& requiredRequestPort_8e, const Udm::Object& scenario_97);
	void processInputPackets( const Packets_t& requiredRequestPorts_86, const Packets_t& scenarios_88);
	bool patternMatcher( const Udm::Object& requiredRequestPort_8c, const Udm::Object& scenario_95);
	void effector();
	void outputAppender();

private:
	Packets_t _requiredRequestPort_8a;
	Packets_t _scenario_93;
	class Match
	{
	public:
		PICML::Invocation invocation_a6;
		cadena_scenario::Facet facet_a7;
		cadena_scenario::Receptacle receptacle_a8;
		PICML::ProvidedRequestPort providedRequestPort_a9;
		PICML::RequiredRequestPort requiredRequestPort_aa;
		cadena_scenario::Scenario scenario_ab;
	};

	std::list< Match> _matches;
};

class SourcesToConnectors_ad
{
public:
	void operator()( const Packets_t& eSSConnections_ae, const Packets_t& publishConnectors_b0);

protected:
	bool isInputUnique( const Udm::Object& eSSConnection_b6, const Udm::Object& publishConnector_bf);
	void processInputPackets( const Packets_t& eSSConnections_ae, const Packets_t& publishConnectors_b0);
	bool patternMatcher( const Udm::Object& eSSConnection_b4, const Udm::Object& publishConnector_bd);
	void effector();
	void outputAppender();

private:
	Packets_t _eSSConnection_b2;
	Packets_t _publishConnector_bb;
	class Match
	{
	public:
		PICML::OutEventPort outEventPort_cb;
		cadena_scenario::EventSource eventSource_cc;
		PICML::OutEventPortPublish outEventPortPublish_cd;
		cadena_scenario::ESSConnection eSSConnection_ce;
		PICML::PublishConnector publishConnector_cf;
	};

	std::list< Match> _matches;
};

class CreatingPublishConnectors_d0
{
public:
	void operator()( const Packets_t& scenarios_d1, const Packets_t& componentAssemblys_d5, Packets_t& eSSConnections_d3, Packets_t& publishConnectors_d4);

protected:
	bool isInputUnique( const Udm::Object& scenario_dd, const Udm::Object& componentAssembly_e6);
	void processInputPackets( const Packets_t& scenarios_d1, const Packets_t& componentAssemblys_d5);
	bool patternMatcher( const Udm::Object& scenario_db, const Udm::Object& componentAssembly_e4);
	void effector();
	void outputAppender( const cadena_scenario::ESSConnection& eSSConnection_f2, const PICML::PublishConnector& publishConnector_f4);

private:
	Packets_t* _eSSConnection_d7;
	Packets_t* _publishConnector_d8;
	Packets_t _scenario_d9;
	Packets_t _componentAssembly_e2;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_ee;
		PICML::PublishConnector publishConnector_ef;
		PICML::ComponentAssembly componentAssembly_f0;
	};

	std::list< Match> _matches;
};

class PortFinder_f6
{
public:
	void operator()( const Packets_t& scenarios_f7, const Packets_t& componentAssemblys_fb, Packets_t& scenarios_f9, Packets_t& ports_fa);

protected:
	bool isInputUnique( const Udm::Object& scenario_103, const Udm::Object& componentAssembly_10c);
	void processInputPackets( const Packets_t& scenarios_f7, const Packets_t& componentAssemblys_fb);
	bool patternMatcher( const Udm::Object& scenario_101, const Udm::Object& componentAssembly_10a);
	void effector();
	void outputAppender( const cadena_scenario::Scenario& scenario_11b, const PICML::Port& port_11d);

private:
	Packets_t* _scenario_fd;
	Packets_t* _port_fe;
	Packets_t _scenario_ff;
	Packets_t _componentAssembly_108;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_117;
		PICML::Port port_118;
		PICML::ComponentDef componentDef_119;
		PICML::ComponentAssembly componentAssembly_11a;
	};

	std::list< Match> _matches;
};

class Emits_11f
{
public:
	void operator()( const Packets_t& scenarios_120, const Packets_t& outEventPorts_122);

protected:
	bool isInputUnique( const Udm::Object& scenario_128, const Udm::Object& outEventPort_131);
	void processInputPackets( const Packets_t& scenarios_120, const Packets_t& outEventPorts_122);
	bool patternMatcher( const Udm::Object& scenario_126, const Udm::Object& outEventPort_12f);
	void effector();
	void outputAppender();

private:
	Packets_t _scenario_124;
	Packets_t _outEventPort_12d;
	class Match
	{
	public:
		cadena_scenario::EventSink eventSink_13e;
		PICML::EmitConnector emitConnector_13f;
		cadena_scenario::EventSource eventSource_140;
		PICML::InEventPort inEventPort_141;
		cadena_scenario::Scenario scenario_142;
		PICML::OutEventPort outEventPort_143;
	};

	std::list< Match> _matches;
};

class RootFinder_15d
{
public:
	void operator()( const Packets_t& rootFolders_15e, const Packets_t& scenarios_160, Packets_t& scenarios_162, Packets_t& componentAssemblys_163);

protected:
	bool isInputUnique( const Udm::Object& rootFolder_16a, const Udm::Object& scenario_173);
	void processInputPackets( const Packets_t& rootFolders_15e, const Packets_t& scenarios_160);
	bool patternMatcher( const Udm::Object& rootFolder_168, const Udm::Object& scenario_171);
	void effector();
	void outputAppender( const cadena_scenario::Scenario& scenario_186, const PICML::ComponentAssembly& componentAssembly_188);

private:
	Packets_t* _scenario_164;
	Packets_t* _componentAssembly_165;
	Packets_t _rootFolder_166;
	Packets_t _scenario_16f;
	class Match
	{
	public:
		PICML::RootFolder rootFolder_181;
		cadena_scenario::Scenario scenario_182;
		PICML::ComponentImplementations componentImplementations_183;
		PICML::ComponentImplementationContainer componentImplementationContainer_184;
		PICML::ComponentAssembly componentAssembly_185;
	};

	std::list< Match> _matches;
};

class ComponentCreation_18a
{
public:
	void operator()( const Packets_t& pICML_Assembly_Ins_18b, const Packets_t& cadena_Scenario_Ins_18d, Packets_t& cadena_Scenario_Outs_18f, Packets_t& pICML_Assembly_Outs_190);

protected:
	void callComponentCreation_289( const Packets_t& componentAssemblys_194, const Packets_t& scenarios_198);
	void callPortsCreation_28c( const Packets_t& pICML_Components_1ba, const Packets_t& cadena_Components_1bc);

private:
	Packets_t* _cadena_Scenario_Out_191;
	Packets_t* _pICML_Assembly_Out_192;
};

class ComponentCreation_193
{
public:
	void operator()( const Packets_t& componentAssemblys_194, const Packets_t& scenarios_198, Packets_t& componentDefs_196, Packets_t& componentInstances_197);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_1a0, const Udm::Object& scenario_1a9);
	void processInputPackets( const Packets_t& componentAssemblys_194, const Packets_t& scenarios_198);
	bool patternMatcher( const Udm::Object& componentAssembly_19e, const Udm::Object& scenario_1a7);
	void effector();
	void outputAppender( const PICML::ComponentDef& componentDef_1b5, const cadena_scenario::ComponentInstance& componentInstance_1b7);

private:
	Packets_t* _componentDef_19a;
	Packets_t* _componentInstance_19b;
	Packets_t _componentAssembly_19c;
	Packets_t _scenario_1a5;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_1b1;
		PICML::ComponentDef componentDef_1b2;
		cadena_scenario::Scenario scenario_1b3;
	};

	std::list< Match> _matches;
};

class PortsCreation_1b9
{
public:
	void operator()( const Packets_t& pICML_Components_1ba, const Packets_t& cadena_Components_1bc);

protected:
	void callEventSources_27a( const Packets_t& componentInstances_255, const Packets_t& componentDefs_258);
	void callEventSinks_27d( const Packets_t& componentDefs_22f, const Packets_t& componentInstances_232);
	void callFacets_280( const Packets_t& componentDefs_209, const Packets_t& componentInstances_20c);
	void callReceptacles_283( const Packets_t& componentDefs_1bf, const Packets_t& componentInstances_1c2);
	void callAssignNames_286( const Packets_t& componentInstances_1e5, const Packets_t& componentDefs_1e7);
};

class Receptacles_1be
{
public:
	void operator()( const Packets_t& componentDefs_1bf, const Packets_t& componentInstances_1c2, Packets_t& componentDefs_1c1, Packets_t& componentInstances_1c4);

protected:
	bool isInputUnique( const Udm::Object& componentDef_1cb, const Udm::Object& componentInstance_1d4);
	void processInputPackets( const Packets_t& componentDefs_1bf, const Packets_t& componentInstances_1c2);
	bool patternMatcher( const Udm::Object& componentDef_1c9, const Udm::Object& componentInstance_1d2);
	void effector();
	void outputAppender( const PICML::ComponentDef& componentDef_1e0, const cadena_scenario::ComponentInstance& componentInstance_1e2);
	void forwardInputs();

private:
	Packets_t* _componentDef_1c5;
	Packets_t* _componentInstance_1c6;
	Packets_t _componentDef_1c7;
	Packets_t _componentInstance_1d0;
	class Match
	{
	public:
		PICML::RequiredRequestPort requiredRequestPort_1dc;
		PICML::ComponentDef componentDef_1dd;
		cadena_scenario::ComponentInstance componentInstance_1de;
	};

	std::list< Match> _matches;
};

class AssignNames_1e4
{
public:
	void operator()( const Packets_t& componentInstances_1e5, const Packets_t& componentDefs_1e7);

protected:
	bool isInputUnique( const Udm::Object& componentInstance_1ed, const Udm::Object& componentDef_1f6);
	void processInputPackets( const Packets_t& componentInstances_1e5, const Packets_t& componentDefs_1e7);
	bool patternMatcher( const Udm::Object& componentInstance_1eb, const Udm::Object& componentDef_1f4);
	void effector();
	void outputAppender();

private:
	Packets_t _componentInstance_1e9;
	Packets_t _componentDef_1f2;
	class Match
	{
	public:
		cadena_scenario::ComponentPort componentPort_204;
		PICML::Port port_205;
		cadena_scenario::ComponentInstance componentInstance_206;
		PICML::ComponentDef componentDef_207;
	};

	std::list< Match> _matches;
};

class Facets_208
{
public:
	void operator()( const Packets_t& componentDefs_209, const Packets_t& componentInstances_20c, Packets_t& componentDefs_20b, Packets_t& componentInstances_20e);

protected:
	bool isInputUnique( const Udm::Object& componentDef_215, const Udm::Object& componentInstance_21e);
	void processInputPackets( const Packets_t& componentDefs_209, const Packets_t& componentInstances_20c);
	bool patternMatcher( const Udm::Object& componentDef_213, const Udm::Object& componentInstance_21c);
	void effector();
	void outputAppender( const PICML::ComponentDef& componentDef_22a, const cadena_scenario::ComponentInstance& componentInstance_22c);
	void forwardInputs();

private:
	Packets_t* _componentDef_20f;
	Packets_t* _componentInstance_210;
	Packets_t _componentDef_211;
	Packets_t _componentInstance_21a;
	class Match
	{
	public:
		PICML::ProvidedRequestPort providedRequestPort_226;
		PICML::ComponentDef componentDef_227;
		cadena_scenario::ComponentInstance componentInstance_228;
	};

	std::list< Match> _matches;
};

class EventSinks_22e
{
public:
	void operator()( const Packets_t& componentDefs_22f, const Packets_t& componentInstances_232, Packets_t& componentDefs_231, Packets_t& componentInstances_234);

protected:
	bool isInputUnique( const Udm::Object& componentDef_23b, const Udm::Object& componentInstance_244);
	void processInputPackets( const Packets_t& componentDefs_22f, const Packets_t& componentInstances_232);
	bool patternMatcher( const Udm::Object& componentDef_239, const Udm::Object& componentInstance_242);
	void effector();
	void outputAppender( const PICML::ComponentDef& componentDef_250, const cadena_scenario::ComponentInstance& componentInstance_252);
	void forwardInputs();

private:
	Packets_t* _componentDef_235;
	Packets_t* _componentInstance_236;
	Packets_t _componentDef_237;
	Packets_t _componentInstance_240;
	class Match
	{
	public:
		PICML::InEventPort inEventPort_24c;
		PICML::ComponentDef componentDef_24d;
		cadena_scenario::ComponentInstance componentInstance_24e;
	};

	std::list< Match> _matches;
};

class EventSources_254
{
public:
	void operator()( const Packets_t& componentInstances_255, const Packets_t& componentDefs_258, Packets_t& componentInstances_257, Packets_t& componentDefs_25a);

protected:
	bool isInputUnique( const Udm::Object& componentInstance_261, const Udm::Object& componentDef_26a);
	void processInputPackets( const Packets_t& componentInstances_255, const Packets_t& componentDefs_258);
	bool patternMatcher( const Udm::Object& componentInstance_25f, const Udm::Object& componentDef_268);
	void effector();
	void outputAppender( const cadena_scenario::ComponentInstance& componentInstance_276, const PICML::ComponentDef& componentDef_278);
	void forwardInputs();

private:
	Packets_t* _componentInstance_25b;
	Packets_t* _componentDef_25c;
	Packets_t _componentInstance_25d;
	Packets_t _componentDef_266;
	class Match
	{
	public:
		cadena_scenario::ComponentInstance componentInstance_272;
		PICML::OutEventPort outEventPort_273;
		PICML::ComponentDef componentDef_274;
	};

	std::list< Match> _matches;
};

