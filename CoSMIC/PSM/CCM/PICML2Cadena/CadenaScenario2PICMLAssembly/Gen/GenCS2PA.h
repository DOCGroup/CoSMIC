#include <UdmBase.h>
#include <cint_string.h>
#include "CadenaScenario2PICMLAssembly.h"
#include "CrossLinks.h"
#include "PICML.h"
#include "cadena_scenario.h"

typedef std::list< Udm::Object> Packets_t;

// Forward declarations.
class RootRuleBlock_0;
class PortConnection_5;
class ConnectorsToSinks_a;
class TransferingCorrelatorStrings_32;
class InputSplitter_57;
class MethodInvocations_78;
class SourcesToConnectors_a7;
class CreatingPublishConnectors_cf;
class PortFinder_f5;
class RootFinder_133;
class ComponentCreation_157;
class ComponentAlignment_160;
class AssociatingPorts_18d;
class PortsCreation_1b2;
class Receptacles_1b7;
class AssignNames_1dd;
class Facets_201;
class EventSinks_227;
class EventSources_24d;
class ComponentCreation_282;

// Class declarations.
class RootRuleBlock_0
{
public:
	void operator()( const Packets_t& pICML_File_Ins_1, const Packets_t& cadena_File_Ins_3);

protected:
	void callRootFinder_2ce( const Packets_t& rootFolders_134, const Packets_t& scenarios_136);
	void callComponentCreation_2d1( const Packets_t& pICML_Assembly_Ins_158, const Packets_t& cadena_Scenario_Ins_15a);
	void callPortConnection_2d4( const Packets_t& pICML_Assembly_Ins_6, const Packets_t& cadena_Scenario_Ins_8);
};

class PortConnection_5
{
public:
	void operator()( const Packets_t& pICML_Assembly_Ins_6, const Packets_t& cadena_Scenario_Ins_8);

protected:
	void callInputSplitter_11e( const Packets_t& scenarios_58, const Packets_t& componentAssemblys_5b);
	void callCreatingPublishConnectors_121( const Packets_t& scenarios_d0, const Packets_t& componentAssemblys_d4);
	void callPortFinder_124( const Packets_t& scenarios_f6, const Packets_t& componentAssemblys_fa);
	void callConnectorsToSinks_127( const Packets_t& publishConnectors_b, const Packets_t& eSSConnections_d);
	void callTransferingCorrelatorStrings_12a( const Packets_t& publishConnectors_33, const Packets_t& eSSConnections_35);
	void callSourcesToConnectors_12d( const Packets_t& eSSConnections_a8, const Packets_t& publishConnectors_aa);
	void callMethodInvocations_130( const Packets_t& requiredRequestPorts_79, const Packets_t& scenarios_7b);
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
		PICML::ComponentAssembly componentAssembly_2b;
		PICML::ComponentDef componentDef_2c;
		cadena_scenario::EventSink eventSink_2d;
		PICML::InEventPort inEventPort_2e;
		PICML::PublishConnector publishConnector_2f;
		cadena_scenario::ESSConnection eSSConnection_30;
	};

	std::list< Match> _matches;
};

class TransferingCorrelatorStrings_32
{
public:
	void operator()( const Packets_t& publishConnectors_33, const Packets_t& eSSConnections_35);

protected:
	bool isInputUnique( const Udm::Object& publishConnector_3b, const Udm::Object& eSSConnection_44);
	bool isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ESSConnection, const Udm::Object& PublishConnector);
	void processInputPackets( const Packets_t& publishConnectors_33, const Packets_t& eSSConnections_35);
	bool patternMatcher( const Udm::Object& publishConnector_39, const Udm::Object& eSSConnection_42);
	void effector();
	void outputAppender();

private:
	Packets_t _publishConnector_37;
	Packets_t _eSSConnection_40;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_4b;
		PICML::PublishConnector publishConnector_4c;
		cadena_scenario::ESSConnection eSSConnection_4d;
	};

	std::list< Match> _matches;
};

class InputSplitter_57
{
public:
	void operator()( const Packets_t& scenarios_58, const Packets_t& componentAssemblys_5b, Packets_t& scenarios_5a, Packets_t& componentAssemblys_5d);

protected:
	bool isInputUnique( const Udm::Object& scenario_64, const Udm::Object& componentAssembly_6d);
	void processInputPackets( const Packets_t& scenarios_58, const Packets_t& componentAssemblys_5b);
	bool patternMatcher( const Udm::Object& scenario_62, const Udm::Object& componentAssembly_6b);
	void effector();
	void outputAppender( const cadena_scenario::Scenario& scenario_74, const PICML::ComponentAssembly& componentAssembly_76);
	void forwardInputs();

private:
	Packets_t* _scenario_5e;
	Packets_t* _componentAssembly_5f;
	Packets_t _scenario_60;
	Packets_t _componentAssembly_69;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_72;
		PICML::ComponentAssembly componentAssembly_73;
	};

	std::list< Match> _matches;
};

class MethodInvocations_78
{
public:
	void operator()( const Packets_t& requiredRequestPorts_79, const Packets_t& scenarios_7b);

protected:
	bool isInputUnique( const Udm::Object& requiredRequestPort_81, const Udm::Object& scenario_8a);
	void processInputPackets( const Packets_t& requiredRequestPorts_79, const Packets_t& scenarios_7b);
	bool patternMatcher( const Udm::Object& requiredRequestPort_7f, const Udm::Object& scenario_88);
	void effector();
	void outputAppender();

private:
	Packets_t _requiredRequestPort_7d;
	Packets_t _scenario_86;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_9e;
		PICML::ComponentDef componentDef_9f;
		cadena_scenario::FRConnection fRConnection_a0;
		cadena_scenario::Facet facet_a1;
		cadena_scenario::Receptacle receptacle_a2;
		PICML::ProvidedRequestPort providedRequestPort_a3;
		PICML::RequiredRequestPort requiredRequestPort_a4;
		cadena_scenario::Scenario scenario_a5;
	};

	std::list< Match> _matches;
};

class SourcesToConnectors_a7
{
public:
	void operator()( const Packets_t& eSSConnections_a8, const Packets_t& publishConnectors_aa);

protected:
	bool isInputUnique( const Udm::Object& eSSConnection_b0, const Udm::Object& publishConnector_b9);
	void processInputPackets( const Packets_t& eSSConnections_a8, const Packets_t& publishConnectors_aa);
	bool patternMatcher( const Udm::Object& eSSConnection_ae, const Udm::Object& publishConnector_b7);
	void effector();
	void outputAppender();

private:
	Packets_t _eSSConnection_ac;
	Packets_t _publishConnector_b5;
	class Match
	{
	public:
		PICML::ComponentAssembly componentAssembly_c8;
		PICML::ComponentDef componentDef_c9;
		cadena_scenario::EventSource eventSource_ca;
		PICML::OutEventPort outEventPort_cb;
		cadena_scenario::ESSConnection eSSConnection_cc;
		PICML::PublishConnector publishConnector_cd;
	};

	std::list< Match> _matches;
};

class CreatingPublishConnectors_cf
{
public:
	void operator()( const Packets_t& scenarios_d0, const Packets_t& componentAssemblys_d4, Packets_t& eSSConnections_d2, Packets_t& publishConnectors_d3);

protected:
	bool isInputUnique( const Udm::Object& scenario_dc, const Udm::Object& componentAssembly_e5);
	void processInputPackets( const Packets_t& scenarios_d0, const Packets_t& componentAssemblys_d4);
	bool patternMatcher( const Udm::Object& scenario_da, const Udm::Object& componentAssembly_e3);
	void effector();
	void outputAppender( const cadena_scenario::ESSConnection& eSSConnection_f1, const PICML::PublishConnector& publishConnector_f3);

private:
	Packets_t* _eSSConnection_d6;
	Packets_t* _publishConnector_d7;
	Packets_t _scenario_d8;
	Packets_t _componentAssembly_e1;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_ed;
		cadena_scenario::ESSConnection eSSConnection_ee;
		PICML::ComponentAssembly componentAssembly_ef;
	};

	std::list< Match> _matches;
};

class PortFinder_f5
{
public:
	void operator()( const Packets_t& scenarios_f6, const Packets_t& componentAssemblys_fa, Packets_t& scenarios_f8, Packets_t& ports_f9);

protected:
	bool isInputUnique( const Udm::Object& scenario_102, const Udm::Object& componentAssembly_10b);
	void processInputPackets( const Packets_t& scenarios_f6, const Packets_t& componentAssemblys_fa);
	bool patternMatcher( const Udm::Object& scenario_100, const Udm::Object& componentAssembly_109);
	void effector();
	void outputAppender( const cadena_scenario::Scenario& scenario_11a, const PICML::Port& port_11c);

private:
	Packets_t* _scenario_fc;
	Packets_t* _port_fd;
	Packets_t _scenario_fe;
	Packets_t _componentAssembly_107;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_116;
		PICML::Port port_117;
		PICML::ComponentDef componentDef_118;
		PICML::ComponentAssembly componentAssembly_119;
	};

	std::list< Match> _matches;
};

class RootFinder_133
{
public:
	void operator()( const Packets_t& rootFolders_134, const Packets_t& scenarios_136, Packets_t& scenarios_138, Packets_t& componentAssemblys_139);

protected:
	bool isInputUnique( const Udm::Object& rootFolder_140, const Udm::Object& scenario_149);
	void processInputPackets( const Packets_t& rootFolders_134, const Packets_t& scenarios_136);
	bool patternMatcher( const Udm::Object& rootFolder_13e, const Udm::Object& scenario_147);
	void effector();
	void outputAppender( const cadena_scenario::Scenario& scenario_153, const PICML::ComponentAssembly& componentAssembly_155);

private:
	Packets_t* _scenario_13a;
	Packets_t* _componentAssembly_13b;
	Packets_t _rootFolder_13c;
	Packets_t _scenario_145;
	class Match
	{
	public:
		PICML::RootFolder rootFolder_14e;
		cadena_scenario::Scenario scenario_14f;
	};

	std::list< Match> _matches;
};

class ComponentCreation_157
{
public:
	void operator()( const Packets_t& pICML_Assembly_Ins_158, const Packets_t& cadena_Scenario_Ins_15a, Packets_t& cadena_Scenario_Outs_15c, Packets_t& pICML_Assembly_Outs_15d);

protected:
	void callComponentCreation_2c5( const Packets_t& componentAssemblys_283, const Packets_t& scenarios_286);
	void callComponentAlignment_2c8( const Packets_t& scenarios_161, const Packets_t& componentAssemblys_165);
	void callAssociatingPorts_2cb( const Packets_t& componentInstances_18e, const Packets_t& componentDefs_190);

private:
	Packets_t* _cadena_Scenario_Out_15e;
	Packets_t* _pICML_Assembly_Out_15f;
};

class ComponentAlignment_160
{
public:
	void operator()( const Packets_t& scenarios_161, const Packets_t& componentAssemblys_165, Packets_t& componentDefs_163, Packets_t& componentInstances_164);

protected:
	bool isInputUnique( const Udm::Object& scenario_16d, const Udm::Object& componentAssembly_176);
	bool isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ComponentDef, const Udm::Object& ComponentInstance, const Udm::Object& Scenario);
	void processInputPackets( const Packets_t& scenarios_161, const Packets_t& componentAssemblys_165);
	bool patternMatcher( const Udm::Object& scenario_16b, const Udm::Object& componentAssembly_174);
	void effector();
	void outputAppender( const PICML::ComponentDef& componentDef_189, const cadena_scenario::ComponentInstance& componentInstance_18b);

private:
	Packets_t* _componentDef_167;
	Packets_t* _componentInstance_168;
	Packets_t _scenario_169;
	Packets_t _componentAssembly_172;
	class Match
	{
	public:
		cadena_scenario::Scenario scenario_181;
		PICML::ComponentDef componentDef_182;
		cadena_scenario::ComponentInstance componentInstance_183;
		PICML::ComponentAssembly componentAssembly_184;
	};

	std::list< Match> _matches;
};

class AssociatingPorts_18d
{
public:
	void operator()( const Packets_t& componentInstances_18e, const Packets_t& componentDefs_190);

protected:
	bool isInputUnique( const Udm::Object& componentInstance_196, const Udm::Object& componentDef_19f);
	bool isGuardTrue( const Udm::Object& ComponentDef, const Udm::Object& ComponentInstance, const Udm::Object& ComponentPort, const Udm::Object& Port);
	void processInputPackets( const Packets_t& componentInstances_18e, const Packets_t& componentDefs_190);
	bool patternMatcher( const Udm::Object& componentInstance_194, const Udm::Object& componentDef_19d);
	void effector();
	void outputAppender();

private:
	Packets_t _componentInstance_192;
	Packets_t _componentDef_19b;
	class Match
	{
	public:
		PICML::Port port_1aa;
		cadena_scenario::ComponentPort componentPort_1ab;
		cadena_scenario::ComponentInstance componentInstance_1ac;
		PICML::ComponentDef componentDef_1ad;
	};

	std::list< Match> _matches;
};

class PortsCreation_1b2
{
public:
	void operator()( const Packets_t& pICML_Components_1b3, const Packets_t& cadena_Components_1b5);

protected:
	void callEventSources_273( const Packets_t& componentInstances_24e, const Packets_t& componentDefs_251);
	void callEventSinks_276( const Packets_t& componentDefs_228, const Packets_t& componentInstances_22b);
	void callFacets_279( const Packets_t& componentDefs_202, const Packets_t& componentInstances_205);
	void callReceptacles_27c( const Packets_t& componentDefs_1b8, const Packets_t& componentInstances_1bb);
	void callAssignNames_27f( const Packets_t& componentInstances_1de, const Packets_t& componentDefs_1e0);
};

class Receptacles_1b7
{
public:
	void operator()( const Packets_t& componentDefs_1b8, const Packets_t& componentInstances_1bb, Packets_t& componentDefs_1ba, Packets_t& componentInstances_1bd);

protected:
	bool isInputUnique( const Udm::Object& componentDef_1c4, const Udm::Object& componentInstance_1cd);
	void processInputPackets( const Packets_t& componentDefs_1b8, const Packets_t& componentInstances_1bb);
	bool patternMatcher( const Udm::Object& componentDef_1c2, const Udm::Object& componentInstance_1cb);
	void effector();
	void outputAppender( const PICML::ComponentDef& componentDef_1d9, const cadena_scenario::ComponentInstance& componentInstance_1db);
	void forwardInputs();

private:
	Packets_t* _componentDef_1be;
	Packets_t* _componentInstance_1bf;
	Packets_t _componentDef_1c0;
	Packets_t _componentInstance_1c9;
	class Match
	{
	public:
		PICML::RequiredRequestPort requiredRequestPort_1d5;
		PICML::ComponentDef componentDef_1d6;
		cadena_scenario::ComponentInstance componentInstance_1d7;
	};

	std::list< Match> _matches;
};

class AssignNames_1dd
{
public:
	void operator()( const Packets_t& componentInstances_1de, const Packets_t& componentDefs_1e0);

protected:
	bool isInputUnique( const Udm::Object& componentInstance_1e6, const Udm::Object& componentDef_1ef);
	void processInputPackets( const Packets_t& componentInstances_1de, const Packets_t& componentDefs_1e0);
	bool patternMatcher( const Udm::Object& componentInstance_1e4, const Udm::Object& componentDef_1ed);
	void effector();
	void outputAppender();

private:
	Packets_t _componentInstance_1e2;
	Packets_t _componentDef_1eb;
	class Match
	{
	public:
		cadena_scenario::ComponentPort componentPort_1fd;
		PICML::Port port_1fe;
		cadena_scenario::ComponentInstance componentInstance_1ff;
		PICML::ComponentDef componentDef_200;
	};

	std::list< Match> _matches;
};

class Facets_201
{
public:
	void operator()( const Packets_t& componentDefs_202, const Packets_t& componentInstances_205, Packets_t& componentDefs_204, Packets_t& componentInstances_207);

protected:
	bool isInputUnique( const Udm::Object& componentDef_20e, const Udm::Object& componentInstance_217);
	void processInputPackets( const Packets_t& componentDefs_202, const Packets_t& componentInstances_205);
	bool patternMatcher( const Udm::Object& componentDef_20c, const Udm::Object& componentInstance_215);
	void effector();
	void outputAppender( const PICML::ComponentDef& componentDef_223, const cadena_scenario::ComponentInstance& componentInstance_225);
	void forwardInputs();

private:
	Packets_t* _componentDef_208;
	Packets_t* _componentInstance_209;
	Packets_t _componentDef_20a;
	Packets_t _componentInstance_213;
	class Match
	{
	public:
		PICML::ProvidedRequestPort providedRequestPort_21f;
		PICML::ComponentDef componentDef_220;
		cadena_scenario::ComponentInstance componentInstance_221;
	};

	std::list< Match> _matches;
};

class EventSinks_227
{
public:
	void operator()( const Packets_t& componentDefs_228, const Packets_t& componentInstances_22b, Packets_t& componentDefs_22a, Packets_t& componentInstances_22d);

protected:
	bool isInputUnique( const Udm::Object& componentDef_234, const Udm::Object& componentInstance_23d);
	void processInputPackets( const Packets_t& componentDefs_228, const Packets_t& componentInstances_22b);
	bool patternMatcher( const Udm::Object& componentDef_232, const Udm::Object& componentInstance_23b);
	void effector();
	void outputAppender( const PICML::ComponentDef& componentDef_249, const cadena_scenario::ComponentInstance& componentInstance_24b);
	void forwardInputs();

private:
	Packets_t* _componentDef_22e;
	Packets_t* _componentInstance_22f;
	Packets_t _componentDef_230;
	Packets_t _componentInstance_239;
	class Match
	{
	public:
		PICML::InEventPort inEventPort_245;
		PICML::ComponentDef componentDef_246;
		cadena_scenario::ComponentInstance componentInstance_247;
	};

	std::list< Match> _matches;
};

class EventSources_24d
{
public:
	void operator()( const Packets_t& componentInstances_24e, const Packets_t& componentDefs_251, Packets_t& componentInstances_250, Packets_t& componentDefs_253);

protected:
	bool isInputUnique( const Udm::Object& componentInstance_25a, const Udm::Object& componentDef_263);
	void processInputPackets( const Packets_t& componentInstances_24e, const Packets_t& componentDefs_251);
	bool patternMatcher( const Udm::Object& componentInstance_258, const Udm::Object& componentDef_261);
	void effector();
	void outputAppender( const cadena_scenario::ComponentInstance& componentInstance_26f, const PICML::ComponentDef& componentDef_271);
	void forwardInputs();

private:
	Packets_t* _componentInstance_254;
	Packets_t* _componentDef_255;
	Packets_t _componentInstance_256;
	Packets_t _componentDef_25f;
	class Match
	{
	public:
		cadena_scenario::ComponentInstance componentInstance_26b;
		PICML::OutEventPort outEventPort_26c;
		PICML::ComponentDef componentDef_26d;
	};

	std::list< Match> _matches;
};

class ComponentCreation_282
{
public:
	void operator()( const Packets_t& componentAssemblys_283, const Packets_t& scenarios_286, Packets_t& componentAssemblys_285, Packets_t& scenarios_288);

protected:
	bool isInputUnique( const Udm::Object& componentAssembly_28f, const Udm::Object& scenario_298);
	bool isGuardTrue( const Udm::Object& ComponentAssembly, const Udm::Object& ComponentDef, const Udm::Object& ComponentImplementationContainer, const Udm::Object& ComponentImplementations, const Udm::Object& ComponentInstance, const Udm::Object& IDLFile, const Udm::Object& IDLFiles, const Udm::Object& RootFolder, const Udm::Object& Scenario);
	void processInputPackets( const Packets_t& componentAssemblys_283, const Packets_t& scenarios_286);
	bool patternMatcher( const Udm::Object& componentAssembly_28d, const Udm::Object& scenario_296);
	void effector();
	void outputAppender( const PICML::ComponentAssembly& componentAssembly_2c1, const cadena_scenario::Scenario& scenario_2c3);
	void forwardInputs();

private:
	Packets_t* _componentAssembly_289;
	Packets_t* _scenario_28a;
	Packets_t _componentAssembly_28b;
	Packets_t _scenario_294;
	class Match
	{
	public:
		PICML::ComponentDef componentDef_2af;
		cadena_scenario::ComponentInstance componentInstance_2b0;
		PICML::IDLFile iDLFile_2b1;
		PICML::IDLFiles iDLFiles_2b2;
		PICML::RootFolder rootFolder_2b3;
		PICML::ComponentImplementationContainer componentImplementationContainer_2b4;
		PICML::ComponentImplementations componentImplementations_2b5;
		PICML::ComponentAssembly componentAssembly_2b6;
		cadena_scenario::Scenario scenario_2b7;
	};

	std::list< Match> _matches;
};

