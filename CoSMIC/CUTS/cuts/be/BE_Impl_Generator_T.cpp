// $Id$

#if !defined (__CUTS_INLINE__)
#include "BE_Impl_Generator_T.inl"
#endif

#include "BE_algorithm.h"
#include "BE_Preprocessor.h"
#include "BE_Env_Visitor_T.h"
#include "BE_Execution_Visitor_T.h"
#include "BE_Assembly_Generator_T.h"
#include "UDM_Utility_T.h"

#include "boost/bind.hpp"
#include "boost/iterator/filter_iterator.hpp"

//
// Visit_RootFolder
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_RootFolder (const PICML::RootFolder & root)
{
  typedef std::vector <PICML::ComponentImplementations> Folder_Set;
  Folder_Set folders = root.ComponentImplementations_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (folders,
    boost::bind (&Folder_Set::value_type::Accept, _1, boost::ref (*this)));
}

//
// Visit_ComponentImplementations
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ComponentImplementations (
const PICML::ComponentImplementations & impls)
{
  typedef std::vector <PICML::ComponentImplementationContainer> Container_Set;
  Container_Set container = impls.ComponentImplementationContainer_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (container,
    boost::bind (&Container_Set::value_type::Accept, _1, boost::ref (*this)));
}

//
// Visit_ComponentImplementationContainer
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ComponentImplementationContainer (
const PICML::ComponentImplementationContainer & container)
{
  // Get this component implementation. This can either be an
  // assembly, or a monolithic implementation.
  PICML::ComponentImplementation impl = container.ComponentImplementation_child ();

  if (impl != Udm::null)
  {
    if (impl.type () == PICML::MonolithicImplementation::meta)
    {
      PICML::MonolithicImplementation monoimpl =
        PICML::MonolithicImplementation::Cast (impl);

      CUTS_BE::visit <IMPL_STRATEGY> (monoimpl,
        boost::bind (&PICML::MonolithicImplementation::Accept, _1, boost::ref (*this)));
    }
    else if (impl.type () == PICML::ComponentAssembly::meta)
    {
      PICML::ComponentAssembly assembly = PICML::ComponentAssembly::Cast (impl);

      CUTS_BE::visit <IMPL_STRATEGY> (assembly,
        boost::bind (&PICML::ComponentAssembly::Accept, _1, boost::ref (*this)));
    }
    else
    {
      // Um, why do we not know about this type!?!?
    }
  }
  else
  {
    // Wow, this does not contain any children!!
  }
}

//
// Visit_MonolithicImplementation
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_MonolithicImplementation (
const PICML::MonolithicImplementation & monoimpl)
{
  // Get the parent of the monolithic implementation.
  PICML::ComponentImplementationContainer container =
    monoimpl.ComponentImplementationContainer_parent ();

  // Preprocess the container and extract as much information
  // as we can about the current component's implementation.
  CUTS_BE_PREPROCESSOR ()->preprocess (container);

  if (CUTS_BE_File_Open_T <IMPL_STRATEGY>::generate (container, monoimpl))
  {
    // Write the prologue for the file.
    CUTS_BE_Prologue_T <IMPL_STRATEGY>::generate (container, monoimpl);

    // Get the implementation node and write all the includes.
    const CUTS_BE_Impl_Node * impl = 0;
    CUTS_BE_PREPROCESSOR ()->impls ().find (container.name (), impl);

    // Write the include files for this implementation.
    CUTS_BE::visit <IMPL_STRATEGY> (impl->include_,
      boost::bind (&CUTS_BE_Impl_Generator_T::Visit_Include,
      boost::ref (this), _1));

    // Figure out what type of component we are implementing. Right
    // now there is a one-to-one implementation to component type
    // mapping. Therefore, the component has the known behavior
    // for this respective implementation.
    PICML::Implements implements = monoimpl.dstImplements ();

    if (implements != Udm::null)
    {
      // Extract the component type being implemented.
      PICML::ComponentRef ref = implements.dstImplements_end ();
      PICML::Component component = ref.ref ();

      // Write the beginning of the component's implementation.
      CUTS_BE_Component_Impl_Begin_T <IMPL_STRATEGY>::
        generate (monoimpl, component);

      // Visit the component.
      CUTS_BE::visit <IMPL_STRATEGY> (component,
        boost::bind (&PICML::Component::Accept, _1, boost::ref (*this)));

      // Write the end of the component's implementation.
      CUTS_BE_Component_Impl_End_T <IMPL_STRATEGY>::
        generate (monoimpl, component);

      // Get all the facets in the component so that we can
      // generate their implementation.
      typedef std::vector <PICML::ProvidedRequestPort> Facet_Set;
      Facet_Set facets = component.ProvidedRequestPort_kind_children ();

      CUTS_BE::visit <IMPL_STRATEGY> (facets,
        boost::bind (&CUTS_BE_Impl_Generator_T::Visit_ProvidedRequestPort_impl,
        boost::ref (this), _1));

      PICML::ComponentFactory factory;

      if (this->get_component_factory (component, factory))
      {
        // Write the beginning of the factory's implementation.
        CUTS_BE_Factory_Impl_Begin_T <IMPL_STRATEGY>::
          generate (factory, monoimpl, component);

        CUTS_BE::visit <IMPL_STRATEGY> (factory,
          boost::bind (&PICML::ComponentFactory::Accept,
          _1, boost::ref (*this)));

        // Write the end of the factory's implementation.
        CUTS_BE_Factory_Impl_End_T <IMPL_STRATEGY>::
          generate (factory, monoimpl, component);
      }
    }

    // Write the epilogue for the file, then close it.
    CUTS_BE_Epilogue_T <IMPL_STRATEGY>::generate (container, monoimpl);
    CUTS_BE_File_Close_T <IMPL_STRATEGY>::generate (container, monoimpl);
  }
  else
  {
    CUTS_BE_PREPROCESSOR ()->remove (container);
  }
}

//
// Visit_MonolithicImplementation
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ComponentAssembly (const PICML::ComponentAssembly & assembly)
{
  // Get the parent of the monolithic implementation.
  PICML::ComponentImplementationContainer container =
    assembly.ComponentImplementationContainer_parent ();

  if (CUTS_BE_ComponentAssembly_File_Open_T <IMPL_STRATEGY>::
      generate (container, assembly))
  {
    // Write the prologue for the file.
    CUTS_BE_ComponentAssembly_Prologue_T <IMPL_STRATEGY>::
      generate (container, assembly);

    CUTS_BE_Assembly_Generator_T <IMPL_STRATEGY> generator;
    PICML::ComponentAssembly (assembly).Accept (generator);

    // Write the epilogue for the file, then close it.
    CUTS_BE_ComponentAssembly_Epilogue_T <IMPL_STRATEGY>::
      generate (container, assembly);

    CUTS_BE_ComponentAssembly_File_Close_T <IMPL_STRATEGY>::
      generate (container, assembly);
  }
}

//
// Visit_Component
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_Component (const PICML::Component & component)
{
  // Determine if we are ready to write the variables.
  if (!CUTS_BE_Write_Variables_Last_T <IMPL_STRATEGY>::result_type)
    this->write_variables_i (component);

  // Visit all the supported interfaces.
  typedef std::vector <PICML::Supports> Supports_Set;
  Supports_Set supports = component.Supports_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (supports,
    boost::bind (&Supports_Set::value_type::Accept,
    _1, boost::ref (*this)));

  // Visit all the InEventPort elements of the <component>.
  typedef std::vector <PICML::InEventPort> InEventPort_Set;
  InEventPort_Set sinks = component.InEventPort_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (sinks,
    boost::bind (&InEventPort_Set::value_type::Accept,
    _1, boost::ref (*this)));

  // Visit all the ProvidedRequestPort elements of the <component>.
  typedef std::vector <PICML::ProvidedRequestPort> Facet_Set;
  Facet_Set facets = component.ProvidedRequestPort_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (facets,
    boost::bind (&Facet_Set::value_type::Accept,
    _1, boost::ref (*this)));

  // Visit all the PeriodicEvent elements of the <component>.
  typedef std::vector <PICML::PeriodicEvent> PeriodicEvent_Set;
  PeriodicEvent_Set periodics = component.PeriodicEvent_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (periodics,
    boost::bind (&PeriodicEvent_Set::value_type::Accept,
    _1, boost::ref (*this)));

  // Visit all the Attribute elements of the <component>.
  typedef std::vector <PICML::Attribute> Attribute_Set;
  Attribute_Set attrs = component.Attribute_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (attrs,
    boost::bind (&Attribute_Set::value_type::Accept,
    _1, boost::ref (*this)));

  // Visit all the ReadonlyAttribute elements of the <component>.
  typedef std::vector <PICML::ReadonlyAttribute> ReadonlyAttribute_Set;
  ReadonlyAttribute_Set ro_attrs = component.ReadonlyAttribute_kind_children ();

  typedef is_type <PICML::ReadonlyAttribute> ReadonlyAttribute_Type;

  std::for_each (boost::make_filter_iterator <ReadonlyAttribute_Type> (
                    ro_attrs.begin (), ro_attrs.end ()),
                 boost::make_filter_iterator <ReadonlyAttribute_Type> (
                    ro_attrs.end (), ro_attrs.end ()),
                 boost::bind (&ReadonlyAttribute_Set::value_type::Accept,
                    _1, boost::ref (*this)));

  // Get the environment for the component.
  PICML::Environment env = component.Environment_child ();

  // Begin generating environment related metadata.
  CUTS_BE_Environment_Begin_T <IMPL_STRATEGY>::generate (component);

  if (env != Udm::null)
  {
    CUTS_BE_Env_Visitor_T <IMPL_STRATEGY> env_visitor;

    CUTS_BE::visit <IMPL_STRATEGY> (env,
      boost::bind (&PICML::Environment::Accept,
      _1, boost::ref (env_visitor)));
  }

  // End generating environment related metadata.
  CUTS_BE_Environment_End_T <IMPL_STRATEGY>::generate (component);

  // Determine if we are writing the variables
  if (CUTS_BE_Write_Variables_Last_T <IMPL_STRATEGY>::result_type)
    this->write_variables_i (component);
}

//
// Visit_InEventPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_InEventPort (const PICML::InEventPort & sink)
{
  CUTS_BE_InEventPort_Begin_T <IMPL_STRATEGY>::generate (sink);

  CUTS_BE_Execution_Visitor_T <IMPL_STRATEGY> exec_visitor;
  exec_visitor.generate (sink);

  CUTS_BE_InEventPort_End_T <IMPL_STRATEGY>::generate (sink);
}

//
// Visit_ProvidedRequestPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & facet)
{
  // Begin the generation of the provided request port.
  CUTS_BE_ProvidedRequestPort_Begin_T <IMPL_STRATEGY>::generate (facet);

  CUTS_BE_Execution_Visitor_T <IMPL_STRATEGY> exec_visitor;
  exec_visitor.generate (facet);

  // End the generation of the provided request port.
  CUTS_BE_ProvidedRequestPort_End_T <IMPL_STRATEGY>::generate (facet);
}

//
// Visit_ProvidedRequestPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ProvidedRequestPort_impl (const PICML::ProvidedRequestPort & facet)
{
  // Get the parent component and the facet's interface/object.
  PICML::Component component = PICML::Component::Cast (facet.parent ());
  PICML::Object object = PICML::Object::Cast (facet.ref ());

  if (object != Udm::null)
  {
    // Write the beginning of the facet's implementation.
    CUTS_BE_Object_Impl_Begin_T <IMPL_STRATEGY>::generate (component, facet);

    CUTS_BE::visit <IMPL_STRATEGY> (object,
      boost::bind (&PICML::Object::Accept, _1, boost::ref (*this)));

    // Write the end of the facet's implementation.
    CUTS_BE_Object_Impl_End_T <IMPL_STRATEGY>::generate (component, facet);
  }
}

//
// Visit_ProvidedRequestPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_PeriodicEvent (const PICML::PeriodicEvent & periodic)
{
  // Begin the generation of the periodic event.
  CUTS_BE_PeriodicEvent_Begin_T <IMPL_STRATEGY>::generate (periodic);

  CUTS_BE_Execution_Visitor_T <IMPL_STRATEGY> exec_visitor;
  exec_visitor.generate (periodic);

  // End the generation of the periodic event.
  CUTS_BE_PeriodicEvent_End_T <IMPL_STRATEGY>::generate (periodic);
}

//
// Visit_InEventPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_Attribute (const PICML::Attribute & attr)
{
  CUTS_BE_Attribute_Begin_T <IMPL_STRATEGY>::generate (attr);

  CUTS_BE_Attribute_End_T <IMPL_STRATEGY>::generate (attr);
}

//
// Visit_ProvidedRequestPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & attr)
{
  CUTS_BE_ReadonlyAttribute_Begin_T <IMPL_STRATEGY>::generate (attr);

  CUTS_BE_ReadonlyAttribute_End_T <IMPL_STRATEGY>::generate (attr);
}

//
// get_component_factory
//
template <typename IMPL_STRATEGY>
bool CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
get_component_factory (const PICML::Component & component,
                       PICML::ComponentFactory & factory)
{
  // Try and locate the real factory for the component.
  typedef std::set <PICML::ManagesComponent> Manages_Set;
  Manages_Set manages = component.srcManagesComponent ();

  if (manages.size () > 0)
  {
    PICML::ManagesComponent manage = (*manages.begin ());
    factory = manage.srcManagesComponent_end ();
    return true;
  }

  typedef std::set <PICML::ComponentRef> ComponentRef_Set;
  ComponentRef_Set refs = component.referedbyComponentRef ();

  PICML::MgaObject parent;
  std::string parent_type;

  for (ComponentRef_Set::iterator iter = refs.begin ();
       iter != refs.end ();
       iter ++)
  {
    parent = iter->parent ();
    Uml::Class type = parent.type ();

    if (type == PICML::File::meta ||  type == PICML::Package::meta)
      return this->get_component_factory (iter->ref (), factory);
  }

  return false;
}

//
// Visit_WorkerType
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_WorkerType (const PICML::WorkerType & type)
{
  PICML::Worker worker = type.ref ();

  if (worker != Udm::null)
    CUTS_BE_Worker_Variable_T <IMPL_STRATEGY>::generate (type, worker);
}

//
// Visit_TwowayOperation
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_TwowayOperation (const PICML::TwowayOperation & twoway)
{
  CUTS_BE_TwowayOperation_Begin_T <IMPL_STRATEGY>::generate (twoway);

  CUTS_BE_TwowayOperation_End_T <IMPL_STRATEGY>::generate (twoway);
}

//
// Visit_OnewayOperation
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_OnewayOperation (const PICML::OnewayOperation & oneway)
{
  CUTS_BE_OnewayOperation_Begin_T <IMPL_STRATEGY>::generate (oneway);

  CUTS_BE_OnewayOperation_End_T <IMPL_STRATEGY>::generate (oneway);
}

//
// Visit_ComponentFactory
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ComponentFactory (const PICML::ComponentFactory & factory)
{
  // Visit all the component's factory operations.
  typedef std::vector <PICML::FactoryOperation> FactoryOperation_Set;
  FactoryOperation_Set operations = factory.FactoryOperation_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (operations,
    boost::bind (&FactoryOperation_Set::value_type::Accept,
    _1, boost::ref (*this)));

  // Visit all the base factories, so we can generate to
  // correct methods for this component's factory.
  typedef std::vector <PICML::Inherits> Inherits_Set;
  Inherits_Set inherits = factory.Inherits_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (inherits,
    boost::bind (&CUTS_BE_Impl_Generator_T::Visit_ComponentFactory_inherits,
    this, _1));
}

//
// Visit_ComponentFactory
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ComponentFactory_inherits (const PICML::Inherits & inherits)
{
  PICML::ComponentFactory factory =
    PICML::ComponentFactory::Cast (inherits.ref ());

  CUTS_BE::visit <IMPL_STRATEGY> (factory,
    boost::bind (&PICML::ComponentFactory::Accept, _1, boost::ref (*this)));
}

//
// Visit_FactoryOperation
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_FactoryOperation (const PICML::FactoryOperation & fop)
{
  CUTS_BE_FactoryOperation_Begin_T <IMPL_STRATEGY>::generate (fop);

  CUTS_BE_FactoryOperation_End_T <IMPL_STRATEGY>::generate (fop);
}

//
// Visit_Supports
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_Supports (const PICML::Supports & supports)
{
  PICML::Object object = supports.ref ();

  if (object != Udm::null)
  {
    CUTS_BE::visit <IMPL_STRATEGY> (object,
      boost::bind (&PICML::Object::Accept, _1, boost::ref (*this)));
  }
}

//
// Visit_Component_supports
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_Object (const PICML::Object & object)
{
  // Write all the methods of the facet.
  typedef std::vector <PICML::OnewayOperation> OnewayOperation_Set;
  OnewayOperation_Set oneways = object.OnewayOperation_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (oneways,
    boost::bind (&OnewayOperation_Set::value_type::Accept,
    _1, boost::ref (*this)));

  typedef std::vector <PICML::TwowayOperation> TwowayOperation_Set;
  TwowayOperation_Set twoways = object.TwowayOperation_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (twoways,
    boost::bind (&TwowayOperation_Set::value_type::Accept,
    _1, boost::ref (*this)));
}

//
// write_variables_i
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
write_variables_i (const PICML::Component & component)
{
  CUTS_BE_Variables_Begin_T <IMPL_STRATEGY>::generate (component);

  // Write all the basic variables.
  typedef std::vector <PICML::Variable> Variable_Set;
  Variable_Set vars = component.Variable_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (vars,
    boost::bind (&Variable_Set::value_type::Accept,
    _1, boost::ref (*this)));

  // Write all the worker related variables.
  typedef std::vector <PICML::WorkerType> WorkerType_Set;
  WorkerType_Set workers = component.WorkerType_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (workers,
    boost::bind (&WorkerType_Set::value_type::Accept, _1, boost::ref (*this)));

  // Write the attribute variables.
  typedef std::vector <PICML::ReadonlyAttribute> ReadonlyAttribute_Set;
  ReadonlyAttribute_Set ro_attrs = component.ReadonlyAttribute_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (ro_attrs,
    boost::bind (&CUTS_BE_Impl_Generator_T::Visit_ReadonlyAttribute_Variable,
    boost::ref (this), _1));

  // Write the periodic event variables.
  typedef std::vector <PICML::PeriodicEvent> PeriodicEvent_Set;
  PeriodicEvent_Set periodics = component.PeriodicEvent_kind_children ();

  CUTS_BE::visit <IMPL_STRATEGY> (periodics,
    boost::bind (&CUTS_BE_Impl_Generator_T::Visit_PeriodicEvent_Variable,
    boost::ref (this), _1));

  // End the generation of the variables.
  CUTS_BE_Variables_End_T <IMPL_STRATEGY>::generate (component);
}
