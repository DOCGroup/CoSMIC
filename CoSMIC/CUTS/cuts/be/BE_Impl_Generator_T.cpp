// $Id$

#if !defined (__CUTS_INLINE__)
#include "BE_Impl_Generator_T.inl"
#endif

#include "BE_Preprocessor.h"
#include "BE_Env_Visitor_T.h"
#include "BE_Execution_Visitor_T.h"
#include "UDM_Utility_T.h"

#include "boost/bind.hpp"
#include "boost/iterator/filter_iterator.hpp"

//
// CUTS_BE_Impl_Generator_T
//
template <typename IMPL_STRATEGY>
CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
CUTS_BE_Impl_Generator_T (void)
{

}

//
// ~CUTS_BE_Impl_Generator_T
//
template <typename IMPL_STRATEGY>
CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
~CUTS_BE_Impl_Generator_T (void)
{

}

//
// Visit_RootFolder
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_RootFolder (const PICML::RootFolder & root)
{
  typedef std::vector <PICML::ComponentImplementations> Folder_Set;
  Folder_Set folders = root.ComponentImplementations_children ();

  std::for_each (folders.begin (),
                 folders.end (),
                 boost::bind (&Folder_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
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

  std::for_each (container.begin (),
                 container.end (),
                 boost::bind (&Container_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_ComponentImplementationContainer
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ComponentImplementationContainer (
const PICML::ComponentImplementationContainer & container)
{
  // There is a chance that this <container> doesn't have any
  // monolithic implemenations. If this is the case, then we
  // don't want to visit it.
  typedef std::vector <PICML::MonolithicImplementation> MonoImpl_Set;
  MonoImpl_Set monos = container.MonolithicImplementation_kind_children ();

  if (monos.empty ())
    return;

  // Let's preprocess this container before we continue. We
  // need to extract as much information about the component(s)
  // in this container as possible.

  CUTS_BE_PREPROCESSOR ()->preprocess (container);

  /**
   * class My_Backend_Traits
   * {
   *   static std::ofstream outfile_;
   *
   *   struct Open_File
   *   {
   *     static bool generate (container)
   *       { My_Backend_Traits::outfile_.open (container.name ()); }
   *   };
   *
   *   struct Close_File
   *   {
   *     static bool generate (container)
   *       { My_Backend_Traits::outfile_.close (container.name ());
   *         My_Backend_Traits::outfile_.clear (); }
   *   };
   * };
   *
   * if (CUTS_BE::generate_if <IMPL_STRATEGY::Open_File>::
   *                           result_type::generate (container))
   * {
   *  ...
   * }
   */
  if (this->traits_.open_file (container))
  {
    /**
     * CUTS_BE::generate_if <IMPL_STRATEGY::Prologue_Generator>::
     *                       result_type::generate (container);
     */
    // Write the prologue for the file.
    this->traits_.write_prologue (container);

    // Write the includes for this implementation. We also need to
    // write the includes for all first-level references, i.e.,
    // IDL references.

    const CUTS_BE_Impl_Node * impl = 0;
    CUTS_BE_PREPROCESSOR ()->impls ().find (container.name (), impl);

    this->traits_.write_includes (impl->include_);

    /**
     * CUTS_BE::if_then <CUTS_BE::visit_type <STRATEGY, PICML::MonolithicImplementation>::result_type,
     *                   CUTS_BE::iterate_all>::
     *                   result_type::execute (monos, functor);
     */
    std::for_each (monos.begin (),
                   monos.end (),
                   boost::bind (&MonoImpl_Set::value_type::Accept,
                                _1,
                                boost::ref (*this)));

    // Write the epilogue for the file, then close it.
    this->traits_.write_epilogue (container);
    this->traits_.close_file (container);
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

    // Signal the <traits_> to write the beginning of the
    // monolithic implementation.
    this->traits_.write_impl_begin (monoimpl, component);

    // Visit the component.
    component.Accept (*this);

    // Signal the <traits_> to write the end of the
    // monolithic implementation.
    this->traits_.write_impl_end (monoimpl, component);

    // Get all the facets in the component so that we can
    // generate their implementation.
    typedef std::vector <PICML::ProvidedRequestPort> Facet_Set;
    Facet_Set facets = component.ProvidedRequestPort_kind_children ();

    std::for_each (facets.begin (),
                   facets.end (),
                   boost::bind (&CUTS_BE_Impl_Generator_T::
                                Visit_ProvidedRequestPort_impl,
                                boost::ref (this),
                                _1));

    // Get the factory that manages this component.
    PICML::ComponentFactory factory;

    if (this->get_component_factory (component, factory))
    {
      this->traits_.write_factory_impl_begin (factory, monoimpl, component);

      factory.Accept (*this);

      this->traits_.write_factory_impl_end (factory, monoimpl, component);
    }
  }
}

//
// Visit_Component
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_Component (const PICML::Component & component)
{
  // Visit all the supported interfaces.
  typedef std::vector <PICML::Supports> Supports_Set;
  Supports_Set supports = component.Supports_kind_children ();

  std::for_each (supports.begin (),
                 supports.end (),
                 boost::bind (&Supports_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit all the InEventPort elements of the <component>.
  typedef std::vector <PICML::InEventPort> InEventPort_Set;
  InEventPort_Set sinks = component.InEventPort_kind_children ();

  std::for_each (sinks.begin (),
                 sinks.end (),
                 boost::bind (&InEventPort_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit all the ProvidedRequestPort elements of the <component>.
  typedef std::vector <PICML::ProvidedRequestPort> Facet_Set;
  Facet_Set facets = component.ProvidedRequestPort_kind_children ();

  std::for_each (facets.begin (),
                 facets.end (),
                 boost::bind (&Facet_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit all the PeriodicEvent elements of the <component>.
  typedef std::vector <PICML::PeriodicEvent> PeriodicEvent_Set;
  PeriodicEvent_Set periodics = component.PeriodicEvent_kind_children ();

  std::for_each (periodics.begin (),
                 periodics.end (),
                 boost::bind (&PeriodicEvent_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit all the Attribute elements of the <component>.
  typedef std::vector <PICML::Attribute> Attribute_Set;
  Attribute_Set attrs = component.Attribute_kind_children ();

  std::for_each (attrs.begin (),
                 attrs.end (),
                 boost::bind (&Attribute_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit all the ReadonlyAttribute elements of the <component>.
  typedef std::vector <PICML::ReadonlyAttribute> ReadonlyAttribute_Set;
  ReadonlyAttribute_Set ro_attrs = component.ReadonlyAttribute_kind_children ();

  typedef
    is_type <PICML::ReadonlyAttribute> ReadonlyAttribute_Type;

  std::for_each (
    boost::make_filter_iterator <ReadonlyAttribute_Type> (
      ro_attrs.begin (), ro_attrs.end ()),
    boost::make_filter_iterator <ReadonlyAttribute_Type> (
      ro_attrs.end (), ro_attrs.end ()),
    boost::bind (&ReadonlyAttribute_Set::value_type::Accept,
                 _1,
                 boost::ref (*this)));

  // Visit all the Environment element of the <component>.
  PICML::Environment env = component.Environment_child ();
  this->traits_.write_environment_begin (component);

  if (env != Udm::null)
  {
    CUTS_BE_Env_Visitor_T <IMPL_STRATEGY> env_visitor (this->traits_);
    env.Accept (env_visitor);
  }

  this->traits_.write_environment_end (component);

  // We are now ready to write the variables for the components. The
  // variables consist of the attributes and the behavior declared
  // variables.
  this->traits_.write_variables_begin (component);

  typedef std::vector <PICML::Variable> Variable_Set;
  Variable_Set vars = component.Variable_kind_children ();

  std::for_each (vars.begin (),
                 vars.end (),
                 boost::bind (&Variable_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  typedef std::vector <PICML::WorkerType> WorkerType_Set;
  WorkerType_Set workers = component.WorkerType_kind_children ();

  std::for_each (workers.begin (),
                 workers.end (),
                 boost::bind (&WorkerType_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Write the attribute variables.
  std::for_each (ro_attrs.begin (),
                 ro_attrs.end (),
                 boost::bind (&IMPL_STRATEGY::write_ReadonlyAttribute_variable,
                              boost::ref (this->traits_),
                              _1));

  // Write the periodic event variables.
  std::for_each (periodics.begin (),
                 periodics.end (),
                 boost::bind (&IMPL_STRATEGY::write_PeriodicEvent_variable,
                              boost::ref (this->traits_),
                              _1));

  this->traits_.write_variables_end ();
}

//
// Visit_InEventPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_InEventPort (const PICML::InEventPort & sink)
{
  this->traits_.write_InEventPort_begin (sink);

  CUTS_BE_Execution_Visitor_T <IMPL_STRATEGY> exec_visitor (this->traits_);
  exec_visitor.generate (sink);

  this->traits_.write_InEventPort_end (sink);
}

//
// Visit_ProvidedRequestPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & facet)
{
  this->traits_.write_ProvidedRequestPort_begin (facet);

  CUTS_BE_Execution_Visitor_T <IMPL_STRATEGY> exec_visitor (this->traits_);
  exec_visitor.generate (facet);

  this->traits_.write_ProvidedRequestPort_end (facet);
}

//
// Visit_ProvidedRequestPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ProvidedRequestPort_impl (const PICML::ProvidedRequestPort & facet)
{
  // Get the parent component and the facet's interface/object.
  PICML::Component parent = PICML::Component::Cast (facet.parent ());
  PICML::Object object = PICML::Object::Cast (facet.ref ());

  if (object != Udm::null)
  {
    this->traits_.write_object_impl_begin (parent, facet);

    object.Accept (*this);

    this->traits_.write_object_impl_end (parent, facet);
  }
}

//
// Visit_ProvidedRequestPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_PeriodicEvent (const PICML::PeriodicEvent & periodic)
{
  this->traits_.write_PeriodicEvent_begin (periodic);

  CUTS_BE_Execution_Visitor_T <IMPL_STRATEGY> exec_visitor (this->traits_);
  exec_visitor.generate (periodic);

  this->traits_.write_PeriodicEvent_end (periodic);
}

//
// Visit_InEventPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_Attribute (const PICML::Attribute & attr)
{
  this->traits_.write_Attribute_begin (attr);

  this->traits_.write_Attribute_end (attr);
}

//
// Visit_ProvidedRequestPort
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & ro_attr)
{
  this->traits_.write_ReadonlyAttribute_begin (ro_attr);

  this->traits_.write_ReadonlyAttribute_end (ro_attr);
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
// Visit_Variable
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_Variable (const PICML::Variable & variable)
{
  this->traits_.write_variable (variable);
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
    this->traits_.write_worker_variable (type, worker);
}

//
// Visit_TwowayOperation
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_TwowayOperation (const PICML::TwowayOperation & twoway)
{
  this->traits_.write_TwowayOperation_begin (twoway);

  this->traits_.write_TwowayOperation_end (twoway);
}

//
// Visit_OnewayOperation
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_OnewayOperation (const PICML::OnewayOperation & oneway)
{
  this->traits_.write_OnewayOperation_begin (oneway);

  this->traits_.write_OnewayOperation_end (oneway);
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

  std::for_each (operations.begin (),
                 operations.end (),
                 boost::bind (&FactoryOperation_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit all the base factories, so we can generate to
  // correct methods for this component's factory.
  typedef std::vector <PICML::Inherits> Inherits_Set;
  Inherits_Set inherits = factory.Inherits_kind_children ();

  std::for_each (inherits.begin (),
                 inherits.end (),
                 boost::bind (&CUTS_BE_Impl_Generator_T::
                              Visit_ComponentFactory_inherits,
                              this,
                              _1));
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

  factory.Accept (*this);
}

//
// Visit_FactoryOperation
//
template <typename IMPL_STRATEGY>
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_FactoryOperation (const PICML::FactoryOperation & factory_op)
{
  this->traits_.write_FactoryOperation_begin (factory_op);

  this->traits_.write_FactoryOperation_end (factory_op);
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
    object.Accept (*this);
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

  std::for_each (oneways.begin (),
                 oneways.end (),
                 boost::bind (&OnewayOperation_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  typedef std::vector <PICML::TwowayOperation> TwowayOperation_Set;
  TwowayOperation_Set twoways = object.TwowayOperation_kind_children ();

  std::for_each (twoways.begin (),
                 twoways.end (),
                 boost::bind (&TwowayOperation_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}
