#include "stdafx.h"
#include "SIMLVisitor.h"


namespace SIML
{

SIMLVisitor::SIMLVisitor()  { }

SIMLVisitor::~SIMLVisitor() { }

bool SIMLVisitor::visitAtomicType( const WSML::AtomicType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAttribute( const WSML::Attribute& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAverage( const PICML::Average& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBoolean( const PICML::Boolean& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBranchState( const PICML::BranchState& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitByte( const PICML::Byte& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentPackage( const PICML::ComponentPackage& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitDisplayNode( const PICML::DisplayNode& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitECBehavior( const PICML::ECBehavior& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitECEventFilterConfiguration( const PICML::ECEventFilterConfiguration& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitEdge( const PICML::Edge& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitEnumValue( const PICML::EnumValue& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitEnvironment( const PICML::Environment& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitExternalReferenceEndPoint( const PICML::ExternalReferenceEndPoint& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitFixedIterationBenchmarks( const PICML::FixedIterationBenchmarks& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitGenericObject( const PICML::GenericObject& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitGenericValue( const PICML::GenericValue& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitGenericValueObject( const PICML::GenericValueObject& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitImplementationArtifact( const PICML::ImplementationArtifact& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitImplementationDependency( const PICML::ImplementationDependency& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitJitter( const PICML::Jitter& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitLabel( const PICML::Label& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitLongInteger( const PICML::LongInteger& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMaximum( const PICML::Maximum& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMinimum( const PICML::Minimum& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMonolithicImplementation( const PICML::MonolithicImplementation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMultipleServiceRequests( const PICML::MultipleServiceRequests& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageConfiguration( const PICML::PackageConfiguration& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPeriodicBenchmarks( const PICML::PeriodicBenchmarks& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPeriodicEvent( const PICML::PeriodicEvent& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPrivateFlag( const PICML::PrivateFlag& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPublishConnector( const PICML::PublishConnector& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitRealNumber( const PICML::RealNumber& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSOAPAddress( const WSML::SOAPAddress& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSOAPBinding( const WSML::SOAPBinding& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSOAPBody( const WSML::SOAPBody& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSOAPFault( const WSML::SOAPFault& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSOAPHeaderFault( const WSML::SOAPHeaderFault& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSOAPOperation( const WSML::SOAPOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitServiceConsumer( const PICML::ServiceConsumer& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitServiceLevels( const PICML::ServiceLevels& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitShortInteger( const PICML::ShortInteger& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitState( const PICML::State& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitStateBase( const PICML::StateBase& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitString( const PICML::String& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTask( const PICML::Task& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTimeProbe( const PICML::TimeProbe& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTopLevelPackage( const PICML::TopLevelPackage& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTriggerBenchmarks( const PICML::TriggerBenchmarks& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTypeEncoding( const PICML::TypeEncoding& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTypeKind( const PICML::TypeKind& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAction( const PICML::Action& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitActionBase( const PICML::ActionBase& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAggregate( const PICML::Aggregate& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitArtifactContainer( const PICML::ArtifactContainer& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAttribute( const PICML::Attribute& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBehaviorModel( const PICML::BehaviorModel& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBenchmarkAnalysis( const PICML::BenchmarkAnalysis& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBinding( const WSML::Binding& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBindingOperation( const WSML::BindingOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBridge( const PICML::Bridge& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitCapability( const PICML::Capability& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponent( const PICML::Component& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentAssembly( const PICML::ComponentAssembly& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentContainer( const PICML::ComponentContainer& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentFactory( const PICML::ComponentFactory& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentImplementationContainer( const PICML::ComponentImplementationContainer& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentPropertyDescription( const PICML::ComponentPropertyDescription& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitCompositeAction( const PICML::CompositeAction& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitConnectedComponent( const PICML::ConnectedComponent& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitDefinitions( const WSML::Definitions& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitDeploymentPlan( const PICML::DeploymentPlan& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitDocumentation( const WSML::Documentation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitDomain( const PICML::Domain& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitECConfiguration( const PICML::ECConfiguration& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitECConsumer( const PICML::ECConsumer& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitECRole( const PICML::ECRole& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitECSupplier( const PICML::ECSupplier& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitElement( const WSML::Element& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitEnum( const PICML::Enum& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitEvent( const PICML::Event& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitException( const PICML::Exception& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitExecutorProject( const PICML::ExecutorProject& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitFactoryOperation( const PICML::FactoryOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitFault( const WSML::Fault& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitFile( const PICML::File& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitHasExceptions( const PICML::HasExceptions& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitHasOperations( const PICML::HasOperations& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitImplementationRequirement( const PICML::ImplementationRequirement& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitImport( const WSML::Import& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInheritable( const PICML::Inheritable& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInput( const WSML::Input& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInputAction( const PICML::InputAction& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInterconnect( const PICML::Interconnect& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitLatency( const PICML::Latency& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitLookupOperation( const PICML::LookupOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMPC( const PICML::MPC& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMessage( const WSML::Message& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMessages( const WSML::Messages& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMetricsBase( const PICML::MetricsBase& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitNode( const PICML::Node& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitNotificationOperation( const WSML::NotificationOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitObject( const PICML::Object& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitObjectByValue( const PICML::ObjectByValue& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOneWayOperation( const WSML::OneWayOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOnewayOperation( const PICML::OnewayOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOperation( const WSML::Operation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOperationBase( const PICML::OperationBase& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOutput( const WSML::Output& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOutputAction( const PICML::OutputAction& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackage( const PICML::Package& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageConfigurationContainer( const PICML::PackageConfigurationContainer& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageContainer( const PICML::PackageContainer& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPath( const PICML::Path& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPaths( const PICML::Paths& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPort( const WSML::Port& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPortType( const WSML::PortType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPrefixable( const PICML::Prefixable& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitProject( const PICML::Project& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitProperty( const PICML::Property& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitRTRequirements( const PICML::RTRequirements& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitReadonlyAttribute( const PICML::ReadonlyAttribute& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitRequestResponseOperation( const WSML::RequestResponseOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitRequirement( const PICML::Requirement& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitRequirementBase( const PICML::RequirementBase& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitRequirementSatisfier( const PICML::RequirementSatisfier& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitResource( const PICML::Resource& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSOAPHeader( const WSML::SOAPHeader& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSatisfierProperty( const PICML::SatisfierProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSchema( const WSML::Schema& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSchemaBuiltins( const WSML::SchemaBuiltins& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSchemaImport( const WSML::SchemaImport& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSchemaReference( const WSML::SchemaReference& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitServantProject( const PICML::ServantProject& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitService( const WSML::Service& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitServiceProvider( const PICML::ServiceProvider& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSharedResource( const PICML::SharedResource& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSolicitResponseOperation( const WSML::SolicitResponseOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitStubProject( const PICML::StubProject& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSupportsInterfaces( const PICML::SupportsInterfaces& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSwitchedAggregate( const PICML::SwitchedAggregate& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSystem( const SIML::System& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitThroughput( const PICML::Throughput& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTopLevelBehavior( const PICML::TopLevelBehavior& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTopLevelPackageContainer( const PICML::TopLevelPackageContainer& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTwowayOperation( const PICML::TwowayOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTypes( const WSML::Types& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitValueObject( const PICML::ValueObject& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitWorker( const PICML::Worker& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitWorkerFile( const PICML::WorkerFile& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitWorkerLibrary( const PICML::WorkerLibrary& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitWorkerPackage( const PICML::WorkerPackage& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitWorkerPackageBase( const PICML::WorkerPackageBase& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitArtifactDependency( const PICML::ArtifactDependency& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitArtifactDependsOn( const PICML::ArtifactDependsOn& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitArtifactDeployRequirement( const PICML::ArtifactDeployRequirement& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitArtifactExecParameter( const PICML::ArtifactExecParameter& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitArtifactInfoProperty( const PICML::ArtifactInfoProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAssemblyConfigProperty( const PICML::AssemblyConfigProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAssemblyDeployRequirement( const PICML::AssemblyDeployRequirement& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAssemblyselectRequirement( const PICML::AssemblyselectRequirement& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAttributeDelegate( const PICML::AttributeDelegate& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAttributeMappingDelegate( const PICML::AttributeMappingDelegate& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAttributeMappingValue( const PICML::AttributeMappingValue& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAttributeValue( const PICML::AttributeValue& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBenchmarkCharacteristics( const PICML::BenchmarkCharacteristics& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBindingPortType( const WSML::BindingPortType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBindsOperation( const WSML::BindsOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBodyBinding( const WSML::BodyBinding& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBodyParts( const WSML::BodyParts& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBranchTransition( const PICML::BranchTransition& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBridge2Interconnect( const PICML::Bridge2Interconnect& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentConfigProperty( const PICML::ComponentConfigProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentInfoProperty( const PICML::ComponentInfoProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentOperation( const PICML::ComponentOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentProperty( const PICML::ComponentProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitConfigProperty( const PICML::ConfigProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitConsumer2BehaviorConnection( const PICML::Consumer2BehaviorConnection& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitCriticalPath( const PICML::CriticalPath& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitDstEdge( const PICML::DstEdge& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitEdgeProperty( const PICML::EdgeProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitEffect( const PICML::Effect& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitEventSinkDelegate( const PICML::EventSinkDelegate& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitEventSourceDelegate( const PICML::EventSourceDelegate& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitExtResourceConn( const PICML::ExtResourceConn& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitExternalDelegate( const PICML::ExternalDelegate& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitFacetDelegate( const PICML::FacetDelegate& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitFaultMessage( const WSML::FaultMessage& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitFinish( const PICML::Finish& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitHeaderBinding( const WSML::HeaderBinding& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitHeaderMessage( const WSML::HeaderMessage& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitHeaderPart( const WSML::HeaderPart& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitImplementation( const PICML::Implementation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitImplementationCapability( const PICML::ImplementationCapability& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitImplementationDependsOn( const PICML::ImplementationDependsOn& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitImplements( const PICML::Implements& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInfoProperty( const PICML::InfoProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInput( const PICML::Input& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInputEffect( const PICML::InputEffect& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInputMessage( const WSML::InputMessage& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInstanceMapping( const PICML::InstanceMapping& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInterconnect2Bridge( const PICML::Interconnect2Bridge& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInterconnect2Node( const PICML::Interconnect2Node& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitLabelConnection( const PICML::LabelConnection& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMakeMemberPrivate( const PICML::MakeMemberPrivate& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitManagesComponent( const PICML::ManagesComponent& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMetricConnection( const PICML::MetricConnection& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMonolithDeployRequirement( const PICML::MonolithDeployRequirement& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMonolithExecParameter( const PICML::MonolithExecParameter& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMonolithprimaryArtifact( const PICML::MonolithprimaryArtifact& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMultiInput( const PICML::MultiInput& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitNode2Interconnect( const PICML::Node2Interconnect& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOutputMessage( const WSML::OutputMessage& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageConfBasePackage( const PICML::PackageConfBasePackage& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageConfConfigProperty( const PICML::PackageConfConfigProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageConfReference( const PICML::PackageConfReference& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageConfSelectRequirement( const PICML::PackageConfSelectRequirement& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageConfSpecializedConfig( const PICML::PackageConfSpecializedConfig& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageConfigProperty( const PICML::PackageConfigProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageInfoProperty( const PICML::PackageInfoProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageInterface( const PICML::PackageInterface& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPathProperty( const PICML::PathProperty& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPortBinding( const WSML::PortBinding& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPortProxy( const SIML::PortProxy& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitReceptacleDelegate( const PICML::ReceptacleDelegate& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitRecursiveFilterConnection( const PICML::RecursiveFilterConnection& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSOAPFaultExtension( const WSML::SOAPFaultExtension& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitShares( const PICML::Shares& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSrcEdge( const PICML::SrcEdge& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSupplier2FilterConnection( const PICML::Supplier2FilterConnection& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTimerConnection( const PICML::TimerConnection& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTimerEventSinkConn( const PICML::TimerEventSinkConn& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTransition( const PICML::Transition& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitWorkLoadOperationConnection( const PICML::WorkLoadOperationConnection& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitWorkloadCharacteristics( const PICML::WorkloadCharacteristics& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitdeliverTo( const PICML::deliverTo& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitemit( const PICML::emit& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitinvoke( const PICML::invoke& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitpackage( const PICML::package& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitpublish( const PICML::publish& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitCollocationGroup( const PICML::CollocationGroup& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTaskSet( const PICML::TaskSet& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitWorkspaces( const PICML::Workspaces& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAlias( const PICML::Alias& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAttributeMapping( const PICML::AttributeMapping& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitAttributeMember( const PICML::AttributeMember& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBindingRef( const WSML::BindingRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBoxed( const PICML::Boxed& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitCollection( const PICML::Collection& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitCompRef( const PICML::CompRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentAssemblyReference( const PICML::ComponentAssemblyReference& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentImplementationReference( const PICML::ComponentImplementationReference& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentPackageReference( const PICML::ComponentPackageReference& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentRef( const PICML::ComponentRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitConstant( const PICML::Constant& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitDataType( const PICML::DataType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitDiscriminator( const PICML::Discriminator& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitEventRef( const PICML::EventRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitExceptionRef( const PICML::ExceptionRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitExternalResources( const PICML::ExternalResources& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitFaultRef( const WSML::FaultRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitFileRef( const PICML::FileRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitGetException( const PICML::GetException& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitImplementationArtifactReference( const PICML::ImplementationArtifactReference& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInEventPort( const PICML::InEventPort& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInParameter( const PICML::InParameter& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInherits( const PICML::Inherits& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInoutParameter( const PICML::InoutParameter& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInputRef( const WSML::InputRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitLookupKey( const PICML::LookupKey& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMember( const PICML::Member& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMessageRef( const WSML::MessageRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitNodeReference( const PICML::NodeReference& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOperationRef( const WSML::OperationRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOperationRef( const PICML::OperationRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOutEventPort( const PICML::OutEventPort& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOutParameter( const PICML::OutParameter& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitOutputRef( const WSML::OutputRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageConfigurationReference( const PICML::PackageConfigurationReference& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitParameterType( const PICML::ParameterType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPart( const WSML::Part& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPartRef( const WSML::PartRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPathReference( const PICML::PathReference& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitProvidedRequestPort( const PICML::ProvidedRequestPort& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitRequiredRequestPort( const PICML::RequiredRequestPort& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitReturnType( const PICML::ReturnType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitServiceRef( const WSML::ServiceRef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSetException( const PICML::SetException& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSharedComponentReference( const PICML::SharedComponentReference& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSupports( const PICML::Supports& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitVariable( const PICML::Variable& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitWorkerType( const PICML::WorkerType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitBenchmarkType( const PICML::BenchmarkType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitCommonPortAttrs( const PICML::CommonPortAttrs& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentImplementation( const PICML::ComponentImplementation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentLib( const PICML::ComponentLib& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitConstantType( const PICML::ConstantType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitDataAnalysisBase( const PICML::DataAnalysisBase& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitElements( const PICML::Elements& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitExtensibilityElement( const WSML::ExtensibilityElement& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitExtensibleBinding( const WSML::ExtensibleBinding& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitExtensibleMessage( const WSML::ExtensibleMessage& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitExtensibleOperation( const WSML::ExtensibleOperation& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitExtensiblePort( const WSML::ExtensiblePort& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitGraphVertex( const PICML::GraphVertex& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitIORef( const WSML::IORef& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitManageable( const PICML::Manageable& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMemberType( const PICML::MemberType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMultiInputBase( const PICML::MultiInputBase& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitMultiOutputBase( const PICML::MultiOutputBase& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitNamedType( const PICML::NamedType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitNoInheritable( const PICML::NoInheritable& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPort( const PICML::Port& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPredefinedType( const PICML::PredefinedType& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitProvideable( const PICML::Provideable& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitReferrable( const WSML::Referrable& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSOAPHeaders( const WSML::SOAPHeaders& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSingleInputBase( const PICML::SingleInputBase& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitSingleOutputBase( const PICML::SingleOutputBase& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTaggable( const PICML::Taggable& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentAnalyses( const PICML::ComponentAnalyses& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentBuild( const PICML::ComponentBuild& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentImplementations( const PICML::ComponentImplementations& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentPackages( const PICML::ComponentPackages& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitComponentTypes( const PICML::ComponentTypes& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitDeploymentPlans( const PICML::DeploymentPlans& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitImplementationArtifacts( const PICML::ImplementationArtifacts& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitInterfaceDefinitions( const PICML::InterfaceDefinitions& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPackageConfigurations( const PICML::PackageConfigurations& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPathDiagrams( const PICML::PathDiagrams& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitPredefinedTypes( const PICML::PredefinedTypes& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTargets( const PICML::Targets& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitTopLevelPackages( const PICML::TopLevelPackages& object )
{
	if ( !object)
		return false;

	return true;
}


bool SIMLVisitor::visitWorkerLibraries( const PICML::WorkerLibraries& object )
{
	if ( !object)
		return false;

	return true;
}



} // namespace

